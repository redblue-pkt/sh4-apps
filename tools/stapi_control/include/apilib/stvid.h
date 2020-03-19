/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided “AS IS”, WITH ALL FAULTS. ST does not */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights,trade secrets or other intellectual property rights.    */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/
/**
 @File   stvid.h
 @brief  Video driver header file



*/
#ifndef __STVID_H
#define __STVID_H

/* Includes ----------------------------------------------------------------- */

#include "stos.h"

#ifdef ST_OSLINUX
    #include "stdevice.h"
#else
    #include "stlite.h"
#endif
#include "stmmdefs.h"

#include "stevt.h"
#include "stavmem.h"
#include "stgxobj.h"
#include "stlayer.h"
#if defined(ST_VALIDATION)&&defined(ST_VALIMSGLOG)
#include "msglog.h"
#endif /*defined(ST_VALIDATION)&&defined(ST_VALIMSGLOG)*/

#include "stclkrv.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Exported Constants ------------------------------------------------------- */

#define STVID_DRIVER_ID       21
#define STVID_DRIVER_BASE     (STVID_DRIVER_ID << 16)

#define STVID_IGNORE_ID       0xFF

#define STVID_OPTIMISED_NB_FRAME_STORE_ID  80u
#define STVID_VARIABLE_IN_FIXED_SIZE_NB_FRAME_STORE_ID 81u
#define STVID_VARIABLE_IN_FULL_PARTITION_NB_FRAME_STORE_ID 82u
#define STVID_MAX_NUMBER_OF_PAN_AND_SCAN 3

#define STVID_NUMBER_OF_CEH_INTERVALS 32
#define SCALING_FACTORS_MAX_ELEMENTS 7
#define MAX_INPUT_BUFFER 2 /* InputBufferParams is defined as an array, so that MVC or SVC transport streams with
                              multiple sub streams (one subarea per view or layer) can be supported */

enum
{
    STVID_ERROR_DECODER_RUNNING = STVID_DRIVER_BASE,
    STVID_ERROR_DECODER_RUNNING_IN_RT_MODE,
    STVID_ERROR_DECODER_PAUSING,
    STVID_ERROR_DECODER_STOPPED,
    STVID_ERROR_DECODER_NOT_PAUSING,
    STVID_ERROR_NOT_AVAILABLE,
    STVID_ERROR_DECODER_FREEZING,
    STVID_ERROR_EVENT_REGISTRATION,
    STVID_ERROR_SYSTEM_CLOCK,
    STVID_ERROR_IMPOSSIBLE_WITH_MEM_PROFILE,
    STVID_ERROR_MEMORY_ACCESS,
    STVID_ERROR_DATA_INJECTION,
    STVID_ERROR_DECODER_BUSY
    /* Add new error codes at last place, until numeric values are removed from tests scripts */
};

enum
{
    /* This event passes a (STVID_DisplayAspectRatio_t) as parameter */
    STVID_ASPECT_RATIO_CHANGE_EVT = STVID_DRIVER_BASE,
    /* This event passes no parameter */
    STVID_BACK_TO_SYNC_EVT,
    /* This event passes no parameter */
    STVID_DATA_ERROR_EVT,
    /* This event passes no parameter */
    STVID_DATA_OVERFLOW_EVT,
    /* This event passes a (STVID_DataUnderflow_t *) as parameter */
    STVID_DATA_UNDERFLOW_EVT,
    /* This event passes a (STVID_DigitalInputWindows_t *) as parameter */
    STVID_DIGINPUT_WIN_CHANGE_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_FRAME_RATE_CHANGE_EVT,
    /* This event passes a (STVID_MemoryProfile_t *) as parameter */
    STVID_IMPOSSIBLE_WITH_MEM_PROFILE_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_NEW_PICTURE_TO_BE_DISPLAYED_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_NEW_PICTURE_DECODED_EVT,
    /* This event passes no parameter */
    STVID_OUT_OF_SYNC_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_PICTURE_DECODING_ERROR_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_RESOLUTION_CHANGE_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_SCAN_TYPE_CHANGE_EVT,
    /* This event passes a (STVID_SequenceInfo_t *) as parameter */
    STVID_SEQUENCE_INFO_EVT,
    /* This event passes a (STVID_SpeedDriftThreshold_t *) as parameter */
    STVID_SPEED_DRIFT_THRESHOLD_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_STOPPED_EVT,
    /* This event passes a (STVID_UserData_t *) as parameter */
    STVID_USER_DATA_EVT,
    /* This event passes a (STVID_SynchronisationInfo_t *) as parameter */
    STVID_SYNCHRONISATION_CHECK_EVT,
    /* This event passes no parameter */
    STVID_SEQUENCE_END_CODE_EVT,
    /* This event passes a (STVID_PictureInfos_t *) as parameter */
    STVID_NEW_PICTURE_ORDERED_EVT,
    /* This event passes a (STVID_ParsedData_t *) as parameter */
    STVID_PARSED_DATA_EVT,
    /* This event passes a (STVID_CRCCheckResult_t *) as parameter */
    STVID_END_OF_CRC_CHECK_EVT,  /* Debug only */
     /* This event passes a (STVID_CRCDataMessage_t *) as parameter */
    STVID_NEW_CRC_QUEUED_EVT,
    /* This event passes a (STVID_FieldInfos_t *) as parameter */
    STVID_NEW_FIELD_TO_BE_DISPLAYED_EVT,
    /* This event passes a (STVID_UnsupportedStreamType_t *) as parameter */
    STVID_UNSUPPORTED_STREAM_TYPE_EVT,
    /* This event passes a (STVID_PictureCharacteristicsChangeParams_t *) as parameter */
    STVID_PICTURE_CHARACTERISTICS_CHANGE_EVT,
    /* This event passes no parameter */
    STVID_SPEED_SLAVE_MODE_LIMIT_REACHED_EVT,
    /* This event passes a (STVID_MarkerData_t *) as parameter */
    STVID_MARKER_DETECTION_EVT,
    /* This event passes no parameter */
    STVID_NO_MORE_PICTURE_TO_BE_DISPLAYED_EVT,
    /* This event passes a (STVID_NotificationEventParams_t *) as parameter */
    STVID_NOTIFICATION_EVT,
};

typedef enum STVID_BroadcastProfile_e
{
    STVID_BROADCAST_DVB     = 1,
    STVID_BROADCAST_DIRECTV = 2,
    STVID_BROADCAST_ATSC    = 4,
    STVID_BROADCAST_DVD     = 8,
    STVID_BROADCAST_ARIB    = 16
} STVID_BroadcastProfile_t;

typedef enum STVID_Clear_e
{
    STVID_CLEAR_DISPLAY_BLACK_FILL            = 1,
    STVID_CLEAR_DISPLAY_PATTERN_FILL          = 2,
    STVID_CLEAR_FREEING_DISPLAY_FRAME_BUFFER  = 4
} STVID_Clear_t;

typedef enum STVID_CodingMode_e
{
    STVID_CODING_MODE_MB    = 1
} STVID_CodingMode_t;

typedef enum STVID_ColorType_e
{
    STVID_COLOR_TYPE_YUV420 = 1,
    STVID_COLOR_TYPE_YUV422 = 2,
    STVID_COLOR_TYPE_YUV444 = 4
} STVID_ColorType_t;

typedef enum STVID_DecimationFactor_e
{
    STVID_DECIMATION_FACTOR_NONE             = 0,
    STVID_DECIMATION_FACTOR_H2               = 1,
    STVID_DECIMATION_FACTOR_V2               = 2,
    STVID_DECIMATION_FACTOR_H4               = 4,
    STVID_DECIMATION_FACTOR_V4               = 8,
    STVID_DECIMATION_FACTOR_H4_ADAPTATIVE_H2 = 16,
    STVID_DECIMATION_FACTOR_2                = (STVID_DECIMATION_FACTOR_H2 | STVID_DECIMATION_FACTOR_V2),
    STVID_DECIMATION_FACTOR_4                = (STVID_DECIMATION_FACTOR_H4 | STVID_DECIMATION_FACTOR_V4),
    STVID_DECIMATION_FACTOR_420              = 32,
    STVID_POSTPROCESS_RECONSTRUCTION         = 64,
    STVID_WATERMARK_RECONSTRUCTION           = 128
} STVID_DecimationFactor_t;

typedef enum STVID_PostProcessing_Command_e
{
    STVID_POSTPROCESSING_ENABLE_DEBLOCKING   =1,
    STVID_POSTPROCESSING_DISABLE_DEBLOCKING  =2,
    STVID_POSTPROCESSING_ENABLE_DERINGING    =4,
    STVID_POSTPROCESSING_DISABLE_DERINGING   =8,
    STVID_POSTPROCESSING_DEBLOCKING_STRENGTH =16,
    STVID_POSTPROCESSING_DERINGING_STRENGTH  =32
} STVID_POSTPROCESSING_Command_t;

typedef enum STVID_PostProcessing_Strength_e
{
    STVID_POSTPROCESSING_STRENGTH_MIN    =0,
    STVID_POSTPROCESSING_STRENGTH_MEDIUM =128,
    STVID_POSTPROCESSING_STRENGTH_MAX    =255
} STVID_PostProcessing_Strength_t;

typedef struct STVID_PostProcessing_Param_s
{
    struct
    {
        STVID_PostProcessing_Strength_t DeblockingStrength;
    } PPDeblocking;
    struct
    {
        STVID_PostProcessing_Strength_t DeringingStrength;
    } PPDeringing;
} STVID_POSTPROCESSING_Param_t;

typedef enum STVID_DecodedPictures_e
{
    STVID_DECODED_PICTURES_ALL,
    STVID_DECODED_PICTURES_IP,
    STVID_DECODED_PICTURES_I,
    STVID_DECODED_PICTURES_FIRST_I,
    STVID_DECODED_PICTURES_I_NO_FLUSH
} STVID_DecodedPictures_t;

typedef enum STVID_FlushMode_e
{
    STVID_FLUSH_CANCEL,
    STVID_FLUSH_ALL,
    STVID_FLUSH_FROM_DISCONTINUITY_TO_PTS,
    STVID_FLUSH_FROM_PTS_TO_DISCONTINUITY,
    STVID_FLUSH_FROM_PTS,
    STVID_FLUSH_TO_PTS,
    STVID_FLUSH_FROM_DISCONTINUITY,
    STVID_FLUSH_TO_DISCONTINUITY
} STVID_FlushMode_t;

typedef enum STVID_InjectionMode_e
{
    STVID_INJECTION_DEFAULT,
    STVID_INJECTION_LIVE,
    STVID_INJECTION_LOCAL,
    STVID_INJECTION_LOCAL_NORAP,
    STVID_INJECTION_LIVE_IP
} STVID_InjectionMode_t;

/* Enum dimensioning the maximum resolution the decoder will have to deal with */
typedef enum STVID_FormatLevel_e
{
    STVID_FORMAT_LEVEL_DEFAULT = 0, /* Maximum supported by the platform (SD, HD) */
    STVID_FORMAT_LEVEL_SELF_DETECT, /* The video driver may allocate its frame buffers dynamically */
    /* Explicit maximum resolution support... */
    STVID_FORMAT_LEVEL_QCIF,        /* Max 176 x 144 pixels @ 30Hz */
    STVID_FORMAT_LEVEL_CIF,         /* Max 360 x 288 pixels @ 30Hz */
    STVID_FORMAT_LEVEL_SD,          /* Max 720 x 576 pixels @ 30Hz */
    STVID_FORMAT_LEVEL_HD_720,      /* Max 1280 x 720 pixels @ 60Hz */
    STVID_FORMAT_LEVEL_HD_1080      /* Max 1920 x 1088 pixels @ 60Hz */
} STVID_FormatLevel_t;

/* This structure is containing kind of bit field of possible context. */
typedef enum STVID_Context_e
{
   STVID_CONTEXT_STANDARD        		= 0<<0,	/* Activate default context */
   STVID_CONTEXT_MOSAIC          		= 1<<0,	/* Mosaic context */
   STVID_CONTEXT_IP_INJECTION    		= 1<<1,	/* Enables an Internet Protocol like injection context (jittering) */
   STVID_CONTEXT_DVR             		= 1<<2, /* Enables a full DVR feature context including fwd and bwd */
   STVID_CONTEXT_DVR_I_ONLY_BWD  		= 1<<3, /* Forces the I_ONLY backward trickmode in case of DVR plateforms */
   STVID_CONTEXT_NORASTER_MAIN_BUFFER 	= 1<<4  /* Forces the memory optimization so that the main resconstruction buffer are not allocated with Raster attribute */
} STVID_Context_t;


