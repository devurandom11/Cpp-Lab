#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H

#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
 private:
  int subtreeKeyCount;

 public:
  ExtendedAVLNode(int nodeKey) : AVLNode(nodeKey) { subtreeKeyCount = 1; }

  virtual int GetSubtreeKeyCount() override { return subtreeKeyCount; }

  void SetSubtreeKeyCount(int subtreeKeyCount) {
    this->subtreeKeyCount = subtreeKeyCount;
  }

  virtual void UpdateSubtreeKeyCount() {
    int count = 1;
    if (GetLeft()) {
      count += static_cast<ExtendedAVLNode*>(GetLeft())->GetSubtreeKeyCount();
    }
    if (GetRight()) {
      count += static_cast<ExtendedAVLNode*>(GetRight())->GetSubtreeKeyCount();
    }
    SetSubtreeKeyCount(count);
  }
};

#endif