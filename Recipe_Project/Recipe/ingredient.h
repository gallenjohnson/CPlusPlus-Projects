/********************************************************************
  G. Allen Johnson - 29 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  ingredient.h
  Assignment 2
  CLASS PROVIDED:  ingredient
********************************************************************/

#ifndef gajohnsonCS11_ingredient_h
#define gajohnsonCS11_ingredient_h

#include "fraction.h"
#include "myString.h"
#include "measure.h"
#include <iostream>

namespace gajohnsonCS11{
    class ingredient{
    public:
        friend std::ostream& operator << (std::ostream& out, const ingredient &printMe);
        friend std::istream& operator >> (std::istream& in, ingredient &readMe);
        ingredient operator *= (const fraction &right);

    private:
        measure component;
        myString ingrName;
    };
}
#endif // gajohnsonCS11_ingredient_h











