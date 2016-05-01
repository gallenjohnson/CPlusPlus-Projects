/********************************************************************
  G. Allen Johnson - 29 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  recipe.h
  Assignment 3 EXTRA CREDIT
  CLASS PROVIDED:  recipe
  DESCRIPTION:  This class consists of a name, an array of ingredients,
                the instructions, number of servings, and number of
                ingredients. Both the name and the instructions are
                stored as myString objects. There is not a limit on the
                number of ingredients in the recipe. Rather than use an
                array of myStrings for the collection of instructions,
                the concatenate feature of myStrings is used to combine
                the instruction lines into one myString object as they
                are read them from the file. Newlines are concatenated
                in between the lines to retain the original formatting.
                The recipe class includes a * operator. The * operator
                doesn't exactly multiply. Rather, it returns a recipe
                which is equal to the original left operand (a recipe
                object) EXCEPT that the number of servings is equal to
                the right operand (a fraction object) and the
                ingredients in the recipe are scaled appropriately.
                Value semantics are allowed.

  recipe();
  post: A recipe object is created with a name myString object set
        to "", an ingredient pointer set with with 1 value,
        ingredients[1], an instructions myString object object set
        to "", and an int numIngredients set to 0.


  recipe(const recipe& copyRecipe);
  pre:  copyRecipe is assigned a value.
  post: A copy of the recipe object passed to the function parameter
        is created.

  ~recipe();
  pre:  Dynamic memory has been allocated.
  post: Dynamic memory is deleted once execution of the code exits the
        scope of the function.

  myString getName() const;
  pre:  name has been initialized with a myString object.
  post: The name myString object of the recipe is returned.

  recipe operator = (const recipe& rightRecipe);
  pre:  rightRecipe is assigned a value
  post: The calling object gets the value of rightRecipe.

  friend recipe operator * (const recipe &left,
                                  const fraction &right);
  pre:  left is initialized with a recipe object and right is
        initialized with a fraction object.
  post: A recipe object is returned which is equal to the original
        left operand except that the number of servings is equal to
        the right operand, and the amounts of the ingredients in the
        recipe are updated and scaled appropriately.

  friend std::ostream& operator << (std::ostream& out,
                                          const recipe &printMe);
  pre:  printMe is assigned a value.
  post: The value of printMe is pushed to the out stream.

  friend std::istream& operator >> (std::istream& in,
                                          recipe &readMe);
  pre:  In stream is open and not in a fail state.  readMe has been
        assigned a value.
  post: A recipe object is read into readMe. The readMe recipe object
        is then pushed to the in stream, which is returned.

  Dynamic Memory usage by the myString class:
        If there is insufficient dynamic memory, the following
        functions throw bad_alloc:  the default and copys constructors,
        operator =, operator *, and the extraction operator >>.

********************************************************************/

#ifndef gajohnsonCS11_recipe_h
#define gajohnsonCS11_recipe_h

#include "fraction.h"
#include "myString.h"
#include "measure.h"
#include "ingredient.h"
#include <iostream>

namespace gajohnsonCS11{
    class recipe{
    public:
        recipe();
        recipe(const recipe& copyRecipe);
        ~recipe();
        recipe operator = (const recipe& rightRecipe);
        myString getName() const;
        friend recipe operator * (const recipe &left,
                                  const fraction &right);
        friend std::ostream& operator << (std::ostream& out,
                                          const recipe &printMe);
        friend std::istream& operator >> (std::istream& in,
                                          recipe &readMe);

    private:
        myString name;
        ingredient *ingredients;
        myString instructions;
        fraction servings;
        int numIngredients;
    };
}
#endif // gajohnsonCS11_recipe_h


















