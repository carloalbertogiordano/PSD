#include <stdio.h>
#include "sort.h"
#include "utils.h"

int main(void){

  int n = 10;//Grandezza array
  int arr[10] = {4, 3029, 3, 7, 4, 30, 1, 5, 43, 304}; //array
  int oldArr[10] = {4, 3029, 3, 7, 4, 30, 1, 5, 43, 304};

  //insertionSort(arr, n);
  bubbleSort(arr, n);

  printArray(arr, n);
  printf("\n");
  printArray(oldArr, n);
}
