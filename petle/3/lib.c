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

void liczby_w_przedziale(int a, int b, char *prompt, char *nie_ma_liczb) {
	int i;
if(sprawdzenie(a,b)){
	printf(prompt,a,b);

	for(i=a+1 ; i<b ; i++) {
		printf("%i ", i);
	}
}
else printf(nie_ma_liczb,a,b);
printf("\n");}

/* funkcja sprawdza czy sa liczby w przedziale */
int sprawdzenie(int a, int b) {
	int out = 0;

	if( abs(a-b) > 1 ) out = 1;

	return out;
}
