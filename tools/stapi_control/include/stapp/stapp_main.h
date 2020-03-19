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
@file     stapp_main.h
@brief    This is the main entry point header of the STAPI Software development kit
@author   STMicroelectronics
*/

#ifndef _STAPP_MAIN_H_
#define _STAPP_MAIN_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* OS+ include */
/* ----------- */
#if defined(OSPLUS)
#if defined(PROCESSOR_ST231)
#define __MINGW32__
#endif
#include <osplus/dev.h>
#include <osplus/lvm.h>
#include <osplus/vfs.h>
#include <osplus/e2fs.h>
#include <osplus/fat.h>
#include <osplus/registry.h>
#include <osplus.h>
#include <errno.h>
#endif

/* Includes */
/* -------- */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "stddefs.h"
#include "stdevice.h"
#include "stcommon.h"
#include "stavmem.h"
#include "stbuffer.h"
#include "stsys.h"
#include "stos.h"

/* New types */
/* --------- */
#ifndef DOUBLE
typedef double DOUBLE;
#endif
#ifndef FLOAT
typedef float FLOAT;
#endif
#ifndef IL32
typedef long IL32;
#endif
#ifndef DU8
#if !defined(ST_OSLINUX)&&!defined(PROCESSOR_SH4)
#pragma ST_device(DU8)
#endif
typedef volatile unsigned char DU8;
#endif
#ifndef DU16
#if !defined(ST_OSLINUX)&&!defined(PROCESSOR_SH4)
#pragma ST_device(DU16)
#endif
typedef volatile unsigned short DU16;
#endif
#ifndef DU32
#if !defined(ST_OSLINUX)&&!defined(PROCESSOR_SH4)
#pragma ST_device(DU32)
#endif
typedef volatile unsigned int DU32;
#endif

/* Activate STAPP services */
/* ----------------------- */
#if !defined(SDK_COMPONENT_TEST)
#define STAPP_EVENT
#define STAPP_I2C
#define STAPP_MBX
#define STAPP_PIOS
#define STAPP_SCART
#define STAPP_SYSINI
#define STAPP_UART
#define STAPP_TUNER
#define STAPP_DMA
#define STAPP_DEMUX
#define STAPP_PWM
#define STAPP_CLKRV
#define STAPP_DENC
#define STAPP_VTG
#define STAPP_VOUT
#define STAPP_LAYER
#define STAPP_BLIT
#define STAPP_GRAFIX
#define STAPP_VMIX
#define STAPP_VIDEO
#define STAPP_AUDIO
#define STAPP_FLASH
#define STAPP_BLAST
#define STAPP_USB
#define STAPP_GAM_LOADER
#define STAPP_ATAPI
#define STAPP_VFS
#define STAPP_TRACE
#define STAPP_DEMUX
#define STAPP_TCPIP
#define STAPP_SMART
#define STAPP_GUI
#define STAPP_TBX
#define STAPP_HDMI
#define STAPP_CRYPT
#define STAPP_DRM
#define STAPP_KEYSCN
#define STAPP_SUBT
#define STAPP_SPI
#define STAPP_VIN
#define STAPP_VBI
#define STAPP_INJECT
#define STAPP_PCPD
#define STAPP_POD
#define STAPP_TTX
#define STAPP_CC
#define STAPP_FSK
#define STAPP_POWER
#define STAPP_PLAYREC
#define STAPP_IPRC
#define STAPP_RESET
#define STAPP_XCPU
#define STAPP_MOCA
#define STAPP_RM
#define STAPP_PCCRD
#define STAPP_SMOOTHSTREAMING
#endif

/* Define cable modem flag if not already defined */
/* ---------------------------------------------- */
#if !defined(CABLE_MODEM_ATTACHED)
#define CABLE_MODEM_ATTACHED 0
#endif

