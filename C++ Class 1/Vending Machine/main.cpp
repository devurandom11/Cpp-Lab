#include <iostream>
#include "VendingMachine.h"
using namespace std;

int main()
{
    int purchaseAmount;
    int restockAmount;
    VendingMachine machine;

    cin >> purchaseAmount >> restockAmount;

    machine.Purchase(purchaseAmount);
    machine.Restock(restockAmount);
    machine.Report();

    return 0;
}