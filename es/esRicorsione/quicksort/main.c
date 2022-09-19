#include <stdio.h>

#define DIM 10

void swap(int *a, int *b){
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int *array, int low, int high){
  int i = low-1;
  int j = high+1;
  int x = array[low];

  while(1){
    do{
      j--;
    }while(array[j] > x);
    do{
      i++;
    }while(array[i] < x);
    if(i >= j)
      return j;
    swap(&array[i],&array[j]);
  }
}

void quicksort(int *a, int start, int finish1) {
  int finish = --finish1;
  if(start < finish){
    int j = partition(a, start, finish/2);
    quicksort(a, start, j);
    quicksort(a, ++j, finish);
  }
}


int main(void){
  int arr[DIM] = {30,15,7,10,4,20,9,8,143,1000};

  quicksort(arr, 0, DIM);

  printf("DEFAULT :\t30,15,7,10,4,20,9,8,143,1000\nRESULT : \t");
  for(int i = 0; i<DIM; i++)
    printf("%d ", arr[i]);
  printf("\nEXPECTED : \t4 7 8 9 10 15 20 30 143 1000\n");
}
