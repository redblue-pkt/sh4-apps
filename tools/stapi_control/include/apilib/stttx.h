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
 @File   sttx.h
 @brief



*/


#ifndef _STTX_H
#define _STTX_H

#include "stlite.h"
#include "stos.h"
#include "stevt.h"
#include "stavmem.h"
#include "stddefs.h"
#include "stcommon.h"
#include "stclkrv.h"
#include "stfdma.h"
#include "sttbx.h"
#include "stinject.h"

#ifdef __cplusplus
    extern "C" {
#endif

#if defined (ST_5197)
#define TTX_FEATURE_GDMA
#endif

#if !defined(TTX_FEATURE_GDMA)
#define TTX_FEATURE_FDMA
#endif

#define ST_MAX_DEVICE_NAME_TOCOPY                   (ST_MAX_DEVICE_NAME-1)  /* 15 characters used in strcpy */
#define STTTX_DRIVER_ID                             3
#define STTTX_DRIVERID_BASE_BIT_POS                 16
#define STTTX_DRIVER_BASE                           (STTTX_DRIVER_ID << STTTX_DRIVERID_BASE_BIT_POS)

#define STTTX_MAX_INSTANCE                          2

#if defined(TTX_FEATURE_GDMA)
#define STTTX_LINESIZE                              48 /*BYTES*/
#elif defined(TTX_FEATURE_FDMA)
#define STTTX_LINESIZE                              44 /*BYTES*/
#endif

#define STTTX_MAXLINES                              16

/* Should be less than 32 as we maintain a mask of U32 type  */
#define STTTX_FILTER_MAX_REQUESTS                   20

#define STTTX_FREE_REQUEST_TAG                      0x1FFFFFFF
    /* Error return codes */

#define STTTX_ERROR_BASE                            STTTX_DRIVER_BASE

typedef U32                                         STTTX_Handle_t;

typedef enum STTTX_DriverId_e
{
    STTTX_INSTANCE_0 = STTTX_DRIVER_BASE,
    STTTX_INSTANCE_MAX
}STTTX_DriverId_t;


typedef enum STTTX_ErrorCode_e
{
    STTTX_ERROR_GET_MEMORY = STTTX_DRIVER_BASE,
    STTTX_ERROR_START_FAILED,
    STTTX_ERROR_STOP_FAILED,
    STTTX_ERROR_INVALID_STATE,
    STTTX_ERROR_IO_REMAP_FAILED,
    STTTX_ERROR_MAP_MEMORY,
    STTTX_ERROR_REQUEST_TAG_IN_USE,
    STTTX_ERROR_REQUEST_QUEUE_FULL
}STTTX_ErrorCode_t;

typedef enum STTTX_FeildParity_e
{
    STTTX_FIELD_TOP = 0,
    STTTX_FIELD_BOTTOM,
} STTTX_FieldParity_t;

typedef enum STTTX_DataSource_e
{
    STTTX_DATA_SOURCE_PTI = 0x0,
    STTTX_DATA_SOURCE_STINJECT = 0x1,
    STTTX_DATA_SOURCE_USER_THREAD = 0x2
}STTTX_DataSource_t;

typedef enum STTTX_EventType_e
{
    /*Parser Dependent Events*/
    STTTX_EVT_NEW_FIELD = 1,
    STTTX_EVT_SKIP_PES,
    STTTX_EVT_DATA_UNDEFLOW,
    /*Rendrer dependent Events*/
    STTTX_EVT_IP_ENABLED ,
    STTTX_EVT_FIELD_DELIVERED
}STTTX_EventType_t;

typedef enum STTTX_Mode_e
{
    STTTX_MODE_VBI , /* Driver will output the TTX data through DENC*/
    STTTX_MODE_STB , /* Driver will provide the TTX data to the application trhough callback function*/
    STTTX_MODE_STB_VBI , /* Driver will provide the TTX data to both application and DENC*/
}STTTX_Mode_t;


/* Filter criteria definition */
typedef enum STTTX_FilterType_e
{
    STTTX_FILTER_ANY = 0,                            /* Filter on any teletext packet */
    STTTX_FILTER_MAGAZINE  = 1,                      /* Filter on specified magazine  */
    STTTX_FILTER_PAGE      = 2,                      /* Filter on specified page      */
    STTTX_FILTER_SUBPAGE   = 4,                      /* Filter on specified subpage   */
    STTTX_FILTER_PACKET_0  = 8,                      /* Filter on X/0 packet          */
    STTTX_FILTER_PACKET_30 = 16,                     /* Filter on X/30 packet         */
    STTTX_FILTER_PAGE_COMPLETE_ODD = 32,         /* Filter on complete page odd field */
    STTTX_FILTER_PAGE_COMPLETE_EVEN= 64              /* Filter on complete page, even */
} STTTX_FilterType_t;

/*
Presently no events.
But in future we would require few events specially for NDs requirements
*/


typedef struct STTTX_InitParams_s
{
    ST_DeviceName_t                     EVTDeviceName;
    ST_DeviceName_t                     VTGDeviceName;
    ST_DeviceName_t                     VMIXDeviceName;
    ST_DeviceName_t                     DENCDeviceName;
    ST_DeviceName_t                     CLKRVDeviceName;
    ST_Partition_t                      *CPUPartition_p;
    STAVMEM_PartitionHandle_t           AVMEMPartition;
    STTTX_Mode_t                        Mode;
} STTTX_InitParams_t;

/* Termination parameters */

typedef struct STTTX_TermParams_s
{
    BOOL                    ForceTerminate;
}STTTX_TermParams_t;

/* Open parameters */

typedef struct STTTX_OpenParams_s
{
    STTTX_Mode_t      Mode;                       /* output destination         */
}STTTX_OpenParams_t;



typedef struct STTTX_BufferParams_s
{
    void                                *BufferBaseAddr_p;
    U32                                 BufferSize;
    U32                                 NumBuffers;
    STTTX_Handle_t                      Handle;
}STTTX_BufferParams_t;

typedef struct STTTX_FieldExtndInfo_s
{
    U8          DataUnitId[STTTX_MAXLINES]; /* Teletext subtitle or no subtitles */
    U8          PTSValid;
    U8          PTSBit33;
    U32         PTS;
}STTTX_FieldExtndInfo_t;


typedef struct STTTX_Field_s
{
    U32                                 ValidLines;                                     /* bit-field lines  0..31     */
    U8                                  Lines[STTTX_MAXLINES][STTTX_LINESIZE];
    STTTX_FieldParity_t                 FieldType;
    STTTX_FieldExtndInfo_t              ExtndInfo;
} STTTX_Field_t;

typedef void          (*STTTX_RequestCallbackFunc_t)(U32 Tag, STTTX_Field_t *Field);

typedef struct STTTX_Request_s
{
    U32                     RequestTag;                 /*Unique id for a request     */
    STTTX_FilterType_t      RequestType;                /* Filter flags               */
    U32                     MagazineNumber;
    U32                     PageNumber;
    U32                     PageSubCode;
    U32                     PacketMask;                 /* type of packet required    */
    STTTX_Field_t           *Field;                     /* odd  page assembly struc index 0 */
                                                        /* even page assembly struc index 1 */
    STTTX_RequestCallbackFunc_t NotifyFunc_fp;
} STTTX_Request_t;


typedef ST_ErrorCode_t          (*STTTX_GetWriteAddr_t)(void * const Handle, void** const Address_p);
typedef ST_ErrorCode_t          (*STTTX_UpdateReadAddr_t)(void * const Handle, void* const Address);


typedef struct STTTX_ParserInterface_s
{
    STTTX_GetWriteAddr_t             GetWriteAddr_fp;
    STTTX_UpdateReadAddr_t           UpdateReadAddr_fp;
    void                             *Handle;
} STTTX_ParserInterface_t;

typedef enum STTTX_InterfaceCommand_e
{
    STTTX_FILTER_CALLBACK_UPDATE = 0

} STTTX_InterfaceCommand_t;



ST_Revision_t  STTTX_GetRevision(void);
ST_ErrorCode_t STTTX_Init(const ST_DeviceName_t DeviceName, STTTX_InitParams_t *InitParams_p);
ST_ErrorCode_t STTTX_Open(const ST_DeviceName_t DeviceName,  STTTX_OpenParams_t *OpenParam_p, STTTX_Handle_t *Handle_p);
ST_ErrorCode_t STTTX_Start(STTTX_Handle_t Handle);
ST_ErrorCode_t STTTX_Stop(STTTX_Handle_t Handle);
ST_ErrorCode_t STTTX_Close(const STTTX_Handle_t Handle);
ST_ErrorCode_t STTTX_Term(const ST_DeviceName_t DeviceName, const STTTX_TermParams_t *TermParam_p);
ST_ErrorCode_t STTTX_GetInputBufferParams(const STTTX_Handle_t Handle, STTTX_BufferParams_t *TTX_BufferParams_p);
ST_ErrorCode_t STTTX_SetDataInputInterface(STTTX_Handle_t Handle, STTTX_ParserInterface_t *ParserInterface_p);
ST_ErrorCode_t STTTX_DeleteDataInputInterface(STTTX_Handle_t Handle, STTTX_ParserInterface_t *ParserInterface_p);
ST_ErrorCode_t STTTX_SetRequest( STTTX_Handle_t  Handle, STTTX_Request_t *Request_p );
ST_ErrorCode_t STTTX_ClearRequest( STTTX_Handle_t  Handle, STTTX_Request_t *Request_p);
ST_ErrorCode_t STTTX_SetSyncOffset(STTTX_Handle_t  Handle, U32 Offset);
ST_ErrorCode_t STTTX_ModeChange(const STTTX_Handle_t Handle, STTTX_Mode_t Mode);
ST_ErrorCode_t STTTX_EnableSync(STTTX_Handle_t  Handle, U8 EnableSync);
ST_ErrorCode_t STTTX_GetBufferFreeSize(STTTX_Handle_t Handle, U32 *Size_p);


#if defined(ST_OSLINUX)
ST_ErrorCode_t STTTX_UnmapBufferFromUserSpace(STTTX_BufferParams_t* DataParams_p);
ST_ErrorCode_t STTTX_MapBufferToUserSpace(STTTX_BufferParams_t* DataParams_p);
ST_ErrorCode_t STTTX_SetInterface( STTTX_Handle_t Handle, STTTX_InterfaceCommand_t cmd, U32 arg );
#endif


/*TBD*/
/*
ST_ErrorCode_t STTTX_SetDataIdentifier(STTTX_Handle_t  Handle,U8 DataIdentifier );
ST_ErrorCode_t STTTX_GetDataIdentifier(STTTX_Handle_t  Handle,U8 *DataIdentifier_p );

*/


#ifdef __cplusplus
}
#endif

#endif /*_STTX_H*/
