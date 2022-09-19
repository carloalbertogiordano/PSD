#include"../item.h"
#include"../list.h"
#include<stdio.h>

int main(void){
  int pos;
  List l = newList();
  Item item;

  for(int i = 0; i < 5; i++){
    printf("Add an element to the list %d/5\n",i);
    item = inputItem();
    addHead(l, item);
  }

  printList(l);

  /*List clone;
  clone = cloneList(l);
  printf("\n");
  printList(clone);*/

  /*reverseList(l);
  printList(l);*/

  /*printf("Add an element in a new position\n Item:");
  item = inputItem();
  printf("Specify now the new position\n");
  scanf("%d",&pos);
  int success = addListItem(l, item, pos);
  if(success) printList(l);
  else printf("Err: cannot add element to the list\n");*/

  /*printf("Insert a Item to search:");
  item = inputItem();
  outputItem(item);
  Item i = searchList(l, i, &pos);
  if(pos == -1) printf("Item not found\n");
  else {printf("Item "); outputItem; printf("found in pos %d\n",pos);}*/

  /*printf("Insert a value to search:");
  item = inputItem();

  pos = searchItemPos(item, l);
  if(pos == -1){printf("Element not found\n");}
  else{
    printf("\n");
    outputItem(item);
    printf("in pos: %d", pos);
  }*/
}
