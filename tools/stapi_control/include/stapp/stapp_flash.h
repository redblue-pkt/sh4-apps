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
 * @file     stapp_flash.h
 * @brief    This is the flash memories file header.
 *           It gives also access to flash file system (OS21 only) through OSPLUS interface.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_FLASH_H_
#define _STAPP_FLASH_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constants */
/* --------- */
#if defined(cab5197)
#define FLASH_MAX_NUMBER 2
#endif
#if defined(sat5189)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(sat7111)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(adi7108)
#if (HARDWARE_REVISION>=4)
#define FLASH_MAX_NUMBER 3
#else
#define FLASH_MAX_NUMBER 2
#endif
#endif
#if defined(hdk5251)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdk5289)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdk7108)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdk7111)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2069)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2039)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2057)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2064)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(ep8000)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(epp8000)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(gpv8000)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2067)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(dp2010)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(dp7000)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(dp7001)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(dp7050)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(fx6010)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2075)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2076)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb618)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb628)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(mb628e)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(eud7141)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdkh225)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb676)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb680)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb704)
#define FLASH_MAX_NUMBER 2
#endif
#if defined(mb796)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb837)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(mb903)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(b2066)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(hmp7105)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(sdk7105)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(kourou)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(isdb7102)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(iptv7105)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(b2068)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdk7167)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(ngb7167)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(hdk7197)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(hdkh251)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(dtt5267)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(b2049)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(custom001030)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom001034)
#if (HARDWARE_REVISION>=3)
#define FLASH_MAX_NUMBER 2
#else
#define FLASH_MAX_NUMBER 1
#endif
#endif
#if defined(custom001035)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom001036)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom001039)
#define FLASH_MAX_NUMBER 2
#endif
#if defined(custom002005)
/* No flash support */
#endif
#if defined(custom002006)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom002007)
/* No flash support */
#endif
#if defined(custom002008)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom003008)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom003009)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom003011)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom003012)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom003015)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(custom003018)
#define FLASH_MAX_NUMBER 3
#endif
#if defined(custom018001)
/* No flash support */
#endif
#if defined(custom021001)
#define FLASH_MAX_NUMBER 1
#endif
#if defined(custom022001)
#define FLASH_MAX_NUMBER 1
#endif

/* List of flash type supported */
/* ---------------------------- */
typedef enum
{
 FLASH_NONE   = 0,
 FLASH_NOR    = 1,
 FLASH_SERIAL = 2,
 FLASH_NAND   = 3,
 FLASH_MTD    = 4
} FLASH_Type_t;

/* Flash parameters type */
/* --------------------- */
#if defined(FLASH_MAX_NUMBER)
typedef struct
{
 FLASH_Type_t Type;             /* Return flash type (nor/spi/nand/mtd)  */
 char        *DeviceName;       /* Flash device name                     */
 U32          DeviceCode;       /* Return device code of the flash       */
 U32          ManufacturerCode; /* Return manufacturer code of the flash */
 U32          Size;             /* Return size of the flash              */
 U32          NbBlocks;         /* Return number of blocks of the flash  */
 U32          BlockMap[12];     /* Give list of block mapping            */
} FLASH_Parameters_t;
#endif

/* Flash structure type */
/* -------------------- */
typedef struct
{
 FLASH_Type_t         Type;            /* Define type of flash nor/spi/nand...       */
 char                *DeviceName;      /* Define unique name of flash entry          */
 U32                  Model;           /* Type of the flash (for STFLASH)            */
 U32                  Address;         /* Start address in memory seen by cpu        */
 U32                  Size;            /* Size of the flash in bytes                 */
 U32                  Nblocks;         /* Number of blocks of the flash              */
 U32                  BlockMap[12];    /* List of block definition map               */
 U32                  AccessType;      /* Bus width access (8/16/32bits)             */
 U32                  SpiBus;          /* Spi bus identifier                         */
 U32                  SpiPio;          /* Spi pio identifier                         */
 U32                  SpiBit;          /* Spi bit of pio identifier                  */
 U32                  DiskBlockStart;  /* Number of the block where flash disk start */
 U32                  DiskBlockStop;   /* Number of the block where flash disk stop  */
 U32                  NandCtrlTiming;  /* Emi control timing for nand                */
 U32                  NandWriteTiming; /* Emi control timing for nand                */
 U32                  NandReadTiming;  /* Emi control timing for nand                */
 void                *Handle;          /* Handle of the flash driver used            */
 Semaphore_t          SemLock;         /* Semaphore to lock usage of API             */
 void                *Blocks;          /* List of blocks                             */
} FLASH_Descriptor_t;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t FLASH_Init         (void);
ST_ErrorCode_t FLASH_InitType     (U32 Type);
ST_ErrorCode_t FLASH_Term         (void);
ST_ErrorCode_t FLASH_TermType     (U32 Type);
#if defined(FLASH_MAX_NUMBER)
ST_ErrorCode_t FLASH_SectorLock   (U32 DeviceId,U32 Address,U32 Size);
ST_ErrorCode_t FLASH_SectorUnlock (U32 DeviceId,U32 Address,U32 Size);
ST_ErrorCode_t FLASH_SectorErase  (U32 DeviceId,U32 Address,U32 Size);
ST_ErrorCode_t FLASH_SectorWrite  (U32 DeviceId,U32 Address,U32 Size,U8 *Buffer);
ST_ErrorCode_t FLASH_SectorRead   (U32 DeviceId,U32 Address,U32 Size,U8 *Buffer);
ST_ErrorCode_t FLASH_Lock         (U32 DeviceId);
ST_ErrorCode_t FLASH_Unlock       (U32 DeviceId);
ST_ErrorCode_t FLASH_GetParams    (U32 DeviceId,FLASH_Parameters_t *FLASH_Params);
ST_ErrorCode_t FLASH_Erase        (U32 DeviceId,U8                 *FLASH_Address,U32 Size);
ST_ErrorCode_t FLASH_Read         (U32 DeviceId,U8                 *FLASH_Address,U32 Size,U8 *Buffer);
ST_ErrorCode_t FLASH_Write        (U32 DeviceId,U8                 *FLASH_Address,U32 Size,U8 *Buffer);
#endif

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

