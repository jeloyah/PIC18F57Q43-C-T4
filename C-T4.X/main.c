
#include <xc.h>
#include "main.h"
#include "gpio.h"
#include "timer0.h"

void main(void) {
    
    /* Peripheral and System Initialization*/
      
    /* PortA initialization */
    PortA_Initialize();
    
    /* PortB initialization */
    
    
    /* PortC initialization */
    
    
    /* PortD initialization */
    
    
    /* PortE initialization */
    
    
    /* PortF initialization */
    
   
    /* TIMER0 Initialization */
    TIMER0_Initialize();
     
    /* infinite loop */
    while(1)
    {
     switch(PORTD)   /* Read PORTD */
     {
         case 0xF0:     /* All buttons are open */
             
             AllON();   /* Turn on all LEDs */           
            
             break;
         
         case 0x70:      /* SW4 (RD7) is closed */
             
             Sequence1(); /* Do sequence1 */           
            
             break;
         
         case 0xB0:       /* SW3 (RD6( button is closed */ 
            
             Sequence2(); /* Do sequence2 */           
            
             break;
             
         case 0xC0:       /* SW2 (RD5) & SW1 (RD4) are closed */
            
             Sequence3();
          
             break;
         
         case 0x50:      /* SW4 (RD7) & SW3 (RD5) are closed */
            
             Sequence4();
          
             break;
         
         default:        /* All the combinations */
             
             AllOFF();
             
             break;
     } /* end switch */
        
    } /* end while */
    
    return;
}

void AllON(void)
{
    LATF = 0xF0;                /* RD7:RD4 = on-on-on-on */
}


void Sequence1(void)
{
    LATF = 0x80;                /* RD7:RD4 = on-off-off-off */
    TIMER0_Delay();             /* Delay subroutine */
    LATF = 0x10;                /* RD6:RD4 = off-off-off-on */
    TIMER0_Delay();             /* Delay subroutine */
}

void Sequence2(void)
{
    ??;                /* RD7:RD4 = on-on-off-off */
    TIMER0_Delay();             /* Delay subroutine */
    ??;                /* RD7:RD4 = off-off-on-on */
    TIMER0_Delay();             /* Delay subroutine */
}

void Sequence3(void)
{
    ??;                /* RD7:RD4 = on-on-on-off */
    TIMER0_Delay();             /* Delay subroutine */
    ??;                /* RD7:RD4 = off-on-on-on */
    TIMER0_Delay();             /* Delay subroutine */          
}

void Sequence4(void)
{
    ??;                /* RD7:RD4 = on-on-on-on */
    TIMER0_Delay();             /* Delay subroutine */
    ??;                /* RD7:RD4 = off-off-off-off */
    TIMER0_Delay();             /* Delay subroutine */      
}

void AllOFF(void)
{
    LATF = 0x00;                /* RD7:RD4 = off-off-off-off */
}
