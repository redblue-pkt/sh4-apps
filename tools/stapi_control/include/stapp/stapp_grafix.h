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
 * @file     stapp_grafix.h
 * @brief    This is the graphics file header.
 *           It is used to display graphic planes on tv screen.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_GRAFIX_H_
#define _STAPP_GRAFIX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define GFX_LAYER_MAX_NUMBER 2
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(ST_5206)
#define GFX_LAYER_MAX_NUMBER 3
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(ST_7105)
#if !defined(LMI_16BIT)
#define GFX_LAYER_MAX_NUMBER 3
#else
#define GFX_LAYER_MAX_NUMBER 1
#endif
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(ST_7108)
#define GFX_LAYER_MAX_NUMBER 4
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(ST_7111)
#if !defined(LMI_16BIT)
#define GFX_LAYER_MAX_NUMBER 2
#else
#define GFX_LAYER_MAX_NUMBER 1
#endif
#define CURSOR_LAYER_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define GFX_LAYER_MAX_NUMBER 2
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(ST_H205)
#if !defined(LMI_16BIT)
#define GFX_LAYER_MAX_NUMBER 4
#else
#define GFX_LAYER_MAX_NUMBER 1
#endif
/*#define CURSOR_LAYER_MAX_NUMBER 1*/
#endif
#if defined(GFX_LAYER_MAX_NUMBER)&&defined(BLIT_MAX_NUMBER)
#define TEXT_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(GFX_LAYER_MAX_NUMBER)
#include "stgxobj.h"
#include "stlayer.h"
#include "stvtg.h"
#if defined(BLIT_MAX_NUMBER)
#include "stblit.h"
#endif
#if defined(DVD_GFX2D)
#include "st2fx.h"
#include "directfb.h"
#endif
#endif

/* External declarations */
/* --------------------- */
#if defined(GFX_LAYER_MAX_NUMBER)
extern STLAYER_Handle_t         GFX_LAYER_Handle[GFX_LAYER_MAX_NUMBER];
extern STLAYER_ViewPortHandle_t GFX_LAYER_ViewPortHandle[GFX_LAYER_MAX_NUMBER];
extern STGXOBJ_Bitmap_t         GFX_GXOBJ_Bitmap[GFX_LAYER_MAX_NUMBER];
extern STGXOBJ_Palette_t        GFX_GXOBJ_Palette[GFX_LAYER_MAX_NUMBER];
extern BOOL                     GFX_LAYER_Enable[GFX_LAYER_MAX_NUMBER];
extern BOOL                     GFX2D_IsDFBLayer[GFX_LAYER_MAX_NUMBER];
#endif
#if defined(CURSOR_LAYER_MAX_NUMBER)
extern STLAYER_Handle_t         CURSOR_LAYER_Handle[CURSOR_LAYER_MAX_NUMBER];
extern STLAYER_ViewPortHandle_t CURSOR_LAYER_ViewPortHandle[CURSOR_LAYER_MAX_NUMBER];
extern STGXOBJ_Bitmap_t         CURSOR_GXOBJ_Bitmap[CURSOR_LAYER_MAX_NUMBER];
extern STGXOBJ_Palette_t        CURSOR_GXOBJ_Palette[CURSOR_LAYER_MAX_NUMBER];
extern BOOL                     CURSOR_LAYER_Enable[CURSOR_LAYER_MAX_NUMBER];
#endif
#if defined(DVD_GFX2D)
extern ST_DeviceName_t          GFX2D_DeviceName[GFX_LAYER_MAX_NUMBER];
extern ST2FX_Handle_t           GFX2D_Handle[GFX_LAYER_MAX_NUMBER];
extern IDirectFB               *GFX2D_DFB_MainInterface;
extern IDirectFBSurface        *GFX2D_DFB_Surface[GFX_LAYER_MAX_NUMBER];
extern IDirectFBDisplayLayer   *GFX2D_DFB_Layer[GFX_LAYER_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t GRAFIX_Init(void);
ST_ErrorCode_t GRAFIX_Term(void);
ST_ErrorCode_t GRAFIX_DFBInit(void);
ST_ErrorCode_t GRAFIX_DFBTerm(void);
#if defined(GFX_LAYER_MAX_NUMBER)
ST_ErrorCode_t GRAFIX_Enable (U32 GRAFIX_Plane);
ST_ErrorCode_t GRAFIX_Disable(U32 GRAFIX_Plane);
ST_ErrorCode_t GRAFIX_Clear  (U32 GRAFIX_Plane,U32 BLIT_Index);
#endif
#if defined(CURSOR_LAYER_MAX_NUMBER)
ST_ErrorCode_t GRAFIX_CursorEnable (U32 CURSOR_Index);
ST_ErrorCode_t GRAFIX_CursorDisable(U32 CURSOR_Index);
ST_ErrorCode_t GRAFIX_CursorMove   (U32 CURSOR_Index,U32 X,U32 Y);
#endif

/* Internal Prototypes */
/* ------------------- */
#if defined(GFX_LAYER_MAX_NUMBER)&&defined(BLIT_MAX_NUMBER)
void GFXi_BLIT_Callback(STEVT_CallReason_t Reason,const ST_DeviceName_t RegistrantName,STEVT_EventConstant_t Event,const void *EventData,const void *SubscriberData_p);
#endif

/* Add support for font */
/* -------------------- */
#if defined(TEXT_MAX_NUMBER)&&defined(GFX_LAYER_MAX_NUMBER)&&defined(BLIT_MAX_NUMBER)
#include "stapp_text.h"
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

