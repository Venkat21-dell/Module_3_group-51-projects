#include <stdio.h>
#include "MyStm32f407xx.h"
#include<stdbool.h>


#define BTN_PRESSED ENABLE

int encrypt() 

{ 
   bool flag = false;
   const int a = 123;
   const int b = 234;
   int result = a * b; //this is the algorithm for encryption
   if(result==28782)
   {

      flag= true;
   }
   else{

      flag=false;
   }

   return flag;
}
   
   void delay(void)
   {
      for (uint32_t i = 0; i < 5000000; i++);
   }
  
   void unlock (void)   
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0); //pin for Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0); //pin for Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0); //pin for Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0); //pin for Blue LED

   }
   
   void lock (void)   
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);  //pin for Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);  //pin for Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);  //pin for Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);   //pin for Blue LED

   }
   
   void alarm_activation_deactivation(void) 
   {
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12); // pin for Green LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13); // pin for Orange LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);  // pin for RED LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);  //pin for Blue LED
      delay();

   }
   
   void Approach_Light(void) 
   {
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15); // Blue LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14); // Red LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13); // Orange LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);  // Green LED
      delay();
      
   }
   int main(void)
   {   
      int count = 0;
      GPIO_Handle_t GpioLed, GPIOBtn, GpioLed1, GpioLed2, GpioLed3;

      GpioLed.pGPIOx = GPIOD;                                    
      GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;    
      GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed);

      GpioLed1.pGPIOx = GPIOD;
      GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;      // PIN D13 is Orange LED
      GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed1);

      GpioLed2.pGPIOx = GPIOD;
      GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;      // PIN D14 is Red LED
      GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
      GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed2);

      GpioLed3.pGPIOx = GPIOD;
      GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;     // PIN D15 is Blue LED
      GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;      
      GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
      GPIO_PeriClockControl(GPIOD, ENABLE);
      GPIO_Init(&GpioLed3);

      GPIOBtn.pGPIOx = GPIOA;
      GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;    // PIN A0 is Blue Switch
      GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
      GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
      GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
      GPIO_PeriClockControl(GPIOA, ENABLE);
      GPIO_Init(&GPIOBtn);
      
      if (encrypt())
      {

         while (1)
         {
            if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)   
            {
               delay();
               count = count + 1;    
            }
            if (count == 3)  
            {
               lock();
            }
            else if (count == 9)
            {
                unlock();
            }
            else if (count==18)
            {

               alarm_activation_deactivation();
            }
            else if (count==27)
            {
               Approach_Light();
            }
         }
      }
   }
