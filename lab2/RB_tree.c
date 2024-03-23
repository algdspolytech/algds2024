#include <stdio.h>
#include <stdlib.h>
#include "RB_tree.h"

Node* ParentR(Node** root, Node* x) {
    if ((*root) == NULL || (*root) == x) {
        return NULL;
    }

    if (((*root)->left != NULL && (*root)->left == x) || ((*root)->right != NULL && (*root)->right == x)) {
        return (*root);
    }

    Node* leftParent = ParentR(&((*root)->left), x);
    if (leftParent != NULL) {
        return leftParent;
    }

    Node* rightParent = ParentR(&((*root)->right), x);
    if (rightParent != NULL) {
        return rightParent;
    }

    return NULL;
}

Node* Parent(Node** root, Node* x) {
    if (*root == NULL || x == NULL) {
        return NULL;
    }

    Node* parent = *root;
    Node* child = (parent->data < x->data) ? parent->right : parent->left;

    while (child != NULL) {
        if (child == x) {
            return parent;
        }

        parent = child;
        child = (parent->data < x->data) ? parent->right : parent->left;
    }

    return ParentR(root, x);
}

void printRBTreeR(Node *root, int level) {
    if (root != NULL) {
        printRBTreeR(root->left, level + 1);
        printf("%d(%s)[%d]   ", root->data, (root->color == RED) ? "RED" : "BLACK", level);
        printRBTreeR(root->right, level + 1);
    }
}

void printRBTree(Node *root) {
   printRBTreeR(root, 0);
}

void deleteTree(struct Node** root) {
    if (*root == NULL) {
        return;
    }

    deleteTree(&(*root)->left);
    deleteTree(&(*root)->right);

    free(*root);
}

int blackHeight(Node* node) {
    if (node == NULL) {
        return 1;
    }

    int leftHeight = blackHeight(node->left);
    int rightHeight = blackHeight(node->right);

    if ((leftHeight == 0 || rightHeight == 0) || leftHeight != rightHeight) {
        return 0;
    }

    if (node->color == BLACK) {
        return leftHeight + 1;
    } else {
        return leftHeight;
    }
}



