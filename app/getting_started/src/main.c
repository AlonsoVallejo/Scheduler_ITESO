/****************************************************************************************************/
/**
  \mainpage
  \n 
  \brief        Main application (main module)
  \author       Abraham Tezmol Otero, M.S.E.E
  \project      Tau 
  \version      1.0
  \date         12/Jun/2016
   
  Program compiled with  WinIDEA Open Build 9.12.256 (54401), tested on Atmel SAMV71 Xplained Ultra
*/
/****************************************************************************************************/


/*~~~~~~  Headers ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/** Main group of includes for board definitions, chip definitions and type definitions */
#include    "board.h"
/** Task scheduler definitions */
#include    "app_scheduler.h"
/** LED control definitions */
#include    "led_ctrl.h"
/** EDGB GPIO control definitions */
#include    "ECU Abstraction/EDGB/EDGB_GPIO.h"
/** EDGB SPI control definitions */
#include    "ECU Abstraction/EDGB/EDGB_SPI.h"
/** UART communication */
#include    "serial_ctrl.h"
/** Watchdog control function prototypes definitions */
#include    "../src/Services/Watchdog Timer Control/wdt_ctrl.h"
/** Dynamic Memory allocation services */
#include    "../src/Services/Memory/memory_allocation.h"

/*~~~~~~  Local definitions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~  Global variables ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*~~~~~~  Local functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
/**
 *  \brief getting-started Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
extern int main( void )
{
	
	/* Disable watchdog */
	vfnWdtCtrl_Disable();
	/* Enable I and D cache */
	/* SCB_EnableDCache(); */
	SCB_EnableICache();
	/* Configure LED */
	vfnLedCtrl_Configure();
	/* Configure EDGB_GPIO */
	vfn_EDGB_GPIOCtrl_Configure();
	/* Configure EDGB_SPI */
	vfn_EDGB_SPI_Configure();
	/* Configure Non-preemtive scheduler */
	vfnScheduler_Init();
	/* Start scheduler */
	vfnScheduler_Start();
	
	/* Once all the basic services have been started, go to infinite loop to serviced activated tasks */
	for(;;)
    {
		vfnTask_Scheduler();
	}
}
