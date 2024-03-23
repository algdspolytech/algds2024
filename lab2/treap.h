#ifndef TREAP_H
#define TREAP_H

#include <stdlib.h>

typedef struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key);                    // Создание нового узла
Node* insert(Node* root, int key);            // Добавление ключа в treap
Node* deleteNode(Node* root, int key);        // Удаление ключа из treap
Node* rotateRight(Node* root);                // Правый поворот вокруг узла
Node* rotateLeft(Node* root);                 // Левый поворот вокруг узла

#endif // TREAP_H
