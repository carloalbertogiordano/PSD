#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"
#include "queue.h"
#include "stack.h"
#include "item.h"

struct node{
	Item value;
	struct node *left;
	struct node *right;
};

BTree newTree(){
	return NULL;
}

int isEmptyTree(BTree b){
	if(b==NULL) return 1;
	return 0;
}

BTree buildTree(BTree b1, BTree b2, Item e){
	if(e==NULL) return NULL;
	BTree b=malloc(sizeof(struct node));
	b->value=e;
	b->left=b1;
	b->right=b2;
	
	return b;
}

Item getBTreeRoot(BTree b){
	if(isEmptyTree(b)) return NULL;
	return b->value;
}

BTree getLeft(BTree b){
	if(isEmptyTree(b)) return NULL;
	return b->left;
}
BTree getRight(BTree b){
	if(isEmptyTree(b)) return NULL;
	return b->right;
}

void preOrder(BTree b){
	if(!isEmptyTree(b)){
		outputItem(b->value);
		preOrder(b->left);
		preOrder(b->right);
	}
}
void postOrder(BTree b){
	if(!isEmptyTree(b)){
		postOrder(b->left);
		postOrder(b->right);
		outputItem(b->value);
	}
}
void inOrder(BTree b){
	if(!isEmptyTree(b)){
		inOrder(b->left);
		outputItem(b->value);
		inOrder(b->right);	
	}	
}

int maxHeight(int bRight, int bLeft){
	if(bRight > bLeft)
		return bRight;
	else
		return bLeft;
}

int getHeight (BTree b){
	if(isEmptyTree(b))
		return -1;
	
	return 1 + maxHeight(getHeight(b->right), getHeight(b->left));
}

int numNodi (BTree b){
	if(isEmptyTree(b))
		return 0;

	return numNodi(b->left) + numNodi(b->right) + 1;
}

void visitaQueue (BTree b){
	BTree left, right;
	Queue q = newQueue();
	enqueue(q, b);				

	while(!isEmptyQueue(q)){
		BTree node = dequeue(q);	
		outputItem(node->value);

		left = getLeft(node);		
		if(left != NULL){
			enqueue(q, left);		
		}
		right = getRight(node);
		if(right != NULL){
			enqueue(q, right);		
		}
	}
}


void preOrderStack(BTree b){
	Stack s = newStack();
	BTree left, right;

	push(s, b);
	while(!isEmptyStack(s)){
		BTree node = top(s);
		outputItem(node->value);
		pop(s);
		right = getRight(node);
		if(right != NULL){
			push(s, right);
		}
		left = getLeft(node);		
		if(left != NULL){
			push(s, left);
		}
	}
}


void postOrderStack(BTree b){
	Stack s = newStack();
	BTree p = NULL; 

	while(!isEmptyTree(b)||!isEmptyStack(s)){
		if(!isEmptyTree(b)){
			push(s, b);
			b = b->left;
		}
		else{
			b = top(s);			
			if(isEmptyTree(b->right)||b->right == p){
				outputItem(b->value);
				pop(s);					
				p = b;					
				b = NULL;				
			}
			else
				b = b->right;		
		}
	}
}
void inOrderStack(BTree b){
	Stack s = newStack();

	while(!isEmptyTree(b)||!isEmptyStack(s)){
		if(!isEmptyTree(b)){
			push(s, b);
			b = b->left;
		}
		else{
			b = top(s);
			pop(s);
			outputItem(b->value);
			b = b->right;			
		}
	}
}