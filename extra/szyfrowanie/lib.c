/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void wczytaj_tekst(short *tekst, char *prompt) {
    int i = 0;
    char znak;
    printf(prompt);

    do {
	znak = getchar();
	tekst[i] = (int) znak;
	i++;
    } while (znak != EOF);
}

void wyswietl_tekst(short *tekst, char *prompt) {
    int i = 0;
    printf(prompt);

    do {
	printf("%c", (char) tekst[i]);
	i++;
    } while (tekst[i] != EOF);
}

short wybor_opcji(char *prompt) {
    short opcja;
    printf(prompt);

    do {
	scanf("%hi", &opcja);
    } while (opcja <= 0 || opcja >= 3);

    return opcja;
}
