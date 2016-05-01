

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
        int damage = creature::getDamage();
        cout << "The "<< getSpecies() << " attacks for " << damage
             << " points!" << endl;

        return damage;
    }












    string human::getSpecies(){
        return "human";
    }
}



















