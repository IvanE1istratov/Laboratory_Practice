#include "../Inc/init.h"
uint8_t flag_GPIOF_12 = 0;  //Состояние пина F12

int main(void)
{
    //Включаем тактирование портов B, С, D, F, настраиваем пины В0 и В14 на выход
    GPIO_Init_Macros_GPIOB_GPIOC_GPIOD();  
    //Hастраиваем пины В7 на выход 
    GPIO_Init_GPIOB7(); 
    //Предварительно настраиваем пин F12 на выход                    
    GPIO_Init_CMSIS_GPIOF_OUTPUT();
 
    while (1)
    {
        //Кнопка 1 нажата
        if(BIT_READ(GPIOC_IDR, GPIO_PIN_8)){
            BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_14);   // Включение светодиода пина PB14
            if (flag_GPIOF_12 != 0){                // Если пин F12 настроен на выход
                GPIO_Init_CMSIS_GPIOF_INPUT();      // Настраиваем пин F12 на вход
                flag_GPIOF_12 = 0;                  // Взводим флан пин F12 вход
            }
        }
        else{
            BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_14); // Выключение светодиода пина PB14
        }

        //Для кнопки 2
        if(BIT_READ(GPIOD_IDR, GPIO_PIN_3)){
            BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_7);    // Включение светодиода пина PB7
            if (flag_GPIOF_12 != 1){                // Если пин F12 настроен на вход
                GPIO_Init_CMSIS_GPIOF_OUTPUT();     // Настраиваем пин F12 на выход
                flag_GPIOF_12 = 1;                  // Взводим флан пин F12 выход
            }
        }
            else{
                BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_7);  // Выключение светодиода пина PB7
        }


        //Если пин F12 настроен на вход
        if(flag_GPIOF_12 == 0){
            if(BIT_READ(GPIOF_IDR, GPIO_PIN_12)){       //Кнопка на пине PB7 нажата
                BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_0);    // Включение светодиода пина PB0
            }
            else{
                BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_0);  // Выключение светодиода пина PB0
            }
        }
        else{                                           //Если пин F12 настроен на выход
            BIT_SET(GPIOF_BSRR, GPIO_PIN_SET_12);       // Выключение светодиода пина PF12
        }
   }
}

