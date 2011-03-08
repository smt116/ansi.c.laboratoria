/* Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<math.h>
double pobierz_rzeczywista(void){
	double x;
	printf("Podaj liczbe rzeczywista: ");
	scanf("%lf",&x);

	return x;
}
void pierwiastek_i_odwrotnosc_R(double x){
	double p = sqrt(x);
	if( x<0 ){
		printf("Liczba %lf nie ma pierwiastka rzeczywistego\n",x);
	}
	else{
		printf("Pierwiastek z %lf = %lf\n",x,p);
	}
	if( x!=0 ){
		printf("Liczba odwrotna do %lf = %lf\n",x,1.0/x);
	}
	else{
		printf("Liczba %lf nie ma liczby odwrotnej",x);
	}
}
