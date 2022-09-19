#include <stdio.h>
#include "utils.h"

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertSortedArray(int *arr, int* pos){
  for(int i = *pos; i>0; i--){
    if(arr[i]<arr[i-1]){
      swap( arr+i , arr+(i+1));
    }
  }
}

void insertionSort(int *arr, int n){
    for(int i = 1; i <= n; i++){
        insertSortedArray(arr, &i);
      }
}

void bubbleSort(int *a, int dim){
  int stored = 0; //flag
  for(int i = 1; i<dim && stored == 0; i++){
    stored = 1;
    for(int j= 0; j<dim-1; j++){
      if(a[j]>a[j+1]){
        swap(a+j, a+j+1);
        stored=0;
      }
    }
  }
}
