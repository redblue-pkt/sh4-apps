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
 * @file     stapp_i2c.h
 * @brief    This is the i2c file header.
 *           It is used to exchange informations between hardware devices using
 *           standart i2c protocol.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_I2C_H_
#define _STAPP_I2C_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define I2C_MAX_NUMBER 2
#endif
#if defined(sat5189)
#define I2C_MAX_NUMBER 2
#endif
#if defined(sat7111)
#define I2C_MAX_NUMBER 2
#endif
#if defined(adi7108)
#define I2C_MAX_NUMBER 4
#endif
#if defined(hdk5251)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hdk5289)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hdk7108)
#define I2C_MAX_NUMBER 4
#endif
#if defined(hdk7111)
#define I2C_MAX_NUMBER 2
#endif
#if defined(b2069)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2039)
#define I2C_MAX_NUMBER 2
#endif
#if defined(b2057)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2064)
#define I2C_MAX_NUMBER 4
#endif
#if defined(ep8000)
#define I2C_MAX_NUMBER 4
#endif
#if defined(epp8000)
#define I2C_MAX_NUMBER 4
#endif
#if defined(gpv8000)
#define I2C_MAX_NUMBER 4
#endif
#if defined(b2067)
#define I2C_MAX_NUMBER 3
#endif
#if defined(dp2010)
#define I2C_MAX_NUMBER 3
#endif
#if defined(dp7000)
#define I2C_MAX_NUMBER 3
#endif
#if defined(dp7001)
#define I2C_MAX_NUMBER 3
#endif
#if defined(dp7050)
#define I2C_MAX_NUMBER 3
#endif
#if defined(fx6010)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2075)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2076)
#define I2C_MAX_NUMBER 2
#endif
#if defined(mb618)
#define I2C_MAX_NUMBER 3
#endif
#if defined(mb628)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(mb628e)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(eud7141)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 4
#else
#if defined(REMOTE_TUNER_SUPPORT)
#define I2C_MAX_NUMBER 1
#else
#define I2C_MAX_NUMBER 3
#endif
#endif
#endif
#if defined(hdkh225)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 4
#else
#if defined(REMOTE_TUNER_SUPPORT)
#define I2C_MAX_NUMBER 2
#else
#define I2C_MAX_NUMBER 3
#endif
#endif
#endif
#if defined(mb676)
#define I2C_MAX_NUMBER 2
#endif
#if defined(mb680)
#define I2C_MAX_NUMBER 3
#endif
#if defined(mb704)
#define I2C_MAX_NUMBER 2
#endif
#if defined(mb796)
#define I2C_MAX_NUMBER 4
#endif
#if defined(mb837)
#define I2C_MAX_NUMBER 3
#endif
#if defined(mb903)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2066)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hmp7105)
#define I2C_MAX_NUMBER 3
#endif
#if defined(sdk7105)
#if (HARDWARE_REVISION<5)
#define I2C_MAX_NUMBER 4
#else
#define I2C_MAX_NUMBER 3
#endif
#endif
#if defined(kourou)
#define I2C_MAX_NUMBER 3
#endif
#if defined(isdb7102)
#define I2C_MAX_NUMBER 3
#endif
#if defined(iptv7105)
#define I2C_MAX_NUMBER 2
#endif
#if defined(b2068)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hdk7167)
#define I2C_MAX_NUMBER 3
#endif
#if defined(ngb7167)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hdk7197)
#define I2C_MAX_NUMBER 3
#endif
#if defined(hdkh251)
#define I2C_MAX_NUMBER 3
#endif
#if defined(dtt5267)
#define I2C_MAX_NUMBER 3
#endif
#if defined(b2049)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom001030)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom001034)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(custom001035)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(custom001036)
#define I2C_MAX_NUMBER 4
#endif
#if defined(custom001039)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(custom002005)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom002006)
#define I2C_MAX_NUMBER 2
#endif
#if defined(custom002007)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom002008)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 4
#else
#define I2C_MAX_NUMBER 3
#endif
#endif
#if defined(custom003008)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom003009)
#define I2C_MAX_NUMBER 2
#endif
#if defined(custom003011)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom003012)
#define I2C_MAX_NUMBER 3
#endif
#if defined(custom003015)
#define I2C_MAX_NUMBER 2
#endif
#if defined(custom003018)
#define I2C_MAX_NUMBER 2
#endif
#if defined(custom018001)
#define I2C_MAX_NUMBER 2
#endif
#if defined(custom021001)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 5
#else
#define I2C_MAX_NUMBER 4
#endif
#endif
#if defined(custom022001)
#if (CABLE_MODEM_ATTACHED==0)
#define I2C_MAX_NUMBER 4
#else
#define I2C_MAX_NUMBER 3
#endif
#endif

/* Includes */
/* -------- */
#if defined(I2C_MAX_NUMBER)
#include "sti2c.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t I2C_Init(void);
ST_ErrorCode_t I2C_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

