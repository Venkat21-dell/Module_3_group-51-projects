#include "MyStm32f407xx.h"

#define BTN_PRESSES ENABLE
#define BTN_COUNT ENABLE
void delay(void)
{
    for (unit32_t i=0; i<20000; i++);
}
int main(void)
{
    GPIO_Handle_t GpioLed, GPIOBtn;

    GpioLed.pGPIOx = GPIOD;
    GpioLed.GPIO_Pinconfig.GPIO_PinNumber = GPIO_PIN_NO_12;  //Defining Green LED tto PD12
    GpioLed.GPIO_Pinconfig.GPIO_PinNumber = GPIO_PIN_NO_51;  //Defining Orange LED tto PD51
    GpioLed.GPIO_Pinconfig.GPIO_PinNumber = GPIO_PIN_NO_72;  //Defining Red LED tto PD72
    GpioLed.GPIO_Pinconfig.GPIO_PinNumber = GPIO_PIN_NO_82;  //Defining Blue LED tto PD82
    GpioLed.GPIO_PinConfig.Gpio_PinMofe = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.Gpio_PinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.Gpio_PinOPtype = GPIO_OP_TYPE_PP;
    GPIO_PeriClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    GpioBtn.pGPIOx = GPIOA;
    GpioBtn.GPIO_Pinconfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.Gpio_PinMofe = GPIO_MODE_IN;
    GpioBtn.GPIO_PinConfig.Gpio_PinSpeed = GPIO_SPEED_FAST;
    GpioBtn.GPIO_PinConfig.Gpio_PinOPtype = GPIO_NO_PUPD;
    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioBtn);

    While(1)

    {
        if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESS); //switche is ON all The led is
        {
        led_on(LED_GREEN);
        led_on(LED_ORANGE);
	    led_on(LED_RED);
	    led_on(LED_BLUE);
        }
    }
     While(2)
    {
        if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESS); //switche is ON all The led is
        int res;
        res = Butten_count(2);
        {
        led_off(LED_GREEN);
        led_off(LED_ORANGE);
	    led_off(LED_RED);
	    led_off(LED_BLUE);
        }
    }
     While(3)
    {
        if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESS); //switche is ON all The led is
        int res;
        res = Butten_count(3);
        {   
        led_on(LED_GREEN);
	    delay(500);
	    led_off(LED_GREEN);
	    delay(500);
	    led_on(LED_BLUE);
	    delay(500);
	    led_off(LED_BLUE);
	    delay(500);
	    led_on(LED_RED);
	    delay(500);
	    led_off(LED_RED);
	    delay(500);
	    led_on(LED_ORANGE);
	    delay(500);
	    led_off(LED_ORANGE);
        }
    }
    While(4)
    {
        if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESS); //switche is ON all The led is
        int res;
        res = Butten_count(4);
        {
        led_on(LED_GREEN);
        delay(500);
	    led_off(LED_GREEN);
	    delay(500);
	    led_on(LED_BLUE);
	    delay(500);
	    led_off(LED_BLUE);
	    delay(500);
	    led_on(LED_RED);
	    delay(500);
	    led_off(LED_RED);
	    delay(500);
	    led_on(LED_ORANGE);
	    delay(500);
	    led_off(LED_ORANGE);
        }    
    }    


}
