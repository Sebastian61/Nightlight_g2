#include "interrupt_functions.h"
#include "peripheral_features.h"

extern const uint8_t adc_channels[2];

void handle_ADC_interrupt(adc_inst *adc) {
    //move result to uint8_t
    adc->result[adc->channel_number] = ADRES;
    
    //set next channel
    adc->channel_number += 1;
    if(adc->channel_number == TOTAL_CHANNELS)
        adc->channel_number = 0;
    
    //turn off adc interrupt
    ADCONbits.ADON = 0;
    PIE1bits.ADIE = 0;
    return;
}

void handle_timer_0_interrupt(void) {
    return;
}