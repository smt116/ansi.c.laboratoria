/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int wywolanie(int kod_bledu) {
    switch(kod_bledu) {
	case 2: printf("Za duzo argumentow\nPoprawne wywolanie: ./main plik\n",
				    strerror(errno)); return 0; break;
	case 1: printf("Plik nieistnieje\n",
				strerror(errno)); return 0; break;
	default: return 0;
    }
}

int otworz_plik(FILE ** in_handle, int *argc, char *argv[1]) {
    *in_handle = fopen(argv[0], "r");
    if (*argc != 2) {
	wywolanie(2);
	return 0;
    } else {
	if(*in_handle == NULL) {
	    wywolanie(1);
	    return 0;
	} else {
	    return 1;
	}
    }
}

void zamknij_plik(FILE ** in_handle) {
    /* osobna funkcja jako furtka
     * do pozniejszej rozbudowy */
    fclose(*in_handle);printf("ok");
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
