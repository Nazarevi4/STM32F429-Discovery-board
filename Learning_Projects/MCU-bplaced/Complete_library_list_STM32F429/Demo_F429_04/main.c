//--------------------------------------------------------------
// File     : main.c
// Datum    : 24.10.2013
// Version  : 1.0
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
// CPU      : STM32F429
// IDE      : CooCox CoIDE 1.7.4
// GCC      : 4.7 2012q4
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Funktion : Demo der DigIn-Library
// Hinweis  : Diese zwei Files muessen auf 8MHz stehen
//              "cmsis_boot/stm32f4xx.h"
//              "cmsis_boot/system_stm32f4xx.c"
// In Configuration diese Define hinzufügen :
// "STM32F429_439xx" , "__ASSEMBLY__" , "USE_STDPERIPH_DRIVER"
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_dig_in.h"
#include "stm32_ub_dig_out.h"

int main(void)
{
  BitAction wert;

  SystemInit(); // Quarz Einstellungen aktivieren

  UB_DigIn_Init();  // init aller DigIn-Pins
  UB_DigOut_Init(); // init aller DigOut-Pins

  while(1)
  {
    // Pegel an PD2 lesen und an PE2 ausgeben
    wert=UB_DigIn_Read(DIN_PD2);
    UB_DigOut_Pin(DOUT_PE2,wert);
    // Pegel an PD4 lesen und an PE3 ausgeben
    wert=UB_DigIn_Read(DIN_PD4);
    UB_DigOut_Pin(DOUT_PE3,wert);
    // Pegel an PD5 lesen und an PE4 ausgeben
    wert=UB_DigIn_Read(DIN_PD5);
    UB_DigOut_Pin(DOUT_PE4,wert);
    // Pegel an PD7 lesen und an PE5 ausgeben
    wert=UB_DigIn_Read(DIN_PD7);
    UB_DigOut_Pin(DOUT_PE5,wert);
  }
}

