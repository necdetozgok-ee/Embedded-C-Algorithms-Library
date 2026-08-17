#include <stdio.h>
#include "moving_average.h"

int main() {
    MovingAverageFilter filter;
    MovingAverage_Init(&filter);

    float raw_sensor_data[] = {25.0f, 26.5f, 30.0f, 25.5f, 24.8f, 26.0f, 35.0f, 25.1f};
    uint8_t data_length = sizeof(raw_sensor_data) / sizeof(raw_sensor_data[0]);

    printf("--- Moving Average Filter Test ---\n");
    for (uint8_t i = 0; i < data_length; i++) {
        float filtered = MovingAverage_Update(&filter, raw_sensor_data[i]);
        printf("[%d] Ham Veri: %.2f C | Filtrelenmis: %.2f C\n", i + 1, raw_sensor_data[i], filtered);
    }

    return 0;
}
