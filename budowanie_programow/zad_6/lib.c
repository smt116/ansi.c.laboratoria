/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<math.h>

double pobierz_rzeczywista(char *prompt){
	double x;
	printf(prompt);
	scanf("%lf",&x);

	return x;
}
void wypisz_pierwiastek(double x){
	double p = sqrt(x);
	if(x<0){
		printf("Liczba %lf nie ma pierwiastka rzeczywistego\n",x);
	}
	else{
		printf("Pierwiastek z %lf = %lf\n",x,p);
	}
}
