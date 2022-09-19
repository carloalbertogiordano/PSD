#include "item.h"
#include "btree.h"

typedef struct stack *Stack;

Stack newStack();
int isEmptyStack(Stack);
void push(Stack, Btree);
Btree pop(Stack);
Btree top(Stack s);
