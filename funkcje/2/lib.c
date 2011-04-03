/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

void wczytaj_dane(unsigned *n, char *prompt) {
    printf(prompt);
    scanf("%u", n);
}

void silnia(unsigned n, char *prompt) {
    long long int silnia = 1;
    unsigned i;

    for (i = 1; i < n; i++) {
	silnia *= i;
    }

    printf(prompt, i, silnia);
}

void test_10(void) {
    unsigned i;

    for (i = 1; i <= 10; i++) {
	silnia(i, "%u! = %lli\n");
    }
}
