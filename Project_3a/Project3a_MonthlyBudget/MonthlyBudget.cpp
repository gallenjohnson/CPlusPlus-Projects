//*******************************************************************
//  Monthly Budget
//  This program declares a MonthlyBudget structure designed with
//  member variables to hold each of these expense categories.  The
//  program defines two MonthlyBudget structure variables, budget
//  and spent.  The first MonthlyBudget structure variable, budget,
//  will contain the budget figures.  Budget will be passed to a
//  function, displayBudget, that will display the budget categories
//  along with the budgeted amounts.  spent will be passed to another
//  function, getExpenses, that has the user enter the amounts
//  actually spent in each budget category during the past month.
//  Finally, the program passes both structure variables to function
//  compareExpenses, which displays a report indicating the amount
//  over or under the budget that the user spent in each category, as
//  well as the amount over or under for the entire monthly budget.
//  Project 3a
//  G. Allen Johnson - 11 April, 2014
//  CS 10, Section 5393, S. Sarkar
//*******************************************************************

#include <iostream>
#include <iomanip>  //For setw() and setprecision()
#include <cmath>    //For fabs()

using namespace std;

//Creates struct
struct MonthlyBudget
{
    float housing;
    float utilities;
    float household;
    float transportation;
    float food;
    float medical;
    float insurance;
    float entertainment;
    float clothing;
    float misc;

    MonthlyBudget()     //Default Constructor
    {
        //Sets start values for struct members
        housing        = 580.00;
        utilities      = 150.00;
        household      = 65.00;
        transportation = 50.00;
        food           = 250.00;
        medical        = 30.00;
        insurance      = 100.00;
        entertainment  = 150.00;
        clothing       = 75.00;
        misc           = 50.00;
    }
};

//Function prototypes************************************************
void displayBudget(/*in*/ MonthlyBudget);
void badData(/*in-out*/ float&);
void getExpenses(/*in-out*/ MonthlyBudget&);
void compareExpenses(/*in*/ MonthlyBudget, /*in*/ MonthlyBudget);
//*******************************************************************


int main()
{
    //Declaring Variables
    MonthlyBudget budget;
    MonthlyBudget spent;

    //Function calls
    displayBudget(budget);
    getExpenses(spent);
    compareExpenses(budget, spent);

    return 0;
}





//*******************************************************************
//This function clears bad user input and throws an error message.
//
//Pre:  userData has been assigned a value
//
//Post: An error message is thrown and the userData parameter is
//      cleared of the incorrect data.
//*******************************************************************
void badData(/*in-out*/ float& userData)
{
        cin.clear();                                                    //Clears input stream
        cin.ignore();                                                   //Ignores additional whitespace and end of line
        cout << "ERROR: You must enter a positive number." << endl;     //Throws an error to the user
}





//*******************************************************************
//This function displays the budget categories along with the
//budgeted amounts.
//
//Pre:  MonthlyBudget struct has been defined and values for all of
//      its members have been assigned.
//
//Post: Budget categories and budgeted amounts are output to the
//      screen.
//*******************************************************************
void displayBudget(/*in*/ MonthlyBudget theBudget)
{
    float totalBudget;

    //Output to the user
    cout << endl;
    cout << "Here is your monthly budget:" << endl << endl;
    cout << "Housing         $";
    cout << setw(5) << theBudget.housing << endl;
    cout << "Utilities       $";
    cout << setw(5) << theBudget.utilities << endl;
    cout << "Household       $";
    cout << setw(5) << theBudget.household << endl;
    cout << "Transportation  $";
    cout << setw(5) << theBudget.transportation << endl;
    cout << "Food            $";
    cout << setw(5) << theBudget.food << endl;
    cout << "Medical         $";
    cout << setw(5) << theBudget.medical << endl;
    cout << "Insurance       $";
    cout << setw(5) << theBudget.insurance << endl;
    cout << "Entertainment   $";
    cout << setw(5) << theBudget.entertainment << endl;
    cout << "Clothing        $";
    cout << setw(5) << theBudget.clothing << endl;
    cout << "Miscellaneous   $";
    cout << setw(5) << theBudget.misc << endl;

    totalBudget = theBudget.housing + theBudget.utilities +             //Summing total budget
                    theBudget.household + theBudget.transportation +
                    theBudget.food + theBudget.medical +
                    theBudget.insurance + theBudget.entertainment +
                    theBudget.clothing + theBudget.misc;

    //Output total to user
    cout << endl;
    cout << "======================================================";
    cout << endl;
    cout << "Total Budgeted  $";
    cout << setw(5) << totalBudget << endl;
    cout << "======================================================";
    cout << endl << endl << endl;
}





