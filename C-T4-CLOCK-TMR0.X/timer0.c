#include <xc.h>
#include "timer0.h"
#include "pps.h"

/* Config Timer0 */
void TIMER0_Initialize(void)
{

    /* Unlock Peripheral Pin Select */
    PPS_unlock();
    
    /* Map TMR0 output to RC7 */
    RC6PPS = 0x39;   
    
     /* Lock Peripheral Pin Select */
    PPS_lock();
    
    /* Timer0 disabled; 16-bit; no postscaler */
	T0CON0 = 0x10;
    
    /* HFINTOSC; counter not synchronized; prescaler 1:2048 */
	T0CON1 = 0x79;
       
}

void TIMER0_Delay(void)
{
    /* Load TMR0 with value (hex) */
	TMR0H = 0x82;
	TMR0L = 0xFF;
    
    /* Timer0 enabled; 16-bit */
	T0CON0 |= 0x80;    
  
    /* Wait for TMR0IF = 1 */
    while ((PIR3 & 0x80) != 0x80) 
    /* empty loop */ 
          ;
    
    /* Clear TMR0IF bit */
    PIR3 &= 0x7F;
         
    /* Load TMR0 with value (hex) */
    //TMR0H = 0x82;
    //TMR0L = 0xFF;
        
    /* Timer0 disabled */
    T0CON0 &= 0x7F; 
}


