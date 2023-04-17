#ifndef BSTNODEVISITOR_H
#define BSTNODEVISITOR_H

#include "BSTNode.h"

class BSTNodeVisitor {
 public:
  // Returns true to continue traversal, false to terminate
  virtual bool Visit(BSTNode* node) = 0;
};

#endif