/* Include Application headers */
/* --------------------------- */
#include "stapp_os.h"
#if defined(STAPP_EVENT)
#include "stapp_event.h"
#endif
#if defined(STAPP_I2C)
#include "stapp_i2c.h"
#endif
#if defined(STAPP_MBX)
#include "stapp_mbx.h"
#endif
#if defined(STAPP_PIOS)
#include "stapp_pios.h"
#endif
#if defined(STAPP_SCART)
#include "stapp_scart.h"
#endif
#if defined(STAPP_SYSINI)
#include "stapp_sysini.h"
#endif
#if defined(STAPP_UART)
#include "stapp_uart.h"
#endif
#if defined(STAPP_TUNER)
#include "stapp_tuner.h"
#endif
#if defined(STAPP_DMA)
#include "stapp_dma.h"
#endif
#if defined(STAPP_DEMUX)
#include "stapp_demux.h"
#include "stapp_tables.h"
#endif
#if defined(STAPP_PWM)
#include "stapp_pwm.h"
#endif
#if defined(STAPP_CLKRV)
#include "stapp_clkrv.h"
#endif
#if defined(STAPP_DENC)
#include "stapp_denc.h"
#endif
#if defined(STAPP_VTG)
#include "stapp_vtg.h"
#endif
#if defined(STAPP_VOUT)
#include "stapp_vout.h"
#endif
#if defined(STAPP_LAYER)
#include "stapp_layer.h"
#endif
#if defined(STAPP_BLIT)
#include "stapp_blit.h"
#endif
#if defined(STAPP_GRAFIX)
#include "stapp_grafix.h"
#endif
#if defined(STAPP_VMIX)
#include "stapp_vmix.h"
#endif
#if defined(STAPP_VIDEO)
#include "stapp_video.h"
#endif
#if defined(STAPP_AUDIO)
#include "stapp_audio.h"
#endif
#if defined(STAPP_FLASH)
#include "stapp_flash.h"
#endif
#if defined(STAPP_BLAST)
#include "stapp_blast.h"
#endif
#if defined(STAPP_USB)
#include "stapp_usb.h"
#endif
#if defined(STAPP_GAM_LOADER)
#include "stapp_gamloader.h"
#endif
#if defined(STAPP_ATAPI)
#include "stapp_atapi.h"
#endif
#if defined(STAPP_VFS)
#include "stapp_vfs.h"
#endif
#if defined(STAPP_TRACE)
#include "stapp_trace.h"
#endif
#if defined(STAPP_DEMUX)
#include "stapp_tapi.h"
#if defined(SERVICE_A3)
#include "stapp_tapi_a3.h"
#endif
#if defined(SERVICE_DTV)
#include "stapp_tapi_dtv.h"
#endif
#endif
#if defined(STAPP_TCPIP)
#include "stapp_tcpip.h"
#endif
#if defined(STAPP_SMART)
#include "stapp_smart.h"
#endif
#if defined(STAPP_GUI)
#include "stapp_gui.h"
#endif
#if defined(STAPP_TBX)
#include "stapp_tbx.h"
#endif
#if defined(STAPP_HDMI)
#include "stapp_hdmi.h"
#endif
#if defined(STAPP_CRYPT)
#include "stapp_crypt.h"
#endif
#if defined(STAPP_DRM)
#include "stapp_drm.h"
#endif
#if defined(STAPP_KEYSCN)
#include "stapp_keyscn.h"
#endif
#if defined(STAPP_SUBT)
#include "stapp_subt.h"
#endif
#if defined(STAPP_SPI)
#include "stapp_spi.h"
#endif
#if defined(STAPP_VIN)
#include "stapp_vin.h"
#endif
#if defined(STAPP_VBI)
#include "stapp_vbi.h"
#endif
#if defined(STAPP_INJECT)
#include "stapp_inject.h"
#endif
#if defined(STAPP_PCPD)
#include "stapp_pcpd.h"
#endif
#if defined(STAPP_POD)
#include "stapp_pod.h"
#endif
#if defined(STAPP_TTX)
#include "stapp_ttx.h"
#endif
#if defined(STAPP_CC)
#include "stapp_cc.h"
#endif
#if defined(STAPP_FSK)
#include "stapp_fsk.h"
#endif
#if defined(STAPP_POWER)
#include "stapp_power.h"
#endif
#if defined(STAPP_PLAYREC)
#include "stapp_playrec.h"
#endif
#if defined(STAPP_IPRC)
#include "stapp_iprc.h"
#endif
#if defined(STAPP_RESET)
#include "stapp_reset.h"
#endif
#if defined(STAPP_XCPU)
#include "stapp_xcpu.h"
#endif
#if defined(STAPP_MOCA)
#include "stapp_moca.h"
#endif
#if defined(STAPP_RM)
#include "stapp_rm.h"
#endif
#if defined(STAPP_PCCRD)
#include "stapp_pccrd.h"
#endif
#if defined(SDK_USE_STTEST)
#include "sttest.h"
#endif
#if defined(STAPP_SMOOTHSTREAMING)
#include "stapp_smoothstreaming.h"
#endif


