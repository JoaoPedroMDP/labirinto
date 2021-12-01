#ifndef NODE_H
#define NODE_H

typedef struct Node Node;

struct Node{
    Node *under;
    int position;
};

Node *createNode(int line, int column);
int extractXFromInteger(int integer);
int extractYFromInteger(int integer);

#endif //NODE_H