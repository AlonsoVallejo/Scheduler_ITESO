/*
 * EDGB_SPI.h
 *
 *  Created on: 10/09/2017
 *      Author: inspiron  5567_I7
 */

#ifndef EDGB_SPI_H_
#define EDGB_SPI_H_

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */
#include "compiler.h"
#include "typedefs.h"
#include "spi.h"
#include "board.h"
/** Used modules */

/*****************************************************************************************************
* Declaration of module wide TYPEs
*****************************************************************************************************/

/* same order than spi_pins[] */
typedef enum
{
	PIN_SPI_MISO_SELECT,
	PIN_SPI_MOSI_SELECT,
	PIN_SPI_SPCK_SELECT,
	PIN_SPI_NPCS2_SELECT
}tPIN_SPI_;

typedef enum
{
	TASK1_COUNTER,
	TASK2_COUNTER,
	TASK3_COUNTER,
	TASK4_COUNTER,
	TOTAL_TASK_COUTNERS,
}tTASK_COUNTERS_;

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/
extern uint8_t ADP_Tx_DataBuff_TaskCounter[TOTAL_TASK_COUTNERS];
extern uint8_t ADP_Rx_DataBuff[];
/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
extern void vfn_EDGB_SPI_Configure(void);
extern void vfn_EDGB_SPI_EnableSlave(void);
extern void vfn_EDGB_SPI_DisableSlave(void);
extern uint32_t u32_EDGB_SPI_ReadData(void);
extern void vfn_EDGB_SPI_SendData(uint8_t TxData);
/**************************************************************************************************/



#endif /* EDGB_SPI_H_ */