/* Declare names of the devices */
/* ---------------------------- */
#if defined(STAPP_ATAPI)
extern ST_DeviceName_t ATAPI_DeviceName[];        /* "ATAx"      */
#endif
#if defined(STAPP_AUDIO)
extern ST_DeviceName_t AUD_DeviceName[];          /* "AUDx"      */
#endif
#if defined(STAPP_SYSINI)
extern ST_DeviceName_t AVMEM_DeviceName[];        /* "AVMEMx"    */
#endif
#if defined(STAPP_SYSINI)
extern ST_DeviceName_t BOOT_DeviceName[];         /* "BOOTx"     */
#endif
#if defined(STAPP_BLAST)
extern ST_DeviceName_t BLAST_DeviceName[];        /* "BLASTx"    */
#endif
#if defined(STAPP_BLIT)
extern ST_DeviceName_t BLIT_DeviceName[];         /* "BLITx"     */
#endif
#if defined(STAPP_CC)
extern ST_DeviceName_t CC_DeviceName[];           /* "CCx"       */
#endif
#if defined(STAPP_CLKRV)
extern ST_DeviceName_t CLKRV_DeviceName[];        /* "CLKRVx"    */
#endif
#if defined(STAPP_CRYPT)
extern ST_DeviceName_t CRYPT_DeviceName[];        /* "CRYPTx"    */
#endif
#if defined(STAPP_GRAFIX)
extern ST_DeviceName_t CURSOR_LAYER_DeviceName[]; /* "CURSORx"   */
#endif
#if defined(STAPP_DENC)
extern ST_DeviceName_t DENC_DeviceName[];         /* "DENCx"     */
#endif
#if defined(STAPP_DMA)
extern ST_DeviceName_t DMA_DeviceName[];          /* "DMAx"      */
#endif
#if defined(STAPP_UART)
extern ST_DeviceName_t UART_DeviceName[];         /* "COMx"      */
#endif
#if defined(STAPP_EVENT)
extern ST_DeviceName_t EVT_DeviceName[];          /* "EVTx"      */
#endif
#if defined(STAPP_FSK)
extern ST_DeviceName_t FSK_DeviceName[];          /* "FSKx"      */
#endif
#if defined(STAPP_GRAFIX)
extern ST_DeviceName_t GFX_LAYER_DeviceName[];    /* "GFXx"      */
#endif
#if defined(STAPP_HDMI)
extern ST_DeviceName_t HDMI_DeviceName[];         /* "HDMIx"     */
#endif
#if defined(STAPP_I2C)
extern ST_DeviceName_t I2C_DeviceName[];          /* "I2Cx"      */
#endif
#if defined(STAPP_INJECT)
extern ST_DeviceName_t INJECT_DeviceName[];       /* "INJECTx"   */
#endif
#if defined(STAPP_IPRC)
extern ST_DeviceName_t IPRC_DeviceName[];         /* "IPRCx      */
#endif
#if defined(STAPP_KEYSCN)
extern ST_DeviceName_t KEYSCN_DeviceName[];       /* "KEYSCNx"   */
#endif
#if defined(STAPP_LAYER)
extern ST_DeviceName_t LAYER_DeviceName[];        /* "LAYERx"    */
extern ST_DeviceName_t VLAYER_DeviceName[];       /* "VLAYERx"   */
#endif
#if defined(STAPP_MOCA)
extern ST_DeviceName_t MOCA_DeviceName[];         /* "ETHx"      */
#endif
#if defined(STAPP_PCPD)
extern ST_DeviceName_t PCPD_DeviceName[];         /* "PCPDx"     */
#endif
#if defined(STAPP_PIOS)
extern ST_DeviceName_t PIO_DeviceName[];          /* "PIOx"      */
#endif
#if defined(STAPP_PLAYREC)
extern ST_DeviceName_t PLAYREC_DeviceName[];      /* "PLAYRECx"  */
#endif
#if defined(STAPP_POD)
extern ST_DeviceName_t POD_DeviceName[];          /* "PODx"      */
#endif
#if defined(STAPP_POWER)
extern ST_DeviceName_t POWER_DeviceName[];        /* "POWERx"    */
#endif
#if 1||defined(STAPP_DEMUX)
extern ST_DeviceName_t PTI_DeviceName[];          /* "PTIx"      */
#endif
#if defined(STAPP_PWM)
extern ST_DeviceName_t PWM_DeviceName[];          /* "PWMx"      */
#endif
#if defined(STAPP_RESET)
extern ST_DeviceName_t RESET_DeviceName[];        /* "RESETx"    */
#endif
#if defined(STAPP_SMART)
extern ST_DeviceName_t SMART_DeviceName[];        /* "SMARTx"    */
#endif
#if defined(STAPP_SPI)
extern ST_DeviceName_t SPI_DeviceName[];          /* "SPIx"      */
#endif
#if defined(STAPP_SUBT)
extern ST_DeviceName_t SUBT_DeviceName[];         /* "SUBTx"     */
#endif
#if defined(STAPP_TCPIP)
extern ST_DeviceName_t NET_DeviceName[];          /* "NETx"      */
extern ST_DeviceName_t TCPIP_DeviceName[];        /* "TCPIPx"    */
#endif
#if defined(STAPP_TUNER)
extern ST_DeviceName_t TUNER_DeviceName[];        /* "TUNERx"    */
#endif
#if defined(STAPP_DEMUX)
extern ST_DeviceName_t TSMERGER_DeviceName[];     /* "TSMERGERx" */
#endif
#if defined(STAPP_TTX)
extern ST_DeviceName_t TTX_DeviceName[];          /* "TTXx"      */
#endif
#if defined(STAPP_VBI)
extern ST_DeviceName_t VBI_DeviceName[];          /* "VBIx"      */
#endif
#if defined(STAPP_VIDEO)
extern const ST_DeviceName_t VID_DeviceName[];          /* "VIDx"      */
#endif
#if defined(STAPP_VIN)
extern ST_DeviceName_t VIN_DeviceName[];          /* "VINx"      */
#endif
#if defined(STAPP_VOUT)
extern ST_DeviceName_t VOUT_DeviceName[];         /* "VOUTx"     */
#endif
#if defined(STAPP_VMIX)
extern ST_DeviceName_t VMIX_DeviceName[];         /* "VMIXx"     */
#endif
#if defined(STAPP_VTG)
extern ST_DeviceName_t VTG_DeviceName[];          /* "VTGx"      */
#endif
#if defined(STAPP_XCPU)
extern ST_DeviceName_t XCPU_DeviceName[];         /* "XCPUx"     */
#endif
#if defined(STAPP_FLASH)
extern FLASH_Descriptor_t FLASH_List[];           /* "FLASHx"    */
#endif
#if defined(STAPP_PCCRD)
extern ST_DeviceName_t PCCRD_DeviceName[];        /* "PCCRDx"    */
#endif

