//*******************************************************************
//  Game of Life
//  This program simulates the life, death, and survival of bacteria
//  from one generation to the next, assuming the starting grid of
//  bacteria is generation zero (0).  Each cell has a total of up to
//  8 neighbors.  The rules for the creation of each cell in the next
//  generation are as follows:
//  1.  If the cell is currently empty:
//    1.  If the cell has exactly three living neighbors, it will
//        come to life in the next generation.
//    2.  If the cell has any other number of living neighbors, it
//        will remain empty.
//  2.  If the cell is currently living:
//    1.  If the cell has one or zero living neighbors, it will die
//        of loneliness in the next generation.
//    2.  If the cell has four or more living neighbors, it will die
//        of overcrowding in the next generation.
//    3.  If the cell has two or three neighbors, it will remain
//        living.
//  3.  All births and deaths occur simultaneously
//  Project 5
//  G. Allen Johnson - 9 May, 2014
//  CS 10, Section 5393, S. Sarkar
//*******************************************************************

#include <iostream>
#include <fstream>  //For ifstream
#include <iomanip>  //For setw()

using namespace std;


//Function prototypes************************************************
void assignArray(/*in-out*/int table[][20], /*in*/int numRow,
                 /*in*/int numCol, /*in-out*/ifstream& inFile);

