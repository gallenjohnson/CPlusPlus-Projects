

#include "creature.h"
#include "human.h"
#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

namespace gajohnsonCS11{

    //Constructors
    human::human(){
        //Calls base class (creature) constructor to set strength and
        //hitpoints to 10 each.
    }












    human::human(int newStrength, int newHitpoints)
    : creature(newStrength, newHitpoints)
    {}












    //Accessors
    int human::getDamage(){
        /*
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % getStrength()) + 1;
        */
        return creature::getDamage();
    }












    string human::getSpecies(){
        return "Human";
    }
}



















