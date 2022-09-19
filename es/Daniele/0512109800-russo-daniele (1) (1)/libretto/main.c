#include <stdio.h>
#include <stdlib.h>
#include "myLib/list.h"
#include "myLib/libretto.h"

#define MAX 50

int main (void) {

    Libretto lib;
    Esame es;
    char nome[MAX], cognome[MAX], matricola[MAX], denominazione[MAX];
    int i, nEsami;

    printf("Creazione Libretto\n");
    printf("Inserisci nome Studente -> ");
    scanf("%[^\n]", nome);
    getchar();
    printf("Inserisci cognome Studente -> ");
    scanf("%[^\n]", cognome);
    getchar();
    printf("Inserisci matricola Studente -> ");
    scanf("%[^\n]", matricola);
    printf("\n");

    printf("Inserisci il numero di esami da aggiungere -> ");
    scanf("%d", &nEsami);
    

    lib = newLibretto(newStudente(nome, cognome, matricola));

    for (i = 0; i < nEsami; i++) {
        printf("\nInserisci esame %d\n", i + 1);
        es = inputItem();
        addEsame(lib, es);
    }
    printf("\n");

    printLibretto(lib);

    printf("\n");

    printf("Insersici la denominazione dell' esame da cercare -> ");
    scanf("%s", denominazione);

    if (searchEsame(lib, denominazione) == NULL)
        printf("Esame non trovato!\n");
    else
        printf("Esame trovato!\n");


    return 0;

}