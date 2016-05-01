/********************************************************************
  G. Allen Johnson - 29 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  measure.h
  Assignment 2
  CLASS PROVIDED:  measure
********************************************************************/

#ifndef gajohnsonCS11_measure_h
#define gajohnsonCS11_measure_h

#include <iostream>
#include "fraction.h"
#include "myString.h"



namespace gajohnsonCS11{

    class measure{
    public:
        friend std::ostream& operator << (std::ostream& out, const measure &printMe);
        friend std::istream& operator >> (std::istream& in, measure &readMe);
        measure operator *= (const fraction &right);

    private:
        void simplify();
        static const int LARGEST_UNIT = 11;
        static const int SMALLEST_UNIT = 0;
                    // these two constants:  we'll be using a system where
                    // dram = 0, tsp = 1, tbsp = 2, and so on.  So the
                    // smallest unit (dram) is represented by 0, and the
                    // largest unit (acre_ft) is represented by 11.
        static const int NUM_UNITS = 12;
        static const fraction conversionTable[NUM_UNITS];
        static const myString unitStrings[NUM_UNITS];
        fraction amount;
        int unit;
    };
}
#endif // gajohnsonCS11_measure_h




















