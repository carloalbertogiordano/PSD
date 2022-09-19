#include <stdlib.h>
#include <string.h>
#include "studente.h"

#define MAX 50

struct studente {
    char nome[MAX];
    char cognome[MAX];
    char matricola[MAX];
};

Studente newStudente(char *nome, char *cognome, char *matricola) {

    Studente std = malloc(sizeof(struct studente));

    strcpy(std->nome, nome);
    strcpy(std->cognome, cognome);
    strcpy(std->matricola, matricola);

    return std;

}

char *getNome(Studente std) {

    char *nome = (char *) malloc((1 + strlen(std->nome)) * sizeof(char));
    strcpy(nome, std->nome);

    return nome;

}

char *getCognome(Studente std) {

    char *cognome = (char *) malloc((1 + strlen(std->cognome)) * sizeof(char));
    strcpy(cognome, std->cognome);

    return cognome;

}
char *getMatricola(Studente std) {

    char *matricola = (char *) malloc((1 + strlen(std->matricola)) * sizeof(char));
    strcpy(matricola, std->matricola);

    return matricola;

}