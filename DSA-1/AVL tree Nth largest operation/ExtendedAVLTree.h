#ifndef EXTENDEDAVLTREE_H
#define EXTENDEDAVLTREE_H

#include "AVLTree.h"
#include "ExtendedAVLNode.h"

class ExtendedAVLTree : public AVLTree {
 protected:
  // Each node in an ExtendedAVLTree is an ExtendedAVLNode
  virtual BSTNode* MakeNewNode(int key) override {
    return new ExtendedAVLNode(key);
  }

  // Your code here
  virtual AVLNode* Rebalance(AVLNode* node) override {
    // Call the parent class's Rebalance method
    AVLNode* newRoot = AVLTree::Rebalance(node);

    // Update subtreeKeyCount for the current node
    ExtendedAVLNode* extendedNode = static_cast<ExtendedAVLNode*>(node);
    int leftCount = 0;
    int rightCount = 0;
    if (extendedNode->GetLeft()) {
      leftCount = static_cast<ExtendedAVLNode*>(extendedNode->GetLeft())
                      ->GetSubtreeKeyCount();
    }

    if (extendedNode->GetRight()) {
      rightCount = static_cast<ExtendedAVLNode*>(extendedNode->GetRight())
                       ->GetSubtreeKeyCount();
    }

    extendedNode->SetSubtreeKeyCount(leftCount + rightCount + 1);
    return newRoot;
  }

 public:
  virtual int GetNthKey(int n) override {
    // Your code here (remove placeholder line below)
    if (n < 0 || n >= ((ExtendedAVLNode*)root)->GetSubtreeKeyCount()) {
      throw std::out_of_range("n is out of range");
    }

    ExtendedAVLNode* currentNode = (ExtendedAVLNode*)root;
    while (currentNode) {
      int leftSubtreeKeyCount =
          currentNode->GetLeft()
              ? ((ExtendedAVLNode*)currentNode->GetLeft())->GetSubtreeKeyCount()
              : 0;
      if (n < leftSubtreeKeyCount) {
        currentNode = (ExtendedAVLNode*)currentNode->GetLeft();
      } else if (n == leftSubtreeKeyCount) {
        return currentNode->GetKey();
      } else {
        n -= (leftSubtreeKeyCount + 1);
        currentNode = (ExtendedAVLNode*)currentNode->GetRight();
      }
    }
    return -1;
  }
};

#endif