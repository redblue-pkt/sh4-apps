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
 * @file     stapp_vbi.h
 * @brief    This is the vbi file header.
 *           It is used to insert either close-caption, either teletext
 *           on analog video lines.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VBI_H_
#define _STAPP_VBI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_5206)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_7105)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_7108)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_7111)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_7141)
#define VBI_MAX_NUMBER 2
#endif
#if defined(ST_H205)
#define VBI_MAX_NUMBER 2
#endif

/* Includes */
/* -------- */
#if defined(VBI_MAX_NUMBER)
#include "stvbi.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(VBI_MAX_NUMBER)
extern STVBI_Handle_t VBI_Handle[VBI_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VBI_Init(void);
ST_ErrorCode_t VBI_Term(void);
#if defined (CGMSHD_SUPPORT)
ST_ErrorCode_t VBI_CGMS_Start  (U32 VBI_Index,U32 Type);
ST_ErrorCode_t VBI_CGMS_Enable (U32 VBI_Index, U8*  VBI_Data_p,U8 Length);
ST_ErrorCode_t VBI_CGMS_Disable(U32 VBI_Index);
ST_ErrorCode_t VBI_CGMS_Stop   (U32 VBI_Index);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

