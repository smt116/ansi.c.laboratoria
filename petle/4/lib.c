/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

void pobierz_n(unsigned *n, char *prompt) {
    printf(prompt);
    scanf("%u", n);
}

void wypisz_sume(unsigned n, char *prompt) {
    unsigned suma;
    suma = n * (n + 1) / 2;
    printf(prompt, suma);
}
