/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

void pobierz_dane(char *prompt, double *a, double *b) {
    printf(prompt);
    scanf("%lf %lf", a, b);
}
void oblicz_wynik(double a, double b, double *x, int *dzielenie_przez_zero) {
    if (a != 0) {
	*x = b / a;
	*dzielenie_przez_zero = 0;
    } else
	*dzielenie_przez_zero = 1;
}
void pokaz_wynik(char *prompt, char *prompt_blad, char *prompt_tozsamosc,
		 double a, double b, double x, int dzielenie_przez_zero) {
    if (dzielenie_przez_zero)
	printf(prompt_blad);
    else if (x != 0)
	printf(prompt, a, b, x);
    else
	printf(prompt_tozsamosc);
}
