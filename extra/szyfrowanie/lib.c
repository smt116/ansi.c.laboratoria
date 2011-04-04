/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void wczytaj_tekst(short *tekst, char *prompt)
{
    int i;
    printf(prompt);
    do {
	scanf("%hi", tekst[i]);
	i++;
    } while (tekst[i] != EOF);
}

short menu(short *opcjaMenu, char *prompt)
{
    printf(prompt);
    do {
	scanf("%hi", opcjaMenu);
    } while (*opcjaMenu > 0 && *opcjaMenu < 3);
    return *opcjaMenu;
}

void wybor(short opcjaMenu, short *tekst, char *error)
{
    switch (opcjaMenu) {
    case 1:
	ascii_na_tekst(tekst);
    case 2:
	tekst_na_ascii(tekst);
    default:
	printf(error);
    }
}
