#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define true 1
#define false 0
#define N 50

int isOpen(char ch) {
    if (ch == '(' || ch == '[' || ch == '{')
        return true;
    return false;
}

int isClosed(char ch){
    if (ch == ')' || ch == ']' || ch == '}')
        return true;
    return false;
}

int isCorresponding(char ch1, char ch2){ 
    if (ch1 == '{' && ch2 == '}')
        return true;
    else if (ch1 == '[' && ch2 == ']')
        return true;
    else if (ch1 == '(' && ch2 == ')')
        return true;
    return false;
}

int isBalanced (char *str) {

    int i, added, removed;
    char temp;

    if (str == NULL)
        return true;

    Stack stack = newStack();

    for (i = 0; i < strlen(str); i++) {
        if (isOpen(str[i]) == true)
            added = push(stack, str[i]);
        else if (isClosed(str[i]) == true) {
            if (isEmptyStack(stack))
                return false;
            else {
                temp = top(stack);
                if (isCorresponding(temp, str[i]) == false)
                    return false;
                removed = pop(stack);
            }  
        }
    }

    if (isEmptyStack(stack))
        return true;
    return false;
}

char *getStringBrackets (char *exp) {
    int i, j,count=1;

	for(i = 0; i < strlen(exp); i++)
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'||exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
			count++;

	char *string = malloc(count * sizeof(char));
	
    for (i = 0, j = 0; i < strlen(exp); i++) {
        if (isOpen(exp[i]) == true || isClosed(exp[i]) == true) {
            string[j] = exp[i];
            j++;
        }
    }

    return string;
}


void main (void) {

    char exp[N];
    char *finalString;
    printf("Inserisci l'espressione: ");
    scanf("%[^\n]", exp);
    finalString = getStringBrackets(exp);
    if (isBalanced(finalString))
        printf("L' espressione e' bilanciata");
    else
        printf("L'espressione non e' bilanciata\n");    

}
