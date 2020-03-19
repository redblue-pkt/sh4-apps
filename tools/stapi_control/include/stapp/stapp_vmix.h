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
 * @file     stapp_vmix.h
 * @brief    This is the vmix (video mixer) file header.
 *           It is used to mix the different video planes and graphics plane together.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VMIX_H_
#define _STAPP_VMIX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VMIX_MAX_NUMBER 1
#endif
#if defined(ST_5206)
#define VMIX_MAX_NUMBER 2
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VMIX_MAX_NUMBER
#define VMIX_MAX_NUMBER 1
#endif
#endif
#if defined(ST_7105)
#define VMIX_MAX_NUMBER 2
/* This flag is used mainly for STx5205 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VMIX_MAX_NUMBER
#define VMIX_MAX_NUMBER 1
#endif
#endif
#if defined(ST_7108)
#define VMIX_MAX_NUMBER 2
#endif
#if defined(ST_7111)
#define VMIX_MAX_NUMBER 2
/* This flag is used mainly for STx5211 to route main output to aux output */
#if defined(ENABLE_MAIN_TO_DENC_PATH)
#undef  VMIX_MAX_NUMBER
#define VMIX_MAX_NUMBER 1
#endif
#endif
#if defined(ST_7141)
#define VMIX_MAX_NUMBER 2
#endif
#if defined(ST_H205)
#define VMIX_MAX_NUMBER 2
#endif

/* Includes */
/* -------- */
#if defined(VMIX_MAX_NUMBER)
#include "stvmix.h"
#endif

/* External declarations */
/* --------------------- */
#if defined(VMIX_MAX_NUMBER)
extern STVMIX_Handle_t              VMIX_Handle[VMIX_MAX_NUMBER];
extern STVMIX_LayerDisplayParams_t *VMIX_LayerArray[VMIX_MAX_NUMBER][13];
extern STVMIX_LayerDisplayParams_t  VMIX_LayerParams[VMIX_MAX_NUMBER][13];
#endif

/* Data types for plan mixing */
/* -------------------------- */
#if defined(VMIX_MAX_NUMBER)
typedef enum VMIX_PlaneType_e
{
 VMIX_PLANE_NOPLANE=0,
 VMIX_PLANE_GFX0,
 VMIX_PLANE_GFX1,
 VMIX_PLANE_GFX2,
 VMIX_PLANE_GFX3,
 VMIX_PLANE_VID0,
 VMIX_PLANE_VID1,
 VMIX_PLANE_VID2,
 VMIX_PLANE_VID3,
 VMIX_PLANE_VIDV0,
 VMIX_PLANE_VIDV1,
 VMIX_PLANE_CUR0,
 VMIX_PLANE_CUR1,
 VMIX_PLANE_END,
 VMIX_PLANE_MAX_NUMBER=VMIX_PLANE_END
} VMIX_PlaneType_t;
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VMIX_Init                (void);
ST_ErrorCode_t VMIX_Term                (void);
ST_ErrorCode_t VMIX_Create              (SCART_Format_t SCART_Format,STVOUT_Format_t Mode);
ST_ErrorCode_t VMIX_Delete              (void);
#if defined(VMIX_MAX_NUMBER)
ST_ErrorCode_t VMIX_ConnectPlanes       (U32 VMIX_Id,VMIX_PlaneType_t VMIX_Planes[VMIX_PLANE_MAX_NUMBER]);
const char    *VMIX_PlaneTypeToLayerName(VMIX_PlaneType_t VMIX_PlaneType);
ST_ErrorCode_t VMIX_SetAspectRatio      (U32 ID, STGXOBJ_AspectRatio_t AspectRatio);
ST_ErrorCode_t VMIX_ChooseMixerMainToDencWhenMainIsSD       (int) ;
ST_ErrorCode_t VMIX_ChooseMixerAuxToDencWhenMainIsSD        (void);
void           VMIX_EnableMixerMainToDencDataPath           (void);
void           VMIX_DisableMixerMainToDencDataPath          (void);
BOOL           VMIX_GetConfigMixerMainToDencDatapath        (void);
BOOL           VMIX_GetExpectedConfigMixerMainToDencDatapath(U32*);
int            VMIX_GetDencForMixerMainToDencDatapath       (void);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

