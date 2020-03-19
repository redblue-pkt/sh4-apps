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
 * @file     stapi_init.c
 * @brief    Initializes the STAPI modules
 * @author   STMicroelectronics
 */

/* Include */
/* ------- */
#include "stapp_main.h"
#include "stdebug_main.h"

#if defined(STSDK_WITH_MAIN)
int main(int argc,char *argv[])
{
	ST_ErrorCode_t ErrCode = ST_NO_ERROR;

	/* Initialize SDK */
	/* -------------- */
	ErrCode |= STSDK_Init(SDK_INIT_DRIVER_LAYER|SDK_INIT_MIDDLE_LAYER|SDK_INIT_MODULE_LAYER|SDK_INIT_SECURITY|SDK_INIT_DEBUG_LAYER|SDK_INIT_TESTTOOL_SYNC|SDK_INIT_APPLICATION_LAYER);

	/* Terminate SDK */
	/* ------------- */
	ErrCode |= STSDK_Term(SDK_TERM_DRIVER_LAYER|SDK_TERM_MIDDLE_LAYER|SDK_TERM_MODULE_LAYER|SDK_TERM_SECURITY|SDK_TERM_DEBUG_LAYER|SDK_TERM_TESTTOOL_SYNC|SDK_TERM_APPLICATION_LAYER);

	/* Return error code */
	/* ----------------- */
	if (ErrCode == ST_NO_ERROR)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
#endif

/* ========================================================================
   Name:        STSDK_Init
   Description: Initialize the SDK tree
   ======================================================================== */

ST_ErrorCode_t STSDK_Init(U32 SDK_Mode)
{
	ST_ErrorCode_t ErrCode = ST_NO_ERROR;
	U32            ErrDriverLayer[2] = {0, 0}, ErrMiddleLayer[2] = {0, 0}, ErrModuleLayer[2] = {0, 0}, ErrAppliLayer[2]={0, 0};

	/* Initialize driver layer */
	/* ----------------------- */
	if (SDK_Mode & SDK_INIT_DRIVER_LAYER)
	{
		if (SYS_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 0); /* Kernel + memory + cache + system clocks */
		}
		if (PIO_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 1); /* Configure the Pio pins                  */
		}
		if (UART_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 2); /* Configure the Uart ports                */
		}
		if (TBX_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 3); /* Configure the STAPI Trace module        */
		}
