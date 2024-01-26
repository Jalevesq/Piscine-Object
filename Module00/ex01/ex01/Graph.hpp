#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vector2.hpp"

class Graph {
    public:
        Graph();
        ~Graph();

        // displayListVector() // display all the points in listVector
        // displayOneVector(float x, float y, bool allList) // display one time x and y without adding it. bool for displaying all the graph with it or nah?
        // addVector(Vector2 points);
    private:
        Vector2 sizeGraph;
        Vector2 listVector;
};

#endif