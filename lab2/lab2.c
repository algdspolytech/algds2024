#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "lab2.h"

//функция создать новый узел
struct Node* createNode(int key, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->priority = priority;
    node->left = node->right = node->parent = NULL;
    return node;
}

//функция вращает левый узел
void rotateLeft(struct Node** root, struct Node* x) {
    struct Node* y = x->right;

    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->right) x->parent->right = y;
    else x->parent->left = y;

    y->left = x;
    x->parent = y;
}

//функция вращает правый узел
void rotateRight(struct Node** root, struct Node* y) {
    struct Node* x = y->left;

    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;

    x->right = y;
    y->parent = x;
}

//функция добавляет узел для treaps
void insert(struct Node** root, int key, int priority) {
    struct Node* newNode = createNode(key, priority);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Node* temp = *root;
    struct Node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (key < temp->key) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    newNode->parent = parent;
    if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    struct Node** current = root;
    while (newNode->parent != NULL && newNode->priority < newNode->parent->priority) {
        if (newNode->parent->left == newNode) {
            rotateRight(current, newNode->parent);
        }
        else {
            rotateLeft(current, newNode->parent);
        }
        while (*current && (*current)->parent != NULL) {
            current = &((*current)->parent);
        }
    }
}

//сцепления для treaps
void merge(struct Node** T1, struct Node** T2) {
    if (*T1 == NULL) {
        *T1 = *T2;
        return;
    }
    if (*T2 == NULL) return;

    int k = (*T1)->key + (*T2)->key;
    struct Node* dummy = createNode(k / 2, 1000000);

    dummy->left = *T1;
    (*T1)->parent = dummy;
    dummy->right = *T2;
    (*T2)->parent = dummy;

    struct Node** current = &dummy;

    while ((*current)->left != NULL || (*current)->right != NULL) {
        if ((*current)->left == NULL) {
            rotateLeft(current, *current);         
        }
        else if ((*current)->right == NULL) {
            rotateRight(current, *current);
        }
        else {
            if ((*current)->left->priority > (*current)->right->priority) {
                rotateLeft(current, *current);
                if ((*current)->parent == NULL){
                    (*current) = (*current)->left; 
                }              
            }
            else {
                rotateRight(current, *current);
                if ((*current)->parent == NULL){
                    (*current) = (*current)->right; 
                }             
            }
            }
    }

    if ((*current)->parent->left == (*current))
        (*current)->parent->left = NULL; 
    else 
        (*current)->parent->right = NULL;

    if ((*T2)->parent == NULL) *T1 = *T2;
 
    free(dummy);
}

//расцепления для treaps
void splitTreap(struct Node* root, int key, struct Node** T1, struct Node** T2) {
    *T1 = NULL;
    *T2 = NULL;

    struct Node* leftMax = NULL;
    struct Node* rightMin = NULL;

    while (root != NULL) {
        if (key < root->key) {
            if (*T2 == NULL) *T2 = root;
            else rightMin->left = root;

            rightMin = root;
            root = root->left;
            rightMin->left = NULL;
        }
        else {
            if (*T1 == NULL) *T1 = root;
            else leftMax->right = root;

            leftMax = root;
            root = root->right;
            leftMax->right = NULL;
        }
    }

    if (leftMax != NULL) leftMax->right = NULL;
    if (rightMin != NULL) rightMin->left = NULL;
}

//pre-order
void PrintTree(struct Node* t, char* result)
{
    if (t != NULL){   
        char c[100];        
        sprintf(c, "(%d,%d)", t->key, t->priority);
        strcat(result, c);
        
        PrintTree(t->left, result);
        PrintTree(t->right, result);
    }
}
