//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.10.2013
// Version  : 1.1
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
// CPU      : STM32F429
// IDE      : CooCox CoIDE 1.7.4
// GCC      : 4.7 2012q4
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Funktion : Demo der SPI-LoLevel-Library
// Hinweis  : Diese zwei Files muessen auf 8MHz stehen
//              "cmsis_boot/stm32f4xx.h"
//              "cmsis_boot/system_stm32f4xx.c"
// In Configuration diese Define hinzufügen :
// "STM32F429_439xx" , "__ASSEMBLY__" , "USE_STDPERIPH_DRIVER"
//--------------------------------------------------------------

#include "main.h"
#include "stm32_ub_spi5.h"

//--------------------------------------------------------------
// ein Byte per SPI senden und empfangen
//--------------------------------------------------------------
uint8_t spi_send(uint8_t wert)
{
  uint8_t ret_wert;

  // hier Code einfügen und
  // ChipSelect-Pin auf LO legen

  // byte senden und empfangen
  ret_wert=UB_SPI5_SendByte(wert);

  // hier Code einfügen und
  // ChipSelect-Pin auf HI legen

  return(ret_wert);
}

int main(void)
{
  uint8_t wert;

  SystemInit(); // Quarz Einstellungen aktivieren

  // SPI5 im Mode0_MSB initialisieren
  UB_SPI5_Init(SPI_MODE_0_MSB);

  // den Wert 0x45 per SPI senden
  // und ein Byte empfangen
  wert=spi_send(0x45);

  while(1)
  {

  }
}

