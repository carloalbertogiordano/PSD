#include "item.h"

typedef struct node *Btree;

Btree newTree();
int isEmpty(Btree);
Btree buildTree(Btree, Btree, Item);
Item getBtreeRoot(Btree);
Btree getLeft(Btree);
void preOrder(Btree);
void postOrder(Btree);
void inOrder(Btree);
