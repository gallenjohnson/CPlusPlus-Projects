

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include "human.h"
#include "elf.h"
#include "cyberdemon.h"
#include "balrog.h"

using namespace std;
using namespace gajohnsonCS11;


void battleArena(creature &creature1, creature& creature2);
void fightPicker();



int main() {
	srand(time(0));
	char response = 'y';

    while(response == 'y'){
        fightPicker();
        cout << "Battle again? Type y for yes or n for no: ";
        cin >> response;
        cout << endl;
        while(!cin || (response != 'y' && response != 'n')){
            cin.clear();
            cin.ignore();
            cout << "Battle again? Type y for yes or n for no: ";
            cin >> response;
            cout << endl;
        }
	}
}




void fightPicker(){
    human h(20, 50);
    elf e(20, 50);
    cyberdemon c(20, 50);
    balrog b(20, 50);

    switch(rand() % 6){
        case 0: battleArena(h, e);
                break;
        case 1: battleArena(h, c);
                break;
        case 2: battleArena(h, b);
                break;
        case 3: battleArena(e, c);
                break;
        case 4: battleArena(e, b);
                break;
        case 5: battleArena(c, b);
                break;
    }
}












void battleArena(creature &creature1, creature& creature2){
    bool tie = false;

    cout << "********************************************************" << endl;
    cout << "A battle starts between the " << creature1.getSpecies()
         << " and the " << creature2.getSpecies() << "!" << endl << endl;
    cout << "The " << creature1.getSpecies() << " begins with "
         << creature1.getHitpoints() << " hit points." << endl;
    cout << "The " << creature2.getSpecies() << " begins with "
         << creature2.getHitpoints() << " hit points." << endl << endl;

    while(creature1.getHitpoints() > 0 &&
          creature2.getHitpoints() > 0 && !tie){

        creature1.setHitpoints(creature1.getHitpoints() -
                               creature2.getDamage());
        cout << "The " << creature1.getSpecies() << " has "
             << creature1.getHitpoints() << " hit points left." << endl
             << endl;

        creature2.setHitpoints(creature2.getHitpoints() -
                               creature1.getDamage());
        cout << "The " << creature2.getSpecies() << " has "
             << creature2.getHitpoints() << " hit points left." << endl
             << endl;

        if(creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
            tie = true;
    }

    if(tie){
        cout << "It's a tie!  Both the " << creature1.getSpecies() << " and the " << creature2.getSpecies()
             << " perish in the battle!" << endl;
    } else if(creature1.getHitpoints() <= 0){
        cout << "The " << creature2.getSpecies() << " is victorious!"
             << endl;
    } else {
        cout << "The " << creature1.getSpecies() << " is victorious!"
             << endl;
    }

    cout << "********************************************************" << endl;
    cout << endl;
}


















