/*
 * @Author:
 *  #Amy Chung | zhongliguo(at)zhishan-iot.tk
 * @Compiler:SDCC v3.6.0
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:show how to use HML_FwLib_STC90 to make a timer interruption
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
    TIM2_configTypeDef tc;
    
    tc.function          = TIM2_function_tim;
    tc.interruptState    = ENABLE;
    tc.interruptPriority = INTR_priority_0;
    tc.mode              = TIM2_mode_0;
    tc.value             = TIM2_calculateValue(50000);
    
    TIM2_config(&tc);
    TIM2_cmd(ENABLE);
    enableAllInterrupts();
}

/* ----- @main ----- */
void main(void)
{
    sys_init();
    while(true);
}

/*
 * @Prototype:void TIM2_isr(void)
 * @Parameter:None
 * @Ret-val:None
 * @Note:interrupt service function for TIM2
 */
void TIM2_isr(void) __interrupt TF2_VECTOR
{
    static int cnt = 0;
    TIM2_clearFlag();
    
    /* per 500ms */
    cnt++;
    if(cnt == 10)
    {
        GPIO_toggleBitValue(PERIPH_GPIO_1,PERIPH_GPIO_PIN_2);
        cnt = 0;
    }
}
