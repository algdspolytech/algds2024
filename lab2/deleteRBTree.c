#include <stdio.h>
#include <stdlib.h>
#include "RB_tree.h"

Node* MinValueNode(Node* node) {
    Node* pointer = node;

    while(pointer->left != NULL) {
        pointer = pointer->left;
    }

    return pointer;
}
int DeleteCase1(Node** root, Node** node) {
    if (*node == NULL) {
        return 1;
    }

    if (*node == *root) {
        if ((*node)->left == NULL && (*node)->right == NULL) {
            free(*root);
            *root = NULL;
            return 1;
        }
        Node* current = *root;
        *root = (*root)->left != NULL ? (*root)->left : (*root)->right;
        (*root)->color = BLACK;
        free(current);
        return 1;
    }

    return 0;
}

void DeleteCase2(Node** root, Node** node) {
    Node* child = (*node)->left != NULL ? (*node)->left : (*node)->right;

    if (*node == Parent(&(*root),  *node)->left) {
        Parent(&(*root),  *node)->left = child;
        if (child != NULL)
            child->color = BLACK;
        free(*node);
    } else if (*node == Parent(&(*root),  *node)->right) {
        Parent(&(*root),  *node)->right = child;
        if (child != NULL)
            child->color = BLACK;
        free(*node);
    }
}

int DeleteCase3(Node** root, Node** pointer) {
    Node* brother = Parent(&(*root), *pointer)->right;
    if (brother != NULL && brother->color == RED) {
        Parent(&(*root), *pointer)->color = RED;
        brother->color = BLACK ;
        leftRotate(root, Parent(&(*root), *pointer));
        brother = Parent(&(*root), *pointer)->right;
    }
    if(ALL_BLACK(brother)){
        if(Parent(&(*root), *pointer) == *root){
            brother->color = RED;
            return 1;
        }else if (Parent(&(*root), *pointer)->color == RED){
            brother->color = RED;
            Parent(&(*root), *pointer)->color = BLACK;
            return 1;
        }else if (Parent(&(*root), *pointer)->color == BLACK){
            brother->color = RED;
            *pointer = Parent(&(*root), *pointer);  
            return 0;
        }

    }else {
        if (brother != NULL && (brother->right == NULL || brother->right->color == BLACK)){
            brother->color = RED;
            brother->left->color = BLACK;
            rightRotate(root, brother);
            brother = Parent(&(*root), *pointer)->right;
        }
        if(brother != NULL ){
            brother->color = Parent(&(*root), *pointer)->color;
            brother->right->color = BLACK;  
        }

        Parent(&(*root), *pointer)-> color = BLACK; 
        leftRotate(root, Parent(&(*root), *pointer)); 
        return 1;
    }
    return 0;
}

int DeleteCase4(Node** root, Node** pointer) {
    Node* brother = Parent(&(*root), *pointer)->left;
    if (brother != NULL && brother->color == RED) {
        Parent(&(*root), *pointer)->color = RED;
        brother->color = BLACK ;
        rightRotate(root, Parent(&(*root), *pointer));
        brother = Parent(&(*root), *pointer)->left;
    }
    if(ALL_BLACK(brother)){
         if(Parent(&(*root), *pointer) == *root){
            brother->color = RED;
            return 1;
        }else if (Parent(&(*root), *pointer)->color == RED){
            brother->color = RED;
            Parent(&(*root), *pointer)->color = BLACK;
            return 1;
        }else if (Parent(&(*root), *pointer)->color == BLACK){
            brother->color = RED;
            *pointer = Parent(&(*root), *pointer);  
            return 0;
        }
    }else {
        if (brother != NULL && (brother->left == NULL || brother->left->color == BLACK)){
            brother->color = RED;
            brother->right->color = BLACK;
            leftRotate(root, brother);
            brother = Parent(&(*root), *pointer)->left;
        }
        if(brother != NULL ){
            brother->color = Parent(&(*root), *pointer)->color;
            brother->left->color = BLACK;  
        }

        Parent(&(*root), *pointer)->color = BLACK; 
        rightRotate(root, Parent(&(*root), *pointer)); 
        return 1;
    }
}

void FixDeleteRBTree(Node** root, Node** node) {
    //node == root || node == NULL.
    if(DeleteCase1(root, node) == 1) {
        return;
    }

    if ((*node)->color == RED || ((*node)->left != NULL && (*node)->left->color == RED) || ((*node)->right != NULL && (*node)->right->color == RED)) {
        DeleteCase2(root, node);
    //} else if((*node)->color != RED && ((*node)->left != NULL && (*node)->left->color != RED) && ((*node)->right != NULL && (*node)->right->color != RED)) {
    } else{   
        Node* pointer = *node;
        while(pointer != *root && pointer->color == BLACK) {
            if(pointer == Parent(&(*root), pointer)->left) {
                if(DeleteCase3(root, &pointer) == 1) {
                    break;
                }
            } else  {
                if(DeleteCase4(root, &pointer) == 1) {
                    break;
                }
            }
        }

        if(*node == Parent(&(*root),  *node)->left) {
            Parent(&(*root),  *node)->left = NULL;
        } else if(*node == Parent(&(*root),  *node)->right) {
            Parent(&(*root),  *node)->right = NULL;
        }
        free(*node);
        (*root)->color = BLACK;
    }
}

Node* DeleteNode(Node** root, const int data) {
    if(*root == NULL) {
        return *root;
    }

    if(data < (*root)->data) {
        return DeleteNode(&(*root)->left, data);
    }

    if(data > (*root)->data) {
        return DeleteNode(&(*root)->right, data);
    }

    if((*root)->left == NULL || (*root)->right == NULL) {
        return *root;
    }

    Node* temp = MinValueNode((*root)->right);
    (*root)->data = temp->data;
    return DeleteNode(&(*root)->right, temp->data);
}

void DeleteValue(Node** root, const int data) {
    Node* node = DeleteNode(root, data);
    FixDeleteRBTree(root, &node);
}
