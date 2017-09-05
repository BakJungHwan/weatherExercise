#include "searchWeather.h"

void printDateWeather()
{
	int date;
	char area[AREA_LEN];
	char ap;
	char weather[WEATHER_LEN];
	
	FILE* pFile;
	pFile = fopen(WEATHERDATA,"r");
	if(pFile == NULL)
	{
		perror("File Opening Error");
	}
	
	while(1)
	{
		fread(&date,sizeof(int),1,pFile);
		fgets(area,AREA_LEN,pFile);
		ap = fgetc(pFile);
		fgets(weather,WEATHER_LEN,pFile);
		
		if(feof(pFile))
		{
			break;
		}
		
		printf("\n");
		printf("----------------------------------------\n");
		printf("Date : %d\n", date);
		printf("Area : %s", area);
		printf("AP : %c\n", ap);
		printf("Weather : %s", weather);
		printf("----------------------------------------\n");
	}
	
	printf("\n");
	
	fclose(pFile);
}
