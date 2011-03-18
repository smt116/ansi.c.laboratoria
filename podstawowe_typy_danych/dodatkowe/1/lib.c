/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
double a, b, x;

void pobierz_dane(char *prompt)
{
    printf(prompt);
    scanf("%lf %lf", &a, &b);
}
void oblicz_wynik(void)
{
    x = b / a;
}
void pokaz_wynik(char *prompt)
{
    printf(prompt, a, b, x);
}
