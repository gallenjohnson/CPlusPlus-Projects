

#include "creature.h"
#include "elf.h"
#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

namespace gajohnsonCS11{

    //Constructors
    elf::elf(){
        //Calls base class (creature) constructor to set strength and
        //hitpoints to 10 each.
    }












    elf::elf(int newStrength, int newHitpoints)
    : creature(newStrength, newHitpoints)
    {}












    //Accessors
    int elf::getDamage(){
        int damage = creature::getDamage();

        // Elves inflict double magical damage with a 50% chance
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage
                 << " additional damage points!" << endl;
            damage *= 2;
        }

        return damage;
    }












    string elf::getSpecies(){
        return "elf";
    }
}




















