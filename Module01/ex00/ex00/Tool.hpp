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

        void Attach(IObserver *observer);
        void Detach(IObserver *observer);
        void Notify();
        void HowManyObserver();
    private:
        std::string _toolName;

        std::list<IObserver *> _list_observer;
        IObserver* _currentWorker;
};

#endif