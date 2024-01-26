#include <iostream>

#include "Vector2.hpp"
#include "Graph.hpp"

int main(void) {
    Vector2 myGraphSize;
    myGraphSize.addPoint(10, 10);

    Graph myGraph(myGraphSize);

    Vector2 pointsList1;
    Vector2 pointsList2;

    pointsList1.addPoint(4,5);
    pointsList1.addPoint(2, 6);
    pointsList1.addPoint(50, 60);
    pointsList1.addPoint(9, 19);
    pointsList1.addPoint(0,0);
    pointsList1.addPoint(0, 19);
    pointsList1.addPoint(9, 0);
    pointsList1.addPoint(1, 0);
    pointsList1.addPoint(2, 0);

    pointsList2.addPoint(5, 1);

    myGraph.addVector(pointsList1);
    myGraph.addVector(pointsList2);
    myGraph.displayGraphInfo();
    myGraph.displayGraphVisual();
}