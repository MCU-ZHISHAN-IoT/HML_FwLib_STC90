/*
 * @Author:
 *  #Amy Chung | zhongliguo@zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use firmware library to make a tim0 interruption
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
    TIM_configTypeDef tc;
    
    tc.function          = TIM_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = INTR_priority_0;
    tc.mode              = TIM_mode_1;
    tc.value             = TIM_calculateValue(50000,TIM_mode_1);
    
    TIM_config(PERIPH_TIM_0,&tc);
    TIM_cmd(PERIPH_TIM_0,ENABLE);
    enableAllInterrupts();
}

/* ----- @main ----- */
void main(void)
{
	sys_init();
	while(true);
}

/*
 * @Prototype:void tim0_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for timer-0
 */
void tim0_isr(void) __interrupt TF0_VECTOR
{
    static int cnt = 0;
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
        cnt = 0;
    }
}
