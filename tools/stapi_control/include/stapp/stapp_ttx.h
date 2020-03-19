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
 * @file     stapp_ttx.h
 * @brief    This is the teletext file header.
 *           It is used to display teletext on tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TTX_H_
#define _STAPP_TTX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_5206)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_7105)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define TTX_MAX_NUMBER 1
#endif
#if defined(ST_H205)
#define TTX_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(TTX_MAX_NUMBER)
#include "stttx.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t TTX_Init (void);
ST_ErrorCode_t TTX_Term (void);
#if defined(TTX_MAX_NUMBER)
ST_ErrorCode_t TTX_Start(U32 PlayId,U32 LayerId,U32 Pid);
ST_ErrorCode_t TTX_Stop (U32 PlayId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

