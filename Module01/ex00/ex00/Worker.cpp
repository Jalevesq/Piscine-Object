#include "Worker.hpp"



Worker::Worker() {
    this->_coordonnee.x = 0;
    this->_coordonnee.y = 0;
    this->_coordonnee.z = 0;

    this->_stat.exp = 0;
    this->_stat.level = 0;
    this->_shovel = NULL;
}

void Worker::giveNewShovel(Shovel *newShovel) {
    if (this->_shovel) {
        this->_shovel->removeFromWorker();
        this->_shovel = newShovel;
    }
}

void Worker::dropShovel() {
    this->_shovel = NULL;
}