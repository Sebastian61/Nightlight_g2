/*
 * File:   main.c
 * Author: Sebastian
 *
 * Created on October 19, 2023, 11:37 PM
 */

// PIC10F322 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTOSC    // Oscillator Selection bits (INTOSC oscillator: CLKIN function disabled)
#pragma config BOREN = NSLEEP   // Brown-out Reset Enable (Brown-out Reset enabled while running and disabled in Sleep)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)
#pragma config LPBOR = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "pin_config.h"
#include "main.h"

nightlight_t nightlight;

void system_init(void);

void __interrupt() myisr(void) {
    //check power button press
    //check ADC result
    //systick
      //update nightlight brightness
}

void main(void) {
    system_init();
    while(1) {
        //idle
    }
}

void system_init(void) {
    /*** OSC initialize ***/
    OSCCONbits.IRCF = 0b101; //4MHz
    
    /*** IO initialize ***/
    //set output
    
    //IO interrupt on change initialize
    IOCAF &= ~(BUTTON_MASK); //clear IOC interrupt flag
    IOCAP |= BUTTON_MASK; //enable IOC
    IOCAN |= BUTTON_MASK; //enable IOC on negative
    INTCONbits.IOCIF = 0; //clear IOC interrupt flag
    INTCONbits.IOCIE = 1; //set IOC interrupt
    
    /*** ADC initialize ***/
    ANSELA |= (AN_INPUT_MASK | LIGHT_SENSOR_MASK); //set adc pins
    ANSELA &= ~(BUTTON_MASK); //disable adc on other pins
    ADCONbits.ADCS = 0b101; //set conversion clock bits Fosc/16
    PIR1bits.ADIF = 0; //clear adc interrupt flag
    PIE1bits.ADIE = 1; //enable adc interrupt
    
    /*** Timer initialize ***/
    //Timer0 initialize
    OPTION_REGbits.T0CS = 0; //internal clock cycle
    OPTION_REGbits.PSA = 0; //prescaler is assigned to timer0
    OPTION_REGbits.PS = 0b111; //prescaler 1:256
    INTCONbits.TMR0IF = 0; //clear timer 0 interrupt flag
    INTCONbits.TMR0IE = 1; //enable timer 0 interrupt
    
    /*** Interrupt initialize ***/
    
    //nightlight initialize
}