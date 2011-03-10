/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef _LIB_ZAD_8
#define _LIB_ZAD_8
/* Funkcja wczyta liczby */
void wczytaj(int n, double tab[n]);

/* Naglowki funkcji wykorzystywanych przez operacje() */
double suma(int n, double tab[n]);
double iloczyn(int n, double tab[n]);
int min(int n, double tab[n]);
int max(int n, double tab[n]);

/* Funkcja poda wynik dzialan */
void operacje(int n, double tab[n]);
#endif
