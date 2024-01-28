#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Worker.hpp"
#include "ISubject.hpp"
#include <list>

class Shovel : public ISubject {
    public:
        Shovel();
        ~Shovel();
        void use() {
            std::cout << "IN SHOVEL USE FUNC" << std::endl;
            if (this->currentWorker == NULL) {
                std::cout << "This shovel is not assign to a worker. It can't be use!" << std::endl;
                return;
            }
            this->_numberOfUses++;
            std::cout << "Shovel used. Total uses: " << this->_numberOfUses << std::endl;
        }

    private:
        friend class Worker;
        IObserver* currentWorker;
        int _numberOfUses;
        std::list<IObserver *> _list_observer;

        void Attach(IObserver *observer) {
            this->Notify();
            this->currentWorker = observer;
            this->_list_observer.push_back(observer);
        }
        void Detach(IObserver *observer) {
            this->_list_observer.remove(observer);
        }
        void Notify() {
            std::list<IObserver *>::iterator iterator = this->_list_observer.begin();
            HowManyObserver();
            while (iterator != this->_list_observer.end()) {
                (*iterator)->Update();
                iterator = this->_list_observer.begin();
            }
        }
        void HowManyObserver() {
            std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
        }
};

#endif
