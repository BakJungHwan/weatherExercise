/*
Description : This program Input WeatherData which consist of Date, Area, AP(Am, Pm), Weather(details) and save in 'weather.dat'.
				It also can print all of the data in file 'weather.dat' and query specific data by inputing date, area, ap.
				It is very simple and not safe only for exercise
				
Date : 2017-9-5
Developer : Bak Jung Hwan
Lang : C
*/


#include "searchWeather.h"

// Making enum For switch select
enum{Input=1, PrintAll, Search, Quit};

int main(int argc, char *argv[]) {
	int service;

// main mene
	while(1)
	{
		fputs("1.Input  2.PrintAll  3.Search  4.Quit", stdout);
		fputs(">> ", stdout);
		scanf("%d",&service);
		
		switch(service)
		{
			case Input :
				while(inputDateWeather()!=-1);
				break;
			case PrintAll :
				printDateWeather();
				break;
			case Search :
				searchDateWeather();
				break;
			case Quit :
				return 0;
			default :
				fputs("Wrong Selection\n", stdout);
		}
		
	}
	return 0;
}
