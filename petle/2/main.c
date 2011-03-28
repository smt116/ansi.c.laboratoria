/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main()
{
    int x, y;
    char znak;

    /* dlaczego wymiary x y szachownicy?
     * po co znak???....
     * a no bo ja nie robie 
     * destroy_bagdad - ja robie destroy_city! :D */

    wczytaj_dane("Podaj wymiar i znak, x y znak ", &x, &y, &znak);
    drukuj_szachownice(x, y, znak);

    return 0;
}
