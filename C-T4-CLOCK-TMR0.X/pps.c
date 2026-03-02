#include <xc.h>
#include "pps.h"

void PPS_lock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Set PPS locked bit*/
    PPSLOCK |= 0x01;
    
    /* Enable interrupts */
    ei();  
}

void PPS_unlock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Clear PPS locked bit*/
    PPSLOCK &= 0xFE;
    
    /* Enable interrupts */
    ei();  
}