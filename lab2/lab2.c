#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->priority = rand(); // случайный приоритет
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority) {
            root = rotateRight(root);
        }
    } else if (key > root->key) {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority) {
            root = rotateLeft(root);
        }
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Узел найден
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) { // Нет 
                temp = root;
                root = NULL;
            } else { // Один 
                *root = *temp; 
            }
            free(temp);
        } else {
            // Узел с двумя детьми: получаем преемника
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}
