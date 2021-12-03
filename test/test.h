#ifndef CONVEX    // To make sure you don't declare the function more than once by including the header multiple times.
#define CONVEX

#include "../convexchasing.h"

std::vector <Point> follow_steiner_point(std::vector<Shape>, Point x0);
void solve_sum(int x, int y, int &ans);

#endif


void runTest(int testNum);
void test2D_follow_squares(int testNum);
void test_sum(int testNum);