#include "test.h"

#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <iostream>

// REGEX TESING:
// In order to add a test case do the following:
// 1) Add the name of the test case in the enum (put it last)
// 2) Add the correspondig entry in the All array and update N
// 3) Add a line in initTestNames as the previous entries
// 4) Add a line in the sqitch in thw runTest
// 5) Make the test!

namespace test_type_e{
    enum Type{
        TEST_SUM,
        TEST_2D,
    };
    static const Type All[] = {TEST_SUM, TEST_2D};
    static const int N = 2;
}


const char *testNames[test_type_e::N];

void initTestnames() {
    testNames[test_type_e::TEST_2D] = "Test2D";
    testNames[test_type_e::TEST_SUM] = "TestSum";
}

const char * getTestname(test_type_e::Type type) {
    return * (testNames + type);
}

int main(int argc, char *argv[]) {
    initTestnames();

    for (int i=0; i<test_type_e::N; i++)    runTest(i);
    return 0;
}

void runTest(int testNum) {
    printf("Running test [%s]\n", getTestname(test_type_e::All[testNum]));
    switch (testNum) {
        case test_type_e::TEST_SUM: test_sum(testNum); break;
        case test_type_e::TEST_2D: test2D(testNum); break;
        default:
            fprintf(stderr, "Please enter valid test number: %d\n", testNum);
            return;
    }
}

void test_sum(int testNum) {
    int x = rand() % 10;
    int y = rand() % 20;
    int ans = -1; 

    solve_sum(x, y, ans);
    assert (ans == x + y);
    
    printf("Test [%s] ran succesfully!\n", getTestname(test_type_e::All[testNum]));
}


void test2D(int testNum) {
    assert(1 == 1);
    printf("Test [%s] ran succesfully!\n", getTestname(test_type_e::All[testNum]));
}
