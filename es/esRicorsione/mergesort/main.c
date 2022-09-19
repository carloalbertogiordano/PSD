#include <stdio.h>
#include <stdlib.h>

#define DIM 10

void merge(int *a, int n1, int *b, int n2){ //array dim/2 &dim/2 dim/2+1
	int i, j, k, d[n1 + n2];
	for(i=0, j=0, k=0; i<n1 && j<n2; k++){
    if(a[i] <= b[j]){
      d[k] = a[i];
      i++;
    }
    else{
      d[k] = b[j];
      j++;
    }
  }
  for(; i<n1; i++, k++)
    d[k] = a[i];
  for(; j<n2; j++, k++)
    d[k] = b[j];
  for(k = 0; k< n1+n2; k++)
    a[k] = d[k];
}

void mergeSort(int *a, int n){
  for(int i = 0; i<n; i++)
  if(n > 1){
    mergeSort(a, n/2);
		mergeSort(a+n/2, n-n/2);
    merge(a, n/2, a+n/2, n-n/2);
  }
}

int main (void){
  int arr[DIM] = {30,15,7,10,4,20,9,8,143,1000};

  mergeSort(arr, DIM);

  printf("RESULT : \t");
  for(int i = 0; i<DIM; i++)
    printf("%d ", arr[i]);
  printf("\nEXPECTED : \t4 7 8 9 10 15 20 30 143 1000\n");
}
