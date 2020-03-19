/****************************************************************************

File Name   : stbuffer.h

Description : STBUFFER main header file

Copyright (C) 2008 STMicroelectronics - All Rights Reserved

ST makes no warranty express or implied including but not limited to, any
warranty of (i) merchantability or fitness for a particular purpose and/or
(ii) requirements, for a particular purpose in relation to the LICENSED
MATERIALS, which is provided AS IS, WITH ALL FAULTS. ST does not represent
or warrant that the LICENSED MATERIALS provided hereunder is free of
infringement of any third party patents, copyrights, trade secrets or other
intellectual property rights. ALL WARRANTIES, CONDITIONS OR OTHER TERMS
IMPLIED BY LAW ARE EXCLUDED TO THE FULLEST EXTENT PERMITTED BY LAW


References  :

****************************************************************************/

/* Define to prevent recursive inclusion */
#ifndef __STBUFFER_H
#define __STBUFFER_H

/* C++ support ------------------------------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ---------------------------------------------------------------- */
#include "stddefs.h"
#ifndef ST_OSLINUX
    #include <stdlib.h>
    #include <string.h>
#endif
#include "stos.h"


/* Exported Constants ------------------------------------------------------ */
#define STBUFFER_REVISION				"STBUFFER-REL_2.0.11"
#define STBUFFER_DRIVER_ID				(400)							/* Unique driver identifier */
#define STBUFFER_DRIVER_BASE			(STBUFFER_DRIVER_ID << 16)		/* Driver base constant for events and errors */

/*
  STBUFFER_HANDLE_AUTO to be passed in STBUFFER_Handle_t in STBUFFER_Allocate function if allocation is to
  be done automatically based on memory flags and allocation method. In this case, STBUFFER will also filter the
  request based on any regions associated with the specific memory ID. If none has been created, user should
  pass this as 0. If there is a conflict between allocation method and memory flags, STBUFFER_ERROR_MISMATCH
  would be returned.
  */
#define STBUFFER_HANDLE_AUTO			0xFFFFFFFF


/* Exported Types ---------------------------------------------------------- */

/* STBUFFER error code definitions */
typedef enum STBUFFER_Errors_e
{
	STBUFFER_ERROR_BAD_ID = STBUFFER_DRIVER_BASE,	/* No buffer ID corresponding to that specified */
	STBUFFER_ERROR_RANGE,							/* Accessing buffer out of range */
	STBUFFER_ERROR_SECURE,							/* Illegal atempt to obtain pointer within this address space */
	STBUFFER_ERROR_MMAP_FAILED,
	STBUFFER_ERROR_REGION_NOT_CREATED,				/* Trying to allocate without a successful STBUFFER_Open call.
														This is needed even for STBUFFER_HANDLE_AUTO if no such memory  */
	STBUFFER_ERROR_IN_USE,							/* Trying to deallocated a buffer which has non-zero users */
	STBUFFER_ERROR_REGION_OVERLAP,					/* Trying to create avmem region, overlapping with a existing one */
	STBUFFER_ERROR_DEVICE_NOT_INITIALIZED,			/* trying to allocate a buffer using auto handle without initializing STBUFFER */
	STBUFFER_ERROR_OPERATION_NOT_PERMITTED,         /* Trying to perform invalid operation */
	STBUFFER_ERROR_INVALID_USER                     /* Not a valid user of buffer */
}STBUFFER_Errors_t;

/* Type to specify memory allocation */
/* --------------------------------- */
/* The memory type field defined as follows    */
/* MemoryType = [ 31 <---------> 16 ]  [ 15 <----------> 8 ]     [ 7 <----------> 0 ] */
/* MemoryType = [ MemoryID(16 bits) ]  [ MemoryFlags (8 bits)]   [ AllocationMethod(8 bits) ] */

/* MemoryID = Unique Identifier passed by application to distinguish between multiple regions with same properties.
              Set to a unique non-zero for value to be considered. Set to zero if dont care.
              In Linux it will be used as partition ID, for creating a partition or allocating a block from AVMEM */
/* MemoryFlags = STBUFFER_MemoryFlags_t */
/* AllocationMethod = STBUFFER_AllocationMethod_t */

