#include <stdio.h>
#include <stdlib.h>

void lexicographicalOrder(int n, int current, int* result, int* index) {
    if (current > n) return;
    
    result[(*index)++] = current;

    for (int i = 0; i <= 9; i++) {
        if (current * 10 + i > n) break;
        lexicographicalOrder(n, current * 10 + i, result, index);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    *returnSize = n;
    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;
    
    for (int i = 1; i <= 9; i++) {
        if (i > n) break;
        lexicographicalOrder(n, i, result, &index);
    }

    return result;
}