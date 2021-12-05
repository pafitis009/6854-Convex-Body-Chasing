// Andi
#include "convexchasing.h"
#include <iostream>
#include <vector>
using namespace std;

vector <Point> follow_steiner_point(vector<Shape> v, Point x0){
    vector<Point> points_followed; points_followed.clear();
	
    // Main algorithm
    // You are given a list of shapes to chase and you have
    // to return me a list of points that you are going to go through.
    
    int n = v.size();
    points_followed.insert(x0);
    
	for(int i = 0;i < n;i++)
		points_followed.insert(Steiner(v[i]));
    
    return points_followed;
}
