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
    menu(&opcjaMenu, "Co chcesz zrobic?...");
    wybor(opcjaMenu, tekst, "Blad.");
    return 0;
}