/* To make clean application update for STVID_InitContext_t */
#define STVID_INIT_CONTEXT_DEFAULT (NULL)

/* Chips base (7 bits) */
/* At the beginning, it was 8 bits, but to avoid problems related to signed
 * integers, one bit is never used in the DeviceType */
#define STVID_DEVICE_TYPE_BASE_FIRST_BIT          0
#define STVID_DEVICE_TYPE_BASE_NUMBER_OF_BITS     7
#define STVID_DEVICE_TYPE_BASE_MASK               (((1 << STVID_DEVICE_TYPE_BASE_NUMBER_OF_BITS) - 1) << STVID_DEVICE_TYPE_BASE_FIRST_BIT)

/* Inputs (8 bits) */
#define STVID_DEVICE_TYPE_INPUT_FIRST_BIT         (STVID_DEVICE_TYPE_BASE_FIRST_BIT + STVID_DEVICE_TYPE_BASE_NUMBER_OF_BITS)
#define STVID_DEVICE_TYPE_INPUT_NUMBER_OF_BITS    8
#define STVID_DEVICE_TYPE_INPUT_MASK              (((1 << STVID_DEVICE_TYPE_INPUT_NUMBER_OF_BITS) - 1) << STVID_DEVICE_TYPE_INPUT_FIRST_BIT)
#define STVID_DEVICE_TYPE_INPUT_MPEG2             1
#define STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED      2
#define STVID_DEVICE_TYPE_INPUT_H264              3
#define STVID_DEVICE_TYPE_INPUT_VC1               4
#define STVID_DEVICE_TYPE_INPUT_MPEG4P2           5
#define STVID_DEVICE_TYPE_INPUT_AVS_SD            6
#define STVID_DEVICE_TYPE_INPUT_AVS_HD            7
#define STVID_DEVICE_TYPE_INPUT_VP6               8
#define STVID_DEVICE_TYPE_INPUT_FLV1              9
#define STVID_DEVICE_TYPE_INPUT_RV                10
#define STVID_DEVICE_TYPE_INPUT_MJPEG             11
#define STVID_DEVICE_TYPE_INPUT_JPEG              12
#define STVID_DEVICE_TYPE_INPUT_THEORA            13
#define STVID_DEVICE_TYPE_INPUT_H264_MVC          14

/* Display HW cells (managed as bits because of dual display) (10 bits) */
#define STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT       (STVID_DEVICE_TYPE_INPUT_FIRST_BIT + STVID_DEVICE_TYPE_INPUT_NUMBER_OF_BITS)
#define STVID_DEVICE_TYPE_DISPLAY_NUMBER_OF_BITS  10
#define STVID_DEVICE_TYPE_DISPLAY_MASK            (((1 << STVID_DEVICE_TYPE_DISPLAY_NUMBER_OF_BITS) - 1) << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT)
#define STVID_DEVICE_TYPE_DISPLAY_COMPOSITOR      (1 << 0)
#define STVID_DEVICE_TYPE_DISPLAY_SDDISPO2        (1 << 4)
#define STVID_DEVICE_TYPE_DISPLAY_PIPE            (1 << 5)
#define STVID_DEVICE_TYPE_DISPLAY_HQVDP           (1 << 6)

/* Decode HW cells (3 bits) */
#define STVID_DEVICE_TYPE_DECODE_FIRST_BIT        (STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT + STVID_DEVICE_TYPE_DISPLAY_NUMBER_OF_BITS)
#define STVID_DEVICE_TYPE_DECODE_NUMBER_OF_BITS   3
#define STVID_DEVICE_TYPE_DECODE_MASK             (((1 << STVID_DEVICE_TYPE_DECODE_NUMBER_OF_BITS) - 1) << STVID_DEVICE_TYPE_DECODE_FIRST_BIT)
#define STVID_DEVICE_TYPE_DECODE_LCMPEGX1         4
#define STVID_DEVICE_TYPE_DECODE_DELTA            5

/* Miscellaneous characteristics (3 bits) */
#define STVID_DEVICE_TYPE_MISC_FIRST_BIT          (STVID_DEVICE_TYPE_DECODE_FIRST_BIT + STVID_DEVICE_TYPE_DECODE_NUMBER_OF_BITS)
#define STVID_DEVICE_TYPE_MISC_NUMBER_OF_BITS     3
#define STVID_DEVICE_TYPE_MISC_MASK               (((1 << STVID_DEVICE_TYPE_MISC_NUMBER_OF_BITS) - 1) << STVID_DEVICE_TYPE_MISC_FIRST_BIT)
#define STVID_DEVICE_TYPE_MISC_INJECT             (1 << 0)
#define STVID_DEVICE_TYPE_MISC_HD                 (1 << 1)
#define STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT     (1 << 2)

/* Device types bases */
#define STVID_DEVICE_TYPE_CHIP_BASE 0

typedef enum
{
    STVID_DEVICE_TYPE_5162_BASE = STVID_DEVICE_TYPE_CHIP_BASE,
    STVID_DEVICE_TYPE_5197_BASE = STVID_DEVICE_TYPE_CHIP_BASE,
    STVID_DEVICE_TYPE_7111_BASE,
    STVID_DEVICE_TYPE_7105_BASE,
    STVID_DEVICE_TYPE_7141_BASE,
    STVID_DEVICE_TYPE_7108_BASE,
    STVID_DEVICE_TYPE_5206_BASE,
    STVID_DEVICE_TYPE_H205_BASE,
    STVID_DEVICE_TYPE_DELTAHE_BASE
} STVID_DeviceTypeBase_t;

/* STVID device types for STVID users */
typedef enum STVID_DeviceType_e
{
    STVID_DEVICE_TYPE_5162_MPEG             = STVID_DEVICE_TYPE_5162_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_COMPOSITOR << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_LCMPEGX1 << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5197_MPEG             = STVID_DEVICE_TYPE_5197_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_COMPOSITOR << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_LCMPEGX1 << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_MPEG             = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_H264             = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_VC1              = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_MPEG4P2          = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_AVS              = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_SD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_RV               = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_MJPEG            = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_JPEG             = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_VP6              = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_FLV1             = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_THEORA           = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7111_DIGITAL_INPUT    = STVID_DEVICE_TYPE_7111_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_MPEG             = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_H264             = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_VC1              = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_MPEG4P2          = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_AVS              = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_SD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_RV               = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_MJPEG            = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_JPEG             = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_VP6              = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_FLV1             = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_THEORA           = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7105_DIGITAL_INPUT    = STVID_DEVICE_TYPE_7105_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_MPEG             = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_H264             = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_VC1              = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_MPEG4P2          = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_AVS              = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_HD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_RV               = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_MJPEG            = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_JPEG             = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_VP6              = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_FLV1             = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_THEORA           = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_5206_DIGITAL_INPUT    = STVID_DEVICE_TYPE_5206_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_MPEG             = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_H264             = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_VC1              = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_MPEG4P2          = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_AVS              = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_SD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_RV               = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_MJPEG            = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_JPEG             = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_VP6              = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_FLV1             = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_THEORA           = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7141_DIGITAL_INPUT    = STVID_DEVICE_TYPE_7141_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_MPEG             = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_H264             = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_H264_MVC         = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264_MVC << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_VC1              = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_MPEG4P2          = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_AVS              = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_HD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_RV               = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_MJPEG            = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_JPEG             = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_VP6              = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_FLV1             = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_THEORA           = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_7108_DIGITAL_INPUT    = STVID_DEVICE_TYPE_7108_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_MPEG             = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_H264             = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_H264_MVC         = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_H264_MVC << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_VC1              = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VC1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_MPEG4P2          = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MPEG4P2 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_AVS              = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_AVS_HD << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_RV               = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_RV << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_MJPEG            = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_MJPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_JPEG             = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_JPEG << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_VP6              = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_VP6 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_FLV1             = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_FLV1 << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_THEORA           = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_THEORA << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DECODE_DELTA << STVID_DEVICE_TYPE_DECODE_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT),
    STVID_DEVICE_TYPE_H205_DIGITAL_INPUT    = STVID_DEVICE_TYPE_H205_BASE |
                                             (STVID_DEVICE_TYPE_INPUT_UNCOMPRESSED << STVID_DEVICE_TYPE_INPUT_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_HQVDP << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             (STVID_DEVICE_TYPE_DISPLAY_PIPE << STVID_DEVICE_TYPE_DISPLAY_FIRST_BIT) |
                                             ((STVID_DEVICE_TYPE_MISC_HD | STVID_DEVICE_TYPE_MISC_INJECT | STVID_DEVICE_TYPE_MISC_MULTI_VIEWPORT) << STVID_DEVICE_TYPE_MISC_FIRST_BIT)
} STVID_DeviceType_t;

typedef enum STVID_DisplayAspectRatio_e
{
    STVID_DISPLAY_ASPECT_RATIO_16TO9  = STGXOBJ_ASPECT_RATIO_16TO9,
    STVID_DISPLAY_ASPECT_RATIO_4TO3   = STGXOBJ_ASPECT_RATIO_4TO3,
    STVID_DISPLAY_ASPECT_RATIO_221TO1 = STGXOBJ_ASPECT_RATIO_221TO1,
    STVID_DISPLAY_ASPECT_RATIO_SQUARE = STGXOBJ_ASPECT_RATIO_SQUARE,
    STVID_DISPLAY_ASPECT_RATIO_EXTENDED_PAR = 99
} STVID_DisplayAspectRatio_t;

typedef enum STVID_DisplayAspectRatioConversion_e
{
    STVID_DISPLAY_AR_CONVERSION_PAN_SCAN   = 1,
    STVID_DISPLAY_AR_CONVERSION_LETTER_BOX = 2,
    STVID_DISPLAY_AR_CONVERSION_COMBINED   = 4,
    STVID_DISPLAY_AR_CONVERSION_IGNORE     = 8,
    STVID_DISPLAY_AR_CONVERSION_PANORAMIC  = 16
} STVID_DisplayAspectRatioConversion_t;

typedef enum STVID_ErrorRecoveryMode_e
{
    STVID_ERROR_RECOVERY_FULL       = 1,
    STVID_ERROR_RECOVERY_PARTIAL    = 2,
    STVID_ERROR_RECOVERY_NONE       = 4,
    STVID_ERROR_RECOVERY_HIGH       = 8
} STVID_ErrorRecoveryMode_t;

typedef enum STVID_ForceMode_e
{
    STVID_FORCE_MODE_DISABLED,
    STVID_FORCE_MODE_ENABLED
} STVID_ForceMode_t;

typedef enum STVID_FreezeField_e
{
    STVID_FREEZE_FIELD_TOP     = 1,
    STVID_FREEZE_FIELD_BOTTOM  = 2,
    STVID_FREEZE_FIELD_CURRENT = 4,
    STVID_FREEZE_FIELD_NEXT    = 8
} STVID_FreezeField_t;

typedef enum STVID_FreezeMode_e
{
    STVID_FREEZE_MODE_NONE       = 1,
    STVID_FREEZE_MODE_FORCE      = 2,
    STVID_FREEZE_MODE_NO_FLICKER = 4
} STVID_FreezeMode_t;

typedef enum STVID_MPEGFrame_e
{
    STVID_MPEG_FRAME_I      = STGXOBJ_MPEG_FRAME_I,
    STVID_MPEG_FRAME_P      = STGXOBJ_MPEG_FRAME_P,
    STVID_MPEG_FRAME_B      = STGXOBJ_MPEG_FRAME_B
} STVID_MPEGFrame_t;

typedef enum STVID_MPEGStandard_e
{
    STVID_MPEG_STANDARD_ISO_IEC_11172       = 1,  /* MPEG 1 */
    STVID_MPEG_STANDARD_ISO_IEC_13818       = 2,  /* MPEG 2 */
    STVID_MPEG_STANDARD_ISO_IEC_14496       = 4,  /* MPEG-4 Part 10 - H264 */
    STVID_MPEG_STANDARD_SMPTE_421M          = 8,  /* VC1 */
    STVID_MPEG_STANDARD_ISO_IEC_14496_2     = 16, /* MPEG-4 Part 2 - DivX */
    STVID_MPEG_STANDARD_AVS_GB_T_20090_2    = 32, /* China AVS */
    STVID_MPEG_STANDARD_FLV1                = 64, /* Flash V6/7 (Sorenson Spark) */
    STVID_MPEG_STANDARD_VP6                 = 128, /* Flash V8 */
    STVID_MPEG_STANDARD_RV_8_9              = 256, /* Real Video */
    STVID_MPEG_STANDARD_MJPEG               = 512, /* MJPEG */
    STVID_MPEG_STANDARD_JPEG                = 1024,/* JPEG */
    STVID_MPEG_STANDARD_THEORA              = 2048 /* THEORA */
} STVID_MPEGStandard_t;

