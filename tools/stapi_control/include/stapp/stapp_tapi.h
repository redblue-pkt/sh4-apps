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
 * @file     stapp_tapi.h
 * @brief    This is the dvb-si sections filter header file.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TAPI_H_
#define _STAPP_TAPI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stddefs.h"

/* Defaults PIDs */
/* ------------- */
#define STTAPI_PAT_PID          0x0000
#define STTAPI_CAT_PID          0x0001
#define STTAPI_NIT_PID          0x0010
#define STTAPI_SDT_PID          0x0011
#define STTAPI_BAT_PID          0x0011
#define STTAPI_EIT_PID          0x0012
#define STTAPI_TDT_PID          0x0014
#define STTAPI_TOT_PID          0x0014

/* Tables IDs */
/* ---------- */
#define STTAPI_PAT_TABLE_ID     0x00  /* Program Association Table */
#define STTAPI_CAT_TABLE_ID     0x01  /* Conditional Access Table */
#define STTAPI_PMT_TABLE_ID     0x02  /* Program Map Table */
#define STTAPI_NIT_TABLE_ID     0x40  /* Network Info Table (actual transport) */
#define STTAPI_NITO_TABLE_ID    0x41  /* Network Info Table (other transport) */
#define STTAPI_SDT_TABLE_ID     0x42  /* Service Descriptor Table (actual transport) */
#define STTAPI_SDTO_TABLE_ID    0x46  /* Service Descriptor Table (other transport) */
#define STTAPI_BAT_TABLE_ID     0x4a  /* Bouquet Association Table */
#define STTAPI_EIT_TABLE_ID     0x4e  /* Event Information Table (actual transport) */
#define STTAPI_EITO_TABLE_ID    0x4f  /* Event Information Table (other transport) */
#define STTAPI_TDT_TABLE_ID     0x70  /* Time Date Table */
#define STTAPI_RST_TABLE_ID     0x71  /* Running Status Table */
#define STTAPI_ST_TABLE_ID      0x72  /* Stuffing Table */
#define STTAPI_TOT_TABLE_ID     0x73  /* Time Offset Table */
#define STTAPI_SCTE_TABLE_ID    0xC6  /* SCTE Subtitle Table */
#define STTAPI_INVALID_TABLE    0x100 /* Invalid Table */

/* Enum to avoid to filter some particular fields */
/* ---------------------------------------------- */
#define STTAPI_FILTER_DONT_CARE 0x80000000
#define STTAPI_FILTER_AUTOMATIC 0x40000000

/* Stream Types */
/* ------------ */
typedef enum
{
 STTAPI_STREAM_RESERVED         = 0x00,
 STTAPI_STREAM_VIDEO_MPEG1      = 0x01,
 STTAPI_STREAM_VIDEO_MPEG2      = 0x02,
 STTAPI_STREAM_AUDIO_MPEG1      = 0x03,
 STTAPI_STREAM_AUDIO_MPEG2      = 0x04,
 STTAPI_STREAM_PRIVATE_SECTIONS = 0x05,
 STTAPI_STREAM_PRIVATE_PES      = 0x06,
 STTAPI_STREAM_MHEG             = 0x07,
 STTAPI_STREAM_DSM_CC           = 0x08,
 STTAPI_STREAM_TYPE_H2221       = 0x09,
 STTAPI_STREAM_TYPE_A           = 0x0A,
 STTAPI_STREAM_TYPE_B           = 0x0B,
 STTAPI_STREAM_TYPE_C           = 0x0C,
 STTAPI_STREAM_TYPE_D           = 0x0D,
 STTAPI_STREAM_TYPE_AUX         = 0x0E,
 STTAPI_STREAM_AUDIO_AAC_ADTS   = 0x0F,
 STTAPI_STREAM_VIDEO_MPEG4P2    = 0x10,
 STTAPI_STREAM_AUDIO_AAC_LATM   = 0x11,
 STTAPI_STREAM_AUDIO_AAC_RAW1   = 0x12,
 STTAPI_STREAM_AUDIO_AAC_RAW2   = 0x13,
 STTAPI_STREAM_VIDEO_MPEG4      = 0x1B,
 STTAPI_STREAM_VIDEO_AVS        = 0x42,
 STTAPI_STREAM_AUDIO_LPCM       = 0x80,
 STTAPI_STREAM_AUDIO_AC3        = 0x81,
 STTAPI_STREAM_AUDIO_DTS        = 0x82,
 STTAPI_STREAM_AUDIO_MLP        = 0x83,
 STTAPI_STREAM_AUDIO_DDPLUS     = 0x84,
 STTAPI_STREAM_AUDIO_DTSHD      = 0x85,
 STTAPI_STREAM_AUDIO_DTSHD_XLL  = 0x86,
 STTAPI_STREAM_AUDIO_DDPLUS_2   = 0xA1,
 STTAPI_STREAM_AUDIO_DTSHD_2    = 0xA2,
 STTAPI_STREAM_VIDEO_VC1        = 0xEA,
 STTAPI_STREAM_AUDIO_WMA        = 0xE6
} STTAPI_StreamType_t;

