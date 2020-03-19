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
 @File   staudlx.h
 @brief



*/
#ifndef __STAUDLX_H
#define __STAUDLX_H

/* Includes ----------------------------------------- */

#include "stddefs.h"
#include "stavmem.h"
#include "stevt.h"
#include "stcommon.h"
#include "stmmdefs.h"
#if defined (ST_FLI7510) || defined (ST_FLI7540)
#include"stfrontend.h"
#endif
#include "stclkrv.h"
#ifdef STPOWER_SUPPORTED
#include "stpower.h"
#endif
#define MUTE_AT_DECODER 0
#ifdef __cplusplus
extern "C" {
#endif

#ifdef STCOMPANION_SUPPORTED
#include "stcompanion.h"
#endif
#ifndef STAUD_MAX_SPEED
#define STAUD_MAX_SPEED 180
#endif
#define STAUD_MIN_SPEED 80
#define STAUD_NORMAL_SPEED 100


#define BASE_MASK  0x80000000
#define MASK 0x7FFFFFFF
#define STAUDLX_BUFFERTHRESHOLD_INBYTES(x)  BASE_MASK | x
#define MAXNUMBEROFBANDS 15         // Number of Bands limited to 15
#define NUM_FILT_COEF_PER_FILT 6    // # of filter coef per length
#define DDPULSE_MAX_DRC_VALUE  127
#define DDPLUS_MAX_DRC_VALUE  255
#define DRC_ENABLE_BITMASK 0x1
#define DRC_PERSENT_BITMASK 0x2

    /* Exported Types ----------------------------------- */

    /* Constants ---------------------------------------- */
#define ST_MAX_DEVICE_NAME_TOCOPY (ST_MAX_DEVICE_NAME-1)  /* 15 characters used in strcpy */
#define STAUD_DRIVER_ID       16
#define STAUD_DRIVER_BASE     (STAUD_DRIVER_ID << 16)
#define STAUD_MAX_DEVICE      1
#define STAUD_MAX_OPEN        1
#define MAX_AUDIO_INSTANCE    4
    /* Error return codes */
#define STAUD_ERROR_BASE     STAUD_DRIVER_BASE
    enum
    {
        STAUD_ERROR_DECODER_RUNNING = STAUD_DRIVER_BASE,
        STAUD_ERROR_DECODER_STOPPED,
        STAUD_ERROR_DECODER_PREPARING,
        STAUD_ERROR_DECODER_PREPARED,
        STAUD_ERROR_DECODER_PAUSING,
        STAUD_ERROR_DECODER_NOT_PAUSING,
        STAUD_ERROR_INVALID_STREAM_ID,
        STAUD_ERROR_INVALID_STREAM_TYPE,
        STAUD_ERROR_INVALID_DEVICE,
        STAUD_ERROR_EVT_REGISTER,
        STAUD_ERROR_EVT_UNREGISTER,
        STAUD_ERROR_CLKRV_OPEN,
        STAUD_ERROR_CLKRV_CLOSE,
        STAUD_ERROR_AVSYNC_TASK,
        STAUD_ERROR_MEMORY_DEALLOCATION_FAILED,
        STAUD_ERROR_INVALID_INPUT_TYPE,
        STAUD_MEMORY_GET_ERROR,
        STAUD_FRAME_ERROR,
        STAUD_ASF_ERROR_INVALID_TAG,
        STAUD_ERROR_IO_REMAP_FAILED,
        STAUD_ERROR_INVALID_STATE,
        STAUD_ERROR_ALREADY_IN_SAME_STATE,
        STAUD_ERROR_DECODER_START,
        STAUD_ERROR_DECODER_STOP,
        STAUD_ERROR_MME_TRANSFORM,
        STAUD_ERROR_WRONG_CMD_PARAM,
        STAUD_ERROR_INVALID_ENC_CONFIG,
        STAUD_ERROR_ENCODER_START,
        STAUD_ERROR_ENCODER_STOP,
        STAUD_ERROR_NOT_ENOUGH_BUFFERS,
#ifdef STCOMPANION_SUPPORTED
        STAUD_ERROR_LX_NOT_RESPONDING
#endif
    };

    /* Events */
    enum
    {
        STAUD_NEW_FRAME_EVT = STAUD_DRIVER_BASE,
        STAUD_DATA_ERROR_EVT,
        STAUD_EMPHASIS_EVT,
        STAUD_PREPARED_EVT,
        STAUD_RESUME_EVT,
        STAUD_STOPPED_EVT,
        STAUD_PCM_UNDERFLOW_EVT,
        STAUD_PCM_BUF_COMPLETE_EVT,
        STAUD_FIFO_OVERF_EVT,
        STAUD_NEW_ROUTING_EVT,
        STAUD_NEW_FREQUENCY_EVT,
        STAUD_CDFIFO_UNDERFLOW_EVT,
        STAUD_SYNC_ERROR_EVT,
        STAUD_LOW_DATA_LEVEL_EVT,
        STAUD_PLAYERPARAMS_EVT,
        STAUD_STREAM_INFO_UPDATE_EVT,
        STAUD_MARKER_DETECTION_EVT,
        STAUD_PCMPLAYER_UNDERFLOW,
        STAUD_SPDIFPLAYER_UNDERFLOW,

        STAUD_AVSYNC_SKIP_EVT,
        STAUD_AVSYNC_PAUSE_EVT,
        STAUD_IN_SYNC,
        STAUD_OUTOF_SYNC,
        STAUD_PTS_EVT,
        STAUD_EOF_EVT,                  //Will be gnerated only for WMA/WMAPro
        STAUD_SPDIFRX_FORMAT_EVT,
        STAUD_TEST_NODE_EVT,
        STAUD_TEST_PCM_START_EVT,
        STAUD_TEST_PCM_RESTART_EVT,
        STAUD_TEST_PCM_PAUSE_EVT,
        STAUD_TEST_PCM_STOP_EVT,
        STAUD_TEST_DECODER_STOP_EVT,
        STAUD_STARTING_EVT,
        STAUD_CKSUM_EVT,
        STAUD_NOTIFICATION_EVT, //This event is sent when the condition of an already enabled notification is validated.
        STAUD_DDPULSEID_EVT,
        STAUD_RESERVED_EVT

    };

    typedef enum
    {
        DCREMOVE_DISABLED,
        DCREMOVE_ENABLED,
        DCREMOVE_AUTO,
        // Do not edit below this line
        DCREMOVE_END_OF_PROCESS_APPLY

    }STAUD_DCRemove_t;

    typedef enum STAUD_PCMMode_e
    {
        PCM_ON,
        PCM_OFF

    } STAUD_PCMMode_t;

    /* Object type basic masks */
#if 1
#define    STAUD_CLASS_MASK             0x0FFF0000
#define    STAUD_OPID_MASK              0xF0000000
#define    STAUD_SET_OPID(x,y)          (x = (x|(y << 28)))
#define    STAUD_CLR_OPID(x)            (x = (x & (~STAUD_OPID_MASK)))
#define    STAUD_GET_OPID(x)            ((x & STAUD_OPID_MASK)>>28)
#else
#define    STAUD_CLASS_MASK             0xFFFF0000
#endif
#define    STAUD_TYPE_MASK              0x0000FF00
#define    STAUD_INSTANCE_MASK          0x000000FF
#define    STAUD_OBJECT_MASK            (STAUD_CLASS_MASK | STAUD_TYPE_MASK)

#define    GET_CLASS(Obj)               (Obj & STAUD_CLASS_MASK)
#define    GET_OBJ(Obj)                 (Obj & STAUD_OBJECT_MASK)
#define    GET_INSTANCE(Obj)            (Obj & STAUD_INSTANCE_MASK)

#if 1
     enum
     {
        STAUD_CLASS_INPUT           = (1 << 16),    //0x00010000
        STAUD_CLASS_DECODER         = (2 << 16),    //0x00020000
        STAUD_CLASS_POSTPROC        = (3 << 16),    //0x00030000
        STAUD_CLASS_MIXER           = (4 << 16),    //0x00040000
        STAUD_CLASS_OUTPUT          = (5 << 16),    //0x00050000
        STAUD_CLASS_FORMATTER       = (6 << 16),    //0x00060000
        STAUD_CLASS_BLOCKMNG        = (7 << 16),    //0x00070000
        STAUD_CLASS_ENCODER         = (8 << 16),    //0x00100000
        STAUD_CLASS_SPDIF_FORMATTER = (9 << 16),    //0x00110000
        //Do not add beyond this line or value
        STAUD_CLASS_MAX             = (0xFFF << 16)
    };
#else
    /* MSB 4 nibbles for CLASS*/
#define    STAUD_CLASS_INPUT            (0x1 << 16) //0x00010000
#define    STAUD_CLASS_DECODER          (0x1 << 17) //0x00020000
#define    STAUD_CLASS_POSTPROC         (0x1 << 18) //0x00040000
#define    STAUD_CLASS_MIXER            (0x1 << 19) //0x00080000
#define    STAUD_CLASS_OUTPUT           (0x1 << 20) //0x00100000
#define    STAUD_CLASS_FORMATTER        (0x1 << 21) //0x00200000
#define    STAUD_CLASS_BLOCKMNG         (0x1 << 22) //0x00400000
#define    STAUD_CLASS_ENCODER          (0x1 << 23) //0x00800000
#define    STAUD_CLASS_SPDIF_FORMATTER  (0x1 << 24) //0x01000000
#endif

    /* End to added for the compile */

/* Next 2 Nibbles for TYPE*/
#define    STAUD_TYPE_INPUT_COMPRESSED      (0x1 << 8) //0x00000000
#define    STAUD_TYPE_INPUT_PCM             (0x1 << 9) //0x00000100
#define    STAUD_TYPE_INPUT_PCM_READER      (0x1 << 10)//0x00000200

#define    STAUD_TYPE_DECODER_COMPRESSED    (0x1 << 8) //0X00000000

#define    STAUD_TYPE_ENCODER_COMPRESSED    (0x1 << 8) //0X00000000

#define    STAUD_TYPE_OUTPUT_SPDIF          (0x1 << 8) //0x00000000
#define    STAUD_TYPE_OUTPUT_ANALOG         (0x1 << 9) //0x00000200

#define    STAUD_TYPE_PPROC_GENERIC         (0x1 << 8) //0x00000100

#define    STAUD_TYPE_MIXER_PCM             (0x1 << 8) //0x00000200

#define    STAUD_TYPE_DATA_FORMATTER        (0x1 << 8) //0x00000100
#define    STAUD_TYPE_DUMPER                (0x1 << 9) //0x00000200
/* Next 2 Nibbles for Instance*/
    enum
    {
        STAUD_INSTANCE_0 = 0x01,
        STAUD_INSTANCE_1,
        STAUD_INSTANCE_2,
        STAUD_INSTANCE_3,
        STAUD_INSTANCE_4,
        STAUD_INSTANCE_5,
        STAUD_INSTANCE_6,
        STAUD_INSTANCE_7,
        STAUD_INSTANCE_8,
        STAUD_INSTANCE_9,
        STAUD_INSTANCE_10,
        STAUD_INSTANCE_11,
        //Do not add beyong this line
        STAUD_INSTANCE_MAX
    };

    /* Constants used in STAUD_Capability_t */
#define STAUD_MAX_PCM_FREQS     16
#define STAUD_MAX_TRICK_SPEEDS      6
#define STAUD_MAX_INPUT_OBJECTS     (14 + 1) // 9 parser + 5 reader + I PCM input
#define STAUD_MAX_DECODER_OBJECTS   9  // 9 decoder
#define STAUD_MAX_POST_PROC_OBJECTS 6  // 6 PP
#define STAUD_MAX_MIXER_OBJECTS     2  // 2 mixer
#define STAUD_MAX_OUTPUT_OBJECTS    7  // 5 pcm player + 1 SPDIF player
#define STAUD_MAX_ENCODER_OBJECTS   1  // 1 encoder
#define STAUD_MAX_SPDIFFORMATTER_OBJECTS   1  // 1 SPDIF formatter
#define STAUD_MAX_FP_OBJECTS        4  // 4 Frame Processor

    /* Others */
#define STAUD_IGNORE_ID         0xFF
#define STAUD_EVENT_NUMBER      14

#ifdef ST_OSLINUX
/* This defines the size of the mme buffer which will be used for mme wrapper
     implementation for STLinux
*/
#define MME_DATA_DUMP_SIZE  (3072 * 1024)
#endif

#if defined(ST_FLI7510) || defined(ST_FLI7540)
#define STAUDLX_FAO_PARAM_MAX_SIZE  512*2*2
#endif

    typedef U32 STAUD_Handle_t;


/**************this is for internal use only********/
    typedef enum AUD_ModuleOPIndex_e
    {
        AUD_MAIN_OUT,
//        #if !defined(ST40_AUDIO_CODEC)
            AUD_DIG_OUT,
            AUD_AUX_OUT,
            AUD_HDMI_OUT,
//        #endif
        AUD_MODULE_MAX_OUT
    }AUD_ModuleOPIndex_t;
/**************************************/

    typedef ST_ErrorCode_t
    (*GetWriteAddress_t)(void * const handle, void** const address_p);

    typedef ST_ErrorCode_t
    (*InformReadAddress_t)(void * const handle, void* const address);

    typedef enum STAUD_PlayerID_e
    {
        STAUD_PLAYER_ID_1,
        STAUD_PLAYER_ID_2,
        STAUD_PLAYER_ID_3,
        STAUD_PLAYER_ID_4,
        STAUD_PLAYER_ID_MAX,
        STAUD_PLAYER_DEFAULT
    } STAUD_AudioPlayerID_t;


   typedef struct STAUD_BufferParams_s
    {
        void* BufferBaseAddr_p;
        U32   BufferSize;
        U32   NumBuffers;

    } STAUD_BufferParams_t;

    typedef enum STAUD_BufferID_e
    {
        STAUD_BUFFER_CD1,
        STAUD_BUFFER_CD2,
        STAUD_BUFFER_PCM1,
        STAUD_BUFFER_PCM2,
        STAUD_BUFFER_ID_MAX
    } STAUD_BufferID_t;

    typedef enum STAUD_WordWidth_e
    {
        STAUD_WORD_WIDTH_8,
        STAUD_WORD_WIDTH_16,
        STAUD_WORD_WIDTH_32

    } STAUD_WordWidth_t;

    typedef enum STAUD_Karaoke_e
    {
        STAUD_KARAOKE_NONE = 0,
        STAUD_KARAOKE_AWARE = 1,
        STAUD_KARAOKE_MUSIC = 2,
        STAUD_KARAOKE_VOCAL1 = 4,
        STAUD_KARAOKE_VOCAL2 = 8,
        STAUD_KARAOKE_VOCALS = 16

    } STAUD_Karaoke_t;

    enum
    {
        OBJECT_INPUT_PARSER    = (U32)(STAUD_CLASS_INPUT   | STAUD_TYPE_INPUT_COMPRESSED),
        OBJECT_INPUT_PCM       = (U32)(STAUD_CLASS_INPUT   | STAUD_TYPE_INPUT_PCM),
        OBJECT_INPUT_READER    = (U32)(STAUD_CLASS_INPUT   | STAUD_TYPE_INPUT_PCM_READER),
        OBJECT_DECODER         = (U32)(STAUD_CLASS_DECODER | STAUD_TYPE_DECODER_COMPRESSED),
        OBJECT_ENCODER         = (U32)(STAUD_CLASS_ENCODER | STAUD_TYPE_ENCODER_COMPRESSED),
        OBJECT_MIXER           = (U32)(STAUD_CLASS_MIXER   | STAUD_TYPE_MIXER_PCM),
        OBJECT_POSTPROC        = (U32)(STAUD_CLASS_POSTPROC| STAUD_TYPE_PPROC_GENERIC),
        OBJECT_OUTPUT_PCMP     = (U32)(STAUD_CLASS_OUTPUT  | STAUD_TYPE_OUTPUT_ANALOG),
        OBJECT_OUTPUT_SPDIF    = (U32)(STAUD_CLASS_OUTPUT  | STAUD_TYPE_OUTPUT_SPDIF),
        OBJECT_DATA_FORMATTER  = (U32)(STAUD_CLASS_FORMATTER | STAUD_TYPE_DATA_FORMATTER),
        OBJECT_DATA_DUMPER     = (U32)(STAUD_CLASS_FORMATTER | STAUD_TYPE_DUMPER),
        OBJECT_FORMATTER_SPDIF = (U32)(STAUD_CLASS_SPDIF_FORMATTER | STAUD_TYPE_DATA_FORMATTER),
        OBJECT_BLCKMGR         = (U32)(STAUD_CLASS_BLOCKMNG)
    };

    typedef enum STAUD_Object_e
    {

    /* These will be used to uniquely identify the chain components */

        STAUD_OBJECT_INPUT_CD0              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_0),
        STAUD_OBJECT_INPUT_CD1              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_1),
        STAUD_OBJECT_INPUT_CD2              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_2),
        STAUD_OBJECT_INPUT_CD3              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_3),
        STAUD_OBJECT_INPUT_CD4              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_4),
        STAUD_OBJECT_INPUT_CD5              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_5),
        STAUD_OBJECT_INPUT_CD6              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_6),
        STAUD_OBJECT_INPUT_CD7              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_7),
        STAUD_OBJECT_INPUT_CD8              = (U32) (OBJECT_INPUT_PARSER | STAUD_INSTANCE_8),

        STAUD_OBJECT_INPUT_PCM0             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_0),
        STAUD_OBJECT_INPUT_PCM1             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_1),
        STAUD_OBJECT_INPUT_PCM2             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_2),
        STAUD_OBJECT_INPUT_PCM3             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_3),
        STAUD_OBJECT_INPUT_PCM4             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_4),
        STAUD_OBJECT_INPUT_PCM5             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_5),
        STAUD_OBJECT_INPUT_PCM6             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_6),
        STAUD_OBJECT_INPUT_PCM7             = (U32) (OBJECT_INPUT_PCM    | STAUD_INSTANCE_7),

        STAUD_OBJECT_INPUT_PCMREADER0       = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_0),
        STAUD_OBJECT_INPUT_PCMREADER1       = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_1),
        STAUD_OBJECT_INPUT_PCMREADER2       = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_2),
        STAUD_OBJECT_INPUT_PCMREADER3       = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_3),
        STAUD_OBJECT_INPUT_PCMREADER4       = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_4),
        STAUD_OBJECT_INPUT_PCMREADER5      = (U32) (OBJECT_INPUT_READER |STAUD_INSTANCE_5),

        STAUD_OBJECT_DECODER_COMPRESSED0    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_0),
        STAUD_OBJECT_DECODER_COMPRESSED1    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_1),
        STAUD_OBJECT_DECODER_COMPRESSED2    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_2),
        STAUD_OBJECT_DECODER_COMPRESSED3    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_3),
        STAUD_OBJECT_DECODER_COMPRESSED4    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_4),
        STAUD_OBJECT_DECODER_COMPRESSED5    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_5),
        STAUD_OBJECT_DECODER_COMPRESSED6    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_6),
        STAUD_OBJECT_DECODER_COMPRESSED7    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_7),
        STAUD_OBJECT_DECODER_COMPRESSED8    = (U32) (OBJECT_DECODER | STAUD_INSTANCE_8),

        STAUD_OBJECT_ENCODER_COMPRESSED0    = (U32) (OBJECT_ENCODER | STAUD_INSTANCE_0),

        STAUD_OBJECT_MIXER0                 = (U32) (OBJECT_MIXER | STAUD_INSTANCE_0),
        STAUD_OBJECT_MIXER1                 = (U32) (OBJECT_MIXER | STAUD_INSTANCE_1),

        STAUD_OBJECT_POST_PROCESSOR0        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_0),
        STAUD_OBJECT_POST_PROCESSOR1        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_1),
        STAUD_OBJECT_POST_PROCESSOR2        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_2),
        STAUD_OBJECT_POST_PROCESSOR3        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_3),
        STAUD_OBJECT_POST_PROCESSOR4        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_4),
        STAUD_OBJECT_POST_PROCESSOR5        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_5),
        STAUD_OBJECT_POST_PROCESSOR6        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_6),
        STAUD_OBJECT_POST_PROCESSOR7        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_7),
        STAUD_OBJECT_POST_PROCESSOR8        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_8),
        STAUD_OBJECT_POST_PROCESSOR9        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_9),
        STAUD_OBJECT_POST_PROCESSOR10        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_10),
        STAUD_OBJECT_POST_PROCESSOR11        = (U32) (OBJECT_POSTPROC | STAUD_INSTANCE_11),

        STAUD_OBJECT_OUTPUT_PCMP0            = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_0),
        STAUD_OBJECT_OUTPUT_PCMP1            = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_1),
        STAUD_OBJECT_OUTPUT_PCMP2            = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_2),
        STAUD_OBJECT_OUTPUT_PCMP3            = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_3),
        STAUD_OBJECT_OUTPUT_PCMP4            = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_4),
        STAUD_OBJECT_OUTPUT_HDMI_PCMP0       = (U32) (OBJECT_OUTPUT_PCMP | STAUD_INSTANCE_5),
        STAUD_OBJECT_OUTPUT_SPDIF0           = (U32) (OBJECT_OUTPUT_SPDIF | STAUD_INSTANCE_0),
        STAUD_OBJECT_OUTPUT_HDMI_SPDIF0      = (U32) (OBJECT_OUTPUT_SPDIF | STAUD_INSTANCE_1),

       STAUD_OBJECT_SPDIF_FORMATTER_BYTE_SWAPPER  = (U32) (OBJECT_DATA_FORMATTER | STAUD_INSTANCE_0),
       STAUD_OBJECT_SPDIF_FORMATTER_BIT_CONVERTER = (U32) (OBJECT_DATA_FORMATTER | STAUD_INSTANCE_1),

       STAUD_OBJECT_FRAME_PROCESSOR               = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_2), //Same file as above so kept instance 2
       STAUD_OBJECT_FRAME_PROCESSOR1              = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_3), //Same file as above so kept instance 3
       STAUD_OBJECT_FRAME_PROCESSOR2              = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_4), //Same file as above so kept instance 4
       STAUD_OBJECT_FRAME_PROCESSOR3              = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_5), //Same file as above so kept instance 5

       STAUD_OBJECT_CKSUM_GENERATOR                 = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_6), //Same file as above so kept instance 6
       STAUD_OBJECT_CKSUM_GENERATOR1                = (U32) (OBJECT_DATA_DUMPER    | STAUD_INSTANCE_7), //Same file as above so kept instance 7

       STAUD_OBJECT_HDMI_DATAFORMATTER1             = (U32) (OBJECT_DATA_FORMATTER | STAUD_INSTANCE_8),
       STAUD_OBJECT_HDMI_DATAFORMATTER2             = (U32) (OBJECT_DATA_FORMATTER | STAUD_INSTANCE_9),
       STAUD_OBJECT_SPDIFTX_DATAFORMATTER           = (U32) (OBJECT_DATA_FORMATTER | STAUD_INSTANCE_10),

       STAUD_OBJECT_FORMATTER_SPDIF_DATA          = (U32) (OBJECT_FORMATTER_SPDIF | STAUD_INSTANCE_0),

       STAUD_OBJECT_BLCKMGR                       = (U32)(OBJECT_BLCKMGR | STAUD_INSTANCE_0)

    } STAUD_Object_t;



    typedef enum STAUD_PESParserMode_e
    {
        STAUD_PES_MODE_DISABLED,
        STAUD_PES_MODE_PES,
        STAUD_PES_MODE_ES_1,
        STAUD_PES_MODE_ES_2

    } STAUD_PESParserMode_t;

    typedef enum STAUD_SpeakerType_e
    {
        STAUD_SPEAKER_TYPE_SMALL = 1,
        STAUD_SPEAKER_TYPE_LARGE = 2

    } STAUD_SpeakerType_t;

    typedef enum STAUD_StereoMode_e
    {
        STAUD_STEREO_MODE_STEREO = 1,
        STAUD_STEREO_MODE_PROLOGIC = 2,
        STAUD_STEREO_MODE_DUAL_LEFT = 4,
        STAUD_STEREO_MODE_DUAL_RIGHT = 8,
        STAUD_STEREO_MODE_DUAL_MONO = 16,
        #if defined(ST_OS20)
            STAUD_STEREO_MODE_SECOND_STEREO = 32,
        #else
            STAUD_STEREO_MODE_AUTO = 32,
        #endif

        #if defined(ST_OS20)
            STAUD_STEREO_MODE_LR_MIX = 64,
        #else
            STAUD_STEREO_MODE_SECOND_STEREO = 64,
        #endif
       STAUD_STEREO_MODE_MONO   = 128

    }STAUD_StereoMode_t;

    typedef enum STAUD_Mp2EncStereoMode_e
    {
        MP2E_STEREO      = 0,
        MP2E_JOINTSTEREO = 1,
        MP2E_DUALMONO    = 2,
        MP2E_MONO        = 3
    }STAUD_Mp2EncStereoMode_t;

    typedef enum STAUD_Stop_e
    {
        STAUD_STOP_WHEN_END_OF_DATA = 1,
        STAUD_STOP_NOW = 2

    } STAUD_Stop_t;

    typedef enum STAUD_StreamContent_e
    {
        STAUD_STREAM_CONTENT_AC3        = (1 << 0),
        STAUD_STREAM_CONTENT_DTS        = (1 << 1),
        STAUD_STREAM_CONTENT_MPEG1      = (1 << 2),
        STAUD_STREAM_CONTENT_MPEG2      = (1 << 3),
        STAUD_STREAM_CONTENT_CDDA       = (1 << 4),
        STAUD_STREAM_CONTENT_PCM        = (1 << 5),
        STAUD_STREAM_CONTENT_LPCM       = (1 << 6),
        STAUD_STREAM_CONTENT_PINK_NOISE = (1 << 7),
        STAUD_STREAM_CONTENT_MP3        = (1 << 8),
        STAUD_STREAM_CONTENT_MLP        = (1 << 9),
        STAUD_STREAM_CONTENT_BEEP_TONE  = (1 << 10),
        STAUD_STREAM_CONTENT_MPEG_AAC   = (1 << 11),
        STAUD_STREAM_CONTENT_WMA        = (1 << 12),
        STAUD_STREAM_CONTENT_DV         = (1 << 13),
        STAUD_STREAM_CONTENT_CDDA_DTS   = (1 << 14),
        STAUD_STREAM_CONTENT_LPCM_DVDA  = (1 << 15),
        STAUD_STREAM_CONTENT_HE_AAC       = (1 << 16),
        STAUD_STREAM_CONTENT_DDPLUS       = (1 << 17),
        STAUD_STREAM_CONTENT_WMAPROLSL    = (1 << 18),
        STAUD_STREAM_CONTENT_ALSA         = (1 << 19),
        STAUD_STREAM_CONTENT_MP4_FILE = (1 << 20),
        STAUD_STREAM_CONTENT_ADIF     = (1 << 21),
        STAUD_STREAM_CONTENT_RAW_AAC  = (1 << 22),
        STAUD_STREAM_CONTENT_WAVE     =(1<<23),
        STAUD_STREAM_CONTENT_AIFF     =(1<<24),
        STAUD_STREAM_CONTENT_DRA      =(1<<25),
        STAUD_STREAM_CONTENT_RA      =(1<<26),
        STAUD_STREAM_CONTENT_VRBS      =(1<<27),
        STAUD_STREAM_CONTENT_FLAC      =(1<<28),
        STAUD_STREAM_CONTENT_DDPULSE   = (1<<29),
        STAUD_STREAM_CONTENT_NULL     = (1 << 30)
         // DO NOT EDIT BELOW THIS LINE
    } STAUD_StreamContent_t;

    typedef enum STAUD_StreamType_e
    {
        STAUD_STREAM_TYPE_ES            = (1 << 0),
        STAUD_STREAM_TYPE_PES           = (1 << 1),
        STAUD_STREAM_TYPE_PES_AD        = (1 << 2),
        STAUD_STREAM_TYPE_MPEG1_PACKET  = (1 << 3),
        STAUD_STREAM_TYPE_PES_DVD       = (1 << 4),
        STAUD_STREAM_TYPE_PES_DVD_AUDIO = (1 << 5),
        STAUD_STREAM_TYPE_SPDIF         = (1 << 6),
        STAUD_STREAM_TYPE_PES_ST        = (1 << 7),
        STAUD_STREAM_TYPE_ES_AD         = (1 << 8)

    }STAUD_StreamType_t;

    typedef enum STAUD_BroadcastProfile_e
    {
        STAUD_BROADCAST_DVB,
        STAUD_BROADCAST_DIRECTV,
        STAUD_BROADCAST_ATSC,
        STAUD_BROADCAST_DVD

    }STAUD_BroadcastProfile_t;

    typedef enum STAUD_Configuration_e
    {
        STAUD_CONFIG_DVD_COMPACT,
        STAUD_CONFIG_DVD_TYPICAL,
        STAUD_CONFIG_DVD_FULL,
        STAUD_CONFIG_DVB_COMPACT,
        STAUD_CONFIG_DVB_TYPICAL,
        STAUD_CONFIG_DVB_FULL,
        STAUD_CONFIG_DIRECTV_COMPACT,
        STAUD_CONFIG_DIRECTV_TYPICAL,
        STAUD_CONFIG_DIRECTV_FULL,
    /* ++NEW_DECODER_ARCHITECTURE */

    /*  STAUD_OBJECT_INPUT_CD3 +
        STAUD_OBJECT_DECODER_COMPRESSED2 +
        STAUD_OBJECT_OUTPUT_PCMP0||STAUD_OBJECT_OUTPUT_SPDIF2 */
        STAUD_CONFIG_STB_COMPACT

    /* --NEW_DECODER_ARCHITECTURE */

    } STAUD_Configuration_t;

    typedef enum STAUD_CopyRightMode_e
    {
        STAUD_COPYRIGHT_MODE_NO_RESTRICTION,
        STAUD_COPYRIGHT_MODE_ONE_COPY,
        STAUD_COPYRIGHT_MODE_NO_COPY

    } STAUD_CopyRightMode_t;

     typedef enum STAUD_DACDataAlignment_e
    {
            STAUD_DAC_DATA_ALIGNMENT_LEFT,
            STAUD_DAC_DATA_ALIGNMENT_RIGHT

    } STAUD_DACDataAlignment_t;



    typedef enum STAUD_DACDataFormat_e
    {
        STAUD_DAC_DATA_FORMAT_I2S,
        STAUD_DAC_DATA_FORMAT_STANDARD      // SONY format

    } STAUD_DACDataFormat_t;

    typedef enum STAUD_DACDataPrecision_e
    {
        #if defined (ST_5197)

            STAUD_DAC_DATA_PRECISION_24BITS,
            STAUD_DAC_DATA_PRECISION_20BITS,
            STAUD_DAC_DATA_PRECISION_18BITS,
            STAUD_DAC_DATA_PRECISION_16BITS
        #else
            STAUD_DAC_DATA_PRECISION_16BITS,
            STAUD_DAC_DATA_PRECISION_18BITS,
            STAUD_DAC_DATA_PRECISION_20BITS,
            STAUD_DAC_DATA_PRECISION_24BITS,
            STAUD_DAC_DATA_PRECISION_28BITS,
            STAUD_DAC_DATA_PRECISION_32BITS
        #endif
    }STAUD_DACDataPrecision_t;


    typedef enum STAUD_ADCDataPrecision_e
    {
        STAUD_ADC_DATA_PRECISION_24BITS,
        STAUD_ADC_DATA_PRECISION_20BITS,
        STAUD_ADC_DATA_PRECISION_18BITS,
        STAUD_ADC_DATA_PRECISION_16BITS
    }STAUD_ADCDataPrecision_t;

    typedef enum STAUD_DACNumBitsSubframe_e
    {
        STAUD_DAC_NBITS_SUBFRAME_32,
        STAUD_DAC_NBITS_SUBFRAME_16
    } STAUD_DACNumBitsSubframe_t;

    typedef enum STAUD_PCMReaderMemFmt_e
    {
        STAUD_PCMR_BITS_16_0,
        STAUD_PCMR_BITS_16_16
    }STAUD_PCMReaderMemFmt_t;

    typedef enum STAUD_PCMReaderRnd_e
    {
        STAUD_NO_ROUNDING_PCMR,
        STAUD_BIT16_ROUNDING_PCMR
    }STAUD_PCMReaderRnd_t;

     typedef enum STAUD_SPDIFDataPrecision_e
    {
        STAUD_SPDIF_DATA_PRECISION_24BITS,
        STAUD_SPDIF_DATA_PRECISION_23BITS,
        STAUD_SPDIF_DATA_PRECISION_22BITS,
        STAUD_SPDIF_DATA_PRECISION_21BITS,
        STAUD_SPDIF_DATA_PRECISION_20BITS,
        STAUD_SPDIF_DATA_PRECISION_19BITS,
        STAUD_SPDIF_DATA_PRECISION_18BITS,
        STAUD_SPDIF_DATA_PRECISION_17BITS,
        STAUD_SPDIF_DATA_PRECISION_16BITS

    }STAUD_SPDIFDataPrecision_t;

    typedef enum STAUD_SPDIFEmphasis_e
    {
        STAUD_SPDIF_EMPHASIS_NOT_INDICATED,
        STAUD_SPDIF_EMPHASIS_CD_TYPE
    }STAUD_SPDIFEmphasis_t;

    typedef enum STAUD_Device_e
    {
        STAUD_DEVICE_STI7100,
        STAUD_DEVICE_STI7109,
        STAUD_DEVICE_STI7111,
        STAUD_DEVICE_STI7141,
        STAUD_DEVICE_STI7200,
        STAUD_DEVICE_STI7105,
        STAUD_DEVICE_STI7106,
        STAUD_DEVICE_STI5206,
        STAUD_DEVICE_STI7108,
        STAUD_DEVICE_STIH205,
        STAUD_DEVICE_STI7510,
        STAUD_DEVICE_STI7540,
        STAUD_DEVICE_STI5525,
        STAUD_DEVICE_STI5197
    }STAUD_Device_t;

    typedef enum STAUD_Effect_e
    {
        STAUD_EFFECT_NONE = (1 << 0),
        STAUD_EFFECT_SRS_3D = (1 << 1),
        STAUD_EFFECT_TRUSURROUND = (1 << 2),
        STAUD_EFFECT_SRS_TRUBASS = (1 << 3),
        STAUD_EFFECT_SRS_FOCUS = (1 << 4),
        STAUD_EFFECT_SRS_TRUSUR_XT = (1 << 5),
        STAUD_EFFECT_SRS_BYPASS     =(1<<6)

    }STAUD_Effect_t;

    typedef enum STAUD_VolumeAlgo_e
    {
        STAUD_DLBY_VOLUME = (1 << 0),
        STAUD_SRS_VOLUME = (1 << 1),      //SRS VIQ
        STAUD_ST_VOLUME = (1 << 2)        // STIVC

    }STAUD_VolumeAlgo_t;
    typedef enum STAUD_EffectSRSParams_e
    {
        STAUD_EFFECT_FOCUS_ELEVATION = (1 << 0),
        STAUD_EFFECT_FOCUS_TWEETER_ELEVATION = (1 << 1),
        STAUD_EFFECT_TRUBASS_LEVEL = (1 << 2),
        STAUD_EFFECT_INPUT_GAIN = (1 << 3),
        STAUD_EFFECT_TSXT_HEADPHONE = (1 << 4),
        STAUD_EFFECT_TRUBASS_SIZE = (1 << 5),
        STAUD_EFFECT_TXST_MODE = (1 << 6)
    }STAUD_EffectSRSParams_t;

