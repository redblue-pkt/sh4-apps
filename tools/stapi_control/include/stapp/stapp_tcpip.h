/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not   */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights, trade secrets or other intellectual property rights.   */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**
 * @file     stapp_tcpip.h
 * @brief    This is the tcp/ip file header.
 *           It is used to initialize and use ethernet interfaces availables.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TCPIP_H_
#define _STAPP_TCPIP_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* TCP/IP include */
/* -------------- */
#if defined(TCPIP)
#if defined(cab5197)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(sat5189)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(sat7111)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(adi7108)
/* No tcpip support */
#endif
#if defined(hdk5251)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdk5289)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdk7108)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdk7111)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2069)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2039)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2057)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2064)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2067)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(dp2010)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(dp7000)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(dp7001)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(dp7050)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(fx6010)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(ep8000)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(epp8000)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(gpv8000)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2075)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2076)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb618)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb628)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(mb628e)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(eud7141)||defined(hdkh225)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(mb676)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb680)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb704)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb796)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb837)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(mb903)
#define TCPIP_MAX_NUMBER  2
#endif
#if defined(b2066)
#define TCPIP_MAX_NUMBER  2
#endif
#if defined(hmp7105)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(sdk7105)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(kourou)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(isdb7102)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(iptv7105)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2068)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdk7167)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdk7197)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(hdkh251)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(dtt5267)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(b2049)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom001030)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom001034)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(custom001035)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(custom001036)
#define TCPIP_MAX_NUMBER  1
#define TCPIP_PHY_RTL8201E
#endif
#if defined(custom001037)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom001039)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(custom002005)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom002006)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom002007)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom002008)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(custom003008)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom003009)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom003011)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom003012)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom003015)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom003018)
#define TCPIP_MAX_NUMBER  1
#endif
#if defined(custom018001)
/* No tcpip support */
#endif
#if defined(custom021001)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#if defined(custom022001)
#if defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  1
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  2
#endif
#endif
#if defined(STGMAC0_BASE_ADDRESS)&&defined(STGMAC1_BASE_ADDRESS)
#define TCPIP_MAX_NUMBER  2
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  3
#endif
#endif
#if !defined(STGMAC0_BASE_ADDRESS)&&!defined(STGMAC1_BASE_ADDRESS)
#if (CABLE_MODEM_ATTACHED==1)
#undef  TCPIP_MAX_NUMBER
#define TCPIP_MAX_NUMBER  1
#endif
#endif
#endif
#define TCPIP_MAX_STREAMS 4
#define TCPIP_MAX_STRING  256
#if defined(TCPIP_STACK_NEXGEN)
#include <ngos.h>
#include <ngeth.h>
#include <ngtcp.h>
#include <ngudp.h>
#include <ngnet.h>
#include <ngping.h>
#include <ngresolv.h>
#include <ngdhcpc.h>
#include <ngip/ethernet.h>
#endif

#if defined(TCPIP_STACK_NEXGEN2)
#include <ngos.h>
#include <ngeth.h>
#include <ngtcp.h>
#include <ngudp.h>
#include <ngnet.h>
#include <ngresolv.h>
#include <ngip.h>
#include <ngdhcp6c.h>
#include <ngdhcpc.h>
#include <ngdev.h>
#include <ngmodule.h>
#include <ngpacket.h>
#include <ngos/rtos/osplus/ngosplus_eth.h>
#include <ngmodule.h>
#include <ngpacket.h>
#include <ngstdlib.h>
#include <ngsockio.h>       /* generic socket interface */
#include <nginet6.h>
#include <nginet.h>
#include <ngip/icmp6.h>
#include <ngip/icmp.h>
#endif

#if defined(TCPIP_STACK_FUSION)
#error "fusion includes : To be done for Fusion stack, your contribution is welcome to fill up this part of the code"
#endif
#if defined(OSPLUS)
#include <osplus/lan91.h>
#include <osplus/lan9x1x.h>
#include <osplus/stmac110.h>
#include <osplus/stxmac.h>
#if defined(STXMAC_CONFIG_PHY_ADDRESS)
#define OSPLUS_VERSION 303
#else
#define OSPLUS_VERSION 310
#endif
#if (OSPLUS_VERSION<310)
#include <osplus/ethernet/ethernet_phy_plugin.h>
#else
#include <osplus/phy.h>
#endif
#include <osplus/ioctls/usb/encm.h>
#endif
#if defined(ST_OSLINUX)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#endif
#if !defined(TCPIP_STACK_NONE)
#include "stnet.h"
#endif
#endif

