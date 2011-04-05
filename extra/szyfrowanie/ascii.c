/* 
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

void ascii_na_tekst(short **tekst)
{
    unsigned i = 0;
    do {
	printf("%c ", (char) *tekst[i]);
	i++;
    } while (*tekst[i] != EOF);
}
void tekst_na_ascii(short **tekst)
{
}
