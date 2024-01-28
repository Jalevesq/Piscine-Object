#include "Worker.hpp"


Worker::~Worker() {
    std::cout << "Destructor of Worker called" << std::endl;
    this->dropTool();
}

Worker::Worker() {
    this->_coordonnee.x = 0;
    this->_coordonnee.y = 0;
    this->_coordonnee.z = 0;

    this->_stat.exp = 0;
    this->_stat.level = 0;
    this->_tool = NULL;
    std::cout << "Worker constructor Called!" << std::endl;
}

void Worker::giveNewTool(Tool *newTool) {
    std::cout << "Trying to give a new Tool to Worker !" << std::endl;
    if (!this->checkTool(newTool))
        return;
    if (this->_tool)
        this->_tool->Detach(this);
    newTool->Attach(this);
    this->_tool = newTool;
}

bool Worker::checkTool(Tool* newTool) {
    if (!newTool) {
        std::cout << "Fake Tool given, nothing has been done." << std::endl;
        return false;
    }
    if (newTool == this->_tool) {
        std::cout << "Worker already has this Tool." << std::endl;
        return false;
    }
    return true;
}


void Worker::useTool() {
    if (!this->_tool) {
        std::cout << "The worker has no Tool." << std::endl;
    } else {
        this->_tool->use();
    }
}

void Worker::dropTool() {
    if (this->_tool) {
        std::cout << "A worker is droping a Tool." << std::endl;
        this->_tool->Detach(this);
        this->_tool = NULL;
    }
}

void Worker::Update() {
    this->dropTool();
}