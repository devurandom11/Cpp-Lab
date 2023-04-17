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
    ExtendedAVLNode* extendedNode = (ExtendedAVLNode*)node;
    int leftCount = 0;
    int rightCount = 0;
    if (extendedNode->GetLeft()) {
      leftCount =
          ((ExtendedAVLNode*)extendedNode)->GetLeft()->GetSubtreeKeyCount();
    }

    if (extendedNode->GetRight()) {
      rightCount =
          ((ExtendedAVLNode*)extendedNode)->GetRight()->GetSubtreeKeyCount();
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
      ExtendedAVLNode* extendedNode = (ExtendedAVLNode*)parentNode;
      int leftCount = extendedNode->GetLeft() ? ((ExtendedAVLNode*)extendedNode)
                                                    ->GetLeft()
                                                    ->GetSubtreeKeyCount()
                                              : 0;
      int rightCount = extendedNode->GetRight()
                           ? ((ExtendedAVLNode*)extendedNode)
                                 ->GetRight()
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
    if (n < 0 || n >= ((ExtendedAVLNode*)root)->GetSubtreeKeyCount()) {
      return -1;
    }

    ExtendedAVLNode* currentNode = (ExtendedAVLNode*)root;
    while (currentNode) {
      int leftSubtreeKeyCount =
          currentNode->GetLeft()
              ? ((ExtendedAVLNode*)currentNode)->GetLeft()->GetSubtreeKeyCount()
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