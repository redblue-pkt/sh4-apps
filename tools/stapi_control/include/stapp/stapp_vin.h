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
 * @file     stapp_vin.h
 * @brief    This is the vin (digital video capture) file header.
 *           It is used to capture either an analog video input or a digital video input.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VIN_H_
#define _STAPP_VIN_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No capture driver */
#endif
#if defined(ST_5206)
/* No capture driver */
#endif
#if defined(ST_7105)
#define VIN_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define VIN_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define VIN_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define VIN_MAX_NUMBER 1
#endif
#if defined(ST_H205)
/* No capture port available for cut1.0, enabled for cut>=2.0 */
 #define VIN_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(VIN_MAX_NUMBER)
#include "stvin.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(VIN_MAX_NUMBER)
extern STVIN_Handle_t VIN_Handle[VIN_MAX_NUMBER];
#endif

/* Definitions of source names */
/* --------------------------- */
#define VIN_SRC_MAIN      "MAIN"
#define VIN_SRC_AUX       "AUX"
#define VIN_SRC_REMOTE    "REMOTE"
#define VIN_SRC_EXTERNAL0 "EXT0"
#define VIN_SRC_EXTERNAL1 "EXT1"
#define VIN_SRC_EXTERNAL2 "EXT2"

/* Definitions of destination names */
/* -------------------------------- */
/* The destination could be a file... coming soon */
#define VIN_DST_MAIN      "MAIN"
#define VIN_DST_AUX       "AUX"
#define VIN_DST_REMOTE    "REMOTE"
#define VIN_DST_GFX0      "GFX0"
#define VIN_DST_GFX1      "GFX1"
#define VIN_DST_GFX2      "GFX2"
#define VIN_DST_GFX3      "GFX3"

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VIN_Init     (void);
ST_ErrorCode_t VIN_Term     (void);
#if defined(VIN_MAX_NUMBER)
ST_ErrorCode_t VIN_Open     (U32 VIN_Index,U8 *SrcName,U8 *DstName);
ST_ErrorCode_t VIN_Enable   (U32 VIN_Index);
ST_ErrorCode_t VIN_Disable  (U32 VIN_Index);
ST_ErrorCode_t VIN_Pause    (U32 VIN_Index);
ST_ErrorCode_t VIN_Resume   (U32 VIN_Index);
ST_ErrorCode_t VIN_SetWindow(U32 VIN_Index,U32 SrcX,U32 SrcY,U32 SrcWidth,U32 SrcHeight,U32 DstX,U32 DstY,U32 DstWidth,U32 DstHeight);
ST_ErrorCode_t VIN_Close    (U32 VIN_Index);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
