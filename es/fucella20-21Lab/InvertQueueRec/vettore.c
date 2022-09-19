#include "list.h"

void invertListRec(List l){
  invertListInner(l->head, l->head->next);
}

void invertListInner(Node n1, Node next){
  invertListInner(next, next->next);
}
