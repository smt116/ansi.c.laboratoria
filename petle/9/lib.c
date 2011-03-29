/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include "lib.h"
void pobierz_dane(char *bufor[], unsigned int *ui, double *x, double *y)
{
    short komentarz;
    komentarz = sscanf(*bufor, "%u %lf %lf", ui, x, y);
    if (komentarz == 3) {
	oblicz_dane(*ui, *x, *y);
    }
}

void oblicz_dane(int ui, double x, double y)
{
    printf("%u %lf %lf\n", ui, x, y);
}
