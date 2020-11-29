#include "zapisz.h"

void zapisz(char nazwa[],mat * m)
{
    FILE * fout = fopen(nazwa,"r");
    int i,j;
    fprintf(fout, "%d\n%d\n",m->r,m->c);
    for(i=0;i<m->r;i++)
        for(j=0;j<m->c;j++)
            fprintf(fout,"%f\n",m->tab[i][j]);
    fclose(fout);
}