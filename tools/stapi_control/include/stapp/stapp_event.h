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
 * @file     stapp_event.h
 * @brief    This is the event manager file header.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_EVENT_H_
#define _STAPP_EVENT_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#define EVT_MAX_NUMBER 1

/* Includes */
/* -------- */
#if defined(EVT_MAX_NUMBER)
#include "stevt.h"
#if defined(DVD_STIPRC)
#include "stevt_relay.h"
#endif
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t EVT_Init(void);
ST_ErrorCode_t EVT_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

