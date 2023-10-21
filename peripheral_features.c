#include "peripheral_features.h"

void ADC_set_channel(adc_channel_t channel) {
    ADCONbits.CHS = channel;
    return;
}
