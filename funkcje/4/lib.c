/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
void pobierz_liczbe(char *liczba[], char *prompt)
{
    printf(prompt);
    scanf("%c", liczba);
}
void drukuj_liczbe_od_tyly(char liczba[], char *prompt)
{
    unsigned i;
    printf(prompt);

    for (i = 0; i < strlen(liczba); i++) {
	printf("%c", liczba[i]);
    }
}
