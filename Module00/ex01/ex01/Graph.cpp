#include "Graph.hpp"

Graph::Graph(Vector2 points) {
    std::pair<float, float>& firstNode = *points.begin();
    this->sizeGraph.addPoint(firstNode.first, firstNode.second);

    // Implement the fact that if there is more, directly put it in the listPoints ?
}

void   Graph::addVector(Vector2 points) {
    std::vector<std::pair<float, float> >::iterator it = points.begin();

    while (it != points.end()) {
        this->listPoints.addPoint(it->first, it->second);
        it++;
    }
}

void Graph::displayListVector() {
    std::vector<std::pair<float, float> >::iterator itSize= this->sizeGraph.begin();
    std::cout << "Size - X: " << itSize->first << ", Y: " << itSize->second << std::endl;

    std::cout << "All Vectors" << std::endl;
    std::vector<std::pair<float, float> >::iterator itList = this->listPoints.begin();
    while (itList != this->listPoints.end()) {
        std::cout << "X: " << itList->first << ", Y: " << itList->second << std::endl;
        itList++;
    }
}