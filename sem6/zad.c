#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student;

int wczytaj(student dane[100], char *fnazwa)
{
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);

    for(i=0; i<cnt; i++)
    {
        fgets(bufor, 1023, fin);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);

        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects= atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
        dane[i].nr_albumu,dane[i].imie,dane[i].nazwisko,
        dane[i].kod_przed,dane[i].nazwa_przed,
        dane[i].ects,dane[i].ocena);
    }
}

int znajdz(char *szukany_nr, char kod_przedmiotu[100][10], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(szukany_nr, kod_przedmiotu[i])==0)
            return i;
    }
    return -1;
}

int znajdz_przed(char kod_przedmiotu[100][10], student dane[100], int n)
{
    int ile_znalazlem=0;
    int i;

    for(i=0; i<n; i++)
    {
        if(znajdz(dane[i].kod_przed, kod_przedmiotu, ile_znalazlem)==-1)
        {
            strncpy(kod_przedmiotu[ile_znalazlem], dane[i].kod_przed,9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

int znajdz_ocena(char kod_przedmiotu[100][10], student dane[100], int n, int ile)
{
    int ile_znalazlem=0;
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(kod_przedmiotu[ile], dane[i].kod_przed)==0)
        {
            ile_znalazlem=ile_znalazlem+1;
        }
    }
    return ile_znalazlem;
    
}


void przedmioty(student dane[100], int ile_rekordow)
{
    float max=0;
    float min;
    int i;
    char kody_przed[100][10];
    int ile_przed;
    float sumy_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int pozycja;
    int najlepsza_pozycja;
    int najgorsza_pozycja;
    float najlepsza = 0.0f;
    float najgorsza = 0.0f;

    ile_przed = znajdz_przed(kody_przed,dane,ile_rekordow);

    for(i=0; i<ile_rekordow; i++)
    {
        
        pozycja = znajdz( dane[i].kod_przed, kody_przed, ile_przed);
        sumy_ects[pozycja]=0;
        sumy_ocen[pozycja]+=dane[i].ocena;
        sumy_ects[pozycja]=znajdz_ocena(kody_przed,dane,ile_rekordow,pozycja);
    }

    
    for(i=0; i<ile_przed; i++)
    {
        if(najlepsza<sumy_ocen[i]/sumy_ects[i])
        {
            najlepsza=sumy_ocen[i]/sumy_ects[i];
            najlepsza_pozycja=i;
        }
    }
    for(i=0; i<ile_przed; i++)
    {
        if(sumy_ocen[i]/sumy_ects[i]>sumy_ocen[i+1]/sumy_ects[i+1])
        {
            najgorsza=sumy_ocen[i]/sumy_ects[i];
            najgorsza_pozycja=i;
        }
    }
    printf("Najleprza srednia: ");
    printf("%s - %f \n", kody_przed[najlepsza_pozycja],sumy_ocen[najlepsza_pozycja]/sumy_ects[najlepsza_pozycja]);
    printf("Najgorsza srednia: ");
    printf("%s - %f \n", kody_przed[najgorsza_pozycja],sumy_ocen[najgorsza_pozycja]/sumy_ects[najgorsza_pozycja]);
}

int main(int argc, char ** argv)
{
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);
    //wypisz(dane, ile);

    przedmioty(dane, ile);

    return 0;
}