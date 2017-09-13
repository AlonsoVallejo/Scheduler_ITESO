/****************************************************************************************************/
/**
\file       app_tasks.c
\brief      Multi-thread Task scheduler - list of tasks.
\author     Abraham Tezmol
\version    1.0
\date       07/09/2013
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/** Scheduler function prototypes definitions */
#include    "app_tasks.h"

/*****************************************************************************************************
* Definition of  VARIABLEs - 
*****************************************************************************************************/


/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs 
*****************************************************************************************************/

/*****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/

/* List of tasks to be executed @ 3s */
void TASKS_LIST_3S( void )
{

}

/* List of tasks to be executed @ 1s */
void TASKS_LIST_1S( void )
{
	vfnLedCtrl_BlinkingPattern();
	vfn_EDGB_GPIO_BlinkingPattern(GPIO_PTA09_Select);
	ADP_Tx_DataBuff[0]++;
	vfn_EDGB_SPI_SendData(ADP_Tx_DataBuff[0]);

}
/* List of tasks to be executed @ 2s */
void TASKS_LIST_2S( void )
{

}
/* List of tasks to be executed @ 8s */
void TASKS_LIST_8S( void )
{ 

}


