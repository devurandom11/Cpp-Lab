#ifndef VENDINGMACHINE_H_
#define VENDINGMACHINE_H_
#include <iostream>
using namespace std;
// Declare the VendingMachine class here
class VendingMachine
{
public:
    VendingMachine();
    void Purchase(int amount);
    int GetInventory() const;
    void Restock(int amount);
    void Report() const;

private:
    int bottles;
};
// Do not remove the line below
#endif /* VENDINGMACHINE_H_ */