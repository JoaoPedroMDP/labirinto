#include <stdlib.h>
#include "stack.h"

Stack *mallocStack()
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->size = 0;
    newStack->top = NULL;

    return newStack;
}

void stackNewNode(Stack *stack, Node *newNode)
{
    newNode->under = stack->top;
    stack->top = newNode;
    stack->size++;
}

void removeNode(Stack *stack)
{
    Node *toRemove = stack->top;
    stack->top = stack->top->under;
    stack->size--;

    free(toRemove);
}