typedef enum STAUD_TruBass_Size_e
{
        /*For Tru Bass Size Following Values are support */
        /*Set the valus of TBsize as */
        SpeakerLFResponse40Hz=0,
        SpeakerLFResponse60Hz,
        SpeakerLFResponse100Hz,
        SpeakerLFResponse150Hz,
        SpeakerLFResponse200Hz,
        SpeakerLFResponse250Hz ,
        SpeakerLFResponse300Hz,
        SpeakerLFResponse400Hz,
        NumSpeakerTypes
} STAUD_TruBassSize_t;

typedef enum STAUD_CSiiOutPutMode_e
{
    ST_STEREO,
    ST_MULTICHANNEL
}STAUD_CSiiOutPutMode_t;

typedef enum STAUD_CSiiMode_e
{
    ST_CINEMA,
    ST_MUSIC,
    ST_MONO
}STAUD_CSiiMode_t;


    typedef enum BassMgtType
    {
        BASS_MGT_OFF=0,
        BASS_MGT_DOLBY_1,
        BASS_MGT_DOLBY_2,
        BASS_MGT_DOLBY_3,
        BASS_MGT_SIMPLIFIED,
        BASS_MGT_DOLBY_CERT,/*Bass 0*/
        BASS_MGT_Philips,
        BASS_MGT_DBB
        /*Do not edit below this line*/

    }STAUD_BassMgtType_t;


    typedef enum STAUD_Emphasis_e
    {
        STAUD_EMPHASIS_NONE,
        STAUD_EMPHASIS_FILTER1,
        STAUD_EMPHASIS_FILTER2

    }STAUD_Emphasis_t;

    typedef enum STAUD_MP2EncEmphasis_e
    {
        STAUD_NO_EMPHASIS,
        STAUD_EMPHASIS_50_15_US,
        STAUD_EMPHASIS_RESERVED,
        STAUD_EMPHASIS_CCITT,
        STAUD_EMPHASIS_PROCESSED_DISABLED = 4,
        STAUD_EMPHASIS_PROCESSED_50_15_US,
        STAUD_EMPHASIS_PROCESSED_RESERVED,
        STAUD_EMPHASIS_PROCESSED_CCITT
    }STAUD_MP2EncEmphasis_t;

    typedef enum STAUD_InputMode_e
    {
        STAUD_INPUT_MODE_DMA,
        STAUD_INPUT_MODE_I2S,
        STAUD_INPUT_MODE_I2S_DIRECT

    } STAUD_InputMode_t;

    typedef enum STAUD_InterfaceType_e
    {
        STAUD_INTERFACE_EMI,
        STAUD_INTERFACE_I2C

    }STAUD_InterfaceType_t;

    typedef enum STAUD_DigitalMode_e
    {
        STAUD_DIGITAL_MODE_OFF = 0,
        STAUD_DIGITAL_MODE_NONCOMPRESSED = 3,
        STAUD_DIGITAL_MODE_COMPRESSED = 4,
        STAUD_DIGITAL_MODE_COMPRESSED_ENC

    } STAUD_DigitalMode_t;

    typedef enum STAUD_Stereo_e
    {
        STAUD_STEREO_MONO = 1,
        STAUD_STEREO_STEREO = 2,
        STAUD_STEREO_PROLOGIC = 4,
        STAUD_STEREO_DUAL_LEFT = 8,
        STAUD_STEREO_DUAL_RIGHT = 16,
        STAUD_STEREO_DUAL_MONO = 32,
        STAUD_STEREO_SECOND_STEREO = 64,
        STAUD_STEREO_AUTO = 128

    }STAUD_Stereo_t;


    typedef enum STAUD_Fade_e
    {
        STAUD_FADE_SOFT_MUTE,
        STAUD_FADE_VOL,
        STAUD_FADE_NONE
    } STAUD_Fade_ID_t;


    typedef enum STAUD_CompMode_e
    {
        STAUD_CUSTOM_ANALOG,
        STAUD_CUSTOM_DIGITAL,
        STAUD_LINE_OUT,
        STAUD_RF_MODE,
        STAUD_DD_SUPRESS_MODE
    } STAUD_CompressionMode_t;

    typedef enum STAUD_TranscodeFormat_e
    {
        STAUD_TRANS_FMT_32hbe,/*!< 7FFE 0000 8001 0000 ...(SPDIF FMT Big Endian)   */
        STAUD_TRANS_FMT_32hle,/*!< 0000 FE7F 0000 0180 ...(SPDIF FMT Little Endian)*/
        STAUD_TRANS_FMT_16be, /*!< 7FFE 8001 ... (Big    Endian - Sun Style) DTS   */
        STAUD_TRANS_FMT_16le, /*!< FE7F 0180 ... (Little Endian 16 bit swap) AC3   */
    } STAUD_TranscodeFormat_t;

    typedef enum STAUD_DDREComprProfileType_e
    {
        STAUD_DDRE_COMPR_NO_COMPRESSION     = 0, /*!< no compression              */
        STAUD_DDRE_COMPR_FILM_STANDARD      = 1, /*!< film standard compression   */
        STAUD_DDRE_COMPR_FILM_LIGHT         = 2, /*!< film light compression      */
        STAUD_DDRE_COMPR_MUSIC_STANDARD     = 3, /*!< music standard compression  */
        STAUD_DDRE_COMPR_MUSIC_LIGHT        = 4, /*!< music light compression     */
        STAUD_DDRE_COMPR_SPEECH_COMPRESSION = 5  /*!< speech compression          */
    } STAUD_DDREComprProfileType_t;

    typedef enum STAUD_AudioCodingMode_e
    {
        STAUD_ACC_MODE20,   //0
        STAUD_ACC_MODE20_LFE, // 1
        STAUD_ACC_MODE30,  // 2
        STAUD_ACC_MODE30_LFE, // 3
        STAUD_ACC_MODE21,  // 4
        STAUD_ACC_MODE21_LFE,  //5
        STAUD_ACC_MODE31,  // 6
        STAUD_ACC_MODE31_LFE,  //7
        STAUD_ACC_MODE22,  //8
        STAUD_ACC_MODE22_LFE,  // 9
        STAUD_ACC_MODE32, //10
        STAUD_ACC_MODE32_LFE, //11
        STAUD_ACC_MODE23, //12
        STAUD_ACC_MODE23_LFE, //13
        STAUD_ACC_MODE33,  //14
        STAUD_ACC_MODE33_LFE, //15
        STAUD_ACC_MODE24, //16
        STAUD_ACC_MODE24_LFE, //17
        STAUD_ACC_MODE34,  //18
        STAUD_ACC_MODE34_LFE,  //19
        STAUD_ACC_MODE40,  //20
        STAUD_ACC_MODE40_LFE, //21
        STAUD_ACC_MODE50, //22
        STAUD_ACC_MODE50_LFE, //23
        STAUD_ACC_MODE41,  //24
        STAUD_ACC_MODE41_LFE, //25
        STAUD_ACC_MODE51, //26
        STAUD_ACC_MODE51_LFE, //27
        STAUD_ACC_MODE42, //28
        STAUD_ACC_MODE42_LFE, //29
        STAUD_ACC_MODE52, //30
        STAUD_ACC_MODE52_LFE, //31
        STAUD_ACC_MODE32_T100, //32
        STAUD_ACC_MODE32_T100_LFE, //33
        STAUD_ACC_MODE32_T010, //34
        STAUD_ACC_MODE32_T010_LFE, //35
        STAUD_ACC_MODE22_T200, //36
        STAUD_ACC_MODE22_T200_LFE, //37
        STAUD_ACC_MODE42_WIDE, //38
        STAUD_ACC_MODE42_WIDE_LFE, //39
        STAUD_ACC_MODE33_T010, //40
        STAUD_ACC_MODE33_T010_LFE, //41
        STAUD_ACC_MODE33_T100, //42
        STAUD_ACC_MODE33_T100_LFE, //43
        STAUD_ACC_MODE32_T110, //44
        STAUD_ACC_MODE32_T110_LFE, //45
        STAUD_ACC_MODE32_T200, //46
        STAUD_ACC_MODE32_T200_LFE, //47
        STAUD_ACC_MODE52_WIDE, //48
        STAUD_ACC_MODE52_WIDE_LFE, // 49
        /* following coding mode are not part of HDMI supported coding mode */
        STAUD_ACC_MODE20t, //50
        STAUD_ACC_MODE10, // 51
        STAUD_ACC_MODE44, // 52
        STAUD_ACC_MODE53, // 53
        STAUD_ACC_MODE11p20, //54
        STAUD_ACC_MODE10p20, //55
        STAUD_ACC_MODE20p20, // 56
        STAUD_ACC_MODE30p20, // 57
        STAUD_ACC_MODEk10_V1V2OFF, //58
        STAUD_ACC_MODEk10_V1ON, //59
        STAUD_ACC_MODEk10_V2ON, //60
        STAUD_ACC_MODEk10_V1V2ON, //61
        STAUD_ACC_MODEk_AWARE, //62
        STAUD_ACC_MODEk_AWARE10, //63
        STAUD_ACC_MODEk_AWARE20, //64
        STAUD_ACC_MODEk_AWARE30, //65
        STAUD_ACC_MODEk20_V1V2OFF, //66
        STAUD_ACC_MODEk20_V1ON, //67
        STAUD_ACC_MODEk20_V2ON, // 68
        STAUD_ACC_MODEk20_V1V2ON, //69
        STAUD_ACC_MODEk20_V1Left, //70
        STAUD_ACC_MODEk20_V2Right, //71
        STAUD_ACC_MODEk30_V1V2OFF, //72
        STAUD_ACC_MODEk30_V1ON,// 73
        STAUD_ACC_MODEk30_V2ON, //74
        STAUD_ACC_MODEk30_V1V2ON, //75
        STAUD_ACC_MODEk30_V1Left, //76
        STAUD_ACC_MODEk30_V2Right = 0x4D, //77
        STAUD_ACC_MODE20LPCMA = 0,
        STAUD_ACC_MODE_1p1 = 0x4E, //78
        STAUD_ACC_MODE20t_LFE, //79
        STAUD_ACC_MODE10_LFE, //80
        STAUD_ACC_MODE11p20_LFE, //81
        STAUD_ACC_MODE10p20_LFE, //82
        STAUD_ACC_MODE20p20_LFE, //83
        STAUD_ACC_MODE30p20_LFE, // 84
        STAUD_ACC_MODE44_LFE, //85
        STAUD_ACC_MODE53_LFE, //86
        STAUD_ACC_MODE_ALL, // 87
        STAUD_ACC_MODE_ALL1, //88
        STAUD_ACC_MODE_ALL2, //89
        STAUD_ACC_MODE_ALL3, //90
        STAUD_ACC_MODE_ALL4, //91
        STAUD_ACC_MODE_ALL5, //92
        STAUD_ACC_MODE_ALL6, // 93
        STAUD_ACC_MODE_ALL7, //94
        STAUD_ACC_MODE_ALL8, // 95
        STAUD_ACC_MODE_ALL9, //96
        STAUD_ACC_MODE_ALL10, //97
        STAUD_ACC_MODE_ID,             //no downmix  //98
    } STAUD_AudioCodingMode_t;

    /* This enum is maped from LX code */
    typedef enum STAUD_PLIIDecMode_e
    {
        STAUD_DECMODE_PROLOGIC = 0,      /* Pro Logic Emulation Mode*/
        STAUD_DECMODE_VIRTUAL,           /* Virtual Compatible Mode */
        STAUD_DECMODE_MUSIC,             /* Music Mode              */
        STAUD_DECMODE_MOVIE,             /* Movie/Standard Mode     */
        STAUD_DECMODE_MATRIX,            /* Matrix Mode             */
        STAUD_DECMODE_DOLBY_DIGITAL_EX,  /* Dolby Digital EX Mode   */
        STAUD_DECMODE_NOTUSED,           /* Not Used                */
        STAUD_DECMODE_CUSTOM,            /* Custom (override) Mode  */
        STAUD_DECMODE_RESERVED_1,        /* Reserved Mode #1        */
        STAUD_DECMODE_RESERVED_2,        /* Reserved Mode #2        */
        STAUD_DECMODE_RESERVED_3         /* Reserved Mode #3        */
    } STAUD_PLIIDecMode_t;

    typedef enum STAUD_PLIIOutMode_e
    {
        STAUD_PLII_MODE30 = 3,  /* 3/0 (3-stereo)       */
        STAUD_PLII_MODE22 = 6,  /* 2/2 (phantom center) */
        STAUD_PLII_MODE32 = 7,  /* 3/2                  */

        /* Derived from PLIIx reference code */
        STAUD_PLII_MODE33 = 9,  /* 3/3 (3/2 + center surround channel) */
        STAUD_PLII_MODE34 = 11,   /* 3/4 (3/2 + L/R back channels) */

       /* Extra Modes to support some of the other 5.1/7.1 ch configuration */
        STAUD_PLII_MODE21 = 4,  /* 2/1 (2/0 + center surround channel) */
        STAUD_PLII_MODE31 = 5,  /* 3/1 (3/0 + center surround channel) */
        STAUD_PLII_MODE23 = 8,  /* 2/3 (2/2 + center surround channel) */
        STAUD_PLII_MODE24 = 10   /* 2/4                                 */
    } STAUD_PLIIOutMode_t;

    typedef enum STAUD_PLIICentreWidth_e
    {
        STAUD_PLII_NO_CNTR_SPREAD_07,      /* 0 = No Spreading*/
        STAUD_PLII_MORE_CNTR_SPREAD_17,    /* 1 (Spreading increases with each step)*/
        STAUD_PLII_MORE_CNTR_SPREAD_27,    /* 2*/
        STAUD_PLII_MORE_CNTR_SPREAD_37,    /* 3*/
        STAUD_PLII_MORE_CNTR_SPREAD_47,    /* 4*/
        STAUD_PLII_MORE_CNTR_SPREAD_57,    /* 5*/
        STAUD_PLII_MORE_CNTR_SPREAD_67,    /* 6*/
        STAUD_PLII_FULLY_CNTR_SPREAD_77,   /* 7 = Full phantom (no C output)*/
    } STAUD_PLIICentreWidth_t;

    typedef enum STAUD_PLIIDimensionControl_e
    {
        STAUD_PLII_LR_FULL_FADE2SURROUNDS_0,  /* 0 = full fade to surrounds */
        STAUD_PLII_LR_FULL_FADE2SURROUNDS_1,  /* 1 */
        STAUD_PLII_LR_FULL_FADE2SURROUNDS_2,  /* 2 */
        STAUD_PLII_LR_FULL_FADE2SURROUNDS_3,  /* 3 */
        STAUD_PLII_LR_FULL_MOSTSURROUND_4,    /* 4 = most surround */
        STAUD_PLII_LR_FULL_MOSTSURROUND_5,    /* 5 */
        STAUD_PLII_LR_FULL_MOSTSURROUND_6,    /* 6 */
        STAUD_PLII_NEUTRAL_7,                 /* 7 = neutral (Lt' = Lt, Rt' = Rt) */
        STAUD_PLII_NEUTRAL_8,                 /* 8 */
        STAUD_PLII_NEUTRAL_9,                 /* 9 */
        STAUD_PLII_LR_MOST_CENTER_10,         /* 10 = most center */
        STAUD_PLII_LR_MOST_CENTER_11,         /* 11 */
        STAUD_PLII_LR_MOST_CENTER_12,         /* 12 */
        STAUD_PLII_LR_MOST_CENTER_13,         /* 13 */
        STAUD_PLII_LR_FULL_FADE2FRONT_14      /* 14 = full fade to front */
    } STAUD_PLIIDimensionControl_t;

    typedef enum STAUD_PLIIApply_e
    {
        STAUD_PLII_DISABLE=0,
        STAUD_PLII_ENABLE,
        STAUD_PLII_AUTO
    } STAUD_PLIIApply_t;

    typedef enum STAUD_AudioDataType_e
    {
        STAUD_NORMAL_AUDIO,
        STAUD_ONE_BIT_AUDIO,
        STAUD_DST_AUDIO,
        STAUD_HBR_AUDIO
    } STAUD_AudioDataType_t;
    typedef enum STAUD_SubChainID_e
    {
        STAUD_SUBCHAIN_0 = 0,
        STAUD_SUBCHAIN_1,
        STAUD_SUBCHAIN_2,
        STAUD_SUBCHAIN_3,
        STAUD_SUBCHAIN_MAX
    } STAUD_SubChainID_t;

    typedef enum STAUD_ModuleOPIndex_e
    {
        STAUD_MAIN_OUT = 0 << 28,
        STAUD_DIGITAL_OUT = 1 << 28,
        STAUD_AUX_OUT = 2 << 28,
        STAUD_HDMI_OUT = 3 << 28,
    }STAUD_ModuleOPIndex_t;

    /* Structures */

