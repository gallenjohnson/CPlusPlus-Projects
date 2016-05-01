

#ifndef gajohnsonCS11_cyberdemon_h
#define gajohnsonCS11_cyberdemon_h

#include "demon.h"
#include <iostream>
#include <string>

namespace gajohnsonCS11{
    class cyberdemon : public demon {
    public:
        //Constructors
        cyberdemon();
        cyberdemon(int newStrength, int newHitpoints);

        //Accessors
        int getDamage();
        std::string getSpecies();
    };
}
#endif // gajohnsonCS11_cyberdemon_h


