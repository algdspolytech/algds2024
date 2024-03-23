#include <gtest/gtest.h>
extern "C" {
    #include "RB_tree.h"
}


TEST(RedBlackTreeTest, RedBlackPropertyTest) {
    // Создаем красно-черное дерево
    struct Node* root = NULL;

    // Заполним массив случайными значениями
    int N = 1000;
    int randArray[N];
    for(int i = 0; i < N ; i++) {
        randArray[i] = rand();
    }
    
    // Вставляем узлы в дерево,
    for(int i = 0; i < N; i++){
        insertRBTree(&root, randArray[i] );
        ASSERT_TRUE(blackHeight(root) != 0); 
    }
    
    // удаляем узлы в дерево,
    for(int i = 0; i < N - 10; i++){
        DeleteValue(&root, randArray[i] );
        ASSERT_TRUE(blackHeight(root) != 0); 
    }
    
    // Очищаем дерево
    deleteTree(&root);
    
}

