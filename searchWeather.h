#ifndef __SEARCHWEATHER__
#define __SEARCHWEATHER__
#include <stdio.h>
#include <string.h>
#define AREA_LEN 10
#define WEATHER_LEN 100
#define DWDATASIZE 5
#define WEATHERDATA "weather.dat"

typedef struct __dateWeather
{
	int date;
	char area[AREA_LEN];
	char ap;
	char weather[WEATHER_LEN];
}DateWeather;

int inputDateWeather();
void printDateWeather();
void searchDateWeather();

#endif
