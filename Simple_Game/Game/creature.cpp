

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
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;

        return damage;
    }













    //Mutators
    void creature::setStrength(int newStrength){
        strength = newStrength;
    }












    void creature::setHitpoints(int newHitpoints){
        hitpoints = newHitpoints;
    }












    string creature::getSpecies(){
        /*
        switch (creature) {
            case human:         return "Human";
            case cyberdemon:    return "Cyberdemon";
            case balrog:        return "Balrog";
            case elf:           return "Elf";
        }
        */
        return "unknown";
    }

/*
    //Demon damage
    int creature::getDamage() {
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        // Demons can inflict damage of 50 with a 25% chance
        if (rand() % 4 == 0) {
            damage = damage + 50;
            cout << "Demonic attack inflicts 50 additional damage points!" << endl;
        }

        return damage;
    }



    //Elf damage
    int creature::getDamage() {
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        // Elves inflict double magical damage with a 50% chance
        if ((rand() % 2) == 0) {
            cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
            damage *= 2;
        }

        return damage;
    }



    //Balrog damage
    int creature::getDamage() {
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        // Balrogs are so fast they get to attack twice
        int damage2 = (rand() % strength) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;

        return damage;
    }
    */
}



/********************************************************************
//Base damage
    int creature::getDamage() {
        int damage;

        // All creatures inflict damage which is a random number up to their strength
        damage = (rand() % strength) + 1;
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        // Demons can inflict damage of 50 with a 25% chance
        if (type == 2 || type == 1){
            if (rand() % 4 == 0) {
                damage = damage + 50;
                cout << "Demonic attack inflicts 50 additional damage points!" << endl;
            }
        }

        // Elves inflict double magical damage with a 50% chance
        if (type == 3) {
            if ((rand() % 2) == 0) {
                cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
                damage *= 2;
            }
        }

        // Balrogs are so fast they get to attack twice
        if (type == 2) {
            int damage2 = (rand() % strength) + 1;
            cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
            damage += damage2;
        }

        return damage;
    }

********************************************************************/








