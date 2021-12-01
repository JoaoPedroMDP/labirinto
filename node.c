#include <stdlib.h>
#include "node.h"

Node *mallocNode()
{
    Node *newNode = malloc(sizeof(Node));
    newNode->position = 0;
    newNode->under = NULL;

    return newNode;
}

Node *createNode(int line, int column)
{
    Node *newNode = mallocNode();
    newNode->position = line * 100 + column;

    return newNode;
}

int extractXFromInteger(int integer)
{
    return integer / 100;
}

int extractYFromInteger(int integer)
{
    return integer % 100;
}