/*structure for Application for passing the SBAG configuration to Audio driver API */

typedef struct STAUD_PlayerModeConfig_s
{
    STAUD_DigitalMode_t OutputMode;
    STAUD_Object_t SourceObject;
    STAUD_ModuleOPIndex_t SourceModOutIndex;
}STAUD_OPModeConfig_t;

typedef struct STAUD_SBAGParam_s
{
   BOOL                 Enable;
   U32          ControlReg;
   U32          StartCode;
   U32          EndCode;
}STAUD_SBAGParam_t;

    typedef struct STAUD_Event_s
    {
        STAUD_Object_t  ObjectID;
        U8              EventData[32];
    } STAUD_Event_t;


    /* ++NEW_DECODER_ARCHITECTURE */

    /* Link list for containing all the constituents of a driver chain */
    typedef struct STAUD_DrvChainConstituent_s
    {
        /* Handle to this constituent */
        STAUD_Handle_t  Handle;

        /* Current constituents object type */
        STAUD_Object_t  Object_Instance;

        U32             ChainMask;
        /* Pointer to next contituent in chain */
        struct STAUD_DrvChainConstituent_s  *Next_p;
        /* Pointer to previous contituent in chain */
        struct STAUD_DrvChainConstituent_s  *Prev_p;

    } STAUD_DrvChainConstituent_t;
    /* --NEW_DECODER_ARCHITECTURE */

    /* Driver capability */
    typedef struct STAUD_IPCapability_s
    {
        BOOL PESParserCapable;
        BOOL I2SInputCapable;
        BOOL PCMBufferPlayback;

    } STAUD_IPCapability_t;

    typedef struct STAUD_DRCapability_s
    {
        BOOL DynamicRangeCapable;
        BOOL FadingCapable;
        BOOL TempoCapable;
        BOOL RunTimeSwitch;
        BOOL DeEmphasisCapable;
        BOOL PrologicDecodingCapable;
        BOOL AACMetadataCapable;
        BOOL DDRECapable;
#if defined(ST_5197)
        U16  MaxAttenuation;
#endif
        S32 SupportedTrickSpeeds[STAUD_MAX_TRICK_SPEEDS];
        STAUD_Stop_t SupportedStopModes;
        STAUD_StreamContent_t SupportedStreamContents;
        STAUD_StreamType_t  SupportedStreamTypes;
        STAUD_Effect_t SupportedEffects;
        STAUD_StereoMode_t SupportedStereoModes;
        STAUD_VolumeAlgo_t  STAUD_VolumeAlgo;

    } STAUD_DRCapability_t;

    typedef struct STAUD_ENCCapability_s
    {
        STAUD_StreamContent_t SupportedStreamContents;
        STAUD_StreamType_t  SupportedStreamTypes;

    } STAUD_ENCCapability_t;

    typedef struct STAUD_MXCapability_s
    {
        U8 NumberOfInputs;
        BOOL MixPerInputCapable;

    } STAUD_MXCapability_t;

    typedef struct STAUD_PPCapability_s
    {
        BOOL DownsamplingCapable;
        BOOL ChannelAttenuationCapable;
        BOOL DelayCapable;
        BOOL MultiChannelOutputCapable;
        U16 MaxAttenuation;
        U16 AttenuationPrecision;
        U16 MaxDelay;
        STAUD_Karaoke_t SupportedKaraokeModes;
        STAUD_SpeakerType_t SupportedSpeakerTypes;

    } STAUD_PPCapability_t;

    typedef struct STAUD_OPCapability_s
    {
        BOOL ChannelMuteCapable;
        S32 MaxSyncOffset;
        S32 MinSyncOffset;

    } STAUD_OPCapability_t;

    typedef struct STAUD_ReaderCapability_s
    {
        U16 NumChannels;
        BOOL I2SInputCapable;

    } STAUD_ReaderCapability_t;

