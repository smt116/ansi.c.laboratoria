/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include <math.h>
void wczytaj_dane(double *a, double *b, char *prompt) {
    printf(prompt);
    scanf("%lf %lf", a, b);
}

void oblicz_przeciwprostokatna(double a, double b, char *prompt) {
    double c;
    c = a * a + b * b;
    c = sqrt(c);
    printf(prompt, c);
}
