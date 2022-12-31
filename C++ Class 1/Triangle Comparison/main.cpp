#include <iostream>
#include "Triangle.h"
using namespace std;

int main()
{
    Triangle triangle1;
    Triangle triangle2;
    double base;
    double height;
    double triangle1Area;
    double triangle2Area;

    // TODO: Read and set base and height for triangle1 (use SetBase() and SetHeight())
    cin >> base;
    cin >> height;
    triangle1.SetBase(base);
    triangle1.SetHeight(height);

    // TODO: Read and set base and height for triangle2 (use SetBase() and SetHeight())
    cin >> base;
    cin >> height;
    triangle2.SetBase(base);
    triangle2.SetHeight(height);

    cout << "Triangle with smaller area:" << endl;

    // TODO: Determine smaller triangle (use GetArea())
    //       and output smaller triangle's info (use PrintInfo())
    triangle1Area = triangle1.GetArea();
    triangle2Area = triangle2.GetArea();
    if (triangle1Area >= triangle2Area)
    {
        triangle2.PrintInfo();
    }
    else
    {
        triangle1.PrintInfo();
    }

    return 0;
}