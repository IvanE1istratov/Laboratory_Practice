#include "../Inc/init.h"

//Включаем тактирование портов B, С, D, F, настраиваем пины В0 и В14 на выход
void GPIO_Init_Macros_GPIOB_GPIOC_GPIOD(void){
    //Включаем тактирование портов B, С, D, F
    BIT_SET(RCC_AHB1ENR, RCC_GPIOB_EN | RCC_GPIOC_EN | RCC_GPIOD_EN | RCC_GPIOF_EN );
    //Настраиваем пины В0 и В14 на выход
    BIT_SET(GPIOB_MODER, GPIO_OUTPUT_MODE_PIN_0 | GPIO_OUTPUT_MODE_PIN_14);   
    //Настраиваем pull-push подтягивание     
    BIT_CLEAR(GPIOB_OTYPER, GPIO_PP_PIN_0 | GPIO_PP_PIN_14);   
    //Настраиваем medium скорость тактирования выхода           
    BIT_SET(GPIOB_OSPEEDR, GPIO_SPEED_MEDIUM_PIN_0 | GPIO_SPEED_MEDIUM_PIN_14);   
    //Предварительно отключаем выходное значение пина     
    BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_0 | GPIO_PIN_RESET_14);         
}

//Hастраиваем пины В7 на выход 
void GPIO_Init_GPIOB7(void){
     //Настраиваем пин В7 на выход
     *(uint32_t *)(0x40020400UL + 0x00UL) |=  0x4000UL;
     //Настраиваем pull-push подтягивание
     *(uint32_t *)(0x40020400UL + 0x04UL) &= ~0x80UL;
     //Настраиваем medium скорость тактирования выхода
     *(uint32_t *)(0x40020400UL + 0x08UL) |= 0x4000UL;
     //Предварительно отключаем выходное значение пина 
     *(uint32_t *)(0x40020400UL + 0x18UL) |= 0x800000UL;
}

// Настраиваем пин F12 на вход
void GPIO_Init_CMSIS_GPIOF_INPUT(void){
    //Выключаем пин если он был включен в режиме выход
    CLEAR_BIT(GPIOF->PUPDR, GPIO_PUPDR_PUPD12_0);
    //Переводим в режим выхода
    CLEAR_BIT(GPIOF->MODER, GPIO_MODER_MODE12_0);
    //Выклюяаем medium скорость тактирования выхода
    CLEAR_BIT(GPIOF->OSPEEDR, GPIO_OSPEEDER_OSPEEDR12_0);
}

// Настраиваем пин F12 на выход
void GPIO_Init_CMSIS_GPIOF_OUTPUT(void){
    //Настраиваем пин F7 на выход
    SET_BIT(GPIOF->MODER, GPIO_MODER_MODE12_0);
    //Настраиваем pull-push подтягивание
    CLEAR_BIT(GPIOF->OTYPER, GPIO_OTYPER_OT12);
    //Настраиваем medium скорость тактирования выхода
    SET_BIT(GPIOF->OSPEEDR, GPIO_OSPEEDER_OSPEEDR12_0);
    //Предварительно отключаем выходное значение пина
    CLEAR_BIT(GPIOF->PUPDR, GPIO_PUPDR_PUPD12_0);
}