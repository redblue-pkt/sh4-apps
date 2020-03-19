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
 * @file     stapp_pwm.h
 * @brief    This is the pwm (pulse width modulator) file header.
 *           It is used to generate electrical signals for differents uses cases
 *           (ventilators, sensors, cec for hdmi....).
 * @author   STMicroelectronics
 */

#ifndef _STAPP_PWM_H_
#define _STAPP_PWM_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(ST_5197)
/* No PWM support */
#endif
#if defined(ST_5206)
#define PWM_MAX_NUMBER 1
#endif
#if defined(ST_7105)
#define PWM_MAX_NUMBER 1
#endif
#if defined(ST_7108)
#define PWM_MAX_NUMBER 1
#endif
#if defined(ST_7111)
#define PWM_MAX_NUMBER 1
#endif
#if defined(ST_7141)
#define PWM_MAX_NUMBER 1
#endif
#if defined(ST_H205)
#define PWM_MAX_NUMBER 1
#endif

/* Includes */
/* -------- */
#if defined(PWM_MAX_NUMBER)
#include "stpwm.h"
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t PWM_Init(void);
ST_ErrorCode_t PWM_Term(void);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