typedef enum STVID_ParsedDataType_e
{
    STVID_PARSED_DATA_TYPE_STARTCODE,
    STVID_PARSED_DATA_TYPE_SERIES_BYTES
} STVID_ParsedDataType_t;

typedef enum STVID_Picture_e
{
    STVID_PICTURE_LAST_DECODED = 1,
    STVID_PICTURE_DISPLAYED    = 2
} STVID_Picture_t;

typedef enum STVID_PictureStructure_e
{
    STVID_PICTURE_STRUCTURE_TOP_FIELD,
    STVID_PICTURE_STRUCTURE_BOTTOM_FIELD,
    STVID_PICTURE_STRUCTURE_FRAME
} STVID_PictureStructure_t;

typedef enum STVID_ScanType_e
{
    STVID_SCAN_TYPE_PROGRESSIVE = STGXOBJ_PROGRESSIVE_SCAN,
    STVID_SCAN_TYPE_INTERLACED  = STGXOBJ_INTERLACED_SCAN
} STVID_ScanType_t;

typedef enum STVID_SetupObject_e
{
    STVID_SETUP_FRAME_BUFFERS_PARTITION                 = 0x0001,
    STVID_SETUP_DECODER_INTERMEDIATE_BUFFER_PARTITION   = 0x0002,
    STVID_SETUP_DECIMATED_FRAME_BUFFERS_PARTITION       = 0x0004,
    STVID_SETUP_FDMA_NODES_PARTITION                    = 0x0008,
    STVID_SETUP_PICTURE_PARAMETER_BUFFERS_PARTITION     = 0x0010,
    STVID_SETUP_ES_COPY_BUFFER_PARTITION                = 0x0020,
    STVID_SETUP_ES_COPY_BUFFER                          = 0x0040,
    STVID_SETUP_PARSING_RESULTS_BUFFER_PARTITION        = 0x0080,   /* SCList buffer                    */
    STVID_SETUP_DATA_INPUT_BUFFER_PARTITION             = 0x0100,   /* PES buffer partition             */
    STVID_SETUP_BIT_BUFFER_PARTITION                    = 0x0200,   /* ES bit buffer partition          */
    STVID_SETUP_FORCE_SEQUENCE_INFO                     = 0x0400,   /* Application sequence info        */
    STVID_SETUP_DEFAULT_SEQUENCE_INFO                   = 0x0800,   /* Application sequence default     */
    STVID_SETUP_DEFAULT_CODEC_SPECIFIC_INFO             = 0x1000,   /* Codec specific info              */
    STVID_SETUP_DISPLAY_32PULLDOWN_DETECTION            = 0x2000,   /* Display 3:2 Pullodwn detection   */
    STVID_SETUP_DATA_INPUT_BUFFER                       = 0x4000,   /* PES buffer                       */
    STVID_SETUP_PAUSE_MODE                              = 0x8000    /* Set STVID_Pause mode     */
} STVID_SetupObject_t;

typedef enum STVID_Stop_e
{
    STVID_STOP_WHEN_NEXT_REFERENCE = 1,
    STVID_STOP_WHEN_END_OF_DATA    = 2,
    STVID_STOP_NOW                 = 4,
    STVID_STOP_WHEN_NEXT_I         = 8
} STVID_Stop_t;

typedef enum STVID_StreamType_e
{
    STVID_STREAM_TYPE_ES           = 1,
    STVID_STREAM_TYPE_PES          = 2,
    STVID_STREAM_TYPE_MPEG1_PACKET = 4, /* This type is obsolete, MPEG1 packet extraction is not handled at STAPI driver level and should be handled by application above STAPI */
    STVID_STREAM_TYPE_UNCOMPRESSED = 8
} STVID_StreamType_t;

typedef enum STVID_SynchroAction_e
{
    STVID_SYNCHRO_ACTION_PAUSE,
    STVID_SYNCHRO_ACTION_SKIP
} STVID_SynchroAction_t;

typedef enum STVID_UserDataPosition_e
{
    STVID_USER_DATA_AFTER_SEQUENCE,
    STVID_USER_DATA_AFTER_GOP,
    STVID_USER_DATA_AFTER_PICTURE
} STVID_UserDataPosition_t;

typedef enum STVID_WinAlign_e
{
    STVID_WIN_ALIGN_TOP_LEFT        = 1,
    STVID_WIN_ALIGN_VCENTRE_LEFT    = 2,
    STVID_WIN_ALIGN_BOTTOM_LEFT     = 4,
    STVID_WIN_ALIGN_TOP_RIGHT       = 8,
    STVID_WIN_ALIGN_VCENTRE_RIGHT   = 16,
    STVID_WIN_ALIGN_BOTTOM_RIGHT    = 32,
    STVID_WIN_ALIGN_BOTTOM_HCENTRE  = 64,
    STVID_WIN_ALIGN_TOP_HCENTRE     = 128,
    STVID_WIN_ALIGN_VCENTRE_HCENTRE = 256
} STVID_WinAlign_t;

typedef enum STVID_WinSize_e
{
    STVID_WIN_SIZE_FIXED     = 1,
    STVID_WIN_SIZE_DONT_CARE = 2,
    STVID_WIN_SIZE_INCREASE  = 4,
    STVID_WIN_SIZE_DECREASE  = 8
} STVID_WinSize_t;

typedef enum STVID_CodecMode_e
{
    STVID_CODEC_MODE_DECODE    = 0,
    STVID_CODEC_MODE_TRANSCODE = 1
} STVID_CodecMode_t;

typedef enum STVID_VP6_Standard_e
{
    STVID_VP6_DEFAULT       = 0,
    STVID_VP6_VP6F          = 1     /* parameter to activate to play VP6 flipped stream */
} STVID_VP6_Standard_t;

/* This data structure is defining the characteristics of a possible flipping of one of the two stereo views. */
typedef enum STVID_3D_Flipping_e
{
    STVID_NO_FLIPPING,                   /* No flipping at all is performed. */
    STVID_FLIPPING_FRAME0,               /* The frame 0 has been flipped. */
    STVID_FLIPPING_FRAME1                /* The frame 1 has been flipped. */
} STVID_3D_Flipping_t;

/* This structure is associated with STVID_SetEnhancedDataInputInterface. It specifies the parameters to be used to input data. */
typedef enum
{
    STVID_DATA_INPUT_TYPE_PES,
    STVID_DATA_INPUT_TYPE_PARTIALLY_FILLED_PES_FROM_OFFSET,
    STVID_DATA_INPUT_TYPE_PARTIALLY_FILLED_PES_FROM_ADDRESS
} STVID_DataInputType_t;

typedef enum STVID_PauseMode_e
{
    STVID_PAUSE_DISPLAY,                        /* default behavior: STVID_Pause is pausing only the display pipe */
    STVID_PAUSE_ALL                             /* special pause mode: all modules are paused: display, decode and injection */
} STVID_PauseMode_t;

/* Exported Types ----------------------------------------------------------- */

typedef struct STVID_ScalingFactors_s
{
    U16 N;      /* Defines the numerator in the N/M scaling factor */
    U16 M;      /* Defines the denominator in the N/M scaling factor */
} STVID_ScalingFactors_t;

typedef struct STVID_ScalingCapability_s
{
    BOOL Continuous;                                       /* TRUE if continuous, FALSE if discreet*/
    U16  NbScalingFactors;                          /* # of elem for in the buffer. 2 if Continuous */
    STVID_ScalingFactors_t *ScalingFactors_p;         /* should always point to ScalingFactorsArray (kept for legacy) */
    STVID_ScalingFactors_t ScalingFactorsArray[SCALING_FACTORS_MAX_ELEMENTS];                     /* actual array of Supported scaling, N/M format */

} STVID_ScalingCapability_t;

typedef struct STVID_Capability_s
{
    STVID_BroadcastProfile_t             SupportedBroadcastProfile;
    STVID_CodingMode_t                   SupportedCodingMode;            /* OR of supported ones */
    STVID_ColorType_t                    SupportedColorType;             /* OR of supported ones */
    STVID_DecimationFactor_t             SupportedDecimationFactor;      /* OR of supported ones */
    STVID_DisplayAspectRatioConversion_t SupportedDisplayARConversion;   /* OR of supported ones */
    STVID_ErrorRecoveryMode_t            SupportedErrorRecoveryMode;     /* OR of supported ones */
    STVID_FreezeMode_t                   SupportedFreezeMode;            /* OR of supported ones */
    STVID_FreezeField_t                  SupportedFreezeField;           /* OR of supported ones */
    STVID_Picture_t                      SupportedPicture;               /* OR of supported ones */
    STVID_ScanType_t                     SupportedScreenScanType;        /* OR of supported ones */
    STVID_Stop_t                         SupportedStop;                  /* OR of supported ones */
    STVID_StreamType_t                   SupportedStreamType;            /* OR of supported ones */
    BOOL                                 ProfileCapable;                 /* TRUE if supported */
    BOOL                                 StillPictureCapable;            /* Duplicate/Show/Hide/GetPictureAllocInfos
                                                                            function, NonRealTime Decode supported */
    BOOL                                 ManualInputWindowCapable;       /* TRUE if manual       */
    BOOL                                 ManualOutputWindowCapable;      /* windowing supported  */
    BOOL                                 ColorKeyingCapable;             /* TRUE if supported */
    BOOL                                 PSICapable;                     /* TRUE if supported */
    STVID_WinAlign_t                     SupportedWinAlign;              /* OR of supported ones */
    STVID_WinSize_t                      SupportedWinSize;               /* OR of supported ones */
    U8                                   InputWindowHeightMin;           /* value in pixels */
    U8                                   InputWindowWidthMin;            /* value in pixels */
    U8                                   InputWindowPositionXPrecision;  /* value in pixels */
    U8                                   InputWindowPositionYPrecision;  /* value in pixels */
    U8                                   InputWindowWidthPrecision;      /* value in pixels */
    U8                                   InputWindowHeightPrecision;     /* value in pixels */
    U8                                   OutputWindowHeightMin;          /* value in pixels */
    U8                                   OutputWindowWidthMin;           /* value in pixels */
    U8                                   OutputWindowPositionXPrecision; /* value in pixels */
    U8                                   OutputWindowPositionYPrecision; /* value in pixels */
    U8                                   OutputWindowWidthPrecision;     /* value in pixels */
    U8                                   OutputWindowHeightPrecision;    /* value in pixels */
    STVID_ScalingCapability_t            SupportedVerticalScaling;
    STVID_ScalingCapability_t            SupportedHorizontalScaling;
    U8                                   DecoderNumber;
    STVID_SetupObject_t                  SupportedSetupObject;

} STVID_Capability_t;

typedef struct STVID_ConfigureEventParams_s
{
    BOOL    Enable;
    U32     NotificationsToSkip;
} STVID_ConfigureEventParams_t;

typedef struct STVID_ClearParams_s
{
    STVID_Clear_t   ClearMode;
    void *          PatternAddress1_Cp;
    U32             PatternSize1;
    void *          PatternAddress2_Cp;
    U32             PatternSize2;
} STVID_ClearParams_t;

typedef struct STVID_DataInjectionCompletedParams_s
{
    BOOL TransferRelatedToPrevious;
} STVID_DataInjectionCompletedParams_t;

typedef struct STVID_DataUnderflow_s
{
    U32     BitBufferFreeSize;
    U32     BitRateValue;          /* in units of 400 bits/second */
    S32     RequiredTimeJump;
    U32     RequiredDuration;
    BOOL    TransferRelatedToPrevious;
} STVID_DataUnderflow_t;

typedef struct STVID_DigitalInputWindows_s
{
    STGXOBJ_Rectangle_t InputRectangle;  /* x, y, w, h         */
    U32                 OutputWidth;     /* bufferised x=0,y=0 */
    U32                 OutputHeight;    /* (implicit)         */
} STVID_DigitalInputWindows_t;

typedef struct STVID_ForceDecimationFactorParams_s
{
    STVID_ForceMode_t           ForceMode;
    STVID_DecimationFactor_t    DecimationFactor;
} STVID_ForceDecimationFactorParams_t;

typedef struct STVID_Freeze_s
{
    STVID_FreezeMode_t  Mode;
    STVID_FreezeField_t Field;
} STVID_Freeze_t;

typedef U32 STVID_Handle_t;

