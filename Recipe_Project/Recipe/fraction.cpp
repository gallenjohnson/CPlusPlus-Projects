//*******************************************************************
//  G. Allen Johnson - 26 August, 2014
//  CS 11, Section 0656, D. Harden
//  FILE:  fraction.cpp
//  CLASS IMPLEMENTED:  fraction (see fraction.h for documentation)
//  Implementation File
//  Assignment 1
//
//  PRIVATE MEMBERS:
//      Data:
//      numerator:      Stores an integer.  Guaranteed to
//                      have an integer stored by the constructor.
//
//      denominator:    Stores an integer.  Guaranteed to
//                      have an integer stored by the constructor.
//
//      Function:
//      reduce():       Reduces fraction object.  See function below
//                      for details.
//
//  Notes:  Fraction objects will always be stored in a reduced
//          format.  Mixed numbers will always be stored in a non-
//          mixed numbers format.
//*******************************************************************

#include "fraction.h"
#include<iostream>
#include<cmath>         //Used for abs().
#include <cassert>      //Used for assert().  Not necessary, but nice to have.
using namespace std;











namespace gajohnsonCS11{
    /************************Parameterized Constructor******************/

    fraction::fraction(int inNum, int inDenom){
        numerator   = inNum;
        denominator = inDenom;

        reduce();                                                               //Ensures fraction object is stored in a
    }                                                                           //reduced format.












    /*******************************Arithmetic Functions****************/

    fraction operator + (const fraction &first, const fraction &second){
        fraction temp;                                                          //fraction object declared to return sum

        if(first.denominator == second.denominator){
            temp.numerator   = first.numerator + second.numerator;
            temp.denominator = first.denominator;
        }
        else{
            temp.numerator   = ((first.numerator * second.denominator) +
                                (second.numerator * first.denominator));
            temp.denominator = (first.denominator * second.denominator);
        }
        temp.reduce();

        return temp;
    }












    fraction operator - (const fraction &first, const fraction &second){
        fraction temp;                                                          //fraction object declared to return difference

        if(first.denominator == second.denominator){
            temp.numerator   = first.numerator - second.numerator;
            temp.denominator = first.denominator;
        }
        else{
            temp.numerator   = ((first.numerator * second.denominator) -
                                (second.numerator * first.denominator));
            temp.denominator = (first.denominator * second.denominator);
        }
        temp.reduce();

        return temp;
    }












    fraction operator * (const fraction &first, const fraction &second){
        fraction temp;                                                          //fraction object declared to return product

        temp.numerator   = first.numerator * second.numerator;
        temp.denominator = first.denominator * second.denominator;
        temp.reduce();

        return temp;
    }












    fraction operator / (const fraction &first, const fraction &second){
        fraction temp;                                                          //fraction object declared to return quotient

        temp.numerator   = first.numerator * second.denominator;
        temp.denominator = first.denominator * second.numerator;
        if(temp.denominator < 0){
            temp.numerator *= -1;
            temp.denominator *= -1;
        }
        temp.reduce();

        return temp;
    }












    /**********************Relational Comparisons***********************/

    bool operator < (const fraction &first, const fraction &second){
        return ((first.numerator * second.denominator) <
               (second.numerator * first.denominator));
    }











    bool operator > (const fraction &first, const fraction &second){
        return ((first.numerator * abs(second.denominator)) >
               (second.numerator * first.denominator));
    }












    bool operator <= (const fraction &first, const fraction &second){
        return ((first.numerator * second.denominator) <=
               (second.numerator * first.denominator));
    }












    bool operator >= (const fraction &first, const fraction &second){
        return ((first.numerator * second.denominator) >=
               (second.numerator * first.denominator));
    }












    bool operator == (const fraction &first, const fraction &second){
        return ((first.numerator * second.denominator) ==
               (second.numerator * first.denominator));
    }












