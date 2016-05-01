

#ifndef gajohnsonCS11_balrog_h
#define gajohnsonCS11_balrog_h

#include "demon.h"
#include <iostream>
#include <string>

namespace gajohnsonCS11{
    class balrog : public demon {
    public:
        //Constructors
        balrog();
        balrog(int newStrength, int newHitpoints);

        //Accessors
        int getDamage();
        std::string getSpecies();
    };
}
#endif // gajohnsonCS11_balrog_h



