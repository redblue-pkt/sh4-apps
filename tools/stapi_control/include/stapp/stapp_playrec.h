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
 * @file     stapp_playrec.h
 * @brief    This is the playrec file header.
 *           It is used to play and/or to record media contents.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_PLAYREC_H_
#define _STAPP_PLAYREC_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "playrec/playrec.h"

/* Prototypes */
/* ---------- */
ST_ErrorCode_t PLAYREC_Init(void);
ST_ErrorCode_t PLAYREC_Term(void);
#if defined(ST_H205)
ST_ErrorCode_t PLAYREC_Set_User_Connection (ST_DeviceName_t Connection_Name,S32 ClkrvInstance,PLAYREC_ConnectionType_t Type,PLAYREC_ClkrvJitterType_t CLKJitterType);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
