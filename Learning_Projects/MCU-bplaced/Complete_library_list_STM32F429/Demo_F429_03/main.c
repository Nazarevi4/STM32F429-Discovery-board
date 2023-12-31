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
// Funktion : Demo der DigOut-Library
// Hinweis  : Diese zwei Files muessen auf 8MHz stehen
//              "cmsis_boot/stm32f4xx.h"
//              "cmsis_boot/system_stm32f4xx.c"
// In Configuration diese Define hinzufügen :
// "STM32F429_439xx" , "__ASSEMBLY__" , "USE_STDPERIPH_DRIVER"
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_dig_out.h"

void Delay(volatile uint32_t nCount){
  while(nCount--) {
  }
}

int main(void)
{
  SystemInit(); // Quarz Einstellungen aktivieren

  UB_DigOut_Init(); // init aller DigOut-Pins

  while(1)
  {
    Delay(5000000);
    UB_DigOut_Toggle(DOUT_PE2);
    Delay(5000000);
    UB_DigOut_Toggle(DOUT_PE3);
    Delay(5000000);
    UB_DigOut_Toggle(DOUT_PE4);
    Delay(5000000);
    UB_DigOut_Toggle(DOUT_PE5);
  }
}

