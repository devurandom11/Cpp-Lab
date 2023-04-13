#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>

#include "Node.h"

class BSTChecker {
 private:
  // Static helper method
  static Node* LastTryHelper(Node* node, int minKey, int maxKey,
                             std::vector<Node*>& ancestors) {
    // Base cases
    if (!node) return nullptr;
    if (node->key < minKey || node->key > maxKey) return node;
    if (std::find(ancestors.begin(), ancestors.end(), node->left) !=
            ancestors.end() ||
        std::find(ancestors.begin(), ancestors.end(), node->right) !=
            ancestors.end())
      return node;

    // Recursive case
    // Add to set of ancestors
    ancestors.push_back(node);
    Node* leftOffender =
        LastTryHelper(node->left, minKey, node->key - 1, ancestors);
    if (leftOffender) return leftOffender;

    Node* rightOffender =
        LastTryHelper(node->right, node->key + 1, maxKey, ancestors);

    // Remove from set of ancestors
    ancestors.pop_back();

    // Return
    return rightOffender ? rightOffender : leftOffender;
  }

 public:
  // Check if a binary search tree is valid
  static Node* CheckBSTValidity(Node* root) {
    std::vector<Node*> ancestors;
    return LastTryHelper(root, std::numeric_limits<int>::min(),
                         std::numeric_limits<int>::max(), ancestors);
  }
};

#endif
