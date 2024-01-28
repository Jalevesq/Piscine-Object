#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include "Tool.hpp"
# include <map>

# define HAMMER "Hammer"
# define SHOVEL "Shovel"

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
        void dropTool(std::string toolName);
        void useTool(std::string toolName);

        void Update(std::string toolName);
    private:
        Position _coordonnee;
        Statistic _stat;
        std::map<std::string, Tool *> _toolBox;


        std::string checkTool(Tool* newShovel);
};


#endif