#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8
#define DOUBLING_THRESHOLD 0.9

typedef struct intStack {
    int size; //no of elemnts
    int capacity; //max capacity
    int *data; //pointer to array
} stack;

void initialise(stack *s) {
    s->capacity = INITIAL_CAPACITY;
    s->size = 0;
    s->data = (int *)calloc(INITIAL_CAPACITY, sizeof(int));
}

void push(stack *s, int value) {
    if (s->size >= (DOUBLING_THRESHOLD * s->capacity)) {
        int *tempMemory = realloc(s->data, 2 * s->capacity * sizeof(int));
        s->data = tempMemory;
        s->capacity *= 2;
    }
    s->data[s->size] = value;
    s->size++;
}

void pop(stack *s) {
    if (s->size == 0) {
        printf("Warning: Stack empty!\n");
        return;
    }
    s->size--;
    if  (s->size < (0.5 * s->capacity) && (s->capacity * 0.5) >= INITIAL_CAPACITY) {
        int *tempMemory = (int *)realloc(s->data, s->capacity/2 * sizeof(int));
        s->data = tempMemory;
        s->capacity /= 2;
    }
}

int top(stack *s) {
    if(s->size == 0) {
        printf("Warning: Stack empty! \n");
        return INT32_MIN;
    }
    return s->data[s->size-1];
}

int isEmpty(stack *s) {
    return s->size ? 0 : 1;
}

int size(stack *s) {
    return s->size;
}

void freeStack(stack *s) {
    free(s->data);
    s->data = NULL;
    initialise(s);
}