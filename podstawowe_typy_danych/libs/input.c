/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

int pobierz_calkowita(char *prompt)
{
    int liczba;
    printf(prompt);
    scanf("%i", &liczba);
    return liczba;
}

double pobierz_rzeczywista(char *prompt)
{
    double liczba;
    printf(prompt);
    scanf("%lf", &liczba);
    return liczba;
}
