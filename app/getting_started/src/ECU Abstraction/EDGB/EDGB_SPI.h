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

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
extern void vfn_EDGB_SPI_Configure(void);
extern void vfn_EDGB_SPI_EnableSlave(void);
extern void vfn_EDGB_SPI_DisableSlave(void);
extern uint32_t vfn_EDGB_SPI_ReadData(void);
extern void vfn_EDGB_SPI_SendData(uint16_t TxData);
/**************************************************************************************************/



#endif /* EDGB_SPI_H_ */
