/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    int x, y;
    char znak;

    wczytaj_dane("Podaj wymiar i znak, x y znak ", &x, &y, &znak);
    drukuj_szachownice(x, y, znak);

    return 0;
}
