#include "ListItem.h"
#include <iostream>

ListItem::ListItem()
{
    item = "";
}

ListItem::ListItem(string itemInit)
{
    item = itemInit;
}

// Print this node
void ListItem::PrintNodeData()
{
    cout << item << endl;
}