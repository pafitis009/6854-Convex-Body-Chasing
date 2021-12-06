#include "convexchasing.h"

#include <iostream>
#include <vector>
using namespace std;

vector <Point> follow_steiner_point(vector<Shape> v, Point x0){
    vector<Point> points_followed; points_followed.clear();
    points_followed.push_back(x0);
	
    // Main algorithm
    // You are given a list of shapes to chase and you have
    // to return me a list of points that you are going to go through.
    
    int n = v.size();
    points_followed.push_back(x0);
    
	for(int i=0; i<n; i++)
		points_followed.push_back(compute2DPolygonCentroid(v[i].get_points(), n));
    
    return points_followed;
}
