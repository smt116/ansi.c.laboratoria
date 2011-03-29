/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *in_handle;
    char bufor[BUFSIZ];
    unsigned int ui;
    double x, y;

    in_handle = fopen(argv[1], "r");
    if (in_handle == NULL) {
	printf("Poprawne wywolanie: ./main nazwa_pliku\n");
	exit(0);
    } else {

	while (fgets(bufor, BUFSIZ, in_handle) != NULL) {
	    pobierz_dane(bufor, &ui, &x, &y);

	    /* olicza i automatycznie wypisuje */
	    oblicz_dane(ui, x, y);
	}
	fclose(in_handle);
    }
    return EXIT_SUCCESS;
}
