/*
Maciej Małecki
smt116@gmail.com

Nie wiem czy dobrze zrozumiałem to zadanie ;).
*/

#include<stdio.h>
#include<limits.h>
#include<float.h>

main()
{
	int in = INT_MAX;
	printf("INT\t\t %i\n",in);
	printf("INT overflow\t %i\n",in+1);
	printf("\n");

	float fl = FLT_MAX;
	/* co ciekawe FLT_MAX nie jest maksymalne
	 * fl+fl nie wykracza poza zakres float
	 * co moze znaczyc ze siega double */
	printf("FLOAT\t\t %f\n",fl);
	printf("FLOAT overflow\t %f\n",fl+fl);
	printf("FLOAT underflow\t %f\n",-fl-fl);
	printf("\n");

	/* nieskonczonosc? ciekawe :P */
	double db = DBL_MAX;
	printf("DOUBLE\t\t %f\n",db);
	printf("DOUBLE overflow\t %f\n",db+db);
	printf("DOUBLE underflow %f\n",-db-db);
	printf("\n");
}
