/* Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<math.h>
double pobierz_rzeczywista(void){
	/* a no taki sobie margines bledu */
	double x, e = 0.00000000001;
	printf("Podaj liczbe rzeczywista: ");
	scanf("%lf",&x);

	/* magia porownywania liczb typu double :D */
	while( fabs(0-x) < e ){
		printf("Liczba musi byc rozna od 0\nPodaj liczbe rzeczywista: ");
		scanf("%lf",&x);
	}

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
	printf("Liczba odwrotna do %lf = %lf\n",x,1.0/x);
}
