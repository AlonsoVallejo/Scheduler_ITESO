/*******************************************************************************/
/**
\file       app_tasks.h
\brief      Tasks to be assigned to each execution thread of Task scheduler.
\author     Abraham Tezmol
\version    0.1
\date       10/Feb/2008
*/

#ifndef __APP_TASKS
#define __APP_TASKS

/*-- Includes ----------------------------------------------------------------*/
#include "compiler.h"
/* LED control definitions */ 
#include "led_ctrl.h"
/* UART communication */
#include "serial_ctrl.h"
/** Watchdog control function prototypes definitions */
#include "../Watchdog Timer Control/wdt_ctrl.h"
/** EDGB GPIO control definitions */
#include    "ECU Abstraction/EDGB/EDGB_GPIO.h"
/** EDGB SPI control definitions */
#include    "ECU Abstraction/EDGB/EDGB_SPI.h"
/*****************************************************************************************************
* Definition of module wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide TYPES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide MACROS / #DEFINE-CONSTANTS 
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/* List of tasks to be executed @ 3s */
void TASKS_LIST_3S( void );

/* List of tasks to be executed @ 1s, first group */
void TASKS_LIST_1S( void );
    
/* List of tasks to be executed @ 2s */
void TASKS_LIST_2S(  void );

/* List of tasks to be executed @ 8s */
void TASKS_LIST_8S( void );

/*============================================================================*/
#endif /*__APP_TASKS */
