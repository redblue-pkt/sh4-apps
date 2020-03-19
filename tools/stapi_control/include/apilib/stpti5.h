/*****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved               */
/* ST makes no warranty express or implied including but not limited to,     */
/* any warranty of                                                           */
/*                                                                           */
/*   (i)  merchantability or fitness for a particular purpose and/or         */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED */
/*        MATERIALS, which is provided "AS IS", WITH ALL FAULTS. ST does not */
/*        represent or warrant that the LICENSED MATERIALS provided here     */
/*        under is free of infringement of any third party patents,          */
/*        copyrights,trade secrets or other intellectual property rights.    */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE       */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                    */
/*                                                                           */
/*****************************************************************************/

#ifndef _STPTI_H_
 #define _STPTI_H_








/* Includes ---------------------------------------------------------------- */

#include "stos.h"
#include "stddefs.h"

#include "stevt.h"

#if defined( DVD_STPTI5_STUB ) || defined( DVD_STPTI5_PROXY )
#include "stiprc.h"
#define STPTI_IPRC_PRESENT
#endif


/* ------------------------------------------------------------------------- */

#define STPTI_DRIVER_ID             13
#define STPTI_DRIVER_BASE           (STPTI_DRIVER_ID << 16)
#define STPTI_ERROR_BASE            STPTI_DRIVER_BASE

#define STPTI_EVENT_BASE            STPTI_DRIVER_BASE

/* Some constants to indicate the maximums of some of the arrays that can be passed into the API */
#define STPTI_MAX_SLOTS_PER_SAME_PID        (4)
#define STPTI_MAX_NUM_OF_FILTERS            (64)
#define STPTI_MAX_NUM_OF_INDEXEVENTS        (32)
#define STPTI_MAX_NUM_OF_INJECTOR_NODES     (16)
#define STPTI_MAX_NUM_OF_INDEXES_TO_CHAIN   (16)
#define STPTI_START_CODE_MASK_ARRAY_SIZE    (8)


/* Enumerated types -------------------------------------------------------- */

typedef enum STPTI_ErrorType_s
{
    STPTI_ERROR_ALREADY_WAITING_ON_SLOT = (STPTI_ERROR_BASE + 1),
    STPTI_ERROR_BUFFER_NOT_LINKED,
    STPTI_ERROR_CAROUSEL_ALREADY_ALLOCATED,
    STPTI_ERROR_CAROUSEL_ENTRY_INSERTED,
    STPTI_ERROR_CAROUSEL_LOCKED_BY_DIFFERENT_SESSION,
    STPTI_ERROR_CAROUSEL_NOT_LOCKED,
    STPTI_ERROR_CAROUSEL_OUTPUT_ONLY_ON_NULL_SLOT,
    STPTI_ERROR_CORRUPT_DATA_IN_BUFFER,
    STPTI_ERROR_DESCRAMBLER_ALREADY_ASSOCIATED,
    STPTI_ERROR_DESCRAMBLER_NOT_ASSOCIATED,
    STPTI_ERROR_DESCRAMBLER_TYPE_NOT_SUPPORTED,
    STPTI_ERROR_DMA_UNAVAILABLE,
    STPTI_ERROR_ENTRY_ALREADY_INSERTED,
    STPTI_ERROR_ENTRY_IN_USE,
    STPTI_ERROR_ENTRY_NOT_IN_CAROUSEL,
    STPTI_ERROR_EVENT_QUEUE_EMPTY,
    STPTI_ERROR_EVENT_QUEUE_FULL,
    STPTI_ERROR_FILTER_ALREADY_ASSOCIATED,
    STPTI_ERROR_FLUSH_FILTERS_NOT_SUPPORTED,
    STPTI_ERROR_FUNCTION_NOT_SUPPORTED,
    STPTI_ERROR_INCOMPLETE_PES_IN_BUFFER,
    STPTI_ERROR_INCOMPLETE_SECTION_IN_BUFFER,
    STPTI_ERROR_INDEX_INVALID_ASSOCIATION,
    STPTI_ERROR_INDEX_INVALID_HANDLE,
    STPTI_ERROR_INDEX_NONE_FREE,
    STPTI_ERROR_INDEX_NOT_ASSOCIATED,
    STPTI_ERROR_INDEX_PID_ALREADY_ASSOCIATED,
    STPTI_ERROR_INDEX_SLOT_ALREADY_ASSOCIATED,
    STPTI_ERROR_INTERRUPT_QUEUE_EMPTY,
    STPTI_ERROR_INTERRUPT_QUEUE_FULL,
    STPTI_ERROR_INVALID_ALLOW_OUTPUT_TYPE,
    STPTI_ERROR_INVALID_BUFFER_HANDLE,
    STPTI_ERROR_INVALID_CAROUSEL_ENTRY_HANDLE,
    STPTI_ERROR_INVALID_CAROUSEL_HANDLE,
    STPTI_ERROR_INVALID_CD_FIFO_ADDRESS,
    STPTI_ERROR_INVALID_DESCRAMBLER_ASSOCIATION,
    STPTI_ERROR_INVALID_DESCRAMBLER_HANDLE,
    STPTI_ERROR_INVALID_DEVICE,
    STPTI_ERROR_INVALID_FILTER_DATA,
    STPTI_ERROR_INVALID_FILTER_HANDLE,
    STPTI_ERROR_INVALID_FILTER_OPERATING_MODE,
    STPTI_ERROR_INVALID_FILTER_REPEAT_MODE,
    STPTI_ERROR_INVALID_FILTER_TYPE,
    STPTI_ERROR_INVALID_INJECTION_TYPE,
    STPTI_ERROR_INVALID_KEY_USAGE,
    STPTI_ERROR_INVALID_LOADER_OPTIONS,
    STPTI_ERROR_INVALID_PARITY,
    STPTI_ERROR_INVALID_PES_START_CODE,
    STPTI_ERROR_INVALID_PID,
    STPTI_ERROR_INVALID_SESSION_HANDLE,
    STPTI_ERROR_INVALID_SIGNAL_HANDLE,
    STPTI_ERROR_INVALID_SLOT_HANDLE,
    STPTI_ERROR_INVALID_SLOT_TYPE,
    STPTI_ERROR_INVALID_SUPPORTED_TC_CODE,
    STPTI_ERROR_NOT_ALLOCATED_IN_SAME_SESSION,
    STPTI_ERROR_NOT_INITIALISED,
    STPTI_ERROR_NOT_ON_SAME_DEVICE,
    STPTI_ERROR_NOT_SUPPORTED_FOR_DTV,
    STPTI_ERROR_NO_FREE_DESCRAMBLERS,
    STPTI_ERROR_NO_FREE_DMAS,
    STPTI_ERROR_NO_FREE_FILTERS,
    STPTI_ERROR_NO_FREE_SLOTS,
    STPTI_ERROR_NO_PACKET,
    STPTI_ERROR_OFFSET_EXCEEDS_PACKET_SIZE,
    STPTI_ERROR_ONLY_ONE_SIGNAL_PER_BUFFER,
    STPTI_ERROR_ONLY_ONE_SIGNAL_PER_SLOT,
    STPTI_ERROR_PID_ALREADY_COLLECTED,
    STPTI_ERROR_SET_MATCH_ACTION_NOT_SUPPORTED,
    STPTI_ERROR_SIGNAL_ABORTED,
    STPTI_ERROR_SIGNAL_EVERY_PACKET_ONLY_ON_PES_SLOT,
    STPTI_ERROR_SLOT_FLAG_NOT_SUPPORTED,
    STPTI_ERROR_SLOT_NOT_ASSOCIATED,
    STPTI_ERROR_SLOT_NOT_RAW_MODE,
    STPTI_ERROR_SLOT_NOT_SIGNAL_EVERY_PACKET,
    STPTI_ERROR_STORE_LAST_HEADER_ONLY_ON_RAW_SLOT,
    STPTI_ERROR_UNABLE_TO_ENABLE_FILTERS,
    STPTI_ERROR_USER_BUFFER_NOT_ALIGNED,
    STPTI_ERROR_WILDCARD_PID_ALREADY_SET,
    STPTI_ERROR_WILDCARD_PID_NOT_SUPPORTED,
    STPTI_ERROR_SLOT_ALREADY_LINKED,
    STPTI_ERROR_NOT_A_MANUAL_BUFFER,
    STPTI_ERROR_CAROUSEL_ENTRY_ALREADY_ALLOCATED,
    STPTI_ERROR_IOREMAPFAILED,
    STPTI_ERROR_INVALID_STREAM_ID,
    STPTI_ERROR_FILTER_NOT_ASSOCIATED,
    STPTI_ERROR_OBJECT_ALREADY_ASSOCIATED,                      /* Start of new TANGO errors */
    STPTI_ERROR_OBJECTS_NOT_ASSOCIATED,
    STPTI_ERROR_TSINPUT_ROUTE_UNAVAILABLE,
    STPTI_ERROR_TSINPUT_HW_ACCESS_ERROR,
    STPTI_ERROR_TSINPUT_NOT_CONFIGURED,
    STPTI_ERROR_BUFFER_HAS_NO_METADATA,
    STPTI_ERROR_TOO_MANY_SLOTS_WITH_SAME_PID,
    STPTI_ERROR_INAPPROPRIATE_API_FOR_DATA_TYPE,
    STPTI_ERROR_INVALID_DATA_ENTRY_HANDLE,
    STPTI_ERROR_DATA_ENTRY_ALREADY_LOADED,
    STPTI_ERROR_DATA_ENTRY_NOT_LOADED,
    STPTI_ERROR_NOT_ALLOWED_WHILST_PID_SET,
    STPTI_ERROR_DIFFERING_SECURITY_PATH_IDS,
    STPTI_ERROR_ONLY_ONE_INJECTOR_ALLOWED_ON_A_DEVICE,
    STPTI_ERROR_ALREADY_MONITORING_PID,
    STPTI_ERROR_NOT_MONITORING_PID,
    STPTI_ERROR_SLOT_SECONDARY_PID_IN_USE,
    STPTI_ERROR_NOT_ENOUGH_ROOM_TO_RETURN_DATA,
    STPTI_ERROR_OBJECT_ASSOCIATED,
    STPTI_ERROR_OBJECT_HAS_CHILDREN,
    STPTI_ERROR_END   /* Must be last. This is used to determine the number of STPTI error codes. */
} STPTI_ErrorType_t;



