#include "ListItem.h"
#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    // TODO: Declare a list called shoppingList of type ListItem
    list<ListItem> shoppingList;
    string item;

    // TODO: Read inputs (items) and add them to the shoppingList list
    //       Read inputs until a -1 is input
    getline(cin, item);
    while (item != "-1")
    {
        shoppingList.push_back(item);
        getline(cin, item);
    }
    // TODO: Print the shoppingList list using the PrintNodeData() function
    for (unsigned int i = 0; i < shoppingList.size();)
    {
        shoppingList.front().PrintNodeData();
        shoppingList.pop_front();
    }
    return 0;
}