#ifdef STAUD_DEBUG_STATISTICS
    typedef struct STAUD_Statistics_s
    {
        STAUD_Object_t PCMPObject[STAUD_INSTANCE_MAX];
        U32 NumberofFramesReceviedPCMP[STAUD_INSTANCE_MAX];
        U32 NumberOfFramesPlayedPCMP[STAUD_INSTANCE_MAX];
        U32 HugePTStoSTCdiffPCMP[STAUD_INSTANCE_MAX];
        U32 NumberofUnderflowPCMP[STAUD_INSTANCE_MAX];

        STAUD_Object_t SPDIFPObject[STAUD_INSTANCE_MAX];
        U32 NumberofFramesReceviedSPDIFP[STAUD_INSTANCE_MAX];
        U32 NumberOfFramesPlayedSPDIFP[STAUD_INSTANCE_MAX];
        U32 HugePTStoSTCdiffSPDIFP[STAUD_INSTANCE_MAX];
        U32 NumberofUnderflowSPDIFP[STAUD_INSTANCE_MAX];

        STAUD_Object_t DecoderObjectID[STAUD_INSTANCE_MAX];
        U32 NumberOfDecodedFrames[STAUD_INSTANCE_MAX];
        U32 NumberofErroredFrames[STAUD_INSTANCE_MAX];

        STAUD_Object_t ParserObjectID[STAUD_INSTANCE_MAX];
        U32 NumberOfParserFrames[STAUD_INSTANCE_MAX];
    }STAUD_Statistics_t;
#endif

    typedef struct STAUD_Capability_s
    {
        /* Module level Capabilities */
        STAUD_IPCapability_t IPCapability;
        STAUD_DRCapability_t DRCapability;
        STAUD_MXCapability_t MixerCapability;
        STAUD_PPCapability_t PostProcCapability;
        STAUD_OPCapability_t OPCapability;
        STAUD_ENCCapability_t ENCCapability;
        STAUD_ReaderCapability_t ReaderCapability;

        U8 NumberOfInputObjects;
        U8 NumberOfDecoderObjects;
        U8 NumberOfPostProcObjects;
        U8 NumberOfMixerObjects;
        U8 NumberOfOutputObjects;
        U8 NumberOfEncoderObjects;

        STAUD_Object_t InputObjects[STAUD_MAX_INPUT_OBJECTS];
        STAUD_Object_t DecoderObjects[STAUD_MAX_DECODER_OBJECTS];
        STAUD_Object_t PostProcObjects[STAUD_MAX_POST_PROC_OBJECTS];
        STAUD_Object_t MixerObjects[STAUD_MAX_MIXER_OBJECTS];
        STAUD_Object_t OutputObjects[STAUD_MAX_OUTPUT_OBJECTS];
        STAUD_Object_t EncoderObjects[STAUD_MAX_ENCODER_OBJECTS];

    } STAUD_Capability_t;

    typedef union STAUD_InterfaceParams_u
    {
        struct
        {
            void *BaseAddress_p;
            STAUD_WordWidth_t RegisterWordWidth;
        } EMIParams;
        struct
        {
            ST_DeviceName_t I2CDevice;
            U16 SlaveAddress;
        } I2CParams;

    } STAUD_InterfaceParams_t;

    typedef struct STAUD_Attenuation_s
    {
        U8 Left;
        U8 Right;
        U8 LeftSurround;
        U8 RightSurround;
        U8 Center;
        U8 Subwoofer;
        U8 CsLeft;
        U8 CsRight;
        U8 VcrLeft;
        U8 VcrRight;

    } STAUD_Attenuation_t;

    typedef struct STAUD_MixLevel_s
    {
        U16 Left;
        U16 Right;
        U16 LeftSurround;
        U16 RightSurround;
        U16 Center;
        U16 Subwoofer;
        U16 CsLeft;
        U16 CsRight;
    } STAUD_MixLevel_t;

    typedef struct STAUD_Delay_s
    {
        U8 Left;
        U8 Right;
        U8 LeftSurround;
        U8 RightSurround;
        U8 Center;
        U8 Subwoofer;
        U8 CsLeft;
        U8 CsRight;
        /*U8 VcrLeft;
        U8 VcrRight;*/

    } STAUD_Delay_t;

    typedef struct STAUD_DynamicRange_s
    {
        BOOL Enable;   //bit 0 : enable, bit 1 : cut/boost factor in %
        U8 InputID;    //For mixer object, InputID decide from which mixer input DRC coefficients are considered.
        U8 CutFactor;
        U8 BoostFactor;

    } STAUD_DynamicRange_t;

    typedef struct STAUD_DownmixParams_s
    {
        U16             Apply;
        BOOL                stereoUpmix;
        BOOL                monoUpmix;
        BOOL                meanSurround;
        BOOL                secondStereo;
        BOOL                normalize;
        U32             normalizeTableIndex;
        BOOL                dialogEnhance;
        STAUD_AudioCodingMode_t DownMixMode;
    }STAUD_DownmixParams_t;

    typedef struct STAUD_EvtParams_s
    {
        STAUD_Handle_t Handle;
        void *Data;

    } STAUD_EvtParams_t;

    typedef struct STAUD_Equalization_s
    {
        BOOL    enable;
        U8      equalizerBand_0;
        U8      equalizerBand_1;
        U8      equalizerBand_2;
        U8      equalizerBand_3;
        U8      equalizerBand_4;
        U8      equalizerBand_5;
        U8      equalizerBand_6;
        U8      equalizerBand_7;

    } STAUD_Equalization_t;


    typedef struct STAUD_Omni_s
    {
        U8      omniEnable;
        U8      omniInputMode;
        U8      omniSurroundMode;
        U8      omniDialogMode;
        U8      omniLfeMode;
        U8      omniDialogLevel;

    } STAUD_Omni_t;

typedef struct STAUD_CircleSurrondII_s
    {

        BOOL        Phantom;
        BOOL        CenterFB;
        BOOL        IS525Mode;
        BOOL        CenterRear;
        BOOL        RCenterFB;
        BOOL        TBSub;
        BOOL        TBFront;
        BOOL        FocusEnable;
        STAUD_TruBassSize_t TBSize;
        STAUD_CSiiOutPutMode_t OutMode;
        STAUD_CSiiMode_t        Mode;
        S16          InputGain;
        S16         TBLevel;
        S16         FocusElevation;

    } STAUD_CircleSurrondII_t;


    typedef struct STAUD_Fade_s
    {
        STAUD_Fade_ID_t FadeType;

    } STAUD_Fade_t;


    typedef struct STAUD_I2SParams_s
    {
        U32 I2SInputId;
        BOOL InvertWordClock;
        BOOL InvertBitClock;
        STAUD_DACDataFormat_t Format;
        STAUD_DACDataPrecision_t Precision;
        STAUD_DACDataAlignment_t Alignment;
        BOOL MSBFirst;

    } STAUD_I2SParams_t;

    typedef struct STAUD_PESParserParams_s
    {
        STAUD_PESParserMode_t Mode;
        U8 FilterStreamId;
        U8 FilterSubStreamId;
        U8 StreamId;
        U8 SubStreamId;

    } STAUD_PESParserParams_t;

    typedef struct STAUD_CDFIFOParams_s
    {
        STAUD_InputMode_t InputMode;
        STAUD_I2SParams_t I2SParams;
        STAUD_PESParserParams_t PESParserParams;

    } STAUD_CDFIFOParams_t;

    typedef struct STAUD_PCMDataConf_s
    {
        BOOL                        InvertWordClock;
        BOOL                        InvertBitClock;
        STAUD_DACDataFormat_t       Format;
        STAUD_DACDataPrecision_t    Precision;
        STAUD_DACDataAlignment_t    Alignment;
        BOOL                        MSBFirst;
        U32                         PcmPlayerFrequencyMultiplier;       // 384 Fs, 256 Fs etc...
        BOOL                        MemoryStorageFormat16;              // Data given to PCM player is in 16/16 format
    } STAUD_PCMDataConf_t;

    typedef struct STAUD_SPDIFOutParams_s
    {
        BOOL                        AutoLatency;
        U16                         Latency;
        STAUD_CopyRightMode_t       CopyPermitted;
        BOOL                        AutoCategoryCode;
        U8                          CategoryCode;
        BOOL                        AutoDTDI;
        U8                          DTDI;
        STAUD_SPDIFEmphasis_t       Emphasis;
        STAUD_SPDIFDataPrecision_t  SPDIFDataPrecisionPCMMode;          // SPDIF PCM mode data precision
        U32                         SPDIFPlayerFrequencyMultiplier;     // 128 Fs, 256 Fs etc...
    } STAUD_SPDIFOutParams_t;

    typedef struct STAUD_PCMReaderConf_s
    {
        BOOL                                MSBFirst; //MSB first/LSB first
        STAUD_DACDataAlignment_t    Alignment; //left aligned/right aligned wrt LR clock
        BOOL                                Padding;
        BOOL                                FallingSCLK; //sclk edge
        BOOL                                LeftLRHigh; //LR polarity
        #if defined(ST_7111) || defined(ST_7141) || defined(ST_7105) || defined(ST_5206) || defined(ST_7108) || defined(ST_H205) || defined(ST_FLI7510) || defined(ST_FLI7540)
        STAUD_ADCDataPrecision_t  Precision; //Data precision
        U8                      NumChannels;
        BOOL                    UnderFlowstatus;
        BOOL                    MasterClkEdge;
        U8                      DreqTriglimit ;
        BOOL                    RunStop;
        BOOL                    OverFlow;
        U32                     SampleCount;
        BOOL                    vsync;
        U8                      FifoSamplesAvailable;
        #else
            STAUD_DACDataPrecision_t  Precision; //Data precision
        #endif


        STAUD_DACNumBitsSubframe_t  BitsPerSubFrame; // 32/16 bits per subframe
        STAUD_PCMReaderRnd_t            Rounding; // Rounding
        STAUD_PCMReaderMemFmt_t     MemFormat; // 16_0/16_16
        U32                             Frequency; // Frequency of DAC

    } STAUD_PCMReaderConf_t;

    typedef struct STAUD_InitParams_s
    {
        STAUD_Device_t          DeviceType;
        STAUD_Configuration_t   Configuration;
        ST_Partition_t          *CPUPartition_p;
        U32                     InterruptNumber;
        U32                     InterruptLevel;
        ST_DeviceName_t         RegistrantDeviceName;
        U32                     MaxOpen;
        ST_DeviceName_t         EvtHandlerName;
        STAVMEM_PartitionHandle_t AVMEMPartition;
        STAVMEM_PartitionHandle_t BufferPartition;
        BOOL                    AllocateFromEMBX;
        ST_DeviceName_t         ClockRecoveryName;
        U32                     DACClockToFsRatio;
        STAUD_PCMDataConf_t     PCMOutParams;
        STAUD_SPDIFOutParams_t  SPDIFOutParams;
        STAUD_DigitalMode_t     SPDIFMode;
        STAUD_PCMMode_t         PCMMode;
        STAUD_PCMReaderConf_t   PCMReaderMode;
        U8                      DriverIndex;
        U8                      NumChannels;
        U8                      NumChPCMReader;
        BOOL                    EnableMSPPSupport;
    } STAUD_InitParams_t;


    typedef struct STAUD_DataInterfaceParams_s
    {
        void *Destination;
        U8 Holdoff;
        U8 WriteLength;

    } STAUD_DataInterfaceParams_t;

    typedef struct STAUD_PCMBufParams_s
    {
        U8 SlotSize;
        U8 DataPrecision;
        BOOL InvertWordClock;
        BOOL ByteSwapData;
        BOOL UnsignedData;
        BOOL MonoData;
        BOOL MSBFirst;
        U32 Reserved; /*Kept for backwards compatibility  */
    } STAUD_PCMBufParams_t;

    typedef struct STAUD_PCMInputParams_s
    {
        U32 Frequency;
        U32 DataPrecision;
        U8  NumChannels;
    } STAUD_PCMInputParams_t;

    typedef union STAUD_InputParams_u
    {
        STAUD_CDFIFOParams_t CDFIFOParams;
        STAUD_PCMBufParams_t PCMBufParams;

    } STAUD_InputParams_t;

    typedef struct STAUD_MixerInputParams_s
    {
        U8 MixLevel;

    } STAUD_MixerInputParams_t;

    typedef struct STAUD_OpenParams_s
    {
        U32 SyncDelay;

    } STAUD_OpenParams_t;


    typedef union STAUD_OutputParams_u
    {
        STAUD_PCMDataConf_t PCMOutParams;
        STAUD_SPDIFOutParams_t SPDIFOutParams;

    } STAUD_OutputParams_t;

    typedef struct STAUD_PCMBuffer_s
    {
        U32 Block;
        U32 StartOffset;
        U32 Length;
        STAUD_Object_t InputPCMObject;

    } STAUD_PCMBuffer_t;

    typedef struct STAUD_GetBufferParam_s
    {
        void* StartBase;
        U32 Length;

    } STAUD_GetBufferParam_t;

    typedef struct STAUD_PTS_s
    {
        U32 Low;
        U32 High;
        BOOL Interpolated;
        U32 PTS_EvtNotificationTime;
    } STAUD_PTS_t;

    typedef struct STAUD_SpeakerEnable_s
    {
        BOOL Left;
        BOOL Right;
        BOOL LeftSurround;
        BOOL RightSurround;
        BOOL Center;
        BOOL Subwoofer;
        BOOL CsLeft;
        BOOL CsRight;
        BOOL VcrLeft;
        BOOL VcrRight;

    } STAUD_SpeakerEnable_t;

    typedef struct STAUD_SpeakerConfiguration_s
    {
        STAUD_SpeakerType_t Front;
        STAUD_SpeakerType_t Center;
        STAUD_SpeakerType_t LeftSurround;
        STAUD_SpeakerType_t RightSurround;
        STAUD_SpeakerType_t CsLeft;
        STAUD_SpeakerType_t CsRight;
        STAUD_SpeakerType_t VcrLeft;
        STAUD_SpeakerType_t  VcrRight;
        BOOL                LFEPresent;

    } STAUD_SpeakerConfiguration_t;


    typedef enum STAUD_MPEGLayer_e
    {
        STAUD_MPEG_LAYER_I = 1,
        STAUD_MPEG_LAYER_II,
        STAUD_MPEG_LAYER_III,
        STAUD_MPEG_LAYER_NONE

    }
    STAUD_MPEG_Layer_t;

    typedef struct STAUD_PlayerParams_s
    {
       U8  NumberOfChannel;
       U8  OPDivider;
       U32 IPFrequency;
       U8  IsAudioCompressed;
       U8  HDMIEnable;
       U8  ReqI2SOn; // lsb first four bit will represent req i2s2spdif on
       STAUD_AudioDataType_t AudioType;
    }STAUD_PlayerParams_t;

    typedef struct STAUD_MarkerData_s
    {
        ST_MM_Bitstream_Marker_t  Marker;
        STAUD_PTS_t PTS;
        U32 MarkerID0;
        U32 MarkerID1;
    }STAUD_MarkerData_t;

    typedef struct STAUD_StreamInfo_s
    {
        STAUD_StreamContent_t   StreamContent;
//      STAUD_StereoMode_t      AudioMode;
        U32                     BitRate;
        U32                     SamplingFrequency;
        STAUD_MPEG_Layer_t      LayerNumber;
        BOOL                    Emphasis;
        BOOL                    CopyRight;
        U8                      Mode;
        U8                      Bit_Rate_Code;
        U8                      Bit_Stream_Mode;
        U8                      Audio_Coding_Mode;
        U32                     FrameSize;
        ST_AudioInfoFrame_t  AudioInfoFrame;
    } STAUD_StreamInfo_t;



    typedef struct STAUD_StreamParams_s
    {
        STAUD_StreamContent_t StreamContent;
        STAUD_StreamType_t StreamType;
        U32 SamplingFrequency;
        U8 StreamID;

    } STAUD_StreamParams_t;

    typedef struct STAUD_SynchroUnit_s
    {
        U32 SkipPrecision;
        U32 PausePrecision;

    } STAUD_SynchroUnit_t;

    typedef struct STAUD_TermParams_s
    {
        BOOL ForceTerminate;

    } STAUD_TermParams_t;

    typedef struct STAUD_DigitalOutputConfiguration_s
    {
        STAUD_DigitalMode_t DigitalMode;
        STAUD_CopyRightMode_t Copyright;
        U32 Latency;

    } STAUD_DigitalOutputConfiguration_t;


    typedef struct STAUD_Prepare_s
    {
        STAUD_StreamContent_t StreamContent;
        STAUD_StreamType_t StreamType;
        U32 SamplingFrequency;

    } STAUD_Prepare_t;

    typedef struct STAUD_Speaker_s
    {
        BOOL Front;
        BOOL LeftSurround;
        BOOL RightSurround;
        BOOL Center;
        BOOL Subwoofer;
        BOOL CsLeft;
        BOOL CsRight;
        BOOL VcrLeft;
        BOOL VcrRight;

    } STAUD_Speaker_t;

    typedef struct STAUD_StartParams_s
    {
        STAUD_StreamContent_t StreamContent;
        STAUD_StreamType_t StreamType;
        U32 SamplingFrequency;
        U8 StreamID;

    } STAUD_StartParams_t;

    typedef struct {
        U32             ValidMeta        : 1;       /* 1bit:  Valdity of the Dolby Style metadata obtained from ACC decoder */
        U32             CMixLev          : 2;       /* 2bit:  Center Mix value index                                        */
        U32             SurMixLev        : 2;       /* 2bit:  Surround Mix Value index                                      */
        U32             DSurMod          : 2;       /* 2bit:  Dolby Surround Mode                                           */
        U32             ComprFlag        : 1;       /* 1bit:  Compression Flag                                              */
        U32             DialNorm0        : 5;       /* 5bit:  Dialog Normalization for left or all Chan                     */
        U32             DialNorm1        : 5;       /* 5bit:  Dialog Normalization for right chan in 1+1 mode               */
        U32             DynRangFlag      : 1;       /* 1bit:  Dyanmic Range Flag                                            */
        U32             Reserved1        : 13;      /* 13bit: Reserved - Must be 0                                          */
        U8              Compr0;                     /* 8bit:  Compression value for left or all chan                        */
        U8              Compr1;                     /* 8bit:  Compression Value for right chan in 1+1 mode                  */
        U8              DRC[2][6];
    } STAUD_BavariaMetadataDesc_t;

    typedef struct STAUD_ENCOutputParams_s
    {
        BOOL   AutoOutputParam;
        U32     BitRate;
        U32     OutputFrequency;

        union
        {
            struct
            {
                BOOL CompOn;
                BOOL CompOnSec;
                BOOL TestMode;
                U8     Ac3Mode;
                BOOL LfeActivate;
                BOOL LfeLpActivate;
                U32   SurDelayActivate : 1; /* 1bit: to activate surround delay */
                U32   BavariaOn        : 2; /* 2bit: to activate BavariaOn      */
                U32   Reserved         : 29;/* 29bit: Reserved - Must be 0      */
                STAUD_BavariaMetadataDesc_t Metadata;
            }DDConfig;

            struct
            {
                U32     bandWidth;      /* BandWidth */
                BOOL    Intensity;  /* Intensity Stereo */
                BOOL    VbrMode;        /* VBR Mode */
                U32     VbrQuality;     /* VBR Quality */
                BOOL    FullHuffman;
                BOOL    paddingMode;
                BOOL    Crc;
                BOOL    privateBit;
                BOOL    copyRightBit;
                BOOL    originalCopyBit;
                BOOL    EmphasisFlag;
                BOOL    downmix;
            }MP3Config;

            struct
            {
                STAUD_Mp2EncStereoMode_t    Mode;
                BOOL                        CrcOn;
                STAUD_MP2EncEmphasis_t      Emphasis;
                BOOL                        Copyrighted;
                BOOL                        Original;
            }MP2Config;

            struct
            {
                unsigned long quantqual;
                int VbrOn;
            }AacConfig;

        }EncoderStreamSpecificParams;

    } STAUD_ENCOutputParams_s;

    /* This structure is used for advanced PLII settings (example for certifications) */
    typedef struct STAUD_PLIIParams_s
    {
        STAUD_PLIIApply_t   Apply;
        STAUD_PLIIDecMode_t DecMode;
        S8                  DimensionControl; /* Valid range -3 to +3 */
        U8                  CentreWidth;       /* Valid range 0 to 7 */
        BOOL                Panaroma;
        BOOL                ChannelPolarity;
        BOOL                SurroundFilter;
        STAUD_PLIIOutMode_t OutMode;
        BOOL                AutoBalance;
        BOOL                InvMatrixEnable;
        S16                 PcmScale;
    } STAUD_PLIIParams_t;

    typedef struct STAUD_DRInitParams_s
    {
        BOOL SBRFlag;

    } STAUD_DRInitParams_t;

