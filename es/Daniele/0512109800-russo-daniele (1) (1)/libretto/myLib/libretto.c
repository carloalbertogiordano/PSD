#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libretto.h"

#define MAX 50

struct libretto {
    Studente studente;
    List esami;
};

Libretto newLibretto(Studente std) {

    Libretto lib = malloc(sizeof(struct libretto));

    lib->studente = std;
    lib->esami = newList();

    return lib;
}

void addEsame(Libretto lib, Esame exam) {

    addHead(lib->esami, exam);

}

void printLibretto(Libretto lib) {

    printf("Nome Studente -> %s\n", getNome(lib->studente));
    printf("Cognome Studente -> %s\n", getCognome(lib->studente));
    printf("Matricola Studente -> %s\n", getMatricola(lib->studente));
    printf("\n");
    printList(lib->esami);

}

Esame searchEsame(Libretto lib, char *denominazione) {

    int pos;

    return searchListItem(lib->esami, newEsame(denominazione, NULL, NULL), &pos);

}