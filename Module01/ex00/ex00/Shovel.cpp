#include "Shovel.hpp"

Shovel::Shovel() : _list_observer() {
    std::cout << "Shovel constructor Called!" << std::endl;
    this->currentWorker = NULL;
    this->_numberOfUses = 0;
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor Called!" << std::endl;
    this->Notify();
}