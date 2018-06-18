/*
 * @Author:
 *  #Jiabin Hsu  | zsiothsu(at)zhishan-iot.ga
 *  #Weilun Fong | wlf(at)zhishan-iot.ga
 * @E-mail:mcu(at)zhishan-iot.ga
 * @File-description:operations for EXTI resource
 * @Required-compiler:SDCC
 * @Support-mcu:STC micro STC90 series
 * @Version:V0
 */

#include "exti.h"

/*
 * @Protype:void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef ec)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)ec:the pointer of config struct which includes all configuration information
 * @Note:config EXTI module
 */
void EXTI_config(PERIPH_EXTI exti,EXTI_configTypeDef *ec)
{
	EXTI_setMode(exti,ec->mode);
	EXTI_setPriority(exti,ec->priority);
}

/*
 * @Protype:void EXTI_cmd(PERIPH_EXTI exti,Action a)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)a:expected status
 * @Note:enable or disable EXTI module
 */
void EXTI_cmd(PERIPH_EXTI exti,Action a)
{
	switch(exti)
	{
		case PERIPH_EXTI_0:EX0 = a;break;
		case PERIPH_EXTI_1:EX1 = a;break;
		case PERIPH_EXTI_2:EX2 = a;break;
		case PERIPH_EXTI_3:EX3 = a;break;
		default:break;
	}
}

/*
 * @Protype:void EXTI_cmd(PERIPH_EXTI exti,Action a)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)mod:expected work mode
 * @Note:set work mode EXTI module
 */
void EXTI_setMode(PERIPH_EXTI exti,EXTI_MOD mod)
{
	switch(exti)
	{
		case PERIPH_EXTI_0:IT0 = mod;break;
		case PERIPH_EXTI_1:IT1 = mod;break;
		case PERIPH_EXTI_2:IT2 = mod;break;
		case PERIPH_EXTI_3:IT3 = mod;break;
		default:break;
	}
}

/*
 * @Protype:void EXTI_setPriority(PERIPH_EXTI exti,INTR_PIOR p)
 * @Parameter:
 *  (1)exti:target EXTI module
 *  (2)p:expected intterrupt priority class
 * @Note:set priority of EXTI module
 */
void EXTI_setPriority(PERIPH_EXTI exti,INTR_PIOR p)
{
	switch(exti)
	{
		case PERIPH_EXTI_0:
		{
			/* lower bit */
			IP  = (IP & 0xFE) | (p & 0x01);
			/* higher bit */
			IPH = (IPH & 0xFE) | ((p >> 0x1) & 0x01);
		} break;
		case PERIPH_EXTI_1:
		{
			/* lower bit */
			IP  = (IP & 0xFB) | ((p & 0x01) << 0x2);
			/* higher bit */
			IPH = (IPH & 0xFB) | ((p & 0x02) << 0x1);
		} break;
		case PERIPH_EXTI_2:
		{
			/* lower bit */
			PX2 = (p & 0x01);
			/* higher bit */
			IPH = (IPH & 0xBF) | ((p & 0x02)) << 0x6;
		} break;
		case PERIPH_EXTI_3:
		{
			/* lower bit */
			PX3 = (p & 0x01);
			/* higher bit */
			IPH = (IPH & 0x7F) | ((p & 0x02)) << 0x7;
		} break;
		default:break;
	}
}