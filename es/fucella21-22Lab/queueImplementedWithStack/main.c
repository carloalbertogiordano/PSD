#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main (void){

  Queue q = newQueue();

  for(int i = 0; i < 5; i++){
    printf("insert a number\n");
    Item a = inputItem();
    enqueue(q, a);
  }

  printf("This is the queue\n");
  printQueue(q);

  printf("Removing items from queue...\n");

  while (!isEmptyQueue(q)) {
    Item a = dequeue(q);
    outputItem(a);
    printf(" ");
  }

    return 0;

  free(q);
}
