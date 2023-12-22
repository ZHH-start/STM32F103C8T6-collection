#include "stm32f10x.h"                  /* Device header */
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"
#include "PWM.h"

int16_t speed;
uint16_t time;

/*
编码旋钮A接PA6, B接PA7
编码旋钮器占用TIM3
计时器中断占用TIM2用于每隔一秒读一次编码器转速
LED接PA0
*/

static void Init(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	Timer_Init();
	OLED_Init();
	Encoder_Init();
	PWM_Init();
}

int main(void) {
	Init();
	
	OLED_ShowString(1, 1, "Light:");
	
	while (1) {
		OLED_ShowNum(1, 7, GetLight(), 3);
	}
}


 
