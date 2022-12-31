#include <iostream>
using namespace std;
#include "ItemToPurchase.h"
#include <vector>
// Default Constructor
ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

// Public Methods
void ItemToPurchase::SetName(string name)
{
    this->itemName = name;
}

string ItemToPurchase::GetName() const
{
    return itemName;
}

void ItemToPurchase::SetPrice(int price)
{
    this->itemPrice = price;
}

int ItemToPurchase::GetPrice() const
{
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity)
{
    this->itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const
{
    return itemQuantity;
}

void PrintTotal(vector<ItemToPurchase> items)
{
    unsigned int i;
    int total = 0;

    cout << "TOTAL COST" << endl;
    for (i = 0; i < items.size(); i++)
    {
        cout << items[i].GetName() << " " << items[i].GetQuantity() << " @ $" << items[i].GetPrice() << " = $" << items[i].GetQuantity() * items[i].GetPrice() << endl;
        total += items[i].GetQuantity() * items[i].GetPrice();
    }
    cout << endl;
    cout << "Total: $" << total << endl;
}