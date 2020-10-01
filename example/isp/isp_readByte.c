/*****************************************************************************/
/** 
 * \file        isp_readByte.c
 * \author      Amy Chung | zhongliguo@zhishan-iot.tk
 * \date        
 * \brief       show how to use HML_FwLib_STC90 to use ISP to write and read byte
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
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = UTIL_interruptPriority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;

    UART_config(&uc);
    enableAllInterrupts();

    GPIO_configBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_0, SET);
    ISP_cmd(ENABLE);
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

    if(ISP_readByte(ISP_ADDR_START) == 'T')
    {
        /**
         * \note reset the module.if 'T' were written successfully,
         *       P10 will be lighted
         */
        GPIO_configBitValue(PERIPH_GPIO_1, PERIPH_GPIO_PIN_0, RESET);
        ISP_eraseByte(ISP_ADDR_START);
    }
    else
    {
        ISP_writeByte(ISP_ADDR_START, 'T');
        UART_sendByte(ISP_readByte(ISP_ADDR_START));  /* show result */
    }

    while(true);
}