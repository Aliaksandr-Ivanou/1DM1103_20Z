#include "wypisz.h"

void wypisz(mat * m)
{
    int i,j;
    printf("[");
    for(i=0;i<m->r;i++)
    {
        for(j=0;j<m->c;j++)
            printf("%5.1f",m->tab[i][j]);
        if(i<(m->r-1))
            printf("\n ");
    }
    printf(" ]\n");
}