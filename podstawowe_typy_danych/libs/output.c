/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include<stdio.h>

/* OPERACJE BITOWE */
void drukujBity(char *prompt, unsigned liczba)
{
    unsigned ilosc_bitow = 8 * sizeof(liczba), bit;

    printf(prompt);

    while (ilosc_bitow--) {
	bit = (liczba >> 1) & 01;
	switch (bit) {
	case '0':
	    putchar('0');
	    break;
	case '1':
	    putchar('1');
	    break;
	default:
	    printf("ERROR");
	    break;
	}
    }
}