#if !defined( _stptiHAL_ )
/* To prevent type infiltration on the HAL only the above defines are permitted to be used globally
   throughout the driver.  Inside the stptiHAL the rest of STPTI API (below) is not available. */

typedef enum STPTI_Event_s
{
    STPTI_EVENT_BUFFER_OVERFLOW_EVT = STPTI_EVENT_BASE, /* supported */
    STPTI_EVENT_CC_ERROR_EVT,                           /* supported */
    STPTI_EVENT_CLEAR_TO_SCRAMBLED_EVT,                 /* supported */
    STPTI_EVENT_CWP_BLOCK_EVT,
    STPTI_EVENT_DMA_COMPLETE_EVT,
    STPTI_EVENT_INDEX_MATCH_EVT,
    STPTI_EVENT_INTERRUPT_FAIL_EVT,
    STPTI_EVENT_INVALID_DESCRAMBLE_KEY_EVT,
    STPTI_EVENT_INVALID_LINK_EVT,
    STPTI_EVENT_INVALID_PARAMETER_EVT,                  /* supported */
    STPTI_EVENT_PACKET_ERROR_EVT,                       /* supported */
    STPTI_EVENT_PCR_RECEIVED_EVT,                       /* supported */
    STPTI_EVENT_SCRAMBLED_TO_CLEAR_EVT,                 /* supported */
    STPTI_EVENT_SECTIONS_DISCARDED_ON_CRC_CHECK_EVT,    /* supported */
    STPTI_EVENT_TC_CODE_FAULT_EVT,
    STPTI_EVENT_PES_ERROR_EVT,                          /* supported */
    STPTI_EVENT_BUFFER_LEVEL_CHANGE_EVT,                /* supported */
    STPTI_EVENT_DATA_ENTRY_COMPLETE_EVT,                /* supported */
    STPTI_EVENT_MARKER_ERROR_EVT,                       /* supported */
    STPTI_EVENT_INVALID_SECONDARY_PID_PACKET_EVT,       /* supported */
    STPTI_EVENT_END
}STPTI_Event_t;


#define STPTI_TIMEOUT_IMMEDIATE  ((U32)0)
#define STPTI_TIMEOUT_INFINITY   ((U32)0XFFFFFFFF)


typedef enum STPTI_Timer_s
{
    STPTI_AUDIO_TIMER0,
    STPTI_VIDEO_TIMER0
} STPTI_Timer_t;


typedef enum STPTI_Copy_s
{
    STPTI_COPY_TRANSFER_BY_MEMCPY,
    STPTI_COPY_TRANSFER_BY_FDMA,
    STPTI_COPY_TRANSFER_BY_MEMCPY_SCATTER_LIST,
    STPTI_COPY_TRANSFER_BY_MEMCPY_LINUX_KERNEL,         /* Only for linux kernel space to kernel space copies */
} STPTI_Copy_t;


typedef enum STPTI_SCBits_s
{
    STPTI_SCB_CLEAR   = 0,
    STPTI_SCB_DEFAULT = 1,
    STPTI_SCB_EVEN    = 2,
    STPTI_SCB_ODD     = 3
} STPTI_SCBits_t;


typedef enum STPTI_FilterRepeatMode_s
{
    STPTI_FILTER_REPEAT_MODE_STPTI_FILTER_ONE_SHOT,
    STPTI_FILTER_REPEAT_MODE_STPTI_FILTER_REPEATED
} STPTI_FilterRepeatMode_t;


typedef enum STPTI_FilterType_s
{
    STPTI_FILTER_TYPE_EMM_FILTER,
    STPTI_FILTER_TYPE_ECM_FILTER,
    STPTI_FILTER_TYPE_DC2_MULTICAST16_FILTER,
    STPTI_FILTER_TYPE_DC2_MULTICAST32_FILTER,
    STPTI_FILTER_TYPE_DC2_MULTICAST48_FILTER,
    STPTI_FILTER_TYPE_SECTION_FILTER_TINY_MODE,
    STPTI_FILTER_TYPE_SECTION_FILTER_SHORT_MODE,
    STPTI_FILTER_TYPE_SECTION_FILTER_LONG_MODE,
    STPTI_FILTER_TYPE_SECTION_FILTER_NEG_MATCH_MODE,
    STPTI_FILTER_TYPE_PES_FILTER,
    STPTI_FILTER_TYPE_TSHEADER_FILTER,
    STPTI_FILTER_TYPE_PES_STREAMID_FILTER
} STPTI_FilterType_t;
#define STPTI_FILTER_TYPE_SECTION_FILTER STPTI_FILTER_TYPE_SECTION_FILTER_SHORT_MODE


typedef enum STPTI_ScrambleState_s
{
    STPTI_SCRAMBLE_STATE_UNKNOWN,
    STPTI_SCRAMBLE_STATE_CLEAR,
    STPTI_SCRAMBLE_STATE_TRANSPORT_SCRAMBLED,
    STPTI_SCRAMBLE_STATE_PES_SCRAMBLED
}STPTI_ScrambleState_t;


