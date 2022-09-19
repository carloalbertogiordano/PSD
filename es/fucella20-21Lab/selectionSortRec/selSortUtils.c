#include <stdio.h>

int findMin(int *arr, int s, int dim){

  int minPos=s;

  printf("searchiMin looking at array as \n");
  for(int i = 0; i < s; i++)
    printf("  ");
  for(int i = s; i < dim; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  for(int i = s; i < dim; i++){
    if(arr[i] < arr[minPos]){
      printf("start:%d minPos:%d\n",s, minPos);
      minPos = i;
    }
  }
  return minPos;
}

void swap(int *a, int *b){
  printf("swapping %d and %d\n", *a, *b);
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;

}

void selSort(int *arr, int dim, int s){
  printf("\n\nStart %d\n", s);
  if(s == dim)
    return;

  int minPos = findMin(arr, s, dim);
  printf("min in pos %d\n", minPos);
  if(arr[s] > arr[minPos]){
    printf("swapping %d and %d \t",arr[s] ,arr[minPos] );
    swap(arr+s, arr+minPos);
  }
  for(int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  selSort(arr, dim, ++s);
}
