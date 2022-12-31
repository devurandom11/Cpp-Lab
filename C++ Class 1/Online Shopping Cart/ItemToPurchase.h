#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#include <vector>
#include <string>
using namespace std;

class ItemToPurchase
{
public:
    // Default constructor
    ItemToPurchase();
    void SetName(string name);
    string GetName() const;
    void SetPrice(int price);
    int GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;

private:
    string itemName;
    int itemPrice;
    int itemQuantity;
};

void PrintTotal(vector<ItemToPurchase> items);

#endif