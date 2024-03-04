#ifndef GOOGLETEST_SAMPLES_LAB2_H_
#define GOOGLETEST_SAMPLES_LAB2_H_

//структура узлов в дереве
struct Node {
    int key;                  //ключа   
    int priority;             //приоритет
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* createNode(int key, int priority);
void rotateLeft(struct Node** root, struct Node* x);
void rotateRight(struct Node** root, struct Node* y);
void insert(struct Node** root, int key, int priority);
void merge(struct Node** T1, struct Node** T2);
void splitTreap(struct Node* root, int key, struct Node** T1, struct Node** T2);
void PrintTree(struct Node* t, char* result);

#endif