/*This is added for DTS Neo Params
    typedef enum STAUD_DTSNeoBW_e
    {
        STAUD_DTSNEOBW_16BITS,
        STAUD_DTSNEOBW_24BITS
    }STAUD_DTSNeoBW_t;
*/
    typedef enum STAUD_DTSNeoMode_e
    {
        STAUD_DTSNEOMODE_CINEMA=1,
        STAUD_DTSNEOMODE_MUSIC,
        STAUD_DTSNEOMODE_WIDE
    }STAUD_DTSNeoMode_t;

    typedef enum STAUD_DTSNeoAUXMode_e
    {
        STAUD_DTSNEOMODE_BACK,
        STAUD_DTSNEOMODE_SIDE
    }STAUD_DTSNeoAUXMode_t;

    typedef struct STAUD_DTSNeo_s
    {
        BOOL Enable;
/*      STAUD_DTSNeoBW_t NeoBW;  Neo Bit Width is not required */
        U8                  CenterGain;
        STAUD_DTSNeoMode_t  NeoMode;
        STAUD_DTSNeoAUXMode_t  NeoAUXMode;
        U8              OutputChanels;

    }STAUD_DTSNeo_t;

    typedef struct STAUD_BTSC_s
    {
        BOOL    Enable;
        S16     InputGain;
        S16     TXGain;
        BOOL      DualSignal;
    } STAUD_BTSC_t;


    typedef enum STAUD_SRSVolIQMode_e
   {
       STAUD_VIQ_NORMALIZER_ENABLE,
       STAUD_VIQ_GAINS_IN_DB,
       STAUD_VIQ_GAINS_IN_MB,
           STAUD_VIQ_MODE_BIT0,
           STAUD_VIQ_MODE_BIT1,
       STAUD_VIQ_LOG_GAIN
   } STAUD_SRSVolIQMode_t;

   typedef enum STAUD_SRSVolIQSpkSize_e
   {
       STAUD_KSRS_FULLRANGE,
       STAUD_KSRS_40HZ,
       STAUD_KSRS_110HZ,
       STAUD_KSRS_200HZ,
       STAUD_KSRS_315HZ,
       STAUD_KSRS_410HZ
   } STAUD_SRSVolIQSpkSize_t;

    typedef enum
    {
        STAUD_HEADROOM_MODE_NEGATIVE,
        STAUD_HEADROOM_MODE_0,
        STAUD_HEADROOM_MODE_1,
        STAUD_HEADROOM_MODE_2,
        STAUD_HEADROOM_MODE_3,
    }STAUD_PPHeadRoomMode_t;

    typedef struct STAUD_SRSVIQ_s
    {
        BOOL                                      Enable;
        U32                                        InputGain;
        U32                                        OutputGain;
        U32                                        BypassGain;
        BOOL                                      BypassEnable;
        U32                                        VolIQRefLevel;
        STAUD_SRSVolIQMode_t          SRSVolIQMode;
        STAUD_SRSVolIQSpkSize_t      SRSVolIQSpkSize;
        BOOL                                      NoiseManagerEnable;
        U32                                        NoiseThreshold;
        U32                                        VolIQMaxGain;
    } STAUD_SRSVIQ_t;
    /* Kindly Refer to 7200 DataSheet to understand the scenarios */


    typedef struct STAUD_DolbyVolume_s
    {
        BOOL                                        Enable;
        BOOL                                        DV_Enable_Volume_Modler;     // DEF: ENABLED
        BOOL                                        DV_Enable_Volume_Limiter;    // DEF: ENABLED
        BOOL                                        DV_Enable_Volume_Leveler;    // DEF: ENABLED
        BOOL                                        DV_Enable_Hmode_Modler;      // HALF MODE -> DEF: DISABLED
        BOOL                                        DV_Enable_Msp;               // MIDSIDE PROCESSING -> DEF: DISABLED
        U8                                          DV_Volume_Level_Amount;      // 0 to 10 -> DEF: 0
        U8                                          DV_Input_Ref_Level;          // 0 to 100 dB SPL -> DEF: 85 dB SPL
        U8                                          DV_Pregain;                  // -30 to 30 dB SPL -> DEF: 0
        U8                                          DV_Output_Ref_Level;         // 0 to 100 dB SPL -> DEF: 85 dB SPL
        U8                                          DV_Calibration_Offset;       // -100 to 30 dB   -> DEF: 0 dB
        U8                                          DV_Digital_Ref_Level;        // -100 to 30 dB   -> DEF: 0 dB
        U8                                          DV_Analog_Ref_Level;         // -100 to 30 dB   -> DEF: 0 dB
        U8                                          DV_Nbands;                   // DEF: 0
        U8                                          DV_Dummy_Pad2;               // DEF: 0
    } STAUD_DolbyVolume_t;

        typedef struct  STAUD_DTSNeural_s
        {
                U8  Apply;            //!< Disable/Enable/Auto DTS Neural processing

                //=============== ( Values Common to 227 amd 527) ===============
                U8  Latency;          //!< Latency mode; Low Latency, High Latency
                U8  LFECutoff;        //!< LFE cutoff frequency, e.g. 60Hz, 80Hz, 0 = Mute

                // Following field is interpreted as Depth for 227 mode and SurroundDepth for 527 mode
                U8  Depth;            //!< Front     -> 0x28, Default -> 0x14, Rear  -> 0x00
                              //!< Surrounds -> 0x28, Default -> 0x14, Backs -> 0x00

        //=============== ( Values Specific to 227 only) ===============
                U8 Mode;              //!< Mode of Neural; Standard, DICE
                U8 DICEProcessLevel;  //!< Level of DICE enhancement to perform;
                              //!< Minimum -> 0, Default -> 0x0A, Maximum -> 0x14
                U8 FrontWidth;        //!< L/R -> 0x28, Default -> 0x14, C = 0x00
                U8 SurroundWidth;     //!< Wide -> 0x14, Default = 0x14, Narrow -> 0x00
                U8 LimiterEnable;     //Enable/Disable FinalLimiterCeling.

        } STAUD_DTSNeural_t;

    typedef struct STAUD_ApplyMetadata_s
    {
        U8  PCMMetadata;
        U8  MixerMetaData;
        U8  EncMetadata;
        U8  InputID;
    }STAUD_ApplyMetadata_t;

   typedef struct STAUD_LPCMOPSetting_s
   {
        U32  TargetRefLevel   : 5;
        U32  Reserve          :24;
    }STAUD_LPCMOPSetting_t;

    typedef enum
    {
        HE_AAC_MODE  = 1 ,
        DPulse_MS10_MODE,
        DPulse_MS11_Single_Decode_MODE,
        DPulse_MS11_Dual_Decode_MODE
    }STAUD_HEAAC_DPULSE;

    typedef enum
    {
        STAUD_AAC_ADTS_FORMAT,
        STAUD_AAC_ADIF_FORMAT,
        STAUD_AAC_MP4_FILE_FORMAT,
        STAUD_AAC_LOAS_FORMAT,
        STAUD_AAC_RAW_FORMAT,
        STAUD_AAC_BSAC_RAW_FORMAT,
        STAUD_AAC_AUTO_TYPE=7
    }STAUD_AAC_FORMATTYPE;


    typedef struct STAUD_AACOPSetting_s
    {
        U32  TargetRefLevel   : 5;
        U32  DPulseType       : 3;
        U32  EnableARIB       : 1;
        U32  Mono2Stereo      : 1;  // Force fully copy mono data to L,R : need for certification
        U32  ForceFormat      : 1;  // Force the Format type... otherwise auto-detect.
        U32  FormatType       : 3;  // AAC encapsulation format (ADTS,LOAS,ADIF, MP4, Raw)
        U32  Reserve          :18;
    }STAUD_AACOPSetting_t;

    typedef struct STAUD_DDPOPSetting_s
    {
        U32  UpSampling         : 2;
        U32  DitherAlgo         : 1;
        U32  Enable71DMix       : 1;
        U32  EnableLfeDMix      : 1;
        U32  Enable71Decoder    : 1;
        U32  ReportFrameInfo    : 1;
        U32  Reserve            :25;
    }STAUD_DDPOPSetting_t;

    typedef struct STAUD_DTSOPSetting_s
    {
        U32  DTS96KEnable       : 1;
        U32  DTSESEnable        : 1;
        U32  DTSMixLfe          : 1;
        U32  DTSLBREnable       : 1;
        U32  SampleFreq         : 8;
        U32  EnableNavFadeIn    : 1;
        U32  Reserve            :19;
    }STAUD_DTSOPSetting_t;

    typedef struct STAUD_Mp2OPSetting_s
    {
        U32  mp3DSurroundMode : 2;
        U32 Reserved          :30;
    }STAUD_Mp2OPSetting_t;

    typedef union STAUD_OPConfigParams_u
    {
        STAUD_DTSOPSetting_t    DTS;
        STAUD_DDPOPSetting_t    DDP;
        STAUD_AACOPSetting_t    AAC;
        STAUD_LPCMOPSetting_t   LPCM;
        U32                     u32;
    }STAUD_OPConfigParams_t;

    typedef enum STAUD_MP3SurroundMode_e
    {
       STAUD_MP3Surround_Disable=0,
       STAUD_MP3Surround_Mode1,
       STAUD_MP3Surround_Mode2,
    }STAUD_MP3SurroundMode_t;

    typedef struct STAUD_WOWHD_s
    {
        BOOL                       WOWHDEnable;
        BOOL                       WOWHDBypass;
        BOOL                       Speaker_Headphone;
        U32                        InputGain;
        U32                        OutputGain;
        U32                        DefinitionControl;
        BOOL                       EnableSRS;
        U32                        SRSMode;
        U32                        srsSpaceControl;
        U32                        srsCenterControl;
        BOOL                       HBREnable;
        U32                        TruBassControl;
        STAUD_TruBassSize_t        TruBassSpeakerSize;
        U32                        FocusControl;
        BOOL                       EnableLimiter;
        U32                        LimiterControl;
    } STAUD_PPSRSWOWHDConfigParam_t;



    typedef struct STAUD_HeadRoom_s
    {
        BOOL                      ControlEnable;
        STAUD_PPHeadRoomMode_t    HeadRoomMode;
        S8                        UserGain;
    } STAUD_PPHeadRoomConfigParams_t;

    typedef struct STAUD_GPEQ_s
    {
        BOOL    Enable;
        int         m_iNumBands;                      // Max 15 bands supported.
        int         m_piCutoffFreq[MAXNUMBEROFBANDS];    //filter cutoff frequancies
        double      m_pdQFactor[MAXNUMBEROFBANDS];       // Quality factor for each band (0.1 - 32.0)
        double      m_pdGainDB[MAXNUMBEROFBANDS];      // slider gains
        int     m_iEnableShelvingFilter;
    //    double    m_dMaxSliderGainDB;   // max slider gain  .. need to discuss.

    } STAUD_PPGPEQConfigParam_t;


    typedef struct STAUD_DBB_s
    {
        BOOL                                  DBBIsBypassed;
        BOOL                                  UseSubWoofer;
        U16                                   BoostBandHpCutoffFreq;
        U16                                   SubWooferCutoffFreq;
        S16                                   SubWooferGain;
        S16                                   NonLinearGain;
        U16                                   DBBGain;
        U8                                    HRMContent;
        STAUD_PPHeadRoomMode_t                HeadRoomMode;
    } STAUD_PPDBBConfigParam_t;


    typedef struct STAUD_SpdifOut_s
    {
        BOOL                                  Apply;
    } STAUD_PPSpdifOutConfigParam_t;


    typedef struct STAUD_STHeadPhone_s
    {
        BOOL                                  STHeadPhoneIsBypassed;
        BOOL                                  EnableDownmix;
        BOOL                                  EnableReverb;

/*config parameters here*/
    } STAUD_PPSTHeadPhoneConfigParam_t;
        typedef struct STAUD_BBE_s
    {
        BOOL BBEenable;
     BOOL BBEmode;
        float BBEContourLevel;
        float BBEProcessBoost;
        float BBE3DGain;
    } STAUD_PPBBEConfigParam_t;

    typedef U8* STAUD_PPFAOParams_t; // Not visisble to upper layers

    typedef struct
      {
        BOOL  SpeakerCompisBypassed;
        U8 SpeakerCompType;
        union
         {
          STAUD_PPFAOParams_t FAOParams;
          void* CustomerSpecificParaEq;
         }CompParams;
      } STAUD_PPSpeakerCompParams_t;


        typedef struct STAUD_Omni2_s
    {
        BOOL Omni2Enable;
          BOOL Omni2InputMode;
        BOOL Omni2CenterMode;
    } STAUD_PPOmni2_t;

    typedef struct STAUD_STSpeechEnh_s
    {
      BOOL  SpeechEnhIsBypassed;
    } STAUD_PPSpeechEnhConfigParams_t;


    #define STIVC_MAX_BANDS  5

    typedef enum STAUD_STIVCMode_e
    {
       STAUD_STIVC_BYPASS,
       STAUD_STIVC_MDRC,
       STAUD_STIVC_LOUDNESS,
       STAUD_STIVC_MDRC_LOUDNESS,
       STAUD_STIVC_LIMITER,
       STAUD_STIVC_MDRC_LIMITER,
       STAUD_STIVC_LOUDNESS_LIMITER,
       STAUD_STIVC_MDRC_LOUDNESS_LIMITER,
    }STAUD_PPSTIVCMode_t;

    typedef struct STAUD_STIVCBandParams_s
      {
        S32  FreCutOff;
        S32  PostGain;
        S32  ComThresh;
        S32   ComSlope;
        S32  NgThresh;
        S32  NgSlope;
        S32  AttackTime;
        S32  ReleaseTime;
    } STAUD_PPSTIVCBandParams_t;

    typedef struct STAUD_STIVCLounessParams_s
    {
        U16 SmoothTime;
        S16 RefLevel;
        U16 MaxGain;
        U16 Strength;
    } STAUD_PPSTIVCLoudnessParams_t;

    typedef struct STAUD_STIVCLimiterParams_s
    {
        BOOL RmsMeasure;
        S16  Threshold;
    } STAUD_PPSTIVCLimiterParams_t;


    typedef struct STAUD_PPSTIVC_Config_s
    {
      STAUD_PPSTIVCMode_t             Mode;
      STAUD_PPSTIVCMode_t             UpdateMode;
      U8                              NumBands;
      STAUD_PPSTIVCBandParams_t       BandCompressors[STIVC_MAX_BANDS];
      STAUD_PPSTIVCLoudnessParams_t   Loudness_p;
      STAUD_PPSTIVCLimiterParams_t    Limiter_p;
    } STAUD_PPSTIVCConfigParams_t;


    typedef enum
    {
      STAUD_DRC_PASS_THROUGH,
      STAUD_ST_IVC,
      STAUD_SRS_VOLUME_IQ,
      STAUD_DOLBY_VOLUME,
    }STAUD_PPDynamicRangeControlType_t;


    typedef struct STAUD_PPDRCConfig_s
    {
      STAUD_PPDynamicRangeControlType_t DRCType;
      union
      {
        STAUD_PPSTIVCConfigParams_t         STIVCParams;
        STAUD_DolbyVolume_t                 DlbyVolParams;
        STAUD_SRSVIQ_t                      SRSVIQParams;
      } AlgoUsed;
    } STAUD_PPDRCConfigParams_t;

    /* Kindly Refer to 7200 DataSheet to understand the scenarios */
    typedef enum STAUD_Scenario_e
    {
        STAUD_SET_SENARIO_0 = 0,
        STAUD_SET_SENARIO_1 ,
        STAUD_SET_SENARIO_2
    }STAUD_Scenario_t;
