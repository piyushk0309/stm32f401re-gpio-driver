



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
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_led.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;



	gpio_btn.pGPIOx = GPIOB;
	gpio_btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	gpio_btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	gpio_btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_btn.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PIN_PU;




	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_PeriClockControl(GPIOB, ENABLE);

	GPIO_Init(&gpio_led);
	GPIO_Init(&gpio_btn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOB,GPIO_PIN_NO_12)==0)
		{
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
		    delay();
		}
	}

	return 0;
}

