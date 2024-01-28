#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include "Tool.hpp"

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
        void giveNewTool(Tool *newShovel);
        void dropTool();
        void useTool();

        void Update();
    private:
        Position _coordonnee;
        Statistic _stat;
        Tool *_tool;


        bool checkTool(Tool* newShovel);
};


#endif