#if 0
enum eSTAUD_PCMFormat
{
        PCM_8BIT        = 8,
        PCM_16BIT       = 16,
        PCM_20BIT       = 20,
        PCM_24BIT       = 24,
        PCM_16BIT_LE    = 65536,
        PCM_16BIT_U     = 131072,
        PCM_16BIT_ULE   = 196608,
        PCM_8BIT_U      = 17,
        PCM_32BIT       =   32,
        PCM_32BIT_BE    =  33

};
#endif
    typedef enum eSTAUD_PCMFormat
    {
        STAUD_PCM_8BIT      = 8,
        STAUD_PCM_16BIT     = 16,
        STAUD_PCM_20BIT     = 20,
        STAUD_PCM_24BIT     = 24,
        STAUD_PCM_16BIT_LE  = 65536,
        STAUD_PCM_16BIT_U   = 131072,
        STAUD_PCM_16BIT_ULE = 196608,
        STAUD_PCM_8BIT_U    = 17,
        STAUD_PCM_32BIT     = 32,
        STAUD_PCM_32BIT_BE  = 33,
        STAUD_PCM_WS8A		= 34,
        STAUD_PCM_WS8Mu		= 35
    }STAUD_PCMFormat_t;

    typedef struct STAUD_PESBufferParams
    {
        U32          Size;
    }STAUD_PESBufferParams_t;

#ifndef STAUD_REMOVE_CLKRV_SUPPORT

enum STAUD_CLKRVIdentifier
{
    CLKRV_FORNOMINAL,
    CLKRV_FORSYNCHRO
};

typedef struct STAUD_CLKRV_s
{
    STCLKRV_Handle_t                   ClkrvHandle;
    enum STAUD_CLKRVIdentifier         ClkrvIdentifier;
}STAUD_CLKRV_t;

#endif

typedef struct  STAUD_DiscardControlParam_s
{
    BOOL                Apply; /* 1 Enable Discard control i.e. audio drop */
                               /* 0 Disable Discard control */
}STAUD_DiscardControlParam_t;

enum STAUD_Profiles_e
{
    STAUD_MS10_PROFILE,
    STAUD_MS11_PROFILE,
    STAUD_DVB_PROFILE,
    STAUD_RESERVE_PROFILE

};

typedef struct STAUD_Profile_s
{
    enum STAUD_Profiles_e         Profile;
    STAUD_Object_t                Object;
} STAUD_Profile_t;



typedef enum
{
    STAUD_DIALNORM_PARAM        = 1,
    STAUD_PAUSE_THRESHOLD       = 2,
    STAUD_SKIP_THRESHOLD        = 3,
    STAUD_MODULE_STARTUP_DELAY  = 4,
    STAUD_MIXER_OUT_AT_SRC_FREQ = 5,

    STAUD_RESERVE_PARAM
}STAUD_UserConfigType_e;

typedef struct STAUD_UserParam_s
{
    U32 UserParam;
    STAUD_UserConfigType_e ValidFlag;
} STAUD_UserParam_t;


typedef struct STAUD_UserConfig_s
{
    STAUD_UserParam_t       STAUD_UserConfig;
    STAUD_Object_t          Object;
} STAUD_UserConfig_t;
typedef enum
{
    STAUD_VOLUME_MODE_LIGHT,
    STAUD_VOLUME_MODE_NORMAL,
    STAUD_VOLUME_MODE_HEAVY
}Levelermode_t;

typedef struct STAUD_PPUnifiedVolumeParams_s
{
    BOOL Apply;
    Levelermode_t LevelerAmount;
    S32 DigitalReflevel;
}STAUD_PPUnifiedVolumeParams_t;


/*********** STAUD_DRIVERCONFIG RELATED DECLARATIONS MOVED HERE *******/
/**** Reason: To reduce redundancy in the 4 driver config files ******************/

/* Max Number of units per object-set i.e. one producer and all its consumer */
#define MAX_PRODUCERS_PER_OBJECTSET 1 /* There can only be one producer per object set*/
/* Max Number of Consumer-Units is set here */
#ifdef STAUD_MAX_CONSUMER_NO
#define MAX_CONSUMERS_PER_OBJECTSET  (STAUD_MAX_CONSUMER_NO <4 ? 4:STAUD_MAX_CONSUMER_NO)
#else
#define MAX_CONSUMERS_PER_OBJECTSET  4
#endif
#define MAX_UNIT_PER_MODULE (MAX_PRODUCERS_PER_OBJECTSET + MAX_CONSUMERS_PER_OBJECTSET + 1)/* last one(OBJECTSET_DONE will mark the end of units  for this module */

/* Max Number of Object-Sets per Driver */
#ifdef MAX_STAUDLX_OBJECTSET_PER_DRIVER
#define MAX_OBJECTSET_PER_DRIVER    (MAX_STAUDLX_OBJECTSET_PER_DRIVER + 1)
#else
#define MAX_OBJECTSET_PER_DRIVER    (60 + 1)/* last one will mark the end of modules for this driver i.e. essentially end of driver */
#endif
/* Markers */
#define DRIVER_DONE     0xFFFF
#define OBJECTSET_DONE  (DRIVER_DONE - 1)

/* Object set cosists of one producer module and all its consumer modules */
typedef STAUD_Object_t ObjectSet[MAX_UNIT_PER_MODULE];

/* A driver consist of its ObjectSets */
typedef ObjectSet DriverConfig[MAX_OBJECTSET_PER_DRIVER];
typedef struct STAUD_Config_s{
    DriverConfig        * AudioDriverConfig_p;
    U32                   SubchainId;
    U32                   ConfigFlags;
}STAUD_Config_t;

typedef struct STAUD_ActiveObjects_s
    {
        /* Modules active for each type*/
        U8 NumInputObjects;
        U8 NumDecoderObjects;
        U8 NumPostProcObjects;
        U8 NumMixerObjects;
        U8 NumOutputObjects;
        U8 NumSPDIFFormatterObjects;
        U8 NumEncoderObjects;
        /* Module ID*/
        STAUD_Object_t InputObjects[STAUD_MAX_INPUT_OBJECTS];
        STAUD_Object_t DecoderObjects[STAUD_MAX_DECODER_OBJECTS];
        STAUD_Object_t PostProcObjects[STAUD_MAX_POST_PROC_OBJECTS];
        STAUD_Object_t MixerObjects[STAUD_MAX_MIXER_OBJECTS];
        STAUD_Object_t OutputObjects[STAUD_MAX_OUTPUT_OBJECTS];
        STAUD_Object_t SPDIFFormatterObjects[STAUD_MAX_SPDIFFORMATTER_OBJECTS];
        STAUD_Object_t EncoderObjects[STAUD_MAX_ENCODER_OBJECTS];

    } STAUD_ActiveObjects_t;



typedef struct STAUD_DDRE_s
{
    BOOL                         Enable;
    U8                           MetadataType; //eMetadataPPType
//    U8                           Cut_MC;
//    U8                           Boost_MC;
//    U8                           Cut_Stereo;
//    U8                           Boost_Stereo;
    BOOL                         TranscodeEnable;
    STAUD_TranscodeFormat_t      CompressedFormat;
    BOOL                         BypassEncoder;
//    STAUD_CompressionMode_t      CompressionMode;
    BOOL                         ExtPCMMode;
    STAUD_DDREComprProfileType_t  CompProfile;
} STAUD_DDRE_t;



//AD Splicing START

//It defines the type of notification.
// more notifications can be added here.

typedef enum STAUD_Notification_s
{
    STAUD_EARLY_PTS_DETECTION

}STAUD_Notification_t;

//Structure corresponding to a notification
//More structures can be added to the union for different notifications
typedef struct STAUD_NotificationParams_s
{
    STAUD_Notification_t  Notification;
    U32                   NotificationID;                         //Supplied by user
    union
    {
        struct
        {
            STAUD_PTS_t PTS;
            U32         Tolerance;
        } EarlyPtsNotification;
    };
} STAUD_NotificationParams_t;

//Structure corresponding to STAUD_NOTIFICATION_EVT event
//This will be sent to event callback
typedef struct STAUD_NotificationEventParams_s
{
    STAUD_Notification_t  Notification;
    U32                   NotificationID;
    union
    {
        struct
        {
            STAUD_PTS_t PTS;
        }EarlyPtsNotification;
    };
} STAUD_NotificationEventParams_t;


// For each notification type, separate structures can be defined and then handled in their respective functions;
typedef struct STAUD_EarlyPTSNotification_s
{
    STAUD_PTS_t PTS;
    U32                 Tolerance;
    U32                         NotificationID;
    BOOL                        Enable;
    STAUD_Notification_t         Notification;

}STAUD_EarlyPTSNotification_t;


//It specifies the flush mode to be adopted by the driver.
// find their specs in AD splicing design doc
typedef enum STAUD_FlushMode_e
{
    STAUD_FLUSH_CANCEL,
    STAUD_FLUSH_FROM_DISCONTINUITY_TO_PTS,
    STAUD_FLUSH_FROM_PTS_TO_DISCONTINUITY,
    STAUD_FLUSH_FROM_PTS,
    STAUD_FLUSH_TO_PTS,
    STAUD_FLUSH_FROM_DISCONTINUITY,
    STAUD_FLUSH_TO_DISCONTINUITY

} STAUD_FlushMode_t;

// It defines the parameters to be adopted for a particular flush mode
// It flush mode is PTS based then PTSBased trigger is accessed.
// DiscontinuityBased trigger is accessed only for STAUD_FLUSH_TO_DISCONTINUITY
typedef struct STAUD_FlushParams_s
{
    STAUD_FlushMode_t   FlushMode;
    struct
    {
        struct
        {
            U32 NbFrameToKeep;
        }DiscontinuityBased;

        struct
        {
            S32 Tolerance;
            STAUD_PTS_t PTS;
        }PTSBased;

   }Trigger;

} STAUD_FlushParams_t;



//AD Splicing END

typedef struct DDPulseStreamInfo_s
{

    U32  BitDepth         :  3; //!< eAccBitdepth :Encoded bit resolution
    U32  EncSampleRate    :  5; //!< Original Encoding Sample rate
    U32  SBRPresent       :  1; //!< SBR Signalled in Stream
    U32  PSPresent        :  1; //!< PS Signalled in Stream
    U32  DownSampleSBR    :  1; //!< Is DownSample SBR indicated in stream
    U32  AACFrameLenFlag  :  1; //!< 0 = 1024/ 1 = 960,indicated in GASpecificConfig
    U32  DolbyPulseId     :  1; //!< 1 = DPulse Stream/ 0 = Normal AAC/HEAAC Stream
    U32  NbLayers         :  3; //!< No. of Layers in case of LOAS
    U32  NbProgram        :  4; //!< No. of Programs in case of LOAS
    U32  NbSubframe       :  6; //!< No. of Subframes in case of LOAS/ADTS
        U32  Reserved_0       :  6; //!< Reserved for Future Use, Must be 0
} DDPulseFramestatus_t;

typedef union DDPulseStreamInfo_u
{
    U32                  Bits;
    DDPulseFramestatus_t DDPulseFramestatus;
}DDPulseStreamInfo_t;


/*********** STAUD_DRIVERCONFIG RELATED STUFF ENDS HERE *******/

    /* Exported Variables ------------------------------- */



    /* Exported Macros ---------------------------------- */


    /* Exported Functions ------------------------------- */

