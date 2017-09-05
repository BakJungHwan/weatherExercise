#include "searchWeather.h"

void printSearchData(int s_date, char* s_area, char s_ap)
{
	int date;
	char area[AREA_LEN];
	char ap;
	char weather[WEATHER_LEN];
	char isFound=0;
	
	FILE* pFile;
	pFile = fopen(WEATHERDATA,"r");
	if(pFile == NULL)
	{
		perror("File Opening Error");
	}
	
	do
	{
		fread(&date,sizeof(int),1,pFile);
		fgets(area,AREA_LEN,pFile);
		area[strlen(area)-1]='\0';
		
		ap = fgetc(pFile);
		
		fgets(weather,WEATHER_LEN,pFile);
		
		if(date==s_date)
		{
			if(!strcmp(area,s_area))
			{
				if(ap==s_ap)
				{
					printf("\n");
					printf("----------------------------------------\n");
					printf("Date : %d\n", date);
					printf("Area : %s\n", area);
					printf("AP : %c\n", ap);
					printf("Weather : %s", weather);
					printf("----------------------------------------\n");
					printf("\n");
					isFound = 1;
				}
			}
		}
	}while(!feof(pFile));
	
	if(!isFound)
	{
		fputs("There isn't matched data which you want\n\n", stdout);
	}
	
	
	fclose(pFile);
	
}


void searchDateWeather()
{
	int s_date;
	char s_area[AREA_LEN];
	char s_ap;
	
	fputs("Which date do you want to search? : ", stdout);
	scanf("%d", &s_date);
	
	fputs("Which area do you want to search? : ", stdout);
	scanf("%s", s_area);
	
	while(getchar()!='\n');
	
	fputs("Which ap do you want to search? : ", stdout);
	scanf("%c",&s_ap);
	
	while(getchar()!='\n');
	
	printSearchData(s_date,s_area, s_ap);
	
	
}
