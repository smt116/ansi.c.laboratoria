/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main() {
    short tekst[ROZMIAR];
    /* co uzytkownik chce zrobic: */
    short opcja;

    wczytaj_tekst(tekst, "Podaj tekst wejsciowy (EOF konczy procedure):\n");
    wyswietl_tekst(tekst, "\nPodany tekst: \n");

    opcja = wybor_opcji("\nCo chcesz zrobic?:\n\t1. Zamien tekst na ASCII\n\t2. Zlicz ilosc poszczegolonych liter\nWybor: ");

    switch (opcja) {
        case 1: tekst_na_ascii(tekst); break;
        case 2: zlicz_litery(tekst); break;
        default: printf("blad");
    }
    return 0;
}
