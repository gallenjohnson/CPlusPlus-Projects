//*******************************************************************
//  Rocket Program
//  This program draws a rocket shape on the screen based on user
//  input of three values, height, width and stages. The type of box
//  generated (ie. an outline or filled-in) is based on a check for
//  odd or even values input by the user for the box height
//  (or number of rows). Here is the general specification given user
//  input for the height of the box.....
//  Draws an outline of a box for each stage if the value for the
//  height of the box (or number of rows) is an even number.
//  Draws a filled-in box for each stage if the value for the height
//  of the box (or number of rows) is an odd number.
//  INPUT VALIDATION: Do not accept values less than 3 or greater
//  than 15 for height and width and the input for stages must be a
//  nonnegative value.
//  Project 1
//  G. Allen Johnson - 23 March, 2014
//  CS 10, Section 5393, S. Sarkar
//*******************************************************************

#include <iostream>

using namespace std;

//Function prototypes************************************************
void getDimensions(/*in-out*/int &height, /*in-out*/int &width,
                   /*in-out*/int &stages);

void drawLine(/*in*/int width);

void drawOutline(/*in*/int width);

void drawBox(/*in*/int height, /*in*/int width);

void drawPoint(/*in*/int width);

void drawMidLines(/*in*/int width);

void drawCone(/*in*/int width);

void drawRocket(/*in-out*/int height, /*in-out*/int width,
                /*in-out*/int stages);
//*******************************************************************





int main()
{
    int height = 0, width = 0, stages = 0;  //Initializing variables

    getDimensions(height, width, stages);   //Function call to get rocket dimensions

    drawRocket(height, width, stages);      //Function call to draw the rocket

    return 0;
}





//*******************************************************************
//This function prompts the user for the width and height of the
//rocket to be drawn and the number of stages/cargo bays and stores
//that data into these reference parameters to be passed back to the
//calling function.
//*******************************************************************
void getDimensions(/*out*/int &height, /*out*/int &width,
                   /*out*/int &stages)
//Pre:  None.
//Post: Values are assigned to height, width, and stages.
//      Input for all 3 variables has been validated.
//      Height to be no greater than 15 and no less than 3.
//      Width to be no greater than 15 and less than 3.
//      Stages to be no greater than 5 and no less than 1.
{
    int errorCode = 0;

    do
    {

        if (errorCode != 0)                                           //Checks if the user has already been through
        {                                                             //the loop and throws an error prompt
            switch(errorCode)                                         //Checks for an error code to tell the user
            {                                                         //exactly what value they entered incorrectly
                case 1 : cout << "You entered an incorrect height. "; //I mostly did this to stay fresh on switches
                         cout << "Your data has been reset. ";        //and to experiment with creating error codes.
                         cout << "Please try again." << endl;
                         break;
                case 2 : cout << "You entered an incorrect width. ";
                         cout << "Your data has been reset. ";
                         cout << "Please try again." << endl;
                         break;
                case 3 : cout << "You entered an incorrect number";
                         cout << " of stages. Your data has been";
                         cout << " reset. " << endl;
                         cout << "Please try again." << endl;
                         break;
                case 4 : cout << "You entered an incorrect height";
                         cout << " and width." << endl;
                         cout << "Your data has been reset. ";
                         cout << "Please try again." << endl;
                         break;
                case 5 : cout << "You entered an incorrect height ";
                         cout << "and number of stages." << endl;
                         cout << "Your data has been reset. ";
                         cout << "Please try again." << endl;
                         break;
                case 6 : cout << "You entered an incorrect width ";
                         cout << "and number of stages." << endl;
                         cout << "Your data has been reset. ";
                         cout << "Please try again." << endl;
                         break;
                case 7 : cout << "Really?  What, were you going ";
                         cout << "for the gold medal in" << endl;
                         cout << "trying to break my code? ";
                         cout << "Your data has been reset, ";
                         cout << "smart guy." << endl;
                         cout << "Try again." << endl;
                         break;
            }
            cout << endl;
        }

        //Prompts user
        cout << "Please enter a height no less than 3 and no ";
        cout << "greater than 15: ";
        cin >> height;

        //Validates input
        while (!cin)
        {
            cin.clear();
            cin.ignore();

            cout << endl;
            cout << "You entered an invalid data value." << endl;
            cout << "Please enter a height between 3 and 15: ";
            cin >> height;
        }
        if (height < 3 || height > 15)                                //Sets error code
            errorCode = 1;

        cout << endl;
        cout << "Please enter a width no less than 3 and no greater";
        cout << " than 15: ";
        cin >> width;

        //Validates input
        while (!cin)
        {
            cin.clear();
            cin.ignore();

            cout << endl;
            cout << "You entered an invalid data value." << endl;
            cout << "Please enter a width between 3 and 15: ";
            cin >> width;
        }
        if (width < 3 || width > 15)
            errorCode = 2;                                            //Sets error code

        cout << endl;
        cout << "Please enter the number of stages in the rocket no";
        cout << " less than 1" << endl;
        cout << "and no greater than 5: ";
        cin >> stages;

        //Validates input
        while (!cin)
        {
            cin.clear();
            cin.ignore();

            cout << endl;
            cout << "You entered an invalid data value." << endl;
            cout << "Please enter a number of stages between";
            cout << " 1 and 5: ";
            cin >> stages;
        }
        if (stages < 1 || stages > 5)
            errorCode = 3;                                            //Sets error code

        cout << endl;

        //Checks for multiple errors
        if ((height < 3 || height > 15) && (width < 3 || width > 15))
            errorCode = 4;                                            //Sets error code
        if ((height < 3 || height > 15) &&
            (stages < 1 || stages > 5))
            errorCode = 5;                                            //Sets error code
        if ((width < 3 || width > 15) && (stages < 1 || stages > 5))
            errorCode = 6;                                            //Sets error code
        if ((width < 3 || width > 15) &&
            (height < 3 || height > 15) &&
            (stages < 1 || stages > 5))
            errorCode = 7;                                            //Sets error code

    }while (height < 3 || height > 15 || width < 3 || width > 15 ||   //Checks user input
            stages < 1 || stages > 5);

    cout << endl;
}
//*******************************************************************





