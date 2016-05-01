//*******************************************************************
//  G. Allen Johnson - 26 August, 2014
//  CS 11, Section 0656, D. Harden
//  FILE:  fraction.h
//  Assignment 1
//  CLASS PROVIDED:  fraction
//  DESCRIPTION:    This class defines a fraction object as having
//                  a numerator and a denominator and stores all
//                  fractions in that format, in their reduced form.
//
//                  It overloads the +, -, *, /, +=, -=, *=, /=, ++
//                  and -- (pre and post-fix), <<, and >> operators
//                  so that they can be used with fraction objects.
//
//                  The class allows for arithmetic operations using
//                  fraction to fraction, fraction to integer, and
//                  integer to fraction.
//
//                  The class allows for comparison operations using
//                  fraction to fraction, fraction to integer, and
//                  integer to fraction.
//
//                  Input from the user for the numerator is expected
//                  to be an integer.  Input from the user for the
//                  denominator is expected to be an integer other
//                  than zero.  The code does not check for zero value
//                  denominators.
//
//                  If entering a numerator and denominator, input for
//                  the numerator and denominator should include a
//                  forward slash and be in the following format:
//                  numerator/denominator
//
//                  Mixed numbers are expected to be in
//                  the following format:
//                  number+numerator/denominator.
//
//                  Improper fractions will be displayed as a mixed
//                  number using the following format:
//                  number+numerator/denominator.
//
//                  In the case of a negative mixed number fraction,
//                  the format will be:
//                  -number+numerator/denominator.
//
//                  Fraction objects with a negative denominator will
//                  be displayed with the negative sign at the
//                  numerator.  numerator/-denominator will be
//                  displayed as:  -numerator/denominator.
//
//                  Single integers will be stored as a fraction with
//                  a denominator of 1 and will be displayed as a whole
//                  number.  A fraction object which is reduced to a
//                  denominator of 1 will be displayed as a whole number.
//                  Fraction objects with a zero numerator will
//                  be displayed as just a zero.
//
//
//
//  CONSTRUCTOR for the fraction class:
//      fraction(int inNum = 0, int inDenom = 1)
//          Postcondition:  If no arguments are passed, a fraction
//          object is returned with a default numerator of 0 and a
//          denominator of 1.  If one argument is passed, the
//          numerator is set to it and the denominator is set to 1.
//          Otherwise the numerator and denominator are set by the
//          calling object and the fraction object is reduced before
//          it is returned.
//
//  MODIFICATION MEMBER FUNCTIONS for the fraction class:
//
//  Binary Arithmetic Functions
//      friend fraction operator + (const fraction &first,
//                                  const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  A reduced fraction object is returned which is
//                          the sum of the first and second fraction objects.
//
//      friend fraction operator - (const fraction &first,
//                                  const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  A reduced fraction object is returned which is
//                          the difference of the first and second fraction
//                          objects.
//
//      friend fraction operator * (const fraction &first,
//                                  const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  A reduced fraction object is returned which is
//                          the product of the first and second fraction
//                          objects.
//
//      friend fraction operator / (const fraction &first,
//                                  const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  A reduced fraction object is returned which is
//                          the quotient of the first and second fraction
//                          objects.
//
//  Relational Functions
//      friend int operator < (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//      friend int operator > (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//      friend int operator <= (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//      friend int operator >= (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//      friend int operator == (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//      friend int operator != (const fraction &first,
//                             const fraction &second);
//          Precondition:   first and second fraction objects initialized.
//          Postcondition:  An int result of 1 is returned if the
//                          comparison is true.  An int result of 0 is
//                          returned if the comparison is false.
//
//
//  Shorthand Arithmetic Functions
//      fraction operator += (const fraction &second);
//          Precondition:   The calling object and the second fraction
//                          fraction object are both initialized.
//          Postcondition:  The value of the second object is added to the
//                          value of the calling object which is reduced and
//                          returned.
//
//      fraction operator -= (const fraction &second);
//          Precondition:   The calling object and the second fraction
//                          fraction object are both initialized.
//          Postcondition:  The value of the second object is subtracted from
//                          value of the calling object which is reduced and
//                          returned.
//
//      fraction operator *= (const fraction &second);
//          Precondition:   The calling object and the second fraction
//                          fraction object are both initialized.
//          Postcondition:  The value of the second object is multiplied to
//                          value of the calling object which is reduced and
//                          returned.
//
//      fraction operator /= (const fraction &second);
//          Precondition:   The calling object and the second fraction
//                          fraction object are both initialized.
//          Postcondition:  The value of the calling object is divided by
//                          value of the second fraction object.  The new
//                          value of the calling object is reduced and
//                          returned.
//
//
//  Pre/Post-Fix Incrementers
//      fraction operator ++ ();
//          Precondition:   The calling object is initialized.
//          Postcondition:  The calling object is incremented and its
//                          value is returned.
//
//      fraction operator ++(int);
//          Precondition:   The calling object is initialized.
//          Postcondition:  The calling object is incremented.  The
//                          original value of the calling object is
//                          returned.
//
//      fraction operator -- ();
//          Precondition:   The calling object is initialized.
//          Postcondition:  The calling object is decremented and its
//                          value is returned.
//
//      fraction operator --(int);
//          Precondition:   The calling object is initialized.
//          Postcondition:  The calling object is decremented.  The
//                          original value of the calling object is
//                          returned.
//
//
//  Insertion Operator and Outputs
//      friend ostream& operator << (ostream& out,
//                                   const fraction& printOut);
//          Precondition:   The printOut fraction object is initialized.
//          Postcondition:  The printOut fraction object is passed to
//                          the out file stream with a numerator, a "\",
//                          and a denominator, in a reduced format.  The
//                          out file stream is returned.
//
//  Extraction Operator and Inputs
//      friend istream& operator >> (istream& in, fraction& dataIn);
//          Precondition:   The dataIn fraction object is initialized.
//          Postcondition:  A numerator and denominator are assigned to
//                          the dataIn fraction object and the dataIn
//                          fraction object is passed to the in file
//                          stream, in reduced format.  The in file
//                          stream is returned.
//*******************************************************************

