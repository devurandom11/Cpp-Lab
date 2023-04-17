#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H

#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
 private:
  int subtreeKeyCount;

 public:
  ExtendedAVLNode(int nodeKey) : AVLNode(nodeKey) { subtreeKeyCount = 1; }

  virtual int GetSubtreeKeyCount() override { return subtreeKeyCount; }

  virtual void IncrementSubtreeKeyCount() {
    subtreeKeyCount = GetSubtreeKeyCount() + 1;
  }

  virtual void DecrementSubtreeKeyCount() {
    subtreeKeyCount = GetSubtreeKeyCount() - 1;
  }
};

#endif