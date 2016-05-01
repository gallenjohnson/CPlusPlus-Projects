//Client.cpp provides an interface to test the fraction class ADT implementation
//The fraction class objects defined here have two data members and six member functions that provide both binary and boolean operations.
//You may comment out portions of this code so that you can incrementally test the fraction class operations that you have coded.
//Aside from the commenting for testing purposes you MAY NOT MAKE ANY CHANGES to the source code in this client program.

#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    fraction f1(2,7); //object defined with a parameterized class constructor
    fraction f2(1,3);
    fraction result;  //object defined with a default class constructor
    fraction f3;
    const fraction f4(12, 8); //a const object defined with a parameterized class constructor
    const fraction f5(202, 303);

    cout << "The fraction object result contains ";
    result.print(); //calling an observer function
    cout << endl;

    result=f1; //assign one fraction object to another

    //Two boolean operations on fraction objects
    cout<<"\nTesting Boolean operations on fraction objects"<<endl;

    // Relational test: Equality ...note == operator replaced with class member function isEqualTo
    if (f1.isEqualTo(result)){ //a class relational expression - boolean operation/function
        f1.print();
        cout << " is equal to ";
        result.print();
        cout<<endl;
    } else {
        f1.print();
        cout << " is not equal to";
        result.print();
        cout<<endl;
    }

    // Relational test: Greater than or less than ...note  > < operators replaced with class member function isGreaterThan
    if (f2.isGreaterThan(result)){ //a relational expression - a class boolean operation / member function called
        f2.print();
        cout <<" is greater than ";
        result.print();
        cout<<endl;
    } else {
        f2.print();
        cout <<" is less than ";
        result.print();
        cout<<endl;
    }

    //Four binary operations on fraction objects
    cout<<"\nTesting Binary operations on fraction objects"<<endl;

    //multiply two fraction objects ...note * operator replaced with the class member function MultipliedBy
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.MultipliedBy(f2); //a class binary operation / member function called
    result.print();
    cout << endl;

    f3 = result; //assignment

    //add two fraction objects ...note + operator replaced with the class member function AddedTo
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.AddedTo(f2);
    result.print();
    cout << endl;

    //subtract two fraction objects ...note - operator replaced with the class member function Subtract
    cout << "The difference of ";
    f2.print();
    cout << " and ";
    f1.print();
    cout << " is ";
    result = f2.Subtract(f1);
    result.print();
    cout << endl;

    //divide two const fraction objects ...note / operator replaced with the class member function DividedBy
    cout << "The quotient of ";
    f4.print();
    cout << " and ";
    f5.print();
    cout << " is ";
    result = f4.DividedBy(f5);
    result.print();
    cout << endl;

    cout<<"\nFraction class (ADT) implementation test is now completed"<<endl;

    return 0;
}