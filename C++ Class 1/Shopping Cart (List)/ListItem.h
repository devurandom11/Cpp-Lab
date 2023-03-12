#ifndef LISTITEMH
#define LISTITEMH

#include <string>


class ListItem
{
public:
   ListItem();

   ListItem(std::string itemInit);

   // Print this node
   void PrintNodeData();

private:
   std::string item;
};

#endif
