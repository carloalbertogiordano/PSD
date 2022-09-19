#include "esame.h"
#include "studente.h"
#include "list.h"

typedef struct libretto *Libretto;

Libretto newLibretto(Studente std);
void addEsame(Libretto lib, Esame exam);
void printLibretto(Libretto lib);
Esame searchEsame(Libretto lib, char *denominazione);