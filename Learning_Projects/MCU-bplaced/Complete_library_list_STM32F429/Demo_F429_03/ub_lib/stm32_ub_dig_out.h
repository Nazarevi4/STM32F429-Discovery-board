//--------------------------------------------------------------
// File     : stm32_ub_dig_out.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F4_UB_DIG_OUT_H
#define __STM32F4_UB_DIG_OUT_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"




//--------------------------------------------------------------
// Liste aller Digital-Out Pins
// (keine Nummer doppelt und von 0 beginnend)
//--------------------------------------------------------------
typedef enum 
{
  DOUT_PE2 = 0,  // PE2-Pin
  DOUT_PE3 = 1,  // PE3-Pin
  DOUT_PE4 = 2,  // PE4-Pin
  DOUT_PE5 = 3   // PE5-Pin
}DOUT_NAME_t;

#define  DOUT_ANZ   4 // Anzahl von DOUT_NAME_t

//--------------------------------------------------------------
// Struktur eines Digital-Out Pins
//--------------------------------------------------------------
typedef struct {
  DOUT_NAME_t GPIO_NAME;   // Name
  GPIO_TypeDef* GPIO_PORT; // Port
  const uint16_t GPIO_PIN; // Pin
  const uint32_t GPIO_CLK; // Clock
  BitAction GPIO_INIT;     // Init
}DOUT_PIN_t;


//--------------------------------------------------------------
// Globale Funktionen
//--------------------------------------------------------------
void UB_DigOut_Init(void);
void UB_DigOut_Lo(DOUT_NAME_t dig_pin);
void UB_DigOut_Hi(DOUT_NAME_t dig_pin);
void UB_DigOut_Toggle(DOUT_NAME_t dig_pin);
void UB_DigOut_Pin(DOUT_NAME_t dig_pin,BitAction wert);



//--------------------------------------------------------------
#endif // __STM32F4_UB_DIG_OUT_H
