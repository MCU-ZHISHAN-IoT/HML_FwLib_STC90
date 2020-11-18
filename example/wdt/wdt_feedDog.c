/*****************************************************************************/
/** 
 * \file        wdt_feedDog.c
 * \author      Amy Chung | zhongliguo@zhishan-iot.tk
 * \date        
 * \brief       a demo for on-chip watchdog
 * \note        
 * \version     v0.3
 * \ingroup     example
 * \remarks     test-board: ZS5110; test-MCU: STC90C53RC
******************************************************************************/

/*****************************************************************************
 *                             header file                                   *
 *****************************************************************************/
#include "hml/hml.h"

/*****************************************************************************/
/** 
 * \author      Amy Chung
 * \date        
 * \brief       initial MCU
 * \param[in]   
 * \return      none
 * \ingroup     example
 * \remarks     
******************************************************************************/
void sys_init(void)
{
    UART_configTypeDef uc;

    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_1;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
    enableAllInterrupts();
}

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
    sys_init();
    UART_sendString("MCU boot ...\n");
    WDT_setPrescale(WDT_prescale_32);
    WDT_cmd(ENABLE);

    while (true)
    {
        /* feed watchdog per 500ms */
        sleep(500);
        WDT_feed();
        UART_sendString("root@localboard:Watch dog has been fed\r\n");
    }
}
