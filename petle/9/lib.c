/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int otworz_plik(FILE * in_handle, char *argv[1])
{
    in_handle = fopen(argv[1], "r");
    if (in_handle == NULL) {
	printf("Poprawne wywolanie: ./main nazwa_pliku\n");
	return 0;
    } else
	return 1;
}
