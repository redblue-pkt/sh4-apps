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
 * @file     stapp_demux.h
 * @brief    This is the demultiplexer and transport interface file header.
 *           It is used to route and to filter transport streams containers.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_DEMUX_H_
#define _STAPP_DEMUX_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
#define TSMERGER_MAX_NUMBER 1
/*#define TSMERGER_BYPASS*/
#define PTI_MAX_NUMBER 3
#endif
#if defined(ST_5206)
#define TSMERGER_MAX_NUMBER 1
/*#define TSMERGER_BYPASS*/
#define PTI_MAX_NUMBER 3
#endif
#if defined(ST_7105)
#define TSMERGER_MAX_NUMBER 1
/*#define TSMERGER_BYPASS*/
#define PTI_MAX_NUMBER 6
#endif
#if defined(ST_7108)
#define TSTANGO_MAX_NUMBER 1
#define PTI_MAX_NUMBER 6
#endif
#if defined(ST_7111)
#define TSMERGER_MAX_NUMBER 1
/*#define TSMERGER_BYPASS*/
#define PTI_MAX_NUMBER 3
#endif
#if defined(ST_7141)
#define TSMERGER_MAX_NUMBER 2
/*#define TSMERGER_BYPASS*/
#define PTI_MAX_NUMBER 6
#endif
#if defined(ST_H205)
#define TSTANGO_MAX_NUMBER 1
#define PTI_MAX_NUMBER 6
#endif
/* By default, all architectures can collect up to 4 Pes in the same times */
#define PTI_PESCOLLECT_MAX_NUMBER 4

/* Includes */
/* -------- */
#if defined(TSMERGER_MAX_NUMBER)
#include "stmerge.h"
#endif
#if defined(PTI_MAX_NUMBER)
#include "stpti.h"
#endif

/* Check DVR coherency */
/* ------------------- */
#if defined(TSMERGER_BYPASS)&&defined(DVR)
#error "For DVR application, TS Merger has to be in normal mode, please modify the code !"
#endif

/* Enum wrapper */
/* ------------ */
#if defined(TSMERGER_MAX_NUMBER)
#if defined(ST_5197)
#define DEMUX_TSIN_0  STMERGE_TSIN_0
#define DEMUX_TSIN_1  STMERGE_TSIN_1
#define DEMUX_TSIN_2  STMERGE_TSIN_2
#define DEMUX_SWTS_0  STMERGE_SWTS_0
#define DEMUX_SWTS_1  STMERGE_SWTS_1
#define DEMUX_SWTS_2  STMERGE_SWTS_2
#define DEMUX_PTI_0   STMERGE_PTI_0
#define DEMUX_PTI_1   STMERGE_PTI_1
#define DEMUX_NO_DEST STMERGE_NO_DEST
#endif
#if defined(ST_5206)||defined(ST_7105)||defined(ST_7111)||defined(ST_7141)
#define DEMUX_TSIN_0  STMERGE_TSIN_0
#define DEMUX_TSIN_1  STMERGE_TSIN_1
#define DEMUX_TSIN_2  STMERGE_TSIN_2
#define DEMUX_TSIN_3  STMERGE_TSIN_3
#define DEMUX_SWTS_0  STMERGE_SWTS_0
#define DEMUX_SWTS_1  STMERGE_SWTS_1
#define DEMUX_SWTS_2  STMERGE_SWTS_2
#define DEMUX_PTI_0   STMERGE_PTI_0
#define DEMUX_PTI_1   STMERGE_PTI_1
#define DEMUX_NO_DEST STMERGE_NO_DEST
#if defined(ST_7141)
#define CCSC_TSIN_0   STMERGE2_TSIN_0
#define CCSC_TSIN_1   STMERGE2_TSIN_1
#define CCSC_TSIN_2   STMERGE2_TSIN_2
#define CCSC_SWTS_0   STMERGE2_SWTS_0
#define CCSC_SWTS_1   STMERGE2_SWTS_1
#define CCSC_SWTS_2   STMERGE2_SWTS_2
#endif
#endif
#endif
#if defined(TSTANGO_MAX_NUMBER)
#if defined(ST_7108)||defined(ST_H205)
#define DEMUX_NONE    STPTI_STREAM_ID_NONE
#define DEMUX_TSIN_0  STPTI_STREAM_ID_TSIN0
#define DEMUX_TSIN_1  STPTI_STREAM_ID_TSIN1
#define DEMUX_TSIN_2  STPTI_STREAM_ID_TSIN2
#define DEMUX_TSIN_3  STPTI_STREAM_ID_TSIN3
#define DEMUX_TSIN_4  STPTI_STREAM_ID_TSIN4
#define DEMUX_TSIN_5  STPTI_STREAM_ID_TSIN5
/*#define DEMUX_TSCA_0  STPTI_STREAM_ID_TSCA0*/
/*#define DEMUX_TSCA_1  STPTI_STREAM_ID_TSCA1*/
#define DEMUX_NO_DEST 0xCAFE0000
#define DEMUX_PTI_0   0xCAFE0001
#define DEMUX_PTI_1   0xCAFE0002
#endif
#endif

