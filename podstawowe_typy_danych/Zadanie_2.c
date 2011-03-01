/*
Maciej Małecki
smt116@gmail.com

w tresci zadania jest blad, a wlasciwie w
przykladach, bo 0x40 to nie jest A tylko @ ;)
*/
#include<stdio.h>
main()
{
	int kod;
	printf("Podaj kod ASCII, "); scanf("%i",&kod);

	printf("Znak kodu nr %i w ASCII to znak %c\n",kod,(char)kod);
}
