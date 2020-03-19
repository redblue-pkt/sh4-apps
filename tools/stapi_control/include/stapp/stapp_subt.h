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
 * @file     stapp_subt.h
 * @brief    This is the subtitle file header.
 *           It is used to display dvb subtitles on graphic plane with video and audio.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_SUBT_H_
#define _STAPP_SUBT_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
/* Only one instance of subtitle for now as stsubt driver is not multi-instance capable */
#define SUBT_MAX_NUMBER 1

/* Includes */
/* -------- */
#if defined(SUBT_MAX_NUMBER)
#include "stsubt.h"
#endif

/* Subtitle types */
/* -------------- */
#if defined(SUBT_MAX_NUMBER)
typedef enum
{
 SUBT_CODEC_NONE,         /* No subtitles            */
 SUBT_CODEC_DVB,          /* DVB subtitles           */
 SUBT_CODEC_DIVX,         /* DivX subtitles          */
 SUBT_CODEC_DIVXHD,       /* DivX Plus HD subtitles  */
 SUBT_CODEC_SCTE27        /* SCTE-27 based subtitles */
} SUBT_CodecType_t;
#endif

/* Subtitle start params */
/* --------------------- */
#if defined(SUBT_MAX_NUMBER)
typedef struct SUBT_StartParams_s
{
 U32 PlayID;        /* Identifier of playrec id                           */
 U32 GFXPlaneID;    /* Identifier of gfx plane where to display subtitles */
 U16 PID;           /* Pid to be decoded and displayed                    */
 U16 CompoPageID;   /* Compo page id to be decoded and displayed          */
 U16 AnciPageID;    /* Ancillary page id to be decoded and displayed      */
} SUBT_StartParams_t;
#endif

/* Subtitle codec definition */
/* ------------------------- */
#if defined(SUBT_MAX_NUMBER)
typedef struct SUBT_Codec_s
{
 BOOL             SUBT_Used;   /* Is TRUE if this subtitle is used                  */
 U32              SUBT_PlayId; /* Player identifier attached to this subtitle codec */
 SUBT_CodecType_t SUBT_Codec;  /* Codec type supported                              */
 STSUBT_Handle_t  SUBT_Handle; /* Handle of the subtitle                            */
} SUBT_Codec_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(SUBT_MAX_NUMBER)
extern SUBT_Codec_t SUBT_Codec[SUBT_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t SUBT_Init      (void);
ST_ErrorCode_t SUBT_Term      (void);
#if defined(SUBT_MAX_NUMBER)
ST_ErrorCode_t SUBT_Init_Codec  (U32 PlayId,SUBT_CodecType_t SUBT_CodecType);
ST_ErrorCode_t SUBT_Term_Codec  (U32 PlayId);
ST_ErrorCode_t SUBT_Init_Font   (U32 PlayId,SUBT_CodecType_t SUBT_CodecType,U32 SUBT_Pid);
ST_ErrorCode_t SUBT_Term_Font   (U32 PlayId);
ST_ErrorCode_t SUBT_Enable      (U32 PlayId);
ST_ErrorCode_t SUBT_Disable     (U32 PlayId);
ST_ErrorCode_t SUBT_Start       (U32 PlayId,SUBT_StartParams_t *SUBT_StartParams);
ST_ErrorCode_t SUBT_Stop        (U32 PlayId);
ST_ErrorCode_t SUBT_SetWindow   (U32 PlayId,U32 PositionX,U32 PositionY,U32 Width,U32 Height);
ST_ErrorCode_t SUBT_Pause       (U32 PlayId);
ST_ErrorCode_t SUBT_Resume      (U32 PlayId);
ST_ErrorCode_t SUBT_ClearDisplay(U32 PlayId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

