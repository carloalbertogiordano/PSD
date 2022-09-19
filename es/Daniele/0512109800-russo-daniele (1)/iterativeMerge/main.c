#include <stdio.h>
#include "array.h"


#define DIM 10


int main(){

	/*int a1[]={1,2,3,4};
	int a2[]={0,6,8,10,12,20};*/
	
	int a[DIM];
	
	printf("Inserisci gli elementi dell'array\n");
    inputArray(a,DIM);
	iterativeMergeSort(a, DIM);
	printArray(a,DIM);


    return 0;
}