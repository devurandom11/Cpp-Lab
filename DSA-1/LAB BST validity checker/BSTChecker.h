#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include <iostream>
#include <limits>

#include "Node.h"

class BSTChecker {
 private:
  // Declare constexpr variables for maximum and minimum int values
  static constexpr int MAX = std::numeric_limits<int>::max();
  static constexpr int MIN = std::numeric_limits<int>::min();

  static Node* DFSHelper(Node* node, int minKey, int maxKey) {
    // Perform a DFS traversal of the tree, checking the validity of each node
    if (!node) {
      return nullptr;
    }

    if (node->key < minKey || node->key > maxKey) {
      return node;
    }

    Node* leftOffender = DFSHelper(node->left, minKey, node->key - 1);
    Node* rightOffender = DFSHelper(node->right, node->key + 1, maxKey);

    return leftOffender ? leftOffender : rightOffender;
  }

 public:
  static Node* CheckBSTValidity(Node* root) {
    return DFSHelper(root, MIN, MAX);
  }
};

#endif
