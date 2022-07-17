#ifndef FIGHT_HPP
#define FIGHT_HPP


#include "characters.hpp"

namespace msm {



class Fight {
    private:
        Player player[2];
        bool turn; // false - player[0], true = player[1]


    public:
        Fight();
        ~Fight();

        int turn(movemode_t mode);
        int fight();
};

#endif





}