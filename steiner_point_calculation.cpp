// Binwei
#include "convexchasing.h"
#include <iostream>
#include <cmath>


Point compute2DPolygonCentroid(std::vector<Point> vertices, int vertexCount)
{
    std::vector<double> aa;
    aa.push_back(0);aa.push_back(0);

    Point centroid = Point(aa,2);


    double signedArea = 0.0;
    double x0 = 0.0; // Current vertex X
    double y0 = 0.0; // Current vertex Y
    double x1 = 0.0; // Next vertex X
    double y1 = 0.0; // Next vertex Y
    double a = 0.0;  // Partial signed area

    // For all vertices except last
    int i=0;
    for (i=0; i<vertexCount-1; ++i)
    {
        x0 = vertices[i].get_coordinate(0);
        y0 = vertices[i].get_coordinate(1);
        x1 = vertices[i+1].get_coordinate(0);
        y1 = vertices[i+1].get_coordinate(1);
        a = x0*y1 - x1*y0;
        signedArea += a;
        centroid.update(0,centroid.get_coordinate(0)+(x0 + x1)*a);
        centroid.update(1,centroid.get_coordinate(1)+(y0 + y1)*a);
    }

    // Do last vertex separately to avoid performing an expensive
    // modulus operation in each iteration.
    x0 = vertices[i].get_coordinate(0);
    y0 = vertices[i].get_coordinate(1);
    x1 = vertices[0].get_coordinate(0);
    y1 = vertices[0].get_coordinate(1);
    a = x0*y1 - x1*y0;
    signedArea += a;
    centroid.update(0,centroid.get_coordinate(0)+(x0 + x1)*a);
    centroid.update(1,centroid.get_coordinate(1)+(y0 + y1)*a);

    signedArea *= 0.5;
    centroid.update(0,centroid.get_coordinate(0)/ (6.0*signedArea));
    centroid.update(01,centroid.get_coordinate(1)/ (6.0*signedArea));

    return centroid;
}

Point compute2DPolygonSteiner (std::vector<Point> vertices, int vertexCount){
    

    std::vector<double> aa;
    aa.push_back(0);aa.push_back(0);

        Point steiner = Point(aa,2);

    double x0 = 0.0; // Current vertex X
    double y0 = 0.0; // Current vertex Y
    double x1 = 0.0; // Next vertex X
    double y1 = 0.0; // Next vertex Y
    double angle=(3.14159)*(vertexCount-2);
    std::vector<Point> edge;
    std::vector<double> v;

    int i=0;
    for (i=0; i<vertexCount-1; ++i)
    {
        x0 = vertices[i].get_coordinate(0);
        y0 = vertices[i].get_coordinate(1);
        x1 = vertices[i+1].get_coordinate(0);
        y1 = vertices[i+1].get_coordinate(1);

        v.push_back(x1-x0);v.push_back(y1-y0);

        edge.push_back(Point(v,2));
    }

    x0 = vertices[i].get_coordinate(0);
    y0 = vertices[i].get_coordinate(1);
    x1 = vertices[0].get_coordinate(0);
    y1 = vertices[0].get_coordinate(1);

    v.push_back(x1-x0);v.push_back(y1-y0);

    edge.push_back(Point(v,2));

    for (i=0; i<vertexCount-1; ++i)
    {

        x0 = edge[i].get_coordinate(0);
        y0 = edge[i].get_coordinate(1);
        x1 = edge[i+1].get_coordinate(0);
        y1 = edge[i+1].get_coordinate(1);


        double cos= x0*x1+y0*y1;
        double the= acos(cos);

        steiner.update(0,steiner.get_coordinate(0)+the/angle*vertices[i+1].get_coordinate(0));
        steiner.update(1,steiner.get_coordinate(1)+the/angle*vertices[i+1].get_coordinate(1));
    }
        x0 = edge[i].get_coordinate(0);
        y0 = edge[i].get_coordinate(1);
        x1 = edge[0].get_coordinate(0);
        y1 = edge[0].get_coordinate(1);


        double cos= x0*x1+y0*y1;
        double the= acos(cos);

        steiner.update(0,steiner.get_coordinate(0)+the/angle*vertices[0].get_coordinate(0));
        steiner.update(1,steiner.get_coordinate(1)+the/angle*vertices[0].get_coordinate(1));

    return vertices[0];
}

Point Steiner(Shape s){

    return compute2DPolygonSteiner(s.get_points(),(s.get_points()).size());
}

Point Centroid(Shape s){

    return compute2DPolygonCentroid(s.get_points(),(s.get_points()).size());
}