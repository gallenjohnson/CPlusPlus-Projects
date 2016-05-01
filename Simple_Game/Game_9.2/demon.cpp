

#include "creature.h"
#include "demon.h"
#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

namespace gajohnsonCS11{

    //Constructors
    demon::demon(){
        //Calls base class (creature) constructor to set strength and
        //hitpoints to 10 each.
    }












    demon::demon(int newStrength, int newHitpoints)
    : creature(newStrength, newHitpoints)
    {}












    //Accessors
    int demon::getDamage(){
        int damage = creature::getDamage();

        // Demons can inflict damage of 50 with a 25% chance
        if (rand() % 4 == 0) {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!";
            cout << endl;
        }

        return damage;
    }












    string demon::getSpecies(){
        return "demon";
    }
}





















