#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include <iostream>
#include <limits>
#include <unordered_set>

#include "Node.h"

class BSTChecker {
 private:
  // Convenience constants
  static constexpr int MAX = std::numeric_limits<int>::max();
  static constexpr int MIN = std::numeric_limits<int>::min();

  static Node* DFSHelper(Node* node, int minKey, int maxKey,
                         std::unordered_set<Node*>& visited, Node* parent) {
    if (!node) {
      return nullptr;
    }

    // Check if the node has already been visited (ancestor detection)
    if (visited.find(node) != visited.end()) {
      return node;
    }
    visited.insert(node);

    if (node->key < minKey || node->key > maxKey) {
      return node;
    }

    // Check if left or right child is pointing to the parent
    if ((node->left && node->left == parent) ||
        (node->right && node->right == parent)) {
      return node;
    }

    Node* leftOffender =
        DFSHelper(node->left, minKey, node->key - 1, visited, node);
    Node* rightOffender =
        DFSHelper(node->right, node->key + 1, maxKey, visited, node);

    return leftOffender ? leftOffender : rightOffender;
  }

 public:
  static Node* CheckBSTValidity(Node* root) {
    // Pass in a set for memoization
    std::unordered_set<Node*> visited;
    return DFSHelper(root, MIN, MAX, visited, nullptr);
  }
};

#endif
