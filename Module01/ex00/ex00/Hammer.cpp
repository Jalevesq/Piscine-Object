#include "Hammer.hpp"


Hammer::Hammer() : Tool("Hammer")  {
    std::cout << "Hammer constructor Called!" << std::endl;
}

Hammer::~Hammer() {
    std::cout << "Hammer destructor Called!" << std::endl;
}


void Hammer::use() {
    this->incrementToolUses();
    std::cout << "Hammer used. Total uses: " << this->getNumberOfUses() << std::endl;
}