/*
 * GPIO.h
 *
 *  Created on: 10/09/2017
 *      Author: inspiron  5567_I7
 */

#ifndef GPIO_H_
#define GPIO_H_

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
extern uint32_t GPIO_Configure( uint32_t GPIO );

extern uint32_t GPIO_Set( uint32_t GPIO );

extern uint32_t GPIO_Clear( uint32_t GPIO );

/*****************************************************************************************************
* Declaration of module wide TYPEs
*****************************************************************************************************/
/*Same order than array pinsGPIO[]*/
typedef enum
 {
	GPIO_PTA09_Select,
	GPIO_PTA23_Select,
	GPIO_PTD28_Select,
	GPIO_PTA2_Select
}tGPIO_SELECT;
/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs
*****************************************************************************************************/


/*****************************************************************************************************
* Declaration of module wide FUNCTIONS
*****************************************************************************************************/

#endif /* GPIO_H_ */
