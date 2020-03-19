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
 * @file     stapp_vout.h
 * @brief    This is the vout (video output stage) file header.
 *           It is used to output the different mixer outputs to hd or sd connectors.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VOUT_H_
#define _STAPP_VOUT_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VOUT_MAX_NUMBER 3
#endif
#if defined(ST_5206)
#define VOUT_MAX_NUMBER 2
#endif
#if defined(ST_7105)
#define VOUT_MAX_NUMBER 4
/* DVO is activated by setting VOUT_DVO_ENABLE in stapp_vout.h                   */
/* #define VOUT_DVO_ENABLE                                                       */
/* You need to disable  keyscan/uart/i2c/hdmi component if you want to use DVO_0 */
/* KEYSCN  is disabled  by removing KEYSCN_MAX_NUMBER  in stapp_keyscn.h         */
/* UART    is disabled  by removing UART_MAX_NUMBER    in stapp_uart.h           */
/* HDMI    is disabled  by removing HDMI_MAX_NUMBER    in stapp_hdmi.h           */
/* I2C     is disabled  by removing I2C_MAX_NUMBER     in stapp_i2c.h            */
/* #define VOUT_MAX_NUMBER 5 (DVO_0 enabled)                                     */
/* You need to disable  blast/smart component if you want to use DVO_1           */
/* BLAST   is disabled  by removing BLAST_MAX_NUMBER   in stapp_blast.h          */
/* SMART   is disabled  by removing SMART_MAX_NUMBER   in stapp_smart.h          */
/* #define VOUT_MAX_NUMBER 6 (DVO_0 and DVO_1 enabled)                           */
/* This flag is used mainly for STx5205 to route main output to aux output       */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VOUT_MAX_NUMBER
#define VOUT_MAX_NUMBER 3
#endif
#endif
#if defined(ST_7108)
#define VOUT_MAX_NUMBER 4
/* DVO is activated by setting VOUT_DVO_ENABLE in stapp_vout.h                   */
/* #define VOUT_DVO_ENABLE                                                       */
/* You need to disable smart component if you want to use DVO_0                  */
/* UART is disabled by removing UART_MAX_NUMBER in stapp_uart.h                  */
/* #define VOUT_DVO_ENABLE                                                       */
#endif
#if defined(ST_7111)
#define VOUT_MAX_NUMBER 4
/* This flag is used mainly for STx5211 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VOUT_MAX_NUMBER
#define VOUT_MAX_NUMBER 3
#endif
#endif
#if defined(ST_7141)
#define VOUT_MAX_NUMBER 4
#endif
#if defined(ST_H205)
#define VOUT_MAX_NUMBER 3
#endif

/* Includes */
/* -------- */
#if defined(VOUT_MAX_NUMBER)
#include "stvout.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(VOUT_MAX_NUMBER)
extern STVOUT_Handle_t VOUT_Handle[VOUT_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VOUT_Init(void);
ST_ErrorCode_t VOUT_Term(void);
#if defined(VOUT_MAX_NUMBER)
ST_ErrorCode_t VOUT_Create(U32 DeviceId,SCART_Format_t SCART_Format,STVOUT_Format_t Mode);
ST_ErrorCode_t VOUT_Delete(U32 DeviceId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

