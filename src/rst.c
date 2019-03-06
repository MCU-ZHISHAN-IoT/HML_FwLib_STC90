/*
 * @Author:
 *  #Jiabin Hsu | zsiothsu(at)zhishan-iot.tk
 * @E-mail:mcu(at)zhishan-iot.tk
 * @File-description:operations of reset resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90-RC/RD+ series
 * @Version:V0
 */

#include "rst.h"
 
#ifdef ___COMPILE_RST___

/*
 * @Prototype:void RST_reset(RST_bootarea area)
 * @Parameter:(1)area:boot area
 * @Ret-val:
 * @Note:resets module and chooses area the module boots from
 */
void RST_reset(RST_bootarea area)
{
    SET_BIT_MASK(ISP_CONTR,ISPEN);
    CONFB(ISP_CONTR,BIT_NUM_SWBS,area);
    SET_BIT_MASK(ISP_CONTR,SWRST);
}

#endif
