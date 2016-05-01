//*******************************************************************
//  Fraction Header
//  This file describes the Fraction header
//  Program Fraction manipulates instances of class Fraction.
//  Assignment 3b
//  G. Allen Johnson - 23 April, 2014
//  CS 10, Section 5393, S. Sarkar
//*******************************************************************

class fraction
{
public:
    //function prototypes
    fraction();                             //Default constructor
    fraction(int, int);                     //Parameterized constructor
    fraction AddedTo(fraction);             //Add function
    fraction Subtract(fraction);            //Subtract function
    fraction MultipliedBy(fraction);        //Multiplication function
    fraction DividedBy(fraction) const;     //Divide function
    bool isGreaterThan(fraction);           //Tests if object is greater than target object
    bool isEqualTo(fraction);               //Tests if object is equal to target object
    void print() const;                     //Observer function - Prints out object values



private:
    //data members
    int numerator;
    int denominator;


};