//		if (TRACE_Init(TRACE_UART_ID) != ST_NO_ERROR)
//		{
//			ErrDriverLayer[0] |= (1 << 4); /* Configure the Trace driver              */
//		}
		if (EVT_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 5); /* Configure the Event handler             */
		}
		if (I2C_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 6); /* Configure the I2C ports                 */
		}
		if (SPI_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 7); /* Configure the SPI interface             */
		}
		if (PWM_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 8); /* Configure the PWM                       */
		}
		if (FLASH_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 9); /* Configure the Flash drivers             */
		}
		if (DMA_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 <<10); /* Configure the DMA engines               */
		}
		if (PCPD_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 11); /* Configure the PCPD driver               */
		}
		if (SCART_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 12); /* Configure the SCARTs                    */
		}
		if (TUNER_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 13); /* Configure the Tuners                    */
		}
		if (DEMUX_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 14); /* Configure the Demux (Merger+Pti)        */
		}
		if (INJECT_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1<<15); /* Configure the Inject interface          */
		}
		if (CLKRV_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 16); /* Configure the Clock recovery            */
		}
		if (DENC_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 17); /* Configure the DENC output               */
		}
		if (VTG_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 18); /* Configure the VTG time generators       */
		}
		if (VOUT_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 19); /* Configure the VOS output                */
		}
		if (LAYER_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 20); /* Configure the Video layers              */
		}
		if (VBI_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 21); /* Configure the VBI interface             */
		}
		if (BLIT_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 22); /* Configure the Bitter                    */
		}
		if (GRAFIX_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 23); /* Configure the Graphic layers            */
		}
		if (VMIX_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 24); /* Configure the Mixers                    */
		}
		if (VID_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 25); /* Configure the Video drivers             */
		}
		if (AUD_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 26); /* Configure the Audio drivers             */
		}
		if (BLAST_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 27); /* Configure the Blast driver              */
		}
		if (USB_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 28); /* Configure the USB interface             */
		}
		if (GAMLOAD_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 29); /* Configure the GAM loader                */
		}
		if (CRYPT_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 0); /* Configure the CRYPT interface           */
		}
		if (ATAPI_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 1); /* Configure the ATAPI interface           */
		}
		if (SMART_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 2); /* Configure the Smartcard interface       */
		}
		if (HDMI_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 3); /* Configure the HDMI interface            */
		}
		if (KEYSCN_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 4); /* Configure the KEYSCAN interface         */
		}
		if (VIN_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 5); /* Configure the VIN interface             */
		}
		if (TTX_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 6); /* Configure the Teletext driver           */
		}
		if (CC_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 7); /* Configure the Close caption driver      */
		}
		if (POD_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 8); /* Configure the POD interface             */
		}
		if (MOCA_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 9); /* Configure the MoCA interface            */
		}
		if (PCCRD_Init() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 10); /* Configure the PCCRD interface           */
		}
		if (GRAFIX_DFBInit() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 11); /* Configure the GRAFIX-DirectFB interface */
		}
		if (SmoothStreaming_Init() != ST_NO_ERROR)
		{
		    ErrDriverLayer[1] |= (1 << 12); /* Configure the smoothstreaming interface */
		}
	 }

	/* Initialize middle layer */
	/* ----------------------- */
	if (SDK_Mode & SDK_INIT_MIDDLE_LAYER)
	{
		if (TCPIP_Init() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 0); /* Initialize TCP/IP stack                 */
		}
		if (VFS_Init() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 1); /* Initialize the file system              */
		}
		if (PLAYREC_Init() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 2); /* Initialize the play and record manager  */
		}
		if (SUBT_Init() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 3); /* Initialize the Subtitle driver          */
		}
	}

	/* Initialize module layer */
	/* ----------------------- */
	if (SDK_Mode & SDK_INIT_MODULE_LAYER)
	{
		if (MODULES_Init() != ST_NO_ERROR)
		{
			ErrModuleLayer[0] |= (1 << 0); /* Initialize the modules                  */
		}
	}

	/* Initialize Security */
	/* ------------------- */
	if (SDK_Mode&SDK_INIT_SECURITY)
	{
		if (SECMODULES_Init() != ST_NO_ERROR)
		{
			ErrModuleLayer[0] |= (1 << 0); /* Initialize the secmodules               */
		}
	}

	/* Initialize application layer */
	/* ---------------------------- */
	if (SDK_Mode & SDK_INIT_APPLICATION_LAYER)
	{
		if (GUI_Init( ) != ST_NO_ERROR)
		{
			ErrAppliLayer[0] |= (1 << 0);  /* Initialize the GUI interface            */
		}
	}

	/* Initialize testtool */
	/* ------------------- */
	TesttoolInit(TESTTOOL_UART_ID);

	/* Print information */
	/* ----------------- */
	print("\n");
	print("===================================================\n");
	print("    SDK - Software development kit debug environment\n");
