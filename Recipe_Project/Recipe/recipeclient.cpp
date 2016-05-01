/********************************************************************
  G. Allen Johnson - 29 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  recipeclient.cpp
  Assignment 3 EXTRA CREDIT
  Description:  This program reads in a number of recipes from a
  file, maximum of 100.  It prompts the user to select a recipe and
  select the number of servings for that recipe. It then prints out
  the correct ingredient amounts proportional to the number of
  desired servings.
********************************************************************/

#include "recipe.h"
#include "fraction.h"
#include "myString.h"
#include "measure.h"
#include "ingredient.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;
using namespace gajohnsonCS11;


/***********************Function Prototypes*************************/
void menu(const recipe recArray[], int numRecipes);
int menuChoice();
fraction numServings(const myString &drink);
void readFile(recipe recArray[], int recSize, int &numRecipes);
void makeRecipe(const recipe recList[], int numRecipes);
/*******************************************************************/



int main()
{
    const int REC_SIZE = 100;
    int numRecipes;
    recipe recipeList[REC_SIZE];
    readFile(recipeList, REC_SIZE, numRecipes);
    myString recipeName;

    menu(recipeList, numRecipes);
    makeRecipe(recipeList, numRecipes);

    for (int count = 0; count < numRecipes; count++){
        cout << recipeList[count];
    }
    return 0;
}












/*******************************************************************
This function accepts the user input for which recipe to choose,
accepts the number of desired servings from the user, reads the
selected recipe stored in the array into a temporary recipe object,
converts the ingredient amounts in proportion to the desired
servings, and then outputs that data to the user.

Pre:    recList and recSize have been assigned values.

Post:   If the menu choice is not negative and the servings are
        greater than 0, then the selected recipe will print out with
        the correctly scaled ingredient amounts.  If a negative
        number is entered for the main menu, then the program exits.
        If 0 servings is selected, no recipe is printed out and the
        menu is displayed once more.
*********************************************************************/
void makeRecipe(const recipe recList[], int numRecipes){
    int inChoice;
    fraction newServings;
    recipe tempRecipe;
    myString tempName;

    inChoice = menuChoice();
    tempName = recList[inChoice].getName();

    while(inChoice >= 0 && inChoice <= numRecipes){
        newServings = numServings(tempName);
        if(newServings > 0){
            tempRecipe = recList[inChoice];
            tempRecipe = tempRecipe * newServings;
            cout << tempRecipe;
        } else
            cout << endl;
        menu(recList, numRecipes);
        inChoice = menuChoice();
        tempName = recList[inChoice].getName();
    }
}












/********************************************************************
This function reads the data.txt file and copies the recipe data into
an array of type recipe.

Pre:    recArray and numRecipes are initialized.  recSize is assigned
        a value.

Post:   Recipe data is put into the recArray and numRecipes is
        updated with the number of recipes present in the array.
*********************************************************************/
void readFile(recipe recArray[], int recSize, int &numRecipes){
    int count = 1;
    ifstream in("data.txt");
    assert(in);
    in >> recArray[0];
    while(in && count < recSize){
        in >> recArray[count];
        count++;
    }
    in.close();
    numRecipes = count;
}












/********************************************************************
This function prompts the user for the number of servings and returns
that value as a fraction object.

Pre:    drink is assigned a value.

Post:   newServings is updated with the amount of desired servings.
*********************************************************************/
fraction numServings(const myString &drink){
    fraction newServings;
    cout << "How many servings of " << drink << "? ";
    cin >> newServings;
    while (!cin){
        cin.clear();
        cin.ignore();
        cout << "How many servings of " << drink << "? ";
        cin >> newServings;
    }
    return newServings;
}











/********************************************************************
This function prompts the user for a menu choice and returns that
selection as an integer.

Pre:    None.

Post:   choice is updated with the user's selection and returned.
*********************************************************************/
int menuChoice(){
    int choice;
    cout << "Enter choice (negative number to quit) >> ";
    cin >> choice;
    while (!cin){
        cin.clear();
        cin.ignore();
        cout << "Enter choice (negative number to quit) >> ";
        cin >> choice;
    }
    return choice;
}












/********************************************************************
This function prints out the menu.

Pre:    recArray and numRecipes are initialized and assigned values.

Post:   A menu of recipe names is displayed to the user.
*********************************************************************/
void menu(const recipe recArray[], int numRecipes){
    myString tempName;
    cout << "Please select a recipe:" << endl;

    for(int index = 0; index < numRecipes; index++){
        tempName = recArray[index].getName();
        cout << "   " << index << ". " << tempName << endl;
    }
}



















