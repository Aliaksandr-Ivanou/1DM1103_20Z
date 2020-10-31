#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int szerokosc;

int wczytaj(FILE *fin, float *tablica)
{
    int wlasciwie_zinterpretowane;
    int dlugosc = 0;
    int i;
    float liczba;

    if ((wlasciwie_zinterpretowane = fscanf(fin, "%d", &dlugosc))!=1)
    {
        printf("Pierwszy napis nie jest liczbą całkowitą"
                "(Liczba prawidłowo zinterpretowanych argumentów: %d)!\n",
                wlasciwie_zinterpretowane);
        exit(-1);
    }

    if ((wlasciwie_zinterpretowane = fscanf(fin, "%d", &szerokosc))!=1)
    {
        printf("Pierwszy napis nie jest liczbą całkowitą"
                "(Liczba prawidłowo zinterpretowanych argumentów: %d)!\n",
                wlasciwie_zinterpretowane);
        exit(-1);
    }
    printf("dlugosc:%d ,szeerokosc:%d\n",dlugosc,szerokosc);


        for (i=0; i<dlugosc*szerokosc; i++)
        {
            if(fscanf(fin, "%f",&liczba)!=1)
            {
                printf("%d-liczba w pliku nie jest liczbą zmiennoprzecinkową.\n",i+1);
                exit(-2);
            }
            tablica[i]=liczba;
            printf("%f ",liczba);
        }
        
    return dlugosc;
} 

void wypisz_wektor(float *w, int n, int s)
{
    printf("(%d), [",n);
        for (int j=0;j<n*s;j++)
           printf("%f ",w[j]);
    printf("]\n");
}


int main(int argc, char *argv[])
{
    FILE *fin;
    float wektor[100];
    int dlugosc;
    
    fin=fopen(argv[1],"r");
    dlugosc=wczytaj(fin,wektor);
    //printf("%d\n",dlugosc);

    //printf("szerokość:%d\n",szerokosc);

    wypisz_wektor(wektor,dlugosc,szerokosc);
    float A[dlugosc][szerokosc];
    float *w=wektor;
    int j=0;
    //printf("[ ");
    for(int s=0;s<szerokosc;s++)
    for (int d=0;d<dlugosc;d++)
        {
            A[d][s]=w[j];
            j++;
        }
    //printf("]\n");
    int szer=szerokosc;

    
    //printf("Suma %d liczb z pliku %s:\n",dlugosc, argv[1]);

    fin=fopen(argv[2],"r");
    dlugosc=wczytaj(fin,wektor);
    //printf("%d\n",dlugosc);

    //printf("szerokość:%d\n",szerokosc);
    
    wypisz_wektor(wektor,dlugosc,szerokosc);

    float x[dlugosc];
    float *wek=wektor;
    for (int i=0;i<dlugosc;i++)
        x[i]=wek[i];

    float nwek[dlugosc];

    //printf("ser: %d\n",szer);
    //for (int j = 0; j < dlugosc; j++)
        for(int s=0;s<=szer;s++)
        {
            nwek[s]=0;
            //printf("s:%d\n",s);
            for(int i=0;i<dlugosc;i++)
                {
                    nwek[s]+=A[i][s]*x[i];
                    //printf("%f ,i=%d ,s=%d,a=%f ,x=%f \n",nwek[s]+=A[i][s]*x[i],i,s,A[i][s],x[i]);
                }
        }
    
    wypisz_wektor(nwek,dlugosc,szerokosc);

    //printf("Suma %d liczb z pliku %s:\n",dlugosc, argv[2]);

    return 0;
}