/* Descriptor Types */
/* ---------------- */
typedef enum
{
 STTAPI_DESCRIPTOR_VIDEO_STREAM                 = 0x02,
 STTAPI_DESCRIPTOR_AUDIO_STREAM                 = 0x03,
 STTAPI_DESCRIPTOR_HIERARCHY                    = 0x04,
 STTAPI_DESCRIPTOR_REGISTRATION                 = 0x05,
 STTAPI_DESCRIPTOR_DATA_STREAM_ALIGNMENT        = 0x06,
 STTAPI_DESCRIPTOR_TARGET_BACKGROUND_GRID       = 0x07,
 STTAPI_DESCRIPTOR_VIDEO_WINDOW                 = 0x08,
 STTAPI_DESCRIPTOR_CA                           = 0x09,
 STTAPI_DESCRIPTOR_LANGUAGE_NAME                = 0x0A,
 STTAPI_DESCRIPTOR_SYSTEM_CLOCK                 = 0x0B,
 STTAPI_DESCRIPTOR_MULTIPLEX_BUFFER             = 0x0C,
 STTAPI_DESCRIPTOR_COPYRIGHT                    = 0x0D,
 STTAPI_DESCRIPTOR_MAX_BITRATE                  = 0x0E,
 STTAPI_DESCRIPTOR_PRIVATE_DATA_INDICATOR       = 0x0F,
 STTAPI_DESCRIPTOR_SMOOTHING_BUFFER             = 0x10,
 STTAPI_DESCRIPTOR_STD                          = 0x11,
 STTAPI_DESCRIPTOR_IBP                          = 0x12,
 STTAPI_DESCRIPTOR_CAROUSEL_IDENTIFIER          = 0x13,
 STTAPI_DESCRIPTOR_ASSOCIATION_TAG              = 0x14,
 STTAPI_DESCRIPTOR_DEFERRED_ASSOCIATION_TAG     = 0x15,
 STTAPI_DESCRIPTOR_RESERVED_16                  = 0x16,
 STTAPI_DESCRIPTOR_NPT_REFERENCE                = 0x17,
 STTAPI_DESCRIPTOR_NPT_ENDPOINT                 = 0x18,
 STTAPI_DESCRIPTOR_STREAM_MODE                  = 0x19,
 STTAPI_DESCRIPTOR_STREAM_EVENT                 = 0x1A,
 STTAPI_DESCRIPTOR_MPEG4_VIDEO                  = 0x1B,
 STTAPI_DESCRIPTOR_MPEG4_AUDIO                  = 0x1C,
 STTAPI_DESCRIPTOR_MPEG4_IOD                    = 0x1D,
 STTAPI_DESCRIPTOR_MPEG4_SL                     = 0x1E,
 STTAPI_DESCRIPTOR_MPEG4_FMC                    = 0x1F,
 STTAPI_DESCRIPTOR_MPEG4_EXTERNAL_ES_ID         = 0x20,
 STTAPI_DESCRIPTOR_MPEG4_MUX_CODE               = 0x21,
 STTAPI_DESCRIPTOR_MPEG4_FMX_BUFFER_SIZE        = 0x22,
 STTAPI_DESCRIPTOR_MPEG4_MULTIPLEX_BUFFER       = 0x23,
 STTAPI_DESCRIPTOR_MPEG4_CONTENT_LABELING       = 0x24,
 STTAPI_DESCRIPTOR_TVA_METADATA_POINTER         = 0x25,
 STTAPI_DESCRIPTOR_TVA_METADATA                 = 0x26,
 STTAPI_DESCRIPTOR_TVA_METADATA_STD             = 0x27,
 STTAPI_DESCRIPTOR_AVC_VIDEO                    = 0x28,
 STTAPI_DESCRIPTOR_AVC_IPMP                     = 0x29,
 STTAPI_DESCRIPTOR_AVC_TIMING_AND_HRD           = 0x2A,
 STTAPI_DESCRIPTOR_NETWORK_NAME                 = 0x40,
 STTAPI_DESCRIPTOR_SERVICE_LIST                 = 0x41,
 STTAPI_DESCRIPTOR_STUFFING                     = 0x42,
 STTAPI_DESCRIPTOR_SATELLITE_DELIVERY_SYSTEM    = 0x43,
 STTAPI_DESCRIPTOR_CABLE_DELIVERY_SYSTEM        = 0x44,
 STTAPI_DESCRIPTOR_VBI_DATA                     = 0x45,
 STTAPI_DESCRIPTOR_VBI_TELETEXT                 = 0x46,
 STTAPI_DESCRIPTOR_BOUQUET_NAME                 = 0x47,
 STTAPI_DESCRIPTOR_SERVICE                      = 0x48,
 STTAPI_DESCRIPTOR_COUNTRY_AVAIBILITY           = 0x49,
 STTAPI_DESCRIPTOR_LINKAGE                      = 0x4A,
 STTAPI_DESCRIPTOR_NVOD_REFERENCE               = 0x4B,
 STTAPI_DESCRIPTOR_TIME_SHIFTED                 = 0x4C,
 STTAPI_DESCRIPTOR_SHORT_EVENT                  = 0x4D,
 STTAPI_DESCRIPTOR_EXTENDED_EVENT               = 0x4E,
 STTAPI_DESCRIPTOR_TIME_SHIFTED_EVENT           = 0x4F,
 STTAPI_DESCRIPTOR_COMPONENT                    = 0x50,
 STTAPI_DESCRIPTOR_MOSAIC                       = 0x51,
 STTAPI_DESCRIPTOR_STREAM_IDENTIFIER            = 0x52,
 STTAPI_DESCRIPTOR_CA_IDENTIFIER                = 0x53,
 STTAPI_DESCRIPTOR_CONTENT                      = 0x54,
 STTAPI_DESCRIPTOR_PARENTAL_RATING              = 0x55,
 STTAPI_DESCRIPTOR_TELETEXT                     = 0x56,
 STTAPI_DESCRIPTOR_TELEPHONE                    = 0x57,
 STTAPI_DESCRIPTOR_LOCAL_TIME_OFFSET            = 0x58,
 STTAPI_DESCRIPTOR_SUBTITLING                   = 0x59,
 STTAPI_DESCRIPTOR_TERRESTRIAL_DELIVERY_SYSTEM  = 0x5A,
 STTAPI_DESCRIPTOR_MULTILINGUAL_NETWORK_NAME    = 0x5B,
 STTAPI_DESCRIPTOR_MULTILINGUAL_BOUQUET_NAME    = 0x5C,
 STTAPI_DESCRIPTOR_MULTILINGUAL_SERVICE_NAME    = 0x5D,
 STTAPI_DESCRIPTOR_COMPONENT_SERVICE_NAME       = 0x5E,
 STTAPI_DESCRIPTOR_PRIVATE_DATA_SPECIFIER       = 0x5F,
 STTAPI_DESCRIPTOR_SERVICE_MOVE                 = 0x60,
 STTAPI_DESCRIPTOR_SHORT_SMOOTHING_BUFFER       = 0x61,
 STTAPI_DESCRIPTOR_FREQUENCY_LIST               = 0x62,
 STTAPI_DESCRIPTOR_PARTIAL_TRANSPORT_STREAM     = 0x63,
 STTAPI_DESCRIPTOR_DATA_BROADCAST               = 0x64,
 STTAPI_DESCRIPTOR_CA_SYSTEM                    = 0x65,
 STTAPI_DESCRIPTOR_DATA_BROADCAST_ID            = 0x66,
 STTAPI_DESCRIPTOR_TRANSPORT_STREAM             = 0x67,
 STTAPI_DESCRIPTOR_DSNG                         = 0x68,
 STTAPI_DESCRIPTOR_PDC                          = 0x69,
 STTAPI_DESCRIPTOR_AC3                          = 0x6A,
 STTAPI_DESCRIPTOR_ANCILLARY_DATA               = 0x6B,
 STTAPI_DESCRIPTOR_CELL_LIST                    = 0x6C,
 STTAPI_DESCRIPTOR_CELL_FREQUENCY_LINK          = 0x6D,
 STTAPI_DESCRIPTOR_ANNOUNCEMENT_SUPPORT         = 0x6E,
 STTAPI_DESCRIPTOR_APPLICATION_SIGNALLING       = 0x6F,
 STTAPI_DESCRIPTOR_ADAPTATION_FIELD_DATA        = 0x70,
 STTAPI_DESCRIPTOR_SERVICE_IDENTIFIER           = 0x71,
 STTAPI_DESCRIPTOR_SERVICE_AVAILABILITY         = 0x72,
 STTAPI_DESCRIPTOR_TVA_DEFAULT_AUTHORITY        = 0x73,
 STTAPI_DESCRIPTOR_TVA_RELATED_CONTENT          = 0x74,
 STTAPI_DESCRIPTOR_TVA_ID                       = 0x75,
 STTAPI_DESCRIPTOR_TVA_CONTENT_IDENTIFIER       = 0x76,
 STTAPI_DESCRIPTOR_TIMESLICING_FEC_IDENTIFIER   = 0x77,
 STTAPI_DESCRIPTOR_ECM_REPETITION_RATE          = 0x78,
 STTAPI_DESCRIPTOR_S2_SATELLITE_DELIVERY_SYSTEM = 0x79,
 STTAPI_DESCRIPTOR_ENHANCED_AC3                 = 0x7A,
 STTAPI_DESCRIPTOR_DTS                          = 0x7B,
 STTAPI_DESCRIPTOR_AAC                          = 0x7C,
 STTAPI_DESCRIPTOR_XAIT_LOCATION                = 0x7D,
 STTAPI_DESCRIPTOR_FTA_CONTANT_MANAGEMENT       = 0x7E,
 STTAPI_DESCRIPTOR_EXTENSION                    = 0x7F
} STTAPI_DescriptorType_t;

