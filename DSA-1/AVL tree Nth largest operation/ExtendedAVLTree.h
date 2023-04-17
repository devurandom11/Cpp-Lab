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

 public:
  virtual int GetNthKey(int n) override {
    // Your code here (remove placeholder line below)
    return 0;
  }
};

#endif