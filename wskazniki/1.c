#include <stdio.h>

void kwadrat (int l, int *n) {
  *n = l*l;
}

void wczytaj_liczbe(int *n) {
  printf("Podaj liczbe naturalna: ");
  scanf("%d", n);
}

int main()
{
  int liczba, wynik;
  wczytaj_liczbe(&liczba);
  kwadrat(liczba, &wynik);

  printf("Podano liczbe %d. Jej kwadrat to %d\n", liczba, wynik);

  return 0;
}

