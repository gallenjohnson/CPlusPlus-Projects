/********************************************************************
  G. Allen Johnson - 29 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  recipe.cpp
  Assignment 3 EXTRA CREDIT
  CLASS PROVIDED:  recipe
********************************************************************/


/*
   CLASS INVARIANT:

   There are 3 data members in this class:
   - "name" is a myString object with represents the name of the
   recipe. The string is stored as a null-terminated string in the
   dynamic array that aString points to.

   - "ingredients" is a pointer of type ingredient and holds the
   ingredients for the recipe.  Each ingredient has component of
   type measure and an ingrName of type myString. ingrName represents
   the name of the ingredient.  component describes the amount of the
   ingredient and the unit of measure for that amount.  Each component
   has an amount of type fraction and a unit of type int.  The
   component will be converted and displayed, if needed, to the most
   "reasonable" unit, which is the largest unit where the amount is
   greater than or equal to 1 if such a unit exists. Otherwise, the
   unit should be the smallest known unit. The conversions are:
    4/3 dram = 1 tsp
    3 tsp = 1 tbsp
    2 tbsp = 1 oz
    8 oz = 1 cup
    2 cup = 1 pint
    2 pint = 1 qt
    4 qt = 1 gal
    2 gal = 1 peck
    4 peck = 1 bushel
    55/7 bushel = 1 barrel
    6000 barrel = 1 acre_ft

   - "instructions" is a myString object which holds the instructions
   for carrying out the recipe.

   - "servings" is a fraction object which shows the number of
   servings for that recipe.

   - "numIngredients" is an integer which stores the number of
   ingredients for that recipes.
*/

#include "fraction.h"
#include "myString.h"
#include "measure.h"
#include "ingredient.h"
#include "recipe.h"
#include <iostream>
#include <cassert>      // for assert
#include <cctype>       // for isspace
#include<cstring>       // for strcpy, strlen, and strcat

using namespace std;

namespace gajohnsonCS11{



    //Default Constructor
    recipe::recipe(){
    name = "";
    ingredients = new ingredient[1];
    instructions = "";
    servings = 0;
    numIngredients = 0;
    }












    //Copy Constructor
    recipe::recipe(const recipe& copyRecipe){
        ingredients = new ingredient[copyRecipe.numIngredients];
        for(int index = 0; index < copyRecipe.numIngredients; index++){
            ingredients[index] = copyRecipe.ingredients[index];
        }
    }












    //Destructor
    recipe::~recipe(){
    delete [] ingredients;
    }












    myString recipe::getName() const{
        return name;
    }












    /********************************************************************
    The values in the right recipe object are read into the calling
    object.  If the right recipe object has an array of ingredients, this
    function steps through that array and assigns the values accordingly.
    ********************************************************************/
    recipe recipe::operator = (const recipe& rightRecipe){
        if(this != &rightRecipe){
            delete [] ingredients;
            ingredients = new ingredient[rightRecipe.numIngredients];
            for(int index = 0; index < rightRecipe.numIngredients; index++){
                ingredients[index] = rightRecipe.ingredients[index];
            }
            name = rightRecipe.name;
            instructions = rightRecipe.instructions;
            servings = rightRecipe.servings;
            numIngredients = rightRecipe.numIngredients;

        }
        return *this;
    }












    /********************************************************************
    A recipe object is returned which is equal to the original left
    operand except that the number of servings is equal to the right
    operand, and the amounts of the ingredients in the recipe are updated
    and scaled appropriately.
    ********************************************************************/
    recipe operator * (const recipe &left, const fraction &right){
        recipe tempRec;

        delete [] tempRec.ingredients;
        tempRec.ingredients = new ingredient[left.numIngredients];
        tempRec = left;
        tempRec.servings = right;
        for(int index = 0; index < left.numIngredients; index++)
            tempRec.ingredients[index] *= (tempRec.servings/left.servings);

        return tempRec;
    }












    /********************************************************************
    The values in printMe are read into the outstream. If the printMe
    recipe object has an array of ingredients, this function steps
    through that array.
    ********************************************************************/
    ostream& operator << (std::ostream& out, const recipe &printMe){
        out << printMe.name << endl;
        out << printMe.servings << " servings" << endl << endl;
        for(int counter = 0; counter < printMe.numIngredients; counter++){
            out << printMe.ingredients[counter] << endl;
        }
        out << endl;
        out << printMe.instructions << endl;

        return out;
    }












    /********************************************************************
    The values in readMe are read into the instream. It accepts recipes
    in the following format:
    A line indicating the name of the recipe
    A line indicating how many servings the recipe makes
    A line indicating how many ingredients are in the recipe
    A line for each ingredient
    A blank line
    One or more lines of recipe instructions
    A blank line at the end to mark the end of the instructions
    ********************************************************************/
    istream& operator >> (istream &in, recipe &readMe){
        myString temp;
        readMe.name.read(in, '\n');
        in >> readMe.servings;
        in.ignore(10000, '\n');
        in >> readMe.numIngredients;
        delete [] readMe.ingredients;
        readMe.ingredients = new ingredient[readMe.numIngredients];
        in.ignore(10000, '\n');
        for(int count = 0; count < readMe.numIngredients; count++){
            in >> readMe.ingredients[count];
        }
        in.ignore(10000, '\n');
        readMe.instructions = "";
        temp.read(in, '\n');
        while (temp != "") {
            readMe.instructions = readMe.instructions + temp + "\n";
            temp.read(in, '\n');
        }
        return in;
    }
}
