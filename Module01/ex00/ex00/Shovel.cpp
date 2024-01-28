#include "Shovel.hpp"

Shovel::Shovel() : Tool("Shovel")  {
    std::cout << "Shovel constructor Called!" << std::endl;
    this->_numberOfUses = 0;
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor Called!" << std::endl;
}


void Shovel::use() {
    this->_numberOfUses++;
    std::cout << "Shovel used. Total uses: " << this->_numberOfUses << std::endl;
}