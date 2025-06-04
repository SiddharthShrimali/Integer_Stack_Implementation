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

void initialise(stack *head) {
    head->size=0;
    head->firstNode=NULL;
}

void push(stack *head, int value) {
    node *temp;
    temp = (node *) malloc(sizeof(node));
    temp->data = value;
    temp->next = head->firstNode;
    head->firstNode = temp;
    head->size++;
}

void pop(stack *head) {
    if (head->size == 0) {
        printf("Warning: Trying to pop from an empty stack!\n");
        return;
    }
    node *temp;
    temp = head->firstNode;
    head->firstNode = head->firstNode->next;
    free(temp);
    head->size--;
}

int top(stack *head) {
    if (head->size == 0) {
        printf("Warning: Stack empty!\n");
        return INT32_MIN;
    }
    return head->firstNode->data;
}

int isEmpty(stack *head) {
    return head->size ? 0 : 1;
}

int size(stack *head) {
    return head->size;
}

void freeStack(stack *head) {
    for(int i = head->size; i > 0; i--) {
        pop(head);
    }
}