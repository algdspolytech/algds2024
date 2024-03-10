#include <stdio.h>
#include "HelpFunc.h"

int main() {

    char name[20] = "TestName.txt";

    int res = FindCountMax(name);

    printf("Your CountMax is %d", res);

    return 0;

}