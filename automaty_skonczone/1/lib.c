/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include "lib.h"

void pobieranie_tekstu(char *prompt) {
    printf(prompt);

    char znak;
    znak = getchar();

    while (znak != EOF) {
	if (znak == ' ' || znak == '\t') {
	    putchar(znak);
	    niweluj_znaki_biale(&znak);
	} 
	else putchar(znak);

	znak = getchar();
    }
}
void niweluj_znaki_biale(char *znak) {
    while (*znak == ' ' || *znak == '\t') {
	*znak = getchar();
    }

    putchar(*znak);
}
