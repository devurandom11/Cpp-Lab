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
  virtual void InsertNode(BSTNode* node) override {
    // Call parent
    AVLTree::InsertNode(node);

    // Update subtree key counts
    while (node) {
      ((ExtendedAVLNode*)node)->IncrementSubtreeKeyCount();
      node = node->GetParent();
    }
  }

  virtual bool RemoveNode(BSTNode* node) override {
    // Call parent
    BSTNode* parent = node->GetParent();

    bool removed = AVLTree::RemoveNode(node);

    if (removed) {
      while (parent) {
        ((ExtendedAVLNode*)parent)->DecrementSubtreeKeyCount();
        parent = parent->GetParent();
      }
    }
    return removed;
  }

 public:
  virtual int GetNthKey(int n) override {
    // Your code here (remove placeholder line below)
    return 0;
  }
};

#endif