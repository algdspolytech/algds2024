#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"

int sequence(char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("File not found\n");
        return -1;
    }
    int max = 0;
    int n = 1;
    int k = 0;
    int l = 0;

    if (fscanf(file, "%d", &l) == EOF){
        printf("File is empty\n");
        return -2;
    }
    while(fscanf(file, "%d", &k) != EOF){
        if (k % l == 0){
            l = k;
            n++;
            max = (n > max)? n : max;
        }
        else{
            l = k;
            max = (n > max)? n : max;
            n = 1;
        }
    }
    return max;
}

void test_sequence(char *filename, int expected_result) {
    int result = sequence(filename);
    if (result == expected_result) {
        printf(GREEN "Test passed" RESET " for file %s\n" , filename);
    } else {
        printf(RED "Test failed" RESET " for file %s: expected %d, got %d\n" , filename, expected_result, result);
    }
}

int main() {
    test_sequence("tests/test1.txt", 4);
    test_sequence("tests/test2.txt", 3);
    test_sequence("tests/test3.txt", 4);
    test_sequence("tests/empty.txt", -2);
    test_sequence("tests/nonexistent.txt", -1);

    return 0;
}