/* Structure containing a context to be set to a video instance */
typedef struct STVID_InitContext_s
{
    STVID_Context_t Context;                /* Context for the video instance */
    struct
        {
        STVID_FormatLevel_t FormatLevel;    /*Indication about format and level*/
        U32 Reserved[6];               /* Reserved for future usage. Should be set to zero. */
        } ContextParams;                    /* Context parameters */
} STVID_InitContext_t;


typedef struct STVID_InitParams_s
{
    STVID_DeviceType_t      DeviceType;
    void *                  BaseAddress_p;
    void *                  DeviceBaseAddress_p;
    BOOL                    BitBufferAllocated;
    void *                  BitBufferAddress_p;
    U32                     BitBufferSize;  /* in byte */
    STEVT_EventConstant_t   InterruptEvent;
    ST_DeviceName_t         InterruptEventName;
    BOOL                    InstallVideoInterruptHandler;
    U32                     InterruptNumber;
    U32                     InterruptLevel;
    ST_Partition_t *        CPUPartition_p;
    STAVMEM_PartitionHandle_t AVMEMPartition;
    U32                     MaxOpen;
    U32                     UserDataSize;
    ST_DeviceName_t         EvtHandlerName;
    ST_DeviceName_t         ClockRecoveryName;
    U32                     AVSYNCDriftThreshold;
    void *                  BaseAddress2_p;             /* Not used anymore */
    void *                  BaseAddress3_p;             /* Not used anymore */
    STVID_InitContext_t *   InitContext_p;
} STVID_InitParams_t;


typedef struct STVID_MemoryProfile_s
{
    U32                         MaxWidth;
    U32                         MaxHeight;
    U8                          NbFrameStore;
    STVID_DecimationFactor_t    DecimationFactor;
    union
    {
        struct
        {
            U8    Main;
            U8    Decimated;
        } OptimisedNumber;
        struct
        {
            U32  Main;
            U32  Decimated;
        } VariableInFixedSize;
        struct
        {
            STAVMEM_PartitionHandle_t Main;
            STAVMEM_PartitionHandle_t Decimated;
        } VariableInFullPartition;
    } FrameStoreIDParams;
} STVID_MemoryProfile_t;

typedef struct STVID_OpenParams_s
{
    U32 Dummy;
} STVID_OpenParams_t;

typedef struct STVID_ParsedData_s
{
    STVID_ParsedDataType_t ParsedDataType;
    union
    {
         struct
         {
               U8   Value;
         } StartCode;
         struct
         {
               U32  SeriesSizeInBytes;
         } ByteSeries;
    } WantedData;
    void *  ParsedDataAddress1;
    U32     ParsedDataSize1;
    void *  ParsedDataAddress2;
    U32     ParsedDataSize2;
} STVID_ParsedData_t;

typedef struct STVID_PTS_s
{
    U32  PTS;
    BOOL PTS33;
    BOOL Interpolated;
    BOOL IsValid;
} STVID_PTS_t;

typedef struct STVID_SetupCodecSpecificInfo_s
{
    STVID_MPEGStandard_t    MPEGStandard;
    union
    {
        struct
        {
            STVID_VP6_Standard_t VP6_Standard;
        } STANDARD_VP6;
#ifdef JPEG_SUB_REGION
        struct
        {
            /* Subregion parameters */
            int JPEG_SubRegionX0;
            int JPEG_SubRegionY0;
            int JPEG_SubRegionX1;
            int JPEG_SubRegionY1;
        } STANDARD_JPEG;
#endif
    } CodecSetup;
} STVID_SetupCodecSpecificInfo_t;

typedef struct STVID_SequenceInfo_s
{
    U32                         Height;
    U32                         Width;
    STVID_DisplayAspectRatio_t  Aspect;
    U32                         PAR_Num;
    U32                         PAR_Den;
    STVID_ScanType_t            ScanType;
    U32                         FrameRate;
    U32                         BitRate;
    STVID_MPEGStandard_t        MPEGStandard;
    BOOL                        IsLowDelay;
    U32                         VBVBufferSize;
    U8                          StreamID;
    U32                         ProfileAndLevelIndication;
    U8                          VideoFormat;

    /* Valid only if MPEGStandard is STVID_MPEG_STANDARD_ISO_IEC_13818 */
    U8                          FrameRateExtensionN; /*  2 bits */
    U8                          FrameRateExtensionD; /*  5 bits */
    /* End of valid only if MPEGStandard is STVID_MPEG_STANDARD_ISO_IEC_13818 */

    BOOL                        OverScanAllowed; /* This flag tells application if overscan postprocessing in application's display is suitable or not
                                                  * the returned value is :
                                                  * FALSE in case of H264 stream with overscan_appropriate_flag == 0
                                                  * TRUE in all other cases (i.e. always TRUE for codecs different from H264) */
} STVID_SequenceInfo_t;

typedef struct STVID_SetupParams_s
{
    STVID_SetupObject_t SetupObject;
    union
    {
        STAVMEM_PartitionHandle_t       AVMEMPartition;
        STVID_SequenceInfo_t            SequenceInfo;       /* Default sequence info given by the application */
                                                            /* in order to set or override internal values    */
        STVID_SetupCodecSpecificInfo_t  SetupCodecSpecificInfo;
        struct
        {
            U32 BufferSize;
            BOOL BufferAllocated;
            void * BufferAddress_p;
        } SingleBuffer;
        struct
        {
            U32 BufferSize;
            BOOL BufferAllocated;
            void * BufferAddress1_p;
            void * BufferAddress2_p;
        } DoubleBuffer;
        struct
        {
            U8 NumberOfBuffers;
            U32 * BufferSizesTable;
            BOOL BufferAllocated;
            void ** BufferAddressesTable;
        } AnyBuffer;
        struct
        {
            /* TRUE: 3:2 Pulldown repetitions are detected and source is then treated as Progressive. FALSE: No detection done so ScanType is unchanged.
               By default, Detect32PulldownRepetitions = TRUE */
            BOOL Detect32PulldownRepetitions;
        } DisplaySetup;

        STVID_PauseMode_t SetupPauseMode;
    } SetupSettings;
} STVID_SetupParams_t;

typedef struct STVID_TimeCode_s
{
    U8 Hours;
    U8 Minutes;
    U8 Seconds;
    U8 Frames;
    BOOL Interpolated;
} STVID_TimeCode_t;

typedef struct STVID_DecimatedBitmapParams_s
{
    void *                        Data1_p;
    void *                        Data1_Cp;
    void *                        Data1_NCp;
    U32                           Size1;
    void *                        Data2_p;
    void *                        Data2_Cp;
    void *                        Data2_NCp;
    U32                           Size2;
} STVID_DecimatedBitmapParams_t;

/* This data structure is created so that it defines the supplemental information of SideBySide half packing arrangement. */
typedef struct STVID_3D_SideBySideHalf_s
{
    BOOL                Frame0IsLeft;         /* The frame 0 is left view (value TRUE) or a right one (value FALSE). */
    U16                 Frame0GridPosition_x; /* The horizontal location (in 1/16 pixel unit) of the upper left sample of the considered frame. */
    U16                 Frame1GridPosition_x; /* The horizontal location (in 1/16 pixel unit) of the upper left sample of the considered frame. */
    STVID_3D_Flipping_t Flipping;             /* The optional flipping content characteristics. */
} STVID_3D_SideBySideHalf_t;

/* This data structure is created so that it defines the supplemental information of TopAndBottom half packing arrangement. */
typedef struct STVID_3D_StackedHalf_s
{
    BOOL                Frame0IsLeft;         /* The frame 0 is left view (value TRUE) or a right one (value FALSE). */
    U16                 Frame0GridPosition_y; /* The vertical location (in 1/16 pixel unit) of the upper left sample of the considered frame. */
    U16                 Frame1GridPosition_y; /* The vertical location (in 1/16 pixel unit) of the upper left sample of the considered frame. */
    STVID_3D_Flipping_t Flipping;             /* The optional flipping content characteristics. */
} STVID_3D_StackedHalf_t;

typedef struct STVID_3D_FrameSeq_s
{
    BOOL                IsFrame0;             /* TRUE if current picture is frame 0 */
    BOOL                Frame0IsLeft;         /* The frame 0 is left view (value TRUE) or a right one (value FALSE). */
    STVID_3D_Flipping_t Flipping;             /* The optional flipping content characteristics. */
} STVID_3D_FrameSeq_t;
/* This data structure is used in order to specify additional information concerning a specific 3D format. */
typedef union STVID_3D_VideoSupplInfo_s
{
    STVID_3D_SideBySideHalf_t   STVID_3D_SideBySideHalf;
    STVID_3D_StackedHalf_t      STVID_3D_StackedHalf;
    STVID_3D_FrameSeq_t		STVID_3D_FrameSeq;
} STVID_3D_VideoSupplInfo_t;

/* This data structure is specifying the 3D frame arrangement a decoded frame. */
typedef struct STVID_3D_Property_s
{
    ST_MM_3D_Format_t           STVID_3D_Format;           /* All possible frame packing arrangement schemes */
    STVID_3D_VideoSupplInfo_t   STVID_3D_SupplInfo;   /* Additional information related to the way the stereoscopic views will have to be processed */
} STVID_3DVideoProperty_t;

typedef struct STVID_VideoParams_s
{
    U32                         FrameRate;
    STGXOBJ_ScanType_t          ScanType;
    STVID_3DVideoProperty_t     STVID_3D_Property;        /* Specifies the way the stereoscopy is encoded within the picture. */
    STGXOBJ_Bitmap_t            SecondViewBitmapParams;
    STVID_MPEGFrame_t           MPEGFrame;
    STVID_PictureStructure_t    PictureStructure;
    BOOL                        TopFieldFirst;
    STVID_TimeCode_t            TimeCode;
    STVID_PTS_t                 PTS;
    STVID_DecimationFactor_t    DecimationFactors;
    BOOL                        DoesNonDecimatedExist;      /* = TRUE when the non-decimated picture does exist */
    STVID_DecimatedBitmapParams_t DecimatedBitmapParams;
    U32                         PictureSignature;           /* Internal signature specific to each picture */
    U32                         CEHRegisters[STVID_NUMBER_OF_CEH_INTERVALS];    /* Dynamic constrast histogram registers */
#ifdef STVID_USE_CRC /* Debug only */
    U32                         ForceFieldCRC;
    BOOL                        IsMonochrome;
#endif /* STVID_USE_CRC */
} STVID_VideoParams_t;

typedef struct STVID_PictureDescriptors_s
{
    U32     PictureMeanQP;    /* mean of quatisation parameters */
    U32     PictureVarianceQP; /* variance of quatisation parameters */
} STVID_PictureDescriptors_t;

/* Added to export picture buffer */
typedef void * STVID_PictureBufferHandle_t;

typedef struct STVID_PictureCroppingInfos_s
{
    struct
    {
        S32     FrameCentreHorizontalOffset;
        S32     FrameCentreVerticalOffset;
        U32     DisplayHorizontalSize;
        U32     DisplayVerticalSize;
        BOOL    HasDisplaySizeRecommendation;
    } PanAndScanIn16thPixel;

    struct
    {
        U32     LeftOffset;
        U32     RightOffset;
        U32     TopOffset;
        U32     BottomOffset;
    } FrameCropInPixel;

} STVID_PictureCroppingInfos_t;

typedef struct STVID_PictureInfos_s
{
    STGXOBJ_Bitmap_t    BitmapParams;
    STVID_VideoParams_t VideoParams;
    STVID_PictureBufferHandle_t PictureBufferHandle;
    STVID_PictureBufferHandle_t DecimatedPictureBufferHandle;
    STVID_PictureDescriptors_t  PictureDescriptors;
} STVID_PictureInfos_t;

typedef struct STVID_FieldInfos_s
{
    BOOL                        DisplayTopNotBottom; /* TRUE if the picture will be displayed in top type */
    STVID_PictureBufferHandle_t PictureBufferHandle; /* Handle to Picture Buffer, to be used by application throw API calls */
} STVID_FieldInfos_t;


typedef enum STVID_CharacteristicsChanged_e
{
    STVID_ASPECT_RATIO_CHANGE       = 1,
    STVID_SCAN_TYPE_CHANGE          = 2,
    STVID_FRAME_RATE_CHANGE         = 4,
    STVID_RESOLUTION_CHANGE         = 8,        /* Picture height or width has changed */
    STVID_CENTRE_FRAME_OFFSET_CHANGE= 16,
    STVID_3D_FORMAT                 = 32        /* the 3D format has changed */
} STVID_CharacteristicsChanged_t;


