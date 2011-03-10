/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>

void wczytaj(int n, double tab[n]){
	/* takie rozwiazanie umozliwa pozniejsza modyfikacje
	 * i zwiekszenie ilosci danych ktore chcemy uzyskac
	 * od uzytkownika */
	int i = 0;
	/**/
	while(i<n){
		printf("Podaj liczbe nr %i: ",i);
		scanf("%lf",&tab[i]);
		i++;
	}
}
double suma(int n, double tab[n]){
	int i = 0;
	double suma_ = 0.0;
	while(i<n){
		suma_ += tab[i];
		i++;
	}
	
	return suma_;
}
double iloczyn(int n, double tab[n]){	
	int i = 0;
	double iloczyn_ = 1.0;
	while(i<n){
		iloczyn_ *= tab[i];
		i++;
	}
	
	return iloczyn_;
}
int min(int n, double tab[n]){
	double min = tab[0];
       	int k = 0, i = 1;
	while(i<n){
		if(tab[i]<min){
			k = i;
			min = tab[i];
		}
		i++;
	}

	return k;
}
int max(int n, double tab[n]){
	double max = tab[0];
	int k = 0, i = 1;
	while(i<n){
		if(tab[i]>max){
			k = i;
			max = tab[i];
		}
		i++;
	}

	return k;
}
void operacje(int n, double tab[n]){
	double suma_ = suma( n, tab ),
		iloczyn_ = iloczyn( n, tab );
	int min_ = min( n, tab ),
		max_ = max( n, tab );
	
	printf("\n");
	printf("Suma:\t\t%f\n",suma_);
	printf("Iloczyn:\t%f\n",iloczyn_);
	printf("Minimum:\t%f\n",tab[min_]);
	printf("Maximum:\t%f\n",tab[max_]);
	printf("\n");
}

