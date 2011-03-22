/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include"lib.h"

int main() {
    double a, b, x;
    int dzielenie_przez_zero;
    pobierz_dane("Podaj dane: a b ", &a, &b);
    oblicz_wynik(a, b, &x, &dzielenie_przez_zero);
    pokaz_wynik("%lf * x = %lf => x= %lf\n",
		"Nie mozna dzielic przez zero!\n",
		"Rownanie ma nieskonczenie wiele rozwiazan\n", a, b, x,
		dzielenie_przez_zero);
    return 0;
}
