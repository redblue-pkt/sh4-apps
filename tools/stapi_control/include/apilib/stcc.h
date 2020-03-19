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
 @File   stcc.h
 @brief



*/


#ifndef __STCC_H
#define __STCC_H


/******************************************************************************/
/* Modules includes                                                           */
/******************************************************************************/
#include "stddefs.h"


#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
/* Public constants                                                           */
/******************************************************************************/
#define  STCC_DRIVER_ID         136                              /* Driver ID */
#define  STCC_DRIVER_BASE       (STCC_DRIVER_ID << 16)

enum                                                      /* STCC Error Codes */
{
    STCC_ERROR_DECODER_RUNNING = STCC_DRIVER_BASE
  , STCC_ERROR_DECODER_STOPPED
  , STCC_ERROR_VBI_UNKNOWN
  , STCC_ERROR_VBI_ACCESS
  , STCC_ERROR_EVT_REGISTER
  , STCC_ERROR_EVT_UNREGISTER
  , STCC_ERROR_EVT_SUBSCRIBE
  , STCC_ERROR_TASK_CALL
  , STCC_ERROR_VTG_UNKNOWN
  , STCC_ERROR_EVT_UNKNOWN
  , STCC_ERROR_VID_UNKNOWN
};

enum                                                         /* STCC Event ID */
{
    STCC_DATA_TO_BE_PRESENTED_EVT = STCC_DRIVER_BASE
};


/******************************************************************************/
/* Public types                                                               */
/******************************************************************************/
typedef enum STCC_FormatMode_e
{
    STCC_FORMAT_MODE_DETECT          =   0
  , STCC_FORMAT_MODE_DTVVID21        =   1
  , STCC_FORMAT_MODE_EIA708          =   2
  , STCC_FORMAT_MODE_DVS157          =   4
  , STCC_FORMAT_MODE_UDATA130        =   8
  , STCC_FORMAT_MODE_EIA608          =  16
  , STCC_FORMAT_MODE_DVB             =  32
  , STCC_FORMAT_MODE_ITU_T35         =  64
  , STCC_FORMAT_MODE_SCTE128         = 128                                  /* User Data - SCTE 128 */
  , STCC_FORMAT_MODE_ATSC            = 256                                  /* User Data - A/53, Part 4 */
  , STCC_FORMAT_MODE_SCTE20          = STCC_FORMAT_MODE_EIA608              /* User Data - SCTE 20 */
  , STCC_FORMAT_MODE_SCTE21          = STCC_FORMAT_MODE_EIA708              /* User Data - SCTE 21 */
  , STCC_FORMAT_MODE_DTV_MPEG2       = STCC_FORMAT_MODE_DTVVID21            /* User Data - DTV MPEG-2 Video */
  , STCC_FORMAT_MODE_DTV_AVC         = STCC_FORMAT_MODE_ITU_T35             /* User Data - DTV AVC Video */

} STCC_FormatMode_t;

typedef enum STCC_OutputMode_e
{
    STCC_OUTPUT_MODE_NONE            =  0
  , STCC_OUTPUT_MODE_DENC            =  1
  , STCC_OUTPUT_MODE_EVENT           =  2
  , STCC_OUTPUT_MODE_DTV_BMP         =  4       /* Not supported */
  , STCC_OUTPUT_MODE_UART_DECODED    =  8       /* Not supported */

} STCC_OutputMode_t;

typedef struct STCC_Data_s
{
    U8                  Values[2];              /* cc_data1 and cc_data2 */
    STCC_FormatMode_t   FormatMode;             /* Reference to standard */
    U32                 Field;                  /* cc_type */
                                                /* 00 NTSC line 21 field 1 closed captions */
                                                /* 01 NTSC line 21 field 2 closed captions */
                                                /* 10 DTVCC Channel Packet Data */
                                                /* 11 DTVCC Channel Packet Start */

} STCC_Data_t;

typedef U32 STCC_Handle_t;

typedef struct STCC_InitParams_s
{
    ST_Partition_t*   CPUPartition_p;           /* Driver memory pool */
    U32               MaxOpen;                  /* Maximum allowed clients */
    ST_DeviceName_t   EvtHandlerName;           /* STEVT instance used for notification */
    ST_DeviceName_t   VBIName;                  /* STVBI instance used for closed caption rendering */
    ST_DeviceName_t   VIDName;                  /* STVID instance providing user data */
    ST_DeviceName_t   VTGName;                  /* STVTG instance used for synchronization */

} STCC_InitParams_t;

typedef struct STCC_OpenParams_s
{
    U32   Dummy;                                /* Not used */

} STCC_OpenParams_t;

typedef struct STCC_TermParams_s
{
    BOOL  ForceTerminate;                       /* TRUE to close all opened handles */

} STCC_TermParams_t;


/******************************************************************************/
/* Public macros                                                              */
/******************************************************************************/

/******************************************************************************/
/* Public functions prototypes                                                */
/******************************************************************************/
ST_Revision_t   STCC_GetRevision( void );

ST_ErrorCode_t  STCC_Init
                    ( const ST_DeviceName_t             DeviceName
                    , const STCC_InitParams_t * const   InitParams_p
                    );
ST_ErrorCode_t  STCC_Term
                    ( const ST_DeviceName_t             DeviceName
                    , const STCC_TermParams_t * const   TermParams_p
                    );
ST_ErrorCode_t  STCC_Open
                    ( const ST_DeviceName_t             DeviceName
                    , const STCC_OpenParams_t * const   OpenParams_p
                    , STCC_Handle_t * const             Handle_p
                    );
ST_ErrorCode_t  STCC_Close
                    ( const STCC_Handle_t               Handle
                    );
ST_ErrorCode_t  STCC_SetFormatMode
                    ( const STCC_Handle_t               Handle
                    , const STCC_FormatMode_t           FormatMode
                    );
ST_ErrorCode_t  STCC_GetFormatMode
                    ( const STCC_Handle_t               Handle
                    , STCC_FormatMode_t * const         FormatMode_p
                    );
ST_ErrorCode_t  STCC_SetOutputMode
                    ( STCC_Handle_t const               Handle
                    , const STCC_OutputMode_t           OutputMode
                    );
ST_ErrorCode_t  STCC_GetOutputMode
                    ( STCC_Handle_t const               Handle
                    , STCC_OutputMode_t* const          OutputMode_p
                    );
ST_ErrorCode_t  STCC_Start
                    ( const STCC_Handle_t               Handle
                    );
ST_ErrorCode_t  STCC_Stop
                    ( const STCC_Handle_t               Handle
                    );


#ifdef __cplusplus
}
#endif

#endif /* #ifndef __STCC_H */
