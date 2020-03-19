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
 * @file     stapp_sysini.h
 * @brief    This is the system initialization file header.
 *           It is used to initialize the system and provide also generic file/io api.
 *           It provides also generic buffer allocation management and access to registers.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_SYSINI_H_
#define _STAPP_SYSINI_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Include */
/* ------- */
#if defined(OSPLUS)
#include <osplus/vfs.h>
#include <osplus/sdmmc.h>
#endif
#if defined(ST_OSLINUX)
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <fcntl.h>
#include <unistd.h>
#endif
#include "stos.h"
#include "stbuffer.h"

/* Constants */
/* --------- */
#if defined(AVMEM1_BASE_ADDRESS)
#define AVMEM_MAX_NUMBER                1
#endif
#if defined(AVMEM2_BASE_ADDRESS)
#undef AVMEM_MAX_NUMBER
#define AVMEM_MAX_NUMBER                2
#endif
#if defined(AVMEM3_BASE_ADDRESS)
#undef AVMEM_MAX_NUMBER
#define AVMEM_MAX_NUMBER                3
#endif
#define CACHE_PARTITION_MAX_NUMBER      1
#define NCACHE_PARTITION_MAX_NUMBER     1
#if defined(DVD_SECURED_CHIP)
#define SEC_CACHE_PARTITION_MAX_NUMBER  1
#define SEC_NCACHE_PARTITION_MAX_NUMBER 1
#endif

/* For secured chipsets */
/* -------------------- */
/* In DVD_SECURED_CHIP mode : Please note the following convention :                                                           */
/*                            AVMEM_MAX_NUMBER=AVMEM_SECURED_MAX_NUMBER+AVMEM_UNSECURED_MAX_NUMBER                             */
/*                            AVMEM_PartitionHandle[0....AVMEM_SECURED_MAX_NUMBER-1] are avmem secured regions                 */
/*                            AVMEM_PartitionHandle[AVMEM_SECURED_MAX_NUMBER...AVMEM_MAX_NUMBER] are avmem non secured regions */
#if defined(DVD_SECURED_CHIP)
#ifdef  AVMEM_MAX_NUMBER
#undef  AVMEM_MAX_NUMBER
#endif
#define AVMEM_MAX_NUMBER (AVMEM_SECURED_MAX_NUMBER+AVMEM_UNSECURED_MAX_NUMBER)
#endif

/* STBUFFER handles */
/* ---------------- */
extern STBUFFER_Handle_t BUFFER_CACHED_Handle[];
extern STBUFFER_Handle_t BUFFER_CACHED_CONTIGUOUS_Handle[];
extern STBUFFER_Handle_t BUFFER_NCACHED_Handle[];
extern STBUFFER_Handle_t BUFFER_NCACHED_CONTIGUOUS_Handle[];
#if defined(DVD_SECURED_CHIP)
extern STBUFFER_Handle_t BUFFER_SEC_CACHED_Handle[];
extern STBUFFER_Handle_t BUFFER_SEC_NCACHED_Handle[];
extern STBUFFER_Handle_t BUFFER_SEC_CACHED_CONTIGUOUS_Handle[];
extern STBUFFER_Handle_t BUFFER_SEC_NCACHED_CONTIGUOUS_Handle[];
#endif
#if defined(AVMEM_MAX_NUMBER)
extern STBUFFER_Handle_t BUFFER_AVMEM_Handle[];
#endif
#if defined(OSPLUS)
extern STBUFFER_Handle_t BUFFER_OSPLUS_CACHED_Handle[];
extern STBUFFER_Handle_t BUFFER_OSPLUS_NCACHED_Handle[];
#endif

/* STCLOCK support */
/* --------------- */
#if (defined(ST_5197)||defined(ST_5206)||defined(ST_7105)||defined(ST_7108)||defined(ST_7111)||defined(ST_7141)||defined(ST_H205))&&!defined(ST_OSLINUX)
#define CLOCK_MAX_NUMBER 1
#endif
#if defined(CLOCK_MAX_NUMBER)||defined(DVD_STCLOCK_STUB)
#include "stclock.h"
#endif
#if defined(CLOCK_MAX_NUMBER)
extern STCLOCK_Handle_t CLOCK_Handle[CLOCK_MAX_NUMBER];
#endif

