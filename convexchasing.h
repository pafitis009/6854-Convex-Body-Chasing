#include <assert.h>
#include <vector>

using namespace std;

class Point{
    std::vector <double> coordinates;
    int d;

public:
    Point(std::vector<double> a, int b){
        coordinates = a;
        d = b;
    };
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

    void update(int index, double new_coordinate){
        assert(index < d);

        coordinates[index] = new_coordinate;
    }
};



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
    Shape (int dimension){
        vector<Point> e; e.clear();
        points = e;
        d = dimension;
        n = 0;
    }

    void insert(Point a){
        assert(a.get_dimension() == d);
        points.push_back(a);
        n++;
    }

    Point get_point(int index){
        assert (index < n);
        return points[index];
    }

    std::vector<Point> get_points(){
        return points;
    }

    int get_n(){
        return n;
    }

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


vector <Point> follow_steiner_point(vector<Shape> v, Point x0);
Point compute2DPolygonCentroid(std::vector<Point> vertices, int vertexCount);
void solve_sum(int x, int y, int &ans);
