#include "Vector2.hpp"

void Vector2::addPoint(float x, float y) {
    this->points.push_back(std::pair<float, float>(x, y));
}

    
        