typedef enum STPTI_SlotType_s
{
    STPTI_SLOT_TYPE_NULL        = 0x00,
    STPTI_SLOT_TYPE_SECTION     = 0x01,
    STPTI_SLOT_TYPE_PES         = 0x02,
    STPTI_SLOT_TYPE_RAW         = 0x03,
    STPTI_SLOT_TYPE_EMM         = 0x05,
    STPTI_SLOT_TYPE_ECM         = 0x06,
    STPTI_SLOT_TYPE_VIDEO_ES    = 0x07,
    STPTI_SLOT_TYPE_AUDIO_ES    = 0x08,
    STPTI_SLOT_TYPE_PCR         = 0x80,     /* a virtual slot mode */

} STPTI_SlotType_t;

#define STPTI_SLOT_TYPE_ES STPTI_SLOT_TYPE_VIDEO_ES


/*################################################################
IMPORTANT Do not reorder. NONE must follow TSCA which follows TSIN
TSCA values must be inclusive OR'ed with 0x1000 so the TSHAL can
identify the difference. NONE must be let as 0xFFFF
0x8000 is reserved value and not to be used.
##################################################################*/
typedef enum STPTI_StreamID_s
{
    STPTI_STREAM_ID_TSIN0  = 0x0000,
    STPTI_STREAM_ID_TSIN1  = 0x0001,
    STPTI_STREAM_ID_TSIN2  = 0x0002,
    STPTI_STREAM_ID_TSIN3  = 0x0003,
    STPTI_STREAM_ID_TSIN4  = 0x0004,
    STPTI_STREAM_ID_TSIN5  = 0x0005,
    STPTI_STREAM_ID_TSIN6  = 0x0006,
    STPTI_STREAM_ID_TSIN7  = 0x0007,
    STPTI_STREAM_ID_TSIN8  = 0x0008,
    STPTI_STREAM_ID_TSIN9  = 0x0009,
    STPTI_STREAM_ID_TSIN10 = 0x000A,
    STPTI_STREAM_ID_TSIN11 = 0x000B,
    STPTI_STREAM_ID_TSIN12 = 0x000C,
    STPTI_STREAM_ID_TSIN13 = 0x000D,
    STPTI_STREAM_ID_TSIN14 = 0x000E,
    STPTI_STREAM_ID_TSIN15 = 0x000F,
    STPTI_STREAM_ID_TSIN16 = 0x0010,
    STPTI_STREAM_ID_TSIN17 = 0x0011,
    STPTI_STREAM_ID_TSIN18 = 0x0012,
    STPTI_STREAM_ID_TSIN19 = 0x0013,
    STPTI_STREAM_ID_TSIN20 = 0x0014,
    STPTI_STREAM_ID_TSIN21 = 0x0015,
    STPTI_STREAM_ID_TSIN22 = 0x0016,
    STPTI_STREAM_ID_TSIN23 = 0x0017,
    STPTI_STREAM_ID_TSIN24 = 0x0018,
    STPTI_STREAM_ID_TSIN25 = 0x0019,
    STPTI_STREAM_ID_TSIN26 = 0x001A,
    STPTI_STREAM_ID_TSIN27 = 0x001B,
    STPTI_STREAM_ID_TSIN28 = 0x001C,
    STPTI_STREAM_ID_TSIN29 = 0x001D,
    STPTI_STREAM_ID_TSIN30 = 0x001E,
    STPTI_STREAM_ID_TSIN31 = 0x001F,
    STPTI_STREAM_ID_SWTS0  = 0x1000,            /* SWTS ports are only for routing to TSOUT / CableCard,     */
    STPTI_STREAM_ID_SWTS1  = 0x1001,            /* You cannot route them directly to the Transport Processor */
    STPTI_STREAM_ID_SWTS2  = 0x1002,
    STPTI_STREAM_ID_SWTS3  = 0x1003,
    STPTI_STREAM_ID_SWTS4  = 0x1004,
    STPTI_STREAM_ID_SWTS5  = 0x1005,
    STPTI_STREAM_ID_SWTS6  = 0x1006,
    STPTI_STREAM_ID_SWTS7  = 0x1007,
    STPTI_STREAM_ID_SWTS8  = 0x1008,
    STPTI_STREAM_ID_MIB0   = 0x2000,            /* MIB ports are only for routing to Transport Processor     */
    STPTI_STREAM_ID_NONE   = 0xFFFF		/* You cannot route them directly to the TSOUT */
    /* Use to deactivate a virtual PTI from receiving Live Data */
}STPTI_StreamID_t;

/* (deprecated names) Kept for backwards compatibility */
#define STPTI_STREAM_ID_TSCA0 STPTI_STREAM_ID_SWTS0
#define STPTI_STREAM_ID_TSCA1 STPTI_STREAM_ID_SWTS1
#define STPTI_STREAM_ID_TSCA2 STPTI_STREAM_ID_SWTS2
#define STPTI_STREAM_ID_TSCA3 STPTI_STREAM_ID_SWTS3


typedef enum STPTI_Protocol_s
{
    STPTI_PROTOCOL_DVB,
    STPTI_PROTOCOL_DVB_TAGGED
} STPTI_Protocol_t;

typedef enum STPTI_SecondaryPidMode_e
{
   STPTI_SECONDARY_PID_MODE_SUBSTITUTION,
   STPTI_SECONDARY_PID_MODE_INSERTION,
   STPTI_SECONDARY_PID_MODE_INSERTDELETE
} STPTI_SecondaryPidMode_t;

typedef enum STPTI_PacketLength_e
{
    STPTI_PACKET_LENGTH_DVB = 188,
    STPTI_PACKET_LENGTH_DVB_TAGGED = 196,
}STPTI_PacketLength_t;

typedef struct STPTI_InjectorNode_s
{
    U8 * Data_p;
    U32  SizeOfData;
}STPTI_InjectorNode_t;

typedef enum STPTI_TSInputClkRcvSrc_e
{
    STPTI_TSINPUT_CLK_RCV0,
    STPTI_TSINPUT_CLK_RCV1,
    STPTI_TSINPUT_CLK_RCV2,
    STPTI_TSINPUT_CLK_RCV_END   /* Always Leave Last in the List !! */
}STPTI_TSInputClkRcvSrc_t;

typedef enum STPTI_TSInputPaceClkSrc_e
{
    STPTI_TSINPUT_PACE_CLK0,
    STPTI_TSINPUT_PACE_CLK1,
    STPTI_TSINPUT_PACE_CLK_END   /* Always Leave Last in the List !! */
}STPTI_TSInputPaceClkSrc_t;

typedef enum STPTI_TSInputDestination_e
{
    STPTI_TSINPUT_DEST_DEMUX, /* Always leave first in the List! */
    STPTI_TSINPUT_DEST_TSOUT0,
    STPTI_TSINPUT_DEST_TSOUT1,
    STPTI_TSINPUT_DEST_EXT_TSOUT0,
    STPTI_TSINPUT_DEST_EXT_TSOUT1,
    STPTI_TSINPUT_DEST_END    /* Always Leave Last in the List !! */
}STPTI_TSInputDestination_t;

typedef enum STPTI_TSInputTagging_e
{
    STPTI_TSINPUT_TAGS_NONE, /* Always leave first in the List! */
    STPTI_TSINPUT_TAGS_STFE,
    STPTI_TSINPUT_TAGS_TTS,
    STPTI_TSINPUT_TAGS_END   /* Always Leave Last in the List !! */
}STPTI_TSInputTagging_t;

