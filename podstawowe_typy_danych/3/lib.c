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

void wiek_na_sekundy(int wiek){
	time_t sek_do_teraz = time(NULL);
	/* ... */
	printf("%i\n",...);
}
