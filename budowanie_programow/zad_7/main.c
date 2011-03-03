/* Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include "helpers.h"
int main(){
	double x = pobierz_rzeczywista();

	/* Funkcja wypisze pierwiastek i odwrotnosc */
	pierwiastek_i_odwrotnosc_R(x);
	printf("\n");

	return 0;
}
