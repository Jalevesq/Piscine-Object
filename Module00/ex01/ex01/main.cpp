#include <iostream>

#include "Vector2.hpp"
#include "Graph.hpp"

int main(void) {
    Vector2 myGraphSize;
    myGraphSize.addPoint(10, 20);

    Graph myGraph(myGraphSize);

    Vector2 pointsList;

    pointsList.addPoint(4,5);
    pointsList.addPoint(2, 6);

    myGraph.addVector(pointsList);
    myGraph.displayListVector();
}