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
 * @file     stapp_tbx.h
 * @brief    This is the stapi trace system file header.
 *           It is used to display debug traces coming from stapi components.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TBX_H_
#define _STAPP_TBX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if !defined(ST_OSLINUX)||(defined(DVD_STTBX_RELAY)&&defined(STTBX_TRACE_SIZE)&&(STTBX_TRACE_SIZE!=0))
#define TBX_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(TBX_MAX_NUMBER)
#include "sttbx.h"
#include "sttrace.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t TBX_Init(void);
ST_ErrorCode_t TBX_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

