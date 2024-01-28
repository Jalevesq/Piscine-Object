#include "Worker.hpp"


Worker::~Worker() {
    std::cout << "Destructor of Worker called" << std::endl;
    this->dropTool(HAMMER);
    this->dropTool(SHOVEL);
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
    std::string newToolName = this->checkTool(newTool);
    if (newToolName.empty())
        return;
    newTool->Attach(this);
    this->_toolBox[newToolName] = newTool;
    std::cout << newToolName << " taken !" << std::endl;
}

std::string Worker::checkTool(Tool* newTool) {
    if (!newTool) {
        std::cout << "Fake Tool given, nothing has been done." << std::endl;
        return "";
    }
    std::string newToolName = newTool->getToolName();
    std::map<std::string, Tool *>::iterator it = this->_toolBox.find(newToolName);
    if (it != this->_toolBox.end()) {
        std::cout << "Worker already has this Tool." << std::endl;
        return "";
    }
    return newToolName;
}


void Worker::useTool(std::string toolName) {
    std::map<std::string, Tool *>::iterator it = this->_toolBox.find(toolName);
    if (it == this->_toolBox.end()) {
        std::cout << "This worker can't use a " << toolName << " because he doesn't have it in his tool box." << std::endl;
    } else {
        it->second->use();
    }
}

void Worker::dropTool(std::string toolName) {
    std::map<std::string, Tool *>::iterator it = this->_toolBox.find(toolName);
    std::cout << "Trying to drop a tool" << std::endl;
    if (it != this->_toolBox.end()) {
        std::cout << "A worker is dropping a " << toolName << "." << std::endl;
        it->second->Detach(this);
        this->_toolBox.erase(it);
    } else {
        std::cout << "This worker can't drop a " << toolName << " because he doesn't have it in his tool box." << std::endl;
    }
}

void Worker::Update(std::string toolName) {
    this->dropTool(toolName);
}