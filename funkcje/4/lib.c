/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include <string.h>
/* string.h dla strlen(); */

void pobierz_liczbe(char *liczba, unsigned *dlugosc, char *prompt)
{
    unsigned i = 0;
	printf(prompt);
	
  	scanf("%s", liczba);
	*dlugosc = strlen(liczba);
}

void drukuj_liczbe_od_tyly(unsigned dlugosc, char liczba[dlugosc], char *prompt)
{
    unsigned i;
    printf(prompt);
	
	for(i = dlugosc-1; i>0 ; i--) {
		printf("%1c", liczba[i]);
    }
	printf("%c", liczba[0]);

	printf("\n");
}
