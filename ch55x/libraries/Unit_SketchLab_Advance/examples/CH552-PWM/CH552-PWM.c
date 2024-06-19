/** @file CH552-PWM.c (SOURCE)
 *
 *  @brief CH552 PWM example
 *
 *  @author @CesarBautista 
 *
 *  @bug No known bugs.
 */

/******************************************************************************
 * INCLUDES
 *****************************************************************************/

#include <stdio.h>
#include "src/system.h"                   // system functions
#include "src/gpio.h"                     // for GPIO
#include "src/delay.h"                    // for delays
#include "src/pwm.h"

/******************************************************************************
 * MACROS AND DEFINES
 *****************************************************************************/

#define MIN_COUNTER 10
#define MAX_COUNTER 254
#define STEP_SIZE   10

/******************************************************************************
 * TYPEDEFS
 *****************************************************************************/
// Define los pines PWM
#define PIN_PWM1             P30       // PWM pin 0
#define PIN_PWM2             P34       // PWM pin 4

// Selecciona el pin PWM
#define SELECT_PWM(pin)      (PIN_PWM2)     // Selecciona el pin que desees usar aquí (PIN_PWM1 o PIN_PWM2)
#define PIN_PWM              SELECT_PWM(PIN_PWM1) // Selecciona el pin PWM deseado

// Ahora puedes cambiar entre PIN_PWM1 y PIN_PWM2 simplemente modificando SELECT_PWM en tu definición de PIN_PWM


/******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES
 *****************************************************************************/

void change_pwm(int hex_value)
{
    PWM_write(PIN_PWM, hex_value);
}
void main(void) 
{
    PWM_set_freq(1000);                    
    PIN_output(PIN_PWM);       
    PWM_start(PIN_PWM);      
    PWM_write(PIN_PWM, 0);
    CLK_config();                          
    DLY_ms(5);                            

while (1) 
{
    for (int i = MIN_COUNTER; i < MAX_COUNTER; i+=STEP_SIZE) 
    {
        change_pwm(i);
        DLY_ms(10);
    }
    for (int i = MAX_COUNTER; i > MIN_COUNTER; i-=STEP_SIZE)
    {
        change_pwm(i);
        DLY_ms(10);
    }
    
}
}
