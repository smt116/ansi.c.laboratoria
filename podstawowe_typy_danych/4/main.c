/*
 * Maciej Małecki
 * smt116@gmail.com
 */

#include"lib.h"

int main(){
	int wiek[2];
	pobierz_wiek("Podaj wiek (dd-mm-rrrr) ", wiek);

	wiek_na_sekundy(wiek);

	return 0;
}
