#include "Workshop.hpp"

Workshop::Workshop() {
    std::cout << "Workshop constructor called!" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructor called!" << std::endl;
}

void Workshop::Attach(IObserver *observer) {
    this->_list_observer.push_back(observer);
}

void Workshop::Detach(IObserver *observer) {
    this->_list_observer.remove(observer);
}

void Workshop::Notify() {
    std::list<IObserver *>::iterator iterator = this->_list_observer.begin();
    HowManyObserver();
    while (iterator != this->_list_observer.end()) {
        (*iterator)->Update(this, "Workshop");
        iterator = this->_list_observer.begin();
    }
}

void  Workshop::HowManyObserver() {
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}