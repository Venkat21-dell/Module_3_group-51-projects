#include "MyStm32f407xx.h"
void delay(void)
{
	for(unit32_t i=0; i<500000;i++)
}
int main(void)
{
    GPIO_Handle_t  GpioLed;
    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_MODE_OUT;
    GpioLed.GPIO_PinComfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPTO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    	while(1)
    	{
    		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
    		delay();
    	}


}