    bool operator != (const fraction &first, const fraction &second){
        return ((first.numerator * second.denominator) !=
               (second.numerator * first.denominator));
    }












    /****************Shorthand Arithmetic Functions*********************/

    fraction fraction::operator += (const fraction &second){
        *this = *this + second;
        return *this;
    }












    fraction fraction::operator -= (const fraction &second){
        *this = *this - second;
        return *this;
    }












    fraction fraction::operator *= (const fraction &second){
        *this = *this * second;
        return *this;
    }












    fraction fraction::operator /= (const fraction &second){
        *this = *this / second;
        return *this;
    }












    /****************************Post-Incrementer***********************/

    fraction fraction::operator--(int){
        fraction temp(*this);                                                   //fraction object declared to mimic behavior
        *this = *this - 1;                                                      //of the post-fix incrementer
        return temp;
    }











    fraction fraction::operator++(int){
        fraction temp(*this);
        *this = *this + 1;
        return temp;
    }












    /****************************Pre-Incrementer************************/

    fraction fraction::operator--(){
        *this = *this - 1;

        return *this;
    }











    fraction fraction::operator++(){
        *this = *this + 1;

        return *this;
    }












    /**********************Insertion Operator & Output******************/

    ostream& operator << (ostream& out, const fraction& printOut){

        if(printOut.denominator == 1)
            out << printOut.numerator;
        else if(printOut.denominator == -1)
            out << printOut.numerator * -1;
        else if(printOut.numerator == 0)
            out << printOut.numerator;
        else if (abs(printOut.numerator) > abs(printOut.denominator)){          //Print out routine for mixed numbers
            if(printOut < 0){
                out << (printOut.numerator / printOut.denominator)
                    << "+" << abs(printOut.numerator % printOut.denominator)
                    << "/" << abs(printOut.denominator);
            }
            else
                out << (printOut.numerator / printOut.denominator)
                    << "+" << printOut.numerator % printOut.denominator
                    << "/" << printOut.denominator;
        }
        else
            out << printOut.numerator << "/" << printOut.denominator;

        return out;
    }












    /**********************Extraction Operator & Input******************/

    istream& operator >> (istream& in, fraction& dataIn){
        int firstNum, secondNum, thirdNum;                                      //ints declared to temporarily store integers
        assert(in);                                                             //read from the file.
        in >> firstNum;
        if(in.peek() == ' ' || in.peek() == '\n'){
            dataIn.numerator = firstNum;
            dataIn.denominator = 1;
        }
        else if(in.peek() == '/'){
            in.ignore();
            in >> secondNum;
            dataIn.numerator = firstNum;
            dataIn.denominator = secondNum;
        }
        else {
            in.ignore();
            in >> secondNum;
            in.ignore();
            in >> thirdNum;
            if(firstNum < 0){
                dataIn.numerator = ((thirdNum * firstNum) - secondNum);
                dataIn.denominator = thirdNum;
            }
            else {
                dataIn.numerator = ((thirdNum * firstNum) + secondNum);
                dataIn.denominator = thirdNum;
            }
        }
        dataIn.reduce();
        return in;
    }












    /************************Reduce Function****************************/
    //
    //  This function reduces a fraction object to its lowest terms.
    //
    //Pre:  The numerator and denominator values have been initialized.
    //
    //Post: The numerator and denominator values are reduced to their
    //      lowest terms.
    //
    /*******************************************************************/
    void fraction::reduce()
    {
        int smallerValue;                                                       //int declared serves as the starting point
                                                                                //for the for-loop counter.
        if (abs(numerator) < abs(denominator))
            smallerValue = abs(numerator);
        else
            smallerValue = abs(denominator);

        for (int counter = smallerValue; counter > 0; counter--){
            if (numerator % counter == 0 && denominator % counter == 0)
                {
                    numerator = (numerator / counter);
                    denominator = (denominator / counter);
                }
        }
    }
}
