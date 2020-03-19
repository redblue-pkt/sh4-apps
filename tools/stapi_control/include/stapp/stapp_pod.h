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
 * @file     stapp_pod.h
 * @brief    This is the cable-card file header.
 *           It is used to access cable-card (mainly used by cable/docsis platforms).
 * @author   STMicroelectronics
 */

#ifndef _STAPP_POD_H_
#define _STAPP_POD_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
/* No pod support */
#endif
#if defined(sat5189)
/* No pod support */
#endif
#if defined(sat7111)
/* No pod support */
#endif
#if defined(adi7108)
/* No pod support */
#endif
#if defined(hdk5251)
/* No pod support */
#endif
#if defined(hdk5289)
/* No pod support */
#endif
#if defined(hdk7108)
/* No pod support */
#endif
#if defined(hdk7111)
/* No pod support */
#endif
#if defined(b2039)
/* No pod support */
#endif
#if defined(b2057)
/* No pod support */
#endif
#if defined(b2064)
/* No pod support */
#endif
#if defined(ep8000)
/* No pod support */
#endif
#if defined(epp8000)
/* No pod support */
#endif
#if defined(gpv8000)
/* No pod support */
#endif
#if defined(b2067)
/* No pod support */
#endif
#if defined(dp2010)
/* No pod support */
#endif
#if defined(dp7000)
/* No pod support */
#endif
#if defined(dp7001)
/* No pod support */
#endif
#if defined(dp7050)
/* No pod support */
#endif
#if defined(fx6010)
/* No pod support */
#endif
#if defined(b2075)
/* No pod support */
#endif
#if defined(b2076)
/* No pod support */
#endif
#if defined(mb618)
/* No pod support */
#endif
#if defined(mb628)
#if (DOCSIS_STB_PROFILE==1)
#define POD_MAX_NUMBER 1
#endif
#endif
#if defined(mb628e)
/* No pod support */
#endif
#if defined(eud7141)
/* No pod support */
#endif
#if defined(hdkh225)
/* No pod support */
#endif
#if defined(mb676)
/* No pod support */
#endif
#if defined(mb680)
/* No pod support */
#endif
#if defined(mb704)
/* No pod support */
#endif
#if defined(mb796)
/* No pod support */
#endif
#if defined(mb837)
/* No pod support */
#endif
#if defined(mb903)
/* No pod support */
#endif
#if defined(b2066)
/* No pod support */
#endif
#if defined(hmp7105)
/* No pod support */
#endif
#if defined(sdk7105)
/* No pod support */
#endif
#if defined(kourou)
/* No pod support */
#endif
#if defined(isdb7102)
/* No pod support */
#endif
#if defined(iptv7105)
/* No pod support */
#endif
#if defined(b2068)
/* No pod support */
#endif
#if defined(hdk7167)
/* No pod support */
#endif
#if defined(ngb7167)
/* No pod support */
#endif
#if defined(hdk7197)
/* No pod support */
#endif
#if defined(hdkh251)
/* No pod support */
#endif
#if defined(dtt5267)
/* No pod support */
#endif
#if defined(b2049)
/* No pod support */
#endif
#if defined(custom001030)
/* No pod support */
#endif
#if defined(custom001034)
/* No pod support */
#endif
#if defined(custom001035)
#if (DOCSIS_STB_PROFILE==1)
#define POD_MAX_NUMBER 1
#endif
#endif
#if defined(custom001036)
/* No pod support */
#endif
#if defined(custom001039)
/* No pod support */
#endif
#if defined(custom002005)
/* No pod support */
#endif
#if defined(custom002006)
/* No pod support */
#endif
#if defined(custom002007)
/* No pod support */
#endif
#if defined(custom002008)
/* No pod support */
#endif
#if defined(custom003008)
/* No pod support */
#endif
#if defined(custom003009)
/* No pod support */
#endif
#if defined(custom003011)
/* No pod support */
#endif
#if defined(custom003012)
/* No pod support */
#endif
#if defined(custom003015)
/* No pod support */
#endif
#if defined(custom003018)
/* No pod support */
#endif
#if defined(custom018001)
/* No pod support */
#endif
#if defined(custom021001)
/* No pod support */
#endif
#if defined(custom022001)
/* No pod support */
#endif

/* Includes */
/* -------- */
#if defined(POD_MAX_NUMBER)
#include "stpod.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t POD_Init(void);
ST_ErrorCode_t POD_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif
