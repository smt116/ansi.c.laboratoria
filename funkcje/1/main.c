/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"
int main() {
    double a, b;
    wczytaj_dane(&a, &b,
		 "Podaj krotsze boki trojkata prostokatnego\na b = ");

    oblicz_przeciwprostokatna(a, b, "Przeciwprostokatna wynosi %lf\n");
    return 0;
}
