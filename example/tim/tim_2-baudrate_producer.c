/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @File-description:show how to use firmware library to
 *                   use timer_2 as a baudrate producer
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#include "conf.h"
  
/*
 * @Protype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:init MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    /* set baudrate as 9600bps */
    uc.baudrate = 9600;
    uc.baudGenerator = PERIPH_TIM_2;
    uc.interruptState = ENABLE;
    uc.interruptPriority = DISABLE;
    uc.mode = UART_mode_1;
    uc.multiBaudrate = DISABLE;
    uc.receiveState  = ENABLE;
    
    UART_config(&uc);
    enableAllInterrupts();
}

/* ----- @main ----- */
void main(void)
{
    sys_init();
    while(true)
    {
        /* send per 500ms */
        sleep(500);
        UART_sendString("Hello,world\r\n");
	}
}

