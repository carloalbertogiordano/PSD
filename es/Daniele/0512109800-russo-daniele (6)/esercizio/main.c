#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"
#include "item.h"

int main(){
	
	
	BTree th, ta, tc, td, tl, tp, ts, to, tq;
	BTree th1, ta1, tc1, td1, tl1, tp1, ts1, to1, tq1;
	int s;
	
	int first[9]= {4, 6, 8, 2, 3, 9, 7, 1, 0};
	int second[9]= {4, 6, 8, 2, 3, 9, 7, 1, 0};
	
	td=buildTree(NULL, NULL, first + 0);
	to=buildTree(NULL, NULL, first + 1);
	tq=buildTree(NULL, NULL, first + 2);
	ts=buildTree(NULL, NULL, first + 2);
	tp=buildTree(NULL, NULL, first + 4);
	
	tl=buildTree(to, tq, first + 5);
	ta=buildTree(td, tl, first + 6);
	tc=buildTree(tp, ts, first + 7);
	
	th=buildTree(ta, tc, first + 8);


	td1=buildTree(NULL, NULL, second + 0);
	to1=buildTree(NULL, NULL, second + 1);
	tq1=buildTree(NULL, NULL, second + 2);
	ts1=buildTree(NULL, NULL, second + 2);
	tp1=buildTree(NULL, NULL, second + 4);
	
	tl1=buildTree(to1, tq1, second + 5);
	ta1=buildTree(td1, tl1, second + 6);
	tc1=buildTree(tp1, ts1, second + 7);
	
	th1=buildTree(ta1, tc1, second + 8);

	preOrder(th);

	
	printf("Inserisci l'elemento da cercare -> ");
	Item search = inputItem();

	Item out = searchBTree(th, search);

	if(out!= NULL){
		printf("Elemento trovato!\n");
		outputItem(out);
	}
	else
		printf("Elemento non trovato!\n");


	printf("\nIl massimo dell'albero -> ");
	outputItem(maxTree(th));

	if(cmpBTree(th,th1))
		printf("\nGli alberi sono uguali\n");
	else
		printf("\nGli alberi non sono uguali\n");

	printf("\n");
	
	return 0;
}