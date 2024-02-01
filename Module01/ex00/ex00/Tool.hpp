#ifndef TOOL_HPP
#define TOOL_HPP

#include <iostream>
#include "IObserver.hpp"
#include <list>
#include "ISubject.hpp"

class Tool : public ISubject {
    public:
        Tool(std::string toolName);
        virtual ~Tool();
        const std::string& getToolName() const;
        virtual void use() = 0;

        virtual void Attach(IObserver *observer);
        virtual void Detach(IObserver *observer);
        virtual void Notify(const std::string& notifyType);
        void HowManyObserver();

        void incrementToolUses();
        const int& getNumberOfUses() const;
    private:
        std::string _toolName;
        int _numberOfUses;

        std::list<IObserver *> _list_observer;
};

#endif