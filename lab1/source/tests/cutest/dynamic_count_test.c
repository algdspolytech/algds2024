#include <stdio.h>

#include "dynamic_count_test.h"
#include "CuTest.h"

#include "../../dynamic_count.h"
#include "../../trivial.h"

void countNumbersTest(CuTest* tc, int n, int k, int expected) {
    printf_s("Starting for n = %i, k = %i ...\n", n, k);
    int actual = countNumbers(n, k);

    CuAssertIntEquals(tc, expected, actual);
}

void countNumbers_n0k0_0Returned(CuTest* tc) {
    countNumbersTest(tc, 0, 0, 0);
}


void countNumbers_n7k1_7Returned(CuTest* tc) {
    countNumbersTest(tc, 7, 1, 7);
}


void countNumbers_n1k7_1Returned(CuTest* tc) {
    countNumbersTest(tc, 1, 7, 1);
}


void countNumbers_small_n_k(CuTest* tc) {
    for (int n = 1; n < 8; n++) {
        for (int k = 1; k < 8; k++) {
            countNumbersTest(tc, n, k, countNumberViaEnum(n, k));
        }
    }
}


CuSuite* getTestSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, countNumbers_n0k0_0Returned);
    SUITE_ADD_TEST(suite, countNumbers_n7k1_7Returned);
    SUITE_ADD_TEST(suite, countNumbers_n1k7_1Returned);
    SUITE_ADD_TEST(suite, countNumbers_small_n_k);
    return suite;
}

void runAllTests() {
    CuString* output = CuStringNew();
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, getTestSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf_s("%s\n", output->buffer);
}
