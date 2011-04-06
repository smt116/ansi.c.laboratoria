/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
/* na potrzeby testow ograniczona tablica: */
    short tekst[4096];
    short opcjaMenu;

    wczytaj_tekst(tekst, "Podaj tekst wejsciowy (EOF konczy procedure): ");
    /* wyswietlanie tekstu do testow - pozniej usune */
    wyswietl_tekst(tekst, "\nPodany tekst: \n");
    opcjaMenu = menu("Co chcesz zrobic?:\n\t1. Zamien ASCII na tekst\n\t2. Zamien tekst na ASCII\nWybor: ");

    switch (opcjaMenu) {
        case 1: ascii_na_tekst(tekst); break;
        case 2: tekst_na_ascii(tekst); break;
        default: printf("blad");
    }
    return 0;
}