typedef struct STPTI_TSInputParam_s
{
    ST_Partition_t              *Partition_p;
    STPTI_PacketLength_t         PacketLength;
    BOOL                         SyncLDEnable;
    BOOL                         SerialNotParallel;             /* Only applicable to TSIN                                                                */
    BOOL                         AsyncNotSync;                  /* Only applicable to TSIN                                                                */
    BOOL                         AlignByteSOP;                  /* Only applicable to TSIN                                                                */
    BOOL                         InvertTSClk;                   /* Only applicable to TSIN                                                                */
    BOOL                         IgnoreErrorInByte;             /* Only applicable to TSIN                                                                */
    BOOL                         IgnoreErrorInPkt;              /* Only applicable to TSIN                                                                */
    BOOL                         IgnoreErrorAtSOP;              /* Only applicable to TSIN                                                                */
    BOOL                         InputBlockEnable;
    U32                          MemoryPktNum;
    STPTI_TSInputClkRcvSrc_t     ClkRvSrc;                      /* Only applicable to TSIN                                                                */
    STPTI_TSInputDestination_t   Routing;
    STPTI_TSInputTagging_t       InputDataTagging;              /* Only applicable to TSCA  - not supported on all devices                                */
    U32                          OutputPacingRate;              /* Only applicable to Routing == STPTI_TSINPUT_DEST_TSOUTx - not supported on all devices */
    STPTI_TSInputPaceClkSrc_t    OutputPacingClkSrc;            /* Only applicable to Routing == STPTI_TSINPUT_DEST_TSOUTx - not supported on all devices */
    BOOL                         CIMode;                        /* Only applicable to Routing == STPTI_TSINPUT_DEST_TSOUTx                                */
    BOOL                         OutputSerialNotParallel;       /* Only applicable to Routing == STPTI_TSINPUT_DEST_TSOUTx                                */
}STPTI_TSInputParams_t;

typedef struct STPTI_TSInputStatus_s
{
    BOOL                Lock;
    BOOL                FifoOverflow;
    BOOL                BufferOverflow;
    BOOL                OutOfOrderRP;
    BOOL                PktOverflow;
    BOOL                DMAPointerError;
    BOOL                DMAOverflow;
    U8                  ErrorPackets;
    U8                  ShortPackets;
}STPTI_TSInputStatus_t;

typedef enum STPTI_InjectorInputTagging_e
{
    STPTI_INJECTOR_TAGS_NONE,      /* Always leave first in the List! */
    STPTI_INJECTOR_STFE_TAGS,
    STPTI_INJECTOR_DLNA_TTS_TAGS
}STPTI_InjectorInputTagging_t;

/* Handles and misc types -------------------------------------------------- */


typedef U32 STPTI_Handle_t;

typedef STPTI_Handle_t STPTI_Buffer_t;
typedef STPTI_Handle_t STPTI_Filter_t;
typedef STPTI_Handle_t STPTI_Injector_t;
typedef STPTI_Handle_t STPTI_Signal_t;
typedef STPTI_Handle_t STPTI_Slot_t;
typedef STPTI_Handle_t STPTI_Index_t;
typedef STPTI_Handle_t STPTI_DataEntry_t;


typedef U16 STPTI_Pid_t;
typedef U8 STPTI_TSPacket_t[188];       /* DVB packet */


/* data structures --------------------------------------------------------- */



typedef struct STPTI_Capability_s
{
    U8                             DeviceIndex;
    ST_DeviceName_t                EventHandlerName;

    U16                            NumberSlots;
    U16                            NumberDMAs;
    U16                            NumberKeys;
    U16                            NumberSectionFilters;

    BOOL                           AlternateOutputSupport;
    BOOL                           PidWildcardingSupport;
    BOOL                           RawStreamDescrambling;
    STPTI_Protocol_t               Protocol;
} STPTI_Capability_t;


typedef struct STPTI_TimeStamp_s
{
    U32 LSW;
    U8  Bit32;
} STPTI_TimeStamp_t;


#define STPTI_MAX_START_CODES_SUPPORTED 1


typedef union STPTI_IndexDefinition_s
{
    struct
    {
        U32 PayloadUnitStartIndicator:1;            /* 0x00000001 */
        U32 ScramblingChangeToClear:1;              /* 0x00000002 */
        U32 ScramblingChangeToEven:1;               /* 0x00000004 */
        U32 ScramblingChangeToOdd:1;                /* 0x00000008 */

        U32 DiscontinuityIndicator:1;               /* 0x00000010 */
        U32 RandomAccessIndicator:1;                /* 0x00000020 */
        U32 PriorityIndicator:1;                    /* 0x00000040 */
        U32 PCRFlag:1;                              /* 0x00000080 */

        U32 OPCRFlag:1;                             /* 0x00000100 */
        U32 SplicingPointFlag:1;                    /* 0x00000200 */
        U32 TransportPrivateDataFlag:1;             /* 0x00000400 */
        U32 AdaptationFieldExtensionFlag:1;         /* 0x00000800 */

        U32 FirstRecordedPacket:1;                  /* 0x00001000 */
        U32 MPEGStartCode:1;                        /* 0x00002000 */
        U32 IFrameStart:1;                          /* 0x00004000 - RESERVED (for used in supporting drivers) */
        U32 PFrameStart:1;                          /* 0x00008000 - RESERVED (for used in supporting drivers) */

        U32 BFrameStart:1;                          /* 0x00010000 - RESERVED (for used in supporting drivers) */
        U32 IFieldStart:1;                          /* 0x00020000 - RESERVED (for used in supporting drivers) */
        U32 PFieldStart:1;                          /* 0x00040000 - RESERVED (for used in supporting drivers) */
        U32 BFieldStart:1;                          /* 0x00080000 - RESERVED (for used in supporting drivers) */

        U32 IDRFrameStart:1;                        /* 0x00100000 - RESERVED (for used in supporting drivers) */
        U32 IDRFieldStart:1;                        /* 0x00200000 - RESERVED (for used in supporting drivers) */
        U32 SequenceStart:1;                        /* 0x00400000 - RESERVED (for used in supporting drivers) */

        U32 Reserved:7;                             /* 0x3f800000 */
        U32 Reserved2:2;                            /* 0xC0000000 */
    } s;
    U32 word;
} STPTI_IndexDefinition_t;


typedef struct STPTI_StartCode_s
{
    U8  MPEGStartCodeValue;
    U8  MPEGStartCodeOffsetInToTSPacket;
    U16 AuxillaryData;
} STPTI_StartCode_t;

typedef enum STPTI_StartCodeMode_s
{
    STPTI_NO_STARTCODE_INDEXING,
    STPTI_INDEX_STARTCODES_WITH_CONTEXT
} STPTI_IndexingStartCodeMode_t;


typedef struct STPTI_IndexEventData_s
{
    STPTI_IndexDefinition_t IndexBitMap;
    U32                     PacketCount;
    U32                     BufferPacketAddress;            /* not supported, use OffsetIntoBuffer instead */
    U32                     RecordBufferPacketCount;

    size_t                  OffsetIntoBuffer;
    STPTI_Buffer_t          BufferHandle;

    STPTI_TimeStamp_t       PCRTime;
    U16                     PCRTimeExtension;

    STPTI_TimeStamp_t       PacketArrivalTime;
    U16                     ArrivalTimeExtension;

    U8                      NumberStartCodesDetected;
    STPTI_StartCode_t       MPEGStartCode[STPTI_MAX_START_CODES_SUPPORTED];

    U32                     AssociatedDataBytes;
} STPTI_IndexEventData_t;


typedef struct STPTI_PCREventData_s
{
    BOOL              DiscontinuityFlag;
    STPTI_TimeStamp_t PCRArrivalTime;
    U16               PCRArrivalTimeExtension;
    STPTI_TimeStamp_t PCRBase;
    U16               PCRExtension;
} STPTI_PCREventData_t;


typedef struct STPTI_ErrEventData_s
{
    U32 DMANumber;
    U32 BytesRemaining;
    U32 ExpectedCC;
    U32 ReceivedCC;
} STPTI_ErrEventData_t;

typedef struct STPTI_BufferLevelData_s
{
    STPTI_Buffer_t BufferHandle;
    U32 FreeLength;
} STPTI_BufferLevelData_t;

typedef struct STPTI_MarkerEventData_s
{
    int                         Marker;                 /* this is enum ST_MM_Bitstream_Marker_t found in stmmdefs.h (not present in all SDKs) */
    U32                         MarkerID0;
    U32                         MarkerID1;
} STPTI_MarkerEventData_t;

typedef struct STPTI_DataEntryEventData_s
{
    STPTI_DataEntry_t DataEntryHandle;
} STPTI_DataEntryEventData_t;

