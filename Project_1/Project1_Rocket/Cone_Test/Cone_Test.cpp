#include <iostream>

using namespace std;

void drawOutline(/*in*/int width);

void drawPoint(/*in*/int width);

void drawMidLines(/*in*/int width);

void drawCone(/*in*/int width);

int main()
{
    int repeat = 1;
    while (repeat == 1)
    {
        int width;
        cout << "Enter Cone Width: ";
        cin >> width;
        cout << endl << endl;

        drawCone(width);

        cout << "Press 1 to draw again: ";
        cin >> repeat;
        cout << endl << endl;
    }


    return 0;
}





void drawOutline(/*in*/int width)
{
    cout << "*";
    for (int count = 2; count < width; count++)
        cout << " ";
    cout << "*" << endl;
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
    int leadSpace = midPoint - 2;
    int spacing = 1;

    if (width % 2 == 0)
        spacing++;

    for (int spaceCount = spacing; spaceCount < width; spaceCount += 2)
    {
        for (int count = leadSpace; count > 0; count--)
            cout << " ";

        drawOutline(spaceCount + 2);

        leadSpace --;
    }
}





void drawCone(/*in*/int width)
{
    drawPoint(width);
    drawMidLines(width);
    //drawOutline(width);
}



