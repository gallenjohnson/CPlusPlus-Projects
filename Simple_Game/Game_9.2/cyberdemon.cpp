

#include "demon.h"
#include "cyberdemon.h"
#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

namespace gajohnsonCS11{

    //Constructors
    cyberdemon::cyberdemon(){
        //Calls base class (demon), which calls base class (creature)
        //constructor to set strength and hitpoints to 10 each.
    }












    cyberdemon::cyberdemon(int newStrength, int newHitpoints)
    : demon(newStrength, newHitpoints)
    {}












    //Accessors
    string cyberdemon::getSpecies(){
        return "cyberdemon";
    }
}





















