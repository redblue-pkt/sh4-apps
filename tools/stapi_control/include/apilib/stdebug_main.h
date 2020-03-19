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
 * @file     stdebug_main.h
 * @brief    This is the STDEBUG main entry point header file.
 * @author   STMicroelectronics
 */

#ifndef _MAIN_STDEBUG_H_
#define _MAIN_STDEBUG_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include <stdio.h>
#include <string.h>
#include "stddefs.h"
#include "stdevice.h"
#include "stcommon.h"
#include "stapp_os.h"
#include "testtool.h"

/* Prototypes */
/* ---------- */
ST_ErrorCode_t TesttoolInit    (U32  DeviceId);
ST_ErrorCode_t TesttoolTerm    (U32  DeviceId);
ST_ErrorCode_t TesttoolRun     (BOOL Synchronous);
ST_ErrorCode_t ATAPI_Debug     (void);
ST_ErrorCode_t AUD_Debug       (void);
ST_ErrorCode_t BLAST_Debug     (void);
ST_ErrorCode_t BLIT_Debug      (void);
ST_ErrorCode_t CC_Debug        (void);
ST_ErrorCode_t CLKRV_Debug     (void);
ST_ErrorCode_t CRYPT_Debug     (void);
ST_ErrorCode_t DRM_Debug       (void);
ST_ErrorCode_t DEMUX_Debug     (void);
ST_ErrorCode_t DENC_Debug      (void);
ST_ErrorCode_t DMA_Debug       (void);
ST_ErrorCode_t FLASH_Debug     (void);
ST_ErrorCode_t FSK_Debug       (void);
ST_ErrorCode_t GRAFIX_Debug    (void);
ST_ErrorCode_t GUI_Debug       (void);
ST_ErrorCode_t HDMI_Debug      (void);
ST_ErrorCode_t I2C_Debug       (void);
ST_ErrorCode_t KEYSCN_Debug    (void);
ST_ErrorCode_t MISC_Debug      (void);
ST_ErrorCode_t MOCA_Debug      (void);
ST_ErrorCode_t MODULES_Debug   (void);
ST_ErrorCode_t PLAYREC_Debug   (void);
ST_ErrorCode_t PCPD_Debug      (void);
ST_ErrorCode_t PIO_Debug       (void);
ST_ErrorCode_t POD_Debug       (void);
ST_ErrorCode_t POWER_Debug     (void);
ST_ErrorCode_t PWM_Debug       (void);
ST_ErrorCode_t RACK_Debug      (void);
ST_ErrorCode_t RESET_Debug     (void);
ST_ErrorCode_t SCART_Debug     (void);
ST_ErrorCode_t SMART_Debug     (void);
ST_ErrorCode_t SPI_Debug       (void);
ST_ErrorCode_t SUBT_Debug      (void);
ST_ErrorCode_t SYS_Debug       (void);
ST_ErrorCode_t TABLE_Debug     (void);
#if defined(SECURE_FILTER_SUPPORT)
#if defined(SERVICE_DTV)
ST_ErrorCode_t TABLE_DTV_Debug (void);
#endif
#if defined(SERVICE_A3)
ST_ErrorCode_t TABLE_A3_Debug  (void);
#endif
#endif
ST_ErrorCode_t TCPIP_Debug     (void);
ST_ErrorCode_t TCPIP_Debug6    (void);
ST_ErrorCode_t TEXT_Debug      (void);
ST_ErrorCode_t TTX_Debug       (void);
ST_ErrorCode_t TRACE_Debug     (void);
ST_ErrorCode_t TUNER_Debug     (void);
ST_ErrorCode_t USB_Debug       (void);
ST_ErrorCode_t VFS_Debug       (void);
ST_ErrorCode_t VID_Debug       (void);
ST_ErrorCode_t VIN_Debug       (void);
ST_ErrorCode_t VMIX_Debug      (void);
ST_ErrorCode_t VOUT_Debug      (void);
ST_ErrorCode_t VTG_Debug       (void);
ST_ErrorCode_t RM_Debug        (void);
ST_ErrorCode_t PCCRD_Debug     (void);
ST_ErrorCode_t VBI_Debug       (void);
ST_ErrorCode_t SmoothStreaming_Debug(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

