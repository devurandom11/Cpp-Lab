#include <iostream>
#include <string>

class InventoryNode {
private:
  std::string item;
  int numberOfItems;
  InventoryNode *nextNodeRef;

public:
  // Constructor
  InventoryNode() {
    this->item = "";
    this->numberOfItems = 0;
    this->nextNodeRef = NULL;
  }

  // Constructor
  InventoryNode(std::string itemInit, int numberOfItemsInit) {
    this->item = itemInit;
    this->numberOfItems = numberOfItemsInit;
    this->nextNodeRef = NULL;
  }

  // Constructor
  InventoryNode(std::string itemInit, int numberOfItemsInit,
                InventoryNode nextLoc) {
    this->item = itemInit;
    this->numberOfItems = numberOfItemsInit;
    this->nextNodeRef = &nextLoc;
  }

  // TODO: Define InsertAtFront() member function that inserts a node at the
  //       front of the linked list (after the dummy head node)

  void InsertAtFront(InventoryNode *headNode, InventoryNode *newNode) {
    newNode->nextNodeRef = headNode->nextNodeRef;
    headNode->nextNodeRef = newNode;
  }

  // Get the next node
  InventoryNode *GetNext() { return this->nextNodeRef; }

  // Print node data
  void PrintNodeData() {
    std::cout << this->numberOfItems << " " << this->item << std::endl;
  }
};
