#include<stdio.h>

int bit_liczby (int numer, int liczba)
{
	int p=1,i;
	for(i=0 ; i<numer ; i++)
	{
		p *= 2;
	}
	
	if(liczba&p) {return 1;}
	else return 0;
}
main()
{
	int n,i;
	printf("Jaka liczba? n = "); scanf("%i",&n);
	for(i=31 ; i>=0 ; i--)
	{
		printf("%i",bit_liczby(i,n));
		if(!(i%8))printf(" ");
	}
}