/* Declare cpu max number */
/* ---------------------- */
#if (CABLE_MODEM_ATTACHED==1)
#define CPU_MAX_NUMBER 2
#else
#define CPU_MAX_NUMBER 1
#endif

/* Type to specify memory allocation */
/* --------------------------------- */
/* The memory type field defined for the generic allocations methods is as followed                        */
/*                                                                                                         */
/* MemoryType = [ 31 <---------> 16 ] [ 15 <----------> 12 ] [ 11 <----------> 8 ] [ 7 <-------------> 0 ] */
/* MemoryType = [ MemoryID(16bits)  ] [ MemoryFlags(4bits) ] [ MemoryZone(4bits) ] [ MemoryNumber(8bits) ] */

/* MemoryFlags(4bits) [ 15 <-> 12] */
#if !defined(DVD_SECURED_CHIP)
#define SYS_MEMORY_SECURED        0x00000000
#else
#define SYS_MEMORY_SECURED        0x00001000
#endif
#define SYS_MEMORY_CONTIGUOUS     0x00002000

/* MemoryZone(4bits) [ 11 <-> 8] */
#define SYS_MEMORY_UNKNOWN        0x00000000
#define SYS_MEMORY_CACHED         0x00000100
#define SYS_MEMORY_NCACHED        0x00000200
#define SYS_MEMORY_AVMEM          0x00000300
#if defined(OSPLUS)
#define SYS_MEMORY_OSPLUS_CACHED  0x00000400
#define SYS_MEMORY_OSPLUS_NCACHED 0x00000500
#endif
#if defined(ST_OSLINUX)
#define SYS_MEMORY_BIGPHYSAREA    0x00000600
#endif

/* Local definition for file system */
/* -------------------------------- */
#if defined(OSPLUS)
typedef struct vfs_stat64_s   SYS_Stat_t;
typedef struct vfs_info_s     SYS_Statfs_t;
typedef struct vfs_dirent_s   SYS_Dirent_t;
#define SYS_IS_DIR(mode)      ((mode) & VFS_MODE_DIR)
#define SYS_IS_DIR_STAT(mode) ((mode) & VFS_MODE_DIR)
#define SYS_IS_W(mode)        ((mode) & VFS_MODE_W)
#define SYS_IS_R(mode)        ((mode) & VFS_MODE_R)
#define SYS_IS_RW(mode)       ((mode) & VFS_MODE_RW)
#endif
#if defined(ST_OSLINUX)
typedef struct stat64         SYS_Stat_t;
typedef struct statfs         SYS_Statfs_t;
typedef struct dirent         SYS_Dirent_t;
#define SYS_IS_DIR(mode)      ((mode) & 0x00000004) /* To be used with the mode of a dirent entry         */
#define SYS_IS_DIR_STAT(mode) S_ISDIR(mode)         /* To be used with the mode of on a SYS_Stat_t object */
#define SYS_IS_W(mode)        (((mode) & S_IWUSR) || ((mode) & S_IWGRP) || ((mode) & S_IWOTH))
#define SYS_IS_R(mode)        (((mode) & S_IRUSR) || ((mode) & S_IRGRP) || ((mode) & S_IROTH))
#define SYS_IS_RW(mode)       (SYS_IS_W(mode) && SYS_IS_R(mode)
#endif

