#include <iostream>
#include <string>
#include "VendingMachine.h"
using namespace std;

// Default constructor setting inventory to 20
VendingMachine::VendingMachine()
{
    bottles = 20;
}
// Reduce inventory
void VendingMachine::Purchase(int amount)
{
    bottles -= amount;
}
// Accessor Function
int VendingMachine::GetInventory() const
{
    return bottles;
}
// Increase inventory
void VendingMachine::Restock(int amount)
{
    bottles += amount;
}

void VendingMachine::Report() const
{
    cout << "Inventory: " << VendingMachine::GetInventory() << " bottles" << endl;
}