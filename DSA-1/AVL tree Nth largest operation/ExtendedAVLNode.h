#ifndef EXTENDEDAVLNODE_H
#define EXTENDEDAVLNODE_H

#include "AVLNode.h"

class ExtendedAVLNode : public AVLNode {
 private:
  int subtreeKeyCount;

 public:
  ExtendedAVLNode(int nodeKey) : AVLNode(nodeKey) { subtreeKeyCount = 1; }

  virtual int GetSubtreeKeyCount() override { return subtreeKeyCount; }

  // Your code here
};

#endif