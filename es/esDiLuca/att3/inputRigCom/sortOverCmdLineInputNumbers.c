#include <stdio.h>
#include <stdlib.h>

void ordina(int *arr, int dim){
  for(int i = 0; i < dim; i++)
    for(int j = 0; j < i; j++)
      if(arr[j] > arr[j+1]){
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
}

int main(int argc, char* argv[]){

  printf("Input:\n");
  for(int j = 0; j<argc; j++)
    printf("%d ", atoi(argv[j]));
  printf("\n");

  int *arr = malloc(sizeof(int)*argc);
  int dim = argc;
  --dim;


  for(int i=1; i<argc; i++)
    arr[i-1]=atoi(argv[i]);

    ordina(arr, dim);

  printf("ordinato: ");
  for(int j = 0; j<dim; j++)
    printf("%d ", arr[j]);

  printf("\n");

  free(arr);
}
