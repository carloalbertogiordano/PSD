#include "btree.h"
#include "queue.h"
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

void printTreeWithQueue(Btree b){
  Queue q = newQueue();
  enqueue(q, b);

  while(!isEmptyQueue(q)){
    Item i = dequeue(q);
    outputItem(i);
  }

}
