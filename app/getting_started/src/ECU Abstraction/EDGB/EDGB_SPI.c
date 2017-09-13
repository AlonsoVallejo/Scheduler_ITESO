/*****************************************************************************************************
* Include files
*****************************************************************************************************/
/** Own headers */
#include     "EDGB_SPI.h"
/** Other modules */

/*****************************************************************************************************
* Definition of module wide VARIABLEs
*****************************************************************************************************/
/** Pins to configure for the application. */
static const Pin spi_pins[] = {PINS_SPI_EDGB};

uint8_t ADP_Tx_DataBuff[] = {0x00};
uint8_t ADP_Rx_DataBuff[] = {0x00};
/****************************************************************************************************
* Declaration of module wide FUNCTIONs
****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/

/****************************************************************************************************
* Declaration of module wide TYPEs
*****************************************************************************************************/

/****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs
*****************************************************************************************************/
#define SMC_SPI_EDGB_CS 2
/****************************************************************************************************
* Code of module wide FUNCTIONS
*****************************************************************************************************/

/*****************************************************************************************************/
/**
* \brief
* \author
* \param
* \return
*/

void vfn_EDGB_SPI_Configure(void)
{
	PIO_Configure(spi_pins, PIO_LISTSIZE(spi_pins));

	PMC_EnablePeripheral(ID_SPI0);

	SPI_Configure(SPI0,
				  ID_SPI0,
				 (SPI_MR_MSTR | SPI_PCS( SMC_SPI_EDGB_CS )));

	SPI_ConfigureNPCS(SPI0,
					  SMC_SPI_EDGB_CS,
					  SPI_CSR_CPOL | SPI_CSR_BITS_8_BIT | SPI_DLYBS(6, BOARD_MCK)  |SPI_DLYBCT(100, BOARD_MCK) |SPI_SCBR( 20000000, BOARD_MCK));


	SPI_Enable(SPI0);
}

/*****************************************************************************************************/
/**
* \brief
* \author
* \param
* \return
*/
void vfn_EDGB_SPI_EnableSlave(void)
{
	PIO_Clear(&spi_pins[PIN_SPI_NPCS2_SELECT]);
}

/*****************************************************************************************************/
/**
* \brief
* \author
* \param
* \return
*/
void vfn_EDGB_SPI_DisableSlave(void)
{
	PIO_Set(&spi_pins[PIN_SPI_NPCS2_SELECT]);
}

/*****************************************************************************************************/
/**
* \brief
* \author
* \param
* \return
*/
uint32_t u32_EDGB_SPI_ReadData(void)
{
	vfn_EDGB_SPI_EnableSlave();
	return SPI_Read(SPI0);
}

/*****************************************************************************************************/

/**
* \brief
* \author
* \param
* \return
*/
void vfn_EDGB_SPI_SendData(uint8_t TxData)
{
	vfn_EDGB_SPI_EnableSlave();
	SPI_Write(SPI0, SMC_SPI_EDGB_CS, TxData);
}

