//--------------------------------------------------------------
// File     : stm32_ub_dig_in.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F4_UB_DIG_IN_H
#define __STM32F4_UB_DIG_IN_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


//--------------------------------------------------------------
// Aktivieren, Deaktivieren der entprellten Funktionen mit Timer
// 1=aktiv, 0=inaktiv
//--------------------------------------------------------------
#define  DIN_USE_TIMER      1  // Funktionen per Timer


#if DIN_USE_TIMER==1
  #include "stm32f4xx_tim.h"
  #include "misc.h"
  #include <stdbool.h>
#endif



//--------------------------------------------------------------
// Liste aller Digital-In Pins
// (keine Nummer doppelt und von 0 beginnend)
//--------------------------------------------------------------
typedef enum 
{
  DIN_PD2 = 0,    // PD2-Pin
  DIN_PD4 = 1,    // PD4-Pin
  DIN_PD5 = 2,    // PD5-Pin
  DIN_PD7 = 3     // PD7-Pin
}DIN_NAME_t;

#define  DIN_ANZ   4 // Anzahl von DIN_NAME_t



//--------------------------------------------------------------
// Timer für DigitalIn => TIM7
// Grundfrequenz = 2*APB1 (APB1=45MHz) => TIM_CLK=90MHz
// TIM_Frq = TIM_CLK/(periode+1)/(vorteiler+1)
// TIM_Frq = 20Hz => 50ms (nicht kleiner als 1ms einstellen)
//--------------------------------------------------------------
#if DIN_USE_TIMER==1
  #define   UB_DIN_TIM              TIM7
  #define   UB_DIN_TIM_CLK          RCC_APB1Periph_TIM7
  #define   UB_DIN_TIM_PERIODE      4999
  #define   UB_DIN_TIM_PRESCALE     899
  #define   UB_DIN_TIM_IRQ          TIM7_IRQn
  #define   UB_DIN_TIM_ISR_HANDLER  TIM7_IRQHandler
#endif



//--------------------------------------------------------------
// Struktur eines Digital-In Pins
//--------------------------------------------------------------
typedef struct {
  DIN_NAME_t GPIO_NAME;    // Name
  GPIO_TypeDef* GPIO_PORT; // Port
  const uint16_t GPIO_PIN; // Pin
  const uint32_t GPIO_CLK; // Clock
  GPIOPuPd_TypeDef GPIO_R; // Widerstand
  uint8_t GPIO_AKT;        // Istwert
}DIN_PIN_t;


//--------------------------------------------------------------
// Globale Funktionen
//--------------------------------------------------------------
void UB_DigIn_Init(void);
BitAction UB_DigIn_Read(DIN_NAME_t dig_pin);
#if DIN_USE_TIMER==1
  bool UB_DigIn_OnHiLevel(DIN_NAME_t dig_pin);
  bool UB_DigIn_OnHiEdge(DIN_NAME_t dig_pin);
  bool UB_DigIn_OnLoEdge(DIN_NAME_t dig_pin);
#endif


//--------------------------------------------------------------
#endif // __STM32F4_UB_DIG_IN_H
