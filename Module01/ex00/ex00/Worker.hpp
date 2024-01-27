#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <map>
#include "Shovel.hpp"

class Shovel;

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
        ~Worker();
        void giveNewShovel(Shovel *newShovel);
        void dropShovel();
        void useShovel();
    private:
        Position _coordonnee;
        Statistic _stat;
        Shovel *_shovel;
        static std::map<Shovel*, Worker*> _shovelRegistry;

        bool checkShovel(Shovel* newShovel);
        Worker* searchShovelOwner(Shovel* newShovel);
        void setupNewShovel(Shovel* newShovel);
};


#endif