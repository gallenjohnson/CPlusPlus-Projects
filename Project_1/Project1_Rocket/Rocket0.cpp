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
#include <iomanip>

using namespace std;
/*setw */

// Function prototypes
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


int main()
{
    int height = 0, width = 0, stages = 0;
    getDimensions(height, width, stages);
    drawRocket(height, width, stages);

    return 0;
}



void getDimensions(/*in-out*/int &height, /*in-out*/int &width,
                   /*in-out*/int &stages)
{
    int count = 0;

    do
    {
        if (count != 0)
        {
            count = 0;
            cout << "You entered an invalid data value.  Please ";
            cout << "enter a height" << endl;
            cout << "and width no less than 3 and no greater";
            cout << " than 15." << endl << endl;
        }
        cout << "Please enter a height no less than 3 and no ";
        cout << "greater than 15: ";
        cin >> height;
        cout << "Please enter a width no less than 3 and no greater";
        cout << " than 15: ";
        cin >> width;
        cout << "Please enter the number of stages in the rocket no";
        cout << " less than 1" << endl;
        cout << "and no greater than 5: ";
        cin >> stages;
        cout << endl;
        count = 1;
    }while (height < 3 || height > 15 || width < 3 || width > 15 ||
            stages < 1 || stages > 5);
}





void drawRocket(/*in-out*/int height, /*in-out*/int width,
                /*in-out*/int stages)
{
    drawCone(width);
    for (int count = 0; count < stages; count++)
        drawBox(height, width);
    drawCone(width);
}





void drawLine(/*in*/int width)
{
    for (int count = 0; count < width; count++)
    {
        cout << "*";
        if ((count+1) % (width+1) == width)
            cout << endl;
    }
}





void drawOutline(/*in*/int width)
{
    cout << "*";
    for (int count = 2; count < width; count++)
        cout << " ";
    cout << "*" << endl;
}





void drawBox(/*in*/int height, /*in*/int width)
{
    if ( height % 2 == 1)
    {
        for (int count = 0; count < height; count++)
            drawLine(width);
    }
    else
    {
        drawLine(width);
        for (int count = 2; count < height; count ++)
            drawOutline(width);
        drawLine(width);
    }

}





void drawPoint(/*in*/int width)
{
    if (width % 2 == 0)
    {
        for (int count = 1; count < (width / 2); count++)
            cout << " ";
        cout << "**" << endl;
    }
    else
    {
        for (int count = 0; count < (width / 2); count++)
            cout << " ";
        cout << "*" << endl;
    }
}





void drawMidLines(/*in*/int width)
{
    int midPoint = ((width + 1) / 2);
    int nearPoint = ((midPoint + 1) / 2);
    int quarterPoint = midPoint - nearPoint;
    int farPoint = midPoint + quarterPoint;

    if (width % 2 == 0)
    {
        farPoint++;
    }
    for (int count = 1; count < nearPoint; count++)
        cout << " ";
    drawOutline(farPoint-nearPoint+1);

}





void drawCone(/*in*/int width)
{
    drawPoint(width);
    drawMidLines(width);
    drawOutline(width);
}



