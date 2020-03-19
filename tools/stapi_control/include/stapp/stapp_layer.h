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
 * @file     stapp_layer.h
 * @brief    This is the video layer file header.
 *           It is used by the video decoder to be able to display picture just decoded.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_LAYER_H_
#define _STAPP_LAYER_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#define VID_LAYER_VIRTUAL_MAX_NUMBER 0
#endif
#if defined(ST_5206)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
/* This flag is used mainly for STx5206 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VID_LAYER_MAX_NUMBER
#undef  VID_LAYER_MAX_DISPLAYED
#define VID_LAYER_MAX_NUMBER         1
#define VID_LAYER_MAX_DISPLAYED      1
#endif
#endif
#if defined(ST_7105)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
/* This flag is used mainly for STx5205 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VID_LAYER_MAX_NUMBER
#undef  VID_LAYER_MAX_DISPLAYED
#define VID_LAYER_MAX_NUMBER         1
#define VID_LAYER_MAX_DISPLAYED      1
#endif
#endif
#if defined(ST_7108)
#if !defined(VDP_DISPLAY_ONLY)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#else
#define VID_LAYER_MAX_NUMBER         1
#define VID_LAYER_MAX_DISPLAYED      1
#endif
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
/* This flag is used mainly for STx5211 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VID_LAYER_MAX_NUMBER
#undef  VID_LAYER_MAX_DISPLAYED
#define VID_LAYER_MAX_NUMBER         1
#define VID_LAYER_MAX_DISPLAYED      1
#endif
#endif
#if defined(ST_7141)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
#endif
#if defined(ST_H205)
#if !defined(VDP_DISPLAY_ONLY)
#define VID_LAYER_MAX_NUMBER         2
#define VID_LAYER_MAX_DISPLAYED      2
#else
#define VID_LAYER_MAX_NUMBER         1
#define VID_LAYER_MAX_DISPLAYED      1
#endif
#define VID_LAYER_VIRTUAL_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(VID_LAYER_MAX_NUMBER)
#include "stlayer.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(VID_LAYER_MAX_NUMBER)
extern STLAYER_Handle_t LAYER_Handle[VID_LAYER_MAX_NUMBER];
#endif
#if defined(VID_LAYER_VIRTUAL_MAX_NUMBER)
extern STLAYER_Handle_t VLAYER_Handle[VID_LAYER_VIRTUAL_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t LAYER_Init(void);
ST_ErrorCode_t LAYER_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

