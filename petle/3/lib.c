/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include <math.h>

void wczytaj_dane(int *a, int *b, char *prompt) {
    printf(prompt);
    scanf("%i %i", a, b);
}

void liczby_w_przedziale(int a, int b, char *liczby_w_przedziale, 
	char *nie_ma_liczb, char *a_mniejsze_niz_b) {
    int i;

    switch(sprawdzenie(a,b)) {
	case 0: printf(nie_ma_liczb, a, b); break;
	case 1: 
	    printf(liczby_w_przedziale);
	    for(i=a+1 ; i<b ; i++) {
		printf("%i ", i);
	    }
	    break;
	case 2: printf(a_mniejsze_niz_b, a, b); break;
    }

    printf("\n");
}

/* funkcja sprawdza czy sa liczby w przedziale */
int sprawdzenie(int a, int b) {
    int out = 0;

    if (b-a > 1) {
	out = 1;
    } else {
	if(b-a == 0 || b-a == 1) {
	    out = 0;
	} else {
	    out = 2;
	}
    }

    return out;
}
