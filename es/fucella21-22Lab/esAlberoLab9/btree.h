#include "item.h"

typedef struct node *Btree;

Btree newTree();
int isEmptyTree(Btree);
Btree buildTree(Btree, Btree, Item);
Item getBtreeRoot(Btree);
Btree getLeft(Btree);
void preOrder(Btree);
void postOrder(Btree);
void inOrder(Btree);
int getHeight(Btree);
int getNNodes(Btree);
void levelView(Btree);
void iterativePreOrder(Btree);
void iterativePostOrder(Btree);
