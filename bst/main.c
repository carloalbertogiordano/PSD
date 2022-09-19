#include <stdio.h>
#include "bst.h"
#include "item.h"


int main(){
  BST b = newBST();
  int array[] = { 5, 3, 10, 8, 6, 18};
  int i;
  Item item;
  for(i = 0;i< sizeof(array)/sizeof(int);i++)
    insertBST(&b,&array[i]);

  if(isEmptyBST(b))
    printf("bIsEmpty\n");

  inOrder(b);
  inOrder(b);

  printf("MIN = ");
  outputItem(min(b));
  printf("\nMAX = ");
  outputItem(max(b));

  printLevel(b);

}
