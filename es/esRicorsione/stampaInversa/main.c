//does not work

#include <stdio.h>

#define size 11


void reverse(int a[], int pos){
  printf("ric\n");
  if(pos < 10){
    reverse(a, ++pos);
    printf("weonfnwocnwfncj\n");
    printf("%s", a[pos]);
  }
}

int main(){
  int a[10];
  int pos = 0;

  for(int i = 0; i < 10; i++){
    scanf("%d", a+i);
  }

  for(int i = 0; i < 10; i++)
    printf("%d", a[i]);

    printf("duiocane\n" );

reverse(a, pos);
}
