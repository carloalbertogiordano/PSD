#include <stdio.h>
#include "list.h"
#include "item.h"
#include <stdlib.h>

int main(void){

  List l = newList();

  printf("Create a list of 5 objects\n");

  for(int i= 0; i<5; i++){
    Item a = inputItem();
    addListTail(l, a);
  }

  int oldsize = sizeof(l);

  printf("This is the list printed recursively\n");
  printListRic(l);

  printf("\nInsert Item to search\n");
  Item sear = inputItem();
  int n = countItemRic(l, sear);

  printf("The element aappears %d times\n", n);

  printf("Inseaart item to search\n");
  sear = inputItem();
  Item res = searchItemRic(l, sear);

  if(res != NULL){
    printf("thee  item is here!");
    outputItem(res);
  }
  else
    printf("Item not found\n");

  dealloclistRec(l);
  if(getHead(l) == NULL)
    printf("List deallocated successfully\n");

  free(l);

  return EXIT_SUCCESS;
}
