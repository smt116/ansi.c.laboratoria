#!/bin/bash
clear
gcc -c -Wall -ansi *.c
gcc *.o

echo "2 1 1 1 1" > a.in
./a.out < a.in
echo "2 3 4 -9 6" > a.in
./a.out < a.in

rm *.o
rm a.in
rm a.out
