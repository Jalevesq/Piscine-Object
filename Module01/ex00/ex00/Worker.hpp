#ifndef WORKER_HPP
# define WORKER_HPP

# include <iostream>
# include "Tool.hpp"
# include "Workshop.hpp"
# include <set>

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
        void giveNewTool(Tool *newTool);
        void dropTool(const std::string& toolName);
        void useTool(const std::string& toolName);
        Tool* returnTool(const std::string& toolName);
        // Create a method that return it's tool.
        virtual void Update(void* update, const std::string& typeID);
    private:
        Position _coordonnee;
        Statistic _stat;
        std::set<Tool *> _toolBox;

        std::string checkTool(Tool* newShovel);
        std::set<Tool *>::iterator findTool(const std::string& toolName);
};


#endif