typedef struct STPTI_EventData_s
{
    union
    {
        STPTI_PCREventData_t           PCREventData;
        STPTI_ErrEventData_t           ErrEventData;
        STPTI_IndexEventData_t         IndexEventData;
        STPTI_DataEntryEventData_t     DataEntryEventData;
        STPTI_BufferLevelData_t        BufferLevelData;
        STPTI_MarkerEventData_t        MarkerData;
    } u;

    ST_DeviceName_t  DeviceName;
    STPTI_Slot_t     SlotHandle;
    STPTI_Buffer_t   BufferHandle;
} STPTI_EventData_t;


typedef struct STPTI_PESFilter_s
{
    STPTI_TimeStamp_t *PTSValueMax_p;                   /**< (not supported) */
    STPTI_TimeStamp_t *DTSValueMax_p;                   /**< (not supported) */
    STPTI_TimeStamp_t *PTSValueMin_p;                   /**< (not supported) */
    STPTI_TimeStamp_t *DTSValueMin_p;                   /**< (not supported) */

    U8                 PesHeaderFlags;                  /**< (not supported) */
    U8                 PesHeaderFlagsMask;              /**< (not supported) */
    U8                 PesTrickModeFlags;               /**< (not supported) */
    U8                 PesTrickModeFlagsMask;           /**< (not supported) */
} STPTI_PESFilter_t;


typedef struct STPTI_PESStreamIDFilter_s
{
    U8 StreamID;                                        /**< Stream Id to match */
}STPTI_PESStreamIDFilter_t;


typedef struct STPTI_SectionFilter_s
{
    BOOL DiscardOnCrcError;                             /**< IGNORED ON STPTI5!  You must set this globally in Device Init Params */
    U8  *ModePattern_p;                                 /**< Indicate which Bits in FilterBytes are in a positive match sense (1) or a negative sense (0) */
    BOOL NotMatchMode;                                  /**< Enable DVB Version Not Match Mode */
    BOOL OverrideSSIBit;                                /**< Ignore Section Syntax Indicator (so that CRC checking is not done) */
} STPTI_SectionFilter_t;






typedef struct STPTI_FilterData_s
{
    STPTI_FilterType_t       FilterType;                                /**< Filter Type */
    STPTI_FilterRepeatMode_t FilterRepeatMode;                          /**< Must be set to STPTI_FILTER_REPEAT_MODE_STPTI_FILTER_REPEATED */
    BOOL                     InitialStateEnabled;                       /**< Should it be automatically enabled when associated? */
    U8                      *FilterBytes_p;                             /**< Pointer to Filter Bytes to match against */
    U8                      *FilterMasks_p;                             /**< Pointer to Filter Masks to indicate which bits in the FilterBytes are active */

    union
    {
        STPTI_SectionFilter_t        SectionFilter;
        STPTI_PESFilter_t            PESFilter;                         /**< (not supported) */
        STPTI_PESStreamIDFilter_t    PESStreamIDFilter;                 /**< PES Stream ID filtering (for PES slots) */
    } u;

} STPTI_FilterData_t;


typedef struct STPTI_InitParams_s
{
    U8                             DeviceIndex;                                 /**< Index of the physical device (for TANGO there is only one so should be set to 0) */
    STPTI_Protocol_t               Protocol;                                    /**< Transport Protocol */
    ST_Partition_t                *Partition_p;                                 /**< Partition for Driver Structure under OS21, ignored for STLinux */
    ST_DeviceName_t                EventHandlerName;                            /**< Name for Event Handler used when initialising STEVT (empty string if no STEVT needed) */
    STPTI_StreamID_t               StreamID;                                    /**< Input stream to connect to */
    U16                            NumberOfSlots;                               /**< Number of Slots available for collecting transport packets */
    BOOL                           DiscardOnCrcError;                           /**< OVERRIDE section filters control of CRC discard */
    U16                            NumberOfSectionFilters;                      /**< Number of section filters */
} STPTI_InitParams_t;


typedef struct STPTI_OpenParams_s
{
    ST_Partition_t *DriverPartition_p;                  /**< Partition for Objects under OS21, ignored for STLinux */
} STPTI_OpenParams_t;


typedef struct STPTI_SlotFlags_s
{
    BOOL SignalOnEveryTransportPacket;                  /**< Signal every transport packet for PES slots (not recommended) */
    BOOL CollectForAlternateOutputOnly;                 /**< (not supported) */
    BOOL AlternateOutputInjectCarouselPacket;           /**< (not supported) */
    BOOL StoreLastTSHeader;                             /**< (not supported) */
    BOOL InsertSequenceError;                           /**< (not supported) */
    BOOL OutPesWithoutMetadata;                         /**< Avoid output Metadata needed (means you can't use STPTI_BufferRead calls).  Now works for section slots too. */
    BOOL ForcePesLengthToZero;                          /**< (not supported) */
    BOOL AppendSyncBytePrefixToRawData;                 /**< (not supported) */
    BOOL SoftwareCDFifo;                                /**< (SW CD FIFO) Do not output Metadata needed for STPTI_BufferRead calls */
    BOOL DataEntryReplacement;                          /**< Slot is used to process data entries for packet replacement */
    BOOL DataEntryInsertion;                            /**< Slot is used to process data entries for packet insertion */
} STPTI_SlotFlags_t;


typedef struct STPTI_SlotData_s
{
    STPTI_SlotType_t SlotType;
    STPTI_SlotFlags_t SlotFlags;
} STPTI_SlotData_t;


typedef struct STPTI_Statistics_s
{
    U32 InputPacketCount;
    U32 ContinuityCountErrorCount;
    U32 TransportErrorCount;
} STPTI_Statistics_t;


typedef enum STPTI_Feature_e
{
    STPTI_FEATURE_MINIMUM_ENTRY,

    /* Buffer Features......................*/

    /* Descrambler Features.................*/

    /* Filter Features......................*/

    /* Session Features.....................*/

    /* Signal Features......................*/

    /* Slot Features........................*/
    STPTI_SLOT_FEATURE_DLNA_FORMATTED_OUTPUT,
    STPTI_SLOT_FEATURE_OUTPUT_WITH_TAG_BYTES,
    STPTI_SLOT_FEATURE_OUTPUT_BUFFER_PACKET_COUNT,
    /* Carousel Features....................*/
    STPTI_CAROUSEL_FEATURE_DLNA_FORMATTED_OUTPUT,

    /* Index Features.......................*/

    STPTI_FEATURE_MAXIMUM_ENTRY
}STPTI_Feature_t;

typedef struct STPTI_FeatureInfo_s
{
    STPTI_Feature_t Feature;
    void* Params_p;
} STPTI_FeatureInfo_t;

typedef union STPTI_TermParams_u
{
    BOOL ForceTermination;           /**< left only for legacy reasons */
    BOOL ForceTerminate;             /**< Force termination even if any objects are associated */
} STPTI_TermParams_t;

typedef struct STPTI_DataEntryLoadParams_s
{
    U8   RepeatNTimes;
    U8   *Data_p;
    U16  DataSize;
    U16  FromByte;
    BOOL EventOnOutput;
} STPTI_DataEntryLoadParams_t;


typedef enum STPTI_SecurityOutputNode_e
{
    STPTI_SECURITY_OUTPUT_NODE_CLEAR,
    STPTI_SECURITY_OUTPUT_NODE_SCRAMBLED
} STPTI_SecurityOutputNode_t;


#if defined( STPTI_IPRC_PRESENT )
typedef struct
{
	U32 CurrentWritePage;
	U32 CurrentWritePageIndex;
	ST_ScatterList_t*  ScatterList;
} STPTI_ScatterList_t;
#endif


/* Macros ------------------------------------------------------------------ */


#define STPTI_NullHandle()  ((STPTI_Handle_t)0xFFFFFFFF)
#define STPTI_WildCardPid() 0x2000
#define STPTI_InvalidPid()  0xe000



