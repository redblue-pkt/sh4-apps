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
 * @file     stapp_audio.h
 * @brief    This is the audio file header.
 *           It is used to play audio content on tv.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_AUDIO_H_
#define _STAPP_AUDIO_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   0
#define AUD_MAX_INPUTS 3
#endif
#if defined(ST_5206)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 4
#endif
#if defined(ST_7105)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 16
#endif
#if defined(ST_7108)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 4
#endif
#if defined(ST_7111)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 4
#endif
#if defined(ST_7141)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 4
#endif
#if defined(ST_H205)
#define AUD_MAX_NUMBER 1
#define AUD_MAX_CPUS   1
#define AUD_MAX_INPUTS 4
#endif

/* Includes */
/* -------- */
#if defined(AUD_MAX_NUMBER)
#include "staudlx.h"
#endif

#if defined(AUD_MAX_NUMBER)
#define INPUT_PCM_FRAME_SIZE 1536*4*10
#define AUD_STUFF_BYTES      1000
#endif
/* Constants definitions to enable transcode or multichannel */
/* --------------------------------------------------------- */
#if defined(AUD_MAX_NUMBER)&&(AUD_MAX_CPUS>=1)
/* This flag has to be set to enable multichannel support for the audio driver */
#if 0
#define AUD_MULTICHANNEL_SUPPORT
#endif
/* This flag has to be set to enable transcoding on the spdif compressed output */
/* This flag is OBSOLETE now, to be removed */
#if 0
#define AUD_TRANSCODE_SPDIF_TO_DTS_SUPPORT
#endif
/* This flag has to be set to enable DD+ over HDMI */
#if 0
#define AUD_DDPLUS_OVER_HDMI_SUPPORT
#endif
/* This flag has to be set to enable audio description */
/* This flag is OBSOLETE now, to be removed */
#if 0
#define AUD_DESCRIPTION_SUPPORT
#endif
/* This flag has to be set for dual audio decode */
/* This flag is OBSOLETE now, to be removed */
#if 0
#define AUD_DUAL_DECODE_SUPPORT
#endif
/* This flag has to be set for 16 channel mixing */
#if 0
#define AUD_16CHANNEL_MIXING
#endif
#endif

/* Audio statistics structure */
/* -------------------------- */
#if defined(AUD_MAX_NUMBER)
typedef struct AUD_Statistics_s
{
 U32 New_frame_evt;
 U32 Data_error_evt;
 U32 Pcm_underflow_evt;
 U32 Pcm_buf_complete_evt;
 U32 Fifo_overflow_evt;
 U32 New_frequency_evt;
 U32 Cdfifo_underflow_evt;
 U32 Sync_error_evt;
 U32 Low_data_level_evt;
 U32 Unknow_evt;
 FILE *File_FrameDump;
#ifdef STAUD_DEBUG_STATISTICS
 STAUD_Statistics_t AUD_Status;
#endif
} AUD_Statistics_t;
#endif

/* Type of Audio Chain supported  */
/* ------------------------------ */
typedef enum
{
 AUD_MASTER_CHAINID=0,
 AUD_SINGLE_DECODE_ANALOG_HDMI_SPDIF,
 AUD_SINGLE_DECODE_ANALOG_SPDIF,
 AUD_SINGLE_DECODE_ANALOG_HDMI,
 AUD_SINGLE_DECODE_ANALOG,
 AUD_DECODE_PCMMIX_ANALOG_HDMI_SPDIF,
 AUD_DECODE_PCMMIX_ANALOG_SPDIF,
 AUD_DECODE_PCMMIX_ANALOG_HDMI,
 AUD_DECODE_PCMMIX_ANALOG,
 AUD_DUAL_DECODE_WITHMIX_ANALOG_HDMI_SPDIF,
 AUD_DUAL_DECODE_WITHMIX_ANALOG_SPDIF,
 AUD_DUAL_DECODE_PCMMIX_ANALOG_HDMI,
 AUD_DUAL_DECODE_WITHMIX_ANALOG,
 AUD_DECODETRANSCODE_ANALOG_HDMI_SPDIF,
 AUD_DECODETRANSCODE_ANALOG_SPDIF,
 AUD_MS10_11_ANALOG_HDMI_SPDIF,
 AUD_CANVAS_ANALOG_HDMI_SPDIF,
 AUD_DUAL_DECODE_NOMIX_ANALOG_HDMI_SPDIF,
 AUD_FRAME_DUMP,
 AUD_CUSTOM_CDI_CHAINID,
 AUD_16CH_PCM_MIXING,
 AUD_GAPLESS_AUDIO,
 AUD_CUSTOM_MS11_SINGLE_DECODE,
 AUD_CUSTOM_MS11_DUAL_DECODE,
 AUD_CUSTOM_CHAINID,
 AUD_INVALID_CHAINID
} AUD_AudioChainID_t;

/* Type of Audio Profile supported  */
/* -------------------------------- */
typedef enum
{
 AUD_DAC_PROFILE_STANDARD,
 AUD_DAC_PROFILE_MS11,
 AUD_DAC_PROFILE_INVALID
} AUD_DynamicChainProfile_t;

