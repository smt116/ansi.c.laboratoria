/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char *argv[]) {
    FILE *in_handle;
    unsigned kilometry;
    double litry, cena;

    if (otworz_plik(&in_handle, &argv[1])) {
	/* chwilowo printf dla testow */
	printf("-> Plik wczytany\n"); 
	wczytaj_dane(&in_handle, &kilometry, &litry, &cena);

    } else {
	error_plik("Poprawne wywolanie: ./main nazwa_pliku");
    }
    zamknij_plik(&in_handle);

    return 0;
}
