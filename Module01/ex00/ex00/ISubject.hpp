#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include <iostream>
#include "IObserver.hpp"

class ISubject {
    public:
        virtual ~ISubject(){};
        virtual void Attach(IObserver *observer) = 0;
        virtual void Detach(IObserver *observer) = 0;
        virtual void Notify() = 0;
};

#endif