#include "interface.h"

double getAverageTemperaturePerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    double sumOfTemperatures = 0;
    for (size_t i = 0; i < size; i++) {
        sumOfTemperatures += weatherDataPerWeek[i]->temperatureCelsius;
    }

    return sumOfTemperatures / size;
}

int getMinTemperaturePerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    int minTemperature = weatherDataPerWeek[0]->temperatureCelsius;
    for (size_t i = 1; i < size; i++) {
        if (weatherDataPerWeek[i]->temperatureCelsius < minTemperature) {
            minTemperature = weatherDataPerWeek[i]->temperatureCelsius;
        }
    }

    return minTemperature;
}

int getMaxTemperaturePerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    int maxTemperature = weatherDataPerWeek[0]->temperatureCelsius;
    for (size_t i = 1; i < size; i++) {
        if (weatherDataPerWeek[i]->temperatureCelsius > maxTemperature) {
            maxTemperature = weatherDataPerWeek[i]->temperatureCelsius;
        }
    }

    return maxTemperature;
}

double getAveragePrecipitationPerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    double sumOfPrecipitations = 0;
    for (size_t i = 0; i < size; i++) {
        sumOfPrecipitations += weatherDataPerWeek[i]->precipitationPercents;
    }

    return sumOfPrecipitations / size;
}