/* Prototypes */
/* ---------- */
ST_ErrorCode_t SYS_Init(void);
ST_ErrorCode_t SYS_Term(void);
BOOL           SYS_DCacheFlush(U8 *Buffer,U32 Size);
BOOL           SYS_DCacheEnabled(void);
BOOL           SYS_DCacheEnable(BOOL OnOff);
BOOL           SYS_ICacheEnabled(void);
BOOL           SYS_ICacheEnable(BOOL OnOff);
void          *SYS_FOpen(const char *filename,const char *mode,...);
U32            SYS_FClose(void *stream);
U32            SYS_FRead(void *ptr,U32 size,U32 nmemb,void *stream);
U32            SYS_FWrite(void *ptr,U32 size,U32 nmemb,void *stream);
U32            SYS_FSeek(void *stream,S64 offset,U32 whence);
S64            SYS_FTell(void *stream);
U32            SYS_FEof(void *stream);
U32            SYS_FPrintf(void *stream,const char *format,...);
U32            SYS_FScanf(void *stream,const char *format,...);
char          *SYS_FGets(char *string,U32 n,void *FileContext);
#if defined(OSPLUS)||defined(ST_OSLINUX)
U32            SYS_FRemove(const char *filename);
U32            SYS_FStat(const char *filename,SYS_Stat_t *stats);
U32            SYS_FStatfs(const char *filename,SYS_Statfs_t *statsfs);
void          *SYS_FOpenDir(const char *filename);
U32            SYS_FReadDir(void *directory,SYS_Dirent_t *dirent);
U32            SYS_FCloseDir(void *directory);
U32            SYS_FMkDir(const char *filename);
U32            SYS_FRmDir(const char *filename);
U32            SYS_FTruncate(void *stream,S64 Size);
U32            SYS_FRename(const char *oldname,const char *newname);
#endif
U32            SYS_GetString(U8 *Buffer,U32 Size);
U32            SYS_GetKey(U32 *Key);
U32            SYS_PollKey(U32 *Key);
U32            SYS_ChipVersion(void);
U32            SYS_SystemCommand       (char **args);
U32            SYS_GetCPULoad          (U32 Id);
ST_ErrorCode_t SYS_Memory_Init         (void);
ST_ErrorCode_t SYS_Memory_Term         (void);
U32            SYS_Memory_GetPartition (U32 MemoryType);
U32            SYS_Memory_Allocate     (U32 MemoryType,U32 Size,U32 Alignment);
U32            SYS_Memory_GetDescriptor(U32 MemoryType,U32 Buffer);
U32            SYS_Memory_UserToKernel (U32 MemoryType,U32 Buffer);
U32            SYS_Memory_KernelToUser (U32 MemoryType,U32 Buffer);
U32            SYS_Memory_UserToDevice (U32 MemoryType,U32 Buffer);
U32            SYS_Memory_DeviceToUser (U32 MemoryType,U32 Buffer);
void           SYS_Memory_Deallocate   (U32 MemoryType,U32 Buffer);
U8             SYS_ReadRegDev8         (U32 PhysicalAddress);
U16            SYS_ReadRegDev16LE      (U32 PhysicalAddress);
U32            SYS_ReadRegDev32LE      (U32 PhysicalAddress);
void           SYS_WriteRegDev8        (U32 PhysicalAddress,U8  Value);
void           SYS_WriteRegDev16LE     (U32 PhysicalAddress,U16 Value);
void           SYS_WriteRegDev32LE     (U32 PhysicalAddress,U32 Value);
void           SYS_SetBitsDev8         (U32 PhysicalAddress,U8  Mask);
void           SYS_ClearBitsDev8       (U32 PhysicalAddress,U8  Mask);
void           SYS_SetBitsDev16LE      (U32 PhysicalAddress,U16 Mask);
void           SYS_ClearBitsDev16LE    (U32 PhysicalAddress,U16 Mask);
void           SYS_SetBitsDev32LE      (U32 PhysicalAddress,U32 Mask);
void           SYS_ClearBitsDev32LE    (U32 PhysicalAddress,U32 Mask);
U32            SYS_MapRegisters        (U32 PhysicalAddress,U32 Size,char *Name);
void           SYS_UnmapRegisters      (U32 VirtualAddress ,U32 Size);
ST_ErrorCode_t SYS_RegistrySetKey      (char *string, void *ControlIPAndDEC);
ST_ErrorCode_t SYS_RegistryGetKey      (char *string, void **ControlIPAndDEC);
/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

