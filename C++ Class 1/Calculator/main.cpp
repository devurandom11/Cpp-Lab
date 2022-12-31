#include <iostream>
#include <iomanip>
#include "Calculator.h"

using namespace std;

int main()
{
    Calculator calc;
    double num1;
    double num2;

    cin >> num1;
    cin >> num2;

    cout << fixed << setprecision(1);
    // 1. The initial value
    cout << calc.GetValue() << endl;

    // 2. The value after adding num1
    calc.Add(num1);
    cout << calc.GetValue() << endl;

    // 3. The value after multiplying by 3
    calc.Multiply(3);
    cout << calc.GetValue() << endl;

    // 4. The value after subtracting num2
    calc.Subtract(num2);
    cout << calc.GetValue() << endl;

    // 5. The value after dividing by 2
    calc.Divide(2);
    cout << calc.GetValue() << endl;

    // 6. The value after calling the clear() method
    calc.Clear();
    cout << calc.GetValue() << endl;

    return 0;
}