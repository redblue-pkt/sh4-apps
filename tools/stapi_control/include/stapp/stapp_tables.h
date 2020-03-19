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
 * @file     stapp_tables.h
 * @brief    This is the generic section filter header file.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TABLES_H_
#define _STAPP_TABLES_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes */
/* -------- */
#include "stddefs.h"
#include "stpti.h"

/* Constant definitions */
/* -------------------- */
#define STTABLE_DONT_CARE 0x80000000

/* Handle type */
/* ----------- */
typedef void *STTABLE_Handle_t;

/* Init params type */
/* ---------------- */
typedef struct
{
 STPTI_Handle_t     PtiHandle;
 STPTI_SlotType_t   SlotType;
 STPTI_FilterType_t FilterType;
 U32                PtiBufferSize;
 S32                ProcessPriority;
} STTABLE_InitParams_t;

/* Term params type */
/* ---------------- */
typedef struct
{
 U32 NotUsed;
} STTABLE_TermParams_t;

/* Open params type */
/* ---------------- */
typedef struct
{
 U32 NotUsed;
} STTABLE_OpenParams_t;

/* Status type */
/* ----------- */
typedef enum
{
 STTABLE_OK,
 STTABLE_CRC_FAILED,
 STTABLE_ABORTED,
 STTABLE_TIME_OUT,
 STTABLE_ERROR
} STTABLE_Status_t;

/* Service type */
/* ------------ */
typedef enum
{
 STTABLE_DVB,
 STTABLE_DTV,
 STTABLE_A3
} STTABLE_Service_t;

/* Start params type */
/* ----------------- */
typedef struct
{
 STTABLE_Service_t ServiceType;     /* Service type for which filter needs to be set      */
 U8               *Buffer_p;        /* Buffer pointer to receive the section              */
 U32               BufferSize;      /* Size of the buffer to receive the section          */
 U32               TimeOut;         /* Timeout in milliseconds (1000=1s)                  */
 U16               Pid;             /* Pid to filter                                      */
 U32               Table_Id;        /* Table Id to filter                                 */
#if defined(SERVICE_DTV)||defined(SERVICE_A3)
 U32               Network_Id;      /* Network ID to filter                               */
 U32               CarouselsBitmap; /* Carosel Bitmap to filter                           */
#endif
#if defined(SERVICE_DTV)
 U32               Protocol_Ver;    /* ProtocolVersion to filter                          */
#endif
 U32               Program_Number;  /* Program Number to filter                           */
 U32               Version_Number;  /* Version Number to filter                           */
 U32               Current_NotNext; /* Current or next to filter indicator                */
 U32               Section_Number;  /* Section Number to filter                           */
 BOOL              NotMatchMode;    /* Filter is negative mode                            */
 void             *UserParam_p;     /* Parameter of the user                              */
 void            (*CallBack_p)(void *UserParam_p,STTABLE_Status_t Status,U32 Size); /* Callback function when section received */
 STTABLE_Status_t  Returned_Status; /* This parameter is used if no callback is specified */
 U32               Returned_Size;   /* This parameter is used if no callback is specified */
} STTABLE_StartParams_t;

/* Prototypes */
/* ---------- */
ST_Revision_t  STTABLE_GetRevision(void);
ST_ErrorCode_t STTABLE_Init(ST_DeviceName_t DeviceName,STTABLE_InitParams_t *InitParams);
ST_ErrorCode_t STTABLE_Open(ST_DeviceName_t DeviceName,STTABLE_OpenParams_t *OpenParams,STTABLE_Handle_t *Handle);
ST_ErrorCode_t STTABLE_Close(STTABLE_Handle_t Handle);
ST_ErrorCode_t STTABLE_Start(STTABLE_Handle_t Handle,STTABLE_StartParams_t *StartParams);
ST_ErrorCode_t STTABLE_Stop(STTABLE_Handle_t Handle);
ST_ErrorCode_t STTABLE_Term(ST_DeviceName_t DeviceName,STTABLE_TermParams_t *TermParams);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

