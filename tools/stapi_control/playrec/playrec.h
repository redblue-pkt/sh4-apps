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
 * @file     playrec.h
 * @brief    This is the playrec (player and recorder) header file services api.
 *           It is used to play and/or to record media contents.
 * @author   STMicroelectronics
 */

#ifndef _PLAYREC_H_
#define _PLAYREC_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stddefs.h"
#include "stvid.h"
#include "staudlx.h"
#include "stpti.h"
#include "stvtg.h"
#include "stttx.h"
#include "stsubt.h"
#include "tag.h"

/* Constants */
/* --------- */
#define PLAYREC_DRIVER_ID               (0x7FAE)
#define PLAYREC_DRIVER_BASE             (PLAYREC_DRIVER_ID<<16)
#define PLAYREC_MAX_LENGTH_NAME         (1024)                     /* Maximum length size of the filename       */
#define PLAYREC_MAX_PIDS                (32)                       /* Maximum number of pids by record/playback */
#define PLAYREC_MAX_CONNECTIONS         (16)                       /* Maximum number of connections             */
#if !defined (LMI_16BIT)
#define PLAYREC_MAX_PLAYBACKS           (10)                       /* Maximum number of playbacks in parallel  */
#else
#define PLAYREC_MAX_PLAYBACKS           (1)                        /* Maximum number of playbacks in parallel - for 16 Bit DDR Platforms   */
#endif
#if defined(DVR)
#define PLAYREC_MAX_RECORDS             (8)                        /* Maximum number of records in parallel     */
#else
#define PLAYREC_MAX_RECORDS             (0)                        /* No record available for zapping box       */
#endif
#define PLAYREC_PLAY_SPEED_ONE          (100)                      /* Value for speed equal to one              */
#define PLAYREC_TIME_PRECISION_MS       (100)                      /* Time notification precision for indexing  */
#define PLAYREC_USER_DATA_SIZE          (1024)                     /* Size of user data into the stream info    */
#define PLAYREC_MIN_CIRCULAR_FILE_IN_MS (1*60*1000)                /* The minimum circular file is 1 minutes    */
#if !defined (LMI_16BIT)
#define PLAYREC_MAX_VIEWPORTS           (2)                        /* Maximum number of viewports for one video */
#else
#define PLAYREC_MAX_VIEWPORTS           (1)                        /* Maximum number of viewports for one video- for 16 Bit DDR Platforms  */
#endif
#define PLAYREC_MAX_AUDIO_DECODE        (2)                        /* Maximum of audio decoding (Dual decode)   */
#define PLAYREC_MAX_AUDIO_OUTPUTS       (4)                        /* Maximum of audio Outputs                  */

#define PLAYREC_MASK_VID_CODEC_STYLE    0x0000FFFF                 /* Mask the video codec style and retain only video Type  */

#define PLAYREC_MASK_VID_CODEC_TYPE     0xFFFF0000                 /* Mask the video codec Type and retain only video Style */


/* Stream types */
/* ------------ */
typedef enum
{
 PLAYREC_STREAMTYPE_INVALID     =   0, /* None     : Invalid type                         */
 PLAYREC_STREAMTYPE_MP1V        =   1, /* Video    : MPEG1                                */
 PLAYREC_STREAMTYPE_MP2V        =   2, /* Video    : MPEG2                                */
 PLAYREC_STREAMTYPE_MP4V        =   3, /* Video    : H264                                 */
 PLAYREC_STREAMTYPE_MP1A        =   4, /* Audio    : MPEG 1 Layer I                       */
 PLAYREC_STREAMTYPE_MP2A        =   5, /* Audio    : MPEG 1 Layer II                      */
 PLAYREC_STREAMTYPE_MP4A        =   6, /* Audio    : like HEAAC,Decoder LOAS / LATM - AAC */
 PLAYREC_STREAMTYPE_TTXT        =   7, /* Teletext : Teletext pid                         */
 PLAYREC_STREAMTYPE_SUBT        =   8, /* Subtitle : Subtitle pid                         */
 PLAYREC_STREAMTYPE_PCR         =   9, /* Synchro  : PCR pid                              */
 PLAYREC_STREAMTYPE_AC3         =  10, /* Audio    : AC3                                  */
 PLAYREC_STREAMTYPE_H264        =  11, /* Video    : H264                                 */
 PLAYREC_STREAMTYPE_MPEG4P2     =  12, /* Video    : MPEG4 Part II                        */
 PLAYREC_STREAMTYPE_VC1         =  13, /* Video    : Decode Simple/Main/Advanced profile  */
 PLAYREC_STREAMTYPE_AAC         =  14, /* Audio    : Decode ADTS - AAC                    */
 PLAYREC_STREAMTYPE_HEAAC       =  15, /* Audio    : Decoder LOAS / LATM - AAC            */
 PLAYREC_STREAMTYPE_WMA         =  16, /* Audio    : WMA,WMAPRO                           */
 PLAYREC_STREAMTYPE_DDPLUS      =  17, /* Audio    : DD+ Dolby digital                    */
 PLAYREC_STREAMTYPE_DTS         =  18, /* Audio    : DTS                                  */
 PLAYREC_STREAMTYPE_MMV         =  19, /* Video    : Multimedia content                   */
 PLAYREC_STREAMTYPE_MMA         =  20, /* Audio    : Multimedia content                   */
 PLAYREC_STREAMTYPE_AVS         =  21, /* Video    : AVS Video format                     */
 PLAYREC_STREAMTYPE_MP1A_AD     =  22, /* AudioDes : MPEG 1 Layer I                       */
 PLAYREC_STREAMTYPE_MP2A_AD     =  23, /* AudioDes : MPEG 1 Layer II                      */
 PLAYREC_STREAMTYPE_AC3_AD      =  24, /* AudioDes : AC3                                  */
 PLAYREC_STREAMTYPE_HEAAC_AD    =  25, /* AudioDes : HEAAC                                */
 PLAYREC_STREAMTYPE_LPCM        =  26, /* Audio    : LPCM                                 */
 PLAYREC_STREAMTYPE_MP1A_AUX    =  27, /* AuxAudio : MPEG 1 Layer I                       */
 PLAYREC_STREAMTYPE_MP2A_AUX    =  28, /* AuxAudio : MPEG 1 Layer II                      */
 PLAYREC_STREAMTYPE_MP4A_AUX    =  29, /* AuxAudio : like HEAAC,Decoder LOAS / LATM - AAC */
 PLAYREC_STREAMTYPE_AC3_AUX     =  30, /* AuxAudio : AC3                                  */
 PLAYREC_STREAMTYPE_AAC_AUX     =  31, /* AuxAudio : Decode ADTS - AAC                    */
 PLAYREC_STREAMTYPE_HEAAC_AUX   =  32, /* AuxAudio : Decoder LOAS / LATM - AAC            */
 PLAYREC_STREAMTYPE_WMA_AUX     =  33, /* AuxAudio : WMA,WMAPRO                           */
 PLAYREC_STREAMTYPE_DDPLUS_AUX  =  34, /* AuxAudio : DD+ Dolby digital                    */
 PLAYREC_STREAMTYPE_DTS_AUX     =  35, /* AuxAudio : DTS                                  */
 PLAYREC_STREAMTYPE_DDPULSE     =  36, /* Audio    : Dolby PULSE                          */
 PLAYREC_STREAMTYPE_DDPLUS_AD   =  37, /* AudioDes : e-AC3                                */
 PLAYREC_STREAMTYPE_DDPULSE_AD  =  38, /* AudioDes : Dolby Pulse                          */
 PLAYREC_STREAMTYPE_DDPULSE_AUX =  39, /* AuxAudio : Dolby Pulse                          */
 PLAYREC_STREAMTYPE_LPCM_AUX    =  40, /* AuxAudio : LPCM                                 */
 PLAYREC_STREAMTYPE_AUD_ID      =  41, /* Audio    : Independent Sub-stream ID            */
 PLAYREC_STREAMTYPE_DRA         =  42, /* Audio    : DRA                                  */
 PLAYREC_STREAMTYPE_DRA_AD      =  43, /* AudioDes : DRA                                  */
 PLAYREC_STREAMTYPE_DRA_AUX     =  44, /* AuxAudio : DRA                                  */
 PLAYREC_STREAMTYPE_DTS_AD      =  45, /* AudioDes : DTS                                  */
 PLAYREC_STREAMTYPE_OTHER       = 255, /* Misc     : Non identified pid                   */
} PLAYREC_StreamType_t;