/* Export IPRC handler */
int staud_IPrC_Handler(U32 request, void *arg);

    ST_ErrorCode_t STAUD_OPSetModeConfig (STAUD_Handle_t Handle, STAUD_Object_t OutputObject,
                                STAUD_OPModeConfig_t *PlayerConfig_p);

    ST_ErrorCode_t STAUD_OPGetModeConfig (STAUD_Handle_t Handle, STAUD_Object_t OutputObject,
                                        STAUD_OPModeConfig_t *PlayerConfig_p);

    ST_ErrorCode_t STAUD_SBAGSet(STAUD_Handle_t Handle, STAUD_Object_t InputObject,
                                STAUD_SBAGParam_t  *SBAGParam_p);

    ST_ErrorCode_t STAUD_OPSetAttenuation (STAUD_Handle_t Handle, STAUD_Object_t OutputObject,
                STAUD_Attenuation_t * Attenuation_p);

    ST_ErrorCode_t STAUD_DRSetDecodingType(STAUD_Handle_t Handle, STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_Close(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_DRConnectSource(STAUD_Handle_t Handle, STAUD_Object_t DecoderObject,
                                         STAUD_Object_t InputSource);

    ST_ErrorCode_t STAUD_ConnectSrcDst (STAUD_Handle_t Handle,
                                      STAUD_Object_t SrcObject,U32 SrcId,
                                      STAUD_Object_t DestObject,U32 DstId);

     ST_ErrorCode_t STAUD_DisconnectInput(STAUD_Handle_t Handle,
                                      STAUD_Object_t Object,U32 InputId);

    ST_ErrorCode_t STAUD_PPDisableDownsampling(STAUD_Handle_t Handle, STAUD_Object_t PostProcObject);


    ST_ErrorCode_t STAUD_PPEnableDownsampling(STAUD_Handle_t Handle,
            STAUD_Object_t PostProcObject, U32 OutputFrequency);

    ST_ErrorCode_t STAUD_DRSetBeepToneFrequency (STAUD_Handle_t Handle,
        STAUD_Object_t DecoderObject,U32 BeepToneFrequency);

    ST_ErrorCode_t STAUD_DRGetBeepToneFrequency (STAUD_Handle_t Handle,
        STAUD_Object_t DecoderObject,U32 *BeepToneFreq_p);


    ST_ErrorCode_t STAUD_IPGetBroadcastProfile(STAUD_Handle_t Handle,
            STAUD_Object_t InputObject, STAUD_BroadcastProfile_t * BroadcastProfile_p);

    ST_ErrorCode_t STAUD_DRGetCapability(const ST_DeviceName_t DeviceName,
             STAUD_Object_t DecoderObject, STAUD_DRCapability_t *Capability_p);

    ST_ErrorCode_t STAUD_DRGetDynamicRangeControl(STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject, STAUD_DynamicRange_t * DynamicRange_p);

    ST_ErrorCode_t STAUD_DRSetDownMix (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject, STAUD_DownmixParams_t * DownMixParam_p);

    ST_ErrorCode_t STAUD_DRGetDownMix (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject, STAUD_DownmixParams_t * DownMixParam_p);

    ST_ErrorCode_t STAUD_IPGetSamplingFrequency(STAUD_Handle_t Handle,
            STAUD_Object_t InputObject, U32 *SamplingFrequency_p);

    ST_ErrorCode_t STAUD_DRGetStreamInfo (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject, STAUD_StreamInfo_t * StreamInfo_p);

    ST_ErrorCode_t STAUD_DRGetSpeed(STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject, S32 *Speed_p);

    ST_ErrorCode_t STAUD_IPGetStreamInfo(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject, STAUD_StreamInfo_t *StreamInfo_p);


    ST_ErrorCode_t STAUD_DRGetSyncOffset(STAUD_Handle_t Handle,
                                         STAUD_Object_t DecoderObject, S32 *Offset_p);

    ST_ErrorCode_t STAUD_DRPause(STAUD_Handle_t Handle,
                                 STAUD_Object_t DecoderObject, STAUD_Fade_t *Fade_p);

    ST_ErrorCode_t STAUD_DRPrepare(STAUD_Handle_t Handle,
                                   STAUD_Object_t DecoderObject, STAUD_StreamParams_t *StreamParams_p);

    ST_ErrorCode_t STAUD_DRResume(STAUD_Handle_t Handle,
                                  STAUD_Object_t DecoderObject);

    ST_ErrorCode_t STAUD_OPGetCapability(const ST_DeviceName_t DeviceName,
                                  STAUD_Object_t OutputObject, STAUD_OPCapability_t *Capability_p);

    ST_ErrorCode_t STAUD_OPGetParams(STAUD_Handle_t Handle,
                                  STAUD_Object_t OutputObject, STAUD_OutputParams_t *Params_p);

    ST_ErrorCode_t STAUD_OPEnableSynchronization(STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_OPDisableSynchronization(STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_OPEnableHDMIOutput (STAUD_Handle_t Handle,
                                            STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_OPDisableHDMIOutput (STAUD_Handle_t Handle,
                                            STAUD_Object_t OutputObject);

#ifndef STAUD_REMOVE_CLKRV_SUPPORT
    ST_ErrorCode_t STAUD_DRSetClockRecoverySource (STAUD_Handle_t Handle,
            STAUD_Object_t Object, STCLKRV_Handle_t ClkSource);
    ST_ErrorCode_t STAUD_DRSetCLKRVSource (STAUD_Handle_t Handle, STAUD_Object_t Object, STAUD_CLKRV_t *ClkSource_p);
#endif

    ST_ErrorCode_t STAUD_DRSetDiscardControl (const STAUD_Handle_t Handle,
            STAUD_Object_t Object, STAUD_DiscardControlParam_t *DiscardControlParam_p);

    ST_ErrorCode_t STAUD_OPSetDigitalMode (STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject,
            STAUD_DigitalMode_t OutputMode);

    ST_ErrorCode_t STAUD_OPSetAnalogMode (STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject,
            STAUD_PCMMode_t OutputMode);
    ST_ErrorCode_t STAUD_OPSetEncDigitalOutput(const STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject,
            BOOL EnableDisableEncOutput);

    ST_ErrorCode_t STAUD_OPGetDigitalMode (STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject,
            STAUD_DigitalMode_t * OutputMode);
    ST_ErrorCode_t STAUD_OPGetAnalogMode (STAUD_Handle_t Handle,
            STAUD_Object_t OutputObject,
            STAUD_PCMMode_t * OutputMode);

    ST_ErrorCode_t STAUD_OPMute(STAUD_Handle_t Handle,
                                STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_OPSetParams(STAUD_Handle_t Handle,
                                     STAUD_Object_t OutputObject,
                                     STAUD_OutputParams_t *Params_p);

    ST_ErrorCode_t STAUD_OPUnMute(STAUD_Handle_t Handle,
                                  STAUD_Object_t OutputObject);

    ST_ErrorCode_t STAUD_DRSetDynamicRangeControl(STAUD_Handle_t Handle,
            STAUD_Object_t Object,
            STAUD_DynamicRange_t *
            DynamicRange_p);

    ST_ErrorCode_t STAUD_MXSetReplacementChannel(STAUD_Handle_t Handle,
            STAUD_Object_t MixerObject, U32 InputID, BOOL Apply);

    ST_ErrorCode_t STAUD_DRApplyMetaData (STAUD_Handle_t Handle,
            STAUD_Object_t InputObject, STAUD_ApplyMetadata_t *ApplyMetaData);


    ST_ErrorCode_t STAUD_DRSetCompressionMode (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject,
            STAUD_CompressionMode_t
            CompressionMode_p);

    ST_ErrorCode_t  STAUD_DRSetAudioCodingMode(STAUD_Handle_t  Handle,
                STAUD_Object_t DecoderObject,
                STAUD_AudioCodingMode_t
                AudioCodingMode_p);

    ST_ErrorCode_t STAUD_DRSetSpeed(STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject, S32 Speed);

    ST_ErrorCode_t STAUD_IPSetStreamID(STAUD_Handle_t Handle,
                                       STAUD_Object_t InputObject,
                                       U8 StreamID);

    ST_ErrorCode_t STAUD_DRSetSyncOffset(STAUD_Handle_t Handle,
                                         STAUD_Object_t DecoderObject,
                                         S32 Offset);
    ST_ErrorCode_t STAUD_IPSetADSubStreamID (STAUD_Handle_t Handle, STAUD_Object_t InputObject, U32 SubStreamID);

    ST_ErrorCode_t STAUD_OPSetLatency (STAUD_Handle_t Handle,
                                        STAUD_Object_t OutputObject,
                                        U32 Latency);

    ST_ErrorCode_t STAUD_DRStart(STAUD_Handle_t Handle,
                                 STAUD_Object_t DecoderObject,
                                 STAUD_StreamParams_t *StreamParams_p);

    ST_ErrorCode_t STAUD_DRStop(STAUD_Handle_t Handle,
                                STAUD_Object_t DecoderObject,
                                STAUD_Stop_t StopMode, STAUD_Fade_t *Fade_p);

    ST_ErrorCode_t STAUD_GetCapability(const ST_DeviceName_t DeviceName,
                                       STAUD_Capability_t *Capability_p);

    ST_Revision_t STAUD_GetRevision(void);

    ST_Revision_t STAUD_GetFWRevision(void);

    ST_ErrorCode_t STAUD_Init(const ST_DeviceName_t DeviceName,
                              STAUD_InitParams_t *InitParams_p);

    ST_ErrorCode_t STAUD_OpenDevice(void);

    ST_ErrorCode_t STAUD_IPGetCapability(const ST_DeviceName_t DeviceName,
                                    STAUD_Object_t InputObject,
                                    STAUD_IPCapability_t *Capability_p);

    ST_ErrorCode_t STAUD_IPGetParams(STAUD_Handle_t Handle,
                                     STAUD_Object_t InputObject,
                                     STAUD_InputParams_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPGetInputBufferParams(STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject,
                                                STAUD_BufferParams_t* DataParams_p);
    ST_ErrorCode_t STAud_GetReadPointer(STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject,
                                                U32* DataParams_p);

    ST_ErrorCode_t  STAUD_IPSetDataInputInterface(STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject,
                                                GetWriteAddress_t   GetWriteAddress_p,
                                                InformReadAddress_t InformReadAddress_p,
                                                void * const BufferHandle_p);

    ST_ErrorCode_t  STAUD_IPDeleteDataInputInterface(STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject);

    ST_ErrorCode_t STAUD_IPQueuePCMBuffer(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_PCMBuffer_t *PCMBuffer_p,
                                    U32 NumBuffers, U32 *NumQueued_p);

    ST_ErrorCode_t STAUD_IPGetPCMBuffer (STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_PCMBuffer_t * PCMBuffer_p);

    ST_ErrorCode_t STAUD_IPGetPCMBufferSize (STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U32 * BufferSize);

    ST_ErrorCode_t STAUD_IPSetLowDataLevelEvent(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U32 Level);

    ST_ErrorCode_t STAUD_IPSetParams(STAUD_Handle_t Handle,
                                     STAUD_Object_t InputObject,
                                     STAUD_InputParams_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPSetPCMParams(STAUD_Handle_t Handle,
                                     STAUD_Object_t InputObject,
                                     STAUD_PCMInputParams_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPSetBroadcastProfile (STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_BroadcastProfile_t
                                    BroadcastProfile);

    ST_ErrorCode_t STAUD_IPSetPCMReaderParams(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_PCMReaderConf_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPGetPCMReaderParams(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_PCMReaderConf_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPGetPCMReaderCapability(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_ReaderCapability_t *InputParams_p);

    ST_ErrorCode_t STAUD_IPGetBitBufferFreeSize(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U32 * Size_p);

    ST_ErrorCode_t STAUD_IPGetSynchroUnit (STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    STAUD_SynchroUnit_t *SynchroUnit_p);

    ST_ErrorCode_t STAUD_IPSkipSynchro(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U32 Delay);

    ST_ErrorCode_t STAUD_IPPauseSynchro(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U32 Delay);

    ST_ErrorCode_t STAUD_IPSetWMAStreamID(STAUD_Handle_t Handle,
                                    STAUD_Object_t InputObject,
                                    U8 WMAStreamNumber);

    ST_ErrorCode_t STAUD_MXConnectSource(STAUD_Handle_t Handle,
                                         STAUD_Object_t MixerObject,
                                         STAUD_Object_t *InputSources_p,
                                         STAUD_MixerInputParams_t *
                                         InputParams_p, U32 NumInputs);

    ST_ErrorCode_t STAUD_MXGetMixLevel (STAUD_Handle_t Handle,
                        STAUD_Object_t MixerObject,
                        U32 InputID,
                        U16 *MixLevel_p);

    ST_ErrorCode_t STAUD_MXGetCapability(const ST_DeviceName_t DeviceName,
                                         STAUD_Object_t MixerObject,
                                         STAUD_MXCapability_t *Capability_p);

    ST_ErrorCode_t STAUD_MXSetInputParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t MixerObject,
                                          STAUD_Object_t InputSource,
                                          STAUD_MixerInputParams_t *
                                          InputParams_p);

    ST_ErrorCode_t  STAUD_MXSetMixLevel (STAUD_Handle_t Handle,
                        STAUD_Object_t MixerObject,
                        U32 InputID, U16 MixLevel);

    ST_ErrorCode_t STAUD_MXSetChannelMixLevel (STAUD_Handle_t Handle,
                                            STAUD_Object_t MixerObject, U32 InputID,
                                            STAUD_MixLevel_t *MixLevel);


    ST_ErrorCode_t STAUD_Open(const ST_DeviceName_t DeviceName,
                                                        const STAUD_OpenParams_t *Params_p,
                                                        STAUD_Handle_t *Handle_p);

    ST_ErrorCode_t STAUD_PPGetAttenuation(STAUD_Handle_t Handle,
                                                        STAUD_Object_t PostProcObject,
                                                        STAUD_Attenuation_t *Attenuation_p);

    ST_ErrorCode_t STAUD_PPGetDelay(STAUD_Handle_t Handle,
                                    STAUD_Object_t OutputObject,
                                    STAUD_Delay_t *Delay_p);

    ST_ErrorCode_t STAUD_PPGetEqualizationParams(STAUD_Handle_t Handle,
                                                 STAUD_Object_t PostProcObject,
                                                 STAUD_Equalization_t *Equalization_p);


    ST_ErrorCode_t STAUD_PPGetSpeakerEnable(STAUD_Handle_t Handle,
                                            STAUD_Object_t PostProcObject,
                                            STAUD_SpeakerEnable_t *SpeakerEnable_p);

    ST_ErrorCode_t STAUD_PPGetSpeakerConfig(STAUD_Handle_t Handle,
                                            STAUD_Object_t PostProcObject,
                                            STAUD_SpeakerConfiguration_t *
                                            SpeakerConfig_p);


    ST_ErrorCode_t STAUD_PPSetAttenuation(STAUD_Handle_t Handle,
                                          STAUD_Object_t PostProcObject,
                                          STAUD_Attenuation_t *Attenuation_p);

    ST_ErrorCode_t STAUD_PPSetDelay(STAUD_Handle_t Handle,
                                    STAUD_Object_t PostProcObject,
                                    STAUD_Delay_t *Delay_p);

    ST_ErrorCode_t STAUD_PPSetEqualizationParams(STAUD_Handle_t Handle,
                                                 STAUD_Object_t PostProcObject,
                                                 STAUD_Equalization_t *Equalization_p);


    ST_ErrorCode_t STAUD_PPSetSpeakerEnable(STAUD_Handle_t Handle,
                                            STAUD_Object_t OutputObject,
                                            STAUD_SpeakerEnable_t *SpeakerEnable_p);

    ST_ErrorCode_t STAUD_PPSetSpeakerConfig(STAUD_Handle_t Handle,
                                            STAUD_Object_t OutputObject,
                                            STAUD_SpeakerConfiguration_t *
                                            SpeakerConfig_p,
                                            STAUD_BassMgtType_t BassType);


    ST_ErrorCode_t STAUD_PPConnectSource(STAUD_Handle_t Handle,
                                         STAUD_Object_t PostProcObject,
                                         STAUD_Object_t InputSource);

    ST_ErrorCode_t STAUD_PPGetCapability(const ST_DeviceName_t DeviceName,
                                         STAUD_Object_t PostProcObject,
                                         STAUD_PPCapability_t *Capability_p);


    ST_ErrorCode_t STAUD_PPGetKaraoke(STAUD_Handle_t Handle,
                                      STAUD_Object_t PostProcObject,
                                      STAUD_Karaoke_t *Karaoke_p);


    ST_ErrorCode_t STAUD_PPSetKaraoke(STAUD_Handle_t Handle,
                                      STAUD_Object_t PostProcObject,
                                      STAUD_Karaoke_t Karaoke);


    ST_ErrorCode_t STAUD_Term(const ST_DeviceName_t DeviceName,
                              const STAUD_TermParams_t *TermParams_p);

     /* ++ Decoder level PP */
     ST_ErrorCode_t STAUD_DRSetDeEmphasisFilter (STAUD_Handle_t Handle,
                            STAUD_Object_t PostProcObject,BOOL Emphasis);

     ST_ErrorCode_t STAUD_DRGetDeEmphasisFilter (STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject,BOOL *Emphasis_p);

     ST_ErrorCode_t STAUD_DRSetDolbyDigitalEx(STAUD_Handle_t Handle,
                            STAUD_Object_t DecoderObject,BOOL DolbyDigitalEx);

     ST_ErrorCode_t STAUD_DRGetDolbyDigitalEx(STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject,BOOL * DolbyDigitalEx_p);

     ST_ErrorCode_t STAUD_DRSetEffect (STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject,STAUD_Effect_t Effect);

     ST_ErrorCode_t STAUD_DRGetEffect (STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject, STAUD_Effect_t * Effect_p);

     ST_ErrorCode_t STAUD_DRSetOmniParams (STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject,STAUD_Omni_t Omni);

     ST_ErrorCode_t STAUD_DRGetOmniParams (STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject, STAUD_Omni_t * Omni_p);

     ST_ErrorCode_t STAUD_DRSetCircleSurroundParams (STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject,STAUD_CircleSurrondII_t CSii);

     ST_ErrorCode_t STAUD_DRGetCircleSurroundParams  (STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject, STAUD_CircleSurrondII_t * CSii_p);

     ST_ErrorCode_t STAUD_DRSetSRSEffectParams (STAUD_Handle_t Handle,
                                    STAUD_Object_t DecoderObject,STAUD_EffectSRSParams_t ParamType,S16 Value);

     ST_ErrorCode_t STAUD_DRGetSRSEffectParams (STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject, STAUD_EffectSRSParams_t ParamType,S16 *Value);

     ST_ErrorCode_t STAUD_DRSetPrologic (STAUD_Handle_t Handle,
                            STAUD_Object_t DecoderObject,BOOL Prologic);

     ST_ErrorCode_t STAUD_DRGetPrologic(STAUD_Handle_t Handle,
                        STAUD_Object_t DecoderObject,BOOL * Prologic_p);

     ST_ErrorCode_t STAUD_DRSetPrologicAdvance (STAUD_Handle_t Handle,
                            STAUD_Object_t DecoderObject, STAUD_PLIIParams_t PLIIParams);

     ST_ErrorCode_t STAUD_DRGetPrologicAdvance (STAUD_Handle_t Handle,
                            STAUD_Object_t DecoderObject, STAUD_PLIIParams_t *PLIIParams);

     ST_ErrorCode_t STAUD_DRSetStereoMode (STAUD_Handle_t Handle,
                STAUD_Object_t DecoderObject,STAUD_StereoMode_t StereoMode);

     ST_ErrorCode_t STAUD_DRGetStereoMode (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject,STAUD_StereoMode_t * StereoMode_p);

     ST_ErrorCode_t STAUD_DRGetInStereoMode (STAUD_Handle_t Handle,
            STAUD_Object_t DecoderObject,STAUD_StereoMode_t * StereoMode_p);

     ST_ErrorCode_t STAUD_DRMute(STAUD_Handle_t Handle, STAUD_Object_t OutputObject);

     ST_ErrorCode_t STAUD_DRUnMute(STAUD_Handle_t Handle, STAUD_Object_t OutputObject);

     ST_ErrorCode_t STAUD_DRSetDDPOP (STAUD_Handle_t Handle,
                                            STAUD_Object_t DecoderObject,
                                            U32 DDPOPSetting);
     ST_ErrorCode_t STAUD_DRGetOPParameter(STAUD_Handle_t Handle,
                                            STAUD_Object_t Object,
                                            STAUD_OPConfigParams_t * OPSetting_p);
    ST_ErrorCode_t STAUD_DRSetOPParameter(STAUD_Handle_t Handle,
                                            STAUD_Object_t Object,
                                            STAUD_OPConfigParams_t * OPSetting_p);
     ST_ErrorCode_t STAUD_DRGetSamplingFrequency (STAUD_Handle_t Handle,
                                            STAUD_Object_t InputObject,
                                            U32 * SamplingFrequency_p);

     ST_ErrorCode_t STAUD_DRSetDDREParams (STAUD_Handle_t Handle,
                                            STAUD_Object_t Object,
                                            STAUD_DDRE_t *ddre_p);

     ST_ErrorCode_t STAUD_DRSetInitParams (STAUD_Handle_t Handle,
                                            STAUD_Object_t InputObject,
                                            STAUD_DRInitParams_t * InitParams);

    ST_ErrorCode_t STAUD_ENCGetCapability(const ST_DeviceName_t DeviceName,
                                         STAUD_Object_t EncoderObject,
                                         STAUD_ENCCapability_t *Capability_p);

    ST_ErrorCode_t STAUD_ENCGetOutputParams(STAUD_Handle_t Handle,
                                 STAUD_Object_t EncoderObject,
                                 STAUD_ENCOutputParams_s *EncoderOPParams_p);

    ST_ErrorCode_t STAUD_ENCSetOutputParams(STAUD_Handle_t Handle,
                                 STAUD_Object_t EncoderObject, STAUD_StreamContent_t EncodedStreamContent,
                                 STAUD_ENCOutputParams_s *EncoderOPParams_p);


    ST_ErrorCode_t STAUD_ModuleStart (STAUD_Handle_t Handle,
                                STAUD_Object_t ModuleObject,
                                STAUD_StreamParams_t * StreamParams_p);

    ST_ErrorCode_t STAUD_GenericStart (STAUD_Handle_t Handle);




    ST_ErrorCode_t STAUD_ModuleStop (STAUD_Handle_t Handle,STAUD_Object_t ModuleObject);

    ST_ErrorCode_t STAUD_GenericStop(STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_SetModuleAttenuation(STAUD_Handle_t Handle, STAUD_Object_t ModuleObject,
                                          STAUD_Attenuation_t *Attenuation_p);
    ST_ErrorCode_t STAUD_GetModuleAttenuation (STAUD_Handle_t Handle, STAUD_Object_t ModuleObject,
                                          STAUD_Attenuation_t * Attenuation_p);
#ifdef STPOWER_SUPPORTED
    ST_ErrorCode_t STAUD_PowerFunction(STPOWER_State_t State,const void * DeviceData_p);
#endif

     /* -- Decoder Level PP */


    /* Wrapper Layer function prototypes */

#ifndef STAUD_NO_WRAPPER_LAYER

    ST_ErrorCode_t STAUD_DisableDeEmphasis(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_DisableSynchronisation(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_EnableDeEmphasis(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_EnableSynchronisation(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_GetAttenuation(const STAUD_Handle_t Handle, STAUD_Attenuation_t *Attenuation);

    ST_ErrorCode_t STAUD_GetChannelDelay(const STAUD_Handle_t Handle, STAUD_Delay_t *Delay);

    ST_ErrorCode_t STAUD_GetDigitalOutput(const STAUD_Handle_t Handle, STAUD_DigitalOutputConfiguration_t * Mode);

    ST_ErrorCode_t STAUD_GetDynamicRangeControl(const STAUD_Handle_t Handle, U8 *Control);

    ST_ErrorCode_t STAUD_GetEffect(const STAUD_Handle_t Handle, STAUD_Effect_t *Mode);

    ST_ErrorCode_t STAUD_GetKaraokeOutput(const STAUD_Handle_t Handle, STAUD_Karaoke_t *Mode);

    ST_ErrorCode_t STAUD_GetPrologic(const STAUD_Handle_t Handle, BOOL *PrologicState);

    ST_ErrorCode_t STAUD_GetSpeaker(const STAUD_Handle_t Handle, STAUD_Speaker_t *Speaker);

    ST_ErrorCode_t STAUD_GetSpeakerConfiguration(const STAUD_Handle_t Handle, STAUD_SpeakerConfiguration_t * Speaker);

    ST_ErrorCode_t STAUD_GetStereoOutput(const STAUD_Handle_t Handle, STAUD_Stereo_t *Mode);

    ST_ErrorCode_t STAUD_GetSynchroUnit(STAUD_Handle_t Handle, STAUD_SynchroUnit_t *SynchroUnit_p);

    ST_ErrorCode_t STAUD_Mute(const STAUD_Handle_t Handle, BOOL AnalogueOutput, BOOL DigitalOutput);

    ST_ErrorCode_t STAUD_Pause(const STAUD_Handle_t Handle, STAUD_Fade_t *Fade);

    ST_ErrorCode_t STAUD_PauseSynchro(const STAUD_Handle_t Handle, U32 Unit);

    ST_ErrorCode_t STAUD_Play(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_Prepare(const STAUD_Handle_t Handle, STAUD_Prepare_t *Params);

    ST_ErrorCode_t STAUD_Resume(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_SetAttenuation(const STAUD_Handle_t Handle, STAUD_Attenuation_t Attenuation);

    ST_ErrorCode_t STAUD_SetChannelDelay(const STAUD_Handle_t Handle, STAUD_Delay_t Delay);

    ST_ErrorCode_t STAUD_SetDigitalOutput(const STAUD_Handle_t Handle, STAUD_DigitalOutputConfiguration_t Mode);

    ST_ErrorCode_t STAUD_SetDynamicRangeControl(const STAUD_Handle_t Handle, U8 Control);

    ST_ErrorCode_t STAUD_SetEffect(const STAUD_Handle_t Handle, const STAUD_Effect_t Mode);

    ST_ErrorCode_t STAUD_SetKaraokeOutput(const STAUD_Handle_t Handle, const STAUD_Karaoke_t Mode);

    ST_ErrorCode_t STAUD_SetPrologic(const STAUD_Handle_t Handle);

    ST_ErrorCode_t STAUD_SetSpeaker(const STAUD_Handle_t Handle, const STAUD_Speaker_t Speaker);

    ST_ErrorCode_t STAUD_SetSpeakerConfiguration(const STAUD_Handle_t Handle,
                                                STAUD_SpeakerConfiguration_t Speaker,
                                                STAUD_BassMgtType_t BassType);

    ST_ErrorCode_t STAUD_SetStereoOutput(const STAUD_Handle_t Handle, const STAUD_Stereo_t Mode);

    ST_ErrorCode_t STAUD_SkipSynchro(STAUD_Handle_t Handle, STAUD_AudioPlayerID_t PlayerID, U32 Delay);

    ST_ErrorCode_t STAUD_Start(const STAUD_Handle_t Handle, STAUD_StartParams_t *Params);

    ST_ErrorCode_t STAUD_Stop(const STAUD_Handle_t Handle, const STAUD_Stop_t StopMode, STAUD_Fade_t *Fade);

    ST_ErrorCode_t STAUD_PlayerStart(const STAUD_Handle_t Handle);
    ST_ErrorCode_t STAUD_PlayerStop(const STAUD_Handle_t Handle);

   ST_ErrorCode_t STAUD_GetInputBufferParams(STAUD_Handle_t Handle,
                                STAUD_AudioPlayerID_t PlayerID, STAUD_BufferParams_t* DataParams_p);

    ST_ErrorCode_t STAUD_DRGetDolbyVolumeParams(STAUD_Handle_t Handle,
                                STAUD_Object_t Object, STAUD_DolbyVolume_t * DlbyVolume_p);

    ST_ErrorCode_t STAUD_DRSetDolbyVolumeParams(STAUD_Handle_t Handle,
                                STAUD_Object_t Object, STAUD_DolbyVolume_t * DlbyVolume_p);

    ST_ErrorCode_t STAUD_DRSetDTSNeuralParams(STAUD_Handle_t Handle,
                                STAUD_Object_t Object, STAUD_DTSNeural_t * DTSNeural_p);

   ST_ErrorCode_t STAUD_SetClockRecoverySource (STAUD_Handle_t Handle, STCLKRV_Handle_t ClkSource);

    ST_ErrorCode_t AUD_IntHandlerInstall(int InterruptNumber, int InterruptLevel); /* For time being */

    ST_ErrorCode_t STAUD_PPDcRemove(STAUD_Handle_t Handle,
                                                STAUD_Object_t PPObject, STAUD_DCRemove_t *Params_p);
#endif

#ifdef ST_OSLINUX

    ST_ErrorCode_t STAUD_MapBufferToUserSpace(STAUD_BufferParams_t* DataParams_p);
    ST_ErrorCode_t STAUD_UnmapBufferFromUserSpace(STAUD_BufferParams_t* DataParams_p);

#endif

typedef struct BufferMetaData_s
{
    U32 PTS;
    U32 PTS33;
    BOOL isWMAEncASFHeaderData;
    BOOL isDummyBuffer;
} BufferMetaData_t;

typedef ST_ErrorCode_t (* FrameDeliverFunc_t)
(
    U8 * MemoryStart,
    U32 Size,
    BufferMetaData_t bufferMetaData,
    void * clientInfo
);

ST_ErrorCode_t STAUD_DPSetCallback (STAUD_Handle_t Handle,
                                                STAUD_Object_t DPObject,
                                                FrameDeliverFunc_t Func_fp,
                                                void * clientInfo);

ST_ErrorCode_t STAUD_MXUpdatePTSStatus(STAUD_Handle_t Handle,
                                                STAUD_Object_t MixerObject,
                                                U32 InputID,
                                                BOOL PTSStatus);

ST_ErrorCode_t STAUD_MXUpdateMaster(STAUD_Handle_t Handle,
                                                STAUD_Object_t MixerObject,
                                                U32 InputID,
                                                BOOL FreeRun);

ST_ErrorCode_t STAUD_DRGetCompressionMode (STAUD_Handle_t Handle,
                                                STAUD_Object_t DecoderObject,
                                                STAUD_CompressionMode_t *CompressionMode_p);

ST_ErrorCode_t STAUD_DRGetAudioCodingMode (STAUD_Handle_t Handle,
                                                STAUD_Object_t DecoderObject,
                                                STAUD_AudioCodingMode_t * AudioCodingMode_p);

ST_ErrorCode_t STAUD_IPHandleEOF (STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject);

ST_ErrorCode_t STAUD_IPGetDataInterfaceParams (STAUD_Handle_t Handle,
                                                STAUD_Object_t InputObject,
                                                STAUD_DataInterfaceParams_t *DMAParams_p);

ST_ErrorCode_t STAUD_GetBufferParam (STAUD_Handle_t Handle,
                                        STAUD_Object_t InputObject,
                                        STAUD_GetBufferParam_t *BufferParam);


ST_ErrorCode_t STAUD_DRSetDTSNeoParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t DecoderObject,
                                          STAUD_DTSNeo_t *DTSNeo_p);

ST_ErrorCode_t STAUD_DRGetDTSNeoParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t DecoderObject,
                                          STAUD_DTSNeo_t *DTSNeo_p);

ST_ErrorCode_t STAUD_DRSetSRSVIQParams(STAUD_Handle_t Handle,
                                                   STAUD_Object_t DecoderObject,
                                                   STAUD_SRSVIQ_t  *SRSViq_p);

ST_ErrorCode_t STAUD_DRGetSRSVIQParams (STAUD_Handle_t Handle,
                                                   STAUD_Object_t DecoderObject,
                                                   STAUD_SRSVIQ_t  *SRSViq_p);

ST_ErrorCode_t STAUD_PPSetBTSCParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t PostProcObject,
                                          STAUD_BTSC_t *BTSC_p);

ST_ErrorCode_t STAUD_PPGetBTSCParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t PostProcObject,
                                          STAUD_BTSC_t *BTSC_p);

ST_ErrorCode_t STAUD_SetScenario(STAUD_Handle_t Handle, STAUD_Scenario_t Scenario);
ST_ErrorCode_t STAUD_SetBeepToneFrequency (STAUD_Handle_t Handle, STAUD_Object_t ModuleObject, U32 Frequency);

ST_ErrorCode_t  STAud_GetDriverHandle(const ST_DeviceName_t DeviceName ,STAUD_Object_t  ObjectID,
                                STAUD_Handle_t *DriverHandle);

ST_ErrorCode_t STAUD_IPSetPESBufferParams(STAUD_Handle_t Handle, STAUD_Object_t Object, STAUD_PESBufferParams_t  *PESBufferSize);

#ifdef STCOMPANION_SUPPORTED
ST_ErrorCode_t STAUD_RecoveryCallbackFunction(STCOMPANION_Device_t CPUID, STCOMPANION_Reason_t Reason, U32 RegistrantData);
#endif

ST_ErrorCode_t STAUD_PPSetOmni2Params(STAUD_Handle_t Handle,
                                          STAUD_Object_t DecoderObject,
                                          STAUD_PPOmni2_t  *Omni2_p);

ST_ErrorCode_t STAUD_PPGetOmni2Params (STAUD_Handle_t Handle,
                                                      STAUD_Object_t DecoderObject,
                                                      STAUD_PPOmni2_t  *Omni2_p);

ST_ErrorCode_t STAUD_PPSetCompressorParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t DecoderObject,
                                          STAUD_PPSTIVCConfigParams_t  *mdrc_p);

ST_ErrorCode_t STAUD_PPGetCompressorParams (STAUD_Handle_t Handle,
                                                      STAUD_Object_t DecoderObject,
                                                      STAUD_PPSTIVCConfigParams_t  *mdrc_p);

ST_ErrorCode_t STAUD_PPSetDRCParams(STAUD_Handle_t Handle,
                                          STAUD_Object_t DecoderObject,
                                          STAUD_PPDRCConfigParams_t* DrcConfig_p);

ST_ErrorCode_t STAUD_PPGetDRCParams (STAUD_Handle_t Handle,
                                                      STAUD_Object_t DecoderObject,
                                                      STAUD_PPDRCConfigParams_t* DrcConfig_p);

ST_ErrorCode_t STAUD_SetUnifiedVolumeParams (STAUD_Handle_t Handle, STAUD_Object_t Object, STAUD_PPUnifiedVolumeParams_t * UnifiedVolumeParams_p);
ST_ErrorCode_t STAUD_GetUnifiedVolumeParams (STAUD_Handle_t Handle,STAUD_Object_t Object,STAUD_PPUnifiedVolumeParams_t *UnifiedVolumeParam_p);
ST_ErrorCode_t  STAUD_ConfigureChain(STAUD_Handle_t Handle, STAUD_Config_t * ConfigParam_p);
ST_ErrorCode_t  STAUD_GetConfig(STAUD_Handle_t Handle ,STAUD_ActiveObjects_t * ActiveObjects_p);
ST_ErrorCode_t  STAUD_DRSetProfile( STAUD_Handle_t  Handle, STAUD_Profile_t * STAUD_Profile_p);
ST_ErrorCode_t  STAUD_DRSetUserParam( STAUD_Handle_t  Handle, STAUD_UserConfig_t * STAUDUserConfig_p);

ST_ErrorCode_t  STAUD_SetNotification(const STAUD_Handle_t Handle, const STAUD_Object_t Object, BOOL Enable, const STAUD_NotificationParams_t *  const NotificationParams_p );
ST_ErrorCode_t STAUD_Flush(const STAUD_Handle_t AudioHandle,const STAUD_Object_t Object,const STAUD_FlushParams_t * const FlushParams_p);

#ifdef STAUD_DEBUG_STATISTICS
ST_ErrorCode_t STAUD_GetStatistics(const ST_DeviceName_t DeviceName, STAUD_Statistics_t * AudStatic_p );
ST_ErrorCode_t STAUD_ResetStatistics(const ST_DeviceName_t DeviceName);
#endif

#if defined(ST_FLI7510) || defined(ST_FLI7540)

#define STAUD_OBJECT_NULL 0

typedef enum STAUD_ChainId_e
{
    STAUD_IN_DIGITAL_TUNER_0      = (1<<0),
    STAUD_IN_DIGITAL_TUNER_1      = (1<<1),
    STAUD_IN_PCM_INPUT            = (1<<2),
    STAUD_IN_SPDIF_INPUT          = (1<<3),
    STAUD_IN_ANALOG_TUNER         = (1<<4),
    STAUD_IN_ANALOG_BASEBAND      = (1<<5),
    STAUD_IN_HDMI_INPUT1          = (1<<6),
    STAUD_IN_HDMI_INPUT2           = (1<<7),

    STAUD_IN_DIGITAL_AD_0         = (1<<8),
    STAUD_IN_DIGITAL_AD_1         = (1<<9),
    STAUD_IN_DIGITAL_COMPRESSED_0 = (1<<10),
    STAUD_IN_DIGITAL_COMPRESSED_1 = (1<<11),
    STAUD_IN_DIGITAL_TRANSCODED_0 = (1<<12),
    STAUD_IN_DIGITAL_TRANSCODED_1 = (1<<13),
    STAUD_INTR_ENCODER_OUT0       = (1<<15),

    STAUD_MAX_INPUT_CHAIN_ID      = (1<<14),

    STAUD_MAX_INTR_CHAIN_ID       = (1<<17),

    STAUD_OUT_ENCODER_IN          = (1<<16),
    STAUD_OUT_MAIN_LS             = (1<<18),
    STAUD_OUT_PIP_HP              = (1<<19),
    STAUD_OUT_AUX1                = (1<<20),
    STAUD_OUT_AUX2                = (1<<21),
    STAUD_OUT_SPDIF_COMPRESSED    = (1<<22),
    STAUD_OUT_SPDIF_UNCOMPRESSED  = (1<<23),
    STAUD_OUT_MAX_OUTPUT_CHAIN_ID = (1<<24),

    STAUD_NO_CHAIN_ID          = (1<<31)
} STAUD_ChainId_t;

//Naveen accepted to change this Enum for member order like the following
typedef enum
{
    STAUD_DAC_23_OUT = 1,
    STAUD_DAC_45_OUT,
    STAUD_SCART_IN_1,
    STAUD_SCART_IN_2,
    STAUD_SCART_IN_3,
    STAUD_SCART_IN_4,
    STAUD_SCART_IN_5,
    STAUD_SCART_IN_6,
    STAUD_SCART_IN_7,
    STAUD_SCART_IN_8,
} STAUD_SCARTSource_t;


typedef enum
{
    STAUD_SCART_OUT_1,
    STAUD_SCART_OUT_2,
    STAUD_SCART_OUT_3,
} STAUD_SCARTOut_t;


typedef enum STAUD_AuxI2SOutSource_e
{
    STAUD_PCM_PLAYER_1 = 0,
    STAUD_PCM_PLAYER_2,
    STAUD_PCM_PLAYER_3,
    STAUD_PCM_PLAYER_4,
    STAUD_SIFDEMOD_OUT_BYPASS = 5,
    STAUD_BASEBAND_ADC_BYPASS_OUT = 6,
} STAUD_AuxI2SOutSource_t;

#define FREEMAN_MAX_NUM_CHAINS          25
#define FREEMAN_MAX_NUM_OUTPUT_CHAINS    8
#define FREEMAN_MAX_CHAIN_CONTENTS       6

typedef struct
{
    BOOL                    DefaultParams;
    STAUD_StreamParams_t    StreamParams;
} STAUD_ChainParams_t;

ST_ErrorCode_t STAUD_ConnectChains (STAUD_Handle_t Handle, STAUD_ChainId_t InputChain, STAUD_ChainId_t OutputChain);

ST_ErrorCode_t STAUD_DisconnectChains ( STAUD_Handle_t Handle, STAUD_ChainId_t InputChain, STAUD_ChainId_t OutputChain);

ST_ErrorCode_t STAUD_StartChain( STAUD_Handle_t Handle, STAUD_ChainId_t Chain, STAUD_ChainParams_t *ChainParams_p);

ST_ErrorCode_t STAUD_StopChain( STAUD_Handle_t Handle, STAUD_ChainId_t Chain);

ST_ErrorCode_t STAUD_GetConnectedAudioChains (STAUD_Handle_t Handle, STAUD_ChainId_t OutputChain, STAUD_ChainId_t *InputChain);

ST_ErrorCode_t STAUD_GetObjectList(STAUD_Handle_t  Handle, STAUD_ChainId_t Chain, STAUD_DrvChainConstituent_t ** ObjectList);

ST_ErrorCode_t STAUD_GetObject(STAUD_Handle_t  Handle, STAUD_ChainId_t   Chain, U32 InputType, STAUD_Object_t *Object);

ST_ErrorCode_t STAUD_ManagerStart(STAUD_Handle_t  Handle);

ST_ErrorCode_t STAUD_EnableDisableAD(STAUD_Handle_t  Handle, STAUD_ChainId_t Chain, BOOL EnableDisable);

ST_ErrorCode_t STAUD_IPBasebandInSourceSelect(STAUD_Handle_t  Handle, STAUD_SCARTSource_t BasebandInSource);

ST_ErrorCode_t STAUD_OPSCARTOutSourceSelect(STAUD_Handle_t  Handle, STAUD_SCARTOut_t SCARTOutInstance, STAUD_SCARTSource_t SCARTOutSource);

ST_ErrorCode_t STAUD_OPAuxI2SOutSelect(STAUD_Handle_t  Handle, STAUD_AuxI2SOutSource_t AuxI2SSource);

ST_ErrorCode_t STAUD_OPBypassDemodOutToDAC(STAUD_Handle_t  Handle, BOOL BypassEnable);

ST_ErrorCode_t STAUD_PPSetSpeakerCompConfig (STAUD_Handle_t Handle, STAUD_Object_t PostProcObject, STAUD_PPSpeakerCompParams_t* SpeakerCompParams);

#endif // defined(ST_FLI7510) || defined(ST_FLI7540)

ST_ErrorCode_t STAUD_DRSetSRSWOWHDParams(STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPSRSWOWHDConfigParam_t  *SRSWowhd_p);

ST_ErrorCode_t STAUD_DRGetSRSWOWHDParams (STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPSRSWOWHDConfigParam_t  *SRSWowhd_p);

ST_ErrorCode_t STAUD_PPSetDBBParams(STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPDBBConfigParam_t          *dbb_p);

ST_ErrorCode_t STAUD_PPGetDBBParams (STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPDBBConfigParam_t  *dbb_p);

ST_ErrorCode_t STAUD_PPSetGPEQParams(STAUD_Handle_t Handle, STAUD_Object_t DecoderObject,   STAUD_PPGPEQConfigParam_t  *gpeq_p);

ST_ErrorCode_t STAUD_PPGetGPEQParams(STAUD_Handle_t Handle, STAUD_Object_t DecoderObject,   STAUD_PPGPEQConfigParam_t  *gpeq_p);

ST_ErrorCode_t STAUD_PPSetSTHeadPhoneParams(STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPSTHeadPhoneConfigParam_t *STHeadPhone);

ST_ErrorCode_t STAUD_PPGetSTHeadPhoneParams(STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPSTHeadPhoneConfigParam_t *STHeadPhone);
ST_ErrorCode_t STAUD_PPSetBBEParams(STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPBBEConfigParam_t          *bbe_p);

ST_ErrorCode_t STAUD_PPGetBBEParams (STAUD_Handle_t Handle,  STAUD_Object_t DecoderObject,  STAUD_PPBBEConfigParam_t  *bbe_p);

ST_ErrorCode_t STAUD_PPSetSpeechEnhParams(STAUD_Handle_t Handle, STAUD_Object_t DecoderObject, STAUD_PPSpeechEnhConfigParams_t  *SpeechEnh_p);

ST_ErrorCode_t STAUD_PPGetSpeechEnhParams(STAUD_Handle_t Handle, STAUD_Object_t DecoderObject, STAUD_PPSpeechEnhConfigParams_t  *SpeechEnh_p);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STAUDLX_H */






