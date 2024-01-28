
#include "Tool.hpp"
#include "Worker.hpp"
#include "Shovel.hpp"
#include <iostream>

// ANSI Color Codes
const std::string RED = "\033[31m";      // Red color
const std::string GREEN = "\033[32m";    // Green color
const std::string YELLOW = "\033[33m";   // Yellow color
const std::string BLUE = "\033[34m";     // Blue color
const std::string MAGENTA = "\033[35m";  // Magenta color
const std::string CYAN = "\033[36m";     // Cyan color

// ANSI Formatting Codes
const std::string BOLD = "\033[1m";      // Bold text
const std::string RESET = "\033[0m";     // Reset to default

void test1() {
    
}

int main(void) {
    Tool* tool = new Shovel;
    Tool* tool2 = new Shovel;
    Worker* worker = new Worker;
    Worker* worker2 = new Worker;

    std::cout << "\033[31m" << "Trying to use Tool without having one." << "\033[0m" << std::endl;
    worker->useTool();

    std::cout << "\033[32m" << "Giving NULL to giveNewTool and trying to use it" << "\033[0m" << std::endl;
    worker->giveNewTool(NULL);
    worker->useTool();

    std::cout << "\033[33m" << "Trying to give a new Tool and use it" << "\033[0m" << std::endl;
    worker->giveNewTool(tool);
    worker->useTool();

    std::cout << "\033[34m" << "Trying to give the Tool that he already has" << "\033[0m" << std::endl;
    worker->giveNewTool(tool);
    worker->useTool();

    std::cout << "\033[35m" << "Giving the Tool of worker to worker2 and using it." << "\033[0m" << std::endl;
    worker2->giveNewTool(tool);
    worker2->useTool();
    worker->useTool();

    std::cout << "\033[36m" << "Removing the Tool from worker2 and trying to use it" << "\033[0m" << std::endl;
    worker2->dropTool();
    worker->useTool();
    worker2->useTool();


    std::cout << "\033[31m" << "2 Tools + 2 workers, multiple test" << "\033[0m" << std::endl;
    worker->giveNewTool(tool);
    worker2->giveNewTool(tool2);
    worker->useTool();
    worker2->useTool();

    worker->dropTool();
    worker->dropTool();

    worker->useTool();
    worker2->useTool();

    worker2->dropTool();

    worker->useTool();
    worker2->useTool();


    std::cout << "\033[32m" << "Giving new Worker a Tool, delete the Tool and give him a new one." << "\033[0m" << std::endl;

    Worker* worker3 = new Worker;
    Tool* tool4 = new Shovel;
    Tool* tool5 = new Shovel;
    worker3->giveNewTool(tool4);
    worker3->useTool();
    delete tool4;
    worker3->useTool();
    worker3->dropTool();
    worker3->giveNewTool(tool5);
    worker3->useTool();
    delete worker3;
    worker2->giveNewTool(tool5);
    worker2->useTool();



    delete tool;
    delete tool2;
    delete worker;
    delete worker2;
}
