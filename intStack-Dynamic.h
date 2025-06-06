#ifndef intStack_h
#define intStack_h
#include <stdio.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 8
#define DOUBLING_THRESHOLD 0.9

typedef struct intStack {
    int size; //no of elemnts
    int capacity; //max capacity
    int *data; //pointer to array
} stack;

void initialise(stack *s);

void push(stack *s, int value);

void pop(stack *s);

int top(stack *s);

int isEmpty(stack *s);

int size(stack *s);

void freeStack(stack *s);

#endif