/* Memory partitions */
/* ----------------- */
extern ST_Partition_t  *cache_partition_sdk[];
extern ST_Partition_t  *ncache_partition_sdk[];
#if defined(DVD_SECURED_CHIP)
extern ST_Partition_t  *sec_cache_partition_sdk[];
extern ST_Partition_t  *sec_ncache_partition_sdk[];
#endif

/* Other common declarations */
/* ------------------------- */
extern ST_ClockInfo_t            CLOCK_Info;
extern STAVMEM_PartitionHandle_t AVMEM_PartitionHandle[];

/* Mode startup for SDK */
/* -------------------- */
#define SDK_INIT_DRIVER_LAYER      0x01
#define SDK_INIT_MIDDLE_LAYER      0x02
#define SDK_INIT_MODULE_LAYER      0x04
#define SDK_INIT_DEBUG_LAYER       0x08
#define SDK_INIT_TESTTOOL_SYNC     0x10
#define SDK_INIT_TESTTOOL_TASK     0x20
#define SDK_INIT_APPLICATION_LAYER 0x40
#define SDK_INIT_SECURITY          0x80
#define SDK_TERM_DRIVER_LAYER      0x01
#define SDK_TERM_MIDDLE_LAYER      0x02
#define SDK_TERM_MODULE_LAYER      0x04
#define SDK_TERM_DEBUG_LAYER       0x08
#define SDK_TERM_TESTTOOL_SYNC     0x10
#define SDK_TERM_TESTTOOL_TASK     0x20
#define SDK_TERM_APPLICATION_LAYER 0x40
#define SDK_TERM_SECURITY          0x80

/* Error code return by SDK init/term */
/* ---------------------------------- */
#define SDK_INIT_DRIVER_LAYER_FAILED      0x0FAE0001
#define SDK_INIT_MIDDLE_LAYER_FAILED      0x0FAE0002
#define SDK_INIT_MODULE_LAYER_FAILED      0x0FAE0004
#define SDK_INIT_DEBUG_LAYER_FAILED       0x0FAE0008
#define SDK_INIT_TESTTOOL_SYNC_FAILED     0x0FAE0010
#define SDK_INIT_TESTTOOL_TASK_FAILED     0x0FAE0020
#define SDK_INIT_APPLICATION_LAYER_FAILED 0x0FAE0040
#define SDK_TERM_DRIVER_LAYER_FAILED      0x0FAE0100
#define SDK_TERM_MIDDLE_LAYER_FAILED      0x0FAE0200
#define SDK_TERM_MODULE_LAYER_FAILED      0x0FAE0400
#define SDK_TERM_DEBUG_LAYER_FAILED       0x0FAE0800
#define SDK_TERM_TESTTOOL_SYNC_FAILED     0x0FAE1000
#define SDK_TERM_TESTTOOL_TASK_FAILED     0x0FAE2000
#define SDK_TERM_APPLICATION_LAYER_FAILED 0x0FAE4000

/* Prototypes */
/* ---------- */
void print(const char *format,...);
ST_ErrorCode_t STSDK_Init(U32 SDK_Mode);
ST_ErrorCode_t STSDK_Term(U32 SDK_Mode);
ST_Revision_t  STSDK_GetRevision(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

