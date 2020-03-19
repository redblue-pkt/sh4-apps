/****************************************************************************/
/* COPYRIGHT (C) 2009 STMicroelectronics - All Rights Reserved              */
/* ST makes no warranty express or implied including but not limited to,    */
/* any warranty of                                                          */
/*                                                                          */
/*   (i)  merchantability or fitness for a particular purpose and/or        */
/*   (ii) requirements, for a particular purpose in relation to the LICENSED*/
/*        MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not  */
/*        represent or warrant that the LICENSED MATERIALS provided here    */
/*        under is free of infringement of any third party patents,         */
/*        copyrights, trade secrets or other intellectual property rights.  */
/*        ALL WARRANTIES, CONDITIONS OR OTHER TERMS IMPLIED BY LAW ARE      */
/*        EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW                   */
/*                                                                          */
/****************************************************************************/

/**
   @file		stfdma.h
   @brief	API Interfaces for the STFDMA driver.
 */
 
/* Define to prevent recursive inclusion */
#ifndef __STFDMA_H
#define __STFDMA_H

#if defined (STFDMA_LEGACY_CODE) && defined(DVD_ADDRESSMODE)
#if (DVD_ADDRESSMODE == 32)
#error "No 32 bit support in Legacy Code. Unset STFDMA_LEGACY_CODE"
#endif
#endif

/* Includes --------------------------------------------------------------- */

#include "stddefs.h"         /* Standard definitions */
#include "stos.h"

