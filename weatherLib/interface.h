#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct WeatherDataPerDay WeatherDataPerDay;
struct WeatherDataPerDay {

    int temperatureCelsius;

    int precipitationPercents;

    int windSpeed;
};

typedef struct GeneralWeatherDataPerWeek GeneralWeatherDataPerWeek;
struct GeneralWeatherDataPerWeek {

    double averageTemperaturePerWeek;

    int minTemperaturePerWeek;

    int maxTemperaturePerWeek;

    double averagePrecipitationPerWeek;
};

void freeWeatherDataPerDay(WeatherDataPerDay *);

void freeGeneralWeatherDataPerWeek(GeneralWeatherDataPerWeek *);

void freeWeatherDataPerWeek(WeatherDataPerDay **, size_t);

void readWeatherDataPerDay(WeatherDataPerDay *);

void prettyPrintGeneralWeatherDataPerWeek(GeneralWeatherDataPerWeek *);

void readWeatherDataPerWeek(WeatherDataPerDay *const *, size_t);

void prettyPrintWeatherDataPerDay(WeatherDataPerDay *);

void prettyPrintWeatherDataPerWeek(WeatherDataPerDay *const *, size_t);

double getAverageTemperaturePerWeek(WeatherDataPerDay *const *, size_t);

int getMinTemperaturePerWeek(WeatherDataPerDay *const *, size_t);

int getMaxTemperaturePerWeek(WeatherDataPerDay *const *, size_t);

double getAveragePrecipitationPerWeek(WeatherDataPerDay *const *, size_t);

#endif //INTERFACE_H
