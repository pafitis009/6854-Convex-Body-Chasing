#include "test.h"

#include <math.h>
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
        case test_type_e::TEST_2D: test2D_follow_squares(testNum); break;
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


double get_sum_of_path(vector<Point> path){
    //TODO
    return -1;
}

void test2D_follow_squares(int testNum) {
    vector<Shape> bodies; bodies.clear();
    Shape first = Shape(2);

    vector <double> aL, bL, cL, dL;aL.clear();bL.clear();cL.clear();dL.clear();
    aL.push_back(0);aL.push_back(0);
    bL.push_back(0);bL.push_back(1024);
    cL.push_back(1024);cL.push_back(0);
    dL.push_back(1024);dL.push_back(1024);
    Point a = Point(aL, 2);
    Point b = Point(bL, 2);
    Point c = Point(cL, 2);
    Point d = Point(dL, 2);
    
    first.insert(a);first.insert(a);first.insert(a);first.insert(a);

    bodies.push_back(first);
    
    for(int i=1; i<10; i++){
        Shape prev = bodies[i-1];
        Shape new_shape = Shape(2);

        for(int i=0; i<prev.get_n(); i++){
            Point cur = prev.get_point(i);

            if(i % 2 == 0) cur.update(0, cur.get_coordinate(0) / 2);
            if(i % 2 == 1) cur.update(1, cur.get_coordinate(1) / 2);
            new_shape.insert(cur);
        }

        bodies.push_back(new_shape);
    }
    std::vector<double> start; start.clear();start.push_back(1024);start.push_back(1024);
    Point x0 = Point(start, 2);

    double OPT = 1023 * sqrt(2);

    std::vector<Point> path = follow_steiner_point(bodies, x0);
    double ans = get_sum_of_path(path);

    double comp_ratio = ans / OPT;

    printf("Competitive ratio: %f", comp_ratio);


    printf("Test [%s] ran succesfully!\n", getTestname(test_type_e::All[testNum]));
}
