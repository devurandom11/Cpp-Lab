#ifndef LISTITEMH
#define LISTITEMH

#include <string>

using namespace std;

class ListItem
{
public:
   ListItem();

   ListItem(string itemInit);

   // Print this node
   void PrintNodeData();

private:
   string item;
};

#endif