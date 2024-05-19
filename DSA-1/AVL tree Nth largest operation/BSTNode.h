#ifndef BSTNODE_H
#define BSTNODE_H

#include <functional>
#include <string>

class BSTNode {
private:
  int key;
  BSTNode *parent;
  BSTNode *left;
  BSTNode *right;

public:
  // Constructs the BSTNode with the given key. Left, right, and parent
  // pointers are assigned with nullptr.
  BSTNode(int nodeKey) {
    key = nodeKey;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
  }

  virtual ~BSTNode() {}

  virtual int GetKey() { return key; }

  virtual BSTNode *GetLeft() { return left; }

  virtual BSTNode *GetParent() { return parent; }

  virtual BSTNode *GetRight() { return right; }

  // GetSubtreeKeyCount() must be overridden in an inheriting class
  virtual int GetSubtreeKeyCount() { return -1; }

  // Replace a current child with a new child. Determines if the current child
  // is on the left or right, and calls either SetLeft() or SetRight() with
  // the new node appropriately.
  // Returns true if the new child is assigned, false otherwise.
  virtual bool ReplaceChild(BSTNode *currentChild, BSTNode *newChild) {
    if (left == currentChild) {
      SetLeft(newChild);
      return true;
    } else if (right == currentChild) {
      SetRight(newChild);
      return true;
    }

    // If neither of the above cases applied, then the new child
    // could not be attached to this node.
    return false;
  }

  virtual void SetKey(int newKey) { key = newKey; }

  virtual void SetLeft(BSTNode *newLeftChild) {
    // Assign the left child
    left = newLeftChild;

    // If left child is non-null, assign left child's parent
    if (left) {
      left->parent = this;
    }
  }

  virtual void SetParentToNull() { parent = nullptr; }

  virtual void SetRight(BSTNode *newRightChild) {
    // Assign the right child
    right = newRightChild;

    // If right child is non-null, assign right child's parent
    if (right) {
      right->parent = this;
    }
  }

  virtual std::string ToString() {
    using namespace std;
    return to_string(key);
  }
};

#endif
