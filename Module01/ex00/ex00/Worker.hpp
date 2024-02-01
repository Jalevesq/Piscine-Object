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
        

        template <typename ToolType>
        ToolType* GetTool()  {
            std::set<Tool *>::iterator it = this->_toolBox.begin();
            while (it != this->_toolBox.end()) {
            ToolType* castedTool = dynamic_cast<ToolType*>(*it);
                if (castedTool) {
                    return castedTool;
                }
            }
            return NULL;
        }
        Tool* returnTool(const std::string& toolName);
        virtual void Update(void* update, const std::string& typeID);
        // void joinWorkshop(Workshop* workshop);
        // void leaveWorkshop(Workshop* workshop);
    private:
        Position _coordonnee;
        Statistic _stat;
        std::set<Tool *> _toolBox;

        std::string checkTool(Tool* newShovel);
        std::set<Tool *>::iterator findTool(const std::string& toolName);
};


#endif