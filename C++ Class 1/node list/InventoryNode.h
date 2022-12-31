#include <iostream>
#include <string>

class InventoryNode
{
private:
    std::string item;
    int numberOfItems;
    InventoryNode *nextNodeRef;

public:
    // Constructors
    InventoryNode() : item{}, numberOfItems{}, nextNodeRef{nullptr} {}
    InventoryNode(std::string itemInit, int numberOfItemsInit) : item{std::move(itemInit)}, numberOfItems{numberOfItemsInit}, nextNodeRef{nullptr} {}
    InventoryNode(std::string itemInit, int numberOfItemsInit, InventoryNode &nextLoc) : item{std::move(itemInit)}, numberOfItems{numberOfItemsInit}, nextNodeRef{&nextLoc} {}

    // Insert a node at the front of the linked list (after the dummy head node)
    void InsertAtFront(InventoryNode *headNode, InventoryNode *newNode)
    {
        newNode->nextNodeRef = headNode->GetNext();
        headNode->nextNodeRef = newNode;
    }

    // Get the next node
    InventoryNode *GetNext() const
    {
        return nextNodeRef;
    }

    // Print node data
    void PrintNodeData() const
    {
        std::cout << numberOfItems << " " << item << '\n';
    }
};
