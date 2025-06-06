#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0
#define INITIAL_CAPACITY 8

typedef struct intStack {
    int size; //no of elements
    int data[INITIAL_CAPACITY]; //fixed array
} stack;

void initialise(stack *s) {
    s->size = 0;
}

void push(stack *s, int value) {
    if (s->size == INITIAL_CAPACITY) {
        printf("Warning: Cannot push, stack is full!\n");
        return;
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
}

int top(stack *s) {
    if (s->size == 0) {
        printf("Warning: Stack empty!\n");
        return INT32_MIN;
    }
    return s->data[s->size - 1];
}

int isEmpty(stack *s) {
    return s->size ? 0 : 1;
}

int size(stack *s) {
    return s->size;
}

void freeStack(stack *s) {
    initialise(s);
}
