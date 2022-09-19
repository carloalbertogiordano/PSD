//Strange make error?

#include <stdio.h>
#include "libretto.h"

int main (void){

  char name[20], surname[20];

  printf("insert your name max 20\n");
  scanf("%s", name);
  printf("insert your surname max 20\n");
  scanf("%s", surname);

  Libretto l = newLibretto(name, surname);

  printf("adding 2 exams\n");
  addExam(l, "esame1", 20);
  addExam(l, "esame2", 20);

  printf("Chacking...\n");
  if(searchExamByName(l, "esame1") && searchExamByName(l, "esame2"))
    printf("All ok\n");
  printf("catastrofiuc error aaasraaaa nooiooo\n");

  free(l);
}
