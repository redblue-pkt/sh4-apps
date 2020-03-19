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
 * @file     stapp_vfs.h
 * @brief    This is the vfs file header.
 *           It is used to abstract all mass storage available in the system by using
 *           a virtual file system.
 * @author   STMicroelectronics
 */

#ifndef _STAPP_VFS_H_
#define _STAPP_VFS_H_

/* C++ support */
/* ----------- */
#ifdef __cplusplus
extern "C" {
#endif

/* Constant */
/* -------- */
#define VFS_MAX_MOUNT    16        /* Max number of mount points                                          */
#define VFS_MAX_STRING   32        /* Max length for the string mount name                                */
#define VFS_MAX_CALLBACK 5         /* Maximum number of user callback registrations                       */
#define VFS_MAX_BLOCK    (16*1024) /* Maximum alignment need to avoid intermediate memcpy from filesystem */

/* Mount name structure */
/* -------------------- */
typedef struct VFS_Mount_s
{
 U8 DiskName[VFS_MAX_STRING];
 U8 MountName[VFS_MAX_STRING];
 U8 VolumeName[VFS_MAX_STRING];
 U8 FileSystem[VFS_MAX_STRING];
 U8 ModeName[VFS_MAX_STRING];
} VFS_Mount_t;

/* Array containing the mount points */
/* --------------------------------- */
extern VFS_Mount_t VFS_MountList[VFS_MAX_MOUNT];
extern U32         VFS_MountNumber;

/* Prototypes */
/* ---------- */
ST_ErrorCode_t VFS_Init(void);
ST_ErrorCode_t VFS_Term(void);
ST_ErrorCode_t VFS_Mount(U8 *DiskName,U8 *VolumeName,U8 *FileSystemName,U8 *ModeName,U8 **MountNameOut);
ST_ErrorCode_t VFS_UMount(U8 *MountName);
ST_ErrorCode_t VFS_UMountAll(U8 *DiskName);
ST_ErrorCode_t VFS_DisplayList(void);
ST_ErrorCode_t VFS_RegisterCallback(void (*Callback)(void *USR_Param,char *MountName),void *USR_Param,BOOL CallOnMount,BOOL CallOnUnmount);

/* C++ support */
/* ----------- */
#ifdef __cplusplus
}
#endif
#endif

