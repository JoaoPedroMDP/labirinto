#ifndef STACK_H
#define STACK_H
#include "node.h"

typedef struct Stack Stack;
struct Stack{
    Node *top;
    int size;
};

Stack *mallocStack();
void stackNewNode(Stack *stack, Node *newNode);
void removeNode(Stack *stack);

#endif //STACK_H
