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
static const Pin spi_pins[] = {PIN_SPI_MISO,
							   PIN_SPI_MOSI,
							   PIN_SPI_SPCK,
							   PIN_SPI_NPCS2};

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
#define SPI0_CHIP_SELECT 2
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
	PIO_Configure(&spi_pins[PIN_SPI_MISO_SELECT], PIO_LISTSIZE(spi_pins));
	PIO_Configure(&spi_pins[PIN_SPI_MOSI_SELECT], PIO_LISTSIZE(spi_pins));
	PIO_Configure(&spi_pins[PIN_SPI_SPCK_SELECT], PIO_LISTSIZE(spi_pins));
	PIO_Configure(&spi_pins[PIN_SPI_NPCS2_SELECT], PIO_LISTSIZE(spi_pins));

	SPI_Configure(SPI0,
				  ID_SPI0,
				 (SPI_MR_MSTR | SPI_MR_MODFDIS | SPI_PCS( SPI0_CHIP_SELECT )));

	SPI_ConfigureNPCS(SPI0,
					  SPI0_CHIP_SELECT,
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
uint32_t vfn_EDGB_SPI_ReadData(void)
{
	volatile uint32_t Rx_Data;

	vfn_EDGB_SPI_EnableSlave();
	Rx_Data = SPI_Read(SPI0);
	return Rx_Data;
}

/*****************************************************************************************************/

/**
* \brief
* \author
* \param
* \return
*/
void vfn_EDGB_SPI_SendData(uint16_t TxData)
{
	vfn_EDGB_SPI_EnableSlave();
	SPI_Write(SPI0, SPI0_CHIP_SELECT, TxData);
}