/* Demux statistics structure */
/* -------------------------- */
typedef struct DEMUX_Statistics_s
{
 U32 Buffer_overflow_evt;
 U32 Carousel_cycle_complete_evt;
 U32 Carousel_entry_timeout_evt;
 U32 Carousel_timed_entry_evt;
 U32 Cc_error_evt;
 U32 Clear_to_scrambled_evt;
 U32 Cwp_block_evt;
 U32 Dma_complete_evt;
 U32 Index_match_evt;
 U32 Interrupt_fail_evt;
 U32 Invalid_descramble_key_evt;
 U32 Invalid_link_evt;
 U32 Invalid_parameter_evt;
 U32 Packet_error_evt;
 U32 Pcr_received_evt;
 U32 Scrambled_to_clear_evt;
 U32 Sections_discarded_on_crc_check_evt;
 U32 Tc_code_fault_evt;
 U32 Pes_error_evt;
 U32 Unknow_evt;
 U32 Input_PacketCount;
 U32 Cc_ErrorCount;
 U32 Ts_ErrorCount;
} DEMUX_Statistics_t;

/* External declarations */
/* --------------------- */
extern STPTI_Handle_t   PTI_Handle[PTI_MAX_NUMBER];
extern STPTI_StreamID_t PTI_PhysicalConnection[PTI_MAX_NUMBER];
extern STPTI_StreamID_t PTI_LogicalConnection[PTI_MAX_NUMBER];

/* Prototypes */
/* ---------- */
ST_ErrorCode_t  DEMUX_Init(void);
ST_ErrorCode_t  DEMUX_Term(void);
ST_ErrorCode_t  DEMUX_Connect(ST_DeviceName_t PTI_DeviceName,U32 TS_Source,U32 TS_Destination);
ST_ErrorCode_t  DEMUX_ConnectGet(U32 TS_Source,U32 *TS_Destination,U32 *PTI_DeviceId);
ST_ErrorCode_t  DEMUX_ConnectSet(U32 TS_Source,U32  TS_Destination,U32  PTI_DeviceId,BOOL *ParallelNotSerial,BOOL *InvertBitClock);
ST_ErrorCode_t  DEMUX_GetStatistics(ST_DeviceName_t PTI_DeviceName,DEMUX_Statistics_t *Statistics);
ST_ErrorCode_t  DEMUX_ResetStatistics(ST_DeviceName_t PTI_DeviceName,DEMUX_Statistics_t *Statistics);
#if defined(OSPLUS)||defined(ST_OSLINUX)
ST_ErrorCode_t  DEMUX_PesCollectStart(U32 PES_DeviceId,U8 *FileName,U32 PTI_DeviceId,U32 PidToCollect);
ST_ErrorCode_t  DEMUX_PesCollectStop(U32 PES_DeviceId);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

