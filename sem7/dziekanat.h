#ifndef _DZIEKANAT_H
#define _DZIEKANAT_H
#include "studenci.h"

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);

void najlepszy_student(student dane[100], int ile_rekordow);

int znajdz_przed(char kod_przedmiotu[100][10], student dane[100], int n);

int znajdz_ocena(char kod_przedmiotu[100][10], student dane[100], int n, int ile);

void przedmioty(student dane[100], int ile_rekordow);
#endif