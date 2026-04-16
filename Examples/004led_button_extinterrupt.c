



#include "stm32f401xx_gpio_driver.h"
#include  <string.h>


void delay(void)
{
	for(uint32_t i=0;i<500000/2;i++);
}

int main (void)
{

	GPIO_Handle_t gpio_led;
	GPIO_Handle_t gpio_btn;
	memset(&gpio_led,0,sizeof(gpio_led));
	memset(&gpio_btn,0,sizeof(gpio_btn));



	gpio_led.pGPIOx = GPIOA;
	gpio_led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	gpio_led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	gpio_led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_led.GPIO_PinConfig.GPIO_PinOPType= GPIO_OP_TYPE_PP;
	gpio_led.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;



	gpio_btn.pGPIOx = GPIOA;
	gpio_btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	gpio_btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	gpio_btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	gpio_btn.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_PIN_PU;




	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Init(&gpio_led);
	GPIO_Init(&gpio_btn);



	//IRQ CONFIGURATIONS
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, 15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);


	while(1);
}

void EXTI9_5_IRQHandler(void)
{
	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_5);
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_12);
}

