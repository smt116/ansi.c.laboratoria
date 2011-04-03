/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include "lib.h"

int wywolanie(int kod_bledu) {
    switch (kod_bledu) {
	    case 2:	
			printf("Za duzo argumentow\nPoprawne wywolanie: ./main plik\n",
					strerror(errno)); 
			return 0; break;
	    case 1:	
			printf("Plik nieistnieje\n", strerror(errno));
			return 0; break;
   		default: return 0;
    }
}

int otworz_plik(FILE ** in_handle, int *argc, char *argv[1])
{
    *in_handle = fopen(argv[0], "r");
    if (*argc != 2) {
		wywolanie(2);
		return 0;
    } else {
			if (*in_handle == NULL) {
	    		wywolanie(1);
	    		return 0;
		} else {
	    	return 1;
		}
    }
}

void zamknij_plik(FILE ** in_handle)
{
    /* osobna funkcja jako furtka
     * do pozniejszej rozbudowy */
    fclose(*in_handle);
}
