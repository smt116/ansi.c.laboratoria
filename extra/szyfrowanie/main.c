/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
/* na potrzeby testow ograniczona tablica: */
    short tekst[4096];
    short opcjaMenu;

    wczytaj_tekst(tekst, "Podaj tekst wejsciowy: ");
    wyswietl_tekst(tekst, "\nPodany tekst: \n");
    menu(&opcjaMenu, "Co chcesz zrobic?...");
    wybor(opcjaMenu, tekst, "Blad.");
    return 0;
}
