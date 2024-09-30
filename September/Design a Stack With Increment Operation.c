#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int *inc;
    int top;
    int maxSize;
} CustomStack;

CustomStack* customStackCreate(int maxSize) {
    CustomStack* obj = (CustomStack*)malloc(sizeof(CustomStack));
    obj->stack = (int*)malloc(sizeof(int) * maxSize);
    obj->inc = (int*)calloc(maxSize, sizeof(int)); // Used for lazy increment
    obj->top = -1;
    obj->maxSize = maxSize;
    return obj;
}

void customStackPush(CustomStack* obj, int x) {
    if (obj->top + 1 < obj->maxSize) {
        obj->top++;
        obj->stack[obj->top] = x;
    }
}

int customStackPop(CustomStack* obj) {
    if (obj->top == -1) {
        return -1;
    }
    int res = obj->stack[obj->top] + obj->inc[obj->top];
    if (obj->top > 0) {
        obj->inc[obj->top - 1] += obj->inc[obj->top];
    }
    obj->inc[obj->top] = 0; // Reset increment after applying
    obj->top--;
    return res;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int limit = k < obj->top + 1 ? k - 1 : obj->top;
    if (limit >= 0) {
        obj->inc[limit] += val;
    }
}

void customStackFree(CustomStack* obj) {
    free(obj->stack);
    free(obj->inc);
    free(obj);
}