#ifndef BSTNODEVECTORVISITOR_H
#define BSTNODEVECTORVISITOR_H

#include <unordered_set>
#include <vector>

#include "BSTNodeVisitor.h"

// BSTNodeVectorVisitor stores a vector of BSTNode pointers. Each call to the
// Visit() function pushes the node to the back of the vector.
// BSTNodeVectorVisitor also checks for duplicate node visits. Since a single
// BSTNodeVectorVisitor instance is meant to be used for at most one traversal
// through a BST, visiting the same node twice implies that a circular
// reference exists.
class BSTNodeVectorVisitor : public BSTNodeVisitor {
private:
  // visitedSet is used to ensure that the exact same node instance is not
  // visited more than once.
  std::unordered_set<BSTNode *> visitedSet;

  bool hasCircRef;

public:
  std::vector<BSTNode *> visitedNodes;

  BSTNodeVectorVisitor() { hasCircRef = false; }

  // Returns true if a circular reference was discovered when visiting a node,
  // false otherwise.
  bool HasCircularReference() const { return hasCircRef; }

  virtual bool Visit(BSTNode *node) {
    // Check if the node was already visited. If so, the tree has a circular
    // reference.
    if (visitedSet.count(node) > 0) {
      // Set hasCircRef to true
      hasCircRef = true;

      // Return false to stop infinite traversal
      return false;
    }

    // Add node to set and vector
    visitedSet.insert(node);
    visitedNodes.push_back(node);

    // Return true to continue traversal
    return true;
  }
};

#endif
