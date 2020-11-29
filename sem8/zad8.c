#include "wczytaj.h"
#include "wypisz.h"
#include "norm.h"
#include "zapisz.h"
#include "zwolniej.h"

/*
float **tablica;
int i;
tablica=(float*) malloc(sizeof(float*)*25);
for (i=0;i<25;i++)
    tablica[i]=(float) malloc(sizeof(float)*25);
*/

int main(int argc, char *argv[])
{
    mat * mac;
    FILE * fin;
    if(strcmp(argv[1],"norm")==0)
    {
        fin=fopen(argv[2],"r");
        wczytaj(fin, mac);
        float n=norm(mac);
        mac->r=1;
        mac->c=1;
        mac->tab[0][0]=n;
        if(argv[3]!=NULL)
            zapisz(argv[3],mac);
        else
            wypisz(mac);
        fclose(fin);
        exit(-2);
    } else if(strcmp(  argv[1], "suma")==0)
    {
        mat * mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, mac_a);
        wypisz(mac_a);
        mat * mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, mac_b);
        wypisz(mac_b);
        if(mac_a->r!=mac_b->r)
            exit(-1);
        if (mac_a->c!=mac_b->c)
            exit(-1);
        mac->r=mac_a->r;
        mac->c=mac_a->c;
        int i,j;
        for(i=0;i<mac_a->r;i++)
            for(j=0;j<mac_a->c;j++)
                mac->tab[i][j]=mac_a->tab[i][j]+mac_b->tab[i][j];
        printf("Suma macerzej: \n");
        wypisz(mac);
        fclose(fin);
    }else if(strcmp(  argv[1], "subtract")==0)
    {
        mat * mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, mac_a);
        wypisz(mac_a);
        mat * mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, mac_b);
        wypisz(mac_b);
        mac->r=mac_a->r;
        mac->c=mac_a->c;
        int i,j;
        for(i=0;i<mac_a->r;i++)
            for(j=0;j<mac_a->c;j++)
                mac->tab[i][j]=mac_a->tab[i][j]-mac_b->tab[i][j];
        printf("Suma macerzej: \n");
        wypisz(mac);
        fclose(fin);
    }else if(strcmp( argv[1], "multiply")==0)
    {
        fin=fopen(argv[2],"r");
        wczytaj(fin, mac);
        for(int i=0;i<mac->r;i++)
            for(int j=0;j<mac->c;j++){
                mac->tab[i][j]=mac->tab[i][j]*atof(argv[3]);
            }
        fclose(fin);
    }else if(strcmp(  argv[1], "prod")==0)
    {
        mat * mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, mac_a);
        mat * mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, mac_b);
        mac->c=mac_a->r;
        mac->r=mac_b->c;
        for(int i=0;i<mac_b->r;i++)
            for(int j=0;j<mac_a->c;j++){
                mac->tab[i][j]=mac_a->tab[i][j]*mac_b->tab[j][i];
                printf("%f\n",mac->tab[i][j]);
            }
        fclose(fin);
    }
    if(argv[4]!=NULL)
        zapisz(argv[4],mac);
    else
        wypisz(mac);
    zwolniej(mac);
    return 0;
}
