#include "ucos_ii.h"
#include "led.h"

#define  APP_TASK_START_PRIO                        4
#define  APP_TASK_START_STK_SIZE                    128

static   OS_STK      AppTaskStartStk[APP_TASK_START_STK_SIZE];


static  void  AppTaskStart (void *p_arg)
{
	(void)p_arg;
	InitLed();
	while(1)
	{
		GPIOA->ODR ^= GPIO_Pin_8;
        OSTimeDly(500);
	}
}
	

int main()
{
	OS_CPU_SysTickInit();
	
	OSInit();
	OSTaskCreate(AppTaskStart,
				(void *)0,
				(OS_STK *)&AppTaskStartStk[APP_TASK_START_STK_SIZE - 1],
				APP_TASK_START_PRIO );
	OSStart();
	
}
