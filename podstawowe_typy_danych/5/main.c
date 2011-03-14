/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include"lib.h"
#include<stdio.h>
int main(){
	double wzrost;
	int miara;

	wzrost = wczytaj_liczbe("Podaj wzrost: ");
	miara = wczytaj_miare("Podaj miare: ");
	przelicz(wzrost, miara);

	return 0;
}
