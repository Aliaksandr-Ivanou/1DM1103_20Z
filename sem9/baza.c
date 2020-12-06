#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
        
    }

    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa_pred = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_przedmiot == NULL)
            glowa_pred = przed;
        else
            last_przedmiot->nast = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przedmota = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przedmota, s);

        s = strtok(NULL, ";");
        przed->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa, s);

        s = strtok(NULL, "\n");
        przed->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->semestr, s);
    }

    return glowa_pred;
}

Ocena * wczytaj_oceny(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
        
    }

    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa_pred = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_przedmiot == NULL)
            glowa_pred = przed;
        else
            last_przedmiot->nast = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przedmota = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przedmota, s);

        s = strtok(NULL, ";");
        przed->nazwa = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa, s);

        s = strtok(NULL, "\n");
        przed->semestr = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->semestr, s);
    }

    Ocena *last_ocena = NULL;
    Ocena *glowa_ocen = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *ocen = (Ocena*) malloc(sizeof(Ocena));
        ocen->nast = NULL;

        if (last_ocena == NULL)
            glowa_ocen = ocen;
        else
            last_ocena->nast = ocen;
        last_ocena = ocen;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocen->kod_przedmiotu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->kod_przedmiotu, s);

        s = strtok(NULL, ";");
        ocen->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->nr_albumu, s);

        s = strtok(NULL, ";");
        ocen->ocena = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->ocena, s);

        s = strtok(NULL, "\n");
        ocen->koentarz = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->koentarz, s);
    }

    return glowa_ocen;
}

SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) {
    FILE *fin = fopen(nazwa_pliku, "w");
    int n, i;
    n=ile_studentow(baza);
    fputc(n,fin);
    while (baza->lista_studentow != NULL){
        fputs(baza->lista_studentow->imie,fin);
        fputs(baza->lista_studentow->imie,fin);
        fputs(baza->lista_studentow->imie,fin);
        fputs(baza->lista_studentow->imie,fin);
    }
    n=ile_przedmiotow(baza);
    fputc(n,fin);
    while (baza->lista_przedmiotow != NULL){
        fputs(baza->lista_przedmiotow->kod_przedmota,fin);
        fputs(baza->lista_przedmiotow->nazwa,fin);
        fputs(baza->lista_przedmiotow->semestr,fin);
    }
    n=ile_ocen(baza);
    fputc(n,fin);
    while (baza->lista_ocen != NULL){
        fputs(baza->lista_ocen->kod_przedmiotu,fin);
        fputs(baza->lista_ocen->nr_albumu,fin);
        fputs(baza->lista_ocen->ocena,fin);
        fputs(baza->lista_ocen->koentarz,fin);
    }

    fclose(fin);
    return NULL;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza) {
    int n = 0;
    Przedmiot * stud = baza->lista_przedmiotow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

int ile_ocen(SBaza *baza) {
    int n = 0;
    Ocena * stud = baza->lista_ocen;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmiot(Przedmiot *p) {
    free(p->kod_przedmota);
    free(p->nazwa);
    free(p->semestr);
    free(p);
}

void zwolnij_ocene(Ocena *o) {
    free(o->nr_albumu);
    free(o->kod_przedmiotu);
    free(o->ocena);
    free(o->koentarz);
    free(o);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *p) {
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnij_liste_ocen(Przedmiot *o) {
    Przedmiot *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_ocene(o);
        o = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_studentow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}

void dodaj_przedmiot(SBaza *p, char * kod, char * nazw, char * sem){
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;

    Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
    przed->nast = NULL;

    if (last_przedmiot == NULL)
        glowa = przed;
    else
        last_przedmiot->nast = przed;
    last_przedmiot = przed;

    strcpy(przed->kod_przedmota, kod);

    strcpy(przed->nazwa, nazw);

    strcpy(przed->semestr, sem);

}

void dodaj_student(SBaza *s, char * imie, char * nazwisko, char * nr, char * mail){
    Student *stud = (Student*) malloc(sizeof(Student));
    stud->nast = NULL;
    Student *last_student = NULL;
    Student *glowa = NULL;

    if (last_student == NULL)
           glowa = stud;
    else
        last_student->nast = stud;
    last_student = stud;

    strcpy(stud->imie, imie);

    strcpy(stud->nazwisko, nazwisko);

    strcpy(stud->nr_albumu, nr);

    strcpy(stud->email, mail);
}

void dodaj_studenta_do_przedmiotu(SBaza *baza, char * nr, char * kod){
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;

    Ocena *ocen = (Ocena*) malloc(sizeof(Ocena));
    ocen->nast = NULL;

    if (last_ocena == NULL)
        glowa = ocen;
    else
        last_ocena->nast = ocen;
    last_ocena = ocen;

    strcpy(ocen->kod_przedmiotu, kod);

    strcpy(ocen->nr_albumu, nr);

    strcpy(ocen->ocena, NULL);

    strcpy(ocen->koentarz, NULL);
}