/* Playrec video codec type */
/* ------------------------ */
/* Video codec types should not exceed 0x00000FFF, the upper bits are used to pass some   */
/* extra informations of the video codec like post processing information and so on ...   */
/* Look inside playrec.c source code and video.c from STAPI_SDK                           */
typedef enum
{
 PLAYREC_VID_CODEC_NONE    = 0x00000000,
 PLAYREC_VID_CODEC_MPEG    = 0x00000001,
 PLAYREC_VID_CODEC_H264    = 0x00000002,
 PLAYREC_VID_CODEC_MPEG4P2 = 0x00000003,
 PLAYREC_VID_CODEC_VC1     = 0x00000004,
 PLAYREC_VID_CODEC_FLV1    = 0x00000005,
 PLAYREC_VID_CODEC_VP6     = 0x00000006,
 PLAYREC_VID_CODEC_VP6F    = 0x00000007,
 PLAYREC_VID_CODEC_AVS     = 0x00000008,
 PLAYREC_VID_CODEC_RAW     = 0x00000009,
 PLAYREC_VID_CODEC_MJPEG   = 0x0000000A
} PLAYREC_VideoCodecType_t;

/* Playrec jitter type for demux source */
/* ------------------------------------ */
typedef enum
{
 PLAYREC_JITTER_TYPE_LOW,
 PLAYREC_JITTER_TYPE_NORMAL,
 PLAYREC_JITTER_TYPE_HIGH
} PLAYREC_ClkrvJitterType_t;


/* Playrec video context definition */
/* -------------------------------- */
typedef struct PLAYREC_VideoCodecContext_s
{
 U32                      PlayId;        /* Input parameter given the play id requesting the video codec                                             */
 PLAYREC_VideoCodecType_t VIDCodec;      /* Input parameter given the video codec required by the player                                             */
 PLAYREC_StreamType_t     VIDStreamType; /* Input parameter given the video stream type required by the player                                       */
 ST_DeviceName_t          VIDDeviceName; /* Output parameter providing the video devicename                                                          */
 STVID_Handle_t           VIDHandle;     /* Output parameter providing the video handle                                                              */
 STCLKRV_Handle_t         CLKHandle;     /* Output parameter providing the clkrv handle                                                              */
 void                    *USRParam;      /* Input/Output parameter reserved to the user (as input field set to PLAYREC_PlayInitParams.UserParameter) */
} PLAYREC_VideoCodecContext_t;

/* Playrec video viewport definition */
/* --------------------------------- */
typedef struct PLAYREC_VideoViewportContext_s
{
 U32                          VIDViewPortId;     /* Input parameter given the virtual viewport id required by the player */
 PLAYREC_VideoCodecContext_t *VIDCodecContext;   /* Input parameter given the video codec context                        */
 STVID_ViewPortHandle_t       VIDViewPortHandle; /* Output parameter providing the viewport handle                       */
 STVTG_Handle_t               VTGHandle;         /* Output parameter providing the vtg handle                            */
 void                        *USRParam;          /* Output parameter reserved to the user                                */
} PLAYREC_VideoViewportContext_t;

/* Playrec audio codec type */
/* ------------------------ */
typedef enum
{
 PLAYREC_AUD_CODEC_NONE    = 0x00000000,
 PLAYREC_AUD_CODEC_MPEG1   = 0x00000001,
 PLAYREC_AUD_CODEC_MPEG2   = 0x00000002,
 PLAYREC_AUD_CODEC_MPEG3   = 0x00000003,
 PLAYREC_AUD_CODEC_AC3     = 0x00000004,
 PLAYREC_AUD_CODEC_DTS     = 0x00000005,
 PLAYREC_AUD_CODEC_PCM     = 0x00000006,
 PLAYREC_AUD_CODEC_ADPCM   = 0x00000007,
 PLAYREC_AUD_CODEC_MLP     = 0x00000008,
 PLAYREC_AUD_CODEC_AAC     = 0x00000009,
 PLAYREC_AUD_CODEC_HEAAC   = 0x0000000A,
 PLAYREC_AUD_CODEC_DDPLUS  = 0x0000000B,
 PLAYREC_AUD_CODEC_WMA     = 0x0000000C,
 PLAYREC_AUD_CODEC_ADIF    = 0x0000000D,
 PLAYREC_AUD_CODEC_WAVE    = 0x0000000E,
 PLAYREC_AUD_CODEC_AIFF    = 0x0000000F,
 PLAYREC_AUD_CODEC_DRA     = 0x00000010,
 PLAYREC_AUD_CODEC_REAL    = 0x00000011,
 PLAYREC_AUD_CODEC_VORBIS  = 0x00000012,
 PLAYREC_AUD_CODEC_FLAC    = 0x00000013,
 PLAYREC_AUD_CODEC_DDPULSE = 0x00000014
} PLAYREC_AudioCodecType_t;

/* Playrec audio context definition */
/* -------------------------------- */
typedef struct PLAYREC_AudioCodecContext_s
{
 U32                       PlayId;        /* Input parameter given the play id requesting the video codec                                             */
 PLAYREC_AudioCodecType_t  AUDCodec;      /* Input parameter given the audio codec required by the player                                             */
 PLAYREC_StreamType_t      AUDStreamType; /* Input parameter given the audio stream type required by the player                                       */
 ST_DeviceName_t           AUDDeviceName; /* Output parameter providing the audio devicename                                                          */
 STAUD_Handle_t            AUDHandle;     /* Output parameter providing the audio handle                                                              */
 STCLKRV_Handle_t          CLKHandle;     /* Input/Output parameter providing the clkrv handle, a predefined clkr handle is proposed (video one)      */
 void                     *USRParam;      /* Input/Output parameter reserved to the user (as input field set to PLAYREC_PlayInitParams.UserParameter) */
} PLAYREC_AudioCodecContext_t;

