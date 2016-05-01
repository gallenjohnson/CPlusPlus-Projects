
#include "ingredient.h"
#include "fraction.h"
#include "myString.h"
#include "measure.h"
#include <iostream>

using namespace std;

namespace gajohnsonCS11{

    ostream& operator << (ostream& out, const ingredient &printMe){
        out << printMe.component << printMe.ingrName;

        return out;
    }



    istream& operator >> (istream& in, ingredient &readMe){             //Need to use getline here, dummy
        in >> readMe.component;
        readMe.ingrName.read(in, '\n');

        return in;
    }



    ingredient ingredient::operator *= (const fraction &right){
        component *= right;
        return *this;
    }



}
