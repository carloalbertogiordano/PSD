#include <stdio.h>
#include "entry.h"
#include "key.h"
#include "hashtable.h"
#include "item.h"
#include "list.h"

#define DIM 3

int main(){
	int i;
	Key k;
	Entry e;
	Item it;
	HashTable h;

	h=newHashtable(DIM);

	for(i=0;i<DIM;i++){
		printf("inut key: ");
		k=inputKey();
		printf("\nInput item: ");
		it=inputItem();
		e=newEntry(k, it);
		insertHash(h, e);
	}

	printf("\nsearch Key\n");
	k=inputKey();
	e=searchHash(h, k);
	if(e != NULL)
		outputItem(getValue(e));
	else printf("non presente. \n");

	return 0;
}
