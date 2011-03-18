/* 
	Maciej Małecki
	smt116@gmail.com
*/
#include<stdio.h>
#include<limits.h>
int main()
{
    //wartosci nizej mozna policzyc w programie
    //za pomoca operatorow logicznych ale po co :D....:
    char ch = CHAR_MIN;
    unsigned char uch = UCHAR_MAX;
    short sh = SHRT_MIN;
    unsigned short ush = USHRT_MAX;
    int in = INT_MIN;
    unsigned int uin = UINT_MAX;
    long lo = LONG_MIN;
    unsigned long ulo = ULONG_MAX;

    printf("char\t %c %c\n", ch, uch);
    printf("short\t %hi %hi\n", sh, ush);
    printf("int\t %i %u\n", in, uin);
    printf("long\t %li %lu\n", lo, ulo);

    return 0;
}
