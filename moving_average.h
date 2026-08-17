#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include <stdint.h>

#define FILTER_WINDOW_SIZE 5

typedef struct {
    float buffer[FILTER_WINDOW_SIZE];
    uint8_t index;
    uint8_t count;
    float sum;
} MovingAverageFilter;

void MovingAverage_Init(MovingAverageFilter *filter);

float MovingAverage_Update(MovingAverageFilter *filter, float new_value);

#endif 
