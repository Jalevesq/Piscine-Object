#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include "Shovel.hpp"

struct Position {
    int x;
    int y;
    int z;
};

struct Statistic {
    int level;
    int exp;
};


class Worker {
    public:
        Worker();
        void giveNewShovel(Shovel *newShovel);
        void dropShovel();

    private:
        Position _coordonnee;
        Statistic _stat;
        Shovel *_shovel;
};


#endif