#include "searchWeather.h"

void inputString(char *str, int max)
{	
	int i=0;
	for(i=0; i<max-1; ++i)
	{
		str[i] = getchar();
		if(str[i]=='\n')
		{
			str[i] = '\0';
			return;
		}
	}
	
	str[max-2] = '\n';
	str[max-1] = '\0';
	return;
}

void saveDateWeather(int date, char* area, char ap, char* weather)
{
	FILE* pFile;
	pFile = fopen(WEATHERDATA,"a");
	if(pFile == NULL)
	{
		perror("File Opening Error");
	}
	
	fwrite(&date,sizeof(int),1,pFile);
	fputs(area, pFile);
	fputc('\n',pFile);
	fputc(ap,pFile);
	fputs(weather, pFile);
	fputc('\n',pFile);
	
	fclose(pFile);
	
}


int inputDateWeather()
{
	int date;
	char area[AREA_LEN];
	char ap;
	char weather[WEATHER_LEN];
	
	fputs("Date (Input EOF Exit) : ", stdout);
	if(scanf("%d", &date)==EOF)
	{
		return -1;
	}
	
	while(getchar()!='\n');	
	fputs("Area : ", stdout);
	inputString(area, sizeof(area));
	
	fputs("AP : ", stdout);
	scanf("%c", &ap);
	
	while(getchar()!='\n');
	fputs("Weather : ", stdout);
	inputString(weather, sizeof(weather));
	
	saveDateWeather(date, area, ap, weather);
	
	return 0;
}
