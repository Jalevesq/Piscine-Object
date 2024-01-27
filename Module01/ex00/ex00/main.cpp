
#include "Shovel.hpp"
#include "Worker.hpp"
#include <iostream>
int main(void) {
    Shovel* shovel = new Shovel;
    Worker* worker = new Worker;
    Worker* worker2 = new Worker;

    worker->useShovel();

    worker->giveNewShovel(NULL);
    worker->useShovel();

    worker->giveNewShovel(shovel);
    worker->useShovel();

    worker2->giveNewShovel(shovel);

    worker->useShovel();
    worker2->useShovel();

    worker2->giveNewShovel(shovel);

    delete shovel;
    delete worker;
    delete worker2;
}