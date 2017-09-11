/*-----------------------------------------------------------------------------
 *         Headers
 *----------------------------------------------------------------------------*/

#include "board.h"

/*------------------------------------------------------------------------------
 *         Local Variables
 *----------------------------------------------------------------------------*/
static const Pin pinsGPIO[] = {GPIO_PTA09,
							   GPIO_PTA23,
							   GPIO_PTD28,
							   GPIO_PTA2};

static const uint32_t numGPIO = PIO_LISTSIZE( pinsGPIO );
/*------------------------------------------------------------------------------
 *         Global Functions
 *----------------------------------------------------------------------------*/

/**
 *  Configures the pin associated with the given GPIO number. If the GPIO does
 *  not exist on the board, the function does nothing.
 *  \param GPIO  Number of the GPIO to configure.
 *  \return 1 if the gpio exists and has been configured; otherwise 0.
 */
extern uint32_t GPIO_Configure( uint32_t GPIO )
{
#ifdef PINS_GPIO
	// Check that GPIO exists
	if ( GPIO >= numGPIO) {
		return 0;
	}

	// Configure GPIO
	return ( PIO_Configure( &pinsGPIO[GPIO], 1 ) );
#else
	return 0;
#endif
}

/**
 *  Turns the given GPIO on if it exists; otherwise does nothing.
 *  \param GPIO  Number of the LED to turn on.
 *  \return 1 if the GPIO has been turned on; 0 otherwise.
 */
extern uint32_t GPIO_Set( uint32_t GPIO )
{
#ifdef PINS_GPIO
	/* Check if GPIO exists */
	if ( GPIO >= numGPIO ) {
		return 0;
	}

	/* Turn GPIO on */
	if ( pinsGPIO[GPIO].type == PIO_OUTPUT_0 ) {
		PIO_Set( &pinsGPIO[GPIO] );
	} else {
		PIO_Clear( &pinsGPIO[GPIO] );
	}

	return 1;
#else
	return 0;
#endif
}

/**
 *  Turns a GPIO off.
 *
 *  \param led  Number of the GPIO to turn off.
 *  \return 1 if the GPIO has been turned off; 0 otherwise.
 */
extern uint32_t GPIO_Clear( uint32_t GPIO )
{
#ifdef PINS_GPIO
	/* Check if GPIO exists */
	if ( GPIO >= numGPIO ) {
		return 0;
	}

	/* Turn GPIO off */
	if ( pinsGPIO[GPIO].type == PIO_OUTPUT_0 ) {
		PIO_Clear( &pinsGPIO[GPIO] );
	} else {
		PIO_Set( &pinsGPIO[GPIO] );
	}

	return 1;
#else
	return 0;
#endif
}
