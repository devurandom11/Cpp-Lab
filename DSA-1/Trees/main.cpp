#include <iostream>
#include <string>
#include <vector>

// Binary tree implementation using structs only

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

void insertNode(Node* root, int data) {
  if (data < root->data) {
    if (root->left == nullptr) {
      root->left = createNode(data);
    } else {
      insertNode(root->left, data);
    }
  } else {
    if (root->right == nullptr) {
      root->right = createNode(data);
    } else {
      insertNode(root->right, data);
    }
  }
}

void printTree(Node* root) {
  if (root == nullptr) {
    return;
  }
  printTree(root->left);
  std::cout << root->data << std::endl;
  printTree(root->right);
}

// Binary search tree implementation using classes
class myNode {
 public:
  int data;
  myNode* left;
  myNode* right;
  myNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

class myTree {
 public:
  myNode* root;
  myTree() { root = nullptr; }
  void insert(int data) {
    if (root == nullptr) {
      root = new myNode(data);
    } else {
      insertNode(root, data);
    }
  }
  void insertNode(myNode* root, int data) {
    if (data < root->data) {
      if (root->left == nullptr) {
        root->left = new myNode(data);
      } else {
        insertNode(root->left, data);
      }
    } else {
      if (root->right == nullptr) {
        root->right = new myNode(data);
      } else {
        insertNode(root->right, data);
      }
    }
  }
  void printTree(myNode* root) {
    if (root == nullptr) {
      return;
    }
    printTree(root->left);
    std::cout << root->data << std::endl;
    printTree(root->right);
  }
};

int main() {
  // Struct implementation
  Node* root = createNode(5);
  insertNode(root, 3);
  insertNode(root, 7);
  insertNode(root, 1);
  insertNode(root, 4);
  insertNode(root, 6);
  insertNode(root, 8);
  printTree(root);

  // Class implementation
  myTree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);
  tree.printTree(tree.root);

  return 0;
}