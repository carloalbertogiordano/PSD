#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
	int i = 0;
	Queue q;
	Item a;
	q = newQueue();

	for(i = 0; i < 5; i++){
		printf("\nInsert value : ");
		a = inputItem();
		enqueue(q,a);
		printf("Queue : \t"); printQueue(q);
	}
	for(i = 0; i < 6; i++){
		a = dequeue(q);
		if(a != NULL){
			printf("\nElement deleated : ");
			outputItem(a);
      printf("\tQueue : ");
  		printQueue(q);
		}
    else
      printf("queue in now empty\n" );
	}

}
