/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include"lib.h"
#include<stdio.h>

/* biblioteka w ktorej jest pobierz_rzeczywista(); */
#include"../libs/input.h"
int main()
{
    double wzrost;
    int miara;

    wzrost = pobierz_rzeczywista("Podaj wzrost: ");
    miara = wczytaj_miare("Podaj miare: ");
    przelicz(wzrost, miara);

    return 0;
}
