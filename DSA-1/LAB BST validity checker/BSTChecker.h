#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include <iostream>

#include "Node.h"

class BSTChecker {
 public:
  static Node* CheckBSTValidity(Node* rootNode) {
    Node* violation = nullptr;
    // Check if the left subtree is valid
    if (rootNode->left) {
      // Traverse the tree to the rightmost node
      Node* rightmost = rootNode->left->right;
      while (rightmost && rightmost->right) {
        rightmost = rightmost->right;
      }
      // If the rightmost node is greater than the root, then there is a
      // violation
      if (rightmost && rightmost->key > rootNode->key) {
        violation = rightmost;
      } else {
        // Otherwise, check the left subtree
        violation = CheckBSTValidity(rootNode->left);
      }
    }
    // Check if the right subtree is valid
    if (rootNode->right && !violation) {
      // Traverse the tree to the leftmost node
      Node* leftmost = rootNode->right->left;
      while (leftmost && leftmost->left) {
        leftmost = leftmost->left;
      }
      // If the leftmost node is less than the root, then there is a violation
      if (leftmost && leftmost->key < rootNode->key) {
        violation = leftmost;
      } else {
        // Otherwise, check the right subtree
        violation = CheckBSTValidity(rootNode->right);
      }
    }

    return violation;
  }
};

#endif