/* ENUM to take file dump of Frame processors  */
/* ------------------------------------------- */
typedef enum
{
 AUD_FRAME_DUMP_START,
 AUD_FRAME_DUMP_STOP,
 AUD_NO_DUMP
} AUD_StatsDump_t;

/* Audio codec type */
/* ---------------- */
typedef enum
{
 AUD_CODEC_NONE    = 0x00000000,
 AUD_CODEC_MPEG1   = 0x00000001,
 AUD_CODEC_MPEG2   = 0x00000002,
 AUD_CODEC_MPEG3   = 0x00000004,
 AUD_CODEC_AC3     = 0x00000008,
 AUD_CODEC_DTS     = 0x00000010,
 AUD_CODEC_PCM     = 0x00000020,
 AUD_CODEC_ADPCM   = 0x00000040,
 AUD_CODEC_MLP     = 0x00000080,
 AUD_CODEC_AAC     = 0x00000100,
 AUD_CODEC_HEAAC   = 0x00000200,
 AUD_CODEC_DDPLUS  = 0x00000400,
 AUD_CODEC_WMA     = 0x00000800,
 AUD_CODEC_ADIF    = 0x00001000,
 AUD_CODEC_WAVE    = 0x00002000,
 AUD_CODEC_AIFF    = 0x00004000,
 AUD_CODEC_DRA     = 0x00008000,
 AUD_CODEC_REAL    = 0x00010000,
 AUD_CODEC_VORBIS  = 0x00020000,
 AUD_CODEC_FLAC    = 0x00040000,
 AUD_CODEC_DDPULSE = 0x00080000,
 AUD_CODEC_LPCM    = 0x00100000,
 AUD_CODEC_LPCMD   = 0x00200000,
 AUD_CODEC_WMAPRO  = 0x00400000,
 AUD_CODEC_DTSCD   = 0x00800000,
 AUD_CODEC_MP4     = 0x01000000,
 AUD_CODEC_RAWAAC  = 0x02000000,
 AUD_CODEC_ALL     = 0x7FFFFFFF
} AUD_CodecType_t;

/* PCM Data precision */
/* ------------------ */
typedef enum
{
 AUD_PCM_16BIT=0,
 AUD_PCM_32BIT,
 AUD_PCM_8BIT,
 AUD_PCM_20BIT,
 AUD_PCM_24BIT,
 AUD_PCM_16BIT_LE,
 AUD_PCM_16BIT_U,
 AUD_PCM_16BIT_ULE,
 AUD_PCM_8BIT_U,
 AUD_PCM_32BIT_BE,
 AUD_PCM_WS8A,
 AUD_PCM_WS8Mu 
}AUD_PCMFormat_t;

/* Audio codec definition */
/* ---------------------- */
#if defined(AUD_MAX_NUMBER)
typedef struct AUD_Codec_s
{
 STAUD_Handle_t  AUD_Handle;         /* Handle of the audio                         */
 AUD_CodecType_t AUD_Codec;          /* Codec type supported                        */
 BOOL            AUD_Used;           /* Is TRUE if this audio is used               */
 AUD_CodecType_t AUD_CodecUsed;      /* Codec type supported                        */
 U32             AUD_NumAudUsers;    /*To control output stage at injection and live*/
} AUD_Codec_t;
#endif

/* External declarations */
/* --------------------- */
#if defined(AUD_MAX_NUMBER)
extern AUD_Codec_t    AUD_Codec[AUD_MAX_NUMBER];
extern AUD_Codec_t    AUD_Input[AUD_MAX_NUMBER][AUD_MAX_INPUTS];
extern STAUD_Handle_t AUD_Handle[AUD_MAX_NUMBER];
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t AUD_Init           (void);
ST_ErrorCode_t AUD_Term           (void);
ST_ErrorCode_t AUD_Init_Codec     (AUD_CodecType_t AUD_CodecNeeded,U32 *AUD_ObjectID);
ST_ErrorCode_t AUD_Term_Codec     (U32 AUD_ObjectID);
#if defined(AUD_MAX_NUMBER)
ST_ErrorCode_t AUD_InjectStart    (U32 DeviceId,U32 InputId,U8 *FileName,STAUD_StartParams_t *AUD_StartParams,S32 NbLoops,S32 SubStrmId,S32 EnableADSupport);
ST_ErrorCode_t AUD_InjectStop     (U32 DeviceId,U32 InputId,BOOL WaitEOF);
ST_ErrorCode_t AUD_GetStatistics  (ST_DeviceName_t AUD_DeviceName,AUD_Statistics_t *Statistics);
ST_ErrorCode_t AUD_ResetStatistics(ST_DeviceName_t AUD_DeviceName,AUD_Statistics_t *Statistics);
ST_ErrorCode_t AUD_ConfigureChain (U32 ID,AUD_DynamicChainProfile_t AUD_Profile,U32 AUD_DriverIndex,BOOL AUD_ControlIPAndDec,STAUD_StreamParams_t *AUD_TransCodeParams);
ST_ErrorCode_t AUD_FrameDumpStart (U32 DeviceId,char *FileName);
ST_ErrorCode_t AUD_FrameDumpStop  (U32 DeviceId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

