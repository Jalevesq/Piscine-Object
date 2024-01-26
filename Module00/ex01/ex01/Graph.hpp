#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"
#include <vector>
#include <iostream>

class Graph {
    public:
        Graph(Vector2 points);

        void displayGraphInfo();
        void displayGraphVisual(); // display all the points in listVector
        // displayOneVector(Vector2, bool allList) // display one time x and y without adding it. bool for displaying all the graph with it or nah?
        void    addVector(Vector2 points);
    private:
        bool isPointInList(int x, int y);
        void printGraphLine(int lineNumber, int fixedSizeX, int fixedSizeY);
        Vector2 sizeGraph;
        Vector2 listPoints;
};

#endif