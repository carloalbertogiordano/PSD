#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"
#include "item.h"
int main(){
	BTree th, ta, tc, tp, t14, t1, t2, t6, t11;
	
	t11=buildTree(NULL, NULL, "11");
	t14=buildTree(NULL, NULL, "14");

	t1=buildTree(NULL, NULL, "1");
	t6=buildTree(NULL, NULL, "6");
	t2=buildTree(NULL, NULL, "2");
	
	tc=buildTree(t11, t14, "+");

	ta=buildTree(tc, t1, "-");

	tp=buildTree(t6, t2, "*");
	
	th=buildTree(ta, tp, "/");

	printf("\nAltezza --> %d", getHeight(th));
	printf("\nNumero nodi --> %d\n", numNodi(th));
	printf("Stampa espressione:\n");
	printExpression(th);

	return 0;
}