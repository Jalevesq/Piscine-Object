#include "Shovel.hpp"

Shovel::Shovel() : Tool("Shovel")  {
    std::cout << "Shovel constructor Called!" << std::endl;
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor Called!" << std::endl;
}


void Shovel::use() {
    this->incrementToolUses();
    std::cout << "Shovel used. Total uses: " << this->getNumberOfUses() << std::endl;
}