/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_LIB
#define SMT__LOCAL_LIB

/* biblioteki: */
	#include <stdio.h>
	#include <stddef.h>
	#include <stdlib.h>
	#include <time.h>
	/* polskie znaki: */
	#include <locale.h>
	#include <wchar.h>
	#include <wctype.h>

/* definicje i makra: */
	typedef struct {
		wchar_t q[5];
	} words;

	#define CZAS_START czas_s = clock();
	#define CZAS_STOP clocks = clock() - czas_s;
/* lib.c: */
	void set_lang(void);
	int otworz_plik(FILE **, int *, char *argv[1]);
	void zamknij_plik(FILE **);
	void plwords(words *, unsigned *, unsigned);

#endif
