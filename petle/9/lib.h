/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_LIB
#define SMT__LOCAL_LIB

#include<stdio.h>

int otworz_plik(FILE ** in_handle, char *argv[1]);
void zamknij_plik(FILE ** in_handle);
void wczytaj_dane(FILE ** in_handle, unsigned *, double *, double *);
void oblicz(unsigned, double, double);
void error_plik(char *);
#endif