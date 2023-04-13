#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include <algorithm>
#include <limits>
#include <vector>

#include "Node.h"

class BSTChecker {
 public:
  // Check if a binary search tree is valid
  static Node* CheckBSTValidity(Node* root) {
    std::vector<Node*> ancestors;
    return LastTryHelper(root, std::numeric_limits<int>::min(),
                         std::numeric_limits<int>::max(), ancestors);
  }

 private:
  // Static helper method
  static Node* LastTryHelper(Node* node, int minKey, int maxKey,
                             std::vector<Node*>& ancestors) {
    // Base cases
    if (!node) {
      return nullptr;
    }
    if (node->key < minKey || node->key > maxKey) {
      return node;
    }
    if (std::find(ancestors.begin(), ancestors.end(), node->left) !=
            ancestors.end() ||
        std::find(ancestors.begin(), ancestors.end(), node->right) !=
            ancestors.end()) {
      return node;
    }

    // Recursive case
    ancestors.push_back(node);
    Node* leftOffender =
        LastTryHelper(node->left, minKey, node->key - 1, ancestors);
    Node* rightOffender =
        LastTryHelper(node->right, node->key + 1, maxKey, ancestors);
    ancestors.pop_back();

    // Return
    return rightOffender ? rightOffender : leftOffender;
  }
};

#endif