/* Playrec subtitle codec type */
/* --------------------------- */
typedef enum
{
 PLAYREC_SUB_CODEC_NONE  = 0x00000000,
 PLAYREC_SUB_CODEC_DVB   = 0x00000001,
 PLAYREC_SUB_CODEC_DIVX  = 0x00000002,
 PLAYREC_SUB_CODEC_SRT   = 0x00000003,
 PLAYREC_SUB_CODEC_SSA   = 0x00000004,
 PLAYREC_SUB_CODEC_ASS   = 0x00000005
} PLAYREC_SubtitleCodecType_t;

/* Playrec subtitle context definition */
/* ----------------------------------- */
typedef struct PLAYREC_SubtitleCodecContext_s
{
 U32                          PlayId;        /* Input parameter given the play id requesting the subtitle                                                */
 PLAYREC_SubtitleCodecType_t  SUBCodec;      /* Input parameter given the subtitle codec required by the player                                          */
 ST_DeviceName_t              SUBDeviceName; /* Output parameter providing the subtitle devicename                                                       */
 STSUBT_Handle_t              SUBHandle;     /* Output parameter providing the subtitle handle                                                           */
 STCLKRV_Handle_t             CLKHandle;     /* Input/Output parameter providing the clkrv handle, a predefined clkr handle is proposed (video one)      */
 void                        *USRParam;      /* Input/Output parameter reserved to the user (as input field set to PLAYREC_PlayInitParams.UserParameter) */
} PLAYREC_SubtitleCodecContext_t;

/* Memory type definition */
/* ---------------------- */
typedef enum
{
 PLAYREC_MEMORY_CACHED     = 0x00000001,
 PLAYREC_MEMORY_NCACHED    = 0x00000002,
 PLAYREC_MEMORY_CONTIGUOUS = 0x00000010,
 PLAYREC_MEMORY_SECURED    = 0x00000020,
} PLAYREC_MemoryType_t;

/* File system generic type overload */
/* --------------------------------- */
#if defined(OSPLUS)
typedef struct vfs_stat64_s  PLAYREC_FS_Stat_t;
typedef struct vfs_info_s    PLAYREC_FS_Statfs_t;
typedef struct vfs_dirent_s  PLAYREC_FS_Dirent_t;
typedef struct vfs_dir_s     PLAYREC_FS_Dir_t;
#else
typedef struct stat64        PLAYREC_FS_Stat_t;
typedef struct statfs        PLAYREC_FS_Statfs_t;
typedef struct dirent        PLAYREC_FS_Dirent_t;
#endif

/* Playrec Init parameters structure definition */
/* -------------------------------------------- */
typedef struct PLAYREC_InitParams_s
{
 /* Event handler device name */
 ST_DeviceName_t           EVT_DeviceName;
 /* File Access methods */
 void*                     (*FS_Open )           (char *pathname,char *mode,...);
 U32                       (*FS_Read )           (void *ptr,U32 size,U32 nmemb,void *stream);
 U32                       (*FS_Write)           (void *ptr,U32 size,U32 nmemb,void *stream);
 U32                       (*FS_Close)           (void *stream);
 /* File position change methods */
 U32                       (*FS_Seek)            (void *stream,S64 offset,U32 whence/*==> SEEK_SET|SEEK_CUR|SEEK_END*/);
 S64                       (*FS_Tell)            (void *stream);
 /* File size method */
 S64                       (*FS_Size)            (void *stream);
 /* Remove file method */
 U32                       (*FS_Unlink)          (char *pathname);
 /* Directory access method */
 void*                     (*FS_OpenDir)         (char *pathname);
 U32                       (*FS_CloseDir)        (void *dir);
 U32                       (*FS_ReadDir)         (void *dir,PLAYREC_FS_Dirent_t *dirp);
 U32                       (*FS_MkDir)           (char *pathname);
 U32                       (*FS_RmDir)           (char *pathname);
 /* Status file & filesystem access method */
 U32                       (*FS_StatFs)          (char *pathname,PLAYREC_FS_Statfs_t *buf);
 U32                       (*FS_Stat)            (char *pathname,PLAYREC_FS_Stat_t   *buf);
 /* File resize method */
 U32                       (*FS_Truncate)        (void *stream,S64 length);
 /* File rename method */
 U32                       (*FS_Rename)          (char *oldpath,char *newpath);
 /* Crypto callback methods */
 ST_ErrorCode_t            (*CALL_Encrypt)       (void *SrcBuffer,void *DstBuffer,U32 Size,void *CryptContext,U32 CryptContextSize);
 ST_ErrorCode_t            (*CALL_Decrypt)       (void *SrcBuffer,void *DstBuffer,U32 Size,void *CryptContext,U32 CryptContextSize);
 /* Video/audio codec methods */
 ST_ErrorCode_t            (*VID_InitCodec)      (PLAYREC_VideoCodecType_t        PLAYREC_VideoCodecType,PLAYREC_VideoCodecContext_t *VIDContext);
 ST_ErrorCode_t            (*VID_TermCodec)      (PLAYREC_VideoCodecContext_t    *PLAYREC_VideoCodecContext);
 ST_ErrorCode_t            (*VID_OpenViewPort)   (PLAYREC_VideoCodecContext_t    *PLAYREC_VideoCodecContext,U32 VIDViewPortId,PLAYREC_VideoViewportContext_t *VIDViewPort);
 ST_ErrorCode_t            (*VID_CloseViewPort)  (PLAYREC_VideoViewportContext_t *PLAYREC_VideoViewportContext);
 ST_ErrorCode_t            (*AUD_InitCodec)      (PLAYREC_AudioCodecType_t        PLAYREC_AudioCodecType,PLAYREC_AudioCodecContext_t *AUDContext);
 ST_ErrorCode_t            (*AUD_TermCodec)      (PLAYREC_AudioCodecContext_t    *PLAYREC_AudioCodecContext);
 ST_ErrorCode_t            (*SUB_InitCodec)      (PLAYREC_SubtitleCodecType_t     PLAYREC_SubtitleCodecType,PLAYREC_SubtitleCodecContext_t *SUBContext);
 ST_ErrorCode_t            (*SUB_TermCodec)      (PLAYREC_SubtitleCodecContext_t *PLAYREC_SubtitleCodecContext);
 ST_ErrorCode_t            (*SUB_InitFont)       (PLAYREC_SubtitleCodecType_t     PLAYREC_SubtitleCodecType,PLAYREC_SubtitleCodecContext_t *SUBContext,U32 PLAYREC_SubtPid);
 ST_ErrorCode_t            (*SUB_TermFont)       (PLAYREC_SubtitleCodecContext_t *PLAYREC_SubtitleCodecContext);
 /* Memory allocate/deallocate methods */
 void*                     (*MEM_Allocate)       (PLAYREC_MemoryType_t PLAYREC_MemoryType,U32 Size,U32 Alignment);
 void                      (*MEM_Deallocate)     (PLAYREC_MemoryType_t PLAYREC_MemoryType,void *Buffer);
} PLAYREC_InitParams_t;

