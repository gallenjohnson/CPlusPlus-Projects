

#ifndef gajohnsonCS11_demon_h
#define gajohnsonCS11_demon_h

#include "creature.h"
#include <iostream>
#include <string>

namespace gajohnsonCS11{
    class demon : public creature {
    public:
        //Constructors
        demon();
        demon(int newStrength, int newHitpoints);

        //Accessors
        int getDamage();
        std::string getSpecies();
    };
}
#endif // gajohnsonCS11_demon_h


