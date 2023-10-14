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
// Funktion : Demo der Button-Library
// Hinweis  : Diese zwei Files muessen auf 8MHz stehen
//              "cmsis_boot/stm32f4xx.h"
//              "cmsis_boot/system_stm32f4xx.c"
// In Configuration diese Define hinzufügen :
// "STM32F429_439xx" , "__ASSEMBLY__" , "USE_STDPERIPH_DRIVER"
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_button.h"
#include "stm32_ub_led.h"

int main(void)
{
  SystemInit(); // Quarz Einstellungen aktivieren

  UB_Button_Init(); // Init der Buttons
  UB_Led_Init();    // Init der LEDs

  while(1)
  {
    // Test ob Button gedrückt ist
    if(UB_Button_Read(BTN_USER)==BTN_PRESSED) {
      UB_Led_On(LED_RED);  // rote LED einschalten
    }
    else {
      UB_Led_Off(LED_RED); // rote LED ausschalten
    }

    // Test auf OnClick vom Button
    if(UB_Button_OnClick(BTN_USER)==true) {
      UB_Led_Toggle(LED_GREEN); // grüne LED toggeln
    }
  }
}

