#include <stdio.h>
#include "item.h"
#include "stack.h"
int main(void) {
	Stack s;
	Item a;
	s = newStack();

	for(int i = 0; i < 5; i++) {
		printf("\nInserisci valore : ");
		a = inputItem();
		push(s,a);
		printStack(s);
	}

	while (1){
		a = top(s);
    if(a == NULL) break;
		printf("\nElemento eliminato : ");
		outputItem(a);
		pop(s);
		printf("\nStack : ");
		printStack(s);
	}

}
