#include "Worker.hpp"


Worker::~Worker() {
    std::cout << "Destructor of Worker called" << std::endl;
    std::set<Tool *>::iterator it = this->_toolBox.begin();
    while (it != this->_toolBox.end()) {
        this->dropTool(*it);
        it = this->_toolBox.begin();
    }
}

Worker::Worker() : _toolBox() {
    this->_coordonnee.x = 0;
    this->_coordonnee.y = 0;
    this->_coordonnee.z = 0;

    this->_stat.exp = 0;
    this->_stat.level = 0;
    std::cout << "Worker constructor Called!" << std::endl;
}

void Worker::giveNewTool(Tool *newTool) {
    std::cout << "Trying to give a new Tool to Worker !" << std::endl;
    std::string newtoolName = this->checkTool(newTool);
    if (newtoolName.empty())
        return;
    newTool->Attach(this);
    this->_toolBox.insert(newTool);
    std::cout << newtoolName << " taken !" << std::endl;
}

std::string Worker::checkTool(Tool* newTool) {
    if (!newTool) {
        std::cout << "Fake Tool given, nothing has been done." << std::endl;
        return "";
    }
    std::set<Tool *>::iterator it = this->_toolBox.find(newTool);
    if (it != this->_toolBox.end()) {
        std::cout << "Worker already has this Tool." << std::endl;
        return "";
    }
    return newTool->getToolName();
}


void Worker::useTool(std::string toolName) {
    std::set<Tool *>::iterator it = this->_toolBox.begin();
    while (it != this->_toolBox.end() && (*it)->getToolName() != toolName)
        it++;
    if (it != this->_toolBox.end()) 
        (*it)->use();
    else
        std::cout << "This worker can't use a " << (*it)->getToolName() << " because he doesn't have it in his tool box." << std::endl;
}

void Worker::dropTool(Tool *tool) {
    std::set<Tool *>::iterator it = this->_toolBox.find(tool);
    std::cout << "Trying to drop a tool" << std::endl;
    if (it != this->_toolBox.end()) {
        std::cout << "A worker is dropping a " << (*it)->getToolName() << "." << std::endl;
        (*it)->Detach(this);
        this->_toolBox.erase(it);
    } else {
        std::cout << "This worker can't drop a " << tool << " because he doesn't have it in his tool box." << std::endl;
    }
}

void Worker::Update(Tool *tool) {
    this->dropTool(tool);
}