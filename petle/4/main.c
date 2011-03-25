/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
    unsigned n;
    pobierz_n(&n, "Podaj n (liczba naturalna), n = ");
    wypisz_sume(n, "Suma wynosi %u\n");

    return 0;
}
