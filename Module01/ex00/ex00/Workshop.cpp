
// #include "Workshop.hpp"

// Workshop::Workshop() {

// }

// Workshop::~Workshop() {

// }

// void Workshop::Attach(IObserver *observer) {
//     this->_list_observer.push_back(observer);
// }

// void Workshop::Detach(IObserver *observer) {
//     this->_list_observer.remove(observer);
// }

// void Workshop::Notify() {
//     std::list<IObserver *>::iterator iterator = this->_list_observer.begin();
//     HowManyObserver();
//     while (iterator != this->_list_observer.end()) {
//         (*iterator)->Update("To replace");
//         iterator = this->_list_observer.begin();
//     }
// }

// void  Workshop::HowManyObserver() {
//     std::cout << "There are " << _list_observer.size() << " observers in the list.\n";
// }