typedef struct STVID_PictureCharacteristicsChangeParams_s
{
    STVID_CharacteristicsChanged_t      CharacteristicsChanged;            /* OR between all the changing characteristics */
    STVID_PictureInfos_t                PictureInfo;
    STVID_PictureCroppingInfos_t        PictureCroppingInfo;
} STVID_PictureCharacteristicsChangeParams_t;


typedef struct STVID_DisplayPictureInfos_s
{
    U8 NumberOfPanAndScan;
    struct
    {
        S32     FrameCentreHorizontalOffset;
        S32     FrameCentreVerticalOffset;
        U32     DisplayHorizontalSize;
        U32     DisplayVerticalSize;
        BOOL    HasDisplaySizeRecommendation;
    } PanAndScanIn16thPixel [STVID_MAX_NUMBER_OF_PAN_AND_SCAN];

    struct
    {
        U32     LeftOffset;
        U32     RightOffset;
        U32     TopOffset;
        U32     BottomOffset;
    } FrameCropInPixel;

} STVID_DisplayPictureInfos_t;

typedef struct STVID_SpeedDriftThreshold_s
{
    S32 DriftTime;
    U32 BitRateValue;           /* in units of 400 bits/second */
    U32 SpeedRatio;             /* not used today. Set to 0 in the code. */
} STVID_SpeedDriftThreshold_t;

typedef struct STVID_StartParams_s
{
    BOOL                        RealTime;
    BOOL                        UpdateDisplay;
    STVID_BroadcastProfile_t    BrdCstProfile;
    STVID_StreamType_t          StreamType;
    U8                          StreamID;
    BOOL                        DecodeOnce;
} STVID_StartParams_t;

typedef struct STVID_SynchronisationInfo_s
{
    S32             ClocksDifference;
    BOOL            IsSynchronisationOk;
    BOOL            IsLoosingSynchronisation;
    BOOL            IsBackToSynchronisation;
} STVID_SynchronisationInfo_t;

typedef struct STVID_TermParams_s
{
    BOOL ForceTerminate;
} STVID_TermParams_t;

typedef struct STVID_UserData_s
{
    STVID_BroadcastProfile_t    BroadcastProfile;
    STVID_UserDataPosition_t    PositionInStream;
    U32                         Length;
    BOOL                        BufferOverflow;
    void *                      Buff_p;
    STVID_PTS_t                 PTS;    /* valid for pictures only */

    /* Private Data */
    S32  pTemporalReference; /* Picture user data only */
    BOOL IsRegistered;      /* the 3 fields following are only available if IsReference==TRUE */
    U8 itu_t_t35_country_code;
    U8 itu_t_t35_country_code_extension_byte;
    U16 itu_t_t35_provider_code;
    BOOL TopFieldFirst;     /* Needed for CC EIA608 */
} STVID_UserData_t;


/* Marker is the one found in the dataflow */
typedef struct STVID_MarkerData_t {
    ST_MM_Bitstream_Marker_t Marker;
    STVID_PTS_t PTS;      /* non interpolated PTS will be provided by the decoder. */
    U32 MarkerID0;        /* user data associated to the marker */
    U32 MarkerID1;        /* user data associated to the marker */
} STVID_MarkerData_t;


/* This structure is describing the kind of possible notification a decoder will be asked to issue. */
typedef enum STVID_Notification_t
{
    STVID_EARLY_PTS_DETECTION  /* used in case the injection engine wants to know if a particular
                                  frame (identified by its PTS information) is inside the decoder
                                  data perimeter (either intermediate or bit buffer). */
} STVID_Notification_t;


/* This structure is describing the parameter associated with each notification.*/
typedef struct STVID_NotificationParams_t
{
     STVID_Notification_t Notification;   /* identifying the kind of notification to issue.*/
     U32 NotificationID;                  /* a client supplied identifier to be associated to the notification. */
     union
     {
        struct
        {
          STVID_PTS_t PTS;               /* indicating the PTS value to be considered as a trigger for issuing the notification event. */
          U32 Tolerance;                 /* the tolerance of PTS value when checking the trigger condition.PTS <= InStreamPTS < PTS + Tolerance */
        } EarlyPtsNotification;
     };
} STVID_NotificationParams_t;


typedef struct STVID_NotificationEventParams_t
{
      STVID_Notification_t Notification;   /* identifying the kind of notification to issue.*/
      U32 NotificationID;                  /* a client supplied identifier to be associated to the notification. */
      union
      {
         struct
         {
           STVID_PTS_t PTS;              /* indicating the PTS value to be considered as a trigger for issuing the notification event. */
         } EarlyPtsNotification;
      };
} STVID_NotificationEventParams_t;


typedef void * STVID_ViewPortHandle_t;

typedef struct STVID_ViewPortParams_s
{
    ST_DeviceName_t LayerName;
} STVID_ViewPortParams_t;


/* Data returned by STVID_GetViewPortHandle function */
typedef struct STVID_GetViewPortData_s
{
    ST_DeviceName_t         VideoDeviceName;
    STVID_ViewPortHandle_t  ViewPortHandle;
} STVID_GetViewPortData_t;


typedef struct STVID_WindowParams_s
{
    STVID_WinAlign_t Align;
    STVID_WinSize_t Size;
} STVID_WindowParams_t;

typedef struct STVID_UnsupportedStreamType_s
{
    STVID_MPEGStandard_t    MPEGStandard;
    U32   UnsupportedProfileAndLevelIndication; /* 0 means parsed profile/level is supported else this field contains the unsupported Profile/Level indication */
                                                 /* bits 16-31 : set to 0(reserved), bits 8-15 : Profile, bits 0-7 : Level */
    BOOL   UnsupportedResolutionBeyondCapability; /* Bool for informing application resolution not supported by the codec */

   union
    {
        struct
        {
            BOOL    ASO;
            BOOL    FMO;
            BOOL    RedundantSlices;
        } STANDARD_ISO_IEC_14496;
        struct
        {
            BOOL    GMCTool;
            BOOL    QuarterPixel;
        } STANDARD_ISO_IEC_14496_2;
    } Unsupported;
} STVID_UnsupportedStreamType_t;

typedef struct STVID_FlushParams_s
{
    STVID_FlushMode_t       FlushMode;
    struct
    {
        struct
        {
            U32     NbPictureToKeep;
        } DiscontinuityBased;
        struct
        {
            STVID_PTS_t PTS;
            S32     Tolerance;
        } PTSBased;
    }Trigger;
} STVID_FlushParams_t;

typedef struct STVID_InjectionModeParams_s
{
    const U32 reserved;
} STVID_InjectionModeParams_t;

/* This structure is associated with STVID_SetEnhancedDataInputInterface. It specifies the parameters to be used to connect the
 * input data buffer to the video driver: */
typedef struct STVID_EnhancedDataInputInterfaceParams_s
{
    struct
    {
        STVID_DataInputType_t DataInputType;
        void * FunctionsHandle;
        void * ReadAddress_p;
        U32 Offset;
    } InputBufferParams[MAX_INPUT_BUFFER];
    ST_ErrorCode_t (*GetWriteAddress) (void * Handle, void ** Address_p);
    void (*InformReadAddress) (void * Handle, void * Address);
} STVID_EnhancedDataInputInterfaceParams_t;

/* Add buffer parameter structure to map PES buffer in user space */
#define STVID_CALLBACK_DIRECT_INTERFACE_PTI     (NULL)
#define STVID_CALLBACK_DIRECT_INTERFACE_STINJECT    (1)

/* Exported Variables ------------------------------------------------------- */

/* Exported Macros ---------------------------------------------------------- */

/* Exported Functions ------------------------------------------------------- */

/******************************************************************************/
/* STVID Public API --------------------------------------------------------- */
/******************************************************************************/

