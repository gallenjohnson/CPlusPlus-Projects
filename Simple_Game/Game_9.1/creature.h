#ifndef gajohnsonCS11_creature_h
#define gajohnsonCS11_creature_h

#include <iostream>
#include <string>

namespace gajohnsonCS11{

    class creature{
    private:

            //Data members
            int strength;           // how much damage this creature inflicts
            int hitpoints;	        // how much damage this creature can sustain

        public:

            //Constructors
            creature();		        // initialize to human, 10 strength, 10 hitpoints
            creature(int newStrength, int newHitpoints);

            //Accessors
            std::string getSpecies();	// returns the type of the species
            int getStrength();
            int getHitpoints();
            int getDamage();	    // returns the amount of damage this Creature
                                    // inflicts in one round of combat

            //Mutators
            void setStrength(int newStrength);
            void setHitpoints(int newHitpoints);
    };
}

#endif // gajohnsonCS11_creature_h




















