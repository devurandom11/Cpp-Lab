#include "ItemNode.h"

int main()
{
    ItemNode *headNode; // Create intNode objects
    ItemNode *currNode;
    ItemNode *lastNode;

    string item;
    int i;
    int input;

    // Front of nodes list
    headNode = new ItemNode();
    lastNode = headNode;

    cin >> input;

    for (i = 0; i < input; i++)
    {
        cin >> item;
        currNode = new ItemNode(item);
        lastNode->InsertAtEnd(currNode);
        lastNode = currNode;
    }

    // Print linked list
    currNode = headNode->GetNext();
    while (currNode != NULL)
    {
        currNode->PrintNodeData();
        currNode = currNode->GetNext();
    }
}