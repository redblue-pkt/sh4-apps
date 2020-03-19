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
 * @file     stapp_reset.h
 * @brief    This is the reset file header.
 *           It is used to reset the system.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_RESET_H_
#define _STAPP_RESET_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No reset support */
#endif
#if defined(ST_5206)
/* No reset support */
#endif
#if defined(ST_7105)
/* No reset support */
#endif
#if defined(ST_7108)
/* No reset support */
#endif
#if defined(ST_7111)
/* No reset support */
#endif
#if defined(ST_7141)&&(CABLE_MODEM_ATTACHED==1)
#if (DOCSIS_STB_PROFILE==0)
/*#define RESET_MAX_NUMBER 2*/
#elif (DOCSIS_STB_PROFILE==1)
/*#define RESET_MAX_NUMBER 1*/
#endif
#endif
#if defined(ST_H205)
/* No reset support */
#endif
#if defined(DVD_STIPRC)
#if defined(DVD_STRESET_STUB)
extern STIPRC_DISPATCH_DECLARE(STRESET_Dispatch);
#endif
#endif

/* Includes */
/* -------- */
#if defined(RESET_MAX_NUMBER)
#include "streset.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(RESET_MAX_NUMBER)
extern STRESET_Handle_t RESET_Handle[RESET_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t RESET_Init(void);
ST_ErrorCode_t RESET_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

