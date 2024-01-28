#ifndef SHOVEL_HPP
#define SHOVEL_HPP

#include "Tool.hpp"
#include <list>

class Shovel : public Tool {
    public:
        Shovel();
        ~Shovel();

        void use();
        private:
            int _numberOfUses;

};

#endif
