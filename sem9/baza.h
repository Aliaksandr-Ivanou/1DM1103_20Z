#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

 typedef struct _Przedmiot {
     char * kod_przedmota;
     char * nazwa;
     char * semestr;

     struct _Przedmiot *nast;
} Przedmiot;

 typedef struct _Ocena {
     char * nr_albumu;
     char * kod_przedmiotu;

     char * ocena;
     char * koentarz;

     struct _Ocena *nast;
 } Ocena;


typedef struct _SBaza {
    Student *lista_studentow;/* Głowa listy! */
    Przedmiot *lista_przedmiotow;
    Ocena *lista_ocen;
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
void dodaj_przedmiot(SBaza *baza, char * kod, char * nazw, char * sem);
void dodaj_student(SBaza *baza, char * imie, char * nazwisko, char * nr, char * mail);
void dodaj_studenta_do_przedmiotu(SBaza *baza, char * nr, char * kod);

#endif