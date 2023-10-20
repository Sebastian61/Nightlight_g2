/*
 * File:   main.c
 * Author: Sebastian
 *
 * Created on October 19, 2023, 11:37 PM
 */


#include <xc.h>
#include "main.h"

nightlight_t nightlight;

void system_init(void);

void __interrupt() myisr(void) {
    
}

void main(void) {
    system_init();
    while(1) {
        
    }
}

void system_init(void) {
    //OSC initialize
    //IO initialize
    //ADC initialize
    //Interrupt initialize
}