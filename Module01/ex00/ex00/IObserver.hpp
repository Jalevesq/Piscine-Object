#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <iostream>

class IObserver {
    public:
        virtual ~IObserver(){};
        virtual void Update(void* update, const std::string& typeID) = 0;
};

#endif