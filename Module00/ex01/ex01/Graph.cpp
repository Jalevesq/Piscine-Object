#include "Graph.hpp"

Graph::Graph(Vector2 points) {
    std::pair<float, float>& firstNode = *points.begin();
    this->sizeGraph.addPoint(firstNode.first, firstNode.second);

}

void   Graph::addVector(Vector2 points) {
    std::vector<std::pair<float, float> >::iterator it = points.begin();

    while (it != points.end()) {
        this->listPoints.addPoint(it->first, it->second);
        it++;
    }
}


// Helper function to print a line with dots and X's for points in the graph
void Graph::printGraphLine(int lineNumber, int fixedSizeX, int fixedSizeY) {
    int lenNbrY = std::to_string(fixedSizeY).size();
    std::string spaceLine(lenNbrY, ' ');
    int lenCurrentNbr = std::to_string(lineNumber).size();

    std::cout << "& " << spaceLine.substr(0, lenNbrY - lenCurrentNbr) << lineNumber << " ";

    std::string lineContents(fixedSizeX * 2, ' '); // Initialize with spaces
    for (int j = 1; j < fixedSizeX * 2; j += 2) {
        if (this->isPointInList(j / 2, lineNumber))
            lineContents[j] = 'X';
        else
            lineContents[j] = '.';
    }

    std::cout << lineContents << std::endl;
}

void Graph::displayGraphVisual() {
    std::vector<std::pair<float, float> >::iterator itSize = sizeGraph.begin();
    int fixedSizeX = itSize->first;
    int fixedSizeY = itSize->second;

    std::cout << "- Display Graph -" << std::endl;

    for (int i = 1; i <= fixedSizeY; i++) {
        this->printGraphLine(fixedSizeY - i, fixedSizeX, fixedSizeY);
    }

    std::string spaceForX(4 + std::to_string(fixedSizeY).size(), ' ');
    std::cout << spaceForX;
    for (int i = 0; i < fixedSizeX; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool Graph::isPointInList(int x, int y) {
    std::vector<std::pair<float, float> >::iterator itPoints = this->listPoints.begin();
    for (; itPoints != this->listPoints.end(); itPoints++) {
        if (itPoints->first == x && itPoints->second == y)
            return true;
    }
    return false;
}

void Graph::displayGraphInfo() {
    std::vector<std::pair<float, float> >::iterator itSize = this->sizeGraph.begin();
    std::cout << "Size - X: " << itSize->first << ", Y: " << itSize->second << std::endl;

    std::cout << "All Vectors" << std::endl;
    std::vector<std::pair<float, float> >::iterator itList = this->listPoints.begin();
    while (itList != this->listPoints.end()) {
        std::cout << "X: " << itList->first << ", Y: " << itList->second << std::endl;
        itList++;
    }
}