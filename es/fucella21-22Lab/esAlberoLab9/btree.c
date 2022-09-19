#include "btree.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

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

int isEmptyTree(Btree b){
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
  if(!isEmptyTree(b)){
    outputItem(b->value);
    preOrder(b->left);
    preOrder(b->right);
  }
}

void postOrder(Btree b) {
  if(!isEmptyTree(b)){
    postOrder(b->left);
    postOrder(b->right);
    outputItem(b->value);
  }
}

void inOrder(Btree b){
  if(!isEmptyTree(b)){
    inOrder(b->left);
    outputItem(b->value);
    inOrder(b->right);
  }
}

int max(int a, int b){
  return a > b ? a:b;
}

int getHeight(Btree b){
  if(b ==  NULL) return 0;

  int l = 0, r = 0;

  l = getHeight(b->left);
  r = getHeight(b->right);

  return max(l, r)+1;
}

int getNNodes(Btree b){

  if(b == NULL) return 0;

  int l = getNNodes(b->left);
  int r = getNNodes(b->right);

  return l+r+1;
}

void levelViewInner(Btree b, int space){
  if(b == NULL) return;

  space += 5;

  levelViewInner(b->right, space);

  printf("\n");
  for(int i =  0; i<space; i++)
    printf(" ");
  outputItem(b->value);
  printf("\n");

  levelViewInner(b->left, space);
}

void levelView(Btree b){
  levelViewInner(b, 0);
}

void iterativePreOrder(Btree b){
  Stack s = newStack();
  push(s, b);

  while(!isEmptyStack(s)){
    Btree tmp = pop(s);
    outputItem(tmp->value);

    if(tmp->right != NULL){
      push(s, tmp->right);
    }
    if(tmp->left != NULL){
      push(s, tmp->left);
    }
  }
  free(s);
}
