

#ifndef gajohnsonCS11_human_h
#define gajohnsonCS11_human_h

#include "creature.h"
#include <iostream>
#include <string>

namespace gajohnsonCS11{
    class human : public creature {
    public:
        //Constructors
        human();
        human(int newStrength, int newHitpoints);

        //Accessors
        std::string getSpecies();
    };
}
#endif // gajohnsonCS11_human_h
