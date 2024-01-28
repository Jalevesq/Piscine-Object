
#include "Tool.hpp"

Tool::Tool(std::string toolName)  {
    std::cout << "Tool constructor Called!" << std::endl;
    this->_currentWorker = NULL;
    this->_toolName = toolName;
    this->_numberOfUses = 0;

}

Tool::~Tool() {
    std::cout << "Tool destructor Called!" << std::endl;
    this->Notify();
}

void Tool::Attach(IObserver *observer) {
    this->Notify();
    this->_currentWorker = observer;
    this->_list_observer.push_back(observer);
}

void Tool::Detach(IObserver *observer) {
    this->_list_observer.remove(observer);
}

void  Tool::Notify() {
    std::list<IObserver *>::iterator iterator = this->_list_observer.begin();
    HowManyObserver();
    while (iterator != this->_list_observer.end()) {
        (*iterator)->Update(this->getToolName());
        iterator = this->_list_observer.begin();
    }
}

void  Tool::HowManyObserver() {
    std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
}
const std::string& Tool::getToolName() const {
    return (this->_toolName);
}

void Tool::incrementToolUses() {
    this->_numberOfUses++;
}

const int& Tool::getNumberOfUses() const {
    return (this->_numberOfUses);
}