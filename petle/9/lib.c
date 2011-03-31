/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int otworz_plik(FILE ** in_handle, char *argv[1]) {
    *in_handle = fopen(argv[0], "r");

    if (*in_handle == NULL) {
	return 0;
    } else
	return 1;
}

void zamknij_plik(FILE ** in_handle) {
    fclose(*in_handle);
}

void error_plik(char *error) {
    /* osobna funkcja po to zeby potem 
     * mozna bylo latwo dodac jakies inne
     * opcje przy bledach wywolania */
    printf(error);
}
