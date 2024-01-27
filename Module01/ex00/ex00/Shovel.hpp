#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Worker.hpp"

class Shovel {
    public:
        Shovel();
        ~Shovel();
        void use() {
            this->_numberOfUses++;
            std::cout << "Shovel used. Total uses: " << this->_numberOfUses << std::endl;
        }

    private:
        int _numberOfUses;
};

#endif
