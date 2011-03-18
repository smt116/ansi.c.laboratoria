/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>

int wczytaj_miare(char *prompt)
{
    char miara[2];

    printf(prompt);
    scanf("%s", miara);

    int jednostka = strcmp("cm", miara);
    if (jednostka != 0)
	jednostka = 1;

    return jednostka;
}

void przelicz(double wzrost, int miara)
{
    switch (miara) {
    case 0:
	printf("%2lf in\n", wzrost / 2.54);
	break;
    case 1:
	printf("%2lf cm\n", wzrost * 2.54);
	break;
    }
}
