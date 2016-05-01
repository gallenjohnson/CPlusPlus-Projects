#include <iostream>
#include <cassert>
#include <cctype>
#include "measure.h"
#include "fraction.h"
#include "myString.h"

using namespace std;

namespace gaerdel@gmail.com{

    const myString measure::unitStrings[] =
                    {"dram", "tsp", "tbsp", "oz", "cup", "pint",
                     "qt", "gal", "peck", "bushel", "barrel", "acre_ft"};
    const fraction measure::conversionTable[] =
                    {fraction(4,3), 3, 2, 8, 2, 2, 4, 2, 4,
                     fraction(55,7), 6000};




    fraction measure::operator *= (const fraction &right){
        *this = *this * right;
        return *this;
    }




    void measure::simplify(){
        fraction temp;

        while (unit > measure::SMALLEST_UNIT){
            amount *= conversionTable[unit - 1];
            unit--;
        }
        temp = amount;
        while (unit < measure::LARGEST_UNIT &&
              ((temp / conversionTable[unit]) > 1)){
            amount = amount / conversionTable[unit];
            temp = amount;
            unit++;
        }
    }



    ostream& operator << (ostream& out, const measure &printMe){
        out << printMe.amount << " " << printMe.unitStrings[printMe.unit];

    return out;
    }



    istream& operator >> (istream& in, measure &readMe){                    //<<<<<<<<<WORKING HERE>>>>>>>>>>>>>>
        assert(in);
        in >> readMe.amount >> readMe.unit;

        while(isspace(in.peek())){
            in.ignore();
        }
    return in;
    }
}









