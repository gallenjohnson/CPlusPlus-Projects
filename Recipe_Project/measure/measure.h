#include <iostream>
#include "fraction.h"
#include "myString.h"

namespace gaerdel@gmail.com{

    class measure{
    public:
        friend std::ostream& operator << (std::ostream& out, const measure &printMe);
        friend std::istream& operator >> (std::istream& in, measure &readMe);
        measure operator *= (const gaerdel@gmail.com::fraction &right);

    private:
        void simplify();
        static const int LARGEST_UNIT = 11;
        static const int SMALLEST_UNIT = 0;
                    // these two constants:  we'll be using a system where
                    // dram = 0, tsp = 1, tbsp = 2, and so on.  So the
                    // smallest unit (dram) is represented by 0, and the
                    // largest unit (acre_ft) is represented by 11.
        static const int NUM_UNITS = 12;
        static const gaerdel@gmail.com::fraction conversionTable[NUM_UNITS];
        static const gaerdel@gmail.com::myString unitStrings[NUM_UNITS];
        //gaerdel@gmail.com::fraction amount;
        fraction amount;
        int unit;
    };
}





















