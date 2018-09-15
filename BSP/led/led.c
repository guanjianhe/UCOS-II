#include "led.h"

/* 初始化LED */
void InitLed(void)
{
    /*定义一个GPIO_InitTypeDef类型的结构体*/
    GPIO_InitTypeDef GPIO_InitStructure;
	
    /*开启GPIOC外设时钟*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );

    /* 选择要控制的GPIOB引脚 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	
    /*设置引脚速率为50MHz */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
    /*设置引脚模式为通用推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
    /*调用库函数，初始化GPIOA*/
    GPIO_Init( GPIOA, &GPIO_InitStructure );
	
    /* 关闭led灯 */
    GPIO_SetBits( GPIOA, GPIO_Pin_8 );
}
