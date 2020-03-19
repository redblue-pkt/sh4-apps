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
 @File   Os_20to21_map.h
 @brief



*/
#ifndef __OS_20TO21_MAP_H
#define __OS_20TO21_MAP_H

/* C++ support */
#ifdef __cplusplus
extern "C" {
#endif

/* OS20-OS21 functions wrapper */

#ifdef ST_OS21
#ifndef semaphore_create_fifo_timeout
	#define semaphore_create_fifo_timeout(count) semaphore_create_fifo(count)
#endif
	#define semaphore_create_priority_timeout(count) semaphore_create_priority(count)
	#define interrupt_install(a,b,c,d) interrupt_install(interrupt_handle(a),(interrupt_handler_t )c,d)
	#define interrupt_install_shared(a,b,c,d) interrupt_install_shared(interrupt_handle(a),(interrupt_handler_t )c,d)
	#define interrupt_uninstall(a,b) interrupt_uninstall(interrupt_handle(a))
	#define interrupt_enable_number(number) interrupt_enable(interrupt_handle(number))
	#define interrupt_disable_number(number) interrupt_disable(interrupt_handle(number))
	#define interrupt_clear_number(number) interrupt_clear(interrupt_handle(number))
	#define interrupt_raise_number(number) interrupt_raise(interrupt_handle(number))
	#define task_flags_high_priority_process  0 /* does not exist for ST40 */
	#define clock_t  osclock_t
#endif

#ifdef ST_OS20
    #define task_flags_no_min_stack_size  0
    #define osclock_t  clock_t
#endif

/* C++ support */
#ifdef __cplusplus
}
#endif

#endif /* #ifndef __OS_20TO21_MAP_H */

