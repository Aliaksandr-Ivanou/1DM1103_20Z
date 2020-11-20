#include <stdio.h>
#include <stdlib.h>
#include "studenci.h"
#include "dziekanat.h"

int main(int argc, char ** argv)
{
    student dane[100];
    int ile;

    ile = wczytaj(dane, argv[1]);
    wypisz(dane, ile);

    if(argv[2]=="student")
    {
        najlepszy_student(dane, ile);
    }
    if(argv[2]=="przedmiot")
    {
        przedmioty(dane, ile);
    }

    return 0;
}