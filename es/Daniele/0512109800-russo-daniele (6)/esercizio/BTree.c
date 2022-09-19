#include <stdlib.h>
#include "BTree.h"
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

Item searchBTree (BTree b, Item item) {

    Item res;

    if(!isEmptyTree(b))
        if(cmpItem(b->value, item)==0)
            return b->value;
        else  
            if((res=searchBTree(getLeft(b), item))!=NULL)
                return res;
            else
                if((res=searchBTree(getRight(b), item))!=NULL)
                    return res;

    return NULL;
}

Item max(Item a, Item b, Item c){
	Item temp;

	if (cmpItem(a,b) > 0)
		temp = a;
	else
		temp = b;

	if (cmpItem(temp,c) > 0)
		return temp;
	else
		return c;
}

Item maxTree(BTree b){
	Item maxLeft, maxRight, curr;
	int min = -1;

	if (!isEmptyTree(b)){
		curr = b->value;
		if ((maxLeft = maxTree(getLeft(b))) == NULL)
			maxLeft = &min;
		if ((maxRight = maxTree(getRight(b))) == NULL)
			maxRight = &min;			
		return max(maxLeft, maxRight, curr);
						}
	else 
		return NULL;
}

int cmpBTree(BTree a, BTree b){
	int flag = 0;
	
	if (isEmptyTree(a)&&isEmptyTree(b))
		return 1;
	if (!isEmptyTree(a)&&!isEmptyTree(b)){
		if (cmpItem(a->value,b->value)==0)
			flag=1;
		return (flag&&cmpBTree(a->left, b->left)&&cmpBTree(a->right, b->right));
	}
	return 0;
}