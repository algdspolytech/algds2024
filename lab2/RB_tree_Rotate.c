#include <stdio.h>
#include <stdlib.h>
#include "RB_tree.h"


void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (Parent(&(*root), x) == NULL)
        *root = y;
    else if (x == Parent(&(*root), x)->left)
        Parent(&(*root), x)->left = y;
    else
        Parent(&(*root), x)->right = y;
    y->left = x;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    if (Parent(&(*root), y) == NULL)
        *root = x;
    else if (y == Parent(&(*root), y)->left)
        Parent(&(*root), y)->left = x;
    else
        Parent(&(*root), y)->right = x;
    x->right = y;
}
