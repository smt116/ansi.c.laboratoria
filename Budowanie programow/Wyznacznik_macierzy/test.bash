#!/bin/bash
clear
gcc -c -Wall wczytaj_macierz.c
gcc -c -Wall wyznacznik.c
gcc -c -Wall main.c
gcc wczytaj_macierz.o wyznacznik.o main.o
rm *.o
echo "2 1 1 1 1" > a.in
./a.out < a.in
echo "2 3 4 -9 6" > a.in
./a.out < a.in
rm a.in
rm a.out
