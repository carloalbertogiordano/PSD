#include <stdio.h>
#include "array.h"


void printArray(Item *a, int n){

    int i;
    for(i = 0; i < n; i++)
        outputItem(a[i]);
    printf("\n");
}


void inputArray(Item *arr, int n){

    int i;
    for(i = 0; i < n; i++)
        arr[i] = inputItem();
    
}

int minimo(Item *a, int n){

    int i, min = 0;
    for(i = 1; i < n; i++)
        if(cmpItem(a[min], a[i])>0)
            min = i;

    return min;
}

/*T(n) = T(n-i)+ bn +d qunindi siamo nel caso 2.a O(T(n)) = Quadratico con n*/

void selectionSortRic(Item *a, int n)
{
    int min;

    if(n == 1)  
        return;

    min = minimo(a, n);
    swap(a, a + min);

    return selectionSortRic(a + 1, n - 1);
}



