#include <stdio.h>
#include "MyStm32f407xx.h"
#include<stdbool.h>


#define BTN_PRESSED ENABLE
/**
 * @brief This function runs successfully if encrypt is true
 * 
 * @return flag 
 */
int encrypt() // function made by K Mohammad Habeeb 

{ 
   bool flag = false;
   const int a = 123;
   const int b = 234;
   int result = a * b; // algorithm for encryption
   if(result==28782)
   {

      flag= true;
   }
   else{

      flag=false;
   }

   return flag;
}
   /**
    * @brief The delay function is declared for configuring the STM32 push button
    * 
    */
   void delay(void)
   {
      for (uint32_t i = 0; i < 5000000; i++);
   }
   /**
    * @brief Here we have made a function for alarm status, where all the LEDs are in off condition
    * 
    */
   void alarm_status (void)    // Code By Tanmay
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0); // Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0); // Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0); // Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 0); // Blue LED

   }
   /**
    * @brief Here we have made a function for window, where all the LEDs are in on condition
    * 
    */
   void window_status (void)    // Code by Sharath
   {
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);  // Green LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 1);  // Orange LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 1);  // Red LED
      GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, 1);   // Blue LED

   }
   /**
    * @brief Here we have made a function for car battery info, where all the LEDs are turned ON in clockwise sequence
    * 
    */
   void car_battery_info(void) // The logic for this function was given by Tanmay 
   {
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12); // Green LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13); // Orange LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);  // RED LED
      delay();
      GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);  // Blue LED
      delay();

   }
   /**
    * @brief Here we have made a function for door status, where all the LEDs are turned ON in anti-clockwise sequence
    * 
    */
   void Door_status(void) // The logic for this function was given by Sharath
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

      GpioLed.pGPIOx = GPIOD;                                    // The declaration of the pins is given by Anurag Tiwari
      GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;     // PIN D12 is Green LED
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
      GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;       // This part is contributed by K Mohammad Habib
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
            if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED)   // The function was dicussed and implemented by whole group
            {
               delay();
               count = count + 1;    // count is incremented when push button is pressed by the user
            }
            if (count == 3)  
            {
               window_status();
            }
            else if (count == 9)
            {
                alarm_status();
            }
            else if (count==18)
            {

               car_battery_info();
            }
            else if (count==27)
            {
               Door_status();
            }
         }
      }
   }