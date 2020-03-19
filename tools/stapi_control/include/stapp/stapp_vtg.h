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
 * @file     stapp_vtg.h
 * @brief    This is the vtg (video time generator) file header.
 *           It is used to set and configure tv resolution.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VTG_H_
#define _STAPP_VTG_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VTG_MAX_NUMBER  1
#endif
#if defined(ST_5206)
#define VTG_MAX_NUMBER  2
#endif
#if defined(ST_7105)
#define VTG_MAX_NUMBER  2
#endif
#if defined(ST_7108)
#define VTG_MAX_NUMBER  2
#endif
#if defined(ST_7111)
#define VTG_MAX_NUMBER  2
#endif
#if defined(ST_7141)
#define VTG_MAX_NUMBER  2
#endif
#if defined(ST_H205)
#define VTG_MAX_NUMBER  2
#endif

/* Includes */
/* -------- */
#if defined(VTG_MAX_NUMBER)
#include "stvtg.h"
#endif

/* Global definitions for configuration */
/* ------------------------------------ */
#if !defined(DISPLAY_SD)
#error "DVD_DISPLAY_SD is not defined, please set the DVD_DISPLAY_SD environment variable"
#endif
#define D_PAL       1
#define D_NTSC      2
#define D_1080I50HZ 3
#define D_720P50HZ  4
#define D_576P50HZ  5
#define D_1080I60HZ 6
#define D_720P60HZ  7
#define D_480P60HZ  8
#define D_1080P50HZ 9

/* Vtg format declaration */
/* ---------------------- */
#if defined(VTG_MAX_NUMBER)
typedef enum VTG_Format_e
{
 VTG_FORMAT_UNKNOWN=0,
 VTG_FORMAT_SD,
 VTG_FORMAT_ED,
 VTG_FORMAT_HD
} VTG_Format_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(VTG_MAX_NUMBER)
extern STVTG_Handle_t VTG_Handle[VTG_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VTG_Init(void);
ST_ErrorCode_t VTG_Term(void);
#if defined(VTG_MAX_NUMBER)
ST_ErrorCode_t VTG_SetMode(U32 VTG_Index,STVTG_TimingMode_t  VTG_Mode);
ST_ErrorCode_t VTG_GetMode(U32 VTG_Index,STVTG_TimingMode_t *VTG_Mode,VTG_Format_t *VTG_Format);
void VTG_Set3DFollowMeAutomaticMode (BOOL FollowMe3DMode);
BOOL VTG_Get3DFollowMeAutomaticMode (void);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

