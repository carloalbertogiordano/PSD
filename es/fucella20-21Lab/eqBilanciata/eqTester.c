#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void processEq(char *eq, int *res){
  for(int i = 0; i < strlen(eq); i++){
    if(eq[i] == '(')
      res[i] = 1;
    if(eq[i] == ')')
      res[i] = -1;
    if(eq[i] == '[')
      res[i] = 2;
    if(eq[i] == ']')
      res[i] = -2;
    if(eq[i] == '{')
      res[i] = 3;
    if(eq[i] == '}')
      res[i] = -3;
  }
}

int getNext(int *arr, int size){
  int curr = 3;
  for(int i = 0; i < size; i++)
    if(arr[i] > 0 && arr[i] < 3)
      curr = arr[i];
  return curr;
}

void removePar(int *arr, int size, int tbr){ //tbr = to be removed
  for(int i = 0; i < size; i++){
    if(arr[i] == tbr || arr[i] == (-1*tbr))
      arr[i] = 0;
  }
}

int checkArr(int *arr, int size){
  for(int i = 0; i < size; i++){
    printf("size=%d, i=%d\t arrAnalizie:%d, %d, %d\n",size, i, arr[i], arr[i+1] , arr[i+2]);
    if(arr[i] == 0 && (arr [i+1] == 1 || arr[i+1] == 2 || arr[i+1] == 3) && arr[i+2 == 0]){
      printf("ret 0\n");
      return 0;
    }
  }
  printf("ret 1\n");
  return 1;
}

int compareEq(int *arr, int size){
  int go=-1;

  for(;;){
    printf("kcaslkm\n");
  int p = getNext(arr, size);
  removePar(arr, size, p);
  go = checkArr(arr, size);
  if(go){
    for(int i = 0; i < size; i++)
      printf("%d ", arr[i]);
    return 0;
    }
  }
  for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  return 1;
}

int checkBalance(char *e1){
  int *eq = malloc(sizeof(int) * strlen(e1));
  int size = strlen(e1);
  processEq(e1, eq);
  return compareEq(eq, size);
}
