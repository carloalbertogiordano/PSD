#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"

struct node{
    Item item;
    struct node *left;
    struct node *right;
};

BST newBST(){
    return NULL;
}

int isEmptyBST(BST bst){
    if(bst==NULL)
        return 1;
    return 0;
}

Item getItem(BST b){
      if(isEmptyBST(b))
        return NULL;
    return b->item;
}

BST getLeft(BST b){
    if(isEmptyBST(b))
        return NULL;
    return b->left;
}

BST getRight(BST b){
    if(isEmptyBST(b))
        return NULL;
    return b->right;
}

void preOrder(BST b){
    if(!isEmptyBST(b)){
        outputItem(b->item);
        preOrder(b->left);
        preOrder(b->right);
    }
}

void postOrder(BST b){
    if(!isEmptyBST(b)){
        postOrder(b->left);
        postOrder(b->right);
        outputItem(b->item);
    }
}

void inOrder(BST b){
    if(!isEmptyBST(b)){
        inOrder(b->left);
        outputItem(b->item);
        inOrder(b->right);
    }
}

Item search(BST b, Item item){
  if(isEmptyBST(b))
    return NULL;
  int temp = cmpItem(item,b->item);

  if(temp == 0)
    return b->item;
  else if(temp < 0)
    return search(b->left,item);
  else
    return search(b->right,item);
}

Item min(BST b){
  if(isEmptyBST(b))
    return NULL;
  while(b->left != NULL)
    b = b->left;
  return b->item;
}

Item max(BST b){
  if(isEmptyBST(b))
    return NULL;
  while(b->right != NULL)
    b = b->right;
  return b->item;
}

void insertBST(BST *b, Item item){
  if(isEmptyBST(*b)){
    *b = malloc(sizeof(struct node));
    (*b)->item = item;
    (*b)->left = NULL;
    (*b)->right = NULL;
  }
  int temp = cmpItem(item,(*b)->item);
  if(temp < 0)
    insertBST(&((*b)->left),item);
  else if(temp > 0)
    insertBST(&((*b)->right),item);
}

Item deleteBST(BST *b, Item item)
{
	if(isEmptyBST(*b))
		return NULL;
	int temp = cmpItem(item,(*b)->item);

	if(temp == 0)
	{
		if((*b)->left==NULL)
		{
			BST bTemp;
			Item iTemp;
			bTemp=*b;
			iTemp=(*b)->item;
			*b=(*b)->right;
			free(bTemp);
			return iTemp;
		}
		else if((*b)->right==NULL)
		{
			BST bTemp;
			Item iTemp;
			bTemp=*b;
			iTemp=(*b)->item;
			*b=(*b)->left;
			free(bTemp);
			return iTemp;
		}
		else
		{
			Item iTemp,iMax;
			iTemp=(*b)->item;
			iMax=max((*b)->left);
			(*b)->item=iMax;
			deleteBST(&((*b)->left),iMax);
			return iTemp;
		}
	}
	else if(temp < 0)
		return deleteBST(&((*b)->left),item);
	else
		return deleteBST(&((*b)->right),item);

}






int getDepth(bst node){
  if (node == NULL)
          return -1;
      else {
          /* compute the depth of each subtree */
          int lDepth = getDepth(node->left);
          int rDepth = getDepth(node->right);

          /* use the larger one */
          if (lDepth > rDepth)
              return (lDepth + 1);
          else
              return (rDepth + 1);
      }
}


void print2DUtil(bst root, int space, int count) {
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += count;
    // Process right child first
    print2DUtil(root->right, space, count);
    // Print current node after space
    // count
    printf("\n");
    for (int i = count; i < space; i++)
        printf(" ");
    outputItem(root->item);
    printf("\n");
    // Process left child
    print2DUtil(root->left, space, count);
}

// Wrapper over print2DUtil()
void printLevel(bst b) {
   // Pass initial space count as 0 and distance between nodes is 5 units
   print2DUtil(b, 0, 5);
}
