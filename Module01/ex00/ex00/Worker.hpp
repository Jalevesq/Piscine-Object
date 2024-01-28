#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include "Shovel.hpp"
#include "IObserver.hpp"

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

class Worker : public IObserver {
    public:
        Worker();
        ~Worker();
        void giveNewShovel(Shovel *newShovel);
        void dropShovel();
        void useShovel();

        void Update() {
            this->dropShovel();
        }

    private:
        Position _coordonnee;
        Statistic _stat;
        Shovel *_shovel;


        bool checkShovel(Shovel* newShovel);
};


#endif