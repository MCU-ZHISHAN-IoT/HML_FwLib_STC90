/*****************************************************************************/
/** 
 * \file       gpio_toggleIo.c
 * \author     Amy Chung | zhongliguo(at)zhishan-iot.tk
 * \date       
 * \brief      a example which shows how to control target GPIO pin
 * \note       
 * \version    v0.2
 * \ingroup    example
 * \remarks    test-board: ZS5110; test-MCU: STC90C53RC
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml.h"

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       main function
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void main(void)
{
    GPIO_resetBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    while(true)
    {
        sleep(500);
        GPIO_toggleBitValue(PERIPH_GPIO_4,PERIPH_GPIO_PIN_5);
    }
}
