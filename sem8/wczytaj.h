#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef _WCZYTAJ_H
#define _WCZYTAJ_H

typedef struct _Macierz
{
    int r;
    int c;
    float **tab;
} mat;

void wczytaj(FILE * fin, mat *m);
#endif