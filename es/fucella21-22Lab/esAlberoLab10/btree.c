#include "btree.h"
#include <stdlib.h>

struct node{
  Item value;
  struct node *left;
  struct node *right;
};

Btree newTree(){
  Btree b = malloc(sizeof(struct node));
  b->value = NULL;
  b->left = NULL;
  b->right = NULL;
}

int isEmpty(Btree b){
  if(b == NULL) return 1;
  return 0;
}

Btree buildTree(Btree b1, Btree b2, Item i){
  Btree b = newTree();
  b->value = i;
  b->right = b1;
  b->left = b2;
  return b;
}

Item getBtreeRoot(Btree b){
  return b->value;
}

Btree getLeft(Btree b){
  return b->left;
}
Btree getRight(Btree b){
  return b->right;
}

void preOrder(Btree b){
  if(!isEmpty(b)){
    outputItem(b->value);
    preOrder(b->left);
    preOrder(b->right);
  }
}

void postOrder(Btree b) {
  if(!isEmpty(b)){
    postOrder(b->left);
    postOrder(b->right);
    outputItem(b->value);
  }
}

void inOrder(Btree b){
  if(!isEmpty(b)){
    inOrder(b->left);
    outputItem(b->value);
    inOrder(b->right);
  }
}

int searchNum(Btree b, Item a){
  if(!isEmpty(b)){
    if(cmpItem(a, b->value) == 0)
      return 1;
    searchNum(b->left, a);
    searchNum(b->right, a);
  }
}

Item max;

Item searchMaxInnner(Btree b){
  if(!isEmpty(b)){
    if(cmpItem(b->value, max)>0)
      max = b->value;
    searchMaxInnner(b->left);
    searchMaxInnner(b->right);
  }
}

Item searchMax(Btree b){
  max = newItem(0);
  searchMaxInnner(b);
  return max;
}


int areBreesEqualInner(Btree a, Btree b, int flag){
    if(!isEmpty(a) && !isEmpty(b) && flag){
      areBreesEqualInner(a->left, b->left, flag);

      printf("comparing\t"); outputItem(a->value); printf("\t"); outputItem(b->value); printf("\tres:%d\n", cmpItem(a->value, b->value));

      if(cmpItem(a->value, b->value) != 0)
        return 0;

      areBreesEqualInner(a->right, b->right, flag);

      printf("comparing\t"); outputItem(a->value); printf("\t"); outputItem(b->value); printf("\tres:%d\n", cmpItem(a->value, b->value));

      if(cmpItem(a->value, b->value) != 0)
        return 0;
    }
    return flag;
}

int areBreesEqual(Btree a, Btree b){
  int flag = 1;
  flag = areBreesEqualInner(a, b, flag);
  return flag;
}