typedef U32 STBUFFER_MemoryType_t;

/* Allocation Methods */
typedef enum STBUFFER_AllocationMethod_e
{
	STBUFFER_METHOD_OS			= 0x00000001,		/* Allocate using STOS methods or direct OS methods (some cases in Linux) */
	STBUFFER_METHOD_AVMEM		= 0x00000002,		/* Allocate using AVMEM methods */
	STBUFFER_METHOD_OSPLUS		= 0x00000003		/* Allocate using OSPLUS methods */
}STBUFFER_AllocationMethod_t;

/* MemoryFlags */
typedef enum STBUFFER_MemoryFlags_e
{
	STBUFFER_CACHED				= 0x00000100,	/* Bit 8 = 1 implies cached memory, 0 implies non-cached memory */
	STBUFFER_NCACHED			= 0x00000000,
	STBUFFER_CONTIGUOUS			= 0x00000200,	/* Bit 9 = 1 implies physically contiguous memory, 0 implies dont care for contiguity */
	STBUFFER_NCONTIGUOUS		= 0x00000000,
	#if defined(DVD_SECURED_CHIP)
		STBUFFER_SECURE			= 0x00000400,	/* Bit 10 = 1 implies secure memory on secure chip, 0 imples non-secure */
	#else
		STBUFFER_SECURE			= 0x00000000,
	#endif
	STBUFFER_NSECURE			= 0x00000000,
	STBUFFER_ALLOC_BOTTOM_TOP	= 0x00000800,  	/* Bit 11 = 1 implies allocation mode top-bottom, 0 implies allocation
	                                                           				    mode bottom-top. This bit is relevant only for AVMEM */
	STBUFFER_ALLOC_TOP_BOTTOM	= 0x00000000
}STBUFFER_MemoryFlags_t;

/* Address Type */
typedef enum STBUFFER_AddressType_e
{
	STBUFFER_ADDR_CACHED,		/* Cached address   */
	STBUFFER_ADDR_UNCACHED,		/* Uncached address */
	STBUFFER_ADDR_PHYSICAL_DEV,	/* Physical address as seen from device */
	STBUFFER_ADDR_PHYSICAL_CPU,	/* Physical address as seen from CPU */
	STBUFFER_ADDR_KCACHED,		/* Kernel cached address - same as cached address in OS2x */
	STBUFFER_ADDR_KUNCACHED		/* Kernel uncached address - same as uncached address in OS2x */
}STBUFFER_AddressType_t;

/* STBUFFER Handle */
typedef U32 STBUFFER_Handle_t;

/* STBUFFER BID Handle */
typedef U32 STBUFFER_ID_t;

/* Init Params */
typedef struct STBUFFER_InitParams_s
{
	/* User Defined Partitions */
	ST_Partition_t              *CachedPartition_p;       /* Cached partition for STBUFFER structures. If NULL, use heap */
} STBUFFER_InitParams_t;

/* Open Parameters */
typedef struct STBUFFER_OpenParams_s
{
	STBUFFER_MemoryType_t		    MemoryType;			/* See detailed behaviour description for STBUFFER_Open() */
    union
    {
        ST_Partition_t              *Partition_p;           /* OS Partition handle */
        U32                         AVMEMPartitionHandle;   /* OS2x: Partition Handle, LINUX: AVMEM partition id 0,1... */
    }MemoryRegion;
} STBUFFER_OpenParams_t;

/* Term Parameters */
typedef struct
{
	BOOL		ForceTerminate;
} STBUFFER_TermParams_t;

/* Prototypes for callback functions */
typedef    ST_ErrorCode_t  (*STBUFFER_GetPointer_t) (STBUFFER_ID_t BufferID, void * const ExtBufferHandle_p, void ** const Address_p) ;
typedef    ST_ErrorCode_t  (*STBUFFER_SetPointer_t) (STBUFFER_ID_t BufferID, void * const ExtBufferHandle_p, void *  const Address_p) ;

/* Exported Variables ------------------------------------------------------ */

/* Exported Macros --------------------------------------------------------- */

/* Exported Functions ------------------------------------------------------ */

