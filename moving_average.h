#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <stdint.h>

// Sensör gürültüsünü yumuşatmak için örneklem penceresi boyutu
#define FILTER_WINDOW_SIZE 5

typedef struct {
    float buffer[FILTER_WINDOW_SIZE];
    uint8_t index;
    uint8_t count;
    float sum;
} MovingAverageFilter;

// Filtre yapılandırmasını sıfırlayan fonksiyon
void MovingAverage_Init(MovingAverageFilter *filter);

// Yeni sensör verisi ekleyip güncel ortalamayı hesaplayan fonksiyon
float MovingAverage_Update(MovingAverageFilter *filter, float new_value);

#endif // MOVING_AVERAGE_H