#include<stdio.h>
main()
{
	int a,b,c,d;
	printf("Podaj rozmiar macierzy A po spacji "); scanf("%i %i",&a,&b);
	printf("Podaj rozmiar macierzy B po spacji "); scanf("%i %i",&c,&d);
	
	if(b!=c)
	{
		printf("Macierzy nie da sie pomnozyc...");
	}
	else
	{
		int A[a][b], B[c][d], AB[a][d], i, k;
		//wczytanie macierzy A
		for(i=0 ; i<a ; i++)
		{
			for(k=0 ; k<b ; k++)
			{
				printf("Podaj element A[%i,%i] = ",i,k);
				scanf("%i",&A[i][k]);
			}
		}		
		for(i=0 ; i<c ; i++)
		{
			for(k=0 ; k<d ; k++)
			{
				printf("Podaj element B[%i,%i] = ",i,k);
				scanf("%i",&B[i][k]);
			}
		}
		//mnozenie macierzy
		int l,s=0;
		for(i=0 ; i<a ; i++)
		{
			for(k=0 ; k<d ;k++)
			{
				for(l=0 ; l<b ; l++)
				{
					s += A[i][l]*B[l][k];					
				}
				AB[i][k]=s;s=0;
			}
		}
		//wyswietlanie macierzy
		for(i=0 ; i<a ; i++)
		{
			for(k=0 ; k<d ; k++)
			{
				printf("AB[%i,%i] = %i\n",i,k,AB[i][k]);
			}
		}
	}
}
