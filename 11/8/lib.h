/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_LIB
#define SMT__LOCAL_LIB
void wczytaj_dane(int *, char *, char *);
/* wybor_wzoru wywoluje odpowiednia funkcje
 * dla danego wzoru */
void wybor_wzoru(int, char);

/* funkcje wzor_1-4 rysuja odpowiednie wzory */
void wzor_1(int, char);
void wzor_2(int, char);
void wzor_3(int, char);
void wzor_4(int, char);
#endif
