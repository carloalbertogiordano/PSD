#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myLib/stack.h"
#include "myLib/item.h"

#define N 50

void reverseString (char *string, Stack s) {

    int i;


    for (i = 0; i < strlen(string); i++) {
        push(s, string[i]);
    }


}

Stack printReverseString(Stack s, int *size) {
    if (!isEmptyStack(s)) {
        printf("%c", top(s));
        pop(s);
        (*size)++;
        return printReverseString(s, size);
    }
    printf(" %d", *size);
}

void main (void) {

    char string[N];
    int size = 0;
    int *i = 0;
    Stack s = newStack();
    printf("Inserisci la stringa: ");
    scanf("%s", string);
    reverseString(string, s);
    printReverseString(s, &size);
    

}