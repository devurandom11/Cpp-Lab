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

  virtual bool RemoveNode(BSTNode* nodeToRemove) override {
    // Call the parent class's RemoveAVLNode method
    bool result = AVLTree::RemoveNode(nodeToRemove);

    // Update subtreeKeyCount for ancestors of the removed node
    BSTNode* parentNode = nodeToRemove->GetParent();
    while (parentNode) {
      ExtendedAVLNode* extendedNode = static_cast<ExtendedAVLNode*>(parentNode);
      int leftCount =
          extendedNode->GetLeft()
              ? static_cast<ExtendedAVLNode*>(extendedNode->GetLeft())
                    ->GetSubtreeKeyCount()
              : 0;
      int rightCount =
          extendedNode->GetRight()
              ? static_cast<ExtendedAVLNode*>(extendedNode->GetRight())
                    ->GetSubtreeKeyCount()
              : 0;
      extendedNode->SetSubtreeKeyCount(leftCount + rightCount + 1);
      parentNode = parentNode->GetParent();
    }

    return result;
  }

 public:
  virtual int GetNthKey(int n) override {
    // Your code here (remove placeholder line below)
    return 0;
  }
};

#endif