//	print("    PLATFORM : %s\n", __PLATFORM_NAME__);
//	print("    OS       : %s - %s\n", __OS_NAME__, Kernel_Version());
	print("    VERSION  : %s at %s\n", __DATE__, __TIME__);
	print("===================================================\n\n");
	print("STAPI_SDK Revision : %s\n", STSDK_GetRevision());

	/* Check initialization */
	/* -------------------- */
	if ((ErrDriverLayer[0] != 0) || (ErrDriverLayer[1] != 0))
	{
		ErrCode |= SDK_INIT_DRIVER_LAYER_FAILED;
		print("\nWARNING : Errors encountered during initialization of the driver layer, code = 0x%08x%08x failure summary :\n",ErrDriverLayer[1],ErrDriverLayer[0]);
		if (ErrDriverLayer[0] & (1 << 0))
		{
			print("          - SYS_Init()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 1))
		{
			print("          - PIO_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 2))
		{
			print("          - UART_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 3))
		{
			print("          - TBX_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 4))
		{
			print("          - TRACE_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 5))
		{
			print("          - EVT_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 6))
		{
			print("          - I2C_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 7))
		{
			print("          - SPI_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 8))
		{
			print("          - PWM_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 9))
		{
			print("          - FLASH_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 10))
		{
			print("         - DMA_Init()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 11))
		{
			print("         - PCPD_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 12))
		{
			print("         - SCART_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 13))
		{
			print("         - TUNER_Init()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 14))
		{
			print("         - DEMUX_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 15))
		{
			print("         - INJECT_Init()    Failure");
		}
		if (ErrDriverLayer[0] & (1 << 16))
		{
			print("         - CLKRV_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 17))
		{
			print("         - DENC_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 18))
		{
			print("         - VTG_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 19))
		{
			print("         - VOUT_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 20))
		{
			print("         - LAYER_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 21))
		{
			print("         - VBI_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 22))
		{
			print("         - BLIT_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 23))
		{
			print("         - GRAFIX_Init()    Failure");
		}
		if (ErrDriverLayer[0] & (1 << 24))
		{
			print("         - VMIX_Init()      Failure");
		}
		if (ErrDriverLayer[0] & (1 << 25))
		{
			print("         - VID_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 26))
		{
			print("         - AUD_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 27))
		{
			print("         - BLAST_Init()     Failure");
		}
		if (ErrDriverLayer[0] & (1 << 28))
		{
			print("         - USB_Init()       Failure");
		}
		if (ErrDriverLayer[0] & (1 << 29))
		{
			print("         - GAMLOAD_Init()   Failure");
		}
		if (ErrDriverLayer[1] & (1 << 0))
		{
			print("          - CRYPT_Init()     Failure");
		}
		if (ErrDriverLayer[1] & (1 << 1))
		{
			print("          - ATAPI_Init()     Failure");
		}
		if (ErrDriverLayer[1] & (1 << 2))
		{
			print("          - SMART_Init()     Failure");
		}
		if (ErrDriverLayer[1] & (1 << 3))
		{
			print("          - HDMI_Init()      Failure");
		}
		if (ErrDriverLayer[1] & (1 << 4))
		{
			print("          - KEYSCN_Init()    Failure");
		}
		if (ErrDriverLayer[1] & (1 << 5))
		{
			print("          - VIN_Init()       Failure");
		}
		if (ErrDriverLayer[1] & (1 << 6))
		{
			print("          - TTX_Init()       Failure");
		}
		if (ErrDriverLayer[1] & (1 << 7))
		{
			print("          - CC_Init()        Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 8))
		{
			print("          - POD_Init()       Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 9))
		{
			print("          - MOCA_Init()      Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 10))
		{
			print("         - PCCRD_Init()     Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 11))
		{
			print("         - GRAFIX_DFBInit() Failure\n");
		}
	}
	if ((ErrMiddleLayer[0] != 0) || (ErrMiddleLayer[1] != 0))
	{
		ErrCode |= SDK_INIT_MIDDLE_LAYER_FAILED;
		print("\nWARNING : Errors encountered during initialization of the middle layer, code = 0x%08x%08x failure summary :\n",ErrMiddleLayer[1],ErrMiddleLayer[0]);
		if (ErrMiddleLayer[0] & (1 << 0))
		{
			print("          - TCPIP_Init()   Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 1))
		{
			print("          - VFS_Init()     Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 2))
		{
			print("          - PLAYREC_Init() Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 3))
		{
			print("          - SUBT_Init()    Failure\n");
		}
	}
	if ((ErrModuleLayer[0] != 0) || (ErrModuleLayer[1] != 0))
	{
		ErrCode |= SDK_INIT_MODULE_LAYER_FAILED;
		print("\nWARNING : Errors encountered during initialization of the module layer, code = 0x%08x%08x failure summary :\n",ErrModuleLayer[1],ErrModuleLayer[0]);
		if (ErrModuleLayer[0] & (1 << 0))
		{
			print("          - MODULES_Init() Failure\n");
		}
	}
	if ((ErrAppliLayer[0] != 0) || (ErrAppliLayer[1] != 0))
	{
		ErrCode |= SDK_INIT_APPLICATION_LAYER_FAILED;
		print("\nWARNING : Errors encountered during initialization of the appli  layer, code = 0x%08x%08x failure summary :\n",ErrAppliLayer[1],ErrAppliLayer[0]);
		if (ErrAppliLayer[0] & (1 << 0))
		{
			print("          - GUI_Init()      Failure\n");
		}
	}

	/* Declare debug commands */
	/* ---------------------- */
	if (SDK_Mode & SDK_INIT_DEBUG_LAYER)
	{
		POD_Debug();
		SYS_Debug();
		I2C_Debug();
		SPI_Debug();
		PWM_Debug();
		TUNER_Debug();
		DEMUX_Debug();
		PIO_Debug();
		DENC_Debug();
		VTG_Debug();
		GRAFIX_Debug();
		SCART_Debug();
		BLAST_Debug();
		USB_Debug();
		VID_Debug();
		AUD_Debug();
		ATAPI_Debug();
		VFS_Debug();
		PLAYREC_Debug();
		TRACE_Debug();
		MISC_Debug();
		TABLE_Debug();
		TCPIP_Debug();
		TCPIP_Debug6();
		CLKRV_Debug();
		VMIX_Debug();
		SMART_Debug();
		GUI_Debug();
		DMA_Debug();
		BLIT_Debug();
		HDMI_Debug();
		RACK_Debug();
		CRYPT_Debug();
		DRM_Debug();
		FLASH_Debug();
		KEYSCN_Debug();
		SUBT_Debug();
		VIN_Debug();
		VOUT_Debug();
		TTX_Debug();
		CC_Debug();
		PCPD_Debug();
		POWER_Debug();
		VBI_Debug();
		RESET_Debug();
		MOCA_Debug();
		RM_Debug();
		PCCRD_Debug();
		MODULES_Debug();
		SmoothStreaming_Debug();
		SECMODULES_Debug();
	}

	/* Start testtool in a task */
	/* ------------------------ */
	if (SDK_Mode & SDK_INIT_TESTTOOL_TASK)
	{
		TesttoolRun(FALSE);
	}

	/* Start testtool synchronously */
	/* ---------------------------- */
	if (SDK_Mode & SDK_INIT_TESTTOOL_SYNC)
	{
		TesttoolRun(TRUE);
	}
	/* Return error code */
	/* ----------------- */
	return(ErrCode);
}

/* ========================================================================
   Name:        STSDK_Term
   Description: Terminate the SDK tree
   ======================================================================== */

ST_ErrorCode_t STSDK_Term(U32 SDK_Mode)
{
	ST_ErrorCode_t ErrCode = ST_NO_ERROR;
	U32            ErrDriverLayer[2] = {0, 0}, ErrMiddleLayer[2] = {0, 0}, ErrModuleLayer[2] = {0, 0}, ErrAppliLayer[2] = {0, 0};

	/* Terminate testtool */
	/* ------------------ */
	if ((SDK_Mode & SDK_TERM_TESTTOOL_SYNC) || (SDK_Mode & SDK_TERM_TESTTOOL_TASK))
	{
		TesttoolTerm(TESTTOOL_UART_ID);
	}

	/* Terminate application layer */
	/* --------------------------- */
	if (SDK_Mode & SDK_TERM_APPLICATION_LAYER)
	{
		if (GUI_Term() != ST_NO_ERROR)
		{
			ErrAppliLayer[0] |= (1 << 0);  /* Terminate the GUI interface            */
		}
	}

	/* Terminate security */
	/* ------------------ */
	if (SDK_Mode & SDK_TERM_SECURITY)
	{
		if (SECMODULES_Term() != ST_NO_ERROR)
		{
			ErrModuleLayer[0] |= (1 << 0); /* Terminate the secmodules               */
		}
	}

	/* Terminate module layer */
	/* ---------------------- */
	if (SDK_Mode & SDK_TERM_MODULE_LAYER)
	{
		if (MODULES_Term() != ST_NO_ERROR)
		{
			ErrModuleLayer[0] |= (1 << 0); /* Terminate the modules                  */
		}
	}

	/* Terminate middle layer */
	/* ---------------------- */
	if (SDK_Mode & SDK_TERM_MIDDLE_LAYER)
	{
		if (SUBT_Term() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 3); /* Terminate the Subtitle driver          */
		}
		if (PLAYREC_Term() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 2); /* Terminate the play and record manager  */
		}
		if (VFS_Term() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 1); /* Terminate the file system              */
		}
		if (TCPIP_Term() != ST_NO_ERROR)
		{
			ErrMiddleLayer[0] |= (1 << 0); /* Terminate TCP/IP stack                 */
		}
	}

	/* Terminate driver layer */
	/* ----------------------- */
	if (SDK_Mode & SDK_TERM_DRIVER_LAYER)
	{
		if (SmoothStreaming_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 12);/* Terminate the smoothstreaming interface */
		}
		if (GRAFIX_DFBTerm() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 11);/* Terminate the GRAFIX-DirectFB interface */
		}
		if ( PCCRD_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 10);/* Terminate the PCCRD interface           */
		}
		if (MOCA_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 9); /* Terminate the MOCA interface            */
		}
		if (POD_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 8); /* Terminate the POD interface             */
		}
		if (CC_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 7); /* Terminate the Close caption driver      */
		}
		if (TTX_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 6); /* Terminate the Teletext driver           */
		}
		if (VIN_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 5); /* Terminate the VIN interface             */
		}
		if (KEYSCN_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 4); /* Terminate the KEYSCAN interface         */
		}
		if (HDMI_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 3); /* Terminate the HDMI interface            */
		}
		if (SMART_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 2); /* Terminate the Smartcard interface       */
		}
		if (ATAPI_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 1); /* Terminate the ATAPI interface           */
		}
		if (CRYPT_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[1] |= (1 << 0); /* Terminate the CRYPT interface           */
		}
		if (GAMLOAD_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 29); /* Terminate the GAM loader                */
		}
		if (USB_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 28); /* Terminate the USB interface             */
		}
		if (BLAST_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 27); /* Terminate the Blast driver              */
		}
		if (AUD_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 26); /* Terminate the Audio drivers             */
		}
		if (VID_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 25); /* Terminate the Video drivers             */
		}
		if (VMIX_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 24); /* Terminate the Mixers                    */
		}
		if (GRAFIX_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 23); /* Terminate the Graphic layers            */
		}
		if (BLIT_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 22); /* Terminate the Bitter                    */
		}
		if (VBI_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 21); /* Terminate the VBI interface             */
		}
		if (LAYER_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 20); /* Terminate the Video layers              */
		}
		if (VOUT_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 19); /* Terminate the VOS output                */
		}
		if (VTG_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 18); /* Terminate the VTG time generators       */
		}
		if (DENC_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 17); /* Terminate the DENC output               */
		}
		if (CLKRV_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 16); /* Terminate the Clock recovery            */
		}
		if (INJECT_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 15); /* Terminate the Inject interface          */
		}
		if (DEMUX_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 14); /* Terminate the Demux (Merger+Pti)        */
		}
		if (TUNER_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 13); /* Terminate the Tuners                    */
		}
		if (SCART_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 12); /* Terminate the SCARTs                    */
		}
		if (PCPD_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 11); /* Terminate the PCPD driver               */
		}
		if (DMA_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 10); /* Terminate the DMA engines               */
		}
		if (FLASH_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 9); /* Terminate the Flash drivers             */
		}
		if (PWM_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 8); /* Terminate the PWM                       */
		}
		if (SPI_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 7); /* Terminate the SPI interface             */
		}
		if (I2C_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 6); /* Terminate the I2C ports                 */
		}
		if (EVT_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 5); /* Terminate the Event handler             */
		}
//		if (TRACE_Term(TRACE_UART_ID) != ST_NO_ERROR)
//		{
//			ErrDriverLayer[0] |= (1 << 4); /* Terminate the Trace driver              */
//		}
		if (TBX_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 3); /* Terminate the STAPI Trace module        */
		}
		if (UART_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 2); /* Terminate the Uart ports                */
		}
		if (PIO_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 1); /* Terminate the Pio pins                  */
		}
		if (SYS_Term() != ST_NO_ERROR)
		{
			ErrDriverLayer[0] |= (1 << 0); /* Kernel + memory + cache + system clocks */
		}
	}

	/* Check terminate */
	/* --------------- */
	if ((ErrAppliLayer[0] != 0) || (ErrAppliLayer[1] != 0))
	{
		ErrCode |= SDK_TERM_APPLICATION_LAYER_FAILED;
		print("\nWARNING : Errors encountered during terminate of the appli  layer, code = 0x%08x%08x failure summary :\n",ErrAppliLayer[1],ErrAppliLayer[0]);
		if (ErrAppliLayer[0] & (1 << 0))
		{
			print("          - GUI_Term()      Failure\n");
		}
	}
	if ((ErrModuleLayer[0] != 0) || (ErrModuleLayer[1] != 0))
	{
		ErrCode|=SDK_TERM_MODULE_LAYER_FAILED;
		print("\nWARNING : Errors encountered during terminate of the module layer, code = 0x%08x%08x failure summary :\n",ErrModuleLayer[1],ErrModuleLayer[0]);
		if (ErrModuleLayer[0] & (1 << 0))
		{
			print("          - MODULES_Term() Failure\n");
		}
	}
	if ((ErrMiddleLayer[0] != 0) || (ErrMiddleLayer[1] != 0))
	{
		ErrCode |= SDK_TERM_MIDDLE_LAYER_FAILED;
		print("\nWARNING : Errors encountered during terminate of the middle layer, code = 0x%08x%08x failure summary :\n",ErrMiddleLayer[1],ErrMiddleLayer[0]);
		if (ErrMiddleLayer[0] & (1 << 0))
		{
			print("          - TCPIP_Term()   Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 1))
		{
			print("          - VFS_Term()     Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 2))
		{
			print("          - PLAYREC_Term() Failure\n");
		}
		if (ErrMiddleLayer[0] & (1 << 3))
		{
			print("          - SUBT_Term()    Failure\n");
		}
	}
	if ((ErrDriverLayer[0]!=0)||(ErrDriverLayer[1]!=0))
	{
		ErrCode|=SDK_TERM_DRIVER_LAYER_FAILED;
		print("\nWARNING : Errors encountered during terminate of the driver layer, code = 0x%08x%08x failure summary :\n",ErrDriverLayer[1],ErrDriverLayer[0]);
		if (ErrDriverLayer[1] & (1 << 11))
		{
			print("          - GRAFIX_DFBInit() Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 10))
		{
			print("          - PCCRD_Term()     Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 9))
		{
			print("          - MOCA_Term()      Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 8))
		{
			print("          - POD_Term()       Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 7))
		{
			print("          - CC_Term()        Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 6))
		{
			print("          - TTX_Term()       Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 5))
		{
			print("          - VIN_Term()       Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 4))
		{
			print("          - KEYSCN_Term()    Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 3))
		{
			print("          - HDMI_Term()      Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 2))
		{
			print("          - SMART_Term()     Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 1))
		{
			print("          - ATAPI_Term()     Failure\n");
		}
		if (ErrDriverLayer[1] & (1 << 0))
		{
			print("          - CRYPT_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 29))
		{
			print("          - GAMLOAD_Term()   Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 28))
		{
			print("          - USB_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 27))
		{
			print("          - BLAST_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 26))
		{
			print("          - AUD_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 25))
		{
			print("          - VID_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 24))
		{
			print("          - VMIX_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 23))
		{
			print("          - GRAFIX_Term()    Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 22))
		{
			print("          - BLIT_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 21))
		{
			print("          - VBI_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 20))
		{
			print("          - LAYER_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 19))
		{
			print("          - VOUT_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 18))
		{
			print("          - VTG_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 17))
		{
			print("          - DENC_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 16))
		{
			print("          - CLKRV_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 15))
		{
			print("          - INJECT_Term()    Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 14))
		{
			print("          - DEMUX_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 13))
		{
			print("          - TUNER_Init()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 12))
		{
			print("          - SCART_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 11))
		{
			print("          - PCPD_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 10))
		{
			print("          - DMA_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 9))
		{
			print("          - FLASH_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 8))
		{
			print("          - PWM_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 7))
		{
			print("          - SPI_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 6))
		{
			print("          - I2C_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 5))
		{
			print("          - EVT_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 4))
		{
			print("          - TRACE_Term()     Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 3))
		{
			print("          - TBX_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 2))
		{
			print("          - UART_Term()      Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 1))
		{
			print("          - PIO_Term()       Failure\n");
		}
		if (ErrDriverLayer[0] & (1 << 0))
		{
			print("          - SYS_Term()       Failure\n");
		}
	}
	/* Return error code */
	/* ----------------- */
	return(ErrCode);
}

/* ========================================================================
   Name:        STSDK_GetRevision
   Description: Return the version of the SDK tree
   ======================================================================== */

ST_Revision_t STSDK_GetRevision(void)
{
	return("STAPI_SDK-REL_41.2");
}
// vim:ts=4
