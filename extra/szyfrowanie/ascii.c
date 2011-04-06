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
    unsigned i = 0, ilosc[26] = {};
    do {
	i++;
    } while(tekst[i + 1] != EOF);
}
