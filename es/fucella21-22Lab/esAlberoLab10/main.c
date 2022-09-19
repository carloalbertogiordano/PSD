#include <stdio.h>
#include "btree.h"
#include "item.h"


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


  printf("\nSearch a number \n");
  Item a = inputItem();
  if(searchNum(bh, a) == 1)
    printf("Found\n");
  else
    printf("not found\n");

  Item max = searchMax(bh);
  printf("Largest number is"); outputItem(max); printf("\n");



  Btree bh1=newTree(),ba1=newTree(),bd1=newTree(),bl1=newTree(),bo1=newTree(),bq1=newTree(),bc1=newTree(),bp1=newTree(),bs1=newTree();

  bo1=buildTree(NULL,NULL,newItem(1));
  bq1=buildTree(NULL,NULL,newItem(2));
  bd1=buildTree(NULL,NULL,newItem(3));
  bl1=buildTree(bo,bq,newItem(4));
  bp1=buildTree(NULL,NULL,newItem(5));
  bs1=buildTree(NULL,NULL,newItem(6));
  ba1= buildTree(bd,bl,newItem(7));
  bc1=buildTree(bp,bs,newItem(8));
  bh1=buildTree(ba,bc,newItem(9));

  if(areBreesEqual(bh, bh1))
    printf("btrees are equal\n");
  else
    printf("btrees nnot equal %d\n", areBreesEqual(bh, bh1));

}
