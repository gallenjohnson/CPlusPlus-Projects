

#include "demon.h"
#include "balrog.h"
#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

namespace gajohnsonCS11{

    //Constructors
    balrog::balrog(){
        //Calls base class (demon), which calls base class (creature)
        //constructor to set strength and hitpoints to 10 each.
    }












    balrog::balrog(int newStrength, int newHitpoints)
    : demon(newStrength, newHitpoints)
    {}












    //Accessors
    int balrog::getDamage(){
        cout << "The balrog ";
        int damage = demon::getDamage();

        // Balrogs are so fast they get to attack twice
        int damage2 = creature::getDamage();
        cout << "Balrog speed attack inflicts " << damage2
             << " additional damage points!" << endl;
        damage += damage2;

        return damage;
    }












    string balrog::getSpecies(){
        return "balrog";
    }
}






