ST_Revision_t  STVID_GetRevision(void);
ST_ErrorCode_t STVID_GetCapability(const ST_DeviceName_t DeviceName, STVID_Capability_t  * const Capability_p);
ST_ErrorCode_t STVID_Init(const ST_DeviceName_t DeviceName, const STVID_InitParams_t * const InitParams_p);
ST_ErrorCode_t STVID_Open(const ST_DeviceName_t DeviceName, const STVID_OpenParams_t * const OpenParams_p, STVID_Handle_t * const Handle_p);
ST_ErrorCode_t STVID_Close(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_Term(const ST_DeviceName_t DeviceName, const STVID_TermParams_t * const TermParams_p);

#if (defined (ST_OSLINUX) && (!defined(MODULE) || (!defined(ST_HOSTONLY) && defined(ST_HOST))))
/* Preprocess events only for user space under Linux. */
ST_ErrorCode_t STVID_PreprocessEvent(const ST_DeviceName_t DeviceName, STEVT_EventConstant_t Event, void * EventData);
#else
/* For kernel space under linux: dummy function. */
#define STVID_PreprocessEvent(DeviceName, Event, EventData)     (ST_NO_ERROR)
#endif /* ST_OSLINUX && MODULE */

ST_ErrorCode_t STVID_Clear(const STVID_Handle_t Handle, const STVID_ClearParams_t * const Params_p);
ST_ErrorCode_t STVID_ConfigureEvent(const STVID_Handle_t Handle, const STEVT_EventID_t Event, const STVID_ConfigureEventParams_t * const Params_p);
ST_ErrorCode_t STVID_DataInjectionCompleted(const STVID_Handle_t Handle, const STVID_DataInjectionCompletedParams_t * const Params_p);
ST_ErrorCode_t STVID_DeleteDataInputInterface(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_DisableDeblocking(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_DisableFrameRateConversion(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_DisableSynchronisation(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_DisableSynchronisationOnInterpolatedPTS(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_EnableSynchronisationOnInterpolatedPTS(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_SetInterpolatedPTSBaseline(const STVID_Handle_t   VideoHandle,
                                                const STVID_PTS_t    * const InterpolatedPTSBaseline_p);
ST_ErrorCode_t STVID_EnableDeblocking(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_EnableFrameRateConversion(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_EnableSynchronisation(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_ForceDecimationFactor(const STVID_Handle_t Handle, const STVID_ForceDecimationFactorParams_t * const Params_p);
ST_ErrorCode_t STVID_Freeze(const STVID_Handle_t Handle, const STVID_Freeze_t * const Freeze_p);
ST_ErrorCode_t STVID_GetBitBufferFreeSize(const STVID_Handle_t Handle, U32 * const FreeSize_p);
ST_ErrorCode_t STVID_GetBitBufferParams(const STVID_Handle_t Handle, void ** const BaseAddress_p, U32 * const InitSize_p);
ST_ErrorCode_t STVID_GetDataInputBufferParams(const STVID_Handle_t
     Handle, void ** const BaseAddress_NCp, U32 * const Size_p);
ST_ErrorCode_t STVID_GetDecimationFactor(const STVID_Handle_t Handle, STVID_DecimationFactor_t * const DecimationFactor_p);
ST_ErrorCode_t STVID_GetDecodedPictures(const STVID_Handle_t Handle, STVID_DecodedPictures_t * const DecodedPictures_p);
ST_ErrorCode_t STVID_GetErrorRecoveryMode(const STVID_Handle_t Handle, STVID_ErrorRecoveryMode_t * const Mode_p);
ST_ErrorCode_t STVID_GetMemoryProfile(const STVID_Handle_t Handle, STVID_MemoryProfile_t * const MemoryProfile_p);
ST_ErrorCode_t STVID_GetPictureAllocInfos(const STVID_Handle_t Handle, const STVID_PictureInfos_t * const Params_p, STAVMEM_AllocBlockParams_t * const AllocParams_p);
ST_ErrorCode_t STVID_GetPictureInfos(const STVID_Handle_t Handle, const STVID_Picture_t PictureType, STVID_PictureInfos_t * const PictureInfos_p);
ST_ErrorCode_t STVID_GetDisplayPictureInfo(const STVID_Handle_t Handle, const STVID_PictureBufferHandle_t PictureBufferHandle, STVID_DisplayPictureInfos_t * const DisplayPictureInfos_p);
ST_ErrorCode_t STVID_GetInjectionMode(const STVID_Handle_t VideoHandle, STVID_InjectionMode_t * const InjectionMode_p);
ST_ErrorCode_t STVID_GetSpeed(const STVID_Handle_t Handle, S32 * const Speed_p);
ST_ErrorCode_t STVID_InjectDiscontinuity(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_Pause(const STVID_Handle_t Handle, const STVID_Freeze_t * const Freeze_p);
ST_ErrorCode_t STVID_PostProcessingControl(const STVID_Handle_t VideoHandle, const STVID_POSTPROCESSING_Command_t POSTPROCESSING_Command, const STVID_POSTPROCESSING_Param_t * const POSTPROCESSING_Param_p);
ST_ErrorCode_t STVID_Resume(const STVID_Handle_t Handle);
/* Set the data input buffer interfaces (set read address/get write address), and how the already injected data should be handled. */
ST_ErrorCode_t STVID_SetEnhancedDataInputInterface(const STVID_Handle_t Handle,
                                                   const STVID_EnhancedDataInputInterfaceParams_t * const Params_p);
/* This function called by user autorizes video to call external functions */
ST_ErrorCode_t STVID_SetDataInputInterface(const STVID_Handle_t Handle,
     ST_ErrorCode_t (*GetWriteAddress)  (void * const Handle, void ** const Address_p),
     void (*InformReadAddress)(void * const Handle, void * const Address),
     void * const FunctionsHandle);
ST_ErrorCode_t STVID_SetDeblockingStrength(const STVID_Handle_t VideoHandle, const U8 DeblockingStrength);
ST_ErrorCode_t STVID_SetDecodedPictures(const STVID_Handle_t Handle, const STVID_DecodedPictures_t DecodedPictures);
ST_ErrorCode_t STVID_SetErrorRecoveryMode(const STVID_Handle_t Handle, const STVID_ErrorRecoveryMode_t Mode);
ST_ErrorCode_t STVID_SetInjectionMode(const STVID_Handle_t VideoHandle, const STVID_InjectionMode_t InjectionMode, const STVID_InjectionModeParams_t * const InjectionParams_p);
ST_ErrorCode_t STVID_SetMemoryProfile(const STVID_Handle_t Handle, const STVID_MemoryProfile_t * const MemoryProfile_p);
ST_ErrorCode_t STVID_SetSpeed(const STVID_Handle_t Handle, const S32 Speed);
ST_ErrorCode_t STVID_Setup(const STVID_Handle_t Handle, const STVID_SetupParams_t * const SetupParams_p);
ST_ErrorCode_t STVID_RepeatSynchro(const STVID_Handle_t Handle, const U32 NumberOfFields, U32 * const NumberDone_p);
ST_ErrorCode_t STVID_SkipSynchro(const STVID_Handle_t Handle, const U32 NumberOfFields, U32 * const NumberDone_p);
ST_ErrorCode_t STVID_Start(const STVID_Handle_t Handle, const STVID_StartParams_t * const Params_p);
ST_ErrorCode_t STVID_StartUpdatingDisplay(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_Step(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_StepFrame(const STVID_Handle_t Handle);
ST_ErrorCode_t STVID_Stop(const STVID_Handle_t Handle, const STVID_Stop_t StopMode, const STVID_Freeze_t * const Freeze_p);
ST_ErrorCode_t STVID_GetSynchronizationDelay(const STVID_Handle_t VideoHandle, S32 * const SyncDelay_p);
ST_ErrorCode_t STVID_SetSynchronizationDelay(const STVID_Handle_t VideoHandle, const S32 SyncDelay);
ST_ErrorCode_t STVID_SetClockRecoverySource(const STVID_Handle_t Handle, const STCLKRV_Handle_t ClkSource);
ST_ErrorCode_t STVID_Flush(const STVID_Handle_t VideoHandle, const STVID_FlushParams_t * const FlushParams_p);
ST_ErrorCode_t STVID_SetNotification( const STVID_Handle_t Handle, BOOL Enable, const STVID_NotificationParams_t * const NotificationParams_p );




typedef struct STVID_GetPictureBufferParams_s
{
    STVID_PictureStructure_t    PictureStructure; /* Picture structure (Frame, Top field, Bottom field)*/
    BOOL                        TopFieldFirst; /* If PictureStructure is frame, indicates the first (decoded) field in the frame */
    BOOL                        ExpectingSecondField; /* Set TRUE if the picture is a field picture, the first of the 2 fields (FALSE if second field) */
    U32                         ExtendedTemporalReference; /* Extended temporal reference: temporal_reference, but with no loop back to 0 and no "hole" in value incrementation */
    U32                         PictureWidth;
    U32                         PictureHeight;
} STVID_GetPictureBufferParams_t;


typedef struct STVID_PictureBufferDataParams_s
{
    void *                  Data1_p;
    void *                  Data1_Cp;
    void *                  Data1_NCp;
    U32                     Size1;
    void *                  Data2_p;
    void *                  Data2_Cp;
    void *                  Data2_NCp;
    U32                     Size2;

} STVID_PictureBufferDataParams_t;

typedef U32 STVID_SwapParams_t ;	/* Temporary implementation fo the Swap parameter data structure. Should be set to NULL until clear specification. */

ST_ErrorCode_t STVID_ReleasePictureBuffer(const STVID_Handle_t Handle, const STVID_PictureBufferHandle_t  PictureBufferHandle);
ST_ErrorCode_t STVID_TakePictureBuffer(const STVID_Handle_t Handle, const STVID_PictureBufferHandle_t PictureBufferHandle);

ST_ErrorCode_t STVID_DisableDisplay(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_EnableDisplay(const STVID_Handle_t VideoHandle);

ST_ErrorCode_t STVID_PrintPictureBuffersStatus(const STVID_Handle_t Handle);

#if ! defined STVID_NO_COMPOSITION
    /* These functions can be removed if driver composition is not needed ------- */

    #ifdef STVID_USE_CONNECTED_VIEWPORTS
        /* Special Composition mode not tested and not supported */
        ST_ErrorCode_t STVID_ConnectViewPort(
                 const STVID_Handle_t                   VideoHandle,
                 const STLAYER_ViewPortHandle_t         StlayerViewPortHandle);
        ST_ErrorCode_t STVID_DisconnectViewPort(const STVID_Handle_t                   VideoHandle,
                                                const STLAYER_ViewPortHandle_t         StlayerViewPortHandle);

    #else /* !STVID_USE_CONNECTED_VIEWPORTS */

        ST_ErrorCode_t STVID_CloseViewPort(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_LockViewPort(const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_UnLockViewportMode_t UnLockViewportMode);
        ST_ErrorCode_t STVID_UnLockViewPort(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_DisableBorderAlpha(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_DisableColorKey(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_DisableOutputWindow(const STVID_ViewPortHandle_t ViewPortHandle);

        ST_ErrorCode_t STVID_EnableBorderAlpha(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_EnableColorKey(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_EnableOutputWindow(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_GetAlignIOWindows(const STVID_ViewPortHandle_t ViewPortHandle,
                            S32 * const InputWinX_p,  S32 * const InputWinY_p,  U32 * const InputWinWidth_p,  U32 * const InputWinHeight_p,
                            S32 * const OutputWinX_p, S32 * const OutputWinY_p, U32 * const OutputWinWidth_p, U32 * const OutputWinHeight_p);
        ST_ErrorCode_t STVID_GetDisplayAspectRatioConversion(const STVID_ViewPortHandle_t ViewPortHandle, STVID_DisplayAspectRatioConversion_t * const Conversion_p);
        ST_ErrorCode_t STVID_GetInputWindowMode(const STVID_ViewPortHandle_t ViewPortHandle, BOOL * const AutoMode_p, STVID_WindowParams_t * const WinParams_p);
        ST_ErrorCode_t STVID_GetIOWindows(const STVID_ViewPortHandle_t ViewPortHandle,
                            S32 * const InputWinX_p,  S32 * const InputWinY_p,  U32 * const InputWinWidth_p,  U32 * const InputWinHeight_p,
                            S32 * const OutputWinX_p, S32 * const OutputWinY_p, U32 * const OutputWinWidth_p, U32 * const OutputWinHeight_p);
        ST_ErrorCode_t STVID_GetOutputWindowMode(const STVID_ViewPortHandle_t ViewPortHandle, BOOL * const AutoMode_p, STVID_WindowParams_t * const WinParams_p);
        ST_ErrorCode_t STVID_GetViewPortAlpha(const STVID_ViewPortHandle_t ViewPortHandle, STLAYER_GlobalAlpha_t * const GlobalAlpha_p);
        ST_ErrorCode_t STVID_GetViewPortColorKey(const STVID_ViewPortHandle_t ViewPortHandle, STGXOBJ_ColorKey_t * const ColorKey_p);
        ST_ErrorCode_t STVID_GetViewPortPSI(const STVID_ViewPortHandle_t ViewPortHandle, STLAYER_PSI_t * const VPPSI_p);
        ST_ErrorCode_t STVID_HidePicture(const STVID_ViewPortHandle_t ViewPortHandle);
        ST_ErrorCode_t STVID_OpenViewPort(const STVID_Handle_t VideoHandle,
                                          const STVID_ViewPortParams_t * const ViewPortParams_p,
                                          STVID_ViewPortHandle_t * const ViewPortHandle_p);
        ST_ErrorCode_t STVID_SetDisplayAspectRatioConversion(const STVID_ViewPortHandle_t ViewPortHandle, const STVID_DisplayAspectRatioConversion_t Mode);
        ST_ErrorCode_t STVID_SetInputWindowMode(const STVID_ViewPortHandle_t ViewPortHandle, const BOOL AutoMode, const STVID_WindowParams_t * const WinParams_p);
        ST_ErrorCode_t STVID_SetIOWindows(const STVID_ViewPortHandle_t ViewPortHandle,
                            const S32 InputWinX,  const S32 InputWinY,  const U32 InputWinWidth,  const U32 InputWinHeight,
                            const S32 OutputWinX, const S32 OutputWinY, const U32 OutputWinWidth, const U32 OutputWinHeight);
        ST_ErrorCode_t STVID_SetOutputWindowMode(const STVID_ViewPortHandle_t ViewPortHandle, const BOOL AutoMode, const STVID_WindowParams_t * const WinParams_p);
        ST_ErrorCode_t STVID_SetViewPortAlpha(const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_GlobalAlpha_t * const GlobalAlpha_p);
        ST_ErrorCode_t STVID_SetViewPortColorKey(const STVID_ViewPortHandle_t ViewPortHandle, const STGXOBJ_ColorKey_t * const ColorKey_p);
        ST_ErrorCode_t STVID_SetViewPortPSI(const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_PSI_t * const VPPSI_p);
        ST_ErrorCode_t STVID_ShowPicture(const STVID_ViewPortHandle_t ViewPortHandle, STVID_PictureInfos_t * const Infos_p, const STVID_Freeze_t * const Freeze_p);

        /* Obsolete and useless functions. To be deprecated soon */
        ST_ErrorCode_t STVID_GetViewPortSpecialMode (const STVID_ViewPortHandle_t ViewPortHandle, STLAYER_OutputMode_t * const OuputMode_p, STLAYER_OutputWindowSpecialModeParams_t * const Params_p);
        ST_ErrorCode_t STVID_SetViewPortSpecialMode (const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_OutputMode_t OuputMode, const STLAYER_OutputWindowSpecialModeParams_t * const Params_p);

        ST_ErrorCode_t STVID_SwapViewPorts( const STVID_ViewPortHandle_t    ViewPortHandle1, const STVID_ViewPortHandle_t   ViewPortHandle2, STVID_SwapParams_t *SwapParams_p);
        ST_ErrorCode_t STVID_GetViewPortHandle(const ST_DeviceName_t LAYERDeviceName, STVID_GetViewPortData_t * const GetViewPortData_p);

    #endif /* STVID_USE_CONNECTED_VIEWPORTS */
#endif /* no STVID_NO_COMPOSITION */

#if defined(DVD_SECURED_HOST_UNTRUSTED)
/* This function needs to be called only on secure platforms in order to use the DMU preprocessor hardware work around. */
ST_ErrorCode_t STVID_SetupReservedPartitionForH264PreprocWA_GNB42332(const STVID_Handle_t Handle, const STAVMEM_PartitionHandle_t AVMEMPartition);
#endif /* DVD_SECURED_HOST_UNTRUSTED */

/*******************************************************************************/
/* Internal functions used only by other STAPI Drivers (STVIN, STHDMI...) ---- */
/*******************************************************************************/

ST_ErrorCode_t STVID_GetPictureBuffer(const STVID_Handle_t Handle, const STVID_GetPictureBufferParams_t * const Params_p,
                                      STVID_PictureBufferDataParams_t * const PictureBufferParams_p,
                                      STVID_PictureBufferHandle_t * const PictureBufferHandle_p);
ST_ErrorCode_t STVID_DisplayPictureBuffer(const STVID_Handle_t Handle, const STVID_PictureBufferHandle_t  PictureBufferHandle,
                                          const STVID_PictureInfos_t*  const PictureInfos_p);
ST_ErrorCode_t STVID_SetFrameBuffersColorType(const STVID_Handle_t Handle, STGXOBJ_ColorType_t const ColorType);


/* Un-supported extensions (debug only) ------------------------------------- */

/*******************************************************************************
WARNING (do not remove)
=======
Every user of this code must be made aware of the following limitations.
This section's API's are extensions to the STVID API, for debugging and testing
purposes only. They are not part of the STVID product delivery, they don't
contain driver features used in production. They are not compiled by default.
They may change without notice. They may contain errors, are not tested. They
may be not supported on some platforms, may change the driver normal behaviour.
Application code such as reference software or customer application may use
them at their own risks and not for production. There will be no support.
*******************************************************************************/


#ifdef STVID_DEBUG_GET_STATISTICS
typedef struct STVID_Statistics_s
{
    /* Syntax for the naming of statistics variables: <module>[Pb]<variable_name>
        . <module> tells which module is responsible for the variable,
        . [Pb] is present if in the normal operations the variable should remain 0,
        . <variable_name> is the meaning of the variable */
    U32 ApiPbLiveResetWaitForFirstPictureDetected; /* Counts number of LiveReset while waiting for a 1st picture parsed (automatic Stop()/Start() when idle for too long in real-time) */
    U32 ApiPbLiveResetWaitForFirstPictureDecoded;  /* Counts number of LiveReset while waiting for a 1st picture decoded (automatic Stop()/Start() when idle for too long in real-time) */
    U32 ApiPbLiveResetWaitForNextPicture;   /* Counts number of LiveReset while waiting for the next picture decoded (automatic Stop()/Start() when idle for too long in real-time) */
    U32 AvsyncSkippedFields;                /* Counts number of fields skipped because of AVSYNC module */
    U32 AvsyncRepeatedFields;               /* Counts number of fields repeated because of AVSYNC module */
    U32 AvsyncMaxRepeatedFields;            /* Counts max number of fields required to be repeated at the display */
    U32 AvsyncFailedToSkipFields;           /* Counts number of fields that could not be skipped because display could not */
    U32 AvsyncExtendedSTCAvailable;         /* Counts number of time an extended STC was obtained successfully from STCLKRV */
    U32 AvsyncPictureWithNonInterpolatedPTS;/* Counts number of pictures with PTS's in the stream (non interpolated) */
    U32 AvsyncPictureCheckedSynchronizedOk; /* Counts number of pictures that were checked to be syncronized OK (need PTS+STC+enablesync+speed100) */
    U32 AvsyncPTSInconsistency;             /* Counts number of time the PTS of the current picture is not greater than the PTS of the previous picture */
    U32 DecodeHardwareSoftReset;            /* Counts number of soft reset of the hardware decoder */
    U32 DecodeStartCodeFound;               /* Counts number of start code found in bit buffer */
    U32 DecodeSequenceFound;                /* Counts number of sequence start code found in bit buffer */
    U32 DecodeUserDataFound;                /* Counts number of user data start code found in bit buffer */
    U32 DecodePictureFound;                 /* Counts number of picture srat code found in bit buffer */
    U32 DecodePictureFoundMPEGFrameI;       /* Counts number of I pictures found in bit buffer */
    U32 DecodePictureFoundMPEGFrameP;       /* Counts number of P pictures found in bit buffer */
    U32 DecodePictureFoundMPEGFrameB;       /* Counts number of B pictures found in bit buffer */
    U32 DecodePictureSkippedRequested;      /* Counts number of times the deccode of a picture was skipped following a request from Avsync or trickmode */
    U32 DecodePictureSkippedNotRequested;   /* Counts number of times the deccode of a picture was skipped without request from Avsync or trickmode */
    U32 DecodePictureDecodeLaunched;        /* Counts number of times the deccode of a picture is launched */
    U32 DecodeStartConditionVbvDelay;       /* Counts number of times the 1st decode after STVID_Start occurs according to the Vbv_Delay information. */
    U32 DecodeStartConditionPtsTimeComparison; /* Counts number of times the 1st decode after STVID_Start occurs according to the comparison PTS - STC. */
    U32 DecodeStartConditionVbvBufferSize;  /* Counts number of times the 1st decode after STVID_Start occurs according to the Vbv_Buffer_Size information. */
    U32 DecodeInterruptStartDecode;         /* Counts number of StartDecode interrupts */
    U32 DecodeInterruptPipelineIdle;        /* Counts number of PipelineIdle interrupts */
    U32 DecodeInterruptDecoderIdle;         /* Counts number of DecoderIdle interrupts */
    U32 DecodeInterruptBitBufferEmpty;      /* Counts number of BitBufferEmpty interrupts */
    U32 DecodeInterruptBitBufferFull;       /* Counts number of BitBufferFull interrupts */
    U32 DecodePbStartCodeFoundInvalid;      /* Counts number of invalid start code found in bit buffer */
    U32 DecodePbStartCodeFoundVideoPES;     /* Counts number of invalid start code found in bit buffer that are MPEG video PES start codes */
    U32 DecodePbMaxNbInterruptSyntaxErrorPerPicture;    /* Counts number of SyntaxError interrupts */
    U32 DecodePbInterruptSyntaxError;       /* Counts number of SyntaxError interrupts */
    U32 DecodePbInterruptDecodeOverflowError;/* Counts number of decode overflow interrupts */
    U32 DecodePbInterruptDecodeUnderflowError;/* Counts number of decode underflow interrupts */
    U32 DecodePbDecodeTimeOutError;         /* Counts number of decode time out */
    U32 DecodePbInterruptMisalignmentError; /* Counts number of decode misalignments */
    U32 DecodePbInterruptQueueOverflow;     /* Counts number of times the decode queue of interrupts overflows. Consequence: no IT flag is lost, but multiplicity can be lost because new IT status are ORed. */
    U32 DecodePbHeaderFifoEmpty;            /* Counts number of times the header fifo was empty when poping start code or bits. */
    U32 DecodePbVbvSizeGreaterThanBitBuffer;/* Counts number of times vbv decode level from the stream is greater than the bit buffer size. (Bit buffer is theroritically too small to decode the stream) */
    U32 DecodeMinBitBufferLevelReached;     /* Tells min bit buffer level of occupancy reached according to software polling. */
    U32 DecodeMaxBitBufferLevelReached;     /* Tells max bit buffer level of occupancy reached according to software polling. */
    U32 DecodePbSequenceNotInMemProfileSkipped; /* Counts number of sequence skipped at decode level because they don't fit in the memory profile */
    U32 DecodePbParserError;                /* Counts number of errors reported by parser driver (delta IP) */
    U32 DecodePbPreprocError;               /* Counts number of errors reported by proprocessor driver (delta IP) */
    U32 DecodePbFirmwareError;              /* Counts number of errors reported by Firmware (delta IP) */
#ifdef ST_VALIDATION
    U32 DecodePbFirmwareWatchdogError;      /* Counts number of time out (Firmware WatchDog) errors reported by firmware */
#endif /*if defined(ST_VALIDATION)*/
    U32 DecodeGNBvd42696Error;              /* Counts number of GNBvd42696 (DMC) errors reported by firmware */
/* Decode time statistics from VIDPROD in MicroSeconds */
    U32 DecodeTimeNbPictures;
    U32 DecodeTimeMinPreprocessTime;
    U32 DecodeTimeMaxPreprocessTime;
    U32 DecodeTimeSumOfPreprocessTime;
    U32 DecodeTimeMinBufferSearchTime;
    U32 DecodeTimeMaxBufferSearchTime;
    U32 DecodeTimeSumOfBufferSearchTime;
    U32 DecodeTimeMinDecodeTime;
    U32 DecodeTimeMaxDecodeTime;
    U32 DecodeTimeSumOfDecodeTime;
    U32 DecodeTimeMinFullDecodeTime;
    U32 DecodeTimeMaxFullDecodeTime;
    U32 DecodeTimeSumOfFullDecodeTime;
    U32 DecodeTimeMinLXDecodeTime;
    U32 DecodeTimeMaxLXDecodeTime;
    U32 DecodeTimeSumOfLXDecodeTime;
    U32 DecodeTimeHistoryPicture[5];
    U32 DecodeTimeMaxAvgOver5SlidingPictures;
    U32 DecodeTimeLXHistoryPicture[5];
    U32 DecodeTimeLXMaxAvgOver5SlidingPictures;
/* End of Decode time statistics from VIDPROD */
    U32 DisplayPictureInsertedInQueue;              /* Counts number of pictures inserted in display queue */
    U32 DisplayPictureInsertedInQueueDecimated;     /* Counts number of pictures inserted in display queue */
    U32 DisplayPictureDisplayedByMain;              /* Counts number of pictures displayed (not decimated) */
    U32 DisplayPictureDisplayedByAux;               /* Counts number of pictures displayed (not decimated) */
    U32 DisplayPictureDisplayedBySec;               /* Counts number of pictures displayed (not decimated) */
    U32 DisplayPictureDisplayedDecimatedByMain;     /* Counts number of decimated pictures displayed */
    U32 DisplayPictureDisplayedDecimatedByAux;      /* Counts number of decimated pictures displayed */
    U32 DisplayPictureDisplayedDecimatedBySec;      /* Counts number of decimated pictures displayed */
    U32 DisplayPbQueueLockedByLackOfPicture;        /* Counts number of time the display queue is locked by lack of picture to display */
    U32 DisplayPbVSyncDuringDisplayProgramming;     /* Counts number of times a HW VSync occurs while a display programming is in progress */
    U32 DisplayPbQueueOverflow;                     /* Counts number of overflow of the display queue */
    U32 DisplayPbPictureTooLateRejectedByMain;      /* NOT USED ANYMORE */
    U32 DisplayPbPictureTooLateRejectedByAux;       /* NOT USED ANYMORE */
    U32 DisplayPbPictureTooLateRejectedBySec;       /* NOT USED ANYMORE */
    U32 DisplayPbPicturePreparedAtLastMinuteRejected;/* NOT USED ANYMORE */

    U32 QueuePictureInsertedInQueue;                /* Counts number of pictures inserted in ordering queue */
    U32 QueuePictureRemovedFromQueue;               /* Counts number of pictures removed from ordering queue */
    U32 QueuePicturePushedToDisplay;                /* Counts number of pictures pushed to display */
    U32 QueuePbPictureTooLateRejected;              /* Counts number of pictures rejected because too late */
    U32 SpeedDisplayBFramesNb;
    U32 SpeedDisplayPFramesNb;
    U32 SpeedDisplayIFramesNb;
    U32 MaxBitRate;
    U32 MinBitRate;
    U32 LastBitRate;
    S32 MaxPositiveDriftRequested;
    S32 MaxNegativeDriftRequested;
    U32 NbDecodedPicturesB;
    U32 NbDecodedPicturesP;
    U32 NbDecodedPicturesI;
    U32 SpeedSkipReturnNone;
    U32 SpeedRepeatReturnNone;
    /* Inject statistics ---------------------------------------------------- */
    U32 InjectFdmaTransfers;                /* Counts the number of FDMA transfers performed */
    void * InjectDataInputReadPointer;      /* Tells current read pointer in the data input buffer */
    void * InjectDataInputWritePointer;     /* Tells current write pointer in the data input buffer */
} STVID_Statistics_t;

ST_ErrorCode_t STVID_GetStatistics(const ST_DeviceName_t DeviceName, STVID_Statistics_t * const Statistics_p);
ST_ErrorCode_t STVID_ResetStatistics(const ST_DeviceName_t DeviceName, const STVID_Statistics_t * const Statistics_p);
#endif /* STVID_DEBUG_GET_STATISTICS */

#ifdef STVID_DEBUG_GET_STATUS
typedef struct STVID_Status_s
{
    /* Syntax for the naming of statistics variables: <module>[Pb]<variable_name>
        . <module> tells which module is responsible for the variable,
        . [Pb] is present if in the normal operations the variable should remain 0,
        . <variable_name> is the meaning of the variable */
    /* Driver status (API variables) */
    void * BitBufferAddress_p;
    U32    BitBufferSize;                    /* in byte */
    void * DataInputBufferAddress_p;
    U32    DataInputBufferSize;              /* in byte */
    void * SCListBufferAddress_p;
    U32    SCListBufferSize;                 /* in byte */
    void * IntermediateBuffersAddress_p;
    U32    IntermediateBuffersSize;          /* in byte */
    U32    FdmaNodesSize;                    /* in byte */
    U32    InjectFlushBufferSize;            /* in byte */

    /* TODO Calculate PictureParameterBuffersSize */
    /* U32    PictureParameterBuffersSize; */     /* in byte */

    STVID_InitContext_t    InitContext;      /* Init context params */
    STVID_MemoryProfile_t  MemoryProfile;    /* Current memory profile */
    enum StateMachine_e                      /* TDB like in api.h */
    {
      VIDEO_STATE_STOPPED,
      VIDEO_STATE_RUNNING,
      VIDEO_STATE_PAUSING,
      VIDEO_STATE_FREEZING
    } StateMachine;                          /* State of the instance */
    S32   SyncDelay;
    BOOL VideoAlreadyStarted;                /* TRUE when STVID_Start is called */
    STVID_StartParams_t LastStartParams;     /* Last start parameters */
    BOOL VideoAlreadyFreezed;                /* TRUE when STVID_Freeze is called */
    STVID_Freeze_t LastFreezeParams;         /* Last freeze parameters */

    /* Driver status (internal variables) */
    /* TODO Calculate BitRateValue, DisplayLatency and PresentationDelay */
    /* U32   BitRateValue; */                     /* Last computed bit rate value */
    /* U8    DisplayLatency; */                   /* # of field latency introduced by the display */
    /* U32   PresentationDelay; */                /* */
    void * BitBufferReadPointer;             /* Current read pointer in the bit buffer */
    void * BitBufferWritePointer;            /* Current write pointer in the bit buffer */
    void * DataInputBufferReadPointer;       /* Current read pointer in the data input buffer */
    void * DataInputBufferWritePointer;      /* Current write pointer in the data input buffer */
    void * SCListBufferReadPointer;          /* Current read pointer in the SC List buffer */
    void * SCListBufferWritePointer;         /* Current write pointer in the SC List buffer */

    /* Stream status / characteristics */
    STVID_SequenceInfo_t* SequenceInfo_p;  /* Last sequence information, NULL if none or stopped */
    /* TODO Calculate LastDecodedPictureInfos_p and LastDisplayedPictureInfos_p */
    /* STVID_PictureInfos_t * LastDecodedPictureInfos_p; */ /* Last picture information, NULL if none */
    /* STVID_PictureInfos_t * LastDisplayedPictureInfos_p; */ /* Last picture information, NULL if none */

    /* Environment status */
    /* TODO Calculate DisplayMasterVTGFrameRate, DisplaySlaveVTGFrameRate and STC */
    /* U32   DisplayMasterVTGFrameRate; */       /* Frame rate of the VTG driving the master display */
    /* U32   DisplaySlaveVTGFrameRate; */        /* Frame rate of the VTG driving the slave display */
    /* STVID_PTS_t STC; */                      /* Last captured STC */
} STVID_Status_t;

ST_ErrorCode_t STVID_GetStatus(const ST_DeviceName_t DeviceName, STVID_Status_t * const Status_p);
#endif /* STVID_DEBUG_GET_STATUS */


#if ! defined STVID_NO_COMPOSITION
    #ifndef STVID_USE_CONNECTED_VIEWPORTS
        ST_ErrorCode_t STVID_SetViewPortQualityOptimizations(const STVID_ViewPortHandle_t ViewPortHandle,
                                                             const STLAYER_QualityOptimizations_t * Params_p);
        ST_ErrorCode_t STVID_GetViewPortQualityOptimizations(const STVID_ViewPortHandle_t ViewPortHandle,
                                                             STLAYER_QualityOptimizations_t * const Params_p);
        ST_ErrorCode_t STVID_GrabAndTakeViewportPictureBuffer (const STVID_ViewPortHandle_t ViewPortHandle,
                                                               const STLAYER_GrabReleaseMode_t GrabReleaseMode,
                                                               STLAYER_PictureInfos_t * const PictureInfos_p);
        ST_ErrorCode_t STVID_ReleaseViewportPictureBuffer (const STVID_ViewPortHandle_t ViewPortHandle,
                                                           const STLAYER_PictureBufferHandle_t PictureBufferHandle);
        ST_ErrorCode_t STVID_SetViewPortDecimationMode (const STVID_ViewPortHandle_t ViewPortHandle,
                                                        const  STLAYER_DecimationMode_t DecimationMode);
        ST_ErrorCode_t STVID_GetViewPortDecimationMode (const STVID_ViewPortHandle_t ViewPortHandle,
                                                        STLAYER_DecimationMode_t  * DecimationMode_p);

        #ifdef VIDEO_DEBUG_DEINTERLACING_MODE
            ST_ErrorCode_t STVID_GetRequestedDeinterlacingMode(const STVID_ViewPortHandle_t ViewPortHandle,
                    STLAYER_DeiMode_t * const RequestedMode_p);
            ST_ErrorCode_t STVID_SetRequestedDeinterlacingMode(const STVID_ViewPortHandle_t ViewPortHandle,
                const STLAYER_DeiMode_t RequestedMode);
        #endif /* VIDEO_DEBUG_DEINTERLACING_MODE */

        #ifdef STVID_USE_FMD_REPORTING
            ST_ErrorCode_t STVID_SetFMDParams(const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_FMDParams_t * Params_p);
            ST_ErrorCode_t STVID_GetFMDParams(const STVID_ViewPortHandle_t ViewPortHandle, STLAYER_FMDParams_t * Params_p);
            ST_ErrorCode_t STVID_EnableFMDReporting(const STVID_ViewPortHandle_t ViewPortHandle);
            ST_ErrorCode_t STVID_DisableFMDReporting(const STVID_ViewPortHandle_t ViewPortHandle);
        #endif /* STVID_USE_FMD_REPORTING */

        #ifdef STVID_DEBUG_GET_DISPLAY_PARAMS
            ST_ErrorCode_t STVID_GetVideoDisplayParams(const STVID_ViewPortHandle_t ViewPortHandle, STLAYER_VideoDisplayParams_t * Params_p);
            ST_ErrorCode_t STVID_SetVideoDisplayParams(const STVID_ViewPortHandle_t ViewPortHandle, const STLAYER_VideoDisplayParams_t * Params_p);
        #endif /*STVID_DEBUG_GET_DISPLAY_PARAMS*/

    #endif /* !STVID_USE_CONNECTED_VIEWPORTS */
#endif /* !STVID_NO_COMPOSITION */



#if defined(ST_VALIDATION)&&defined(ST_VALIMSGLOG)
ST_ErrorCode_t STVID_SetMSGLOGHandle(const STVID_Handle_t VideoHandle, MSGLOG_Handle_t MSGLOG_Handle);
#endif /*defined(ST_VALIDATION)&&defined(ST_VALIMSGLOG)*/


#ifdef STVID_USE_CRC
typedef enum STVID_CRCFieldInversion_e
{
    STVID_CRC_INVFIELD_NONE,
    STVID_CRC_INVFIELD_WITH_PREVIOUS,
    STVID_CRC_INVFIELD_WITH_NEXT
} STVID_CRCFieldInversion_t;

typedef struct STVID_RefCRCEntry_s
{
    U32                         IDExtension;    /* MSB for PictureID, incremented at each "reset" of ID */
    S32                         ID;             /* LSB for PictureID */
    U32                         LumaCRC;
    U32                         ChromaCRC;
    BOOL                        FieldPicture;
} STVID_RefCRCEntry_t;

typedef struct STVID_CompCRCEntry_s
{
    U32                         IDExtension;    /* MSB for PictureID, incremented at each "reset" of ID */
    S32                         ID;             /* LSB for PictureID */
    U32                         DecodingOrderFrameID; /* FrameID with same value for both fields of field picture */
    U32                         LumaCRC;
    U32                         ChromaCRC;
    U32                         NbRepeatedLastPicture;
    U32                         NbRepeatedLastButOnePicture;
    BOOL                        FieldPicture;
    U32                         FieldCRC;
    BOOL                        IsMonochrome;
} STVID_CompCRCEntry_t;

typedef struct STVID_CRCErrorLogEntry_s
{
    U32                         RefCRCIndex;
    U32                         CompCRCIndex;
    U32                         IDExtension;    /* MSB for PictureID, incremented at each "reset" of ID */
    S32                         ID;             /* LSB for PictureID */
    U32                         DecodingOrderFrameID; /* FrameID with same value for both fields of field picture */
    U32                         LumaCRC;
    U32                         ChromaCRC;
    STVID_CRCFieldInversion_t   InvertedFields;
    BOOL                        LumaError;
    BOOL                        ChromaError;
    BOOL                        FieldPicture;
    U32                           FieldCRC;
    BOOL                        IsMonochrome;
} STVID_CRCErrorLogEntry_t;

typedef struct STVID_CRCStartParams_s
{
    U32                         NbPictureInRefCRC;
    STVID_RefCRCEntry_t         *RefCRCTable;
    U32                         MaxNbPictureInCompCRC;
    STVID_CompCRCEntry_t        *CompCRCTable;
    U32                         MaxNbPictureInErrorLog;
    STVID_CRCErrorLogEntry_t    *ErrorLogTable;
    U32                         NbPicturesToCheck;
    BOOL                        DumpFailingFrames;
} STVID_CRCStartParams_t;

typedef struct STVID_CRCCheckResult_s
{
    U32 NbRefCRCChecked;     /* Number of reference CRC checked (repeated pictures excluded */
    U32 NbCompCRC;           /* Number of Computed CRC stored in CompCRCTable including overwritten ones */
    U32 NbErrorsAndWarnings; /* Number of Error/warnings log stored in ErrorLogTable including overwritten ones */
    U32 NbErrors;            /* Number of Error only stored in ErrorLogTable including overwritten ones */
} STVID_CRCCheckResult_t;

typedef struct STVID_CRCDataMessage_s
{
    U32 IsReferencePicture;
    S32 PictureOrderCount ;
    U32 LumaCRC ;
    U32 ChromaCRC;
    U32 IsFieldCRC;
    U32 IsFieldBottomNotTop;
} STVID_CRCDataMessage_t;

typedef struct STVID_CRCReadMessages_s
{
    U8 NbToRead;
    STVID_CRCDataMessage_t *Messages_p;
    U8 NbReturned;
} STVID_CRCReadMessages_t;


ST_ErrorCode_t STVID_CRCStartCheck(const STVID_Handle_t VideoHandle, STVID_CRCStartParams_t *StartParams_p);
BOOL STVID_IsCRCCheckRunning(const STVID_Handle_t VideoHandle);
BOOL STVID_IsCRCModeField(const STVID_Handle_t VideoHandle,
                          STVID_PictureInfos_t *PictureInfos_p,
                          STVID_MPEGStandard_t MPEGStandard);
ST_ErrorCode_t STVID_CheckCRC(const STVID_Handle_t VideoHandle,
                                STVID_PictureInfos_t *PictureInfos_p,
                                U32 ExtendedPresentationOrderPictureIDExtension, U32 ExtendedPresentationOrderPictureID,
                                U32 DecodingOrderFrameID, U32 PictureNumber,
                                BOOL IsRepeatedLastPicture, BOOL IsRepeatedLastButOnePicture,
                                void *LumaAddress_NCp, void *ChromaAddress_NCp,
                                U32 LumaCRC, U32 ChromaCRC);
ST_ErrorCode_t STVID_CRCStopCheck(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_CRCGetCurrentResults(const STVID_Handle_t Handle, STVID_CRCCheckResult_t *CRCCheckResult_p);

ST_ErrorCode_t STVID_CRCStartQueueing(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_CRCStopQueueing(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_CRCStartNotifying(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_CRCStopNotifying(const STVID_Handle_t VideoHandle);
ST_ErrorCode_t STVID_CRCGetQueue(const STVID_Handle_t VideoHandle, STVID_CRCReadMessages_t *ReadCRC_p);
ST_ErrorCode_t STVID_CRCSetViewPortHandle(const STVID_Handle_t VideoHandle, const STVID_ViewPortHandle_t ViewPortHandle);
#endif /* STVID_USE_CRC */

#if defined(VALID_TOOLS)
ST_ErrorCode_t STVID_RegisterTraces(void);
#endif /* if defined(VALID_TOOLS) */


/* END OF Un-supported extensions (debug only) - see warning on top of section */

#ifdef ST_OSLINUX
#if !defined MODULE && !defined STVID_MMAP_PESBUFFERS_IN_USERWRAPPER
ST_ErrorCode_t STVID_MapPESBufferToUserSpace(STVID_Handle_t Handle, void ** Address_pp, U32 Size);
ST_ErrorCode_t STVID_UnmapPESBufferFromUserSpace(STVID_Handle_t Handle);
#endif
#endif  /* LINUX */

/* Export IPRC handler */
int stvid_IPrC_Handler(U32 request, void *arg);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* #ifndef __STVID_H */

/* End of stvid.h */
