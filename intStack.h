#ifndef intStack_h
#define intStack_h
#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define INITIAL_CAPACITY 8

typedef struct intStack {
    int size;            //no of elements
    int data[INITIAL_CAPACITY];  //fixed array
} stack;

void initialise(stack *s);

void push(stack *s, int value);

void pop(stack *s);

int top(stack *s);

int isEmpty(stack *s);

int size(stack *s);

void freeStack(stack *s);

#endif