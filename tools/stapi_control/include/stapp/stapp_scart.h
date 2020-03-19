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
 * @file     stapp_scart.h
 * @brief    This is the scart file header.
 *           It is used to control europe tv scart connectors and cvs/svhs cinch connectors.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_SCART_H_
#define _STAPP_SCART_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define SCART_MAX_NUMBER 1
#endif
#if defined(sat5189)
/* No scart support */
#endif
#if defined(sat7111)
/* No scart support */
#endif
#if defined(adi7108)
/* No scart support */
#endif
#if defined(hdk5251)
#define SCART_MAX_NUMBER 2
#endif
#if defined(hdk5289)
#define SCART_MAX_NUMBER 2
#endif
#if defined(hdk7108)
#if (HARDWARE_REVISION<3)
#define SCART_MAX_NUMBER 2
#endif
#endif
#if defined(hdk7111)
#define SCART_MAX_NUMBER 2
#endif
#if defined(b2039)
/* No scart support */
#endif
#if defined(b2057)
#define SCART_MAX_NUMBER 1
#endif
#if defined(b2064)
#define SCART_MAX_NUMBER 1
#endif
#if defined(b2067)
#define SCART_MAX_NUMBER 1
#endif
#if defined(dp2010)
#define SCART_MAX_NUMBER 1
#endif
#if defined(dp7000)
#define SCART_MAX_NUMBER 1
#endif
#if defined(dp7001)
#define SCART_MAX_NUMBER 1
#endif
#if defined(dp7050)
#define SCART_MAX_NUMBER 1
#endif
#if defined(fx6010)
#define SCART_MAX_NUMBER 1
#endif
#if defined(ep8000)
#define SCART_MAX_NUMBER 1
#endif
#if defined(epp8000)
#define SCART_MAX_NUMBER 1
#endif
#if defined(gpv8000)
#define SCART_MAX_NUMBER 1
#endif
#if defined(b2075)
#define SCART_MAX_NUMBER 1
#endif
#if defined(b2076)
/* No scart support */
#endif
#if defined(mb618)
#define SCART_MAX_NUMBER 1
#endif
#if defined(mb628)
/* No scart support */
#endif
#if defined(mb628e)
/* No scart support */
#endif
#if defined(eud7141)
#define SCART_MAX_NUMBER 2
#endif
#if defined(hdkh225)
#define SCART_MAX_NUMBER 1
#endif
#if defined(mb676)
#define SCART_MAX_NUMBER 1
#endif
#if defined(mb680)
/* No scart support */
#endif
#if defined(mb704)
#define SCART_MAX_NUMBER 1
#endif
#if defined(mb796)
/* No scart support */
#endif
#if defined(mb837)
/* No scart support */
#endif
#if defined(mb903)
/* No scart support */
#endif
#if defined(b2066)
/* No scart support */
#endif
#if defined(hmp7105)
/* No scart support */
#endif
#if defined(sdk7105)
#define SCART_MAX_NUMBER 2
#endif
#if defined(kourou)
/* No scart support */
#endif
#if defined(isdb7102)
/* No scart support */
#endif
#if defined(iptv7105)
/* No scart support */
#endif
#if defined(b2068)
#define SCART_MAX_NUMBER 1
#endif
#if defined(hdk7167)
#define SCART_MAX_NUMBER 1
#endif
#if defined(ngb7167)
/* No scart support */
#endif
#if defined(hdk7197)
#define SCART_MAX_NUMBER 1
#endif
#if defined(hdkh251)
#define SCART_MAX_NUMBER 1
#endif
#if defined(dtt5267)
#define SCART_MAX_NUMBER 2
#endif
#if defined(b2049)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom001030)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom001034)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom001035)
/* No scart support */
#endif
#if defined(custom001036)
#define SCART_MAX_NUMBER 2
#endif
#if defined(custom001039)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom002005)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom002006)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom002007)
/* No scart support */
#endif
#if defined(custom002008)
#define SCART_MAX_NUMBER 2
#endif
#if defined(custom003008)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom003009)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom003011)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom003012)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom003015)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom003018)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom018001)
/* No scart support */
#endif
#if defined(custom021001)
#define SCART_MAX_NUMBER 1
#endif
#if defined(custom022001)
/* No scart support */
#endif

/* Includes */
/* -------- */
#if defined(SCART_MAX_NUMBER)
#include "stgxobj.h"
#include "sti2c.h"
#include "stvout.h"
#endif

/* Definitions */
/* ----------- */
#if defined(SCART_MAX_NUMBER)
typedef enum SCART_TV_AspectRatio_e
{
 SCART_TV_ASPECT_RATIO_4_3  = STGXOBJ_ASPECT_RATIO_4TO3,
 SCART_TV_ASPECT_RATIO_16_9 = STGXOBJ_ASPECT_RATIO_16TO9
} SCART_TV_AspectRatio_t;
#endif

/* Definitions of the scart ouput */
/* ------------------------------ */
/* TODO: This is a VOUT configuration rather than a SCART one, this should be moved to VOUT */
typedef enum SCART_Format_e
{
 SCART_CVBS     = 1,
 SCART_RGB      = 2,
 SCART_YPRPB    = 4,
 SCART_YC       = 8,
 SCART_YPRPB_SD = 16
} SCART_Format_t;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t SCART_Init(void);
ST_ErrorCode_t SCART_Term(void);
#if defined(SCART_MAX_NUMBER)
ST_ErrorCode_t SCART_SetAspectRatio(U32 DeviceId,SCART_TV_AspectRatio_t  SCART_TV_AspectRatio);
ST_ErrorCode_t SCART_GetAspectRatio(U32 DeviceId,SCART_TV_AspectRatio_t *SCART_TV_AspectRatio);
#endif
ST_ErrorCode_t SCART_SetColorFormat(U32 DeviceId,SCART_Format_t  SCART_Format);
ST_ErrorCode_t SCART_GetColorFormat(U32 DeviceId,SCART_Format_t *SCART_Format);


/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

