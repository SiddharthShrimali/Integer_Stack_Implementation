#ifndef intStack_ll_h
#define intStack_ll_h
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next; 
} node;

typedef struct Stack {
    int size; //number of nodes
    node *firstNode; //first node
} stack;

void initialise(stack *head);

void push(stack *head, int value);

void pop(stack *head);

int top(stack *head);

int isEmpty(stack *head);

int size(stack *head);

void freeStack(stack *head);

#endif