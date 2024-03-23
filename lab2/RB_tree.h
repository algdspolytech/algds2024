#ifndef RBTREE_H
#define RBTREE_H

#include <stdio.h>
#include <stdlib.h>

#define ALL_BLACK(s) (((s)->left == NULL && (s)->right == NULL) || \
                            ((s)->left != NULL && (s)->left->color == BLACK && \
                            (s)->right != NULL && (s)->right->color == BLACK))


typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right;
} Node;

Node *createNode(int data);
Node *Parent(Node** root, Node* x);
void printRBTree(Node *root);

void insertRBTree(Node **root, int data);

void DeleteValue(Node** root, const int data) ;

void rightRotate(Node **root, Node *y) ;
void leftRotate(Node **root, Node *x);
void deleteTree(struct Node** root);

int blackHeight(Node* node);

#endif /* RBTREE_H */