//*******************************************************************
//This function accepts actual amounts spent from the user and
//assigns those values to the correct member.  Negative numbers are
//not allowed.
//
//Pre:  MonthlyBudget struct has been defined and spent variable has
//      been declared.
//
//Post: Budget categories are assigned validated amounts by the user
//      and the MonthlyBudget struct is returned to the calling
//      function.
//*******************************************************************
void getExpenses(/*in-out*/ MonthlyBudget& spent)
{
    //Declaring Variables
    float userData; //Temp storage for userData to
                    //be entered into member fields

    //Output to user
    cout << "Enter your actual monthly expenditures for each budget";
    cout << " category:" << endl << endl << endl;

    //Get Housing data***********************************************
    cout << "Housing         $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Housing         $  ";
        cin >> userData;
    }
    spent.housing = userData;                                           //Assigns data to member field

    //Get Utilities data*********************************************
    cout << "Utilities       $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Utilities       $  ";
        cin >> userData;
    }
    spent.utilities = userData;                                         //Assigns data to member field

    //Get Household data*********************************************
    cout << "Household       $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Household       $  ";
        cin >> userData;
    }
    spent.household = userData;                                         //Assigns data to member field

    //Get Transportation data****************************************
    cout << "Transportation  $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Transportation  $  ";
        cin >> userData;
    }
    spent.transportation = userData;                                    //Assigns data to member field

    //Get Food data**************************************************
    cout << "Food            $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Food            $  ";
        cin >> userData;
    }
    spent.food = userData;                                              //Assigns data to member field

    //Get Medical data***********************************************
    cout << "Medical         $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Medical         $  ";
        cin >> userData;
    }
    spent.medical = userData;                                           //Assigns data to member field

    //Get Insurance data*********************************************
    cout << "Insurance       $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Insurance       $  ";
        cin >> userData;
    }
    spent.insurance = userData;                                         //Assigns data to member field

    //Get Entertainment data*****************************************
    cout << "Entertainment   $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Entertainment   $  ";
        cin >> userData;
    }
    spent.entertainment = userData;                                     //Assigns data to member field

    //Get Clothing data**********************************************
    cout << "Clothing        $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Clothing        $  ";
        cin >> userData;
    }
    spent.clothing = userData;                                          //Assigns data to member field

    //Get Miscellaneous data*****************************************
    cout << "Miscellaneous   $  ";
    cin >> userData;

    //Validates Data
    while (!cin || userData < 0)
    {
        badData(userData);
        cout << "Miscellaneous   $  ";
        cin >> userData;
    }
    spent.misc = userData;                                              //Assigns data to member field
    cout << endl << endl;
}