/* SDT status */
/* ---------- */
typedef enum
{
 STTAPI_SDT_UNDEFINED            = 0,
 STTAPI_SDT_NOT_RUNNING          = 1,
 STTAPI_SDT_START_IN_FEW_SECONDS = 2,
 STTAPI_SDT_PAUSING              = 3,
 STTAPI_SDT_RUNNING              = 4,
 STTAPI_SDT_RESERVED_5           = 5,
 STTAPI_SDT_RESERVED_6           = 6,
 STTAPI_SDT_RESERVED_7           = 7
} STTAPI_SDTStatus_t;

/* Descriptor Element */
/* ------------------ */
typedef struct
{
 STTAPI_DescriptorType_t Tag;
 U8                      Size;
 U8                     *Data;
} STTAPI_Descriptor_t;

/* PMT Element */
/* ----------- */
typedef struct
{
 U16                  Pid;
 STTAPI_StreamType_t  Type;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
} STTAPI_PMTElement_t;

/* PAT Element */
/* ----------- */
typedef struct
{
 U16 ProgramNumber;
 U16 Pid;
} STTAPI_PATElement_t;

/* SDT Element */
/* ----------- */
typedef struct
{
 U16                  ServiceId;
 BOOL                 EIT_Schedule_Flag;
 BOOL                 EIT_PresentFollowing_Flag;
 STTAPI_SDTStatus_t   Status;
 BOOL                 Scrambled;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
} STTAPI_SDTElement_t;

