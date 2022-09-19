#include <stdio.h>
#include "../btree.h"
#include "../item.h"


int main(){
  Btree bh=newTree(),ba=newTree(),bd=newTree(),bl=newTree(),bo=newTree(),bq=newTree(),bc=newTree(),bp=newTree(),bs=newTree();

  bo=buildTree(NULL,NULL,newItem(1));
  bq=buildTree(NULL,NULL,newItem(2));
  bd=buildTree(NULL,NULL,newItem(3));
  bl=buildTree(bo,bq,newItem(4));
  bp=buildTree(NULL,NULL,newItem(5));
  bs=buildTree(NULL,NULL,newItem(6));
  ba= buildTree(bd,bl,newItem(7));
  bc=buildTree(bp,bs,newItem(8));
  bh=buildTree(ba,bc,newItem(9));

  printf("\n\n\n");

  printf("\nPre order: ");
  preOrder(bh);
  printf("\nPost Order: ");
  postOrder(bh);
  printf("\nIn order : ");
  inOrder(bh);

}
