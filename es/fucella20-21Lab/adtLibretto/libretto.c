#include <stdlib.h>
#include "libretto.h"

struct node{
  char *exam;
  int score;
  struct node *next;
};
struct libretto{
  char *name;
  char *surname;
  struct node *head;
};

Libretto newLibretto (char *n, char *s){
  Libretto l = malloc(sizeof(struct libretto));
  l->name = n;
  l->surname = s;
}

void addExam(Libretto l, char *ex, int s){
  struct node *n = malloc(sizeof(struct node));

  n->exam = ex;
  n->score = s;

  if(l->head == NULL)
    l->head = n;

  else{
    struct node *tmp = l->head;
    do{
      tmp = tmp->next
    }while (tmp->next != NULL);
    tmp->next = n;
  }
}

int searchExamByName(Libretto l, char *name){
  struct node *tmp = l->head;
  while (tmp != NULL) {
    if(strcmp(tmp->name, name))
      return 1;
  }
  return 0;
}
