#include "Workshop.hpp"

Workshop::Workshop() {
    std::cout << "Workshop constructor called!" << std::endl;
}

Workshop::~Workshop() {
    std::cout << "Workshop destructor called!" << std::endl;
    this->Notify("workshopDestruction");
}

void Workshop::Attach(IObserver *observer) {
    if (observer && this->findWorker(observer) == this->_list_observer.end()) {
        std::cout << "A worker is joining a workshop!" << std::endl;
        observer->Update(this, "joinWorkshop");
        this->_list_observer.insert(observer);
    }
}

void Workshop::Detach(IObserver *observer) {
    if (observer && this->findWorker(observer) != this->_list_observer.end()) {
        observer->Update(this, "leaveWorkshop");
        this->_list_observer.erase(observer);
    }
}

void Workshop::Notify(const std::string& notifyType) {
    std::set<IObserver *>::iterator iterator = this->_list_observer.begin();
    HowManyObserver();
    while (iterator != this->_list_observer.end()) {
        (*iterator)->Update(this, notifyType);
        iterator = this->_list_observer.begin();
    }
}

void  Workshop::HowManyObserver() {
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}

std::set<IObserver *>::iterator Workshop::findWorker(IObserver* workerToFind) {
    std::set<IObserver *>::iterator it = this->_list_observer.begin();
    while (it != this->_list_observer.end() && *it != workerToFind)
        it++;
    return it;
}


void Workshop::executeWorkDay() {
    this->Notify("workWorkshop");
}