/* Playrec Terminate parameters structure definition */
/* ------------------------------------------------- */
typedef struct PLAYREC_TermParams_s
{
 BOOL ForceTerminate;
} PLAYREC_TermParams_t;

/* Errors event definition */
/* ----------------------- */
/* This error parameter is coming when PLAYREC_EVT_ERROR is notified */
typedef enum
{
 PLAYREC_PLAY_DECODING_ERROR=PLAYREC_DRIVER_BASE,  /* Error during decode  */
 PLAYREC_PLAY_READ_ERROR,                          /* Error during read    */
 PLAYREC_PLAY_SEEK_ERROR,                          /* Error during seek    */
 PLAYREC_PLAY_FILE_NOT_FOUND_ERROR,                /* Error file not found */
 PLAYREC_RECORD_WRITE_ERROR,                       /* Error during write   */
 PLAYREC_RECORD_COPY_ERROR,                        /* Error during copy    */
 PLAYREC_DRM_NOT_AUTHORIZED_ERRROR,                /* Error device not authorize */
 PLAYREC_UNKNOWN_ERROR                             /* Error undefined      */
} PLAYREC_Errors_t;

/* PLAYREC objects events */
/* ---------------------- */
typedef enum
{
 PLAYREC_EVT_END_OF_PLAYBACK=PLAYREC_DRIVER_BASE, /* Last picture displayed and last audio frame played */
 PLAYREC_EVT_END_OF_FILE,                         /* Reach end of file                                  */
 PLAYREC_EVT_ERROR,                               /* An error has occur, check error parameter          */
 PLAYREC_EVT_UNSUPPORTED_STREAM,                  /* For Emergency stop                                 */
 PLAYREC_EVT_COMMAND_COMPLETED,                   /* Asynchronous commands                              */
 PLAYREC_EVT_WRITE_CLOSE_TO_READ,                 /* Write is close to read (for timeshift)             */
 PLAYREC_EVT_WRITE_TO_READ_MARGIN_OK,             /* Write is far to read (for timeshift) margin ok     */
 PLAYREC_EVT_WRITE_DISK_SPACE_LOW,                /* When hdd space is close to full                    */
 PLAYREC_EVT_WRITE_DISK_FULL,                     /* When hdd space is full                             */
 PLAYREC_EVT_METADATA,                            /* When metadata has been detected in the playback    */
 PLAYREC_EVT_UNSUPPORTED_VIDEO_CODEC,             /* When a codec is not supported in the probing phase */
 PLAYREC_EVT_UNSUPPORTED_AUDIO_CODEC              /* When a codec is not supported in the probing phase */
} PLAYREC_Event_t;

/* This parameter is coming when EVT_COMMAND_COMPLETED is notified */
/* --------------------------------------------------------------- */
typedef enum
{
 PLAYREC_CMD_PLAY_INIT,   /* Event generated when init probing is finished after call to PLAYREC_PlayInit()          */
 PLAYREC_CMD_PLAY_START,  /* Event generated when first picture has been displayed after call to PLAYREC_PlayStart() */
 PLAYREC_CMD_PLAY_PAUSE , /* Event generated when PLAYREC_PlayPause() is really done                                 */
 PLAYREC_CMD_PLAY_RESUME, /* Event generated when PLAYREC_PlayResume() is really done                                */
 PLAYREC_CMD_PLAY_SEEK    /* Event generated when seek has been completely done after call to PLAYREC_PlaySeek()     */
} PLAYREC_ASYNC_CMD_t;

/* Metadata type */
/* ------------- */
typedef enum
{
 PLAYREC_METADATA_USER_0,
 PLAYREC_METADATA_USER_1
} PLAYREC_MetadataTag_t;

/* Object type */
/* ----------- */
typedef enum
{
 PLAYREC_OBJECT_INVALID  = 0x0,
 PLAYREC_OBJECT_PLAYBACK = 0x1,
 PLAYREC_OBJECT_RECORD   = 0x2
} PLAYREC_ObjectType_t;

/* Connection type definition */
/* -------------------------- */
typedef enum
{
 PLAYREC_CONNECTION_SRC_BUFFER = 0x01,
 PLAYREC_CONNECTION_SRC_DEMUX  = 0x02,
 PLAYREC_CONNECTION_DST_DEMUX  = 0x03,
 PLAYREC_CONNECTION_DST_BUFFER = 0x04,
 PLAYREC_CONNECTION_DST_NULL   = 0x05
} PLAYREC_ConnectionType_t;

/* Buffer src connection definition */
/* -------------------------------- */
/* This connection is used when the stream is coming from memory */
typedef struct PLAYREC_ConnectionSrcBuffer_s
{
 U32              BufferBase;                                   /* Base address of the buffer, has to be aligned to 512 bytes   */
 U32              BufferBaseKernel;                             /* Kernel address of the buffer, has to be aligned to 512 bytes */
 U32              BufferSize;                                   /* Size of the buffer                                           */
 void            *UserHandle;                                   /* Handle to passed to methods GetProducer & SetConsumer        */
 ST_ErrorCode_t (*GetProducer)(void *UserHandle,U8 **Producer); /* Method to get the producer pointer                           */
 ST_ErrorCode_t (*SetConsumer)(void *UserHandle,U8  *Consumer); /* Method to set the consumer pointer                           */
 ST_ErrorCode_t (*CallStart  )(void *UserHandle);               /* Method called by playrec when ready to start source          */
 ST_ErrorCode_t (*CallStop   )(void *UserHandle);               /* Method called by playrec when ready to stop source           */
} PLAYREC_ConnectionSrcBuffer_t;

/* Buffer dst connection definition */
/* -------------------------------- */
/* This connection is used when the stream has to go to memory */
typedef struct PLAYREC_ConnectionDstBuffer_s
{
 void            *UserHandle;                                                /* Handle to passed to methods GetProducer & SetConsumer */
 ST_ErrorCode_t (*Inject   )(void *UserHandle,U8 *Buffer,U32 SizeInPackets); /* Method to inject TS data                              */
 ST_ErrorCode_t (*CallStart)(void *UserHandle);                              /* Method called by playrec when ready to start source   */
 ST_ErrorCode_t (*CallStop )(void *UserHandle);                              /* Method called by playrec when ready to stop source    */
} PLAYREC_ConnectionDstBuffer_t;

