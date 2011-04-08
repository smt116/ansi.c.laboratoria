/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#include <stdio.h>

int main()
{
	unsigned T,N;
    	
	scanf("%u",&T);
	while(T--)
	{
        scanf("%u",&N);
		switch(N)
          {
                   case 0: printf("0 1\n"); break;
                   case 1: printf("0 1\n"); break;
                   case 2: printf("0 2\n"); break;
                   case 3: printf("0 6\n"); break;
                   case 4: printf("2 4\n"); break;
                   case 5: printf("2 0\n"); break;
                   case 6: printf("2 0\n"); break;
                   case 7: printf("4 0\n"); break;
                   case 8: printf("2 0\n"); break;
                   case 9: printf("8 0\n"); break;
                   default: printf("0 0\n"); break;
          }
	}

	return 0;
}