/* NIT Element */
/* ----------- */
typedef struct
{
 U16                  TransportStreamId;
 U16                  OriginalNetWorkId;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
} STTAPI_NITElement_t;

/* EIT Element */
/* ----------- */
typedef struct
{
 U16                  EventId;
 struct               {U8 Day;  U8 Month;  U16 Year; U8 Hour; U8 Minute; U8 Second;} StartTime;
 struct               {U8 Hour; U8 Minute; U8 Second;} Duration;
 STTAPI_SDTStatus_t   Status;
 BOOL                 Scrambled;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
} STTAPI_EITElement_t;

/* PAT */
/* --- */
typedef struct
{
 U16                  TransportStreamId;
 U32                  NbElements;
 STTAPI_PATElement_t *Element;
} STTAPI_PATData_t;

/* PMT */
/* --- */
typedef struct
{
 U16                  PcrPid;
 U16                  ProgramNumber;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
 U32                  NbElements;
 STTAPI_PMTElement_t *Element;
 BOOL                 Scrambled;
} STTAPI_PMTData_t;

/* NIT */
/* --- */
typedef struct
{
 U16                  NetWorkId;
 U32                  NbDescriptors;
 STTAPI_Descriptor_t *Descriptor;
 U32                  NbElements;
 STTAPI_NITElement_t *Element;
} STTAPI_NITData_t;

