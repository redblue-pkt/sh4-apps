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
 @File   hdmi_feature.h
 @brief


*/


/* Brings HDMI_FEATURE macro
 This header file could be included from Linux User level, Linux Kernel level, and OS2x
*/

/* FILE TO BE OBSOLETED !*/

#ifndef HDMI_FEATURE_H
#define HDMI_FEATURE_H

/**** soc_7111.h  soc_7105.h ***/
#if defined(ST_7111) || defined(ST_7105) || defined(ST_7141) || defined(ST_7108) || defined(ST_H205)

#define STHDMI_DEVICE_TYPE		STHDMI_DEVICE_TYPE_7111
#define HDMI_FEATURE_LEVEL_MAJOR    1
#define HDMI_FEATURE_LEVEL_MINOR    3

#if defined(ST_7111) || defined(ST_7105) || defined(ST_7141)
#define HDMI_FEATURE_LEVEL_AUX      0
#endif

#if defined(ST_7108)||defined(ST_H205)
#define HDMI_FEATURE_LEVEL_AUX      1
#ifdef ST_7108
#define HDP_PIO_BIT_HDMI_CELL3      PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL3   I2C_DeviceName[2]
#define PIO_DeviceName_HDMI_CELL3   PIO_DeviceName[9]
#endif
#endif


/*****  board m618 - Sat7111 - hdk 7111 ****/
#if defined(m618) || defined(sat7111) || defined(hdk7111)
#define HDP_PIO_BIT_HDMI_CELL2     PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL2  I2C_DeviceName[0]
#define PIO_DeviceName_HDMI_CELL2  PIO_DeviceName[4]
#endif
/*******************************************/
/****** hdk7167 sdk7105 mb680 iptv7105 hmp7105 *****/
#if  defined(hdk7167) || defined(sdk7105)
#define HDP_PIO_BIT_HDMI_CELL2      PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL2   I2C_DeviceName[0]
#define PIO_DeviceName_HDMI_CELL2   PIO_DeviceName[9]
#endif

#ifdef mb680
#define GENERIC_HDP_PIO_BIT_HDMI_CELL       PIO_BIT_7
#define GENERIC_I2C_DeviceName_HDMI_CELL2   I2C_DeviceName[2]
#define GENERIC_PIO_DeviceName_HDMI_CELL2   PIO_DeviceName[9]
#endif

#ifdef hmp7105
#define HDP_PIO_BIT_HDMI_CELL2      PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL2   I2C_DeviceName[1]
#define PIO_DeviceName_HDMI_CELL2   PIO_DeviceName[9]
#endif

#ifdef iptv7105
#define HDP_PIO_BIT_HDMI_CELL      PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL   I2C_DeviceName[2]
#define PIO_DeviceName_HDMI_CELL   PIO_DeviceName[4]
#endif

/****** mb628 mb628e eud7141 ********/
#if defined(mb628) ||defined(mb628e)

#define HDP_PIO_BIT_HDMI_CELL2     PIO_BIT_6
#define I2C_DeviceName_HDMI_CELL2  I2C_DeviceName[3]
#define PIO_DeviceName_HDMI_CELL2  PIO_DeviceName[4]

#ifdef eud7141
#define HDP_PIO_BIT_HDMI_CELL2     PIO_BIT_6
#define I2C_DeviceName_HDMI_CELL2  I2C_DeviceName[2]
#define PIO_DeviceName_HDMI_CELL2  PIO_DeviceName[4]
#endif

#ifdef eud7141
#define HDP_PIO_BIT_HDMI_CELL2     PIO_BIT_6
#define I2C_DeviceName_HDMI_CELL2  I2C_DeviceName[2]
#define PIO_DeviceName_HDMI_CELL2  PIO_DeviceName[4]
#endif


/*  Specific macro: */
/*   Configure PIO5[6] as HMI_HOTPLUG alternate function */
#define HMI_HOTPLUG_ALTERNATE_FUNCTION SYS_SetBitsDev32LE(ST7141_CFG_BASE_ADDRESS+0x150/*SYSTEM_CONFIG20*/,(1<<24))
#endif

#endif

#ifdef ST_5206
#undef STHDMI_DEVICE_TYPE
#define HDMI_FEATURE_LEVEL_MAJOR    1
#define HDMI_FEATURE_LEVEL_MINOR    3
#define HDMI_FEATURE_LEVEL_AUX      0
#define CEC_INTERRUPT               ST5206_CEC_INTERRUPT
#endif

#ifdef ST_5197 
#undef STHDMI_DEVICE_TYPE
#define HDMI_FEATURE_LEVEL_MAJOR    0
#define HDMI_FEATURE_LEVEL_MINOR    0
#define HDMI_FEATURE_LEVEL_AUX      0
#endif

#ifdef hdk5289
#define HDP_PIO_BIT_HDMI_CELL2      PIO_BIT_7
#define I2C_DeviceName_HDMI_CELL2   I2C_DeviceName[0]
#define PIO_DeviceName_HDMI_CELL2   PIO_DeviceName[9]
#endif
/******/

#define HDMI_FEATURE(a, b, c)	(a * 10000 + b * 100 + c)

/*
 HDMI_FEATURE (1,2,0)     HDMI spec v1.2
 HDMI_FEATURE (1,2,1)     HDMI spec v1.2  + CEA_EIA_861B
 HDMI_FEATURE (1,2,2)     HDMI spec v1.2 + CEA_EIA_861B + CEA_EIA_861D
 HDMI_FEATURE (1,3,0)     HDMI spec v1.3
 HDMI_FEATURE (1,3,1)     HDMI spec v1.3  + CEA_EIA_861E       deep colors
*/

#ifndef HDMI_FEATURE_LEVEL_MAJOR
#error "HDMI_FEATURE_LEVEL_MAJOR not defined"
#endif

#define HDMI_FEATURE_LEVEL		HDMI_FEATURE(HDMI_FEATURE_LEVEL_MAJOR, HDMI_FEATURE_LEVEL_MINOR, HDMI_FEATURE_LEVEL_AUX)

#endif  /* #ifndef HDMI_FEATURE_H*/
