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
 * @file     stapp_pccrd.h
 * @brief    This is the pccrd (PC CARD) file header.
 *           This configures the support for PC CARD using pccrd driver
 * @author   STMicroelectronics
 */

#ifndef _STAPP_PCCRD_H_
#define _STAPP_PCCRD_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(hdk5289)
/* No pccrd support */
#endif
#if defined(sdk7105)
/* No pccrd support */
#endif
#if defined(hdk7108)
/* No pccrd support */
#endif
#if defined(hdk7111)
/* Disable the support by default, as enabling
 * the DVB-CI interface alters the TS path
 */
#if 0
#define PCCRD_MAX_NUMBER  1
#endif
#endif
#if defined(b2069)
/* No pccrd support */
#endif

/* Includes */
/* -------- */
#if defined(PCCRD_MAX_NUMBER)
#include "stpccrd.h"
#endif

ST_ErrorCode_t PCCRD_Init(void);
ST_ErrorCode_t PCCRD_Term(void);
#if defined(PCCRD_MAX_NUMBER)
ST_ErrorCode_t PCCRD_DataTransfer(U32 DeviceID, U32 SlotID);
ST_ErrorCode_t PCCRD_Configure(U32 PCCRD_DeviceID, U32 SlotID, S32 Voltage,STPCCRD_CISType_t *PCCRD_CISData,char *ModuleName,U16 *BufSize);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