/* SDT */
/* --- */
typedef struct
{
 U16                  TransportStreamId;
 U16                  OriginalNetWorkdId;
 U32                  NbElements;
 STTAPI_SDTElement_t *Element;
} STTAPI_SDTData_t;

/* EIT */
/* --- */
typedef struct
{
 U16                  ServiceId;
 U16                  TransportStreamId;
 U16                  OriginalNetWorkdId;
 U32                  NbElements;
 STTAPI_EITElement_t *Element;
} STTAPI_EITData_t;

/* TDT */
/* --- */
typedef struct
{
 U8  Day;    /* Day value   [1-31] */
 U8  Month;  /* Month value [1-12] */
 U16 Year;   /* Year (ie : 2008)   */
 U8  Hour;   /* Hour [0-23]        */
 U8  Minute; /* Minute [0-59]      */
 U8  Second; /* Minute [0-59]      */
} STTAPI_TDTData_t;

/* Prototypes for table extraction */
/* ------------------------------- */
#if defined(OSPLUS)||defined(ST_OSLINUX)
ST_ErrorCode_t STTAPI_XXX_AcquireFile(U8 *FileName,U16 Pid,U32 TableId,U32 ProgramNumber,U32 SectionNumber,U32 CurrentNotNext,U8 *Buffer,U32 BufferSize,U32 *ReadSize);
#endif
ST_ErrorCode_t STTAPI_XXX_Acquire(U32 PTI_DeviceId,U16 Pid,U32 TableId,U32 ProgramNumber,U32 SectionNumber,U32 CurrentNotNext,U8 *Buffer,U32 BufferSize,U32 *ReadSize);
ST_ErrorCode_t STTAPI_PAT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_PATData_t *TableData);
ST_ErrorCode_t STTAPI_PMT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_PMTData_t *TableData);
ST_ErrorCode_t STTAPI_SDT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_SDTData_t *TableData);
ST_ErrorCode_t STTAPI_NIT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_NITData_t *TableData);
ST_ErrorCode_t STTAPI_EIT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_EITData_t *TableData);
ST_ErrorCode_t STTAPI_TDT_Acquire(U32 PTI_DeviceId,U16 Pid,STTAPI_TDTData_t *TableData);
ST_ErrorCode_t STTAPI_PAT_Delete(STTAPI_PATData_t *TableData);
ST_ErrorCode_t STTAPI_PMT_Delete(STTAPI_PMTData_t *TableData);
ST_ErrorCode_t STTAPI_SDT_Delete(STTAPI_SDTData_t *TableData);
ST_ErrorCode_t STTAPI_NIT_Delete(STTAPI_NITData_t *TableData);
ST_ErrorCode_t STTAPI_EIT_Delete(STTAPI_EITData_t *TableData);
ST_ErrorCode_t STTAPI_TDT_Delete(STTAPI_TDTData_t *TableData);

