#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <iostream>

class IObserver {
    public:
        virtual ~IObserver(){};
        virtual void Update(std::string toolName) = 0;
};

#endif