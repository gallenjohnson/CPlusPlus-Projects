//*******************************************************************
//  Fraction implementation
//  This file manipulates instances of class Fraction which it
//  inherits from the fraction header.
//  Assignment 3b
//  G. Allen Johnson - 23 April, 2014
//  CS 10, Section 5393, S. Sarkar
//*******************************************************************

#include <iostream>
#include "fraction.h"

using namespace std;


//Function prototypes************************************************
void reducer(/*in-out*/int& num, /*in-out*/int& denom);
void leastCD(/*in-out*/int& num1, /*in-out*/int& denom1,
             /*in-out*/int& num2, /*in-out*/int& denom2);
//Function prototypes************************************************





//*******************************************************************
//This function is a default constructor.
//
//Pre:  numerator and denominator were declared in header file.
//
//Post: numerator and denominator are assigned values.
//*******************************************************************
fraction::fraction()
{
    numerator = 0;
    denominator = 1;
}





//*******************************************************************
//This function is a parameterized constructor.
//
//Pre:  numerator and denominator were declared in header file.
//
//Post: numerator and denominator are assigned values.
//*******************************************************************
fraction::fraction(/*in*/ int n, /*in*/ int d)
{
    numerator = n;
    denominator = d;
}





//*******************************************************************
//This function tests for equality in two fraction objects by
//comparing their numerators and the denominators
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A boolean value is returned
//*******************************************************************
bool fraction::isEqualTo(fraction value)
{
    if(numerator == value.numerator &&                                  //Tests for equality
       denominator == value.denominator)
        return true;
    else
        return false;
}





//*******************************************************************
//This function compares numerator and denominator values between
//two fraction objects to see if the calling object is greater than
//the target object.
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A boolean value is returned
//*******************************************************************
bool fraction::isGreaterThan(fraction value)
{
    float first, second;

    first = static_cast<float>(numerator) /                             //Cast to float and divided the values
            static_cast<float>(denominator);                            //to simplify the code

    second = static_cast<float>(value.numerator) /
             static_cast<float>(value.denominator);

    if (first > second)
        return true;
    else
        return false;
}





//*******************************************************************
//This function multiplies two fraction objects
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A fraction object is returned whose values are equal to the
//      product of the two fraction objects
//*******************************************************************
fraction fraction::MultipliedBy(fraction value)
{
    fraction product;                                                   //Creates temp instance of the fraction object

    product.numerator = numerator * value.numerator;
    product.denominator = denominator * value.denominator;

    return product;
}





//*******************************************************************
//This function adds two fraction objects
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A fraction object is returned whose values are equal to the
//      sum of the two fraction objects
//*******************************************************************
fraction fraction::AddedTo(fraction value)
{
    fraction sum;                                                       //Creates temp instance of the fraction object

    if (denominator == value.denominator)                               //Checks if the denominators happen to match
        sum.numerator = numerator + value.numerator;
    else
    {
        leastCD(numerator, denominator,                                 //Calls leastCD function to get the least
                value.numerator, value.denominator);                    //common denominator and adjust the fraction values

        sum.numerator = numerator + value.numerator;
        sum.denominator = denominator;
    }

    return sum;
}





//*******************************************************************
//This function subtracts two fraction objects
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A fraction object is returned whose values are equal to the
//      difference of the two fraction objects
//*******************************************************************
fraction fraction::Subtract(fraction value)
{
    fraction difference;                                                //Creates temp instance of the fraction object

    if (denominator == value.denominator)                               //Checks if denominator matches
        difference.numerator = numerator - value.numerator;
    else
    {
        leastCD(numerator, denominator,                                 //Calls leastCD function to get least common
                value.numerator, value.denominator);                    //denominator and adjust fraction values

        difference.numerator = numerator - value.numerator;
        difference.denominator = denominator;
    }

    return difference;
}





//*******************************************************************
//This function divides two fraction objects
//
//Pre:  Values have been assigned for both pairs of numerators and
//      denominators
//
//Post: A fraction object is returned whose values are equal to the
//      quotient of the two fraction objects
//*******************************************************************
fraction fraction::DividedBy(fraction value) const
{
    fraction quotient;                                                  //Creates temp instance of fraction object

    quotient.numerator = numerator * value.denominator;
    quotient.denominator = denominator * value.numerator;

    return quotient;
}