/* Toolkit to manage descriptors and other stufs */
/* --------------------------------------------- */
ST_ErrorCode_t STTAPI_ContentTypeToString    (STTAPI_PMTElement_t *Element   ,U8  *ContentTypeString,U8 *Details);
ST_ErrorCode_t STTAPI_DescriptorService      (STTAPI_Descriptor_t *Descriptor,U8  *ProviderName,U8 *ServiceName,U8 *ServiceType);
ST_ErrorCode_t STTAPI_DescriptorTeletext     (STTAPI_Descriptor_t *Descriptor,U8  *Language,U8 *Type,U8 *Magazine,U8 *Page);
ST_ErrorCode_t STTAPI_DescriptorSubtitle     (STTAPI_Descriptor_t *Descriptor,U8  *Language,U8 *Type,U16 *Composition_Id,U16 *Ancillary_Id);
ST_ErrorCode_t STTAPI_DescriptorLanguageName (STTAPI_Descriptor_t *Descriptor,U8  *Language);
ST_ErrorCode_t STTAPI_DescriptorRegistration (STTAPI_Descriptor_t *Descriptor,U8  *FormatIdentifier);
ST_ErrorCode_t STTAPI_DescriptorNetworkName  (STTAPI_Descriptor_t *Descriptor,U8  *NetworkName);
ST_ErrorCode_t STTAPI_DescriptorSatellite    (STTAPI_Descriptor_t *Descriptor,U32 *Frequency,U8 *Modulation,U32 *SymbolRate,U8 *Polarization,U8 *Fec,U16 *OrbitalPosition,BOOL *WestNoEast);
ST_ErrorCode_t STTAPI_DescriptorCable        (STTAPI_Descriptor_t *Descriptor,U32 *Frequency,U8 *Modulation,U32 *SymbolRate,U8 *Fec_In,U8 *Fec_Out);
ST_ErrorCode_t STTAPI_DescriptorTerrestrial  (STTAPI_Descriptor_t *Descriptor,U32 *Frequency,U8 *Bandwith,U8 *Guard_Interval,U8 *Fec_HP,U8 *Fec_LP,U8 *Transmission_Mode);
ST_ErrorCode_t STTAPI_DescriptorShortEvent   (STTAPI_Descriptor_t *Descriptor,U8  *Language,U8 *EventName,U8 *EventDescription);
ST_ErrorCode_t STTAPI_DescriptorAC3          (STTAPI_Descriptor_t *Descriptor,U8  *ComponentType,U8 *MainId,U8 *Asvc,U8 *Bsid);
ST_ErrorCode_t STTAPI_DescriptorEnhancedAC3  (STTAPI_Descriptor_t *Descriptor,U8  *ComponentType,U8 *MainId,U8 *Asvc,U8 *Bsid,U8 *SubStream1,U8 *SubStream2,U8 *SubStream3);
ST_ErrorCode_t STTAPI_CopyPrintable          (U8 *Destination,U8 *Source,U32 Max);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
