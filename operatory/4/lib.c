/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

void wczytaj_liczby(int *a, int *b, char *prompt) {
    printf(prompt);
    scanf("%i %i", a, b);
}

void suma(int a, int b, char *prompt) {
    int suma = 0, tmp = a;
    do {
	suma += tmp*tmp;
	tmp++;
    } while (tmp <= b);

    printf(prompt, a, b, suma);
}
