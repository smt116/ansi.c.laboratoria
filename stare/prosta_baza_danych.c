#include<stdio.h>
#include<string.h>
#define BAZA 10000

/*
  program w sumie nieukoñczony w pe³ni...
  parê fajnych rzeczy chcia³em tutaj dopisaæ ;)
*/

char imie[BAZA][11];
char nazwisko[BAZA][17];
int place[BAZA];

int porownaj(int i,int j)
{
	int ktory = strcmp(nazwisko[i],nazwisko[j]);
	if(ktory!=0) return ktory;
	else return strcmp(imie[i],imie[j]);
}
void swap(int i, int j)
{
	char nazwisko_swap[17], imie_swap[11]; int place_swap;
	strcpy(nazwisko_swap, nazwisko[i]);
	strcpy(imie_swap, imie[i]);
	place_swap = place[i];
	
	strcpy(nazwisko[i], nazwisko[j]);
	strcpy(imie[i], imie[j]);
	place[i] = place[j];
	
	strcpy(nazwisko[j], nazwisko_swap);
	strcpy(imie[j], imie_swap);
	place[j] = place_swap;
}
void sort()
{
	  int n, m, k;
	  n=BAZA-1;
	  while (n>0)
	  {
		  m=0;
		  for (k=0; k<n; k=k+1)
			  if (porownaj(k,k+1)>0)
			  {
				  swap(k,k+1);
				  m=k;
			  }
		  n=m;
	  }
}
void printBase()
{
	int T=0;
	while(T<BAZA)
	{
		printf("%10s ",imie[T]);
		printf("%16s ",nazwisko[T]);
		printf("%6d \n",place[T]);
		T++;
	}
}
void scanfBase()
{
	int T = 0;
	FILE* baza_in;
	baza_in = fopen("1.in","r");
	while(T<BAZA)
	{
		fscanf(baza_in,"%s",imie[T]);
		fscanf(baza_in,"%s",nazwisko[T]);
		fscanf(baza_in,"%d",&place[T]);
		T++;
	}
	fclose(baza_in);
}
int binarySearch(char szukaj[])
{
	int P = 0, K = BAZA;
//debug	printf("%s %s\n",szukaj, nazwisko[11]);
	while(P+1 < K)
	{
		int S; S=(P+K)/2;
		if(strcmp(szukaj,nazwisko[S])<0) K = S;
		else P = S;
//debug		printf("%d %d %d\n",P,K,S);
	}
	if(strcmp(szukaj,nazwisko[P])==0) return P;
	else return -1;
}
void elseSearchUP(int q)
{
	if(strcmp(nazwisko[q],nazwisko[q+1])==0)
	{
		printf("Inna osoba o tym nazwisku: %16s %10s %d\n",nazwisko[q+1],imie[q+1],place[q+1]);
		elseSearchUP(q+1);
	}
}
void elseSearchDOWN(int q)
{
	if(strcmp(nazwisko[q],nazwisko[q-1])==0)
	{
		printf("Inna osoba o tym nazwisku: %16s %10s %d\n",nazwisko[q-1],imie[q-1],place[q-1]);
		elseSearchDOWN(q-1);
	}
}
void search()
{
	char szukaj[16];
	
	printf("Podaj nazwisko szukanej osoby: ");
	scanf("%s",szukaj);
	int find = binarySearch(szukaj); //debug printf(">> %d %s << \n",find,szukaj);
	if(find>0) 
	{ 
		printf("Osoba: %16s %10s %d\n",nazwisko[find],imie[find],place[find]);
		elseSearchUP(find);
		elseSearchDOWN(find);
	}
	else printf("Nie ma takiej osoby \n");
}
main()
{	
	scanfBase();
	sort();
	search();
//	printBase();
	
}
