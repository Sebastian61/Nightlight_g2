#include "peripheral_features.h"

void ADC_set_channel(uint8_t channel) {
    ADCONbits.CHS = channel;
    return;
}

void ADC_start_it(uint8_t channel) {
    ADCONbits.CHS = channel; //set ADC channel
    PIR1bits.ADIF = 0; //clear ADC flag
    PIE1bits.ADIE = 1; //set ADC interrupt
    ADCONbits.ADON = 1; //turn on ADC
    ADCONbits.GO_nDONE = 1; //start ADC conversion
    return;
}