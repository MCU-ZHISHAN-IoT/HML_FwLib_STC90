/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations of reset resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#include "rst.h"

/*
 * @Protype:void RST_reset(RST_bootarea area)
 * @Parameter:(1)area:boot area
 * @Ret-val:
 * @Note:resets module and chooses area the module boots from
 */
void RST_reset(RST_bootarea area)
{
	ISP_CONTR = (ISP_CONTR & 0xBF) | (area << 0x6);
	ISP_CONTR = ISP_CONTR | 0x20; /* reset */
}