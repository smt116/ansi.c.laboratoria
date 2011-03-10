/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>
#include"lib.h"

int wczytaj_kod(char *prompt){
	int kod;
	printf(prompt);
	scanf("%i",&kod);
	return kod;
}

void kod_na_znak(int n){
	printf("Znak o kodzie %i to %c\n",n,(char)n);
}
