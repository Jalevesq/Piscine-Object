#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <list>
# include "Worker.hpp"

class Workshop : ISubject {
    public:
        Workshop();
        ~Workshop();

        void Attach(IObserver *observer);
        void Detach(IObserver *observer);
        void Notify();
        void HowManyObserver();

    private:
        std::list<IObserver *> _list_observer;
};

#endif