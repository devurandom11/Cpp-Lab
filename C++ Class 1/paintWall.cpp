#include <iostream>
#include <iomanip> // needed for setprecision() and fixed
#include <cmath>   // needed for ceil()
using namespace std;

int main()
{
    /* Type your code here. */
    double wallHeight;
    double wallWidth;
    double costPaint;
    const double PAINT_GALLON_SIZE = 350;
    cin >> wallHeight;
    cin >> wallWidth;
    cin >> costPaint;

    double wallArea = wallHeight * wallWidth;
    double paintNeeded = wallArea / PAINT_GALLON_SIZE;
    int cansNeeded = ceil(paintNeeded);
    double paintCost = cansNeeded * costPaint;
    double salesTax = .07 * paintCost;
    double totalCost = paintCost + salesTax;

    cout << "Wall area: " << fixed << setprecision(1) << wallArea << " sq ft" << endl;
    cout << "Paint needed: " << fixed << setprecision(3) << paintNeeded << " gallons" << endl;
    cout << "Cans needed: " << fixed << setprecision(0) << cansNeeded << " can(s)" << endl;
    cout << "Paint cost: $" << fixed << setprecision(2) << paintCost << endl;
    cout << "Sales tax: $" << salesTax << endl;
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}
