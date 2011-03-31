/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char *argv[]) {
    FILE *in_handle;
    char bufor[BUFSIZ];

    if (otworz_plik(&in_handle, &argv[1])) {
	printf("ok");
    } else
	error_plik("Poprawne wywolanie: ./main nazwa_pliku");

    zamknij_plik(&in_handle);

    return 0;
}
