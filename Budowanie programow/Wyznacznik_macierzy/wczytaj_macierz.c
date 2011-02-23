/*
 * Maciej Malecki
 * smt116@gmail.com
 */

/* funkcja do wczytywania danch do macierzy */

#include<stdio.h>
void wczytaj_macierz(int n,float macierz[n][n]){
	int x,y;

	for(x=0 ; x<n ; x++){
		for(y=0 ; y<n ; y++){
			printf("\npodaj element macierzy[%i,%i]= ",x,y);
			scanf("%f",&macierz[x][y]);
		}
	}
}