//*******************************************************************
//This function prints out the values of the numerator and the
//denominator of the fraction object.
//
//Pre:  Values for numerator and denominator have been assigned
//
//Post: Values for numerator and denominator are output in a
//      fraction format
//*******************************************************************
void fraction::print() const
{
    fraction temp;                                                      //Creates temp instance of fraction object

    if (numerator == denominator)                                       //Checks for simple reduction
        cout << "1/1";
    else if (numerator == 1)                                            //Checks for simple numerator
        cout << numerator << "/" << denominator;
    else if (denominator == 0)                                          //Checks for illegal denominator
    {
        cout << endl << "ERROR.  Cannot divide by zero." << endl;
    }
    else
    {
        temp.numerator = numerator;                                     //Assigns values to temp object
        temp.denominator = denominator;

        reducer(temp.numerator, temp.denominator);                      //Calls reducer function to reduce the values
        cout << temp.numerator << "/" << temp.denominator;              //in the fraction object before outputting them
    }                                                                   //to the screen
}





//*******************************************************************
//This function reduces the numerator and denominator values of a
//fraction.
//
//Pre:  num and denom have been assigned values
//
//Post: num and denom have been reduced
//*******************************************************************
void reducer (/*in-out*/int& num, /*in-out*/int& denom)
{
    int x;                                                              //Temporary place holder for larger value

    if (num < denom)
                x = num;

        else
                x = denom;

        for (int counter = x; counter > 0; counter--)                   //Sets counter equal to the lesser of the
        {                                                               //numerator or denominator and checks for a
            if (num % counter == 0 &&                                   //modulus result from each using the counter,
                denom % counter == 0)                                   //which counts down if the modulus result
            {                                                           //isn't zero for both.  If it is, it updates
                num = (num / counter);                                  //the numerator and the denominator values
                denom = (denom / counter);                              //I let it count all the way down in the event
            }                                                           //it hit another common divisor.
        }
}





//*******************************************************************
//This function adjusts the numerator and denominator values of two
//fractions to the least common denominator.
//This function also took up a lot more time than I thought it would,
//but I was determined to get it right and make the damned thing
//work.
//
//Pre:  Values have been assigned to both pairs of numerators and
//      denominators
//
//Post: numerators and denominators have been adjusted for both
//      fraction objects
//*******************************************************************
void leastCD(/*in-out*/int& num1, /*in-out*/int& denom1,
             /*in-out*/int& num2, /*in-out*/int& denom2)
{
    int temp1, temp2;                                                   //Temporary place holders for the larger and
                                                                        //smaller denominator values
    if (denom1 < denom2)                                                //Establishes temp1 as the smaller value and
    {                                                                   //temp2 as the larger value
        temp1 = denom1;
        temp2 = denom2;
    }
    else
    {
        temp1 = denom2;
        temp2 = denom1;
    }

    if ((temp2 % temp1) == 0)                                           //Checks if the larger denominator is divisible
    {                                                                   //by the smaller denominator and updates
        if (denom1 < denom2)                                            //the numerators and denominators if it is.
            {
                denom1 = temp2;
                num1 = num1 * (temp2 / temp1);
            }
        else
            {
                denom2 = temp2;
                num2 = num2 * (temp2 / temp1);
            }
    }
    else
    {
        for (int counter = ((temp2 / temp1) + 1);                       //Sets counter equal to the larger denominator
             counter <= temp2; counter++)                               //divided by the smaller denominator, plus 1,
        {                                                               //as a starting point
            if (((temp1 * counter) % temp2) == 0)                       //Checks for a common multiple
            {
                if (denom1 < denom2)                                    //Updates the appropriate numerators and
                {                                                       //denominators
                    denom1 = temp1 * counter;
                    num1 = num1 * counter;
                    denom2 = denom1;
                    num2 = num2 * (denom1 / temp2);
                }
                else
                {
                    denom2 = temp1 * counter;
                    num2 = num2 * counter;
                    denom1 = denom2;
                    num1 = num1 * (denom2 / temp2);
                }
            }                                                           //Otherwise it increases the counter and
        }                                                               //checks again.  It stops when the counter
    }                                                                   //equals the larger denominator as a mutual
}                                                                       //multiple is guaranteed at that point
