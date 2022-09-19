#include <stdio.h>
#include "utils.h"
#include "array.h"


void printArray(int *a, int n){

    int i;
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}



void inputArray(int *arr, const int n){

    int i;
    for(i = 0; i < n; i++)
        scanf("%d", arr + i);

}



void merge(int *a1,int *a2, int n1, int n2, int *a)
{
	int i,j,k;
	int b[n1+n2];

	for(i=0,j=0,k=0;i<n1 && j<n2;k++)
	{
		if(a1[i]<=a2[j])
			b[k]=a1[i++];
		else
			b[k]=a2[j++];
	}

	for( ;i<n1;i++,k++)
		b[k]=a1[i];

	for( ;j<n2;j++,k++)
		b[k]=a2[j];

	for(k=0;k<n1+n2;k++)
		a[k]=b[k];

}

void mergeSort(int *a,int n)
{
	if(n>1)
	{
		mergeSort(a,n/2);
		mergeSort(a+n/2,n-n/2);
		merge(a,a+n/2,n/2,n-n/2,a);
	}
}

void qSort (int *a, int low, int high){
	if (low<high){
		int q=partition(a, low, high);
		qSort(a, low, q);
		qSort(a, q+1, high);
	}
}

void quickSort (int *a, int n){
	qSort (a, 0, n-1);
}



int partition (int *a, int low, int high){
	int pivot =a[low];
	int i=low-1, j=high+1;
	while (1){
		do{
			j--;
		}while (a[j]>pivot);
		do{
			i++;
		}while (a[i]<pivot);
		if (i>=j)
			return j;
		swap(&a[i], &a[j]);
	}
}

void iterativeMergeSort (int *a, int size){
	int currentSize, leftIndex, midIndex, rightIndex;

	for(currentSize=1;currentSize<size;currentSize=2*currentSize){

		for(leftIndex=0;leftIndex<size;leftIndex+=2*currentSize){

			midIndex = leftIndex + currentSize - 1;
			if (leftIndex + 2 * currentSize - 1 < size - 1)
				rightIndex = leftIndex + 2 * currentSize - 1;
			else
				rightIndex = size - 1;

			merge(a+leftIndex,a+midIndex+1,currentSize,rightIndex-midIndex,a+leftIndex);
		}
	}
}
