#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strtool.h"

int main(void){

  int lnome, lcognome;
  Nome n;
  Cognome c;

  printf("Quanto è lungo il tuo nome?: ");
  scanf("%d", &lnome);
  fflush(stdin);
  n = creaNome(lnome);

  printf("Quanto è lungo il tuo cognome?: ");
  scanf("%d", &lcognome);
  fflush(stdin);
  c = creaCognome(lcognome);

  stampa(n, c);

  Matrix m = buildMatrix(n, c);
  stampaMatrice(m);

  String s = Merge(n, c);
  printf("Concat:");
  printString(s);
  printf("\n");

  printf("Incastona: ");
  String s1 = incastona(m);
  if(s1 != NULL){
    printString(s1);
  }
  printf("\n");

  printf("\nInverti: ");
  inverti(m);
  stampaMatrice(m);

  printf("\ncrea:");
  crea(m);
  stampaMatrice(m);

  printf("ordina nome\n");
  ordina(n);
  printString(n);

  free(n);
  free(c);
  free(m);
  free(s);
  free(s1);
}
