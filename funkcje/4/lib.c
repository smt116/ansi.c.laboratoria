/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<string.h>

void pobierz_liczbe(char *liczba, unsigned *dlugosc, char *prompt)
{
    printf(prompt);
    scanf("%c", liczba);

	/* to ponizej jest bledne... ale jak to poprawic??..*/
	*dlugosc = strlen(liczba);
}

void drukuj_liczbe_od_tyly(unsigned *dlugosc, char *liczba[*dlugosc], char *prompt)
{
    unsigned i;
    printf(prompt);
    
	for (i = 0; i < *dlugosc; i++) {
		printf("%c", liczba[i]);
    }

	printf("\n");
}
