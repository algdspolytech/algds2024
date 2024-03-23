#include <limits.h>
#include "treap.h"
#include "gtest/gtest.h"

class TreapTest : public ::testing::Test {
protected:
    
};
extern "C" {
    #include "treap.h" 
}

// Тест на создание узла и проверку присвоения ключа
TEST_F(TreapTest, CreateNodeAssignsKeyCorrectly) {
    int key = 10;
    Node* node = createNode(key);
    
    ASSERT_NE(node, nullptr); // Убедиться, что узел успешно создан
    ASSERT_EQ(node->key, key); // Проверка, что ключ корректно присвоен
    
    // Очистка
    free(node);
}

// Тест на проверку генерации случайного приоритета
TEST_F(TreapTest, CreateNodeGeneratesPriority) {
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    
    // Тест может быть ненадежным из-за случайности, но мы предполагаем, что приоритеты будут разными
    ASSERT_NE(node1->priority, node2->priority);
    
    // Очистка
    free(node1);
    free(node2);
}

// Тест на крайние значения ключа
TEST_F(TreapTest, CreateNodeWithExtremeKeyValues) {
    Node* nodeMin = createNode(INT_MIN);
    Node* nodeMax = createNode(INT_MAX);
    
    ASSERT_EQ(nodeMin->key, INT_MIN);
    ASSERT_EQ(nodeMax->key, INT_MAX);
    
    // Очистка
    free(nodeMin);
    free(nodeMax);
}

// Дополнительные тесты могут включать проверку инициализации указателей на поддеревья как nullptr
TEST_F(TreapTest, CreateNodeInitializesChildrenToNull) {
    Node* node = createNode(10);
    
    ASSERT_EQ(node->left, nullptr);
    ASSERT_EQ(node->right, nullptr);
    
    // Очистка
    free(node);
}

// Проверка добавления в пустое дерево
TEST_F(TreapTest, InsertIntoEmptyTree) {
    Node* root = NULL;
    root = insert(root, 10);
    ASSERT_NE(root, nullptr);
    ASSERT_EQ(root->key, 10);

    free(root); // Предполагаем, что есть функция для освобождения памяти
}

// Проверка добавления нескольких уникальных ключей
TEST_F(TreapTest, InsertMultipleUniqueKeys) {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);

    ASSERT_EQ(root->key, 10);
    ASSERT_EQ(root->left->key, 5);
    ASSERT_EQ(root->right->key, 20);

    // Функция освобождения памяти должна также рекурсивно очищать поддеревья
}

// Проверка добавления дубликатов ключей (должно игнорироваться)
TEST_F(TreapTest, InsertDuplicateKeys) {
    Node* root = NULL;
    root = insert(root, 10);
    Node* rootAfterDup = insert(root, 10);

    // Проверка, что дерево не изменилось после попытки вставки дубликата
    ASSERT_EQ(root, rootAfterDup);
}

// Проверка удаления из пустого дерева
TEST_F(TreapTest, DeleteFromEmptyTree) {
    Node* root = NULL;
    root = deleteNode(root, 10);
    ASSERT_EQ(root, nullptr);
}

// Проверка удаления несуществующего ключа
TEST_F(TreapTest, DeleteNonExistentKey) {
    Node* root = insert(NULL, 10);
    Node* rootAfterDelete = deleteNode(root, 20); // Ключа 20 нет в дереве

    ASSERT_NE(rootAfterDelete, nullptr);
    ASSERT_EQ(rootAfterDelete->key, 10);

    // Освобождение памяти
}

// Проверка удаления корня с двумя детьми
TEST_F(TreapTest, DeleteRootWithTwoChildren) {
    Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = deleteNode(root, 20); // Удаление корня

    // Должен выбраться новый корень из детей, но конкретный выбор зависит от приоритетов
}

// Проверка правого поворота
TEST_F(TreapTest, RotateRightBasic) {
    Node* root = createNode(20);
    root->left = createNode(10);

    root = rotateRight(root);
    ASSERT_EQ(root->key, 10);
    ASSERT_EQ(root->right->key, 20);
}
