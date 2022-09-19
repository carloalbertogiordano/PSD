#include "item.h"

typedef struct node *BTree;

BTree newTree();
int isEmptyTree(BTree);
BTree buildTree(BTree, BTree, Item);
Item getBTreeRoot(BTree);
BTree getLeft(BTree);
BTree getRight(BTree);
void preOrder(BTree);
void postOrder(BTree);
void inOrder(BTree);

//es
int maxHeight(int, int);
int getHeight (BTree);
int numNodi (BTree);
void visitaQueue (BTree);
void preOrderStack(BTree);
void postOrderStack(BTree);
void inOrderStack(BTree);