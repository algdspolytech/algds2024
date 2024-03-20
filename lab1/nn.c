#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* array_to_list(int* array, int size) {
    if (size == 0) {
        return NULL;
    }
    Node* head = create_node(array[0]);
    Node* current = head;
    for (int i = 1; i < size; i++) {
        current->next = create_node(array[i]);
        current = current->next;
    }
    return head;
}

void calculate_sequence(Node* head, Node** start, Node** end) {
    if (head == NULL){
        printf("Sequence is empty\n");
        *start = NULL;
        *end = NULL;
        return;
    }
    int max = 0;
    int n = 1;
    int l = head->data;
    int k;
    *start = head;
    *end = head;
    Node* current = head->next;
    Node* temp_start = head;
    while (current != NULL) {
        k = current->data;
        if (k % l == 0){
            l = k;
            n++;
            if (n > max){
                max = n;
                *start = temp_start;
                *end = current;
            }
        }
        else{
            l = k;
            n = 1;
            temp_start = current;
        }
        current = current->next;
    }
}


//3 теста
int test_sequence1() {
    int sequence[] = {3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7, 6, 12, 24, 48, 12, 2, 4, 1, 1, 1};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result[] = { 6, 12, 24, 48};
    Node* head = array_to_list(sequence, size);
    Node* start;
    Node* end;
    calculate_sequence(head, &start, &end);
    int i = 0;
    while (start != end) {
        if (start->data != wait_result[i]){
            return 0;
        }
        start = start->next;
        i++;
    }
    return 1;
}

int test_sequence2() {
    int sequence[] = {3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7, 6, 12, 24};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result[] = { 6, 12, 24};
    Node* head = array_to_list(sequence, size);
    Node* start;
    Node* end;
    calculate_sequence(head, &start, &end);
    int i = 0;
    while (start != end) {
        if (start->data != wait_result[i]){
            return 0;
        }
        start = start->next;
        i++;
    }
    return 1;
}

int test_sequence3() {
    int sequence[] = {6, 12, 24, 48, 12, 2, 4, 1, 1, 1, 3, 5, 14, 3, 14, 3, 14, 2, 7, 2, 4, 7};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    int wait_result[] = {6, 12, 24, 48};
    Node* head = array_to_list(sequence, size);
    Node* start;
    Node* end;
    calculate_sequence(head, &start, &end);
    int i = 0;
    while (start != end) {
        if (start->data != wait_result[i]){
            return 0;
        }
        start = start->next;
        i++;
    }
    return 1;
}

int main() {
    int test_results[3];
    test_results[0] = test_sequence1();
    test_results[1] = test_sequence2();
    test_results[2] = test_sequence3();
    for (int i = 0; i < 3; i++){
        if (test_results[i]){
            printf(GREEN "Test %d passed\n" RESET, i+1);
        }
        else{
            printf(RED "Test %d failed\n" RESET, i+1);
        }
    }

    return 0; 
}