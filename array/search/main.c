#include <stdio.h>
#include "../array.h"
#include "../utils.h"

int main(){
    int arr[10] = {1, 4, 2, 9, 23, 7, 5, 8, 4, 6};

    int val = linearSearch(23, arr, 10);

    printf("%d, %d",val, arr[val]);

}
