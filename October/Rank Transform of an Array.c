#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value;
    int index;
};

int compare(const void *a, const void *b) {
    return ((struct Element *)a)->value - ((struct Element *)b)->value;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
    if (arrSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Array to store original elements and their indices
    struct Element* elements = (struct Element*)malloc(arrSize * sizeof(struct Element));
    
    for (int i = 0; i < arrSize; i++) {
        elements[i].value = arr[i];
        elements[i].index = i;
    }
    
    // Sort the elements by their values
    qsort(elements, arrSize, sizeof(struct Element), compare);
    
    // Result array to store ranks
    int* result = (int*)malloc(arrSize * sizeof(int));
    
    // Assign ranks
    int rank = 1;
    result[elements[0].index] = rank;

    for (int i = 1; i < arrSize; i++) {
        if (elements[i].value != elements[i - 1].value) {
            rank++;
        }
        result[elements[i].index] = rank;
    }
    
    // Set the return size and clean up
    *returnSize = arrSize;
    
    free(elements);
    return result;
}