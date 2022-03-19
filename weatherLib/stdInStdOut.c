#include "interface.h"

void readWeatherDataPerDay(WeatherDataPerDay *const weatherData) {
    int temperatureCelsius = 0;
    int precipitationPercents = 0;
    int windSpeed = 0;

    while (1) {
        printf("Temperature in celsius:\n");
        scanf("%d", &temperatureCelsius);

        if ((temperatureCelsius > 100) || (temperatureCelsius < -100)) {
            printf("Incorrect input data, try again. Temperature should be in celsius of [-100, 100] interval of int type value.\n");

            fflush(stdin);
        } else {
            break; // Ok
        }
    }

    while (1) {
        printf("Precipitation in percents:\n");
        scanf("%d", &precipitationPercents);

        if ((precipitationPercents < 0) || (precipitationPercents > 100)) {
            printf("Incorrect input data, try again. Precipitation should be in percents of [0, 100] interval of int type value.\n");

            fflush(stdin);
        } else {
            break; // Ok
        }
    }

    while (1) {
        printf("Wind speed:\n");
        scanf("%d", &windSpeed);

        if (windSpeed < 0) {
            printf("Incorrect input data, try again. Wind speed should be >= 0 of int type value.\n");

            fflush(stdin);
        } else {
            break; // Ok
        }
    }

    weatherData->temperatureCelsius = temperatureCelsius;
    weatherData->precipitationPercents = precipitationPercents;
    weatherData->windSpeed = windSpeed;
}

void readWeatherDataPerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Enter weather data for the %lu day:\n", (i + 1));
        readWeatherDataPerDay(weatherDataPerWeek[i]);
    }
}

void prettyPrintWeatherDataPerDay(WeatherDataPerDay *const weatherData) {
    printf("Temperature celsius = %d\n", weatherData->temperatureCelsius);
    printf("Precipitation percents = %d\n", weatherData->precipitationPercents);
    printf("Wind speed = %d\n", weatherData->windSpeed);
}

void prettyPrintWeatherDataPerWeek(WeatherDataPerDay *const *const weatherDataPerWeek, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Weather data for the %lu day:\n", (i + 1));
        prettyPrintWeatherDataPerDay(weatherDataPerWeek[i]);
    }
}

void prettyPrintGeneralWeatherDataPerWeek(GeneralWeatherDataPerWeek *const generalWeatherDataPerWeek) {
    printf("Average temperature per week celsius = %f\n", generalWeatherDataPerWeek->averageTemperaturePerWeek);
    printf("Min temperature per week celsius = %d\n", generalWeatherDataPerWeek->minTemperaturePerWeek);
    printf("Max temperature per week celsius = %d\n", generalWeatherDataPerWeek->maxTemperaturePerWeek);
    printf("Average precipitation per week percents = %f\n", generalWeatherDataPerWeek->averagePrecipitationPerWeek);
}
