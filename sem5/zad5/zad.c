#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz
{
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE * fin, struct Macierz *m)
{
    int i,j;
    fscanf(fin,"%d",&m->r);
    fscanf(fin,"%d",&m->c);
    for(i=0;i<m->r;i++)
        for (j=0;j<m->c;j++)
            fscanf(fin,"%f",&m->tab[i][j]);
}

void wypisz(struct Macierz m)
{
    int i,j;
    printf("[");
    for(i=0;i<m.r;i++)
    {
        for(j=0;j<m.c;j++)
            printf("%5.1f",m.tab[i][j]);
        if(i<(m.r-1))
            printf("\n ");
    }
    printf(" ]\n");
}

float norm(struct Macierz m)
{
    float s=0;
    int i,j;
    for(i=0;i<m.r;i++)
        for(j=0;j<m.c;j++)
            s+=m.tab[i][j]*m.tab[i][j];
    return sqrt(s);
}

void zapisz(char nazwa[],struct Macierz m)
{
    FILE * fout = fopen(nazwa,"r");
    int i,j;
    fprintf(fout, "%d\n%d\n",m.r,m.c);
    for(i=0;i<m.r;i++)
        for(j=0;j<m.c;j++)
            fprintf(fout,"%f\n",m.tab[i][j]);
    fclose(fout);
}

int main(int argc, char *argv[])
{
    struct Macierz mac;
    FILE * fin;
    if(strcmp(argv[1],"norm")==0)
    {
        fin=fopen(argv[2],"r");
        wczytaj(fin, &mac);
        float n=norm(mac);
        mac.r=1;
        mac.c=1;
        mac.tab[0][0]=n;
        if(argv[3]!=NULL)
            zapisz(argv[3],mac);
        else
            wypisz(mac);
        fclose(fin);
        exit(-2);
    } else if(strcmp(  argv[1], "suma")==0)
    {
        struct Macierz mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, &mac_a);
        wypisz(mac_a);
        struct Macierz mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, &mac_b);
        wypisz(mac_b);
        if(mac_a.r!=mac_b.r)
            exit(-1);
        if (mac_a.c!=mac_b.c)
            exit(-1);
        mac.r=mac_a.r;
        mac.c=mac_a.c;
        int i,j;
        for(i=0;i<mac_a.r;i++)
            for(j=0;j<mac_a.c;j++)
                mac.tab[i][j]=mac_a.tab[i][j]+mac_b.tab[i][j];
        printf("Suma macerzej: \n");
        wypisz(mac);
        fclose(fin);
    }else if(strcmp(  argv[1], "subtract")==0)
    {
        struct Macierz mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, &mac_a);
        wypisz(mac_a);
        struct Macierz mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, &mac_b);
        wypisz(mac_b);
        mac.r=mac_a.r;
        mac.c=mac_a.c;
        int i,j;
        for(i=0;i<mac_a.r;i++)
            for(j=0;j<mac_a.c;j++)
                mac.tab[i][j]=mac_a.tab[i][j]-mac_b.tab[i][j];
        printf("Suma macerzej: \n");
        wypisz(mac);
        fclose(fin);
    }else if(strcmp( argv[1], "multiply")==0)
    {
        fin=fopen(argv[2],"r");
        wczytaj(fin, &mac);
        for(int i=0;i<mac.r;i++)
            for(int j=0;j<mac.c;j++){
                mac.tab[i][j]=mac.tab[i][j]*atof(argv[3]);
            }
        fclose(fin);
    }else if(strcmp(  argv[1], "prod")==0)
    {
        struct Macierz mac_a;
        fin=fopen(argv[2],"r");
        wczytaj(fin, &mac_a);
        struct Macierz mac_b;
        fin=fopen(argv[3],"r");
        wczytaj(fin, &mac_b);
        mac.c=mac_a.r;
        mac.r=mac_b.c;
        for(int i=0;i<mac_b.r;i++)
            for(int j=0;j<mac_a.c;j++){
                mac.tab[i][j]=mac_a.tab[i][j]*mac_b.tab[j][i];
                printf("%f\n",mac.tab[i][j]);
            }
        fclose(fin);
    }
    if(argv[4]!=NULL)
        zapisz(argv[4],mac);
    else
        wypisz(mac);
    return 0;
}
