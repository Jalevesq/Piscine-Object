#include "Shovel.hpp"

Shovel::Shovel() {
    std::cout << "Shovel constructor Called!" << std::endl;
    this->_numberOfUses = 0;
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor Called!" << std::endl;
}