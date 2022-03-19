#include <gtest/gtest.h>

extern "C" {
#include "interface.h"
}

TEST(weatherDataAPI, getAverageTemperaturePerWeekTest
) {
int daysInWeek = 7;
WeatherDataPerDay **weatherDataPerWeek = (WeatherDataPerDay **) malloc(sizeof(WeatherDataPerDay *) * daysInWeek);
if (!weatherDataPerWeek) {
printf("Malloc failed\n");
//return 1;
}
for (
int i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i] = (WeatherDataPerDay *) malloc(sizeof(WeatherDataPerDay));
if (!weatherDataPerWeek[i]) {
printf("Malloc failed\n");
//return 1;
}
}

for (
size_t i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i]->
temperatureCelsius = 11;
weatherDataPerWeek[i]->
precipitationPercents = 11;
weatherDataPerWeek[i]->
windSpeed = 11;
}

EXPECT_EQ(11,
getAverageTemperaturePerWeek(weatherDataPerWeek, daysInWeek
));
}


TEST(weatherDataAPI, getMinTemperaturePerWeekTest
) {
int daysInWeek = 7;
WeatherDataPerDay **weatherDataPerWeek = (WeatherDataPerDay **) malloc(sizeof(WeatherDataPerDay *) * daysInWeek);
if (!weatherDataPerWeek) {
printf("Malloc failed\n");
//return 1;
}
for (
int i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i] = (WeatherDataPerDay *) malloc(sizeof(WeatherDataPerDay));
if (!weatherDataPerWeek[i]) {
printf("Malloc failed\n");
//return 1;
}
}

for (
size_t i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i]->
temperatureCelsius = i + 10;
weatherDataPerWeek[i]->
precipitationPercents = 11;
weatherDataPerWeek[i]->
windSpeed = 11;
}

EXPECT_EQ(10,
getMinTemperaturePerWeek(weatherDataPerWeek, daysInWeek
));
}


TEST(weatherDataAPI, getMaxTemperaturePerWeekTest
) {
int daysInWeek = 7;
WeatherDataPerDay **weatherDataPerWeek = (WeatherDataPerDay **) malloc(sizeof(WeatherDataPerDay *) * daysInWeek);
if (!weatherDataPerWeek) {
printf("Malloc failed\n");
//return 1;
}
for (
int i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i] = (WeatherDataPerDay *) malloc(sizeof(WeatherDataPerDay));
if (!weatherDataPerWeek[i]) {
printf("Malloc failed\n");
//return 1;
}
}

for (
size_t i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i]->
temperatureCelsius = i + 10;
weatherDataPerWeek[i]->
precipitationPercents = 11;
weatherDataPerWeek[i]->
windSpeed = 11;
}

EXPECT_EQ(16,
getMaxTemperaturePerWeek(weatherDataPerWeek, daysInWeek
));
}


TEST(weatherDataAPI, getAveragePrecipitationPerWeek
) {
int daysInWeek = 7;
WeatherDataPerDay **weatherDataPerWeek = (WeatherDataPerDay **) malloc(sizeof(WeatherDataPerDay *) * daysInWeek);
if (!weatherDataPerWeek) {
printf("Malloc failed\n");
//return 1;
}
for (
int i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i] = (WeatherDataPerDay *) malloc(sizeof(WeatherDataPerDay));
if (!weatherDataPerWeek[i]) {
printf("Malloc failed\n");
//return 1;
}
}

for (
size_t i = 0;
i<daysInWeek;
i++) {
weatherDataPerWeek[i]->
temperatureCelsius = 11;
weatherDataPerWeek[i]->
precipitationPercents = 11;
weatherDataPerWeek[i]->
windSpeed = 11;
}

EXPECT_EQ(11,
getAveragePrecipitationPerWeek(weatherDataPerWeek, daysInWeek
));
}
