#include <stdio.h>
#include "array.h"
#include "item.h"

#define n 10

int main ()
{
    Item array[n];

    inputArray(array, n);

    selectionSortRic(array, n);
    printArray(array, n);

}
