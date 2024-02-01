#include "Worker.hpp"


Worker::~Worker() {
    std::cout << "Destructor of Worker called" << std::endl;
    std::set<Tool *>::iterator it = this->_toolBox.begin();
    while (it != this->_toolBox.end()) {
        this->dropTool((*it)->getToolName());
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
    std::string newToolName = newTool->getToolName();
    std::set<Tool *>::iterator it = this->findTool(newToolName);
    if (it != this->_toolBox.end()) {
        std::cout << "Worker already has this Tool." << std::endl;
        return "";
    }
    return newToolName;
}


void Worker::useTool(const std::string& toolName) {
    std::set<Tool *>::iterator it = this->findTool(toolName);
    if (it != this->_toolBox.end()) 
        (*it)->use();
    else
        std::cout << "This worker can't use a " << toolName << " because he doesn't have it in his tool box." << std::endl;
}

void Worker::dropTool(const std::string& toolName) {
    std::set<Tool *>::iterator it = this->findTool(toolName);
    std::cout << "Trying to drop a tool" << std::endl;
    if (it != this->_toolBox.end()) {
        std::cout << "A worker is dropping a " << (*it)->getToolName() << "." << std::endl;
        (*it)->Detach(this);
        this->_toolBox.erase(it);
    } else {
        std::cout << "This worker can't drop a " << toolName << " because he doesn't have it in his tool box." << std::endl;
    }
}

void Worker::Update(void* update, const std::string& typeID) {
    if (typeID == "Tool") {
        Tool *tool = static_cast<Tool*>(update);
       this->dropTool(tool->getToolName());
    } else if (typeID == "joinWorkshop") {
        Workshop* workshop = static_cast<Workshop*>(update);
        this->_workshopList.insert(workshop);
    } else if (typeID == "leaveWorkshop") {
        Workshop* workshop = static_cast<Workshop*>(update);
        this->_workshopList.erase(workshop);
    } else if (typeID == "workWorkshop") {
        // this->work();
    }
}

Tool* Worker::returnTool(const std::string& toolName) {
    std::set<Tool *>::iterator it = findTool(toolName);
    if (it != this->_toolBox.end()) {
        std::cout << toolName << " found! Returning it." << std::endl;
        return *it;
    }
    std::cout << toolName << " not found in toolbox." << std::endl;
    return NULL; 
}

std::set<Tool *>::iterator Worker::findTool(const std::string& toolName) {
    std::set<Tool *>::iterator it = this->_toolBox.begin();
    while (it != this->_toolBox.end() && (*it)->getToolName() != toolName)
        it++;
    return it;
}
