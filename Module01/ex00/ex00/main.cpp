
#include "Tool.hpp"
#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
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

void test1(Worker* worker) {
    std::cout << RED << "TEST 1" <<  RESET << std::endl;
    std::cout << RED << "Trying to use Tool without having one." << RESET << std::endl;
    worker->useTool(SHOVEL);
    std::cout << RED << "END OF TEST 1" << std::endl;
}

void test2(Worker* worker) {
    std::cout << GREEN << "TEST 2" << RESET << std::endl;
    std::cout << GREEN << "Giving NULL to giveNewTool and trying to use it" << RESET << std::endl;
    worker->giveNewTool(NULL);
    worker->useTool(SHOVEL);
    std::cout << GREEN << "END OF TEST 2" << std::endl;
}

void test3(Worker* worker, Tool *tool) {
    std::cout << YELLOW << "TEST 3" << RESET << std::endl;
    std::cout << YELLOW << "Trying to give a new Tool and use it" << RESET << std::endl;
    worker->giveNewTool(tool);
    worker->useTool(tool->getToolName());
    std::cout << YELLOW << "END OF TEST 3" << std::endl;
}

void test4(Worker* worker, Tool *tool) {
    std::cout << BLUE << "TEST 4" << RESET << std::endl;
    std::cout << BLUE << "Trying to give the Tool that he already has" << RESET << std::endl;
    worker->giveNewTool(tool);
    worker->useTool(tool->getToolName());
    std::cout << BLUE << "END OF TEST 4" << RESET << std::endl;
}

void test5(Worker* worker, Worker * worker2, Tool* tool) {
    std::cout << MAGENTA << "TEST 5" << RESET << std::endl;
    std::cout << MAGENTA << "Giving the Tool of worker to worker2 and using it." << RESET << std::endl;
    worker2->giveNewTool(tool);
    worker2->useTool(tool->getToolName());
    worker->useTool(tool->getToolName());
    std::cout << MAGENTA << "END OF TEST 5" << RESET << std::endl;
}

void test6(Worker* worker, Worker * worker2) {
    std::cout << CYAN << "TEST 6" << RESET << std::endl;

    std::cout << CYAN << "Removing the Tool from worker2 and trying to use it" << RESET << std::endl;
    worker2->dropTool(SHOVEL);
    worker2->useTool(SHOVEL);
    worker->useTool(SHOVEL);

    std::cout << CYAN << "END OF TEST 6" << RESET << std::endl;
}

void test7(Worker* worker, Worker * worker2, Tool* tool, Tool* tool2) {
    std::cout << RED << "TEST 7" << RESET << std::endl;
    std::cout << RED << "2 worker taking shovel, use it and drop it." << RESET << std::endl;

    worker->giveNewTool(tool);
    worker2->giveNewTool(tool2);
    worker->useTool(SHOVEL);
    worker2->useTool(SHOVEL);

    worker->dropTool(SHOVEL);
    worker2->dropTool(SHOVEL);

    worker->useTool(SHOVEL);
    worker2->useTool(SHOVEL);

    std::cout << RED << "END OF TEST 7" << RESET << std::endl;
}

void test8() {
    Worker* workerA = new Worker;
    Tool* toolA = new Shovel;
    Tool* toolB = new Shovel;

    std::cout << GREEN << "TEST 8" << RESET << std::endl;
    std::cout << GREEN << "Giving new Worker a Tool, delete the Tool and give him a new one." << RESET << std::endl;

    workerA->giveNewTool(toolA);
    workerA->useTool(SHOVEL);

    delete toolA;
    workerA->useTool(SHOVEL);

    workerA->giveNewTool(toolB);
    workerA->useTool(SHOVEL);


    delete toolB;
    delete workerA;
}

void test9() {
    Worker* workerA = new Worker;
    Worker* workerB = new Worker;
    Tool* toolA = new Shovel;

    std::cout << YELLOW << "TEST 9" << RESET << std::endl;
    std::cout << YELLOW << "Giving new Worker a Tool, delete the Worker and give the tool to another worker." << RESET << std::endl;

    workerA->giveNewTool(toolA);
    workerA->useTool(SHOVEL);

    delete workerA;
    workerB->useTool(SHOVEL);
    workerB->giveNewTool(toolA);
    workerB->useTool(SHOVEL);

    workerB->dropTool(SHOVEL);
    std::cout << YELLOW << "END OF TEST 9" << RESET << std::endl;

    delete workerB;
    delete toolA;
}

void test10() {
    Tool* shovel = new Shovel;
    Tool* hammer = new Hammer;
    Worker* worker = new Worker;

    std::cout << BLUE << "TEST 10" << RESET << std::endl;
    std::cout << BLUE << "Test with Hammer and Shovel. Interchanging & deleting them." << RESET << std::endl;

    worker->giveNewTool(shovel);
    worker->useTool(SHOVEL);
    worker->useTool(SHOVEL);
    worker->giveNewTool(hammer);
    worker->dropTool(HAMMER);
    worker->giveNewTool(shovel);
    worker->useTool(SHOVEL);
    worker->dropTool(SHOVEL);
    worker->giveNewTool(hammer);
    worker->useTool(HAMMER);
    worker->giveNewTool(shovel);
    delete shovel;
    worker->useTool(SHOVEL);
    worker->giveNewTool(hammer);
    worker->useTool(HAMMER);
    delete hammer;
    worker->useTool(HAMMER);    

    std::cout << BLUE << "END OF TEST 10" << RESET << std::endl;
}

void test11() {

    Tool* shovel = new Shovel;
    Tool* hammer = new Hammer;
    Worker* worker = new Worker;
    std::cout << MAGENTA << "TEST 11" << RESET << std::endl;
    std::cout << MAGENTA << "Test one worker with multiple tools." << RESET << std::endl;

    worker->giveNewTool(shovel);
    worker->giveNewTool(hammer);

    worker->useTool(HAMMER);
    worker->useTool(SHOVEL);
    worker->useTool(SHOVEL);
    worker->useTool(SHOVEL);
    worker->useTool(HAMMER);

    worker->dropTool(SHOVEL);
    worker->useTool(SHOVEL);
    worker->useTool(HAMMER);

    worker->dropTool(HAMMER);

    worker->useTool(SHOVEL);
    worker->useTool(HAMMER);

    std::cout << MAGENTA << "END OF TEST 11" << RESET << std::endl;
    delete shovel;
    delete hammer;
    delete worker;


}

int main(void) {
    Tool* tool = new Shovel;
    Tool* tool2 = new Shovel;
    Worker* worker = new Worker;
    Worker* worker2 = new Worker;

    test1(worker);
    test2(worker);
    test3(worker, tool);
    test4(worker, tool);
    test5(worker, worker2, tool);
    test6(worker, worker2);
    test7(worker, worker2, tool, tool2);
    test8();
    test9();
    test10();
    test11();


    delete tool;
    delete tool2;
    delete worker;
    delete worker2;
}
