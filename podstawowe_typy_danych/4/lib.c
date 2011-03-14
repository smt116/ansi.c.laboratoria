/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<time.h>

void pobierz_wiek(char *prompt, int wiek[2]){
	printf(prompt);
	scanf("%i-%i-%i", &wiek[0], &wiek[1], &wiek[2]);
}

void wiek_na_sekundy(int wiek[2]){
	time_t czas_aktualny, 
	       czas_urodzenia;
	struct tm*data_urodzenia;
	double roznica;

	time(&czas_urodzenia);
	data_urodzenia = localtime(&czas_urodzenia);

	data_urodzenia->tm_mday = wiek[0];
	data_urodzenia->tm_mon = wiek[1] - 1;
	data_urodzenia->tm_year = wiek[2] - 1900;

	czas_urodzenia = mktime(data_urodzenia);

	time(&czas_aktualny);

	roznica = difftime(czas_aktualny, czas_urodzenia);

	printf("Juz %0.lf sekund za toba...\n", roznica);
}
