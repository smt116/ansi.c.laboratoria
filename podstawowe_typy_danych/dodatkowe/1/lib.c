/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
double a, b, x;
int dzielenie_przez_zero;

void pobierz_dane(char *prompt)
{
    printf(prompt);
    scanf("%lf %lf", &a, &b);
}
void oblicz_wynik(void)
{
    if (a != 0) {
	x = b / a;
	dzielenie_przez_zero = 0;
    } else
	dzielenie_przez_zero = 1;
}
void pokaz_wynik(char *prompt, char *error)
{
    if (dzielenie_przez_zero)
	printf(error);
    else
	printf(prompt, a, b, x);
}
