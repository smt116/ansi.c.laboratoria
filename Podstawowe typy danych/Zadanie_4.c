/*
Maciej Małecki
smt116@gmail.com
*/
#include<stdio.h>
#include<time.h>
int sumaDni = 0;
int przezyteDni(int poczatek,int koniec)
{
	if(poczatek < koniec)
	{
		if( (!(koniec%4) && koniec%100) || !(koniec%400) )
		{
			sumaDni += 366;
			przezyteDni(poczatek,koniec-1);
		}
		else
		{
			sumaDni += 365;
			przezyteDni(poczatek,koniec-1);
		}
	}
	else
		return sumaDni;
}
int main()
{
	int wiekDzien, wiekMiesiac, wiekRok;
	printf("Podaj swoj wiek (dd mm rrrr) "); 
	scanf("%i %i %i",&wiekDzien,&wiekMiesiac,&wiekRok);
	
	time_t obecnaData;
	struct tm*pelnaData;
	time(&obecnaData);
	pelnaData = localtime(&obecnaData);
	int obecnyDzien = (pelnaData->tm_mday),
	    obecnyMiesiac = (pelnaData->tm_mon)+1,
	    obecnyRok = (pelnaData->tm_year)+1900;
	
	//oczywiscie ilosc dni w miesiacu jest 
	//baaardzo zaokraglona.. za jakis czas
	//napisze funkcje do liczenia dni
	//z uwzglednieniem ilosci dni w miesiacach
	int wyjs = (wiekDzien + 30*(12-wiekMiesiac+obecnyMiesiac)
		   	+ przezyteDni(wiekRok,obecnyRok)) * 86400;
	
	printf("Suma przezytych sekund: %i\n",wyjs);
	return 0;
}
