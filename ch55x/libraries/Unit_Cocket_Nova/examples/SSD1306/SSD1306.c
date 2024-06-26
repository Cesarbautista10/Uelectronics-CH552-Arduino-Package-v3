

// ===================================================================================
// Libraries, Definitions and Macros
// ===================================================================================

// Libraries
#include "src/system.h"                   // system functions
#include "src/gpio.h"                     // for GPIO
#include "src/delay.h"                    // for delays
#include "src/oled.h"                     // for OLED
#include "config.h"


// ===================================================================================
// Buzzer Function
// ===================================================================================

// Create a short beep on the buzzer
void beep(void) {
  uint8_t i;
  for(i=255; i; i--) {
    PIN_low(PIN_BUZZER);
    DLY_us(125);
    PIN_high(PIN_BUZZER);
    DLY_us(125);
  }
}

// ===================================================================================
// Main Function
// ===================================================================================

void main(void) {
  // Setup
  CLK_config();                           // configure system clock
  DLY_ms(5);                              // wait for clock to stabilize
  OLED_init();                            // init OLED

 // Print start message
  OLED_print("*  UNITelectronics  *");
  OLED_print("---------------------\n");
  OLED_print("Ready\n");

  beep();


  // Loop
  while(1) {

  }
}