/* Demux src connection definition */
/* ------------------------------- */
/* This connection is used when the stream is coming from the demux */
typedef struct PLAYREC_ConnectionSrcDemux_s
{
 ST_DeviceName_t           PTIDeviceName; /* Name of the PTI connected to the TS input   */
 ST_DeviceName_t           CLKDeviceName; /* Name of the clkrv for 27MHz management      */
 STPTI_Handle_t            PTIHandle;     /* Handle of the PTI connected to the TS input */
 STCLKRV_Handle_t          CLKHandle;     /* Handle of the clkrv for 27MHz management    */
 PLAYREC_ClkrvJitterType_t CLKJitterType; /* Clkrv jitter type parameter                 */
 U32                       BufferSize;    /* TS Buffer size                              */
} PLAYREC_ConnectionSrcDemux_t;

/* Demux dst connection definition */
/* ------------------------------- */
/* This connection is used to identify where to inject the TS stream */
/* in order to decode it with the internal hardware decoders         */
typedef struct PLAYREC_ConnectionDstDemux_s
{
 ST_DeviceName_t PTIDeviceName;     /* Name of the PTI connected to the FIFO input   */
 ST_DeviceName_t INJECTDeviceName;  /* Name of the injector to be used               */
 STPTI_Handle_t  PTIHandle;         /* Handle of the PTI connected to the FIFO input */
 U32             FIFOBaseAddress;   /* Fifo base address for injection               */
 U32             FIFORequestSignal; /* Request signal for DMA injection              */
} PLAYREC_ConnectionDstDemux_t;

/* Generic connection definition */
/* ----------------------------- */
typedef struct PLAYREC_Connection_s
{
 PLAYREC_ConnectionType_t Type;               /* Type of the connection                                  */
 U32                      TSPacketSize;       /* Size of a ts packet in bytes (default is 188)           */
 U32                      TSPacketHeaderSize; /* Size of a ts packet header size in bytes (default is 0) */
 union
  {
   PLAYREC_ConnectionSrcDemux_t  SrcDemux;
   PLAYREC_ConnectionDstDemux_t  DstDemux;
   PLAYREC_ConnectionSrcBuffer_t SrcBuffer;
   PLAYREC_ConnectionDstBuffer_t DstBuffer;
  } Description;
} PLAYREC_Connection_t;

/* Flags for PLAYREC seek mode */
/* --------------------------- */
typedef enum
{
 /* Seek whence */
 PLAYREC_PLAY_SEEK_SET=0,
 PLAYREC_PLAY_SEEK_CUR,
 PLAYREC_PLAY_SEEK_END
} PLAYREC_SeekFlags_t;

/* Stream data parameters */
/* ---------------------- */
typedef struct
{
 PLAYREC_StreamType_t Type;
 STPTI_Pid_t          Pid;
} PLAYREC_StreamData_t;

/* Play init parameters */
/* -------------------- */
typedef struct PLAYREC_PlayInitParams_s
{
 char                 SourceName[PLAYREC_MAX_LENGTH_NAME];       /* Name of the source, connection name or filename                    */
 char                 DestinationName[PLAYREC_MAX_LENGTH_NAME];  /* Name of the destination, should be "SWTS" by default               */
 char                 Metadatas[PLAYREC_MAX_LENGTH_NAME];        /* Metadatas given by caller                                          */
 U8                   PidsNum;                                   /* Number of pids                                                     */
 PLAYREC_StreamData_t Pids[PLAYREC_MAX_PIDS];                    /* Pid list                                                           */
 BOOL                 IsAsynchronous;                            /* Flag should set to TRUE to return immediatly                       */
 BOOL                 IsFilePartiallyDownloaded;                 /* Identify file partially downloaded (prog download)                 */
 void                *UserParameter;                             /* This parameter will be give at 4th parameter on file open callback */
 BOOL                 CryptEnable;                               /* Set this flag to TRUE to decrypt the playback                      */
 void                *CryptContext;                              /* Crypt context given by the user to PLAYREC                         */
 U32                  CryptContextSize;                          /* Size of the crypt context to be used                               */
} PLAYREC_PlayInitParams_t;

/* Play term parameters */
/* -------------------- */
typedef struct PLAYREC_PlayTermParams_s
{
 U32 Dummy;
} PLAYREC_PlayTermParams_t;

/* Play start parameters */
/* --------------------- */
typedef struct PLAYREC_PlayStartParams_s
{
 char                 SourceName[PLAYREC_MAX_LENGTH_NAME];       /* Name of the source, connection name or filename                  */
 char                 DestinationName[PLAYREC_MAX_LENGTH_NAME];  /* Name of the destination, should be "SWTS" by default             */
 char                 Metadatas[PLAYREC_MAX_LENGTH_NAME];        /* Metadatas given by caller                                        */
 U8                   PidsNum;                                   /* Number of pids                                                   */
 PLAYREC_StreamData_t Pids[PLAYREC_MAX_PIDS];                    /* Pid list                                                         */
 BOOL                 VideoEnableDisplay;                        /* This flag should be TRUE if we want PLAYREC to display the video */
 U32                  VideoLayerIdList[PLAYREC_MAX_VIEWPORTS+1]; /* List of layer id to be used for this playback                    */
 BOOL                 VideoDecodeOnce;                           /* This flag should be TRUE if we want to decode only one picture   */
 BOOL                 AudioEnableOutput;                         /* This flag should be TRUE if we want PLAYREC to unmute audio      */
 U32                  StartPositionInMs;                         /* Start position                                                   */
 S32                  StartSpeed;                                /* Start speed                                                      */
 BOOL                 CryptEnable;                               /* Set this flag to TRUE to decrypt the playback                    */
 void                *CryptContext;                              /* Crypt context given by the user to PLAYREC                       */
 U32                  CryptContextSize;                          /* Size of the crypt context to be used                             */
 STAUD_Object_t 	  InputObjects[PLAYREC_MAX_AUDIO_DECODE];
 STAUD_Object_t 	  OutputObjects[PLAYREC_MAX_AUDIO_OUTPUTS];
} PLAYREC_PlayStartParams_t;

/* Play stop parameters */
/* -------------------- */
typedef struct PLAYREC_PlayStopParams_s
{
 BOOL           VideoDisableDisplay; /* This flag should be TRUE if we want PLAYREC to disable the video plane */
 STVID_Stop_t   VideoStopMethod;     /* Define the way to stop the video decoder                               */
 STVID_Freeze_t VideoFreezeMethod;   /* Define the freeze to perform on the video decoder                      */
 STAUD_Stop_t   AudioStopMethod;     /* Define the way to stop the audio decoder                               */
 STAUD_Fade_t   AudioFadingMethod;   /* Define the fading to perform on the audio decoder                      */
} PLAYREC_PlayStopParams_t;

