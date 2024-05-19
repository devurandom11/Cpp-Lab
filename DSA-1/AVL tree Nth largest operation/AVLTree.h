#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
#include "BinarySearchTree.h"

class AVLTree : public BinarySearchTree {
protected:
  virtual void InsertNode(BSTNode *node) override {
    // AVL insertion starts with the standard BST insertion
    BinarySearchTree::InsertNode(node);

    // Then rebalancing occurs along a path from the new node's parent up
    // to the root.
    node = (AVLNode *)node->GetParent();
    while (node) {
      Rebalance((AVLNode *)node);
      node = (AVLNode *)node->GetParent();
    }
  }

  virtual BSTNode *MakeNewNode(int key) override { return new AVLNode(key); }

  // Updates the given node's height and rebalances the subtree if the
  // balance factor is now -2 or +2. Rebalancing is done by performing one or
  // two rotations. Returns the subtree's new root if a rotation occurred, or
  // the node itself if no rebalancing was required.
  virtual AVLNode *Rebalance(AVLNode *node) {
    // First update the height of this node.
    node->UpdateHeight();

    // Check for an imbalance.
    if (node->GetBalance() == -2) {
      // The subtree is too big to the right.
      AVLNode *rightChild = (AVLNode *)node->GetRight();
      if (rightChild->GetBalance() == 1) {
        // Double rotation case. First do a right rotation
        // on the right child.
        RotateRight(node->GetRight());
      }

      // A left rotation will now make the subtree balanced.
      return (AVLNode *)RotateLeft(node);
    } else if (node->GetBalance() == 2) {
      // The subtree is too big to the left
      AVLNode *leftChild = (AVLNode *)node->GetLeft();
      if (leftChild->GetBalance() == -1) {
        // Double rotation case. First do a left rotation
        // on the left child.
        RotateLeft(node->GetLeft());
      }

      // A right rotation will now make the subtree balanced.
      return (AVLNode *)RotateRight(node);
    }

    // No imbalance, so just return the original node.
    return node;
  }

  virtual bool RemoveAVLNode(AVLNode *nodeToRemove) {
    if (!nodeToRemove) {
      return false;
    }

    // Parent needed for rebalancing.
    BSTNode *parent = nodeToRemove->GetParent();

    // Case 1: Internal node with 2 children
    if (nodeToRemove->GetLeft() && nodeToRemove->GetRight()) {
      // Find successor
      BSTNode *successorNode = nodeToRemove->GetRight();
      while (successorNode->GetLeft()) {
        successorNode = successorNode->GetLeft();
      }

      // Copy the key from the node
      nodeToRemove->SetKey(successorNode->GetKey());

      // Recursively remove successor
      RemoveNode(successorNode);

      // Nothing left to do since the recursive call will have rebalanced
      return true;
    }

    // Case 2: Root node (with 1 or 0 children)
    else if (nodeToRemove == root) {
      if (nodeToRemove->GetLeft()) {
        root = (AVLNode *)nodeToRemove->GetLeft();
      } else {
        root = (AVLNode *)nodeToRemove->GetRight();
      }

      if (root) {
        root->SetParentToNull();
      }

      delete nodeToRemove;
      return true;
    }

    // Case 3: Internal with left child only
    else if (nodeToRemove->GetLeft()) {
      parent->ReplaceChild(nodeToRemove, nodeToRemove->GetLeft());
    }

    // Case 4: Internal with right child only OR leaf
    else {
      parent->ReplaceChild(nodeToRemove, nodeToRemove->GetRight());
    }

    // nodeToRemove is removed from the tree and can be deleted
    delete nodeToRemove;

    // Anything that was below nodeToRemove that has persisted is already
    // correctly balanced, but ancestors of nodeToRemove may need rebalancing.
    AVLNode *nodeToRebalance = (AVLNode *)parent;
    while (nodeToRebalance) {
      Rebalance(nodeToRebalance);
      nodeToRebalance = (AVLNode *)nodeToRebalance->GetParent();
    }

    return true;
  }

  virtual bool RemoveNode(BSTNode *nodeToRemove) override {
    return RemoveAVLNode((AVLNode *)nodeToRemove);
  }

public:
  AVLTree() {
    // Note: Parent class's constructor does all needed work
  }
};

#endif
