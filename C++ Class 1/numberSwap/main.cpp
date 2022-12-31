#include "Number.h"
#include <iostream>
using namespace std;

void Swap(Number &num1, Number &num2)
{ // num1 and num2 are passed by reference
    // int tmpNum = num1.GetNum();
    num1.SetNum(num2.GetNum() + num1.GetNum());
    num2.SetNum(num1.GetNum() - num2.GetNum());
    num1.SetNum(num1.GetNum() - num2.GetNum());
}

int main()
{
    Number num1 = Number(19);
    Number num2 = Number(178);

    Swap(num1, num2);
    cout << "num1 = " << num1.GetNum() << ", num2 = " << num2.GetNum() << endl;

    return 0;
}