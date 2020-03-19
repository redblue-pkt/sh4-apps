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
 * @file     stapp_cc.h
 * @brief    This is the close-caption file header.
 *           It is used to display close-caption on tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_CC_H_
#define _STAPP_CC_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_5206)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_7105)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define CC_MAX_NUMBER 1
#endif
#if defined(ST_H205)
#define CC_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(CC_MAX_NUMBER)
#include "stcc.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(CC_MAX_NUMBER)
extern STCC_Handle_t CC_Handle[CC_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t CC_Init (void);
ST_ErrorCode_t CC_Term (void);
#if defined(CC_MAX_NUMBER)
ST_ErrorCode_t CC_Start(U32 PlayId,U32 LayerId);
ST_ErrorCode_t CC_Stop (U32 PlayId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

