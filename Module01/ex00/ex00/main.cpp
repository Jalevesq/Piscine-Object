
#include "Shovel.hpp"
#include "Worker.hpp"
#include <iostream>

int main(void) {
    Shovel* shovel = new Shovel;
    Shovel* shovel2 = new Shovel;
    Worker* worker = new Worker;
    Worker* worker2 = new Worker;

    std::cout << "\033[31m" << "Trying to use Shovel without having one." << "\033[0m" << std::endl;
    worker->useShovel();

    std::cout << "\033[32m" << "Giving NULL to giveNewShovel and trying to use it" << "\033[0m" << std::endl;
    worker->giveNewShovel(NULL);
    worker->useShovel();

    std::cout << "\033[33m" << "Trying to give a new shovel and use it" << "\033[0m" << std::endl;
    worker->giveNewShovel(shovel);
    worker->useShovel();

    std::cout << "\033[34m" << "Trying to give the shovel that he already has" << "\033[0m" << std::endl;
    worker->giveNewShovel(shovel);
    worker->useShovel();

    std::cout << "\033[35m" << "Giving the shovel of worker to worker2 and using it." << "\033[0m" << std::endl;
    worker2->giveNewShovel(shovel);
    worker2->useShovel();
    worker->useShovel();

    std::cout << "\033[36m" << "Removing the shovel from worker2 and trying to use it" << "\033[0m" << std::endl;
    worker2->dropShovel();
    worker->useShovel();
    worker2->useShovel();


    std::cout << "\033[31m" << "2 shovels + 2 workers, multiple test" << "\033[0m" << std::endl;
    worker->giveNewShovel(shovel);
    worker2->giveNewShovel(shovel2);
    worker->useShovel();
    worker2->useShovel();

    worker->dropShovel();
    worker->dropShovel();

    worker->useShovel();
    worker2->useShovel();

    worker2->dropShovel();

    worker->useShovel();
    worker2->useShovel();


    std::cout << "\033[32m" << "Giving new Worker a shovel, delete the shovel and give him a new one." << "\033[0m" << std::endl;

    Worker* worker3 = new Worker;
    Shovel* shovel4 = new Shovel;
    Shovel* shovel5 = new Shovel;
    worker3->giveNewShovel(shovel4);
    worker3->useShovel();
    delete shovel4;
    worker3->useShovel();
    worker3->dropShovel();
    worker3->giveNewShovel(shovel5);
    worker3->useShovel();

    delete shovel;
    delete shovel2;
    delete worker;
    delete worker2;
}
