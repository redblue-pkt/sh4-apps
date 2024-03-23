/*
 * satip: vtuner to satip mapping
 *
 * Copyright (C) 2014  mc.fishdish@gmail.com
 * [fragments from vtuner by Honza Petrous]
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <linux/dvb/version.h>
#include <linux/dvb/frontend.h>
#include <linux/dvb/dmx.h>

#include "satip_config.h"
#include "satip_vtuner.h"
#include "log.h"

/* driver interface */
#include "vtuner.h"

extern char* const strmap_fecinner[];
extern char* const strmap_rolloff[];

typedef struct satip_vtuner {
  int fd;
  t_satip_config* satip_cfg;
} t_satip_vtuner;


t_satip_vtuner* satip_vtuner_new(char* devname,char *delsys,t_satip_config* satip_cfg)
{
  int fd;
  t_satip_vtuner* vt;

  fd  = open(devname, O_RDWR);
  if ( fd < 0)
    {
      ERROR(MSG_MAIN,"Couldn't open %s\n",devname);
      return NULL;
    }

  vt=(t_satip_vtuner*)malloc(sizeof(t_satip_vtuner));

  vt->fd=fd;
  vt->satip_cfg=satip_cfg;

  /* set default position A, if appl. does not configure */
  satip_set_position(satip_cfg, 0);

  if (delsys!=NULL) {
    // set delivery systems
    int i=0;
    struct vtuner_delsys vt_delsys;
    memset(&vt_delsys,0,sizeof(struct vtuner_delsys));
    char *token = strtok(delsys, ",");
    while (token != NULL) {
       if (!strcasecmp(token, "DVBS")) vt_delsys.value[i++]=SYS_DVBS;
       if (!strcasecmp(token, "DVBS2")) vt_delsys.value[i++]=SYS_DVBS2;
#ifdef __MAINLINE_KERNEL__
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 0)
       if (!strcasecmp(token, "DVBC")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_A;
       if (!strcasecmp(token, "DVBC_A")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_A;
       if (!strcasecmp(token, "DVBC_B")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_B;
       if (!strcasecmp(token, "DVBC_C")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_C;
#else
       if (!strcasecmp(token, "DVBC_A")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_AC;
       if (!strcasecmp(token, "DVBC_B")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_B;
#endif
#else
#if DVB_API_VERSION == 5 && DVB_API_VERSION_MINOR >= 5
       if (!strcasecmp(token, "DVBC")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_A;
       if (!strcasecmp(token, "DVBC_A")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_A;
       if (!strcasecmp(token, "DVBC_B")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_B;
       if (!strcasecmp(token, "DVBC_C")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_C;
#else
       if (!strcasecmp(token, "DVBC_A")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_AC;
       if (!strcasecmp(token, "DVBC_B")) vt_delsys.value[i++]=SYS_DVBC_ANNEX_B;
#endif
#endif

       if (!strcasecmp(token, "DVBT")) vt_delsys.value[i++]=SYS_DVBT;
#ifdef __MAINLINE_KERNEL__
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 0, 0)
       if (!strcasecmp(token, "DVBT2")) vt_delsys.value[i++]=SYS_DVBT2;
#endif
#else
#if DVB_API_VERSION == 5 && DVB_API_VERSION_MINOR >= 3
	if (!strcasecmp(token, "DVBT2")) vt_delsys.value[i++]=SYS_DVBT2;
#endif
#endif
       token = strtok(NULL,",");
       if (i>VTUNER_MAX_DELSYS) break;
    }
    ioctl(fd, VTUNER_SET_DELSYS, &vt_delsys);

  }

  return vt;
}

int satip_vtuner_fd(struct satip_vtuner* vt)
{
  return vt->fd;
}

static t_polarization get_polarization(struct satip_vtuner* vt, struct vtuner_message* msg)
{
  char dbg[50];
  struct diseqc_master_cmd* cmd=&msg->body.fe_params.u.qpsk.sat.diseqc_master_cmd;
  t_polarization ret = SATIPCFG_UNSET;

  if ( cmd->msg[0] == 0xe0 &&
       cmd->msg[1] == 0x10 &&
       cmd->msg[2] == 0x38 &&
       cmd->msg_len == 4 )
    {
      sprintf(dbg,"%02X %02X %02X   msg %02X %02X %02X len %d",
	  cmd->msg[0],
	  cmd->msg[1],
	  cmd->msg[2],
	  cmd->msg[3],
	  cmd->msg[4],
	  cmd->msg[5],
	  cmd->msg_len);
       DEBUG(MSG_NET,"DISEQC %s\n",dbg);

      /* committed switch */
      u8 data=cmd->msg[3];

      if ( (data & 0x01) == 0x01 )
	{
	  msg->body.fe_params.u.qpsk.sat.tone = SEC_TONE_ON; /* high band */
	}
      else if ( (data & 0x11) == 0x10 )
	{
	  msg->body.fe_params.u.qpsk.sat.tone = SEC_TONE_OFF; /* low band */
	}

      if ( (data & 0x02) == 0x02 )
	ret = SATIPCFG_P_HORIZONTAL;
      else if ( (data & 0x22) == 0x20 )
	ret = SATIPCFG_P_VERTICAL;

      /* some invalid combinations ? */
      satip_set_position(vt->satip_cfg, ( (data & 0x0c) >> 2) + 1 );
    }
  else
    {
      if (msg->body.fe_params.u.qpsk.sat.voltage == SEC_VOLTAGE_13)
	ret = SATIPCFG_P_VERTICAL;
      else if (msg->body.fe_params.u.qpsk.sat.voltage == SEC_VOLTAGE_18)
	ret = SATIPCFG_P_HORIZONTAL;
    }
  if (msg->body.fe_params.u.qpsk.sat.burst_cmd.valid) {
     if (msg->body.fe_params.u.qpsk.sat.burst_cmd.value == SEC_MINI_A) {
        DEBUG(MSG_NET,"BURST SEC_MINI_A\n");
        satip_set_position(vt->satip_cfg,1);
     }
     if (msg->body.fe_params.u.qpsk.sat.burst_cmd.value == SEC_MINI_B) {
        DEBUG(MSG_NET,"BURST SEC_MINI_B\n");
        satip_set_position(vt->satip_cfg,2);
     }
  }
  return ret;
}

unsigned int get_sat_frequency(unsigned int freq, unsigned char tone)
{
  int frequency = (int) (freq / 100);
  if (tone == SEC_TONE_ON)
    frequency += 106000;
  else
    if (frequency - 97500 < 0)
      frequency += 97500;
    else
      frequency -= 97500;
  return (unsigned int) frequency;
}

static void set_frontend(struct satip_vtuner* vt, struct vtuner_message* msg)
{
  t_polarization pol;
  unsigned int freq;
  switch (msg->body.fe_params.delivery_system)
  {
     case SYS_DVBS:
       printf("%s line %d\n", __func__, __LINE__);
       pol = get_polarization(vt, msg);
       printf("%s line %d\n", __func__, __LINE__);
       freq = get_sat_frequency(msg->body.fe_params.frequency, msg->body.fe_params.u.qpsk.sat.tone);
       printf("%s line %d\n", __func__, __LINE__);
       satip_set_dvbs(vt->satip_cfg, freq / 10, pol,
		       msg->body.fe_params.u.qpsk.modulation,
		       msg->body.fe_params.u.qpsk.symbol_rate / 1000,
		       msg->body.fe_params.u.qpsk.fec_inner);
       printf("DVBS freq %d, symrate %d\n", freq / 10, msg->body.fe_params.u.qpsk.symbol_rate / 1000);
       break;
     case SYS_DVBS2:
       printf("%s line %d\n", __func__, __LINE__);
       pol = get_polarization(vt, msg);
       printf("%s line %d\n", __func__, __LINE__);
       freq = get_sat_frequency(msg->body.fe_params.frequency, msg->body.fe_params.u.qpsk.sat.tone);
       printf("%s line %d\n", __func__, __LINE__);
       printf("%s freq %d symrate %d, pilot %d, roll %d, fec %d, mod %d, pol %d\n", __func__, freq / 10, msg->body.fe_params.u.qpsk.symbol_rate / 1000, msg->body.fe_params.u.qpsk.pilot, msg->body.fe_params.u.qpsk.rolloff, msg->body.fe_params.u.qpsk.fec_inner, msg->body.fe_params.u.qpsk.modulation, pol);
       satip_set_dvbs2(vt->satip_cfg, freq / 10, pol,
		       msg->body.fe_params.u.qpsk.modulation,
		       msg->body.fe_params.u.qpsk.symbol_rate / 1000,
		       msg->body.fe_params.u.qpsk.fec_inner,
		       msg->body.fe_params.u.qpsk.rolloff,
		       msg->body.fe_params.u.qpsk.pilot);
        printf("DVBS2 freq %d, symrate %d\n", freq / 10, msg->body.fe_params.u.qpsk.symbol_rate / 1000);
       break;
#ifdef __MAINLINE_KERNEL__
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 3, 0)
     case SYS_DVBC_ANNEX_A:
     case SYS_DVBC_ANNEX_B:
     case SYS_DVBC_ANNEX_C:
#else
     case SYS_DVBC_ANNEX_AC:
     case SYS_DVBC_ANNEX_B:
#endif
#else
#if DVB_API_VERSION == 5 && DVB_API_VERSION_MINOR >= 5
     case SYS_DVBC_ANNEX_A:
     case SYS_DVBC_ANNEX_B:
     case SYS_DVBC_ANNEX_C:
#else
     case SYS_DVBC_ANNEX_AC:
     case SYS_DVBC_ANNEX_B:
#endif
#endif
       satip_set_dvbc(vt->satip_cfg, msg->body.fe_params.frequency / 1000000,
		       msg->body.fe_params.u.qam.inversion,
		       msg->body.fe_params.u.qam.modulation,
		       msg->body.fe_params.u.qam.symbol_rate / 1000);
       break;
     default:
       ERROR(MSG_MAIN,"unsupported delsys %i\n", msg->body.fe_params.delivery_system);
       break;
  }
}

static void close_frontend(struct satip_vtuner *vt)
{
  satip_close(vt->satip_cfg);
}

static void set_pidlist(struct satip_vtuner* vt, struct vtuner_message* msg)
{
  int i;

  satip_del_allpid(vt->satip_cfg);

  int hdr=0;
  for (i=0; i<MAX_PIDTAB_LEN; i++)
    if (msg->body.pidlist[i] < 8192  )
      {
        if (satip_add_pid(vt->satip_cfg,msg->body.pidlist[i])==SATIPCFG_OK) {
	  if (!hdr) {
	    DEBUG(MSG_MAIN,"MSG_SET_PIDLIST:\n");
	    hdr=1;
	  }
	  DEBUG(MSG_MAIN,"%d\n",msg->body.pidlist[i]);
	}
      }
}

void satip_vtuner_event(struct satip_vtuner* vt)
{
  struct vtuner_message  msg;

  if (ioctl(vt->fd, VTUNER_GET_MESSAGE, &msg))
    return;

  switch(msg.type)
    {
    case MSG_SET_FRONTEND:
      set_frontend(vt,&msg);
      break;

    case MSG_CLOSE_FRONTEND:
      close_frontend(vt);
      break;

    case MSG_PIDLIST:
      set_pidlist(vt,&msg);
      return;
      break;

    default:
      break;
    }

  msg.type=0;

  if (ioctl(vt->fd, VTUNER_SET_RESPONSE, &msg)){
    ERROR(MSG_MAIN,"ioctl: response not ok\n");
    return;
  }
}
