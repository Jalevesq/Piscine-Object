#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <iostream>
# include <set>

# include "IObserver.hpp"

class Workshop : ISubject {
    public:
        Workshop();
        ~Workshop();

        void Attach(IObserver *observer);
        void Detach(IObserver *observer);
        void Notify(const std::string& notifyType);

        void executeWorkDay();

    private:
        void HowManyObserver();
        std::set<IObserver *> _list_observer;
        std::set<IObserver *>::iterator findWorker(IObserver* workerToFind);
};

#endif