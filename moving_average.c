#include "moving_average.h"

void MovingAverage_Init(MovingAverageFilter *filter) {
    for (uint8_t i = 0; i < FILTER_WINDOW_SIZE; i++) {
        filter->buffer[i] = 0.0f;
    }
    filter->index = 0;
    filter->count = 0;
    filter->sum = 0.0f;
}

float MovingAverage_Update(MovingAverageFilter *filter, float new_value) {
    
    filter->sum -= filter->buffer[filter->index];

    filter->buffer[filter->index] = new_value;
    filter->sum += new_value;

    filter->index = (filter->index + 1) % FILTER_WINDOW_SIZE;

    if (filter->count < FILTER_WINDOW_SIZE) {
        filter->count++;
    }

    return filter->sum / filter->count;
}
