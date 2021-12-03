#ifndef FOO    // To make sure you don't declare the function more than once by including the header multiple times.
#define FOO

#include "../foo.cpp"

void solve_sum(int x, int y, int &ans);

#endif

#ifndef CONVEX    // To make sure you don't declare the function more than once by including the header multiple times.
#define CONVEX
// TODO
#include "../convex_body_chasing.cpp"

#endif


void runTest(int testNum);
void test2D(int testNum);
void test_sum(int testNum);