/* REVISION */
/* Gets the current revision of the driver */
ST_Revision_t STBUFFER_GetRevision(void);

/* INIT & TERM */
/* Initialize the STBUFFER Interface */
ST_ErrorCode_t STBUFFER_Init(const ST_DeviceName_t DeviceName,  const STBUFFER_InitParams_t *InitParams_p );
/* Terminate the STBUFFER interface.*/
ST_ErrorCode_t STBUFFER_Term(const ST_DeviceName_t DeviceName, const STBUFFER_TermParams_t *TermParams_p );

/* OPEN & CLOSE */
/* Create a memory region */
/* In STBUFFER_Open, a region will be registered. The properties of this region are specified by the MemoryFlags in MemoryType.
    The allocation method that is to be used for allocation requests in this region are specified by AllocationMethod in
    MemoryType. Finally, if this region is to be associated with a unique owner, a specific non-zero MemoryID can be
    passed in MemoryType. The memory range of this region is defined by the MemoryRegion_p in case of methods STBUFFER_METHOD_OS,
    STBUFFER_METHOD_OSPLUS and AVMEMParams in case of STBUFFER_METHOD_AVMEM. For Linux, MemoryRegion_p can be passed as NULL.
    For every successful STBUFFER_Open, a unique handle will be returned. For every memory type, a call to STBUFFER_Open is a
    must, else STBUFFER_Allocate will fail. Even if user wants to use STBUFFER_HANDLE_AUTO, regions must first be created.
  */
ST_ErrorCode_t  STBUFFER_Open(const ST_DeviceName_t DeviceName, const STBUFFER_OpenParams_t *OpenParams_p, STBUFFER_Handle_t *Handle_p);
/* Delete a memory region */
ST_ErrorCode_t STBUFFER_Close(STBUFFER_Handle_t Handle);

/* BUFFER COUNT FUNCTIONS */
/* Detach the buffer from a user. Even when no. of users becomes zero, buffer will not be automatically deallocated. It has to be
   explicitly deallocated. */
ST_ErrorCode_t STBUFFER_DetachFromBuffer(STBUFFER_ID_t BufferID, const ST_DeviceName_t UserName);
/* Attach the buffer to a user */
ST_ErrorCode_t STBUFFER_AttachToBuffer(STBUFFER_ID_t BufferID, const ST_DeviceName_t UserName);

/* GET ADDRESS */
/* Obtain a address to the buffer specified - the pointer type is determined by AddressType */
ST_ErrorCode_t STBUFFER_GetAddress (STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, U32 Offset, void **Address_p);

/* R/W POINTER OFFSET MANIPULATIONS */
/* Obtain the current write pointer offset from the base address */
ST_ErrorCode_t STBUFFER_GetWritePointerOffset(STBUFFER_ID_t BufferID, U32 *Offset_p);
/* Set the current write pointer offset. The offset is from the base address of the buffer */
ST_ErrorCode_t STBUFFER_SetWritePointerOffset(STBUFFER_ID_t BufferID, U32 Offset);
/* Obtain the current read pointer offset from the base address */
ST_ErrorCode_t STBUFFER_GetReadPointerOffset(STBUFFER_ID_t BufferID, U32* Offset_p);
/* Set the current read pointer offset */
ST_ErrorCode_t STBUFFER_SetReadPointerOffset(STBUFFER_ID_t BufferID, U32 Offset);

/* ALLOCATION & DEALLOCATION */
/* Allocate a buffer */
/* The allocation function looks for two things before an allocation. First, it sees if the handle is STBUFFER_HANDLE_AUTO.
    If the handle is STBUFFER_HANDLE_AUTO, it tries to find a region match based on MemoryFlags, MemoryID, AllocationMethod.
    If the match is found, memory is allocated and a handle is returned. If the match is not found, STBUFFER_ERROR_MISMATCH
    will be returned. If the user does not care for MemoryID, ZERO must be passed in this field. In such a case, the match will be
    based on AllocationMethod and MemoryFlags. If the user passes a valid handle that is not STBUFFER_HANDLE_AUTO, the allocation
    will be done in that region alone and nowhere else. In this case, the MemoryType is redundant.
  */
