/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char *argv[])
{
    FILE *in_handle;
    char bufor[BUFSIZ];

    if (otworz_plik(in_handle, &argv[1])) {
	printf("Plik otwarty");
    } else
	printf("Blad otwarcie pliku!");


    return 0;
}
