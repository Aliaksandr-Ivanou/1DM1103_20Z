#include "wczytaj.h"

void wczytaj(FILE * fin, mat *m)
{
    int i,j;
    m=(mat*) malloc(sizeof(mat));
    fscanf(fin,"%d",m->r);
    fscanf(fin,"%d",m->c);
    m->tab = (float*) malloc(sizeof(float*)*25);
    for(i=0;i<m->r;i++)
    {
        m->tab[i] = (float*) malloc(sizeof(float) * m->c);
        for (j=0;j<m->c;j++)
            m->tab[i][j] = j+1+i;
    }
}
