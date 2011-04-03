/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    char liczba[200];
    unsigned dlugosc;

    pobierz_liczbe(liczba, &dlugosc, "Podaj liczbe: ");
    drukuj_liczbe_od_tyly(dlugosc, liczba, "Liczba odtylu: ");

    return 0;
}
