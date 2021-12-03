#include <vector>
#include <assert.h>

using namespace std;

class Point{
    std::vector <double> coordinates;
    int d;

public:
    Point(std::vector<double>, int);
    int get_dimension(){return d;};
    double get_coordinate(int index){return coordinates[index];};
    std::vector<double> get_coordinates(){return coordinates;};
    
    Point add(Point b){
        assert(d == b.get_dimension());
        int dimension = d;
        std::vector <double> new_coordinates;new_coordinates.clear(); 
        for(int i=0; i<dimension; i++) new_coordinates.push_back(coordinates[i] + b.get_coordinate(i));

        return Point(new_coordinates, dimension);
    }

    Point substract(Point b){
        assert(d == b.get_dimension());
        int dimension = d;
        std::vector <double> new_coordinates;new_coordinates.clear(); 
        for(int i=0; i<dimension; i++) new_coordinates.push_back(coordinates[i] + b.get_coordinate(i));

        return Point(new_coordinates, dimension);
    }
};

Point::Point (std::vector<double> a, int b){
    coordinates = a;
    d = b;
}

bool ccw(Point A, Point B, Point C ){
    return (C.get_coordinate(1)-A.get_coordinate(1)) * (B.get_coordinate(0)-A.get_coordinate(0)) > 
            (B.get_coordinate(1)-A.get_coordinate(1)) * (C.get_coordinate(0)-A.get_coordinate(0));
}


bool intersect(Point A, Point B, Point C, Point D){
    return (ccw(A,C,D) != ccw(B,C,D)) && (ccw(A,B,C) != ccw(A,B,D));
}

class Shape{
    std::vector <Point> points;
    int n;
    int d;
public:
    Shape(std::vector<Point>, int dimension, int N);
    bool check_if_inside(Point a){
        if(d == 2){
            std::vector<double> p; p.clear();p.push_back(1e8);p.push_back(1e8);
            Point infinity = Point(p, 2);
            for(int i=0; i<n; i++){
                if(intersect(a, infinity, points[i], points[(i+1)%n])) return true;
            }
            return false;
        }
        return false;
    }
};

Shape::Shape (std::vector<Point> a, int dimension, int N){
    points = a;
    d = dimension;
    n = N;
}
