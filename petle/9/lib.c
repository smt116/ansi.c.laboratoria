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
    /* osobna funkcja jako furtka
     * do pozniejszej rozbudowy */
    fclose(*in_handle);
}

void wczytaj_dane(FILE ** in_handle, unsigned *kilometry, double *litry,
		  double *cena) {
    char bufor[BUFSIZ];
    short komentarz;

    while (fgets(bufor, BUFSIZ, *in_handle)) {
	komentarz = sscanf(bufor, "%u %lf %lf", kilometry, litry, cena);
	if(komentarz==3) {
	    oblicz(*kilometry, *litry, *cena);
	}
    }
}

void oblicz(unsigned kilometry, double litry, double cena) {
    double srednie_spalanie, sredni_koszt;

    srednie_spalanie = (litry/kilometry)*100;
    sredni_koszt = srednie_spalanie*cena;

    printf("\n-> Dane dla: %u %.2f %.2f\n",kilometry, litry, cena);

    printf("Srednie spalanie: \t%.2f\nSredni koszt: \t\t%.2f\n", 
		    srednie_spalanie, sredni_koszt);
}

void error_plik(char *error) {
    /* osobna funkcja jako furtka
     * do pozniejszej rozbudowy */
    printf(error);
}
