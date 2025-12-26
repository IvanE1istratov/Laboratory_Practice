#ifndef INIT_H
#define INIT_H
#include <stdint.h>
#include "../../CMSIS/Devices/STM32F4xx/Inc/stm32f4xx.h"
#include "../../CMSIS/Devices/STM32F4xx/Inc/system_stm32f4xx.h"

//Деректива процессора
#define RCC_AHB1ENR                  *(uint32_t *)(0x40023800UL + 0x30UL) // Включение тактирования для переферии, регистр AHB1ENR

#define RCC_GPIOB_EN                 0x02UL      // Включение тактирования для переферии GPIOB
#define RCC_GPIOC_EN                 0x04UL      // Включение тактирования для переферии GPIOC
#define RCC_GPIOD_EN                 0x08UL      // Включение тактирования для переферии GPIOD
#define RCC_GPIOF_EN                 0x32UL      // Включение тактирования для переферии GPIOF

//Настройка переферии GPIOB
#define GPIOB_MODER                  *(uint32_t *)(0x40020400UL + 0x00UL)    // Настроиваем пин порта вход/выход
#define GPIOB_OTYPER                 *(uint32_t *)(0x40020400UL + 0x04UL)    // Настроиваем режим выхода пина push-pull/open-drain
#define GPIOB_OSPEEDR                *(uint32_t *)(0x40020400UL + 0x08UL)    // Настраиваем тактирование пина на low/medium/high speed
#define GPIOB_BSRR                   *(uint32_t *)(0x40020400UL + 0x18UL)    // Регистр сброса записи значения пину

//Настройка переферии GPIOF
#define GPIOF_MODER                  *(uint32_t *)(0x40021400UL + 0x00UL)    // Настроиваем пин порта вход/выход
#define GPIOF_OTYPER                 *(uint32_t *)(0x40021400UL + 0x04UL)    // Настроиваем режим выхода пина push-pull/open-drain
#define GPIOF_OSPEEDR                *(uint32_t *)(0x40021400UL + 0x08UL)    // Настраиваем тактирование пина на low/medium/high speed
#define GPIOF_BSRR                   *(uint32_t *)(0x40021400UL + 0x18UL)    // Регистр сброса записи значения пину
#define GPIOF_IDR                    *(uint32_t *)(0x40021400UL + 0x10UL)    // Регистр состояние входов порта

//Настройка переферии GPIOС
#define GPIOC_IDR                    *(uint32_t *)(0x40020800UL + 0x10UL)    // Регистр состояние входов порта

//Настройка переферии GPIOD
#define GPIOD_IDR                    *(uint32_t *)(0x40020C00UL + 0x10UL)    // Регистр состояние входов порта


//Настройка пина 0
#define GPIO_OUTPUT_MODE_PIN_0       0x01UL          //Настройка на выход
#define GPIO_PP_PIN_0                0x01UL          //push-pull
#define GPIO_SPEED_MEDIUM_PIN_0      0x01UL          //Medium speed
#define GPIO_PIN_RESET_0             0x10000UL      
#define GPIO_PIN_SET_0               0x01UL
//Настройка пина 3
#define GPIO_PIN_3                   0x08UL          //Значения на входе
//Настройка пина 7
#define GPIO_OUTPUT_MODE_PIN_7       0x4000UL        //Настройка на выход
#define GPIO_PP_PIN_7                0x80UL          //push-pull
#define GPIO_SPEED_MEDIUM_PIN_7      0x4000UL        //Medium speed
#define GPIO_PIN_RESET_7             0x800000UL      
#define GPIO_PIN_SET_7               0x80UL
//Настройка пина 8
#define GPIO_PIN_8                   0x100UL         //Значения на входе
//Настройка пина 12
#define GPIO_OUTPUT_MODE_PIN_12      0x1000000UL     //Настройка на выход
#define GPIO_PP_PIN_12               0x1000UL        //push-pull
#define GPIO_SPEED_MEDIUM_PIN_12     0x1000000UL     //Medium speed
#define GPIO_PIN_RESET_12            0x10000000UL      
#define GPIO_PIN_SET_12              0x1000UL
#define GPIO_PIN_12                  0x1000UL        //Значения на входе
//Настройка пина 13
#define GPIO_PIN_13                  0x2000UL        //Значения на входе
//Настройка пина 14
#define GPIO_OUTPUT_MODE_PIN_14      0x10000000UL    //Настройка на выход
#define GPIO_PP_PIN_14               0x4000UL        //push-pull
#define GPIO_SPEED_MEDIUM_PIN_14     0x10000000UL    //Medium speed
#define GPIO_PIN_RESET_14            0x40000000UL      
#define GPIO_PIN_SET_14              0x4000UL

// //универсальная деректива препроцессора 
#define BIT_SET(REG, BIT)       ((REG) |= (BIT))
#define BIT_CLEAR(REG, BIT)     ((REG) &= ~(BIT))
#define BIT_READ(REG, BIT)      ((REG) & (BIT))

void GPIO_Init_Macros_GPIOB_GPIOC_GPIOD(void);
void GPIO_Init_GPIOB7(void);
void GPIO_Init_CMSIS_GPIOF_INPUT(void);
void GPIO_Init_CMSIS_GPIOF_OUTPUT(void);

#endif