/* Record init parameters */
/* ---------------------- */
typedef struct PLAYREC_RecordInitParams_s
{
 char                  SourceName[PLAYREC_MAX_LENGTH_NAME];       /* Name of the source, connection name or filename                    */
 char                  DestinationName[PLAYREC_MAX_LENGTH_NAME];  /* Name of the destination, connection name or filename               */
 char                  Metadatas[PLAYREC_MAX_LENGTH_NAME];        /* Metadatas given by caller                                          */
 U8                    PidsNum;                                   /* Number of pids                                                     */
 PLAYREC_StreamData_t  Pids[PLAYREC_MAX_PIDS];                    /* Pid list                                                           */
 void                 *UserParameter;                             /* This parameter will be give at 4th parameter on file open callback */
 BOOL                  CryptEnable;                               /* Set this flag to TRUE to encrypt the record                        */
 void                 *CryptContext;                              /* Crypt context given by the user to PLAYREC                         */
 U32                   CryptContextSize;                          /* Size of the crypt context to be saved                              */
} PLAYREC_RecordInitParams_t;

/* Record term parameters */
/* ---------------------- */
typedef struct PLAYREC_RecordTermParams_s
{
 U32 Dummy;
} PLAYREC_RecordTermParams_t;

/* Record start parameters */
/* ----------------------- */
typedef struct PLAYREC_RecordStartParams_s
{
 char                 SourceName[PLAYREC_MAX_LENGTH_NAME];       /* Name of the source, connection name or filename                   */
 char                 DestinationName[PLAYREC_MAX_LENGTH_NAME];  /* Name of the destination, connection name or filename              */
 char                 Metadatas[PLAYREC_MAX_LENGTH_NAME];        /* Metadatas given by caller                                         */
 U8                   PidsNum;                                   /* Number of pids                                                    */
 PLAYREC_StreamData_t Pids[PLAYREC_MAX_PIDS];                    /* Pid list                                                          */
 S64                  FileSizeInPackets;                         /* File size in packets to limit the size of the record, 0 otherwise */
 BOOL                 CircularFile;                              /* = TRUE if we want a circular file                                 */
 U32                  CircularFileSizeInMs;                      /* Circular file size in milliseconds                                */
 BOOL                 CryptEnable;                               /* Set this flag to TRUE to encrypt the record                       */
 void                *CryptContext;                              /* Crypt context given by the user to PLAYREC                        */
 U32                  CryptContextSize;                          /* Size of the crypt context to be saved                             */
} PLAYREC_RecordStartParams_t;

/* Record stop parameters */
/* ---------------------- */
typedef struct PLAYREC_RecordStopParams_s
{
 U32 Dummy;
} PLAYREC_RecordStopParams_t;

/* Structure returned on all basic events */
/* -------------------------------------- */
typedef struct PLAYREC_EventData_s
{
 U32                  Id;
 PLAYREC_ObjectType_t Type;
} PLAYREC_EventData_t;

/* Structure returned on error events */
/* ---------------------------------- */
typedef struct PLAYREC_EventError_s
{
 U32                  Id;
 PLAYREC_ObjectType_t Type;
 PLAYREC_Errors_t     Error;
} PLAYREC_EventError_t;

/* Structure returned on commands completed events */
/* ----------------------------------------------- */
typedef struct PLAYREC_EventCommand_s
{
 U32                  Id;       /* Identifier of the playback or record           */
 PLAYREC_ObjectType_t Type;     /* Object type play or record                     */
 PLAYREC_ASYNC_CMD_t  Cmd;      /* Asynchronous cmd which has just been completed */
 ST_ErrorCode_t       ErrCode;  /* Error code returned by the command             */
 U32                  Param1;   /* Optional parameter given by the command        */
} PLAYREC_EventCommand_t;

/* Structure returned on metadata events */
/* ------------------------------------- */
typedef struct PLAYREC_EventMetadata_s
{
 U32                   Id;             /* Identifier of the playback or record        */
 PLAYREC_ObjectType_t  Type;           /* Object type play or record                  */
 PLAYREC_MetadataTag_t MetadataTag;    /* Metadata tag detected                       */
 U32                   PacketTimeInMs; /* Time in milliseconds of the metada notified */
 S64                   PacketPosition; /* Packet position of the metadata notified    */
 U32                   Data;           /* Data information of the metadata            */
} PLAYREC_EventMetadata_t;

/* Play status */
/* ----------- */
typedef struct PLAYREC_PlayStatus_s
{
 char                 SourceName[PLAYREC_MAX_LENGTH_NAME];
 char                 DestinationName[PLAYREC_MAX_LENGTH_NAME];
 char                 Metadatas[PLAYREC_MAX_LENGTH_NAME];
 U8                   PidsNum;
 PLAYREC_StreamData_t Pids[PLAYREC_MAX_PIDS];
 void                *UserParameter;
 S32                  CurrentSpeed;
 BOOL                 PlaybackPaused;
} PLAYREC_PlayStatus_t;

/* Record status */
/* ------------- */
typedef struct PLAYREC_RecordStatus_s
{
 char                 SourceName[PLAYREC_MAX_LENGTH_NAME];
 char                 DestinationName[PLAYREC_MAX_LENGTH_NAME];
 char                 Metadatas[PLAYREC_MAX_LENGTH_NAME];
 U8                   PidsNum;
 PLAYREC_StreamData_t Pids[PLAYREC_MAX_PIDS];
 void                *UserParameter;
 S64                  FileSizeInPackets;
 BOOL                 CircularFile;
 U32                  CircularFileSizeInMs;
 BOOL                 RecordPaused;
} PLAYREC_RecordStatus_t;

/* Play parameters */
/* --------------- */
typedef struct PLAYREC_PlayParams_s
{
 STVID_Handle_t          VIDHandle;
 STAUD_Handle_t          AUDHandle;
 STTTX_Handle_t          TTXHandle;
 STSUBT_Handle_t         SUBHandle;
 STCLKRV_Handle_t        CLKHandle;
 STVID_ViewPortHandle_t  VIEWHandle[PLAYREC_MAX_VIEWPORTS];
 STVTG_Handle_t          VTGHandle;
 ST_DeviceName_t         VIDDeviceName;
 ST_DeviceName_t         AUDDeviceName;
 ST_DeviceName_t         EVTDeviceName;
 BOOL                    CryptEnable;            /* = TRUE if the stream is encrypted */
 void                   *CryptContext;           /* Crypt user context buffer         */
 U32                     CryptContextSize;       /* Crypt user context size           */
 U8                     *TSBuffer;               /* TS buffer pointer                 */
 U32                     TSBufferSize;           /* TS buffer size                    */
 U32                     TSBufferFreeSize;       /* TS buffer size not used           */
 U32                     TSPacketSize;           /* TS packet size                    */
 U32                     TSPacketHeaderSize;     /* TS packet header size             */
 U8                     *PESVideoBuffer;         /* Video pes buffer pointer          */
 U32                     PESVideoBufferSize;     /* Video pes buffer size             */
 U32                     PESVideoBufferFreeSize; /* Video pes buffer size not used    */
 U8                     *PESAudioBuffer;         /* Audio pes buffer pointer          */
 U32                     PESAudioBufferSize;     /* Audio pes buffer size             */
 U32                     PESAudioBufferFreeSize; /* Audio pes buffer size not used    */
 U32                     ESVideoBufferSize;      /* Video bit buffer size             */
 U32                     ESVideoBufferFreeSize;  /* Video bit buffer size not used    */
 U32                     ESAudioBufferSize;      /* Audio bit buffer size             */
 U32                     ESAudioBufferFreeSize;  /* Audio bit buffer size not used    */
 STPTI_Pid_t             VideoPid;               /* Pti video pid                     */
 STPTI_Slot_t            VideoSlot;              /* Pti slot used for Video reception */
 U16                     VideoPacketCounter;     /* Pti slot video counter            */
 STPTI_Pid_t             AudioPid;               /* Pti audio pid                     */
 STPTI_Slot_t            AudioSlot;              /* Pti slot used for Audio reception */
 U16                     AudioPacketCounter;     /* Pti slot audio counter            */
 STPTI_Pid_t             PcrPid;                 /* Pti pcr pid                       */
 STPTI_Slot_t            PcrSlot;                /* Pti slot used for PCR reception   */
} PLAYREC_PlayParams_t;

