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
 * @file     stapp_video.h
 * @brief    This is the video file header.
 *           It is used to play video content on tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VIDEO_H_
#define _STAPP_VIDEO_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define VID_MAX_CPUS   0
#define VID_MAX_NUMBER 2
#define VID_MAX_CODEC  1
#endif
#if defined(ST_5206)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  11    /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA */
#define VID_HD_NO_DECIMATION /* This flag is used to disable hd decimation               */
#if (HARDWARE_REVISION==5)
#define VID_HD_READY         /* This flag is used to allocate hd frame buffers           */
#undef  VID_HD_NO_DECIMATION /* This flag is used to enable hd decimation               */
#endif
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#endif
#if defined(ST_7105)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  11 /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA */
#define VID_HD_READY      /* This flag is used to allocate hd frame buffers           */
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#if defined (MOSAIC_SUPPORT)
#define MOSAIC_MAX_NUMBER 1  /* Maximum mosaic viewport */
#define MOSAIC_MAX_WINDOW 9 /* Maximum mosaic windows in mosaic viewport , currently 9 can be extended upto 16*/
#endif
#endif
#if defined(ST_7108)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  12    /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA/MVC */
#define VID_HD_READY         /* This flag is used to allocate hd frame buffers               */
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#if defined (MOSAIC_SUPPORT)
#define MOSAIC_MAX_NUMBER 1  /* Maximum mosaic viewport */
#define MOSAIC_MAX_WINDOW 9 /* Maximum mosaic windows in mosaic viewport , currently 9 can be extended upto 16*/
#endif
#endif
#if defined(ST_7111)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  11 /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA */
#define VID_HD_READY      /* This flag is used to allocate hd frame buffers           */
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#if defined (MOSAIC_SUPPORT)
#define MOSAIC_MAX_NUMBER 1  /* Maximum mosaic viewport */
#define MOSAIC_MAX_WINDOW 9 /* Maximum mosaic windows in mosaic viewport , currently 9 can be extended upto 16*/
#endif
#endif
#if defined(ST_7141)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  11 /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA */
#define VID_HD_READY      /* This flag is used to allocate hd frame buffers           */
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#if defined (MOSAIC_SUPPORT)
#define MOSAIC_MAX_NUMBER 1  /* Maximum mosaic viewport */
#define MOSAIC_MAX_WINDOW 9 /* Maximum mosaic windows in mosaic viewport , currently 9 can be extended upto 16*/
#endif
#endif
#if defined(ST_H205)
#define VID_MAX_CPUS   1
#define VID_MAX_NUMBER 22
#define VID_MAX_CODEC  11    /* MPEG/H264/MPEG4P2/VC1/FLV1/VP6/VP6F/RAW/AVS/MJPEG/THEORA */
#define VID_HD_READY         /* This flag is used to allocate hd frame buffers           */
#define PIP_MAX_NUMBER VID_MAX_NUMBER
#if defined (MOSAIC_SUPPORT)
#define MOSAIC_MAX_NUMBER 1  /* Maximum mosaic viewport */
#define MOSAIC_MAX_WINDOW 9 /* Maximum mosaic windows in mosaic viewport , currently 9 can be extended upto 16*/
#endif
#endif

/* PIP is disabled for 16 Bit LMI */
#if (SDK_MEMORY_CONFIG<=128)
#if defined PIP_MAX_NUMBER
#undef PIP_MAX_NUMBER
#endif
#endif

/* Includes */
/* -------- */
#if defined(VID_MAX_NUMBER)
#include "stvid.h"
#endif

/* Video codec type */
/* ---------------- */
typedef enum
{
 VID_CODEC_NONE    = 0x00000000,
 VID_CODEC_MPEG    = 0x00000001,
 VID_CODEC_H264    = 0x00000002,
 VID_CODEC_MPEG4P2 = 0x00000003,
 VID_CODEC_VC1     = 0x00000004,
 VID_CODEC_FLV1    = 0x00000005,
 VID_CODEC_VP6     = 0x00000006,
 VID_CODEC_VP6F    = 0x00000007,
 VID_CODEC_AVS     = 0x00000008,
 VID_CODEC_RAW     = 0x00000009,
 VID_CODEC_MJPEG   = 0x0000000A,
 VID_CODEC_THEORA  = 0x0000000B,
 VID_CODEC_MVC     = 0x0000000C
} VID_CodecType_t;

/* Video codec style */
/* ----------------- */
typedef enum
{
 VID_CODEC_FULL         = 0x00000000,
 VID_CODEC_QCIF         = 0x00100000,
 VID_CODEC_CIF          = 0x00200000,
 VID_CODEC_SD           = 0x00400000,
 VID_CODEC_ED           = 0x00800000,
 VID_CODEC_HD           = 0x01000000,
 VID_CODEC_ES           = 0x02000000,
 VID_CODEC_PES          = 0x04000000,
 VID_CODEC_POSTPROCESS  = 0x08000000,
 VID_CODEC_STILL        = 0x10000000,
 VID_CODEC_MOSAIC       = 0x20000000,
} VID_CodecStyle_t;

