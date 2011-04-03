/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"
#include <stdio.h>

int main() {
    int a, b;

    wczytaj_liczby(&a, &b, "Podaj dwie liczby calkowite. a b = ");
    suma(a, b, "Suma liczb w przedziale ( %i,%i ) wynosi %i\n");
    return 0;
}
