/* 
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void tekst_na_ascii(short *tekst) {
    unsigned i = 0;

    do {
	printf("%hi ", tekst[i]);
	i++;
    } while (tekst[i + 1] != EOF);
}

void zlicz_litery(short *tekst) {
    /* poki co zliczam kazdy znak z ascii 
       potem poprawie to ;) */
    unsigned i = 0, j, ilosc[127] = { };

    do {
	ilosc[tekst[i]]++;
	i++;
    } while (tekst[i + 1] != EOF);

    for (i = 65, j = 0; i <= 122; i++, j++) {
	printf("%c %i\t", (char) i, ilosc[i]);
	if (i == 90) { i = 96; printf("\n"); }
	if (j%5==0) printf("\n");
    }
    printf("\n");
}