/* Video codec definition */
/* ---------------------- */
typedef struct VID_Codec_s
{
 STVID_Handle_t         VID_Handle;                                                            /* Handle of the video            */
 VID_CodecType_t        VID_Codec;                                                             /* Codec type supported           */
 U32                    VID_Index;                                                             /* Index of this codec            */
 STCLKRV_Handle_t       VID_ClkHandle;                                                         /* Handle of the stclkrv attached */
 STVID_ViewPortHandle_t VID_ViewPortHandle[VID_LAYER_MAX_NUMBER+VID_LAYER_VIRTUAL_MAX_NUMBER]; /* Viewport list handle           */
 ST_DeviceName_t        VID_DeviceName;                                                        /* Device name of the video       */
 S32                    VID_InjectStartSpeed;                                                  /* To change start speed of Video */
} VID_Codec_t;

/* External declarations */
/* --------------------- */
extern VID_Codec_t VID_Codec[VID_MAX_NUMBER];

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VID_Init         (void);
ST_ErrorCode_t VID_Term         (void);
ST_ErrorCode_t VID_Init_Codec   (VID_CodecType_t VID_CodecType,U32 *VID_Index);
ST_ErrorCode_t VID_Term_Codec   (U32 VID_Index);
ST_ErrorCode_t VID_InjectStart  (U32 VID_Index,VID_CodecType_t VID_CodecType,U8 *FileName,U32 NbLoops,U32 *LayerIdList);
ST_ErrorCode_t VID_InjectStop   (U32 VID_Index);
ST_ErrorCode_t VID_OpenViewPort (U32 VID_Index,U32 LAYER_Index);
ST_ErrorCode_t VID_CloseViewPort(U32 VID_Index,U32 LAYER_Index);

/* Pip support */
/* ----------- */
#if defined(PIP_MAX_NUMBER)
ST_ErrorCode_t PIP_Init     (void);
ST_ErrorCode_t PIP_Term     (void);
ST_ErrorCode_t PIP_Open     (U32 PIP_Index,U32 VID_Index,U32 LAYER_Index);
ST_ErrorCode_t PIP_Close    (U32 PIP_Index);
ST_ErrorCode_t PIP_Enable   (U32 PIP_Index);
ST_ErrorCode_t PIP_Disable  (U32 PIP_Index);
ST_ErrorCode_t PIP_Pause    (U32 PIP_Index);
ST_ErrorCode_t PIP_Resume   (U32 PIP_Index);
ST_ErrorCode_t PIP_SetWindow(U32 PIP_Index,U32 PositionX,U32 PositionY,U32 Width,U32 Height);
#endif

/* Mosaic support */
/* -------------- */
#if defined(MOSAIC_MAX_NUMBER)
ST_ErrorCode_t MOSAIC_Init                     (void);
ST_ErrorCode_t MOSAIC_Term                     (void);
ST_ErrorCode_t MOSAIC_Open                     (U32 MOSAIC_Index,U32 LAYER_Index,U32 *VID_IndexList);
ST_ErrorCode_t MOSAIC_Close                    (U32 MOSAIC_Index);
ST_ErrorCode_t MOSAIC_EnableWindow             (U32 MOSAIC_Index,U32 *MOSAIC_WinIdList);
ST_ErrorCode_t MOSAIC_DisableWindow            (U32 MOSAIC_Index,U32 *MOSAIC_WinIdList);
ST_ErrorCode_t MOSAIC_PauseWindow              (U32 MOSAIC_Index,U32 *MOSAIC_WinIdList);
ST_ErrorCode_t MOSAIC_ResumeWindow             (U32 MOSAIC_Index,U32 *MOSAIC_WinIdList);
ST_ErrorCode_t MOSAIC_SetFocusWindow           (U32 MOSAIC_Index,U32 MOSAIC_WinId);
ST_ErrorCode_t MOSAIC_ConfigureWindowInputRect (U32 MOSAIC_Index,U32 MOSAIC_WinId,U32 PositionX,U32 PositionY,U32 Width,U32 Height,BOOL RefreshMosaic);
ST_ErrorCode_t MOSAIC_ConfigureWindowOutputRect(U32 MOSAIC_Index,U32 MOSAIC_WinId,U32 PositionX,U32 PositionY,U32 Width,U32 Height,BOOL RefreshMosaic);
ST_ErrorCode_t MOSAIC_WinInfo                  (U32 MOSAIC_Index,U32 MOSAIC_WinId,U32 *VID_Index,STGXOBJ_Rectangle_t *MOSAIC_WinInputRect,STGXOBJ_Rectangle_t *MOSAIC_WinOutputRect,U32 *MOSAIC_WinEnable,U32 *MOSAIC_WinPause);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