/* Record parameters */
/* ----------------- */
typedef struct PLAYREC_RecordParams_s
{
 U8           *TSBuffer;                /* TS buffer pointer                 */
 U8           *TSBufferProducer;        /* Current TS producer               */
 U32           TSBufferSize;            /* TS buffer size                    */
 U32           TSBufferFreeSize;        /* TS buffer size not used           */
 U32           TSPacketSize;            /* TS packet size                    */
 U32           TSPacketHeaderSize;      /* TS packet header size             */
 U32           PacketTimeInMs;          /* Current packet time               */
 S64           PacketPosition;          /* Current packet position           */
 U32           PidsNum;                 /* Number of unique pids collected   */
 BOOL          CryptEnable;             /* = TRUE if the stream is encrypted */
 void         *CryptContext;            /* Crypt user context buffer         */
 U32           CryptContextSize;        /* Crypt user context size           */
 STPTI_Pid_t   Pids[PLAYREC_MAX_PIDS];  /* Pid collected list                */
 STPTI_Slot_t  Slots[PLAYREC_MAX_PIDS]; /* Slot collected list               */
} PLAYREC_RecordParams_t;

/* DRM request status */
/* ------------------ */
typedef enum
{
 PLAYREC_DRMLIC_PLAYBACK_REQUIRE_NO_LICENSE=0,
 PLAYREC_DRMLIC_PLAYBACK_REQUIRE_LICENSE,
 PLAYREC_DRMLIC_PLAYBACK_LICENSE_ALREADY_AVAILABLE
} PLAYREC_DRMLicenseState_t;

/* DRM type definition */
/* ------------------- */
typedef enum
{
 PLAYREC_DRMTYPE_NONE=0,    /* No known DRM type found in stream       */
 PLAYREC_DRMTYPE_JANUS,     /* Windows DRM for Portable Devices found  */
 PLAYREC_DRMTYPE_CARDEA,    /* Windows DRM for Networked Devices found */
 PLAYREC_DRMTYPE_DIVXHT,    /* DivX Home Theater DRM found             */
 PLAYREC_DRMTYPE_MARLIN,    /* Marlin DRM found                        */
 PLAYREC_DRMTYPE_PLAYREADY  /* PlayReady DRM found                     */
} PLAYREC_DRMType_t;

/* Play Stream infos */
/* ----------------- */
typedef struct PLAYREC_PlayStreamInfos_s
{
 char                      StreamFormatName[PLAYREC_MAX_LENGTH_NAME]; /* String which identified the format of the stream (ie "mpegts") */
 BOOL                      StreamIsSeekCapable;                       /* = TRUE if stream is seek capable                               */
 BOOL                      VideoMediaPresent;                         /* = TRUE if video media detected                                 */
 BOOL                      AudioMediaPresent;                         /* = TRUE if audio media detected                                 */
 U32                       VideoWidth;                                /* Video stream width                                             */
 U32                       VideoHeight;                               /* Video stream height                                            */
 U32                       VideoFrameRate;                            /* Number of frames per seconds * 1000                            */
 U32                       VideoFrameDurationInUs;                    /* Duration of a video frame in microseconds                      */
 U32                       VideoBitRateInKBitsPerSec;                 /* Video bitrate in kilobits per second                           */
 U32                       AudioBitRateInKBitsPerSec;                 /* Audio bitrate in kilobits per second                           */
 U32                       SeekTimeOutInMs;                           /* TimeOut to detect seek error (5 seconds by default)            */
 PLAYREC_DRMLicenseState_t DRMLicenseState;                           /* Information field regarding possible DRM license request       */
 PLAYREC_DRMType_t         DRMType;                                   /* DRM type detected                                              */
 void                     *DRMServiceHandle;                          /* Handle to the instantiated DRM Service                         */
} PLAYREC_PlayStreamInfos_t;

