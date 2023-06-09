#ifndef AD7606_H
#define AD7606_H

#include "pin_config.h"

#define NUM_OF_AD7606_CHANNEL 16
#define AD7606_DMA_TRANS_COUNT 8

#if AD7606_USE_DMA
    extern volatile uint32_t AD7606_rx_buf[NUM_OF_AD7606_CHANNEL];
    extern volatile double AD7606_buf[NUM_OF_AD7606_CHANNEL];
    extern volatile uint8_t AD7606_trans_complete;
    extern volatile uint8_t AD7606_buf_ready;
    int AD7606_trggier_non_blocking(void *ctx);
    void AD7606_trggier(void);
#else
    extern int16_t AD7606_rx_buf[NUM_OF_AD7606_CHANNEL];
    void AD7606_trggier(void);
#endif

void AD7606_init(void);

#endif
