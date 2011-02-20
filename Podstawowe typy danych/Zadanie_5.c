/*
 * Maciej Małecki
 * smt116@gmail.com
 * */
#include<stdio.h>
int main()
{
	float wzrost; char miara[2];
	printf("Podaj wzrost i miare (XX in/cm) ");
	scanf("%f %s",&wzrost,miara);
	
	int jednostka = strcmp("cm",miara);
	switch(jednostka)
	{
		case 0: printf("%2f cm\n",wzrost/2.54); break;
		default: printf("%2f in\n",wzrost*2.54); break;
	}
	return 0;
}
