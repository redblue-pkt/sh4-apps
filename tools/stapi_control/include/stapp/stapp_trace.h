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
 * @file     stapp_trace.h
 * @brief    This is the stapi sdk trace system file header.
 *           It is used to display debug traces coming from sdk components.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_TRACE_H_
#define _STAPP_TRACE_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Prototypes */
/* ---------- */
#define TRACE_PRINT
ST_ErrorCode_t TRACE_Init(U32 DeviceId);
ST_ErrorCode_t TRACE_Term(U32 DeviceId);
ST_ErrorCode_t TRACE_Print(const char *format,...);
ST_ErrorCode_t TRACE_Report(U32 ReportLevel,const char *format,...);
ST_ErrorCode_t TRACE_StartTime(void);
ST_ErrorCode_t TRACE_StopTime(void);
ST_ErrorCode_t TRACE_Control(BOOL OnOff);
ST_ErrorCode_t TRACE_Watch(BOOL OnOff);
ST_ErrorCode_t TRACE_HddOpen(char *FileName);
ST_ErrorCode_t TRACE_HddClose(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

