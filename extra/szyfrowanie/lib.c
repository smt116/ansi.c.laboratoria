/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void wczytaj_tekst(short *tekst, char *prompt)
{
    int i = 0; char znak;
    printf(prompt);
    do {
	znak = getchar();
	tekst[i] = (int) znak;
	i++;
    } while (znak != EOF);
}

void wyswietl_tekst(short *tekst, char *prompt)
{
    int i = 0;
    printf(prompt);
    do {
	printf("%c", (char) tekst[i]);
	i++;
    } while (tekst[i] != EOF);
}

void menu(short *opcjaMenu, char *prompt)
{
    printf(prompt);
    do {
	scanf("%hi", opcjaMenu);
    } while (*opcjaMenu < 0 && *opcjaMenu > 3);
}

void wybor(short opcjaMenu, short *tekst, char *error)
{
    switch (opcjaMenu) {
    case 1:
	ascii_na_tekst(&tekst);
    case 2:
	tekst_na_ascii(&tekst);
    default:
	printf(error);
    }
}
