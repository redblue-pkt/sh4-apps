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
 @File   vout_feature.h
 @brief


*/

/* Brings macros required by VOUT
 This header file could be included from Linux User level, Linux Kernel level, and OS2x
*/

#ifndef VOUT_FEATURE_H
#define VOUT_FEATURE_H

typedef enum STVOUT_Logical_op_s
{
    LOGICAL_OP_AND,
    LOGICAL_OP_OR
} STVOUT_Logical_op_t;

#define VOUT_LOGICAL_DUAL(a)    (1 - (a))
#define VOUT_VALUE_DUAL(a)      (~(a))

/***** soc_7111.h soc_7105.h ***/
#if defined(ST_7111) || defined(ST_7105) || defined(ST_7141)

#define STVOUT_DEVTYPE              STVOUT_DEVTYPE_7111
#define STVOUT_DVO_TYPE             STVOUT_DVO_HD

#define HAL_CONTROLINTERFACE_HDMI_ENABLE_ADDRESS    (U8*)(((HALHDMI_Properties_t *) Handle)->SYSCFGBaseAddress_p)+SYS_CFG2
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_VALUE      ~HDMI_POFF
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_LOGICALOP  LOGICAL_OP_AND

#ifdef ST_7111
#define HDMI_INTERRUPT              ST7111_HDMI_INTERRUPT
#define CEC_INTERRUPT               ST7111_AUD_HDMI_CEC_INTERRUPT
#endif

#ifdef ST_7105
#define HD_TVOUT_BASE_ADDRESS       ST7105_HD_TVOUT_BASE_ADDRESS
#define CEC_INTERRUPT               ST7105_CEC_INTERRUPT
#endif

#ifdef ST_7141
#define HDMI_INTERRUPT              ST7141_HDMI_INTERRUPT
#define CEC_INTERRUPT               ST7141_CEC_INTERRUPT
#endif

#endif

#if defined(ST_7108)

#define STVOUT_DEVTYPE              STVOUT_DEVTYPE_7108
#ifndef STVOUT_ENHANCED_HDMI
#define STVOUT_ENHANCED_HDMI        /*  some double use with previous definition, but brought by code owner */
#endif
#define STVOUT_DVO_TYPE             STVOUT_DVO_HD

#define HAL_CONTROLINTERFACE_HDMI_ENABLE_ADDRESS    (U8*)(((HALHDMI_Properties_t *) Handle)->RegisterBaseAddress_p)+HDMI_SERIALIZER_CTRL
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_VALUE      ~HDMI_SERIALIZER_POWER_DOWN
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_LOGICALOP  LOGICAL_OP_AND

#endif

#if defined(ST_H205)

#define STVOUT_DEVTYPE              STVOUT_DEVTYPE_H205

#ifndef STVOUT_ENHANCED_HDMI
#define STVOUT_ENHANCED_HDMI        /*  some double use with previous definition, but brought by code owner */
#endif
#define STVOUT_DVO_TYPE             STVOUT_DVO_HD

#define HAL_CONTROLINTERFACE_HDMI_ENABLE_ADDRESS    (U8*)(((HALHDMI_Properties_t *) Handle)->RegisterBaseAddress_p)+HDMI_SERIALIZER_CTRL
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_VALUE      ~HDMI_SERIALIZER_POWER_DOWN
#define HAL_CONTROLINTERFACE_HDMI_ENABLE_LOGICALOP  LOGICAL_OP_AND
#endif


#if defined(ST_5206) || defined(ST_5289)
#define STVOUT_DEVTYPE              STVOUT_DEVTYPE_5206
#define STVOUT_DVO_TYPE             STVOUT_DVO_ED
#define HD_TVOUT_BASE_ADDRESS       ST5206_HD_TVOUT_BASE_ADDRESS
#endif

#ifdef ST_5197
#define STVOUT_DEVTYPE              STVOUT_DEVTYPE_V13
#define STVOUT_DVO_TYPE             STVOUT_DVO_ED
#endif

/****/

/* levels of DEVTYPE*/
#define STVOUT_DEVTYPE_V13  0
#define STVOUT_DEVTYPE_7100 1
#define STVOUT_DEVTYPE_7200 2
#define STVOUT_DEVTYPE_7111 3
#define STVOUT_DEVTYPE_5206 4
#define STVOUT_DEVTYPE_7106 5
#define STVOUT_DEVTYPE_7108 6
#define STVOUT_DEVTYPE_H205 7

#define STVOUT_DVO_ED   0
#define STVOUT_DVO_HD   1

#endif  /* #ifndef VOUT_FEATURE_H*/

