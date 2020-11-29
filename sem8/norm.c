#include "norm.h"

float norm(mat * m)
{
    float s=0;
    int i,j;
    for(i=0;i<m->r;i++)
        for(j=0;j<m->c;j++)
            s+=m->tab[i][j]*m->tab[i][j];
    return sqrt(s);
}