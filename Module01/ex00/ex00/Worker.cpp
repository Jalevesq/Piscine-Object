#include "Worker.hpp"

std::map<Shovel*, Worker*> Worker::_shovelRegistry;

Worker::~Worker() {
    std::cout << "Destructor of Worker called" << std::endl;
}

Worker::Worker() {
    this->_coordonnee.x = 0;
    this->_coordonnee.y = 0;
    this->_coordonnee.z = 0;

    this->_stat.exp = 0;
    this->_stat.level = 0;
    this->_shovel = NULL;
    std::cout << "New worker incoming!" << std::endl;
}

void Worker::giveNewShovel(Shovel *newShovel) {
    std::cout << "Trying to give a new Shovel to Worker !" << std::endl;
    if (!this->checkShovel(newShovel))
        return;

    Worker* shovelOwner = this->searchShovelOwner(newShovel);
    if (shovelOwner) {
        std::cout << "The shovel is owned by someone else. Taking it from him!" << std::endl;
        shovelOwner->dropShovel();
    }
    this->setupNewShovel(newShovel);
}

bool Worker::checkShovel(Shovel* newShovel) {
    if (!newShovel) {
        std::cout << "Fake shovel given, nothing has been done." << std::endl;
        return false;
    }
    if (newShovel == this->_shovel) {
        std::cout << "Worker already has this shovel." << std::endl;
        return false;
    }
    return true;
}

void Worker::setupNewShovel(Shovel *newShovel) {
    this->dropShovel();
    this->_shovel = newShovel;
    this->_shovelRegistry[newShovel] = this;
    std::cout << "New Shovel given !" << std::endl;
}

Worker* Worker::searchShovelOwner(Shovel *newShovel) {
    std::map<Shovel*, Worker*>::iterator it = this->_shovelRegistry.find(newShovel);
    if (it != this->_shovelRegistry.end())
        return it->second;
    return NULL;
}

void Worker::useShovel() {
    if (!this->_shovel) {
        std::cout << "The worker has no Shovel." << std::endl;
    } else {
        this->_shovel->use();
    }
}

void Worker::dropShovel() {
    if (this->_shovel) {
        std::cout << "A worker is droping a Shovel." << std::endl;
        this->_shovelRegistry.erase(this->_shovel);
        this->_shovel = NULL;
    }
}