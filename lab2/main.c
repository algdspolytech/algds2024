#include <stdio.h>
#include "RB_tree.h"

int main() {
    Node *root = NULL;

    for(int i = 0; i<10; i++){
        insertRBTree(&root, i);
    }
    printf("  %d \n", blackHeight(root));

    
    DeleteValue(&root, 1);
    
    printf("  %d \n", blackHeight(root));
    deleteTree(&root);
    return 0;
}
   
