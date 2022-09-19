#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"
#include "item.h"
int main(){
	BTree th, ta, tc, td, tl, tp, ts, to, tq;
	
	td=buildTree(NULL, NULL, "d");
	to=buildTree(NULL, NULL, "o");
	tq=buildTree(NULL, NULL, "q");
	ts=buildTree(NULL, NULL, "s");
	tp=buildTree(NULL, NULL, "p");
	
	tl=buildTree(to, tq, "l");
	ta=buildTree(td, tl, "a");
	tc=buildTree(tp, ts, "c");
	
	th=buildTree(ta, tc, "h");

	printf("\nAltezza --> %d", getHeight(th));
	printf("\nNumero nodi --> %d\n", numNodi(th));
	printf("Stampa per livelli:\n");
	visitaQueue(th);

	return 0;
}