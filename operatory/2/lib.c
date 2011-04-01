/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

int pobierz_ilosc_dni(int *dni, char *prompt) {
	printf(prompt);
	scanf("%i", dni);

	if(dni<=0) {
		return 0;
	} else {
		return 1;
	}
}
