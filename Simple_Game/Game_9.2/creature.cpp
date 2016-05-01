

#include<iostream>
#include<cstdlib>
#include "creature.h"

using namespace std;

namespace gajohnsonCS11{


    //Constructors
    creature::creature(){
        strength = 10;
        hitpoints = 10;
    }












    creature::creature(int newStrength, int newHitpoints){
        strength = newStrength;
        hitpoints = newHitpoints;
    }












    //Accessors
    int creature::getStrength(){
        return strength;
    }












    int creature::getHitpoints(){
        return hitpoints;
    }












    //Base damage
    int creature::getDamage() {
        int damage = (rand() % strength) + 1;
        cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
        return damage;
    }













    //Mutators
    void creature::setStrength(int newStrength){
        strength = newStrength;
    }












    void creature::setHitpoints(int newHitpoints){
        hitpoints = newHitpoints;
    }
}


























