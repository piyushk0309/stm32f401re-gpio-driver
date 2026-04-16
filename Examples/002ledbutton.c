/*
 * 002ledbutton.c
 *
 *  Created on: 07-Apr-2026
 *      Author: hp
 */


#include "stm32f401xx_gpio_driver.h"


void delay(void)
{
	for(uint32_t i=0;i<500000/2;i++);
}

int main (void)
{

	GPIO_Handle_t gpio_led;
	GPIO_Handle_t gpio_btn;


	gpio_led.pGPIOx = GPIOA;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_led.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PIN_PU;



	gpio_btn.pGPIOx = GPIOC;
	gpio_btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	gpio_btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	gpio_btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_btn.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;




	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_PeriClockControl(GPIOC, ENABLE);

	GPIO_Init(&gpio_led);
	GPIO_Init(&gpio_btn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13)==0)
		{
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		    delay();
		}
	}

	return 0;
}