/* TCPIP statistics structure */
/* -------------------------- */
#if defined(OSPLUS)
#if defined(TCPIP_STACK_NEXGEN2)
typedef enum TCPIP_PingStat_e
{
  TCPIP_SEND,           /* Data send        */
  TCPIP_RECV,           /* Data Recieved    */
  TCPIP_NRSP,           /* No Responce      */
  TCPIP_TOUT,           /* time out         */
  TCPIP_ERR,            /* Ping Error       */
}TCPIP_PingStat_t;
typedef void (* TCPIP_PingCallback_t) (TCPIP_PingStat_t PingStat,U32 DataSize,U32 TTL,U32 TimemS,char *AddressStr_p);
typedef struct TCPIP_PingCfg_s
{
 U32 RepeatCnt;                     /* Number of times to send ping request */
 U32 DataLen;                       /* Length of data to send               */
 TCPIP_PingCallback_t PingCallback; /* Call back to print ping status       */
}TCPIP_PingCfg_t;
#else
typedef struct TCPIP_Statistics_s
{
 /* -- Link status -- */
 U32 Link_enabled;
 U32 Link_loopback;
 U32 Link_speed;
 U32 Link_duplex;
 /* -- Fatal receive errors -- */
 U32 Receive_no_buffers;
 U32 Receive_crc_error;
 U32 Receive_alignment_error;
 U32 Receive_runt_error;
 U32 Receive_watchdog_expired;
 /* -- Fatal transmit errors -- */
 U32 Transmit_nocarrier_error;
 U32 Transmit_underrun_error;
 /* -- Miscellaneous receive -- */
 U32 Receive_packet_ok;
 U32 Receive_bytes_ok;
 U32 Receive_multicast_frames;
 /* -- Miscellaneous transmit -- */
 U32 Transmit_packet_ok;
 U32 Transmit_bytes_ok;
 U32 Transmit_multicast_frames;
} TCPIP_Statistics_t;
#endif
#endif
/* Definitions of the IPV4/6 */
/* -------------------------- */
typedef enum TCPIP_IPVx_e
{
 TCPIP_IPV4     = 1,
 TCPIP_IPV6     = 2,
 TCPIP_INVALID  = 4
} TCPIP_IPVx_t;

/* Prototypes */
/* ---------- */
/* A STR name is a virtual stream, it could UPD/RTP/RTSP depending of the support                      */
/* we have in the software. In order to be general, here is a subset of functions to get               */
/* datas from the TCP/IP stack...                                                                      */
/* The STR_Name is a string to identify the streaming access point                                     */
/* The STR_Params is also a string which is compatible with VLC, for example :                         */
/* STR_Params = "udp://@:1234" is a UDP multicast connection on port 1234                              */
/* STR_Params = "udp://192.168.0.32:1234" is a UDP unicast connection on port 1234 and ip 192.168.0.32 */
/* STR_Params = "rtp://192.168.0.32:1234" is a RTP unicast connection on port 1234 and ip 192.168.0.32 */
/* STR_Params = "rtsp://192.168.0.32" is a RTSP connection                                             */
/* STR_Mode   = "r" or "w"                                                                              */
ST_ErrorCode_t TCPIP_Init           (void);
ST_ErrorCode_t TCPIP_Term           (void);
ST_ErrorCode_t TCPIP_GetStream      (U8 *STR_Name,U32 *STR_Handle,U8 **STR_Params,U8 **STR_Mode);
ST_ErrorCode_t TCPIP_OpenStream     (U32 NetId,U8 *STR_Name,U8 *STR_Params,U8 *STR_Mode,U32 *STR_Handle);
ST_ErrorCode_t TCPIP_CloseStream    (U32 STR_Handle);
ST_ErrorCode_t TCPIP_StartStream    (U32 STR_Handle);
ST_ErrorCode_t TCPIP_StopStream     (U32 STR_Handle);
ST_ErrorCode_t TCPIP_WriteStream    (U32 STR_Handle,U8 *PayLoadBuffer,U32 PayLoadSize);
#if defined(OSPLUS)
#if !defined(TCPIP_STACK_NEXGEN2)
ST_ErrorCode_t TCPIP_GetStatistics  (U32 NetId,TCPIP_Statistics_t *Statistics);
ST_ErrorCode_t TCPIP_ResetStatistics(U32 NetId,TCPIP_Statistics_t *Statistics);
#endif
#endif

#if defined(TCPIP_STACK_NEXGEN)
ST_ErrorCode_t FTPS_Start           (U32 NetId);
ST_ErrorCode_t FTPS_Stop            (U32 NetId);
#endif

#if defined(TCPIP_STACK_NEXGEN2)
void TCPIP_Ping(U32 NetId, char *AddressStr_p,const TCPIP_PingCfg_t * PingCfg_p);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

