#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BSTNode.h"
#include "BSTNodeVisitor.h"

class BinarySearchTree {
protected:
  BSTNode *root;

  virtual void DeleteTree(BSTNode *subtreeRoot) {
    if (subtreeRoot) {
      DeleteTree(subtreeRoot->GetLeft());
      DeleteTree(subtreeRoot->GetRight());
      delete subtreeRoot;
    }
  }

  bool InOrder(BSTNodeVisitor &visitor, BSTNode *current) const {
    if (current) {
      // Visit left subtree first, if left child is non-null
      BSTNode *left = current->GetLeft();
      if (left) {
        if (!InOrder(visitor, left)) {
          return false;
        }
      }

      // Visit the current node. Return false if the visitor function
      // returns false.
      if (!visitor.Visit(current)) {
        return false;
      }

      // Visit right subtree last, if right child is non-null
      BSTNode *right = current->GetRight();
      if (right) {
        return InOrder(visitor, right);
      }
    }
    return true;
  }

  // Inserts the node into the tree using the standard BST insertion algorithm
  virtual void InsertNode(BSTNode *node) {
    // Check if tree is empty
    if (!root) {
      root = node;
    } else {
      BSTNode *currentNode = root;
      while (currentNode) {
        // Choose to go left or right
        if (node->GetKey() < currentNode->GetKey()) {
          // Go left. If left child is null, insert the new
          // node here.
          if (currentNode->GetLeft() == nullptr) {
            currentNode->SetLeft(node);
            currentNode = nullptr;
          } else {
            // Go left and do the loop again.
            currentNode = currentNode->GetLeft();
          }
        } else {
          // Go right. If the right child is null, insert the
          // new node here.
          if (currentNode->GetRight() == nullptr) {
            currentNode->SetRight(node);
            currentNode = nullptr;
          } else {
            // Go right and do the loop again.
            currentNode = currentNode->GetRight();
          }
        }
      }
    }
  }

  virtual BSTNode *MakeNewNode(int key) { return new BSTNode(key); }

  // Removes the node from the tree using the standard BST removal algorithm
  virtual bool RemoveNode(BSTNode *nodeToRemove) {
    if (!nodeToRemove) {
      return false;
    }

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

      // Recursively remove successor and return true
      RemoveNode(successorNode);
      return true;
    }

    // Case 2: Root node (with 1 or 0 children)
    else if (nodeToRemove == root) {
      if (nodeToRemove->GetLeft()) {
        root = nodeToRemove->GetLeft();
      } else {
        root = nodeToRemove->GetRight();
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

    return true;
  }

  // Performs a left rotation at the given node. Returns the
  // subtree's new root.
  virtual BSTNode *RotateLeft(BSTNode *node) {
    BSTNode *parent = node->GetParent();
    BSTNode *rightChild = node->GetRight();
    BSTNode *rightLeftChild = rightChild->GetLeft();

    // Replace necessary children from the bottom up
    node->SetRight(rightLeftChild);
    rightChild->SetLeft(node);
    if (parent) {
      parent->ReplaceChild(node, rightChild);
    } else {
      root = rightChild;
      root->SetParentToNull();
    }

    return node->GetParent();
  }

  // Performs a right rotation at the given node. Returns the
  // subtree's new root.
  virtual BSTNode *RotateRight(BSTNode *node) {
    BSTNode *parent = node->GetParent();
    BSTNode *leftChild = node->GetLeft();
    BSTNode *leftRightChild = leftChild->GetRight();

    // Replace necessary children from the bottom up
    node->SetLeft(leftRightChild);
    leftChild->SetRight(node);
    if (parent) {
      parent->ReplaceChild(node, leftChild);
    } else {
      root = leftChild;
      root->SetParentToNull();
    }

    return node->GetParent();
  }

public:
  BinarySearchTree() { root = nullptr; }

  virtual ~BinarySearchTree() { DeleteTree(root); }

  virtual int GetNthKey(int n) = 0;

  virtual BSTNode *GetRoot() { return root; }

  // Performs an inorder traversal of the BST. The visitor's Visit() function
  // is called for each node in the tree. The Visit() function returns true to
  // continue traversal, false to stop traversal. If every Visit() call
  // returns true, then true is returned. If Visit() returns false for any
  // node in the tree, thus terminating traversal, false is returned.
  bool InOrder(BSTNodeVisitor &visitor) const { return InOrder(visitor, root); }

  virtual void InsertKey(int key) { InsertNode(MakeNewNode(key)); }

  // Attempts to remove a node with a matching key. If no node has a matching
  // key then nothing is done and false is returned. Otherwise the node is
  // removed and true is returned.
  virtual bool RemoveKey(int key) {
    BSTNode *node = Search(key);
    if (!node) {
      return false;
    } else {
      return RemoveNode(node);
    }
  }

  // Searches for a node with a matching key. Returns the node with the
  // matching key, or nullptr if no matching key exists in the tree.
  virtual BSTNode *Search(int desiredKey) {
    BSTNode *currentNode = root;
    while (currentNode) {
      // Return the node if the key matches
      if (currentNode->GetKey() == desiredKey) {
        return currentNode;
      }

      // Navigate to the left if the search key is
      // less than the node's key.
      else if (desiredKey < currentNode->GetKey()) {
        currentNode = currentNode->GetLeft();
      }

      // Navigate to the right if the search key is
      // greater than the node's key.
      else {
        currentNode = currentNode->GetRight();
      }
    }

    // The key was not found in the tree.
    return nullptr;
  }
};

#endif
