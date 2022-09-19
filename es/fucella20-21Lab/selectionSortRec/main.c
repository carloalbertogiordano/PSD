#include <stdio.h>
#include <unistd.h>
#include "selSortUtils.h"

int main(void){
  int arr[] = {0, 54, 57, 34, 87, 34, 67, 20, 458, 1};

  printf("A lot of DEGUB prints will follow,\nI made this to visualize the alg better\n");

  for(int i = 0; i < 3; i++){
    printf(".");
    fflush(stdout);
    sleep(1);
  }
  printf("\n\n");

  selSort(arr, 10, 1);
}