/* Exported Variables ------------------------------------------------------ */


/* Functions --------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

#if defined( STPTI_IPRC_PRESENT )
/* Export IPRC Stub handler */
STIPRC_DISPATCH_DECLARE(STPTI_Dispatch);
#endif

ST_Revision_t  STPTI_GetRevision(void);


/*** Device Level APIs *******************************************************/

ST_ErrorCode_t STPTI_Close(STPTI_Handle_t Handle);

ST_ErrorCode_t STPTI_Debug(ST_DeviceName_t DeviceName, char *DbgClass, char *String, int StringSize, int *Context_p);

ST_ErrorCode_t STPTI_DeviceDisableEvent(ST_DeviceName_t DeviceName, STPTI_Event_t EventName);
#define STPTI_DisableEvent STPTI_DeviceDisableEvent
#define STPTI_DisableErrorEvent STPTI_DeviceDisableEvent

ST_ErrorCode_t STPTI_DeviceEnableEvent(ST_DeviceName_t DeviceName, STPTI_Event_t EventName);
#define STPTI_EnableEvent STPTI_DeviceEnableEvent
#define STPTI_EnableErrorEvent STPTI_DeviceEnableEvent

ST_ErrorCode_t STPTI_DeviceGetCapability(ST_DeviceName_t DeviceName, STPTI_Capability_t * DeviceCapability_p);
#define STPTI_GetCapability STPTI_DeviceGetCapability

ST_ErrorCode_t STPTI_DeviceGetGlobalPacketCount(ST_DeviceName_t DeviceName, U32 *Count_p);
#define STPTI_GetGlobalPacketCount STPTI_DeviceGetGlobalPacketCount

ST_ErrorCode_t STPTI_DeviceGetInputPacketCount(ST_DeviceName_t DeviceName, U16 *Count_p);
#define STPTI_GetInputPacketCount STPTI_DeviceGetInputPacketCount

ST_ErrorCode_t STPTI_DeviceGetPacketArrivalTime(STPTI_Handle_t Handle, STPTI_TimeStamp_t * ArrivalTime_p, U16 *ArrivalTimeExtension_p);
#define STPTI_GetPacketArrivalTime STPTI_DeviceGetPacketArrivalTime

ST_ErrorCode_t STPTI_DeviceGetPacketErrorCount(ST_DeviceName_t DeviceName, U32 *Count_p);
#define STPTI_GetPacketErrorCount STPTI_DeviceGetPacketErrorCount

ST_ErrorCode_t STPTI_DeviceGetStatistics(ST_DeviceName_t DeviceName, STPTI_Statistics_t *Statistics_p);
#define STPTI_GetStatistics STPTI_DeviceGetStatistics

ST_ErrorCode_t STPTI_DeviceGetTimer(ST_DeviceName_t DeviceName, STPTI_TimeStamp_t * TimeStamp_p, U16 *TimeExtension_p);
#define STPTI_DeviceGetCurrentPTITimer( DeviceName, TimeStamp_p ) STPTI_DeviceGetTimer( DeviceName, TimeStamp_p, NULL )
#define STPTI_GetCurrentPTITimer( DeviceName, TimeStamp_p )       STPTI_DeviceGetTimer( DeviceName, TimeStamp_p, NULL )

ST_ErrorCode_t STPTI_DevicePause(ST_DeviceName_t DeviceName);
#define STPTI_HardwarePause STPTI_DevicePause

ST_ErrorCode_t STPTI_DevicePidQuery(ST_DeviceName_t DeviceName, STPTI_Pid_t Pid, U32 *SlotsMatchingPid_p, STPTI_Slot_t * Slot_p, U32 SizeOfSlotHandleArray);
#define STPTI_PidQuery STPTI_DevicePidQuery

ST_ErrorCode_t STPTI_DeviceReset(ST_DeviceName_t DeviceName);
#define STPTI_HardwareReset STPTI_DeviceReset

ST_ErrorCode_t STPTI_DeviceResetStatistics(ST_DeviceName_t DeviceName);
#define STPTI_ResetStatistics

ST_ErrorCode_t STPTI_DeviceResume(ST_DeviceName_t DeviceName);
#define STPTI_HardwareResume STPTI_DeviceResume

ST_ErrorCode_t STPTI_DeviceSetStreamID(ST_DeviceName_t DeviceName, STPTI_StreamID_t StreamID);
#define STPTI_SetStreamID STPTI_DeviceSetStreamID

ST_ErrorCode_t STPTI_DeviceSetPidSecurityPath(ST_DeviceName_t DeviceName, U16 Pid, U32 PathID);

ST_ErrorCode_t STPTI_DeviceLinkSecondaryPidToPrimaryPid(ST_DeviceName_t DeviceName, U16 SecondaryPid, U16 PrimaryPid, STPTI_SecondaryPidMode_t SecondaryPidMode, BOOL IgnoreCCErrors);

ST_ErrorCode_t STPTI_DeviceUnLinkSecondaryPidToPrimaryPid(ST_DeviceName_t DeviceName, U16 SecondaryPid, U16 PrimaryPid);

ST_ErrorCode_t STPTI_GetPresentationSTC(ST_DeviceName_t DeviceName, STPTI_Timer_t Timer, STPTI_TimeStamp_t * TimeStamp);

ST_ErrorCode_t STPTI_Init(ST_DeviceName_t DeviceName, const STPTI_InitParams_t * InitParams_p);

ST_ErrorCode_t STPTI_Open(ST_DeviceName_t DeviceName, const STPTI_OpenParams_t * OpenParams_p, STPTI_Handle_t * Handle_p);

ST_ErrorCode_t STPTI_SetDiscardParams(ST_DeviceName_t Device, U8 NumberOfDiscardBytes);

ST_ErrorCode_t STPTI_Term(ST_DeviceName_t DeviceName, const STPTI_TermParams_t * TermParams_p);



/*** STPTI Generic Object APIs ***********************************************/

ST_ErrorCode_t STPTI_ObjectDisableFeature(STPTI_Handle_t ObjectHandle, STPTI_Feature_t Feature);

ST_ErrorCode_t STPTI_ObjectEnableFeature(STPTI_Handle_t ObjectHandle, STPTI_FeatureInfo_t FeatureInfo);

ST_ErrorCode_t STPTI_ObjectGetDeviceName(STPTI_Handle_t ObjectHandle, ST_DeviceName_t *DeviceName_p);

ST_ErrorCode_t STPTI_ObjectTransferOwnership(STPTI_Handle_t OriginalHandle, STPTI_Handle_t PTISessionHandleToTransferTo, STPTI_Handle_t *NewHandle_p);



/*** STPTI Buffer Object APIs ************************************************/

ST_ErrorCode_t STPTI_BufferAllocate(STPTI_Handle_t Handle, U32 RequiredSize, U32 NumberOfPacketsInMultiPacket, STPTI_Buffer_t * BufferHandle_p);

ST_ErrorCode_t STPTI_BufferAllocateManual(STPTI_Handle_t Handle,U8* Base_p, U32 RequiredSize, U32 NumberOfPacketsInMultiPacket, STPTI_Buffer_t * BufferHandle_p);