//*******************************************************************
//This function calls on drawCone and drawBox to draw the rocket
//using the height, width, and stages input from the user.
//*******************************************************************
void drawRocket(/*in-out*/int height, /*in-out*/int width,
                /*in-out*/int stages)
//Pre:  height, width, and stages are assigned.
//Post: drawCone is called twice with the value stored in width.
//      stages is used as a the count limiter in the for loop that
//      calls drawBox.
//      drawBox is called using the values stored in width and height

{
    drawCone(width);                                                  //calls drawCone
    for (int count = 0; count < stages; count++)                      //calls drawBox a number of times equal to stages
        drawBox(height, width);                                       //calls drawBox
    drawCone(width);                                                  //calls drawCone
}
//*******************************************************************





//*******************************************************************
//This function draws a single row of asterisks.
//*******************************************************************
void drawLine(/*in*/int width)
//Pre:  width has been assigned.
//Post: A number of asterisks are drawn equal to width.
//      The row is terminated by an end of line.

{
    for (int count = 0; count < width; count++)                       //for loop outputs the row of asterisks
    {
        cout << "*";
        if ((count+1) % (width+1) == width)                           //Inserts an end of line after the last
            cout << endl;                                             //asterisk has been output
    }
}
//*******************************************************************





//*******************************************************************
//This function draws a single row of empty spaces that is terminated
//on both ends with an asterisk.  Used for drawing empty boxes and
//cones.
//*******************************************************************
void drawOutline(/*in*/int width)
//Pre:  width has been assigned.
//Post: A number of spaces are output equal to width minus 2.  The
//      row of spaces is terminated on both ends with an asterisk.

{
    cout << "*";
    for (int count = 2; count < width; count++)                       //for loop outputs the row of spaces
        cout << " ";
    cout << "*" << endl;
}
//*******************************************************************





//*******************************************************************
//This function calls drawLine and/or drawOutline to draw a filled in
//box or an empty box.
//*******************************************************************
void drawBox(/*in*/int height, /*in*/int width)
//Pre:  height and width have been assigned.
//Post: A series of character rows are output that draw either a
//      filled in or empty box, depending on the height.

{
    if ( height % 2 == 1)                                             //Checks for odd numbered height and draws a
    {                                                                 //filled in box
        for (int count = 0; count < height; count++)
            drawLine(width);                                          //Call to drawLine
    }
    else                                                              //Else it outputs an empty box
    {
        drawLine(width);                                              //Call to drawLine
        for (int count = 2; count < height; count ++)
            drawOutline(width);                                       //Call to drawOutline
        drawLine(width);                                              //Call to drawLine
    }

}
//*******************************************************************





//*******************************************************************
//This function draws the point of the top and bottom cones
//*******************************************************************
void drawPoint(/*in*/int width)
//Pre:  width has been assigned.
//Post: A centered asterisk is output if the width is odd, otherwise
//      2 centered asterisks are output.

{
    if (width % 2 == 0)                                               //Checks for even width
    {
        for (int count = 1; count < (width / 2); count++)             //Outputs spaces to center the point
            cout << " ";
        cout << "**" << endl;                                         //Outputs 2 points for an even width
    }
    else
    {
        for (int count = 0; count < (width / 2); count++)             //Outputs spaces to center the point
            cout << " ";
        cout << "*" << endl;                                          //Outputs 1 point for an odd width
    }
}
//*******************************************************************





//*******************************************************************
//This function draws the middle lines of the top and bottom cones.
//*******************************************************************
void drawMidLines(/*in*/int width)
//Pre:  width has been assigned
//Post: Outputs the rows of characters after the point of the cone.

{
    int midPoint = ((width + 1) / 2);                                 //Establishes the middle of the cone
    int leadSpace = midPoint - 2;                                     //Determines the max white space to the
                                                                      //center of the cone for horizontal spacing
    int spacing = 1;                                                  //Sets the blank spacing as odd between
                                                                      //the asterisks for an odd width row
    if (width % 2 == 0)
        spacing++;                                                    //Changes the spacing to evens for an even
                                                                      //width row
    for (int spaceCount = spacing; spaceCount < width;                //Loops while the spaces between asterisks
         spaceCount += 2)                                             //doesn't exceed the width minus 2
    {
        for (int count = leadSpace; count > 0; count--)               //Outputs the blank spaces for horizontal
            cout << " ";                                              //spacing

        drawOutline(spaceCount + 2);                                  //Calls drawOutline

        leadSpace --;                                                 //Decrements the horizontal blank spacing
    }
}
//*******************************************************************





//*******************************************************************
//This function calls drawPoint and drawMidLines to draw the top
//and bottom cones.
//*******************************************************************
void drawCone(/*in*/int width)
//Pre:  width has been assigned
//Post: Calls drawPoint and drawMidLines to output a point and a
//      series of asterisk terminated, blank-space rows to draw a
//      cone.

{
    drawPoint(width);
    drawMidLines(width);
}
//*******************************************************************



