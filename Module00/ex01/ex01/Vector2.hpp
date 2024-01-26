#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>
#include <vector>
#include <utility> // for std::pair

class Vector2 {
    public:
        void addPoint(float x, float y);

        std::vector<std::pair<float, float> >::iterator begin() {
            return points.begin();
        }

        std::vector<std::pair<float, float> >::iterator end() {
            return points.end();
        }

    private:
        std::vector<std::pair<float, float> > points;
};
#endif