#ifdef __cplusplus
extern "C" {
#endif


/* Exported Constants ----------------------------------------------------- */

/* Driver constants, required by the driver model */
#define STFDMA_DRIVER_ID           323   /* 0x143 */
#define STFDMA_DRIVER_BASE         (STFDMA_DRIVER_ID << 16)

/* Error constants returned by */
enum
{
    STFDMA_ERROR_NOT_INITIALIZED = STFDMA_DRIVER_BASE,
    STFDMA_ERROR_DEVICE_NOT_SUPPORTED,
    STFDMA_ERROR_NO_CALLBACK_TASK,
    STFDMA_ERROR_BLOCKING_TIMEOUT,
    STFDMA_ERROR_CHANNEL_BUSY,
    STFDMA_ERROR_NO_FREE_CHANNELS,
    STFDMA_ERROR_ALL_CHANNELS_LOCKED,
    STFDMA_ERROR_CHANNEL_NOT_LOCKED,
    STFDMA_ERROR_UNKNOWN_CHANNEL_ID,
    STFDMA_ERROR_UNKNOWN_DEVICE_NUMBER,
    STFDMA_ERROR_UNKNOWN_REGION_NUMBER,
    STFDMA_ERROR_UNKNOWN_ADR_PARAMETER,
    STFDMA_ERROR_UNKNOWN_REQUEST_SIGNAL,
    STFDMA_ERROR_INVALID_TRANSFER_ID,
    STFDMA_ERROR_TRANSFER_ABORTED,
    STFDMA_ERROR_TRANSFER_IN_PROGRESS,
    STFDMA_ERROR_INVALID_BUFFER,
    STFDMA_ERROR_INVALID_CHANNEL,
    STFDMA_ERROR_INVALID_CONTEXT_ID,
    STFDMA_ERROR_INVALID_SC_RANGE,
    STFDMA_ERROR_NO_FREE_CONTEXTS,
    STFDMA_ERROR_TRANSFER_FAILED,
    STFDMA_ERROR_REQUEST_SIGNAL_BUSY,
    STFDMA_ERROR_IO_REMAP_FAILED,
    STFDMA_ERROR_MAP_PHY2UNCACHED_FAILED,
    STFDMA_ERROR_LOW_POWER_STATE
};


/* 1D and 2D step control for use with STFDMA_Control_t */
enum
{
    STFDMA_DIRECTION_STATIC =  1,
    STFDMA_DIRECTION_INCREMENTING
};

#define STFDMA_EXTENDED_NODE   0X1F


enum
{
    STFDMA_EXT_NODE_PES   = 0,
    STFDMA_EXT_NODE_SPDIF,
    STFDMA_EXT_NODE_FEI,
    STFDMA_EXT_NODE_NAND,   
    STFDMA_EXT_NODE_MCHI = 0x06
#if defined (STFDMA_DEBUG_SUPPORT)
    ,STFDMA_EXT_NODE_DEBUG
#endif
};


enum
{
    STFDMA_SC_ENTRY   = 0,
    STFDMA_PTS_ENTRY,
    STFDMA_MARKER_ENTRY
};


/* Channel select constants for use with STFDMA_StartTransfer() */
#define STFDMA_USE_ANY_CHANNEL   0xff           /* Use any channel available */


/* Exported Macros -------------------------------------------------------- */

/* Exported Variables ----------------------------------------------------- */

/* Exported Types --------------------------------------------------------- */

/*  DMA Req line constants for use with STFDMA_PacedControl_t */
typedef enum STFDMA_RequestSignal_e
{

    STFDMA_REQUEST_SIGNAL_NONE = 0,

#if defined (ST_7100)

/*=========================== 7100 =========================================*/

    STFDMA_REQUEST_SIGNAL_CD_VIDEO = 3,

    STFDMA_REQUEST_SIGNAL_DISEQC0_EMPTY,
    STFDMA_REQUEST_SIGNAL_DISEQC0_FULL,

    STFDMA_REQUEST_SIGNAL_SH4_SCIF_RX,
    STFDMA_REQUEST_SIGNAL_SH4_SCIF_TX,

    STFDMA_REQUEST_SIGNAL_SSC0_RX,
    STFDMA_REQUEST_SIGNAL_SSC1_RX,
    STFDMA_REQUEST_SIGNAL_SSC2_RX,
    STFDMA_REQUEST_SIGNAL_SSC0_TX,
    STFDMA_REQUEST_SIGNAL_SSC1_TX,
    STFDMA_REQUEST_SIGNAL_SSC2_TX,

    STFDMA_REQUEST_SIGNAL_UART0_RX,
    STFDMA_REQUEST_SIGNAL_UART1_RX,
    STFDMA_REQUEST_SIGNAL_UART2_RX,
    STFDMA_REQUEST_SIGNAL_UART3_RX,
    STFDMA_REQUEST_SIGNAL_UART0_TX,
    STFDMA_REQUEST_SIGNAL_UART1_TX,
    STFDMA_REQUEST_SIGNAL_UART2_TX,
    STFDMA_REQUEST_SIGNAL_UART3_TX,

    STFDMA_REQUEST_SIGNAL_CD_EXT0,
    STFDMA_REQUEST_SIGNAL_CD_EXT1,

    STFDMA_REQUEST_SIGNAL_CPxM_DECRYPTED_DATA,
    STFDMA_REQUEST_SIGNAL_CPxM_ENCRYPTED_DATA,

    STFDMA_REQUEST_SIGNAL_PCM0,
    STFDMA_REQUEST_SIGNAL_PCM1,
    STFDMA_REQUEST_SIGNAL_PCMREADER,
    STFDMA_REQUEST_SIGNAL_SPDIF_AUDIO,

    STFDMA_REQUEST_SIGNAL_SWTS

#elif defined(ST_7111) 
/*=========================== 7111 =========================================*/

    /* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_UART4_RX = 1, /* UART4 is only available for 7111 cut 2 */
	STFDMA_REQUEST_SIGNAL_UART4_TX = 2,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 24,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 25,
	STFDMA_REQUEST_SIGNAL_TTXT = 26,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 27,  
	STFDMA_REQUEST_SIGNAL_PCM = 28,
	STFDMA_REQUEST_SIGNAL_HDMI_PCM_PLYR = 29,
	STFDMA_REQUEST_SIGNAL_HDMI_SPDIF_PLYR = 30,	

	/* FDMA #1 */    
	STFDMA_REQUEST_SIGNAL_HDMI_AVI_BUFF_EMPTY = 1,
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 2,
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 3,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 4,
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 5,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 6,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 7,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 8,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 9,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 10,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 11,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 12,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 13,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 14,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 15,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 16,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 17,
	STFDMA_REQUEST_SIGNAL_CD_EXT0 = 18,
	STFDMA_REQUEST_SIGNAL_CD_EXT1 = 19,
	STFDMA_REQUEST_SIGNAL_IRB_RX_HALF = 20,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 21,
	STFDMA_REQUEST_SIGNAL_IRB_TX_HALF = 22,
	STFDMA_REQUEST_SIGNAL_IRB_TX = 23,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_HALF = 24,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_FULL = 25,
	STFDMA_REQUEST_SIGNAL_SWTS0 = 26,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 27,
	STFDMA_REQUEST_SIGNAL_SWTS2 = 28,
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 29
	
#elif defined(ST_7105)
/*=========================== 7105 ===============================*/

    /* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 10,
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 14,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 15,
	STFDMA_REQUEST_SIGNAL_CD_EXT1 = 16,
	STFDMA_REQUEST_SIGNAL_CD_EXT2 = 17,
	STFDMA_REQUEST_SIGNAL_CPXM_DECRYPTED_INPUT = 18,
	STFDMA_REQUEST_SIGNAL_CPXM_DECRYPTED_OUTPUT = 19,
	STFDMA_REQUEST_SIGNAL_CPXM_ENCRYPTED_INPUT = 20,
	STFDMA_REQUEST_SIGNAL_CPXM_ENCRYPTED_OUTPUT = 21,
	STFDMA_REQUEST_SIGNAL_PCM1 = 23,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 24,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 25,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 27,
	STFDMA_REQUEST_SIGNAL_HDMI_PCM_PLYR = 29,
	STFDMA_REQUEST_SIGNAL_HDMI_SPDIF_PLYR = 30,

    /* FDMA #1 */    
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 1,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 2,
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 3,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 5,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 6,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 7,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 9,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 10,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 11,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 12,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 13,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 14,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 15,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 16,
	STFDMA_REQUEST_SIGNAL_IRB_RX_HALF = 18,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 19,
	STFDMA_REQUEST_SIGNAL_CD_EXT3 = 20,
	STFDMA_REQUEST_SIGNAL_CD_EXT0 = 21,
	STFDMA_REQUEST_SIGNAL_SWTS2 = 22,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 23,
	STFDMA_REQUEST_SIGNAL_SWTS0 = 24,
	STFDMA_REQUEST_SIGNAL_HDMI_AVI_BUFF_EMPTY = 26,
	STFDMA_REQUEST_SIGNAL_TTXT_SDTVOUT = 30

#elif defined(ST_7141)
/*=========================== 7141 =========================================*/
    /* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_SW_REQ0 = 1,
	STFDMA_REQUEST_SIGNAL_DREQ0_HI = 2,
	
	STFDMA_REQUEST_SIGNAL_ILC_0 = 3,
	STFDMA_REQUEST_SIGNAL_ILC_1 = 4,
	STFDMA_REQUEST_SIGNAL_ILC_2 = 5,
	STFDMA_REQUEST_SIGNAL_ILC_3 = 6,	
	STFDMA_REQUEST_SIGNAL_SYSIRQ0 = 7,	
	STFDMA_REQUEST_SIGNAL_SYSIRQ1 = 8,	
	STFDMA_REQUEST_SIGNAL_SYSIRQ2 = 9,	
	STFDMA_REQUEST_SIGNAL_SYSIRQ3 = 10,		
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 11,	
	
	STFDMA_REQUEST_SIGNAL_PCM0 = 12,
	STFDMA_REQUEST_SIGNAL_PCM1 = 13,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 14,
	STFDMA_REQUEST_SIGNAL_PCMREADER1 = 15,
	STFDMA_REQUEST_SIGNAL_HDMI_PCM_PLYR = 16,	
	STFDMA_REQUEST_SIGNAL_HDMI_SPDIF_PLYR = 17,
	
	STFDMA_REQUEST_SIGNAL_SWTS0 = 18,		
	STFDMA_REQUEST_SIGNAL_SWTS1 = 19,	
	STFDMA_REQUEST_SIGNAL_SWTS2 = 20,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 24,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 25,

    /* FDMA #1 */    
	STFDMA_REQUEST_SIGNAL_SW_REQ1 = 1,
	STFDMA_REQUEST_SIGNAL_DREQ1_HI= 2,
	
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 3,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 4,	
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 5,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 6,	
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 7,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 8,	
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 9,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 10,	
	STFDMA_REQUEST_SIGNAL_SSC4_RX = 11,
	STFDMA_REQUEST_SIGNAL_SSC4_TX = 12,		
	STFDMA_REQUEST_SIGNAL_SSC5_RX = 13,
	STFDMA_REQUEST_SIGNAL_SSC5_TX = 14,		
	STFDMA_REQUEST_SIGNAL_SSC6_RX = 15,
	STFDMA_REQUEST_SIGNAL_SSC6_TX = 16,			
	STFDMA_REQUEST_SIGNAL_UART0_RX = 17,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 18,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 19,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 20,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 21,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 22,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 23,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 24,	
	
	STFDMA_REQUEST_SIGNAL_HDMI_AVI_BUFF_EMPTY = 25,	
	STFDMA_REQUEST_SIGNAL_TTXT_SDTVOUT = 28,
	
	/* FDMA #3*/
    STFDMA_REQUEST_SIGNAL_MCHI_RX = 13,
    STFDMA_REQUEST_SIGNAL_MCHI_TX = 14,
    STFDMA_REQUEST_SIGNAL_MCHI_START_PACING = 27

#elif defined (ST_5197)

/*=========================== 5197 =========================================*/

	STFDMA_REQUEST_SIGNAL_DREQ0_HI = 1,
	STFDMA_REQUEST_SIGNAL_DREQ1_HI = 2,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 3,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 4,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 5,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 6,
	STFDMA_REQUEST_SIGNAL_SWTS2 = 7,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 8,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 9,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 10,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 11,
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 12,
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 13,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 14,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 15,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 16,
	STFDMA_REQUEST_SIGNAL_IRB_TX = 17,
	STFDMA_REQUEST_SIGNAL_VTG_0 = 18,
	STFDMA_REQUEST_SIGNAL_ILC_0 = 19,
	STFDMA_REQUEST_SIGNAL_ILC_1 = 20,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 21,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 22,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 23,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 24,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 25,
	STFDMA_REQUEST_SIGNAL_PCM0 = 26,
	STFDMA_REQUEST_SIGNAL_SPDIF_AUDIO = 27,
	STFDMA_REQUEST_SIGNAL_SWTS0 = 28,
	STFDMA_REQUEST_SIGNAL_PCM1 = 29,
	STFDMA_REQUEST_SIGNAL_CD_AUDIO1 = 30,
	STFDMA_REQUEST_SIGNAL_COUNTER_L1 = 31

#elif defined (ST_5206)

/*=========================== 5206 =========================================*/

	STFDMA_REQUEST_SIGNAL_SSC0_RX = 1,
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 2,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 3,
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 4,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 5,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 6,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 7,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 8,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 9,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 10,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 11,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 12,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 13,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 14,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 15,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 16,
	STFDMA_REQUEST_SIGNAL_TTXT = 17,
	STFDMA_REQUEST_SIGNAL_SWTS0 = 18,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 19,
	STFDMA_REQUEST_SIGNAL_SWTS2 = 20,
	STFDMA_REQUEST_SIGNAL_IRB_RX_HALF = 21,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 21,
	STFDMA_REQUEST_SIGNAL_IRB_TX_HALF = 22,
	STFDMA_REQUEST_SIGNAL_IRB_TX = 22,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_HALF = 23,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_FULL = 23,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 24,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 25,
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 26,
	STFDMA_REQUEST_SIGNAL_PCM0 = 27,
	STFDMA_REQUEST_SIGNAL_PCM1 = 28,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 29,
	STFDMA_REQUEST_SIGNAL_SPDIF_AUDIO = 30,
	STFDMA_REQUEST_SIGNAL_COUNTER_L1 = 31

#elif defined (ST_7108)

/*=========================== 7108 =========================================*/

	/* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_PCM0 = 1,
	STFDMA_REQUEST_SIGNAL_PCM1 = 2,
	STFDMA_REQUEST_SIGNAL_PCM2 = 3,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 4,
	STFDMA_REQUEST_SIGNAL_SPDIF_AUDIO = 5,
	STFDMA_REQUEST_SIGNAL_CD_EXT1 = 6,

	/* FDMA #1 */
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 1,
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 2,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 3,
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 4,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 5,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 6,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 7,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 8,
	STFDMA_REQUEST_SIGNAL_HDMI_AVI_BUFF_EMPTY = 17,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 18,
	STFDMA_REQUEST_SIGNAL_IRB_TX = 19,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_FULL = 20,
	STFDMA_REQUEST_SIGNAL_CD_EXT2 = 22,
	STFDMA_REQUEST_SIGNAL_SSC4_RX = 23,
	STFDMA_REQUEST_SIGNAL_SSC4_TX = 24,
	STFDMA_REQUEST_SIGNAL_SSC5_RX = 25,
	STFDMA_REQUEST_SIGNAL_SSC5_TX = 26,
	STFDMA_REQUEST_SIGNAL_SSC6_RX = 27,
	STFDMA_REQUEST_SIGNAL_SSC6_TX = 28,
	
	/* FDMA #2 */
	STFDMA_REQUEST_SIGNAL_SWTS0 = 1,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 2,
	STFDMA_REQUEST_SIGNAL_SWTS2 = 3,
	STFDMA_REQUEST_SIGNAL_SWTS3 = 4,
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 5,
	STFDMA_REQUEST_SIGNAL_SPI_TX = 6,
	STFDMA_REQUEST_SIGNAL_SPI_RX = 7,
	STFDMA_REQUEST_SIGNAL_MCHI_RX = 8,
	STFDMA_REQUEST_SIGNAL_MCHI_TX = 9,
	STFDMA_REQUEST_SIGNAL_MCHI_START_PACING = 10,
	STFDMA_REQUEST_SIGNAL_CD_EXT3 = 11,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 12,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 13,
	STFDMA_REQUEST_SIGNAL_TTXT_SDTVOUT = 21,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 22,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 23,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 24,
	STFDMA_REQUEST_SIGNAL_UART3_RX = 25,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 26,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 27,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 28,
	STFDMA_REQUEST_SIGNAL_UART3_TX = 29

#elif defined (ST_H205)
	/* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_CD_EXT0 = 1,
	STFDMA_REQUEST_SIGNAL_CD_EXT1 = 2,
	STFDMA_REQUEST_SIGNAL_PCI_HALF = 3,
	STFDMA_REQUEST_SIGNAL_SSC10_SBC_RX = 4,
	STFDMA_REQUEST_SIGNAL_SSC10_SBC_TX = 5,
	STFDMA_REQUEST_SIGNAL_SSC11_SBC_RX = 6,
	STFDMA_REQUEST_SIGNAL_SSC11_SBC_TX = 7,
	STFDMA_REQUEST_SIGNAL_SSC12_SBC_RX = 8,
	STFDMA_REQUEST_SIGNAL_SSC12_SBC_TX = 9,
	STFDMA_REQUEST_SIGNAL_SSC0_RX = 10,
	STFDMA_REQUEST_SIGNAL_SSC1_RX = 11,
	STFDMA_REQUEST_SIGNAL_SSC2_RX = 12,
	STFDMA_REQUEST_SIGNAL_SSC3_RX = 13,
	STFDMA_REQUEST_SIGNAL_SSC0_TX = 14,
	STFDMA_REQUEST_SIGNAL_SSC1_TX = 15,
	STFDMA_REQUEST_SIGNAL_SSC2_TX = 16,
	STFDMA_REQUEST_SIGNAL_SSC3_TX = 17,
	STFDMA_REQUEST_SIGNAL_HDMI_AVI = 18,
	STFDMA_REQUEST_SIGNAL_IRB_RX = 19,
	STFDMA_REQUEST_SIGNAL_IRB_TX = 20,
	STFDMA_REQUEST_SIGNAL_UHF2_RXBUF_FULL = 21,
	STFDMA_REQUEST_SIGNAL_PCM0 = 22,
	STFDMA_REQUEST_SIGNAL_PCM1 = 23,
	STFDMA_REQUEST_SIGNAL_PCM2 = 24,
	STFDMA_REQUEST_SIGNAL_PCMREADER = 25,
	STFDMA_REQUEST_SIGNAL_SPDIF_AUDIO = 26,
	STFDMA_REQUEST_SIGNAL_IRB_SBC_RX = 27,
	STFDMA_REQUEST_SIGNAL_UHF2_SBC_RXBUF_FULL = 28,
	
	/* FDMA #0 */
	STFDMA_REQUEST_SIGNAL_TTXT_HDTVOUT = 1,
	STFDMA_REQUEST_SIGNAL_NAND_DATA = 2,
	STFDMA_REQUEST_SIGNAL_NAND_CMD = 3,
	STFDMA_REQUEST_SIGNAL_SPI_TX = 4,
	STFDMA_REQUEST_SIGNAL_SPI_RX = 5,
	STFDMA_REQUEST_SIGNAL_SWTS0 = 6,
	STFDMA_REQUEST_SIGNAL_SWTS1 = 7,
	STFDMA_REQUEST_SIGNAL_UART0_RX = 8,
	STFDMA_REQUEST_SIGNAL_UART1_RX = 9,
	STFDMA_REQUEST_SIGNAL_UART10_SBC_RX = 10,
	STFDMA_REQUEST_SIGNAL_UART11_SBC_RX = 11,
	STFDMA_REQUEST_SIGNAL_UART0_TX = 12,
	STFDMA_REQUEST_SIGNAL_UART1_TX = 13,
	STFDMA_REQUEST_SIGNAL_UART10_SBC_TX = 14,
	STFDMA_REQUEST_SIGNAL_UART11_SBC_TX = 15,
	STFDMA_REQUEST_SIGNAL_UART2_THRES = 16,
	STFDMA_REQUEST_SIGNAL_UART2_TIMEOUT = 17,
	STFDMA_REQUEST_SIGNAL_UART2_RX = 18,
	STFDMA_REQUEST_SIGNAL_UART2_TX = 19,
	STFDMA_REQUEST_SIGNAL_UART0_THRES = 20,
	STFDMA_REQUEST_SIGNAL_UART0_TIMEOUT = 21,
	STFDMA_REQUEST_SIGNAL_UART1_THRES = 22,
	STFDMA_REQUEST_SIGNAL_UART1_TIMEOUT = 23,
	STFDMA_REQUEST_SIGNAL_UART10_SBC_THRES = 24,
	STFDMA_REQUEST_SIGNAL_UART10_SBC_TIMEOUT = 25,
	STFDMA_REQUEST_SIGNAL_UART11_SBC_THRES = 26,
	STFDMA_REQUEST_SIGNAL_UART11_SBC_TIMEOUT = 27,
	STFDMA_REQUEST_SIGNAL_UHF2_THRES = 28,
	STFDMA_REQUEST_SIGNAL_UHF2_TIMEOUT = 29,
	STFDMA_REQUEST_SIGNAL_TTXT_SDTVOUT = 30

#else

/*=========================== UNKNOWN ======================================*/

    #error This hardware does not have a request line configuration

#endif
} STFDMA_RequestSignal_t;


/* Supported FDMA interface device types for STFDMA_Init()  */
typedef enum STFDMA_Device_e
{
    STFDMA_DEVICE_FDMA_1,
    STFDMA_DEVICE_FDMA_2
} STFDMA_Device_t;

/* Multiinstance */
typedef enum STFDMA_Block_e
{
    STFDMA_1,
    STFDMA_2,
    STFDMA_MPX,
	STFDMA_3 = STFDMA_MPX,
#if defined (ST_7111)  || defined (ST_7105) || (defined (ST_7108) && defined (ST_RT))
    STFDMA_MAX = 2
#elif (defined (ST_7141) && defined (STFDMA_IPRC_SUPPORT_ON)) || (defined (ST_7141) && defined(ST_ESTB)) || defined (ST_7108)
    STFDMA_MAX = 3
#elif defined (ST_H205)
    STFDMA_MAX = 2
#else
    STFDMA_MAX = 1
#endif
}STFDMA_Block_t;

/* The avaiable Channel Pools  */
typedef enum STFDMA_Pool_e
{
    STFDMA_DEFAULT_POOL,
    STFDMA_PES_POOL,
    STFDMA_SPDIF_POOL,
    STFDMA_HIGH_BANDWIDTH_POOL,
    STFDMA_MAX_POOL
} STFDMA_Pool_t;


/* Event constants for use with CallbackReason() */
typedef enum STFDMA_Event_e
{
    STFDMA_NOTIFY_NODE_COMPLETE_DMA_CONTINUING,
    STFDMA_NOTIFY_NODE_COMPLETE_DMA_PAUSED,
    STFDMA_NOTIFY_TRANSFER_ABORTED,
    STFDMA_NOTIFY_TRANSFER_COMPLETE,
    STFDMA_NOTIFY_NAND_READ_ERROR 
} STFDMA_Event_t;


/* Theses are the start code ranges that can be configured for start code */
/* detection during PES processing */
typedef enum STFDMA_SCRange_e
{
    STFDMA_DEVICE_PES_RANGE_0,
    STFDMA_DEVICE_ES_RANGE_0,
    STFDMA_DEVICE_ES_RANGE_1,
#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_7108) || defined (ST_5206) || defined (ST_H205)
    STFDMA_DEVICE_MPEG_RANGE_0 = 1,
    STFDMA_DEVICE_MPEG_RANGE_1 = 2,
    STFDMA_DEVICE_H264_RANGE_0 = 3,
/* On the VSOC platform, the ST7100 has VC1 capability */
#if defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_7108) || defined (ST_5206) || defined (ST_H205)
    STFDMA_DEVICE_VC1_RANGE_0 = 4,
#endif
#endif
    STFDMA_DEVICE_MAX_RANGE
} STFDMA_SCRange_t;

typedef enum STFDMA_VideoCodec_e
{
    VIDEO_CODEC_MPEG,
    VIDEO_CODEC_H264,
    VIDEO_CODEC_VC1,
    VIDEO_CODEC_MAX
}STFDMA_VideoCodec_t;

typedef enum STFDMA_AdditionalDataRegion_e
{
    PES_ADDITIONAL_DATA_REGION_0,
    PES_ADDITIONAL_DATA_REGION_1,
    PES_ADDITIONAL_DATA_REGION_2,
    SPDIF_ADDITIONAL_DATA_REGION_3,
#if defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_7108) || defined (ST_H205)
    PES_ADDITIONAL_DATA_REGION_4,
    PES_ADDITIONAL_DATA_REGION_5,
    PES_ADDITIONAL_DATA_REGION_6,
#endif
    ADDITIONAL_DATA_REGION_MAX
} STFDMA_AdditionalDataRegion_t;

typedef enum STFDMA_AdditionalDataRegionParameter_e
{
    /* For additional data region 0-2 and 4-6*/
    PES_SC_WRITE = 0,
    PES_SC_SIZE,
    PES_ESBUF_TOP,
    PES_ESBUF_READ,
    PES_ESBUF_WRITE,
    PES_ESBUF_BOT,
    PES_PES_CTRL,
    PES_SC1_CTRL,
    PES_SC2_CTRL,
    PES_SCD_STATE_WORD_0,
    PES_SCD_STATE_WORD_1,
    PES_SCD_STATE_WORD_2,
    PES_SCD_STATE_WORD_3,
    PES_SCD_STATE,
    PES_SCD_STATE_WORD_4,
    PES_SCD_STATE_WORD_5,
#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) ||defined(ST_7141) || defined (ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
#if defined (DVD_SECURED_CHIP) && defined (DVD_SECURED_HOST_UNTRUSTED)
    PES_RESERVED_0,
    PES_RESERVED_1,
    PES_RESERVED_2,
    PES_RESERVED_3,
    PES_RESERVED_4,
    PES_RESERVED_5,
    PES_HCBUF_TOP,
    PES_HCBUF_READ,
    PES_HCBUF_WRITE,
    PES_HCBUF_BOTTOM,
    PES_HCBUF_MAX_COPY_LEN,
    PES_RESERVED_6,
    PES_RESERVED_7,
    PES_RESERVED_8,
    PES_RESERVED_9,
    PES_RESERVED_10,
#else
    PES_RESERVED_0,
    PES_RESERVED_1,
    PES_RESERVED_2,
    PES_RESERVED_3,
    PES_RESERVED_4,
    PES_RESERVED_5,
    PES_RESERVED_6,
    PES_RESERVED_7,
    PES_RESERVED_8,
    PES_RESERVED_9,
    PES_RESERVED_10,
    PES_RESERVED_11,
    PES_RESERVED_12,
    PES_RESERVED_13,
    PES_RESERVED_14,
    PES_RESERVED_15,
#endif
#endif
    PES_MVC_RESERVED_0,
    PES_MVC_RESERVED_1,
    PES_MVC_RESERVED_2,
    PES_MVC_RESERVED_3,
    PES_MVC_RESERVED_4,
    PES_MVC_RESERVED_5,
    PES_MVC_ES_WRITE_COPY,
    PES_MVC_CBUF_ADDR,
    PES_LAST,

    /* For additional data region 3 */
    SPDIF_RESERVED_0 = 0,
    SPDIF_RESERVED_1,
    SPDIF_RESERVED_2,
    SPDIF_RESERVED_3,
    SPDIF_RESERVED_4,
    SPDIF_RESERVED_5,
    SPDIF_RESERVED_6,
    SPDIF_RESERVED_7,
    SPDIF_FRAME_COUNT,
    SPDIF_FRAMES_TO_GO,
    SPDIF_DATA_PRECISION_MASK,
    SPDIF_RESERVED_11,
    SPDIF_RESERVED_12,
    SPDIF_RESERVED_13,
    SPDIF_RESERVED_14,
    SPDIF_RESERVED_15,
#if !(defined (ST_7100))  /* Dual SPDIF channel support*/
	SPDIF_FRAME_COUNT_1 = 24,
    SPDIF_FRAMES_TO_GO_1,
    SPDIF_DATA_PRECISION_MASK_1,
#endif
    SPDIF_LAST
} STFDMA_AdditionalDataRegionParameter_t;

/*FDMA DMEM Registers*/
typedef enum STFDMA_RegType_e
{
	STFDMA_REG_PIO_BIT,
	STFDMA_REG_POLLING_TIMEOUT,
	STFDMA_REG_NACK_POLLING_TIMEOUT,
	STFDMA_REG_PIO_ADDRESS,
	STFDMA_REG_PTI_ADDRESS,
	STFDMA_REG_MAX
}STFDMA_RegType_t;

/* DMA channel identifier */
typedef U32  STFDMA_ChannelId_t;

/* DMA transfer identifier */
typedef U32  STFDMA_TransferId_t;

/* Identifies a specific FDMA Context */
typedef U32  STFDMA_ContextId_t;

typedef struct STFDMA_RegValue_s
{
	STFDMA_RegType_t	RegType;
	U32								Value;
}STFDMA_RegValue_t;

/*Identifies DMA register to set*/
typedef struct STFDMA_RegParams_s
{
	U32									NumRegParams;
	STFDMA_RegValue_t		RegValues[STFDMA_REG_MAX];
}STFDMA_RegParams_t;

/* Channel status bits for the SPDIF (PCM & Compressed mode) Audio processing */
typedef struct STFDMA_SPDIFChannelStatus_s
{
    U32 Status_0;

#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined(ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
    union
    {
        struct
        {
            U32 Status_1		:   9;
            U32 UserStatus	:   1;
            U32 Valid				:   1;
            U32 Pad				:   21;
        }PCMMode;

        struct
        {
#endif

            U32 Status_1		:   4;
            U32 UserStatus	:   1;
            U32 Valid				:   1;
            U32 Pad				:   26;

#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined(ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
        }CompressedMode;
    }Status;
#endif
} STFDMA_SPDIFChannelStatus_t;


/* FDMA device Init parameters for STFDMA_Init() */
typedef struct STFDMA_InitParams_s
{
    STFDMA_Device_t         DeviceType;         /* FDMA device */
    ST_Partition_t          *DriverPartition_p; /* Mem partion for driver use */
    ST_Partition_t          *NCachePartition_p; /* Non-cached partition */
    U32                     *BaseAddress_p;     /* Base address of FDMA block */
    U32                     InterruptNumber;    /* FMDA block interrupt number */
    U32                     InterruptLevel;     /* FDMA block interrupt level */
    U32                     NumberCallbackTasks; /* Number of task to use for callback manager */
    U32                     ClockTicksPerSecond; /* Number of clock ticks per second */
    STFDMA_Block_t          FDMABlock;           /* FDMA Silicon used */
} STFDMA_InitParams_t;


/* Node control word describing a transfer for STFDMA_Node_t */
typedef struct STFDMA_NodeControl_s
{
    U32 PaceSignal              :       5;      /* Pace signal id number */
    U32 SourceDirection         :       2;      /* Source address direction control */
    U32 DestinationDirection    :       2;      /* Destination address direction control */
#if defined (ST_7111) || defined (ST_7105) || defined (ST_7108) || defined (ST_H205)
    U32 Reserved                :       6;      /* Reserved. Should be set to 0 */
    U32 Secure                  :       1;
    U32 Reserved1               :       14;     /* Reserved. Should be set to 0 */
#elif defined (ST_5197) || defined (ST_5206)
	U32 Reserved                :       16;     /* Reserved. Should be set to 0 */	
    U32 BTSC							:		1;       /* Set to 1 for BTSC enabled */     
    U32 Reserved1               :       4;      /* Reserved. Should be set to 0 */
#elif defined (ST_7141)
	U32 Reserved                   :      6;      /* Reserved. Should be set to 0 */
	U32 Secure                       :      1;
	U32 Reserved1                 :      9;      /* Reserved. Should be set to 0 */
	U32 BTSC                          :      1;      /* Set to 1 for BTSC enabled */
	U32 Reserved2                 :      4;      /* Reserved. Should be set to 0 */
#else
    U32 Reserved                :       21;     /* Reserved. Should be set to 0 */
#endif
    U32 NodeCompletePause       :       1;      /* End of node pause control */
    U32 NodeCompleteNotify      :       1;      /* End of node notification contro */
} STFDMA_NodeControl_t;


/* DMA node structure for application definition of transfers.
 * Linked list transfer are a linked list of STFDMA_Node_t
 */
typedef struct STFDMA_Node_s
{
    struct STFDMA_Node_s        *Next_p;                /* Next node in list (NULL==end) */
    STFDMA_NodeControl_t        NodeControl;                /* Node control bits */
    U32                         NumberBytes;            /* Number of bytes in node */
    void                        *SourceAddress_p;       /* Start of source data */
    void                        *DestinationAddress_p;  /* Start of dest location */
    U32                         Length;                 /* Line length */
    S32                         SourceStride;           /* Stride between source lines */
    S32                         DestinationStride;      /* Stride between dest lines  */
} STFDMA_Node_t;


/* Defines the extended node required for transfers including additional
 * processing for SPDIF (PCM & Compressed mode) Audio
 */
typedef struct STFDMA_SPDIFNode_s
{
    struct STFDMA_SPDIFNode_s *Next_p;

    U32     Extended						:	5;
    U32     Type								:	3;
    U32     DReq								:	5;

#if defined (ST_7100)
    U32     ModeData						:	1;
    U32     Pad									:	14;
#elif defined (ST_7111) || defined (ST_7105) || defined(ST_7141)|| defined(ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
    U32     ModeData						:	1;		/*0x0 = Compressed Mode*/
    																/*0x1 = PCM Mode*/
    U32     Pad									:	1;		/*should be set to 1 for second SPPDIF channel*/
    U32     Secure							:	1;
    U32     Pad2								:	12;
#else
    U32     Pad									:	15;
#endif

    U32     BurstEnd						:	1;
    U32     Valid								:	1;
    U32     NodeCompletePause	:	1;
    U32     NodeCompleteNotify	:	1;
    U32     NumberBytes;							/*Should be a multiple of 8 bytes for PCM mode*/

    void   *SourceAddress_p;					/*Sould be 8 byte aligned for PCM mode*/
    void   *DestinationAddress_p;

#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined(ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
    union
    {
        struct
        {
            U32     Reserved1;
            U32     SStride;							/*Offset from the source address after 8 Byte Read*/
            U32     Reserved2;
        }PCMMode;

        struct
        {
#endif

            U16     PreambleB;
            U16     PreambleA;
            U16     PreambleD;
            U16     PreambleC;
            U32     BurstPeriod;

#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined(ST_5197) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
        }CompressedMode;
    }Data;
#endif

    STFDMA_SPDIFChannelStatus_t  Channel0;
    STFDMA_SPDIFChannelStatus_t  Channel1;

    U32     Pad1[4]; /* Pad to multiple of 32 bytes */
} STFDMA_SPDIFNode_t;

typedef struct STFDMA_FEINode_s
{
    struct  STFDMA_FEINode_s *Next_p;

    U32     Extended						:	5;
    U32     Type								:	3;
    U32     DreqStart						:	5;
    U32     DreqData						:	5;
    U32     FirstNodeOfTransfer	:	1;
    U32     Pad1								:	11;
    U32     NodeCompletePause	:	1;
    U32     NodeCompleteNotify	:	1;
    U32     NumberBytes;
    void   *SourceAddress_p;
    void   *DestinationAddress_p;
    void   *TVOCounterAddress_p;
    U32     Pad2[10];
} STFDMA_FEINode_t;

/* Defines the extended node required for transfers using additional Context information.
 * This is currently only used for transfers requiring PES processing and ES start code detection.
 */
typedef struct STFDMA_ContextNode_s
{
    struct STFDMA_ContextNode_s     *Next_p;
	U32		Extended						:	5;
	U32		Type								:	3;
	U32		Context							:	4;
#if defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_5206) || defined (ST_7108) || defined (ST_H205)
	U32		PESChunkSize				:	2;		/*0x0 = 128 bytes PES chunk (default)*/
																	/*0x1 = 64 bytes PES chunk*/
																	/*0x2 = 32 bytes PES chunk*/
																	/*0x3 = Reserved*/
	U32		Pad1								:	1;
	U32		Secure							:	1;
#else
	U32		Pad1								:	4;
#endif
	U32		Tag									:	8;
#if defined (ST_H205)
	U32		Pad2								:	5;
	U32     MarkerDetectionDisable              :   1;
#else
	U32		Pad2								:	6;
#endif
	U32		NodeCompletePause	:	1;
	U32		NodeCompleteNotify	:	1;
	U32		NumberBytes;							/*Should be a multiple of 128 bytes*/
	void		*SourceAddress_p;				/*PES buffer read pointer*/

	U32     Pad3[4]; /* Pad to multiple of 32 bytes */

} STFDMA_ContextNode_t;

#if defined (STFDMA_NAND_SUPPORT)
typedef struct STFDMA_NANDNode_s
{
    struct STFDMA_NANDNode_s     *Next_p;
    U32     Extended							:   5;	/*set to 0x1F == Extentended type Node*/
    U32     Type									:   3;	/*set to 0x03 = NAND node type*/
    U32     DReq									:   5;	/*paced signal used for NAND Rd or Wr*/
    U32     Bankno								:   3;	/*Bank number for used*/
    U32     NodeType							:   1;	/*0x0=CMD, 0x1=DATA*/
    U32     DataMode							:   2;	/*0x0=Reserved, 0x1=Normal Data, 0x2=Spare Data, 0x3=Normal+Spare Data*/
    U32     AccessType						:   1;	/*0x0=Read Data, 0x1=Write Data, 0x1=CMD Node*/    
    U32     ErrorCorrection				:   1;	/*0x0=Disable, 0x1=Enable*/
    U32     PageFormat						:   2;	/* 0x0 - 512 Bytes Format (512 Bytes Data + 16 Byte Spare +48 Bytes Dummy)
																			 0x1 - Reserved
																			 0x2 - 2048 Bytes Format (4*512 Bytes + 4*16 Bytes)
																			 0x3 - Reserved */
    U32     TwoByEightMode				:   1;	/*Set to 1 for 2X8 mode*/
    U32     Pad1									:   1;	/*Set to 0*/
    U32		SWReset							:   1;	/*In case of CMD node, S/W Reset will be applied when FDMA will recieve the CMD Node*/
    																	/*In case of Data node, S/W Reset wil be applied when the data node is complete and 
    																		the next pointer is NULL*/
    U32		Pad2									:   4;
    U32     NodeCompletePause		:   1;
    U32     NodeCompleteNotify		:   1;
    U32     NumberBytes;								/*Number of bytes to be read or written (If Data node then NumberBytes should be multiple 
    																		of pages to be transferred, for Command node it should be equal to the command sequence size)*/
    void   *SourceAddress_p;
    void   *DestinationAddress_p;
    void   *SpareDataAddress_p;				/*Address of LMI where spare data needed to bestored or to be read from.*/
    void   *BankRegAddress_p;					/*Address of the bank selection register in NandC memory space that needs 
																		    to be programmed initially before any transaction.*/
    U32     ConfigRegValue;							/*Value of the Generic config register in NandC */
    void   *ConfigRegAddress_p;				/*Address of the Generic config register in NandC.*/
    U32     Pad3[7];										/* Pad to multiple of 32 bytes */    
} STFDMA_NANDNode_t;
#endif /*STFDMA_NAND_SUPPORT*/

typedef struct STFDMA_MCHIRxNode_s
{
    struct STFDMA_MCHIRxNode_s     *Next_p;
    U32     Extended         				:   5;		/*set to 0x1F == Extentended type Node*/
    U32     Type                				:   3;		/*Node Type = 0x06 == MCHI Node for Rx*/
    U32     DReq                				:   5;		/*REQ MAPPING == paced signal used for MCHI Rx*/
    U32     Pad1                				:   2;		/*set to 0*/
    U32     Secure             				:   1;		/*for secure transfer*/
    U32		 MCHIPacketStartDReq	:	 5;		/*dreq number of PKT_START_DREQ*/
    U32     Pad2                				:   9;		/*set to 0*/
    U32     NodeCompletePause   	:   1;
    U32     NodeCompleteNotify  	:   1;
    U32     NumberBytes;									/*Should be set to more than (4096 + 3)*/			
    void   *SourceAddress_p;
    void   *DestinationAddress_p;
    U32     Length;                							/*Should be == NumberBytes*/
    U32     *RXFifoLvlAddress_p;  					 /*Memory location which has Number of residual bytes in the MCHI RX FIFO*/      		 
    S32     DestinationStride;      					/* Stride between dest lines: for STFDMA_MCHIRxNode_s == 0*/
   U32      Pad3[8]; 											/*set to 0*/
} STFDMA_MCHIRxNode_t;

typedef struct STFDMA_FlowControlNode_s
{
    struct  STFDMA_FlowControlNode_s        *Next_p;
    U32    PaceSignal										:	5;
    U32    SourceDirection							:	2;
    U32    DestinationDirection					:	2;
    U32    Reserved										:	6;
    U32    Secure											:	1;
    U32    Reserved1										:	3;
    U32    PollingPaceEnable						:	1;
    U32    PollingType									:	2;
    U32    Reserved2										:	8;
    U32    NodeCompletePause					:	1;
    U32    NodeCompleteNotify					:	1;
    U32    NumberBytes;
    void    *SourceAddress_p;
    void    *DestinationAddress_p;
    U32     Length;
    S32    SourceStride;
    S32    DestinationStride;
} STFDMA_FlowControlNode_t;

/* This node should be only used for COMMS read channel. For writing, use Generic node configuration */
typedef struct STFDMA_COMMSNode_s
{
	struct STFDMA_COMMSNode_s    *Next_p;
	U32		PaceSignal						:   5;	/* Pace signal id number */
	U32		SourceDirection				:   2;	/* Source address direction control */
																		/* 0x0 -> reserved */
																		/* 0x1 -> constant source address */
																		/* 0x2 -> incrementing source address */
																		/* 0x3 -> reserved */
																		/* For paced read channels, this is overridden by the info contained in the PaceSignal word*/
	U32		DestinationDirection		:   2;	/* Destination address direction control */
																		/* 0x0 -> reserved */
																		/* 0x1 -> constant destination address */
																		/* 0x2 -> incrementing destination address */
																		/* 0x3 -> reserved */
																		/* For paced read channels, this is overridden by the info contained in the PaceSignal word */
	U32		CommsEnable					:   1;	/* Only used for COMMS read channel */
																		/* set 0x0 to disable, set 0x1 to enable */
	U32     DreqTimeout					:   5;	/* Only used if CommsEnable is set to 0x1 */
																		/* Tells about timeout dreq line */
	U32		Secure								:   1;	/* If set, all transfers tagged as secure */
	U32		CommsMode						:   3;	/* 0x0 8 Bit mode (Default) */
																		/* 0x1 8 bit + Parity mode */
																		/* 0x2 9 Bit data mode */
																		/* 0x3 - 0x4 	Feature/Customer specific:*/
																		/* 0x5 - 0x7: Reserved */
	U32     PTICounter              :   1;
	U32		Pad1									:   10; /* set to 0 */
	U32		NodeCompletePause   	:   1;
	U32		NodeCompleteNotify  	:   1;
	U32		NumberBytes;
	void 	*SourceAddress_p;
	void 	*DestinationAddress_p;
	U32		Length;											/* Feature/Customer specific:  keep it max according to bauderate */
	U32		CommsStatus;								/* Feature/Customer specific:To find out the residual bytes present in the comms fifo */
	U32		ParityErrorThreshold;				/* Feature/Customer specific: After this many number of continuos parity error. */
																		/* FDMA flush the channel and generate parity error interrupt */																		
   U32      Pad2[8]; 										/*set to 0*/
}STFDMA_COMMSNode_t;

#if defined (STFDMA_DEBUG_SUPPORT)
/*Debug channel support*/
enum
{
	LOC_COUNT_32B = 0,
	LOC_COUNT_64B,    
	LOC_COUNT_128B,   
	LOC_COUNT_256B,     
	LOC_COUNT_512B,   	
	LOC_COUNT_1K,
	LOC_COUNT_2K,    
	LOC_COUNT_4K,   
	LOC_COUNT_8K,     
	LOC_COUNT_16K,
	LOC_COUNT_32K,
	LOC_COUNT_64K,    
	LOC_COUNT_128K,   
	LOC_COUNT_256K,     
	LOC_COUNT_512K,   
	LOC_COUNT_1M 		
};

typedef enum STFDMA_DebugMask_e
{
	STFDMA_DEBUGMASK_INITIATOR_NUM							= (0x01 << 0),
	STFDMA_DEBUGMASK_CHANNEL_STA							= (0x01 << 1),
	STFDMA_DEBUGMASK_CMDMBOX_STA							= (0x01 << 2),
	STFDMA_DEBUGMASK_INTMBOX_STA								= (0x01 << 3),
	STFDMA_DEBUGMASK_DREQ_REG_STA							= (0x01 << 4),
	STFDMA_DEBUGMASK_DREQ_LATENCY							= (0x01 << 5),
	STFDMA_DEBUGMASK_SRC_ID_DATA								= (0x01 << 6),
	STFDMA_DEBUGMASK_PENDING_DATA							= (0x01 << 7),
	STFDMA_DEBUGMASK_DATA_TO_READ_FROM_SRC	= (0x01 << 8),
	STFDMA_DEBUGMASK_DATA_TO_SEND_TO_DEST		= (0x01 << 9),
	STFDMA_DEBUGMASK_FRAMES_TO_GO							= (0x01 << 10),
	STFDMA_DEBUGMASK_NODE_FETCH_LATENCY			= (0x01 << 11),
	STFDMA_DEBUGMASK_HOST_INT_NUM							= (0x01 << 12),
	STFDMA_DEBUGMASK_RESERVED_0								= (0x01 << 13),  /*Not Used*/
	STFDMA_DEBUGMASK_SCLIST_OVERFLOW					= (0x01 << 14),
	STFDMA_DEBUGMASK_MCHI_PKT_START_SIG				= (0x01 << 15)
}STFDMA_DebugMask_t;

#define STFDMA_DEBUGMASK_DISABLE_ALL	0
#define STFDMA_DEBUGMASK_ENABLE_ALL		0xDFFF

typedef struct STFDMA_DebugNode_s
{
	struct STFDMA_DebugNode_s *Next_p;						/*Always NULL*/
	U32 Extended			:	5;												/*set to 0x1F == Extentended type Node*/
	U32 Type					:	3;												/*Node Type = 0x07 ==STFDMA_EXT_NODE_DEBUG*/
	U32 LocationCount	:	4;												/*Ranges from LOC_COUNT_32B to LOC_COUNT_1M*/
	U32 PIOEnable			:	1;												/*0x0-Disable, 0x1 - Enable*/
	U32 Pad1					:	13;											/*Reserved*/
	U32 T2Initiator			:	1;												/*0x0- T2(0), 0x1- T2(1)*/
	U32 Pad2					:	5;												/*Reserved*/
	U32 ChannelNumber;													/*Channel Number to be debugged*/
	STFDMA_DebugMask_t	DebugMask;							/*Mask for Feature to be debugged*/
	void									*DestinationAddress_p;	/*Destination buffer for debug data*/
	U32									PIOAddress;							/*PIO address where DREQ register info is to be sent.
																								Only used for DREQ debug feature.*/
	U32									SamplingFreq;						/*Minimum number of SLIM cycles after which next
																								Debug messages should be sent.*/
	U32									Pad3[9];
}STFDMA_DebugNode_t;
#endif

/* The generic node structure */
typedef union STFDMA_GenericNode_s
{
    struct
    {
        union STFDMA_GenericNode_s     *Next_p;
        U32     Extended		:	5;
        U32     Type				:	3;
        U32     Pad				:	24;
        U32     NumberBytes;
        void   *SourceAddress_p;
    } Gen;

    STFDMA_Node_t           Node;
    STFDMA_ContextNode_t    ContextNode;
    STFDMA_SPDIFNode_t      SPDIFNode;
    STFDMA_FEINode_t        FEINode;
#if defined (STFDMA_NAND_SUPPORT)
    STFDMA_NANDNode_t       NANDNode;
#endif
    STFDMA_MCHIRxNode_t           MCHIRxNode;
#if defined (STFDMA_DEBUG_SUPPORT)
    STFDMA_DebugNode_t              DebugNode;
#endif
	STFDMA_FlowControlNode_t		FlowControlNode;
	STFDMA_COMMSNode_t				COMMSNode;
} STFDMA_GenericNode_t;


/* An entry in the start code list for PES processing */
typedef union STFDMA_SCEntry_s
{
    /* Start code entry */
    struct
    {
        U32     Type				: 2;  /* STFDMA_SC_ENTRY */
        U32     Pad1				: 6;
        U32     Tag				: 8;
        U32     DriverReco  : 1;
        U32     InterView    : 1;
        U32     AnchorPic    : 1;
        U32     TemporalId : 3;
        U32     ViewId         : 10;
        void   *Addr;
        
#if defined (ST_7100) || defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_7108) || defined (ST_5206) || defined (ST_H205)
        union
        {
            struct
            {
                U8      SCValue;
                U8      Reserved[3];
            }MPEG2;

            struct
            {
                U32     SCValue			: 8;
                U32     SliceCount		: 16;  /* Undefined for mpeg */
#if defined (STFDMA_H264_I_SLICE_ENABLE)
                U32     SliceType		: 1;	
#else
                U32     Reserved	    	: 1;
#endif
                U32     PriorityId		: 6;
                U32     NonIdr	       	: 1;	
            }H264;
            
#if defined (ST_7111) || defined (ST_7105) || defined(ST_7141) || defined (ST_7108) || defined (ST_5206) || defined (ST_H205)
            struct
            {
                U32     SCValue			: 8;
                U32     SliceAddress	: 9;  /* Undefined for mpeg */
                U32     Reserved			: 15;
            }VC1;
#endif
        }ExtendedInfo;
#else
        U8      SCValue;
        U8      Reserved[3];
#endif

#if defined (DVD_SECURED_CHIP) && defined (DVD_SECURED_HOST_UNTRUSTED)
        void   *Addr2;
#endif
    }
    SC;

    /* PTS entry */
    struct
    {
        U32     Type		:   2;  /* STFDMA_PTS_ENTRY */
        U32     Pad1		:   6;
        U32     Tag		:   8;
        U32     Pad2		:   16;
        void   *Addr;
        U32     PTS1;
        U32     PTS0;
    }
    PTS;

    /* MARKER entry */
    struct
    {
		U32		Type				:	2;
		U32		Pad1				:	6;
		U32		Tag					:	8;
		U32		Marker			:	8;
		U32		Pad2				:	8;
		void	*Addr;
		U32		MarkerId0;
		U32		MarkerId1;
    }
    MarkerEntry;

} STFDMA_SCEntry_t;


/* Configurattion of the start code detection */
typedef struct STFDMA_SCState_s
{
    U8      RangeStart;
    U8      RangeEnd;
    BOOL    RangeEnabled;
    BOOL    PTSEnabled;
    BOOL    OneShotEnabled;
} STFDMA_SCState_t;


/* Transfer status of current node for STFDMA_GetTransferStatus() */
typedef struct STFDMA_TransferStatus_s
{
    BOOL            Paused;                 /* Transfer is paused */
    U32             NodeAddress;            /* Address of current node */
    U32             NodeBytesRemaining;     /* Number of bytes remaining in transfer */
} STFDMA_TransferStatus_t;


/* Callback function type for TransferParams_t  */
typedef void  (*STFDMA_CallbackFunction_t) (U32         TransferId,           /* Transfer id */
                                            U32         CallbackReason,       /* Reason for callback */
                                            U32         *CurrentNode_p,       /* Node transfering */
                                            U32         NodeBytesTransfered,  /* Number of bytes transfered */
                                            BOOL Error,                       /* Interrupt missed */
                                            void *ApplicationData_p,          /* Application data */
                                            STOS_Clock_t  InterruptTime);        /* time_now from interrupt handler */

#if defined (ST_OSLINUX) && defined (CONFIG_STM_DMA)
typedef void  (*STFDMA_LinuxCallbackFunction_t) (void *ApplicationData_p );   /* Application data */
#endif

/* Parameters for STFDMA_StartGenericTransfer() */
typedef struct STFDMA_TransferGenericParams_s
{
    STFDMA_ChannelId_t                  ChannelId;              /* Id of the channel to transfer on */
    STFDMA_Pool_t                       Pool;                   /* The pool from which the channel is to be selected */
    STFDMA_GenericNode_t               *NodeAddress_p;          /* Address of node details */
#if !defined (STFDMA_LEGACY_CODE)
    STFDMA_GenericNode_t               *NodeAddress_Vp;          /* Virtual Address of node*/
#endif
    U32                                 BlockingTimeout;        /* Blocking timeout */
    STFDMA_CallbackFunction_t           CallbackFunction;       /* Pointer to callback function */
    void                               *ApplicationData_p;      /* Pointer application data for callback */
    STFDMA_Block_t                      FDMABlock;              /* FDMA Silicon used */
} STFDMA_TransferGenericParams_t;


/* Parameters for STFDMA_StartTransfer() */
typedef struct STFDMA_TransferParams_s
{
    STFDMA_ChannelId_t                  ChannelId;              /* Id of the channel to transfer on */
    STFDMA_Node_t                      *NodeAddress_p;          /* Address of node details */
#if !defined (STFDMA_LEGACY_CODE)
    STFDMA_Node_t               *NodeAddress_Vp;          /* Virtual Address of node*/    
#endif
    U32                                 BlockingTimeout;        /* Blocking timeout */
    STFDMA_CallbackFunction_t           CallbackFunction;       /* Pointer to callback function */
    void                               *ApplicationData_p;      /* Pointer application data for callback */
    STFDMA_Block_t                      FDMABlock;              /* FDMA Silicon used */
} STFDMA_TransferParams_t;


/* Exported Functions ----------------------------------------------------- */

ST_ErrorCode_t STFDMA_Init(const ST_DeviceName_t DeviceName,
                           const STFDMA_InitParams_t *InitParams_p);


#if defined (STFDMA_LEGACY_CODE)
ST_ErrorCode_t STFDMA_StartGenericTransfer(STFDMA_TransferGenericParams_t *TransferParams_p,
                                           STFDMA_TransferId_t *TransferId_p);
ST_ErrorCode_t STFDMA_StartTransfer   (STFDMA_TransferParams_t *TransferParams_p,
                                       STFDMA_TransferId_t *TransferId_p);
#else
ST_ErrorCode_t STFDMA_StartGenericTransfer(STFDMA_TransferGenericParams_t *TransferParams_p,
                                           STFDMA_TransferId_t *TransferId_p,
                                           BOOL IsPaced);
ST_ErrorCode_t STFDMA_StartTransfer   (STFDMA_TransferParams_t *TransferParams_p,
                                       STFDMA_TransferId_t *TransferId_p,
                                       BOOL IsPaced);
#endif

ST_ErrorCode_t STFDMA_ResumeTransfer(STFDMA_TransferId_t TransferId);
ST_ErrorCode_t STFDMA_FlushTransfer (STFDMA_TransferId_t TransferId);
ST_ErrorCode_t STFDMA_AbortTransfer(STFDMA_TransferId_t TransferId);


ST_ErrorCode_t STFDMA_AllocateContext       (STFDMA_ContextId_t *ContextId);
ST_ErrorCode_t STFDMA_DeallocateContext     (STFDMA_ContextId_t  ContextId);


ST_ErrorCode_t STFDMA_ContextGetSCList      (STFDMA_ContextId_t   ContextId,
                                             STFDMA_SCEntry_t   **SCList,
                                             U32                 *Size,
                                             BOOL                *Overflow);
ST_ErrorCode_t STFDMA_ContextSetSCList      (STFDMA_ContextId_t   ContextId,
                                             STFDMA_SCEntry_t    *SCList,
                                             U32                  Size);


ST_ErrorCode_t STFDMA_ContextGetSCState     (STFDMA_ContextId_t  ContextId,
                                             STFDMA_SCState_t   *State,
                                             STFDMA_SCRange_t    Range);
ST_ErrorCode_t STFDMA_ContextSetSCState     (STFDMA_ContextId_t  ContextId,
                                             STFDMA_SCState_t   *State,
                                             STFDMA_SCRange_t    Range);


ST_ErrorCode_t STFDMA_ContextSetESBuffer    (STFDMA_ContextId_t ContextId, void *Buffer, U32 Size);
ST_ErrorCode_t STFDMA_ContextSetESReadPtr   (STFDMA_ContextId_t ContextId, void *Read);
ST_ErrorCode_t STFDMA_ContextSetESWritePtr  (STFDMA_ContextId_t ContextId, void *Write);
ST_ErrorCode_t STFDMA_ContextGetESReadPtr   (STFDMA_ContextId_t ContextId, void **Read);
ST_ErrorCode_t STFDMA_ContextGetESWritePtr  (STFDMA_ContextId_t ContextId, void **Write, BOOL *Overflow);

#if defined (DVD_SECURED_CHIP)  && defined (DVD_SECURED_HOST_UNTRUSTED)
ST_ErrorCode_t STFDMA_ContextSetHeaderCopyBuffer        (STFDMA_ContextId_t	ContextId, void *Buffer, U32 Size);
ST_ErrorCode_t STFDMA_ContextSetHeaderCopyBufferReadPtr (STFDMA_ContextId_t ContextId, void *ReadPtr);
ST_ErrorCode_t STFDMA_ContextSetHeaderCopyBufferWritePtr(STFDMA_ContextId_t	ContextId, void *WritePtr);
ST_ErrorCode_t STFDMA_ContextGetHeaderCopyBufferReadPtr (STFDMA_ContextId_t	ContextId, void **ReadPtr);
ST_ErrorCode_t STFDMA_ContextGetHeaderCopyBufferWritePtr(STFDMA_ContextId_t	ContextId, void **WritePtr, BOOL *Overflow);
ST_ErrorCode_t STFDMA_SetESToHCBufferTransferCount      (STFDMA_ContextId_t ContextId, STFDMA_VideoCodec_t VideoCodec,
                                                         U32 TransferCount);
#endif

ST_ErrorCode_t STFDMA_GetTransferStatus(STFDMA_TransferId_t TransferId,
                                        STFDMA_TransferStatus_t *TransferStatus_p);


ST_ErrorCode_t STFDMA_LockChannelInPool(STFDMA_Pool_t       Pool, STFDMA_ChannelId_t *ChannelId, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_LockChannel      (STFDMA_ChannelId_t *ChannelId, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_UnlockChannel(STFDMA_ChannelId_t ChannelId, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_SetTransferCount(U32 RequestLineNo,  U32 TransferCount, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_SetRequestLineOpCode(U32 RequestLineNo,  U8 OpCode, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_SetRequestLineIncrement(U32 RequestLineNo,  BOOL Increment, STFDMA_Block_t DeviceNo);
ST_ErrorCode_t STFDMA_SetAddDataRegionParameter(STFDMA_Block_t DeviceNo, STFDMA_AdditionalDataRegion_t RegionNo, STFDMA_AdditionalDataRegionParameter_t ADRParameter, U32 Value);
ST_ErrorCode_t STFDMA_SetRegParams(STFDMA_Block_t DeviceNo, STFDMA_RegParams_t RegParams);

#if defined (ST_OSLINUX) && defined (CONFIG_STM_DMA)
ST_ErrorCode_t STFDMA_SetSTLinuxChannel(STFDMA_ChannelId_t ChannelId, STFDMA_Block_t DeviceNo);
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,11)
ST_ErrorCode_t STFDMA_LockFdmaChannel(int *ChannelId, STFDMA_Block_t DeviceNo);
#else
ST_ErrorCode_t STFDMA_LockFdmaChannel(STFDMA_Block_t DeviceNo);
#endif
#endif

ST_Revision_t STFDMA_GetRevision(void);
ST_ErrorCode_t STFDMA_GetFirmwareRevision(STFDMA_Block_t DeviceNo, U32 *FWRevision);

ST_ErrorCode_t STFDMA_Term(const ST_DeviceName_t DeviceName,
                           const BOOL ForceTerminate,
                           STFDMA_Block_t DeviceNo);

/* Non-blocking call with no callback */
/* This is a stub function to allocate a unique value */
void  STFDMA_NO_CALLBACK (U32  TransferId,           /* Transfer id */
                          U32  CallbackReason,       /* Reason for callback */
                          U32  *CurrentNode_p,       /* Node transfering */
                          U32  NodeBytesTransfered,  /* Number of bytes transfered */
                          BOOL Error,                /* Interrupt missed */
                          void *ApplicationData_p,   /* Application data */
                          STOS_Clock_t  InterruptTime); /* time_now from interrupt handler */


#if defined (STFDMA_USE_VIRTUAL_CONTEXT)

/* Identifies a specific Virtual FDMA Context */
typedef U32  STFDMA_VirtualContextId_t;

ST_ErrorCode_t STFDMA_AllocateVirtualContext       (STFDMA_VirtualContextId_t *VirtualContextId);

ST_ErrorCode_t STFDMA_DeallocateVirtualContext     (STFDMA_VirtualContextId_t  VirtualContextId);

ST_ErrorCode_t STFDMA_VirtualContextRestore (STFDMA_VirtualContextId_t  VirtualContextId,
                                             STFDMA_ContextId_t         ContextId);

ST_ErrorCode_t STFDMA_VirtualContextSave   (STFDMA_ContextId_t         ContextId,
                                            STFDMA_VirtualContextId_t  VirtualContextId);

ST_ErrorCode_t STFDMA_VirtualContextGetSCList(STFDMA_VirtualContextId_t   VirtualContextId,
	                                           STFDMA_SCEntry_t          **SCList,
	                                           U32                         *Size,
	                                           BOOL                        *Overflow);

ST_ErrorCode_t STFDMA_VirtualContextSetSCList(STFDMA_VirtualContextId_t  VirtualContextId,
	                                           STFDMA_SCEntry_t          *SCList,
	                                           U32                        Size);

ST_ErrorCode_t STFDMA_VirtualContextGetSCState (STFDMA_VirtualContextId_t  VirtualContextId,
	                                             STFDMA_SCState_t          *State,
	                                             STFDMA_SCRange_t           Range);

ST_ErrorCode_t STFDMA_VirtualContextSetSCState (STFDMA_VirtualContextId_t  VirtualContextId,
	                                             STFDMA_SCState_t          *State,
	                                             STFDMA_SCRange_t           Range);

ST_ErrorCode_t STFDMA_VirtualContextSetESBuffer (STFDMA_VirtualContextId_t  VirtualContextId,
                                                 void                      *Buffer,
                                                 U32                        Size);

ST_ErrorCode_t STFDMA_VirtualContextSetESReadPtr(STFDMA_VirtualContextId_t  VirtualContextId,
                                                 void                      *Read);

ST_ErrorCode_t STFDMA_VirtualContextSetESWritePtr (STFDMA_VirtualContextId_t  VirtualContextId,
                                                   void                      *Write);

ST_ErrorCode_t STFDMA_VirtualContextGetESReadPtr (STFDMA_VirtualContextId_t   VirtualContextId,
                                                  void                      **Read);

ST_ErrorCode_t STFDMA_VirtualContextGetESWritePtr (STFDMA_VirtualContextId_t  VirtualContextId,
                                                   void **Write,
                                                   BOOL  *Overflow);
#endif /* STFDMA_VIRTUAL_CONTEXT */

#if defined (STFDMA_USE_VIRTUAL_CONTEXT) && defined (DVD_SECURED_CHIP) && defined (DVD_SECURED_HOST_UNTRUSTED)
ST_ErrorCode_t STFDMA_VirtualContextSetHeaderCopyBuffer        (STFDMA_VirtualContextId_t   VirtualContextId,
                                                                void                       *Buffer,
                                                                U32                         Size);
ST_ErrorCode_t STFDMA_VirtualContextSetHeaderCopyBufferReadPtr (STFDMA_VirtualContextId_t   VirtualContextId,
                                                                void                       *ReadPtr);
ST_ErrorCode_t STFDMA_VirtualContextSetHeaderCopyBufferWritePtr(STFDMA_VirtualContextId_t   VirtualContextId,
                                                                void                       *WritePtr);
ST_ErrorCode_t STFDMA_VirtualContextGetHeaderCopyBufferReadPtr (STFDMA_VirtualContextId_t   VirtualContextId,
                                                                void                      **ReadPtr);
ST_ErrorCode_t STFDMA_VirtualContextGetHeaderCopyBufferWritePtr(STFDMA_VirtualContextId_t   VirtualContextId,
                                                                void                      **WritePtr,
                                                                BOOL                       *Overflow);
ST_ErrorCode_t STFDMA_VirtualContextSetESToHCBufferTransferCount      (STFDMA_VirtualContextId_t   VirtualContextId,
                                                                STFDMA_VideoCodec_t         VideoCodec,
                                                                U32                         TransferCount);
#endif /* STFDMA_USE_VIRTUAL_CONTEXT && DVD_SECURED_CHIP */

ST_ErrorCode_t STFDMA_MVCEnable(STFDMA_Block_t DeviceNo, STFDMA_ChannelId_t ChannelId, BOOL Enable);
ST_ErrorCode_t STFDMA_GetDMEMAddrRange(STFDMA_Block_t DeviceNo, U32 *DMEMStartAddr, U32 *DMEMSize);
ST_ErrorCode_t STFDMA_Dump(STFDMA_Block_t DeviceNo, const ST_DeviceName_t FileName);

#ifdef __cplusplus
}
#endif

#if defined (STFDMA_DEBUG_SUPPORT)
ST_ErrorCode_t STFDMA_DisplayStatus (STFDMA_Block_t DeviceNo);
#endif

#endif /* __STFDMA_H */

/* End of stfdma.h */