ST_ErrorCode_t STPTI_BufferDeallocate(STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_BufferExtractData(STPTI_Buffer_t BufferHandle, U32 Offset, U32 NumBytesToExtract,
                                       U8 *Destination0_p, U32 DestinationSize0, U8 *Destination1_p,
                                       U32 DestinationSize1, U32 *DataSize_p, STPTI_Copy_t DmaOrMemCpy);

ST_ErrorCode_t STPTI_BufferExtractNBytes(STPTI_Buffer_t BufferHandle, U32 OffsetFromBufferBase, U32 NumBytesToExtract,
                                         U8 *Destination0_p, U32 DestinationSize0, U8 *Destination1_p,
                                         U32 DestinationSize1, U32 *DataSize_p, STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferExtractPartialPesPacketData(STPTI_Buffer_t BufferHandle, BOOL *PayloadUnitStart_p,
                                                       BOOL *CCDiscontinuity_p, U8 *ContinuityCount_p,
                                                       U16 *DataLength_p);

ST_ErrorCode_t STPTI_BufferExtractPesPacketData(STPTI_Buffer_t BufferHandle, U8 *PesFlags_p, U8 *TrickModeFlags_p,
                                                U32 *PESPacketLength_p, STPTI_TimeStamp_t * PTSValue_p,
                                                STPTI_TimeStamp_t * DTSValue_p);

ST_ErrorCode_t STPTI_BufferExtractSectionData(STPTI_Buffer_t BufferHandle, STPTI_Filter_t MatchedFilterList[],
                                              U16 MaxLengthofFilterList, U16 *NumOfFilterMatches_p, BOOL *CRCValid_p,
                                              U32 *SectionHeader_p);

ST_ErrorCode_t STPTI_BufferExtractTSHeaderData(STPTI_Buffer_t BufferHandle, U32 *TSHeader_p);

ST_ErrorCode_t STPTI_BufferFlush(STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_BufferGetFreeLength(STPTI_Buffer_t BufferHandle, U32 *FreeLength_p);

ST_ErrorCode_t STPTI_BufferGetWriteOffset(STPTI_Buffer_t BufferHandle, U32 *WriteOffset_p);

ST_ErrorCode_t STPTI_BufferGetWritePointer(STPTI_Buffer_t BufferHandle, void **Write_p);

ST_ErrorCode_t STPTI_BufferLevelChangeEvent(STPTI_Handle_t BufferHandle, BOOL Enable);

ST_ErrorCode_t STPTI_BufferLevelSignalEnable( STPTI_Buffer_t BufferHandle, U32 BufferLevelThreshold );

ST_ErrorCode_t STPTI_BufferLevelSignalDisable( STPTI_Buffer_t BufferHandle );

ST_ErrorCode_t STPTI_BufferPacketCount(STPTI_Buffer_t BufferHandle, U32 *Count_p);

ST_ErrorCode_t STPTI_BufferRead(STPTI_Buffer_t BufferHandle, U8 *Destination0_p, U32 DestinationSize0,
                                U8 *Destination1_p, U32 DestinationSize1, U32 *DataSize_p, STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferReadIndexEvent(STPTI_Buffer_t BufferHandle, STPTI_EventData_t *EventData_p, U32 Events2Return,
                                          void *Destination0_p, U32 DestinationSize0, void *Destination1_p,
                                          U32 DestinationSize1, U32 *EventsReturned_p, U32 *DataSize_p, STPTI_Copy_t DmaOrMemcpy );

ST_ErrorCode_t STPTI_BufferReadNBytes(STPTI_Buffer_t BufferHandle, U8 *Destination0_p, U32 DestinationSize0,
                                U8 *Destination1_p, U32 DestinationSize1, U32 *DataSize_p,
                                STPTI_Copy_t DmaOrMemcpy, U32 BytesToCopy);

ST_ErrorCode_t STPTI_BufferReadPartialPesPacket(STPTI_Buffer_t BufferHandle, U8 *Destination0_p, U32 DestinationSize0,
                                                U8 *Destination1_p, U32 DestinationSize1, BOOL *PayloadUnitStart_p,
                                                BOOL *CCDiscontinuity_p, U8 *ContinuityCount_p, U32 *DataSize_p,
                                                STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferReadPes(STPTI_Buffer_t BufferHandle, U8 *Destination0_p, U32 DestinationSize0,
                                   U8 *Destination1_p, U32 DestinationSize1, U32 *Datasize_p, STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferReadSection(STPTI_Buffer_t BufferHandle, STPTI_Filter_t MatchedFilterList[],
                                       U32 MaxLengthofFilterList, U32 *NumOfFilterMatches_p, BOOL *CRCValid_p,
                                       U8 *Destination0_p, U32 DestinationSize0, U8 *Destination1_p,
                                       U32 DestinationSize1, U32 *DataSize_p, STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferReadNSections(STPTI_Buffer_t BufferHandle, STPTI_Filter_t MatchedFilterList[], U32 MaxLengthofFilterList, U32 SectionsToReturn,
                                        U32 *SectionsReturned_p, U32 *NumOfFilterMatches_p, BOOL *CRCValid_p,
                                        U8 *Destination0_p, U32 DestinationSize0, U8 *Destination1_p, U32 DestinationSize1, U32 *DataSize_p, STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferReadTSPacket(STPTI_Buffer_t BufferHandle, U8 *Destination0_p, U32 DestinationSize0,
                                        U8 *Destination1_p, U32 DestinationSize1, U32 *DataSize_p,
                                        STPTI_Copy_t DmaOrMemcpy);

ST_ErrorCode_t STPTI_BufferSetMultiPacket(STPTI_Buffer_t BufferHandle, U32 NumberOfPacketsInMultiPacket);

ST_ErrorCode_t STPTI_BufferSetOverflowControl(STPTI_Buffer_t BufferHandle, BOOL OverwriteOnOverflow);

ST_ErrorCode_t STPTI_BufferSetReadOffset(STPTI_Buffer_t BufferHandle, U32 ReadOffset);

ST_ErrorCode_t STPTI_BufferSetReadPointer(STPTI_Buffer_t BufferHandle, void* Read_p);

ST_ErrorCode_t STPTI_BufferTestForData(STPTI_Buffer_t BufferHandle, U32 *BytesInBuffer_p);

ST_ErrorCode_t STPTI_BufferUnLink(STPTI_Buffer_t Buffer);



/*** STPTI Data Entry Object APIs ********************************************/

ST_ErrorCode_t STPTI_DataEntryAllocate( STPTI_Handle_t SessionHandle, U8 NumTSPackets, STPTI_DataEntry_t * DataEntryHandle_p );

ST_ErrorCode_t STPTI_DataEntryDeallocate( STPTI_DataEntry_t DataEntryHandle );

ST_ErrorCode_t STPTI_DataEntryLoad( STPTI_DataEntry_t DataEntryHandle, STPTI_Slot_t SlotHandle, STPTI_DataEntryLoadParams_t * Params_p );

ST_ErrorCode_t STPTI_DataEntryRemove( STPTI_DataEntry_t DataEntryHandle,  STPTI_Slot_t SlotHandle );



/*** STPTI Filter Object APIs ************************************************/

ST_ErrorCode_t STPTI_FilterAllocate(STPTI_Handle_t Handle, STPTI_FilterType_t FilterType,
                                    STPTI_Filter_t * FilterObject_p);

ST_ErrorCode_t STPTI_FilterAssociate(STPTI_Filter_t FilterHandle, STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_FilterDeallocate(STPTI_Filter_t FilterHandle);

ST_ErrorCode_t STPTI_FilterDisassociate(STPTI_Filter_t FilterHandle, STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_FilterSet(STPTI_Filter_t FilterHandle, STPTI_FilterData_t * FilterData_p);

ST_ErrorCode_t STPTI_FiltersFlush(STPTI_Buffer_t BufferHandle, STPTI_Filter_t Filters[], U16 NumOfFiltersToFlush);

ST_ErrorCode_t STPTI_FiltersEnable(STPTI_Filter_t FiltersToDisable[], U16 NumOfFiltersToDisable,
                                   STPTI_Filter_t  FiltersToEnable[], U16 NumOfFiltersToEnable);
#define STPTI_ModifyGlobalFilterState STPTI_FiltersEnable


/*** STPTI Index Object APIs *************************************************/

ST_ErrorCode_t STPTI_IndexAllocate(STPTI_Handle_t SessionHandle, STPTI_Index_t * IndexHandle_p);

ST_ErrorCode_t STPTI_IndexAssociate(STPTI_Index_t IndexHandle, STPTI_Slot_t SlotHandle, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_IndexAssociateWithPid(STPTI_Index_t IndexHandle, U16 Pid, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_IndexDeallocate(STPTI_Index_t IndexHandle);

ST_ErrorCode_t STPTI_IndexDisassociate(STPTI_Index_t IndexHandle, STPTI_Slot_t SlotHandle, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_IndexDisassociateWithPid(STPTI_Index_t IndexHandle, U16 Pid, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_IndexChain(STPTI_Index_t *IndexHandles, U32 NumberOfHandles);

ST_ErrorCode_t STPTI_IndexSet(STPTI_Index_t IndexHandle, STPTI_IndexDefinition_t IndexMask);

ST_ErrorCode_t STPTI_IndexSetStartCode(STPTI_Index_t IndexHandle, U32 *StartCodeMask, STPTI_IndexingStartCodeMode_t Mode);
#define STPTI_HelperSetStartCodeMask(StartCodeMask, StartCode) StartCodeMask[StartCode/32] |= (1<<(StartCode%32))

ST_ErrorCode_t STPTI_IndexReset(STPTI_Index_t IndexHandle);

ST_ErrorCode_t STPTI_IndexStart(ST_DeviceName_t DeviceName);

ST_ErrorCode_t STPTI_IndexStop(ST_DeviceName_t DeviceName);



/*** STPTI Software Injection Object APIs ************************************/

ST_ErrorCode_t STPTI_InjectorAllocate( STPTI_Handle_t SessionHandle, STPTI_Injector_t  *InjectorHandle_p );

ST_ErrorCode_t STPTI_InjectorDeallocate( STPTI_Injector_t InjectorHandle );

ST_ErrorCode_t STPTI_InjectorInjectBlock( STPTI_Injector_t InjectorHandle, U8 *Block_p, U32 BlockSize, STPTI_InjectorInputTagging_t Tagging );

ST_ErrorCode_t STPTI_InjectorInjectData( STPTI_Injector_t InjectorHandle, STPTI_InjectorNode_t *InjectorNode_p, U32 NumberOfNodes, STPTI_InjectorInputTagging_t Tagging );

ST_ErrorCode_t STPTI_InjectorFlush( STPTI_Injector_t InjectorHandle );



/*** STPTI Signal Object APIs ************************************************/

ST_ErrorCode_t STPTI_SignalAbort(STPTI_Signal_t SignalHandle);

ST_ErrorCode_t STPTI_SignalAllocate(STPTI_Handle_t Handle, STPTI_Signal_t * SignalHandle_p);

ST_ErrorCode_t STPTI_SignalAssociateBuffer(STPTI_Signal_t SignalHandle, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_SignalDeallocate(STPTI_Signal_t SignalHandle);

ST_ErrorCode_t STPTI_SignalDisassociateBuffer(STPTI_Signal_t SignalHandle, STPTI_Buffer_t BufferHandle);

ST_ErrorCode_t STPTI_SignalWaitBuffer(STPTI_Signal_t SignalHandle, STPTI_Buffer_t * BufferHandle_p, U32 TimeoutMS);



/*** STPTI Slot Object APIs **************************************************/

ST_ErrorCode_t STPTI_DisableScramblingEvents(STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_EnableScramblingEvents(STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_SlotGetBuffers(STPTI_Slot_t SlotHandle, STPTI_Buffer_t *BufferHandle_p, STPTI_Buffer_t *RecordBufferHandle_p);
#define STPTI_GetBuffersFromSlot STPTI_SlotGetBuffers

ST_ErrorCode_t STPTI_SlotAllocate(STPTI_Handle_t Handle, STPTI_Slot_t * SlotHandle_p, STPTI_SlotData_t * SlotData_p);

ST_ErrorCode_t STPTI_SlotCancelForceSCB(STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_SlotClearPid( STPTI_Slot_t SlotHandle );

ST_ErrorCode_t STPTI_SlotDeallocate(STPTI_Slot_t SlotHandle);

ST_ErrorCode_t STPTI_SlotDescramblingControl(STPTI_Slot_t SlotHandle, BOOL EnableDescramblingControl);

ST_ErrorCode_t STPTI_SlotDisableEvent(STPTI_Slot_t SlotHandle, STPTI_Event_t EventName);

ST_ErrorCode_t STPTI_SlotEnableEvent(STPTI_Slot_t SlotHandle, STPTI_Event_t EventName);

ST_ErrorCode_t STPTI_SlotForceSCB(STPTI_Slot_t SlotHandle, STPTI_SCBits_t In, STPTI_SCBits_t Out);

ST_ErrorCode_t STPTI_SlotLinkToBuffer(STPTI_Slot_t Slot, STPTI_Buffer_t Buffer);

ST_ErrorCode_t STPTI_SlotLinkToRecordBuffer(STPTI_Slot_t Slot, STPTI_Buffer_t Buffer, BOOL DescrambleTS);

ST_ErrorCode_t STPTI_SlotLinkSecondaryToPrimary(STPTI_Slot_t SecondarySlotHandle, STPTI_Slot_t PrimarySlotHandle, STPTI_SecondaryPidMode_t SecondaryPidMode );

ST_ErrorCode_t STPTI_SlotUnLinkSecondaryToPrimary(STPTI_Slot_t SecondarySlotHandle, STPTI_Slot_t PrimarySlotHandle );

ST_ErrorCode_t STPTI_SlotPacketCount(STPTI_Slot_t SlotHandle, U16 *Count_p);

ST_ErrorCode_t STPTI_SlotQuery(STPTI_Slot_t SlotHandle, BOOL *PacketsSeen_p, BOOL *TransportScrambledPacketsSeen_p,
                               BOOL *PESScrambledPacketsSeen_p, STPTI_Pid_t * Pid_p);

ST_ErrorCode_t STPTI_SlotSetCCControl(STPTI_Slot_t SlotHandle, BOOL IgnoreCCErrors);

ST_ErrorCode_t STPTI_SlotSetCorruptionParams(STPTI_Slot_t SlotHandle, U8 Offset, U8 Value);

ST_ErrorCode_t STPTI_SlotSetSecurityOutputNode(STPTI_Slot_t SlotHandle, STPTI_SecurityOutputNode_t OutputNode);

ST_ErrorCode_t STPTI_SlotSetPid(STPTI_Slot_t SlotHandle, STPTI_Pid_t Pid);

ST_ErrorCode_t STPTI_SlotSetPidAndRemap( STPTI_Slot_t SlotHandle, STPTI_Pid_t InputPid, STPTI_Pid_t OutputPid );

ST_ErrorCode_t STPTI_SlotState(STPTI_Slot_t SlotHandle, U32 *SlotCount_p, STPTI_ScrambleState_t * ScrambleState_p, STPTI_Pid_t * Pid_p);

ST_ErrorCode_t STPTI_SlotUnLink(STPTI_Slot_t Slot);

ST_ErrorCode_t STPTI_SlotUnLinkRecordBuffer(STPTI_Slot_t Slot);

ST_ErrorCode_t STPTI_SlotUpdatePid( STPTI_Slot_t SlotHandle, STPTI_Pid_t Pid );



/*** STPTI TSInput Object APIs ***********************************************/

ST_ErrorCode_t STPTI_TSInputConfigure( STPTI_StreamID_t StreamID, STPTI_TSInputParams_t *Params_p );

ST_ErrorCode_t STPTI_TSInputEnable( STPTI_StreamID_t StreamID, BOOL Enable );

ST_ErrorCode_t STPTI_TSInputReset( STPTI_StreamID_t StreamID );

ST_ErrorCode_t STPTI_TSInputGetStatus( STPTI_StreamID_t StreamID, STPTI_TSInputStatus_t *Status_p );






#ifdef __cplusplus
}
#endif

#endif /* #if !defined( _stptiHAL_ ) */

#endif /* #ifndef _STPTI_H_ */
