/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void wczytaj_dane(FILE ** in_handle, unsigned *kilometry, double *litry,
		  double *cena) {
    char bufor[BUFSIZ];
    short komentarz;

    while (fgets(bufor, BUFSIZ, *in_handle)) {
	komentarz = sscanf(bufor, "%u %lf %lf", kilometry, litry, cena);
	if (komentarz == 3) {
	    oblicz(*kilometry, *litry, *cena);
	}
    }
}

void oblicz(unsigned kilometry, double litry, double cena) {
    double srednie_spalanie, sredni_koszt;

    srednie_spalanie = (litry / kilometry) * 100;
    sredni_koszt = srednie_spalanie * cena;

    printf("\n-> Dane dla: %u %.2f %.2f\n", kilometry, litry, cena);

    printf("Srednie spalanie: \t%.2f\nSredni koszt: \t\t%.2f\n",
	   srednie_spalanie, sredni_koszt);
}
