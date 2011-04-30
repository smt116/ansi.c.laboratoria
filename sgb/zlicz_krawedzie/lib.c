/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void set_lang(void) {
	char *lc_type;
	if(!(lc_type = setlocale(LC_CTYPE, ""))) {
		fwprintf(stderr, L"ERROR: Can't set pl_PL.utf8");
		exit(1);
	} else {
		wprintf(L"-> Zestaw znakow: %s\n", lc_type);
	}
}

int otworz_plik(FILE **plik, int *argc, char *argv[1]) {
	if(*argc !=2 ) {
		wprintf(L"Poprawne wywołanie: ./program nazwa_pliku\n");
		return 0;
	} else {
		*plik = fopen(argv[0], "r");
		if(*plik == NULL) {
			wprintf(L"Plik nieistnieje!\n");
			return 0;
		} else {
			return 1;
		}
	}
}

void zamknij_plik(FILE **plik) {
	fclose(*plik);
}

void policz_krawedzie(words *tab, unsigned *vec, unsigned wiersz) {
	unsigned i, k, p, tmp;
	wint_t a,b;

	for(i=0 ; i<wiersz ; i++) {

		for(k=i+1 ; k<wiersz ; k++) {
			tmp=0;

			for(p=0 ; p<5 ; p++) {
				if(tab[i].q[p] != tab[k].q[p])tmp++;
				if(tmp>1) break;
			}
			if(tmp==1) *vec+=1;
		}
	}
}
