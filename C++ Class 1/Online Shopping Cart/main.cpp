#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "ItemToPurchase.h"

int main()
{
    // Variable declarations
    string itemName;
    int itemPrice, itemQuantity;
    vector<ItemToPurchase> itemVec(2);
    unsigned int i;

    // Prompt user for items to purchase
    for (i = 0; i < itemVec.size(); i++)
    {
        // Get user info
        cout << "Item " << i + 1 << endl;
        cout << "Enter the item name:" << endl;
        getline(cin, itemName);
        cout << "Enter the item price:" << endl;
        cin >> itemPrice;
        cout << "Enter the item quantity:" << endl;
        cin >> itemQuantity;
        cout << endl;
        // Create object
        itemVec[i] = ItemToPurchase();
        itemVec[i].SetName(itemName);
        itemVec[i].SetPrice(itemPrice);
        itemVec[i].SetQuantity(itemQuantity);
        // Use before prompting for next item
        cin.ignore();
    }

    // Print results
    PrintTotal(itemVec);

    return 0;
}