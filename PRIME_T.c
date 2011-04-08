/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>
#include <math.h>

int czy_pierwsza(unsigned liczba) {
	unsigned i;
	
	if(liczba==1) {
		return 0;
	} else {
		for(i=2 ; i<=sqrt(liczba) ; i++) {
			if(liczba%i) {
				continue;
			} else {
				return 0;
			}
		}
		return 1;
	}
}

int main() {
    int T;
	unsigned liczba;

	scanf("%i", &T);
	while(T--) {
		scanf("%u", &liczba);
		if(czy_pierwsza(liczba)) { 
			printf("TAK\n"); 
		} else { 
			printf("NIE\n"); 
		}
	}

    return 0;
}
