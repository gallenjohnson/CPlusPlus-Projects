

#ifndef gajohnsonCS11_elf_h
#define gajohnsonCS11_elf_h

#include "creature.h"
#include <iostream>
#include <string>

namespace gajohnsonCS11{
    class elf : public creature {
    public:
        //Constructors
        elf();
        elf(int newStrength, int newHitpoints);

        //Accessors
        int getDamage();
        std::string getSpecies();
    };
}
#endif // gajohnsonCS11_elf_h

