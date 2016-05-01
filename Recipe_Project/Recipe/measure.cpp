#include <iostream>
#include <cassert>
#include <cctype>
#include "measure.h"
#include "fraction.h"
#include "myString.h"

using namespace std;

namespace gajohnsonCS11{

    const myString measure::unitStrings[] =
                    {"dram", "tsp", "tbsp", "oz", "cup", "pint",
                     "qt", "gal", "peck", "bushel", "barrel", "acre_ft"};

    const fraction measure::conversionTable[] =
                    {fraction(4,3), 3, 2, 8, 2, 2, 4, 2, 4,
                     fraction(55,7), 6000};




    measure measure::operator *= (const fraction &right){
        amount = amount * right;
        this->simplify();

        return *this;
    }




    void measure::simplify(){

        while (amount < 1 && unit > measure::SMALLEST_UNIT){
            amount *= conversionTable[unit - 1];
            unit--;
        }

        while (unit < measure::LARGEST_UNIT &&
              ((amount / conversionTable[unit]) >= 1)){
            amount = amount / conversionTable[unit];
            unit++;
        }
    }



    ostream& operator << (ostream& out, const measure &printMe){
        out << printMe.amount << " " << printMe.measure::unitStrings[printMe.unit];

        return out;
    }



    istream& operator >> (istream& in, measure &readMe){
        myString tempUnit;
        int counter = 0;

        assert(in);
        in >> readMe.amount >> tempUnit;

        while (tempUnit != measure::unitStrings[counter])
        {
            counter++;
        }
        readMe.unit = counter;
        readMe.simplify();

        return in;
    }
}









