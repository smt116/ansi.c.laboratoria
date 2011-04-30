/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int main(int argc, char *argv[])
{
	FILE *plik;
	wchar_t bufor[BUFSIZ], znak;
	unsigned krawedzi = 0;
	clock_t czas_s, clocks;
	size_t rozmiar = sizeof(words), 
			rekord = 0;
	words *tablica = malloc(rozmiar * sizeof *tablica),
		tmp;
/**/
	set_lang();
/**/
	if(otworz_plik(&plik, &argc, &argv[1])) {
		CZAS_START;
		while(fgetws(bufor, BUFSIZ, plik)) {
			swscanf(bufor, L"%5S", tmp.q);

			if(tmp.q[0] != L'*') {
				if(rozmiar == rekord) {
					words *tmp = realloc(tablica, (rozmiar*=2) * sizeof *tmp);
					tablica=tmp;
				}
				tablica[rekord++] = tmp;
			}
		}
/**/
		policz_krawedzie(tablica, &krawedzi, rekord);
		CZAS_STOP;

		wprintf(L"Ilość krawędzi:\t%u\nCzas procesora:\t%ld (%ld sekund)\n", 
				krawedzi, clocks, clocks/CLOCKS_PER_SEC);

		zamknij_plik(&plik);
		free(tablica);
	}

	return 0;
}
