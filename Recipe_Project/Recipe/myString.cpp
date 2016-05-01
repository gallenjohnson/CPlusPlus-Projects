/********************************************************************
  G. Allen Johnson - 18 September, 2014
  CS 11, Section 0656, D. Harden
  FILE:  myString.h
  Assignment 2
  CLASS PROVIDED:  myString
********************************************************************/



/*
   CLASS INVARIANT:

   There is one data member in this class.  "aString" represents the
   string value of the myString object.  The string is stored as a
   null-terminated string in the dynamic array that aString points to.
*/

#include "myString.h"
#include <iostream>     // for getline, istream, and ostream
#include <cassert>      // for assert
#include <cctype>       // for isspace
#include<cstring>       // for strcpy, strlen, and strcat


using namespace std;

namespace gajohnsonCS11{
    /*****************************Constructors**************************/

    //Default Constructor
    myString::myString(){
        aString = new char;
        strcpy(aString, "");
    }












    //Parameterized Constructor
    myString::myString(const char *inString){
        aString = new char[strlen(inString) + 1];
        strcpy(aString, inString);
    }












    //Copy Constructor
    myString::myString(const myString& copyString){
        aString = new char[strlen(copyString.aString) + 1];
        strcpy(aString, copyString.aString);
    }












    //Destructor
    myString::~myString(){
        delete[] aString;
    }












    /***************************Member Functions************************/

    int myString::length() const{
        return strlen(aString);
    }












    /********************************************************************
    The line of char, up to the delimiting character, is read into a non-
    dynamic array.  Once the actual number of characters is known, the
    char pointer, aString, is allocated an amount of dynamic memory to
    hold those characters.
    ********************************************************************/
    void myString::read(istream& in, char delimiter){
        const int SIZE = 128;
        char tempArray[SIZE];

        in.getline(tempArray, (SIZE - 1), delimiter);

        delete [] aString;
        aString = new char[strlen(tempArray) + 1];

        strcpy(aString, tempArray);
    }












    /**************************Concatenation*****************************
    The operator + is overloaded to concatenate myString objects.
    temp.aString is the char pointer and is assigned just enough memory
    to hold the first and second string, plus the NULL value.
    ********************************************************************/
    myString operator + (const myString& first, const myString& second){
        myString temp;

        delete [] temp.aString;
        temp.aString = new char[(strlen(first.aString) + strlen(second.aString) + 1)];

        strcpy(temp.aString, first.aString);
        strcat(temp.aString, second.aString);

        return temp;
    }












    myString myString::operator += (const myString& second){
        *this = *this + second;

        return *this;
    }












    /***********************Assignment Operator**************************
    The operator = is overloaded to put the value of rightString.aString
    into the calling object's aString.  If the calling object is set to
    get its own value, the assignment is skipped and the calling object
    is simply returned as is.
    ********************************************************************/

    myString myString::operator = (const myString& rightString){
        if(this != &rightString){
            delete [] aString;
            aString = new char[strlen(rightString.aString) + 1];
            strcpy(aString, rightString.aString);
        }
        return *this;
    }












    /***************************Square Brackets*************************/

    char& myString::operator [] (int index){
        assert(index >= 0 && index < length());
        return aString[index];
    }












    char myString::operator [] (int index) const{
        assert(index >= 0 && index < length());
        return aString[index];
    }












    /**********************Relational Comparisons***********************/

    bool operator < (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) < 0);
    }












    bool operator <= (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) <= 0);
    }












    bool operator > (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) > 0);
    }












    bool operator >= (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) >= 0);
    }












    bool operator == (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) == 0);
    }












    bool operator != (const myString &first, const myString &second) {
        return (strcmp(first.aString, second.aString) != 0);
    }












    /*******************Insertion & Extraction Operators****************/

    ostream& operator << (ostream& out, const myString& printOut){
        out << printOut.aString;

        return out;
    }












    /********************************************************************
    The extraction operator >> is overloaded to accept myString objects.
    A string of char is read into a temporary, non-dynamic array.  Once
    The number of char is known, the myString object is allocated an
    amount of dynamic memory just big enough to hold the string.
    ********************************************************************/
    istream& operator >> (istream& in, myString& readMe){
        const int SIZE = 128;
        char tempArray[SIZE];

        in >> tempArray;

        delete [] readMe.aString;
        readMe.aString = new char[strlen(tempArray) + 1];
        strcpy(readMe.aString, tempArray);

        return in;
    }
}
