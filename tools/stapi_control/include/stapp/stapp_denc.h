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
 * @file     stapp_denc.h
 * @brief    This is a digital encoder file header.
 *           It provides rgb/cvbs/svgs/yprpb video simple definition output to analog tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_DENC_H_
#define _STAPP_DENC_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_5206)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_7105)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define DENC_MAX_NUMBER 1
#endif
#if defined(ST_H205)
#if defined(b2067) \
 || defined(dp2010) \
 || defined(dp7000) \
 || defined(dp7001) \
 || defined(dp7050) \
 || defined(fx6010) \
 || defined(ep8000) \
 || defined(epp8000) \
 || defined(gpv8000)
#define DENC_MAX_NUMBER 1
#else
#define DENC_MAX_NUMBER 2
#endif
#endif

/* Includes */
/* -------- */
#if defined(DENC_MAX_NUMBER)
#include "stdenc.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(DENC_MAX_NUMBER)
extern STDENC_Handle_t DENC_Handle[DENC_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t DENC_Init(void);
ST_ErrorCode_t DENC_Term(void);
#if defined(DENC_MAX_NUMBER)
ST_ErrorCode_t DENC_SetMode(U32 DENC_Index,STDENC_Mode_t DENC_Mode);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