/* Prototypes */
/* ---------- */
ST_Revision_t  PLAYREC_GetRevision                  (void);
ST_ErrorCode_t PLAYREC_RegistrySetKey               (ST_DeviceName_t DeviceName,char *String,void *Value);
ST_ErrorCode_t PLAYREC_RegistryGetKey               (ST_DeviceName_t DeviceName,char *String,void **Value);
ST_ErrorCode_t PLAYREC_Initialize                   (ST_DeviceName_t DeviceName,PLAYREC_InitParams_t *PLAYREC_InitParams);
ST_ErrorCode_t PLAYREC_Terminate                    (ST_DeviceName_t DeviceName,PLAYREC_TermParams_t *PLAYREC_TermParams);
ST_ErrorCode_t PLAYREC_SetConnection                (char *Connection_Name,PLAYREC_Connection_t *Connection);
ST_ErrorCode_t PLAYREC_GetConnection                (char *Connection_Name,PLAYREC_Connection_t *Connection);
ST_ErrorCode_t PLAYREC_PlayInit                     (U32 PlayId,PLAYREC_PlayInitParams_t *PlayInitParams);
ST_ErrorCode_t PLAYREC_PlayFCCInit                  (U32 PlayId,PLAYREC_PlayStartParams_t *PlayStartParams);
ST_ErrorCode_t PLAYREC_PlayStart                    (U32 PlayId,PLAYREC_PlayStartParams_t *PlayStartParams);
ST_ErrorCode_t PLAYREC_PlayStop                     (U32 PlayId,PLAYREC_PlayStopParams_t *PlayStopParams);
ST_ErrorCode_t PLAYREC_PlaySeek                     (U32 PlayId,S32 TimeInMs,PLAYREC_SeekFlags_t Flags);
ST_ErrorCode_t PLAYREC_PlaySetSpeed                 (U32 PlayId,S32 Speed);
ST_ErrorCode_t PLAYREC_PlayGetSpeed                 (U32 PlayId,S32 *Speed);
ST_ErrorCode_t PLAYREC_PlayGetStatus                (U32 PlayId,PLAYREC_PlayStatus_t *PlayStatus);
ST_ErrorCode_t PLAYREC_PlayGetTime                  (U32 PlayId,U32 *BeginOfFileTimeInMs,U32 *CurrentPlayTimeInMs,U32 *EndOfFileTimeInMs);
ST_ErrorCode_t PLAYREC_PlayGetParams                (U32 PlayId,PLAYREC_PlayParams_t      *PlayParams);
ST_ErrorCode_t PLAYREC_PlayGetStreamInfos           (U32 PlayId,PLAYREC_PlayStreamInfos_t *PlayStreamInfo);
ST_ErrorCode_t PLAYREC_PlayGetTag                   (U32 PlayId,TAG_ContentFlags_t Tag,...);
ST_ErrorCode_t PLAYREC_PlayPause                    (U32 PlayId);
ST_ErrorCode_t PLAYREC_PlayResume                   (U32 PlayId);
ST_ErrorCode_t PLAYREC_PlayStep                     (U32 PlayId);
ST_ErrorCode_t PLAYREC_PlayChangePids               (U32 PlayId,U32 PidsNum,PLAYREC_StreamData_t *Pids);
ST_ErrorCode_t PLAYREC_PlayPauseRecord              (U32 PlayId,U32 RecordId,PLAYREC_RecordStartParams_t *RecordStartParams);
ST_ErrorCode_t PLAYREC_PlayInsertPacket             (U32 PlayId,U8 *Buffer,U8 NbOfPackets);
ST_ErrorCode_t PLAYREC_PlayTerm                     (U32 PlayId,PLAYREC_PlayTermParams_t *PlayTermParams);
ST_ErrorCode_t PLAYREC_PlayFCCTerm                  (U32 PlayId,PLAYREC_PlayStopParams_t *PlayStopParams);
ST_ErrorCode_t PLAYREC_PlaySetVideoOutput           (U32 PlayId,BOOL EnableVideo);
ST_ErrorCode_t PLAYREC_PlaySetAudioOutput           (U32 PlayId,BOOL EnableAudio);
ST_ErrorCode_t PLAYREC_RecordInit                   (U32 RecordId,PLAYREC_RecordInitParams_t *RecordInitParams);
ST_ErrorCode_t PLAYREC_RecordStart                  (U32 RecordId,PLAYREC_RecordStartParams_t *RecordStartParams);
ST_ErrorCode_t PLAYREC_RecordStop                   (U32 RecordId,PLAYREC_RecordStopParams_t *RecordStopParams);
ST_ErrorCode_t PLAYREC_RecordGetStatus              (U32 RecordId,PLAYREC_RecordStatus_t *RecordStatus);
ST_ErrorCode_t PLAYREC_RecordGetTime                (U32 RecordId,U32 *BeginOfFileTimeInMs,U32 *EndOfFileTimeInMs);
ST_ErrorCode_t PLAYREC_RecordGetParams              (U32 RecordId,PLAYREC_RecordParams_t *RecordParams);
ST_ErrorCode_t PLAYREC_RecordPause                  (U32 RecordId);
ST_ErrorCode_t PLAYREC_RecordResume                 (U32 RecordId);
ST_ErrorCode_t PLAYREC_RecordChangePids             (U32 RecordId,U32 PidsNum,PLAYREC_StreamData_t *Pids);
ST_ErrorCode_t PLAYREC_RecordSwitchCircularToLinear (U32 RecordId);
ST_ErrorCode_t PLAYREC_RecordInsertPacket           (U32 RecordId,U8 *Buffer,U8 NbOfPackets);
ST_ErrorCode_t PLAYREC_RecordAddMetadata            (U32 RecordId,PLAYREC_MetadataTag_t MetadataTag,U32 *PacketTimeInMs,S64 *PacketPosition,U32 Data);
ST_ErrorCode_t PLAYREC_RecordTerm                   (U32 RecordId,PLAYREC_RecordTermParams_t *RecordTermParams);
ST_ErrorCode_t PLAYREC_RecordFileRemove             (char *StreamName);
ST_ErrorCode_t PLAYREC_RecordFileCrop               (char *StreamName,U32 StartTimeInMs,U32 EndTimeInMs);
ST_ErrorCode_t PLAYREC_RecordFileCopy               (char *StreamName,char *StreamCopyName,U32 StartTimeInMs,U32 EndTimeInMs);
ST_ErrorCode_t PLAYREC_RecordFileRename             (char *CurrentStreamName,char *NewStreamName);

/* Generic curl/http api access */
/* ---------------------------- */
#if defined(PLAYREC_CURL_STATIC)
#define PLAYREC_CURL_WEAK
#else
#define PLAYREC_CURL_WEAK __attribute__ ((weak))
#endif
#if defined(PLAYREC_NET_STATIC)
#define PLAYREC_NET_WEAK
#else
#define PLAYREC_NET_WEAK __attribute__ ((weak))
#endif
void     *generic_curl_fopen (char *url,const char *operation,...)           PLAYREC_CURL_WEAK;
int       generic_curl_fclose(void *file)                                    PLAYREC_CURL_WEAK;
int       generic_curl_fseek (void *file,long long offset,int origin)        PLAYREC_CURL_WEAK;
long long generic_curl_fsize (void *file)                                    PLAYREC_CURL_WEAK;
long long generic_curl_ftell (void *file)                                    PLAYREC_CURL_WEAK;
size_t    generic_curl_fread (void *ptr,size_t size,size_t nmemb,void *file) PLAYREC_CURL_WEAK;
size_t    generic_curl_fwrite(void *ptr,size_t size,size_t nmemb,void *file) PLAYREC_CURL_WEAK;
char     *generic_curl_fgets (char *ptr,size_t size,void *file)              PLAYREC_CURL_WEAK;
int       generic_curl_feof  (void *file)                                    PLAYREC_CURL_WEAK;
void     *generic_net_fopen  (char *url, const char *mode,...)               PLAYREC_NET_WEAK;
int       generic_net_fclose (void *file)                                    PLAYREC_NET_WEAK;
long long generic_net_fseek  (void *file,long long offset,int origin)        PLAYREC_NET_WEAK;
long long generic_net_fsize  (void *file)                                    PLAYREC_NET_WEAK;
size_t    generic_net_fread  (void *ptr,size_t size,size_t nmemb,void *file) PLAYREC_NET_WEAK;
size_t    generic_net_fwrite (void *ptr,size_t size,size_t nmemb,void *file) PLAYREC_NET_WEAK;
long long generic_net_ftell  (void *file)                                    PLAYREC_NET_WEAK;


/* For debug only */
/* -------------- */
ST_ErrorCode_t PLAYREC_DebugPrint(const char *fmt,...);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif  /*_PLAYREC_H_*/

