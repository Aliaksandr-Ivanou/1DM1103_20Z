#include "dziekanat.h"

int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].nr_albumu, nr_albumow, ile_znalazlem ) == -1) {
            strncpy(nr_albumow[ile_znalazlem], dane[i].nr_albumu, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

void najlepszy_student(student dane[100], int ile_rekordow) {
    char nr_albumow[100][10];
    int ile_studentow;
    float sumy_wazonych_ocen[100];
    int sumy_ects[100];
    float srednie[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_studentow = znajdz_studentow(nr_albumow, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].nr_albumu, nr_albumow, ile_studentow );
        // if (pozycje >= 0)
        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (i=0;i<ile_studentow; i++) 
        printf("Student [%d]: %s - %f:%d - %f \n", i, nr_albumow[i], 
        sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_studentow; i++) {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", 
        najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja],
        sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja]
    );

    printf("%d\n", sumy_ects[ znajdz("444444", nr_albumow, ile_studentow) ]);

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