int cellCount(/*in*/const int table[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y);

void closeFile(/*in-out*/ifstream& inFile, /*in*/string fileName);

int colAlive(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol, /*in*/int y);

void deadCell(/*in*/const int table[][20],
              /*in-out*/int newTable[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y);

void genStep(/*in-out*/int table[][20], /*in-out*/int newTable[][20],
             /*in*/int numRow, /*in*/int numCol);

void liveCell(/*in*/const int table[][20],
              /*in-out*/int newTable[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y);

void openFile(/*in-out*/ifstream& inFile, /*in*/string fileName);

void printBlob(/*in*/const int table[][20], /*in*/int numRow,
               /*in*/int numCol);

int rowAlive(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol, /*in*/int x);

int sumArray(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol);

void updateGenTable(/*in-out*/int table[][20],
                    /*in*/const int newTable[][20], /*in*/int numRow,
                    /*in*/int numCol);

void zeroOut(/*in-out*/int table[][20], /*in*/int numRow,
             /*in*/int numCol);
//Function prototypes************************************************

int main()
{

    //Declares Constants & Variables
    const int NUM_ROWS = 20;                                            //Max num of rows
    const int NUM_COL = 20;                                             //Max num of columns
    int totalCells = NUM_ROWS * NUM_COL;                                //Total cells in matrix
    ifstream inFile;                                                    //To open bacteria.txt
    int table[NUM_ROWS][NUM_COL];                                       //Current generation array
    int newTable[NUM_ROWS][NUM_COL];                                    //Next generation array
    string fileName = "bacteria.txt";                                   //File with bacteria coordinates for array
    int liveRow = 10;                                                   //Bean counting for row 10
    int liveCol = 10;                                                   //Bean counting for column 10
    int deadRow = 16;                                                   //Bean counting for row 16
    int deadCol = 1;                                                    //Bean counting for column 1

    //Open the file bacteria.txt
    openFile(inFile, fileName);

    //Zero out the tables
    zeroOut(table, NUM_ROWS, NUM_COL);
    zeroOut(newTable, NUM_ROWS, NUM_COL);

    //Assign values to the table array based on the file data
    assignArray(table, NUM_ROWS, NUM_COL, inFile);

    //Initial program output
    cout << endl;
    cout << "======================================================";
    cout << endl << endl;
    cout << "First Generation:" << endl;
    printBlob(table, NUM_ROWS, NUM_COL);                                //Prints out generation zero (0)
    cout << endl;

    //Loops through 5 generations of bacteria and updates the table
    //array
    for(int counter = 1; counter <= 5; counter++)
        genStep(table, newTable, NUM_ROWS, NUM_COL);                    //Calls genStep to update table array

    //Final program output
    cout << "======================================================";
    cout << endl << endl;
    cout << "Fifth Generation:" << endl;
    printBlob(table, NUM_ROWS, NUM_COL);                                //Prints out generation five (5)
    cout << endl;
    cout << "======================================================";
    cout << endl << endl;

    //Bean counting
    cout <<"GAME OF LIFE STATS (5th GENERATION)...check figures ";
    cout <<"listed below.." << endl;
    cout << "Total alive in row " << liveRow << "\t=" << setw(5)
         << rowAlive(table, NUM_ROWS, NUM_COL, liveRow);                //Calls function to count live cells in row
    cout << endl;

    cout << "Total alive in col " << liveCol << "\t=" << setw(5)
         <<  colAlive(table, NUM_ROWS, NUM_COL, liveCol);               //Calls function to count live cells in column
    cout << endl;

    cout << "Total dead in row " << deadRow << "\t=" << setw(5)
         <<  (NUM_COL - rowAlive(table, NUM_ROWS, NUM_COL, deadRow));   //Subtracts value of live cells in row from max
    cout << endl;                                                       //number of cells in that row

    cout << "Total dead in col " << deadCol << "\t=" << setw(5)
         <<  (NUM_ROWS - colAlive(table, NUM_ROWS, NUM_COL, deadCol));  //Subtracts value of live cells in column from max
    cout << endl;                                                       //number of cells in that column

    cout << "Total alive \t \t=" << setw(5)
         << sumArray(table, NUM_ROWS, NUM_COL);                         //Calls function to count all live cells in
    cout << endl;                                                       //table array
    cout << "Total dead \t \t=" << setw(5)
         <<  (totalCells - sumArray(table, NUM_ROWS, NUM_COL));         //Subtracts number of live cells from max
    cout << endl << endl;                                               //number of cells in the table array

    closeFile(inFile, fileName);                                        //Closes file



    return 0;
}





//*******************************************************************
//This function accepts row and column coordinates from a file and
//assigns a value of 1 to the cell matching those coordinates
//
//Pre:  table array is created and initialized.  numRow and numCol
//      are assigned values.  inFile is opened and has valid row and
//      column coordinates.
//
//Post: Specified cells are assigned a value of 1.
//*******************************************************************
void assignArray(/*in-out*/int table[][20], /*in*/int numRow,
                 /*in*/int numCol, /*in-out*/ifstream& inFile)
{
    int x, y;                                                           //Cell coordinates

    while(inFile)
    {
        inFile >> x >> y;                                               //Gets cell coordinates from file
        table[x][y] = 1;                                                //Assigns a 1 to that cell
    }
}





//*******************************************************************
//This function handles the logic which determines the range of
//array elements to sum, sums them, and returns that sum to the
//calling function.  It was challenging, interesting, and I learned
//a lot from doing it.  It was also a pain in the ass.
//
//Pre:  table array is created and initialized.
//      numRow, numCol, x, and y are assigned values.
//
//Post: The sum of the cells surrounding the target cell, whose
//      coordinates are determined by x and y, are returned to the
//      calling function.
//*******************************************************************
int cellCount(/*in*/const int table[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y)
{
    int sum = 0;                                                        //Stores the number of live cells in a range

    //Sum of cells if target cell is not on an array border
    if(x > 0 && y > 0 && x < (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if target cell is on the first row and the last column
    else if(x == 0 && y > 0 && x < (numRow - 1) && y == (numCol - 1))
    {
        for(int rIndex = x; rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= y; cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is just on the last column
    else if(x > 0 && y > 0 && x < (numRow - 1) && y == (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= y; cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is on the last row and the last column
    else if(x > 0 && y > 0 && x == (numRow - 1) && y == (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= x; rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= y; cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is just on the first column
    else if(x > 0 && y == 0 && x < (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = y; cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is on the first column and the last row
    else if(x > 0 && y == 0 && x == (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= x; rIndex++)
        {
            for(int cIndex = y; cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is just on the first row
    else if(x == 0 && y > 0 && x < (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = x; rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is just on the last row
    else if(x > 0 && y > 0 && x == (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = (x - 1); rIndex <= x; rIndex++)
        {
            for(int cIndex = (y - 1); cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Sum of cells if the target cell is on the first row and the first column
    else if(x == 0 && y == 0 && x < (numRow - 1) && y < (numCol - 1))
    {
        for(int rIndex = x; rIndex <= (x + 1); rIndex++)
        {
            for(int cIndex = y; cIndex <= (y + 1); cIndex++)
            {
                sum += table[rIndex][cIndex];
            }
        }
    }

    //Otherwise the code went beyond the borders of the array
    else
    {
        cout << "ERROR:  Coordinate Accessed Outside of array in ";
        cout << "function: cellCount." << endl;
        return 1;
    }

    return sum;
}





//*******************************************************************
//This function closes a file
//
//Pre:  ifstream inFile has been declared and opened. fileName has
//      been assigned a value.
//
//Post: The file named in fileName is closed.
//*******************************************************************
void closeFile(/*in-out*/ifstream& inFile, /*in*/string fileName)
{
    inFile.close();                                                     //Closes file
}





//*******************************************************************
//This function returns the sum of living cells in a column
//
//Pre:  table array is created and initialized.  numRow, numCol, and
//      y are assigned values.
//
//Post: An int sum is returned to the calling function
//*******************************************************************
int colAlive(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol, /*in*/int y)
{
    int result = 0;

    for(int rIndex = 0; rIndex < numCol; rIndex++)                      //Steps through each cell in a column
        result += table[rIndex][y];                                     //and collects the sum

    return result;
}





//*******************************************************************
//This function calls the function sumCell to determine how many
//cells are "alive" around the target cell that was passed to it and
//updates the target cell appropriately.
//
//Pre:  table and newTable arrays are created and initialized.
//      numRow, numCol, x, and y are assigned values.
//
//Post: The newTable array is updated.
//*******************************************************************
void deadCell(/*in*/const int table[][20],
              /*in-out*/int newTable[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y)
{
    int sum;

    sum = cellCount(table, numRow, numCol, x, y);                       //Calls sumCell to get the sum of cells
                                                                        //around the target cell
    //Applies empty/dead cell logic
    if(sum == 3)
        newTable[x][y] = 1;
    else
        newTable[x][y] = 0;
}





//*******************************************************************
//This function steps through an array and calls either the deadCell
//or the liveCell function depending on what the value is in that
//cell.  It then calls updateGenTable to assign the values in the
//newTable array back into the table array.
//
//Pre:  table and newTable arrays are created and initialized.
//      numRow and numCol are assigned values.
//
//Post: The table array is updated.
//*******************************************************************
void genStep(/*in-out*/int table[][20], /*in-out*/int newTable[][20],
             /*in*/int numRow, /*in*/int numCol)
{
    for(int rIndex = 0; rIndex < numRow; rIndex++)                      //Steps through array
        for(int cIndex = 0; cIndex < numCol; cIndex++)
        {
            switch(table[rIndex][cIndex])
            {
                case 0  :   deadCell(table, newTable, numRow, numCol,   //Calls deadCell if element is zero (0)
                                     rIndex, cIndex);
                            break;
                case 1  :   liveCell(table, newTable, numRow, numCol,   //Call liveCell if element is one (1)
                                     rIndex, cIndex);
                            break;
            }
        }
    updateGenTable(table, newTable, numRow, numCol);                    //Calls updateGenTable to assign
}                                                                       //values from newTable into the table array





//*******************************************************************
//This function calls the function sumCell to determine how many
//cells are "alive" around the target cell that was passed to it and
//updates the target cell appropriately.
//
//Pre:  table and newTable arrays are created and initialized.
//      numRow, numCol, x, and y are assigned values.
//
//Post: The newTable array is updated.
//*******************************************************************
void liveCell(/*in*/const int table[][20],
              /*in-out*/int newTable[][20], /*in*/int numRow,
              /*in*/int numCol, /*in*/int x, /*in*/int y)
{
    int sum;

    sum = cellCount(table, numRow, numCol, x, y) - 1;                   //Calls sumCell to get the sum of cells
                                                                        //around the target cell, less one (1) to
                                                                        //account for the value of the target live cell.
    //Applies live cell logic
    if(sum <= 1 || sum >= 4)
        newTable[x][y] = 0;
    else if(sum > 1 && sum < 4)
        newTable[x][y] = 1;
}





//*******************************************************************
//This function opens a file
//
//Pre:  ifstream inFile has been declared. fileName has been assigned
//      a value.
//
//Post: The file named in fileName is opened.
//*******************************************************************
void openFile(/*in-out*/ifstream& inFile, /*in*/string fileName)
{
    inFile.open(fileName.c_str());                                      //Opens file
}





//*******************************************************************
//This function prints out a grid of asterisks which serves as a
//visual representation of the bacteria in the live cells of the
//array
//
//Pre:  table array is created and initialized.
//      numRow and numCol are assigned values.
//
//Post: A grid of bacteria is displayed.
//*******************************************************************
void printBlob(/*in*/const int table[][20], /*in*/int numRow,
               /*in*/int numCol)
{
    for(int counter = 0; counter < numCol; counter++)                   //Creates column numbers
    {
        if(counter == 0)
            cout << "   ";                                              //Initial spacing
        cout << (counter % 10) << " ";                                  //Counts off columns
    }
    cout << endl;

    for(int rIndex = 0; rIndex < numRow; rIndex++)
    {
            if(rIndex < 10)                                             //Creates row numbers
                cout << " " << rIndex << " ";
            else
                cout << rIndex << " ";

        for(int cIndex = 0; cIndex < numCol; cIndex++)
        {
            if (table[rIndex][cIndex] == 1)
                cout << "* ";                                           //Outputs an asterisk if cell is alive
            else
                cout << "  ";                                           //Otherwise it outputs a space
        }
        cout << endl;
    }
}





//*******************************************************************
//This function returns the sum of living cells in a row
//
//Pre:  table array is created and initialized.  numRow, numCol, and
//      x are assigned values.
//
//Post: An int sum is returned to the calling function
//*******************************************************************
int rowAlive(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol, /*in*/int x)
{
    int result = 0;

    for(int cIndex = 0; cIndex < numCol; cIndex++)                      //Steps through each cell in a row
        result += table[x][cIndex];                                     //and collects the sum

    return result;
}





//*******************************************************************
//This function sums the values of all of the elements in an array
//
//Pre:  table array is created and initialized.  numRow and numCol
//      are assigned values.
//
//Post: An int sum is returned to the calling function
//*******************************************************************
int sumArray(/*in*/const int table[][20], /*in*/int numRow,
             /*in*/int numCol)
{
    int sum = 0;

    for(int rIndex = 0; rIndex < numRow; rIndex++)
        for(int cIndex = 0; cIndex < numCol; cIndex++)
            sum = sum + table[rIndex][cIndex];                          //Steps through array and sums
                                                                        //the values of the elements
    return sum;
}





//*******************************************************************
//This function copies over the element values from the newTable
//array into the table array
//
//Pre:  table and newTable arrays are created and initialized.
//      numRow and numCol are assigned values.
//
//Post: The table array is updated.
//*******************************************************************
void updateGenTable(/*in-out*/int table[][20],
                    /*in*/const int newTable[][20], /*in*/int numRow,
                    /*in*/int numCol)
{
    for(int rIndex = 0; rIndex < numRow; rIndex++)
        for(int cIndex = 0; cIndex < numCol; cIndex++)                  //Steps through the table array and updates
            table[rIndex][cIndex] = newTable[rIndex][cIndex];           //its values to the values in the newTable array.
}





//*******************************************************************
//This function fills all of the elements in an array with zeroes.
//
//Pre:  table array is created and initialized.  numRow and numCol
//      are assigned values.
//
//Post: The array is zeroed out.
//*******************************************************************
void zeroOut(/*in-out*/int table[][20], /*in*/int numRow,
             /*in*/int numCol)
{
    //Initialize table array
    for(int rIndex = 0; rIndex < numRow; rIndex++)
        for(int cIndex = 0; cIndex < numCol; cIndex++)                  //Steps through array and zeroes it out
            table[rIndex][cIndex] = 0;
}
