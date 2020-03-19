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
@file     stpti.h
@brief    Include wrapper of stpti demux interface to be able to switch from
          any kind of variant of stpti4 api without impacting the application code
@author   STMicroelectronics
*/

#ifndef _STPTI_WRAPPER_H_
#define _STPTI_WRAPPER_H_

#if defined(SERVICE_NDS)
#include "stptinds.h"
#else
#if defined(ST_7108)||defined(ST_H205)
#include "stpti5.h"
#else
#include "stpti4.h"
#endif
#endif
#endif
