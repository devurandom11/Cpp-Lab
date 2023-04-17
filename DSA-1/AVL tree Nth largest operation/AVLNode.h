#ifndef AVLNODE_H
#define AVLNODE_H

#include "BSTNode.h"

class AVLNode : public BSTNode {
 private:
  int height;

  virtual int GetLeftHeight() {
    AVLNode* leftChild = (AVLNode*)GetLeft();
    if (leftChild) {
      return leftChild->height;
    }
    return -1;
  }

  virtual int GetRightHeight() {
    AVLNode* rightChild = (AVLNode*)GetRight();
    if (rightChild) {
      return rightChild->height;
    }
    return -1;
  }

 public:
  // Constructs the AVLNode with the given key. Left, right, and parent
  // pointers are assigned with nullptr and height is assigned with 0.
  AVLNode(int nodeKey) : BSTNode(nodeKey) { height = 0; }

  virtual ~AVLNode() {}

  // Calculate this node's balance factor, defined as:
  // height(left subtree) - height(right subtree)
  virtual int GetBalance() {
    // Get height of left and right subtrees
    int leftHeight = GetLeftHeight();
    int rightHeight = GetRightHeight();

    // Calculate the balance factor.
    return leftHeight - rightHeight;
  }

  virtual int GetHeight() { return height; }

  virtual void SetLeft(BSTNode* newLeftChild) override {
    // Call parent class's SetLeft() first
    BSTNode::SetLeft(newLeftChild);

    // Update height
    UpdateHeight();
  }

  virtual void SetRight(BSTNode* newRightChild) override {
    // Call parent class's SetRight() first
    BSTNode::SetRight(newRightChild);

    // Update height
    UpdateHeight();
  }

  // Recalculate the current height of the subtree rooted at
  // the node, usually called after a subtree has been
  // modified.
  virtual void UpdateHeight() {
    // Get height of left and right subtrees
    int leftHeight = GetLeftHeight();
    int rightHeight = GetRightHeight();

    // Assign height with greater of the two, plus one
    height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
  }
};

#endif