#ifndef gajohnsonCS11_fraction_h
#define gajohnsonCS11_fraction_h
#include <iostream>

namespace gajohnsonCS11{
    class fraction
    {
    public:
        //Parameterized Constructor
        fraction(int inNum = 0, int inDenom = 1);

        //Binary Arithmetic Functions
        friend fraction operator + (const fraction &first,
                                    const fraction &second);
        friend fraction operator - (const fraction &first,
                                    const fraction &second);
        friend fraction operator * (const fraction &first,
                                    const fraction &second);
        friend fraction operator / (const fraction &first,
                                    const fraction &second);

        //Relational Functions
        friend bool operator < (const fraction &first,
                               const fraction &second);
        friend bool operator > (const fraction &first,
                               const fraction &second);
        friend bool operator <= (const fraction &first,
                               const fraction &second);
        friend bool operator >= (const fraction &first,
                               const fraction &second);
        friend bool operator == (const fraction &first,
                               const fraction &second);
        friend bool operator != (const fraction &first,
                               const fraction &second);

        //Shorthand Arithmetic Functions
        fraction operator += (const fraction &second);
        fraction operator -= (const fraction &second);
        fraction operator *= (const fraction &second);
        fraction operator /= (const fraction &second);

        //Pre-Post Fix Incrementers
        fraction operator ++ ();
        fraction operator ++(int);
        fraction operator -- ();
        fraction operator --(int);

        //Insertion Operator and Outputs
        friend std::ostream& operator << (std::ostream& out, const fraction& printOut);
        friend std::istream& operator >> (std::istream& in, fraction& dataIn);

    private:
        void reduce();
        int numerator;
        int denominator;
    };
}
#endif // gajohnsonCS11_fraction_h
