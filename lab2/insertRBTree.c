#include <stdio.h>
#include <stdlib.h>
#include "RB_tree.h"

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void fixViolation(Node **root, Node *z) {
    while (z->data != (*root)->data && Parent(&(*root), z)->color == RED) {
        if (Parent(&(*root), z) == Parent(&(*root), Parent(&(*root), z))->left) {
            Node *y = Parent(&(*root), Parent(&(*root), z))->right;
            if (y != NULL && y->color == RED) {
                Parent(&(*root), z)->color = BLACK;
                y->color = BLACK;
                Parent(&(*root), Parent(&(*root), z))->color = RED;
                z = Parent(&(*root), Parent(&(*root), z));
            } else {
                if (z == Parent(&(*root), z)->right) {
                    z = Parent(&(*root), z);
                    leftRotate(&(*root), z);
                }
                Parent(&(*root), z)->color = BLACK;
                Parent(&(*root), Parent(&(*root), z))->color = RED;
                rightRotate(&(*root), Parent(&(*root), Parent(&(*root), z)));
            }
        } else {
            Node *y = Parent(&(*root), Parent(&(*root), z))->left;
            if (y != NULL && y->color == RED) {
                Parent(&(*root), z)->color = BLACK;
                y->color = BLACK;
                Parent(&(*root), Parent(&(*root), z))->color = RED;
                z = Parent(&(*root), Parent(&(*root), z));
            } else {
                if (z == Parent(&(*root), z)->left) {
                    z = Parent(&(*root), z);
                    rightRotate(&(*root), z);
                }
                Parent(&(*root), z)->color = BLACK;
                Parent(&(*root), Parent(&(*root), z))->color = RED;
                leftRotate(&(*root), Parent(&(*root), Parent(&(*root), z)));
            }
        }
    }
    (*root)->color = BLACK;
}

void insertRBTree(Node **root, int data) {
    Node *newNode = createNode(data);
    Node *parent = NULL;
    Node *current = *root;
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else
            return;
    }
    if (parent == NULL)
        *root = newNode;
    else if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    fixViolation(&(*root), newNode);
}

