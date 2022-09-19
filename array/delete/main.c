#include "../utils.h"
#include <stdio.h>
#include "array.h"


int main(){
    int arr[10] = {1, 4, 2, 9, 0, 7, 5, 8, 4, 6};

    //delPos(arr, 5, DIM);
    //printArray(arr, DIM-1);

    int pos = searchElement(5, arr, 10);
    printf("%d", arr[pos]);
}