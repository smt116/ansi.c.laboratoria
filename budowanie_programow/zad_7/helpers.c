/* Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<math.h>
double pobierz_rzeczywista(void){
	double x;
	printf("Podaj liczbe rzeczywista: ");
	
	scanf("%lf",&x);
	while( x<0 ){
		printf("Liczba musi byc rozna od 0\nPodaj liczbe rzeczywista: ");
		scanf("%lf",&x);
	}

	return x;
}
void pierwiastek_i_odwrotnosc_R(double x){
	double p = sqrt(x);
	printf("Pierwiastek z %lf = %lf\n",x,p);
	if( x!= 0 )
		printf("Liczba odwrotna do %lf = %lf\n",x,1.0/x);
	else
		printf("%lf nie ma liczby odwrotnej\n",x);
}
