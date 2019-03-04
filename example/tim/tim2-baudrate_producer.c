/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use HML_FwLib_STC90 to use timer-2 as a baud rate producer
 * @Test-board:ZS5110
 * @Test-mcu:STC90C53RC
 * @Version:V0
 */

#include "conf.h"
  
/*
 * @Prototype:void sys_init(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:initial MCU
 */
void sys_init(void)
{
    UART_configTypeDef uc;
    
    /* set baud rate as 9600bps */
    uc.baudrate          = 9600;
    uc.baudGenerator     = PERIPH_TIM_2;
    uc.interruptState    = ENABLE;
    uc.interruptPriority = INTR_priority_0;
    uc.mode              = UART_mode_1;
    uc.multiBaudrate     = DISABLE;
    uc.receiveState      = ENABLE;
    
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

