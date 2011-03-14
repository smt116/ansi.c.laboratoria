/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<time.h>

int pobierz_wiek(char *prompt){
	int wiek;
	printf(prompt);
	scanf("%i",&wiek);

	return wiek;
}

int przezyte_dni(int poczatek, int koniec){
	int suma_dni = 0;
	while(poczatek < koniec){
		if((!(koniec%4) && koniec%100) || !(koniec%400)){
			suma_dni += 366;
		}
		else{
			suma_dni += 365;
		}
		koniec--;
	}
	return suma_dni;
}

void wiek_na_sekundy(int wiek){
	time_t data;
	struct tm*pelna_data;
	time(&data);
	pelna_data = localtime(&data);
	int obecny_rok = pelna_data->tm_year + 1900,
	    poczatek = obecny_rok - wiek;

	long wynik = 86400 * przezyte_dni(poczatek, obecny_rok);

	printf("Suma przezytych sekund: %li\n", wynik);
}
