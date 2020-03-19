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
 * @file     stapp_iprc.h
 * @brief    This is the IPRC file header.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_IPRC_H_
#define _STAPP_IPRC_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No IPRC support */
#endif
#if defined(ST_5206)
/* No IPRC support */
#endif
#if defined(ST_7105)
/* No IPRC support */
#endif
#if defined(ST_7108)
#if defined(DVD_STIPRC)
#define IPRC_MAX_NUMBER 1
#endif
#endif
#if defined(ST_7111)
/* No IPRC support */
#endif
#if defined(ST_7141)&&(CABLE_MODEM_ATTACHED==1)&&(!defined(ST_OSLINUX))
#define IPRC_MAX_NUMBER 1
#endif
#if defined(ST_H205)
/* No IPRC support */
#endif

/* Includes */
/* -------- */
#if defined(DVD_STIPRC)
#include "stiprc.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t IPRC_Init(void);
ST_ErrorCode_t IPRC_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
