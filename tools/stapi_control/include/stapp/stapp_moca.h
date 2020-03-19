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
 * @file     stapp_moca.h
 * @brief    This is the MoCA support file header
 *           It is used to configure the MoCA (Linux only) using the stmoca driver
 * @author   STMicroelectronics
 */

#ifndef _STAPP_MOCA_H_
#define _STAPP_MOCA_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(mb903)||defined(b2066)
#if (SDK_VERSION>=34)
#define MOCA_MAX_NUMBER 1
#endif
#endif
/* MoCA is not supported on OS other than Linux */
#if !defined(ST_OSLINUX)
#if defined(MOCA_MAX_NUMBER)
#undef MOCA_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(MOCA_MAX_NUMBER)
#include "stmoca.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(MOCA_MAX_NUMBER)
extern STMOCA_Info_t MOCA_Handle[MOCA_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t MOCA_Init         (void);
ST_ErrorCode_t MOCA_Term         (void);
#if defined(MOCA_MAX_NUMBER)
ST_ErrorCode_t MOCA_Enable       (U32 DeviceId);
ST_ErrorCode_t MOCA_Disable      (U32 DeviceId);
ST_ErrorCode_t MOCA_GetMacControl(U32 DeviceId,STMOCA_Status_t *MAC_Status);
ST_ErrorCode_t MOCA_GetPhyControl(U32 DeviceId,STMOCA_Status_t *PHY_Status);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

