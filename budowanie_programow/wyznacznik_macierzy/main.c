/*
 * Maciej Malecki
 * smt116@gmail.com
 */

#include<stdio.h>
#include"definicje.h"

int main(){
	int n;
	printf("podaj wymiar macierzy kwadratowej: ");
	scanf("%i",&n);
	float macierz[n][n];

	wczytaj_macierz(n,macierz);
     
	printf("%f\n", wyznacznik(n, macierz) );
	return 0;
}
