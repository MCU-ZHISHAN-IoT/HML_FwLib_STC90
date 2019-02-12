/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @File-description:show how to use firmware library to
 *                   use ISP to write and read byte
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#include "conf.h"

/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:init MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    uc.baudrate = 9600;
    uc.baudGenerator = PERIPH_TIM_2;
    uc.interruptState = ENABLE;
    uc.interruptPriority = DISABLE;
    uc.mode = UART_mode_1;
    uc.multiBaudrate = DISABLE;
    uc.receiveState  = ENABLE;
    
    UART_config(&uc);
    enableAllInterrupts();
    
    GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,SET);
    ISP_cmd(ENABLE);
}

/* ----- @main ----- */
void main(void)
{
    sys_init();
    
    if(ISP_readByte(ISP_ADDR_START) == 'T')
    {
        /* reset the module.if 'T' were written successfully,
        P10 will be lighted*/
        GPIO_configBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_0,RESET);
        ISP_eraseByte(ISP_ADDR_START);
    }
    else
    {
        ISP_writeByte(ISP_ADDR_START,'T');
        UART_sendByte(ISP_readByte(ISP_ADDR_START));  /* show result */
    }

    while(true);
}