//*******************************************************************
//This function displays a report indicating the amount over or under
//budget the student spent in each category, as well as the amount
//over or under for the entire monthly budget.
//
//Pre:  MonthlyBudget struct is defined.  budget and spent variables
//      are declared.  All members of budget and spent are assigned.
//
//Post: Output to screen of member values, and sums, differences
//      and totals of member values.
//*******************************************************************
void compareExpenses(/*in*/ MonthlyBudget budget,
                     /*in*/ MonthlyBudget spent)
{
    //Declaring Variables
    float subTotal;     //Temporary storage that stores the difference
                        //of 2 member fields
    float budgetTotal;  //Stores the student's budget total
    float spentTotal;   //Stores how much the student actually spent
    float diffTotal;    //Stores the total difference between budgetTotal
                        //and spentTotal

    cout << fixed << showpoint << setprecision(2);                      //Sets floating number formatting
    cout << endl;

    //Header output
    cout << setw(25) << "Budgeted"
         << setw(10) << "Spent"
         << setw(16) << "Difference" << endl;
    cout << "=================================================";
    cout << endl;

    //Housing output
    subTotal = spent.housing - budget.housing;                          //Calculates subtotal so it can be output
    cout << "Housing";
    cout << setw(17) << budget.housing;
    cout << setw(12) << spent.housing;
    cout << setw(12) << subTotal << endl;
    diffTotal = subTotal;                                               //Updates the total difference
    budgetTotal = budget.housing;                                       //Updates the total budget
    spentTotal = spent.housing;                                         //Updates the total spent

    //Utilities output
    subTotal = spent.utilities - budget.utilities;                      //Calculates subtotal so it can be output
    cout << "Utilities";
    cout << setw(15) << budget.utilities;
    cout << setw(12) << spent.utilities;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.utilities;                                    //Updates the total budget
    spentTotal += spent.utilities;                                      //Updates the total spent

    //Household output
    subTotal = spent.household - budget.household;                      //Calculates subtotal so it can be output
    cout << "Household";
    cout << setw(15) << budget.household;
    cout << setw(12) << spent.household;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.household;                                    //Updates the total budget
    spentTotal += spent.household;                                      //Updates the total spent

    //Transportation output
    subTotal = spent.transportation - budget.transportation;            //Calculates subtotal so it can be output
    cout << "Transportation";
    cout << setw(10) << budget.transportation;
    cout << setw(12) << spent.transportation;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.transportation;                               //Updates the total budget
    spentTotal += spent.transportation;                                 //Updates the total spent

    //Food output
    subTotal = spent.food - budget.food;                                //Calculates subtotal so it can be output
    cout << "Food";
    cout << setw(20) << budget.food;
    cout << setw(12) << spent.food;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.food;                                         //Updates the total budget
    spentTotal += spent.food;                                           //Updates the total spent

    //Medical output
    subTotal = spent.medical - budget.medical;                          //Calculates subtotal so it can be output
    cout << "Medical";
    cout << setw(17) << budget.medical;
    cout << setw(12) << spent.medical;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.medical;                                      //Updates the total budget
    spentTotal += spent.medical;                                        //Updates the total spent

    //Insurance output
    subTotal = spent.insurance - budget.insurance;                      //Calculates subtotal so it can be output
    cout << "Insurance";
    cout << setw(15) << budget.insurance;
    cout << setw(12) << spent.insurance;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.insurance;                                    //Updates the total budget
    spentTotal += spent.insurance;                                      //Updates the total spent

    //Entertainment output
    subTotal = spent.entertainment - budget.entertainment;              //Calculates subtotal so it can be output
    cout << "Entertainment";
    cout << setw(11) << budget.entertainment;
    cout << setw(12) << spent.entertainment;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.entertainment;                                //Updates the total budget
    spentTotal += spent.entertainment;                                  //Updates the total spent

    //Clothing output
    subTotal = spent.clothing - budget.clothing;                        //Calculates subtotal so it can be output
    cout << "Clothing";
    cout << setw(16) << budget.clothing;
    cout << setw(12) << spent.clothing;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.clothing;                                     //Updates the total budget
    spentTotal += spent.clothing;                                       //Updates the total spent

    //Miscellaneous output
    subTotal = spent.misc - budget.misc;                                //Calculates subtotal so it can be output
    cout << "Miscellaneous";
    cout << setw(11) << budget.misc;
    cout << setw(12) << spent.misc;
    cout << setw(12) << subTotal << endl;
    diffTotal += subTotal;                                              //Updates the total difference
    budgetTotal += budget.misc;                                         //Updates the total budget
    spentTotal += spent.misc;                                           //Updates the total spent

    //Total output
    cout << "=================================================";
    cout << endl;
    cout << "Total";
    cout << setw(19) << budgetTotal;
    cout << setw(12) << spentTotal;
    cout << setw(12) << fabs(diffTotal) << endl;                        //fabs() used to take the absolute
    cout << "=================================================";        //value of the floating point value
    cout << endl << endl;

    //Message to user determined by under budget, over budget, or
    //broke even.
    if (diffTotal < 0)
    {
        cout << "Congratulations!  You were $" << fabs(diffTotal);
        cout << " under budget this month." << endl << endl;
    }
    else if (diffTotal == 0)
    {
        cout << "Looks like you broke even this month.";
        cout << endl << endl;
    }
    else
    {
        cout << "You went over budget by $" << diffTotal;
        cout << endl << endl;
    }
}