ST_ErrorCode_t STBUFFER_Allocate(STBUFFER_Handle_t Handle, STBUFFER_MemoryType_t MemoryType, U32 Size, U32 Alignment, STBUFFER_ID_t *BufferID_p);
/* Deallocate a buffer. This will normally succeed only when the use count of the buffer is zero, except if the ForceDeallocate = TRUE */
ST_ErrorCode_t STBUFFER_Deallocate(STBUFFER_ID_t BufferID, BOOL ForceDeallocate);
/* Add a buffer to the STBUFFER framework */
ST_ErrorCode_t STBUFFER_RegisterUserBuffer(STBUFFER_AddressType_t AddressType, U32 Address, U32 Size, void * const ExtBufferHandle_p, STBUFFER_ID_t *BufferID_p );

/* R/W POINTER MANIPULATIONS */
/* Obtain the current write pointer - the pointer type is determined by AddressType */
ST_ErrorCode_t STBUFFER_GetWritePointer(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, void ** const Address_p);
/* Obtain the current read pointer - the pointer type is determined by AddressType */
ST_ErrorCode_t STBUFFER_GetReadPointer(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, void ** const Address_p);
/* Set the current read pointer - the pointer type is determined by AddressType */
ST_ErrorCode_t STBUFFER_SetReadPointer(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, void * const Address_p);
/* Set the current write pointer - the pointer type is determined by AddressType */
ST_ErrorCode_t STBUFFER_SetWritePointer(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, void * const Address_p);

/* CALLBACKS */
/* Obtain the function pointers of SetWrite and GetRead functions - to be used when buffer is externally allocated by producer */
ST_ErrorCode_t STBUFFER_GetProducerCallbacks(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, STBUFFER_SetPointer_t *SetWritePointer_p, STBUFFER_GetPointer_t* GetReadPointer_p );
/* Register the function pointers of SetWrite and GetRead functions - to be used when buffer is externally allocated by producer */
ST_ErrorCode_t STBUFFER_SetProducerCallbacks(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, STBUFFER_SetPointer_t SetWritePointer_p, STBUFFER_GetPointer_t GetReadPointer_p );
/* Obtain the function pointers of SetRead and GetWrite functions - to be used when buffer is externally allocated by consumer */
ST_ErrorCode_t STBUFFER_GetConsumerCallbacks(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, STBUFFER_SetPointer_t *SetReadPointer_p, STBUFFER_GetPointer_t* GetWritePointer_p );
/* Obtain the function pointers of SetRead and GetWrite functions - to be used when buffer is externally allocated by consumer */
ST_ErrorCode_t STBUFFER_SetConsumerCallbacks(STBUFFER_ID_t BufferID, STBUFFER_AddressType_t AddressType, STBUFFER_SetPointer_t SetReadPointer_p, STBUFFER_GetPointer_t GetWritePointer_p );

/* PRODUCER & CONSUMER WAITS */
/* Block wait for enough space in the buffer to become available */
ST_ErrorCode_t STBUFFER_ProducerWait(STBUFFER_ID_t BufferID, U32 Size, S32 TimeoutMS);
/* Block wait for enough data to become available to be read from the buffer*/
ST_ErrorCode_t STBUFFER_ConsumerWait(STBUFFER_ID_t BufferID, U32 Size, S32 TimeoutMS);

/* SIZE FUNCTIONS */
/* Get the size of buffer*/
ST_ErrorCode_t STBUFFER_GetBufferSize(STBUFFER_ID_t BufferID,U32 *Size_p);
/* Get the free size of buffer*/
ST_ErrorCode_t STBUFFER_GetBufferFreeSize(STBUFFER_ID_t BufferID, U32 * const FreeSize_p);

#if !defined(ST_OSLINUX)
/* Get AVMEM partition handle for corresponding to a stbuffer handle */
ST_ErrorCode_t STBUFFER_GetAVMEMPartitionHandle(STBUFFER_Handle_t Handle, U32 * const AVMEMPartitionHandle_p);
#endif


/* C++ support ------------------------------------------------------------- */
#ifdef __cplusplus
}
#endif
#endif  /*__STBUFFER_H*/
/* End of stbuffer.h */

