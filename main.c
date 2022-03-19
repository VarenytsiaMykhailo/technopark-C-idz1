#include "interface.h"

int main() {
    int daysInWeek = 7;
    WeatherDataPerDay **weatherDataPerWeek = (WeatherDataPerDay **) malloc(sizeof(WeatherDataPerDay *) * daysInWeek);
    if (!weatherDataPerWeek) {
        printf("Malloc failed\n");
        return 1;
    }
    for (int i = 0; i < daysInWeek; i++) {
        weatherDataPerWeek[i] = (WeatherDataPerDay *) malloc(sizeof(WeatherDataPerDay));
        if (!weatherDataPerWeek[i]) {
            printf("Malloc failed\n");
            return 1;
        }
    }

    readWeatherDataPerWeek(weatherDataPerWeek, daysInWeek);

    prettyPrintWeatherDataPerWeek(weatherDataPerWeek, daysInWeek);

    double averageTemperaturePerWeek = getAverageTemperaturePerWeek(weatherDataPerWeek, daysInWeek);
    //printf("Average temperature per week = %f\n", averageTemperaturePerWeek);

    int minTemperaturePerWeek = getMinTemperaturePerWeek(weatherDataPerWeek, daysInWeek);
    //printf("Min temperature per week = %d\n", minTemperaturePerWeek);

    int maxTemperaturePerWeek = getMaxTemperaturePerWeek(weatherDataPerWeek, daysInWeek);
    //printf("Max temperature per week = %d\n", maxTemperaturePerWeek);

    double averagePrecipitationPerWeek = getAveragePrecipitationPerWeek(weatherDataPerWeek, daysInWeek);
    //printf("Average precipitation per week = %f%%\n", averagePrecipitationPerWeek);

    GeneralWeatherDataPerWeek *generalWeatherDataPerWeek = (GeneralWeatherDataPerWeek *) malloc(
            sizeof(GeneralWeatherDataPerWeek));
    if (!generalWeatherDataPerWeek) {
        printf("Malloc failed\n");
        return 1;
    }
    generalWeatherDataPerWeek->averageTemperaturePerWeek = averageTemperaturePerWeek;
    generalWeatherDataPerWeek->minTemperaturePerWeek = minTemperaturePerWeek;
    generalWeatherDataPerWeek->maxTemperaturePerWeek = maxTemperaturePerWeek;
    generalWeatherDataPerWeek->averagePrecipitationPerWeek = averagePrecipitationPerWeek;

    prettyPrintGeneralWeatherDataPerWeek(generalWeatherDataPerWeek);

    freeWeatherDataPerWeek(weatherDataPerWeek, daysInWeek);
    freeGeneralWeatherDataPerWeek(generalWeatherDataPerWeek);

    return 0;
}

void freeWeatherDataPerDay(WeatherDataPerDay *const weatherData) {
    free(weatherData);
}

void freeGeneralWeatherDataPerWeek(GeneralWeatherDataPerWeek *weatherDataPerWeek) {
    free(weatherDataPerWeek);
}

void freeWeatherDataPerWeek(WeatherDataPerDay **weatherDataPerWeek, size_t size) {
    for (size_t i = 0; i < size; i++) {
        free(weatherDataPerWeek[i]);
    }
    free(weatherDataPerWeek);
}





