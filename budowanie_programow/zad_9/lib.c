/* Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include<math.h>
void wejs_dane(double wejs[3]){
	/* dane wejsciowe */
	printf("Wartosc poczatkowa: ");
	scanf("%lf",&wejs[0]);
	printf("Wartosc koncowa: ");
	scanf("%lf",&wejs[1]);
	printf("Krok: ");
	scanf("%lf",&wejs[2]);
	/**/
}
double pierwiastek(double x){
	/* warynek x>=0 bedzie sprawdzany przed
	 * wywolaniem tej funkcji */
	double p = sqrt(x);
	return p;
}
void wyjs(double wejs[3]){
	double p = wejs[0],
	       k = wejs[1];
	while( p<=k ){
		if( p>=0 ){
			printf("Pierwiastek z %f wynosi %f\n",p,pierwiastek(p));
		}
		p += wejs[2];
	}
}
