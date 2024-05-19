#ifndef TREECOMMANDS_H
#define TREECOMMANDS_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "BSTNodeVectorVisitor.h"
#include "BinarySearchTree.h"

// TreeTestCommand is the abstract base class for a command that tests some
// aspect of a BinarySearchTree object
class TreeTestCommand {
public:
  virtual ~TreeTestCommand() {}

  virtual bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) = 0;
};

// TreeInsertCommand inserts a vector of keys into the tree when executed
class TreeInsertCommand : public TreeTestCommand {
private:
  std::vector<int> keysToInsert;

public:
  TreeInsertCommand(const std::vector<int> &keys) : keysToInsert(keys) {}

  bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) override {
    // If no keys to insert, return true immediately
    if (0 == keysToInsert.size()) {
      return true;
    }

    // Begin feedback message and insert first key
    testFeedback << "Inserting keys: " << keysToInsert[0];
    tree.InsertKey(keysToInsert[0]);

    // Insert remaining keys
    for (size_t i = 1; i < keysToInsert.size(); i++) {
      testFeedback << ", " << keysToInsert[i];
      tree.InsertKey(keysToInsert[i]);
    }
    testFeedback << std::endl;
    return true;
  }
};

// TreeRemoveCommand removes a vector of keys from the tree when executed
class TreeRemoveCommand : public TreeTestCommand {
private:
  std::vector<int> keysToRemove;

public:
  TreeRemoveCommand(const std::vector<int> &keys) : keysToRemove(keys) {}

  bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) override {
    if (keysToRemove.size() > 0) {
      // Begin feedback message and remove first key
      testFeedback << "Removing keys: " << keysToRemove[0];
      tree.RemoveKey(keysToRemove[0]);

      // Remove remaining keys
      for (size_t i = 1; i < keysToRemove.size(); i++) {
        testFeedback << ", " << keysToRemove[i];
        tree.RemoveKey(keysToRemove[i]);
      }
      testFeedback << std::endl;
    }
    return true;
  }
};

// TreeVerifyKeysCommand verifies a BST's keys using an inorder traversal
class TreeVerifyKeysCommand : public TreeTestCommand {
private:
  std::vector<int> expectedKeys;

public:
  TreeVerifyKeysCommand(const std::vector<int> &keys) : expectedKeys(keys) {}

  bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) override {
    using namespace std;

    // Create a BSTNodeVectorVisitor and do an in order traversal
    BSTNodeVectorVisitor visitor;
    tree.InOrder(visitor);

    // The visitor determines if a circular reference exists
    if (visitor.HasCircularReference()) {
      testFeedback << "FAIL: Tree traversal encountered the same node ";
      testFeedback << "more than once, so a circular reference exists";
      testFeedback << std::endl;
      return false;
    }

    // Make a vector of keys from the visitor's vector of nodes
    vector<int> actual;
    for (BSTNode *node : visitor.visitedNodes) {
      actual.push_back(node->GetKey());
    }

    // Compare actual to expected
    bool pass = true;
    if (actual.size() == expectedKeys.size()) {
      for (size_t i = 0; pass && i < expectedKeys.size(); i++) {
        if (actual[i] != expectedKeys[i]) {
          pass = false;
        }
      }
    } else {
      pass = false;
    }

    // Display results
    testFeedback << (pass ? "PASS" : "FAIL");
    testFeedback << ": Inorder key verification" << endl;
    PrintVector(expectedKeys, testFeedback, ", ", "  Expected: { ", " }\n");
    PrintVector(actual, testFeedback, ", ", "  Actual:   { ", " }\n");

    return pass;
  }

  void PrintVector(std::vector<int> &vec, std::ostream &output,
                   std::string separator = ",", std::string prefix = "",
                   std::string suffix = "") {
    output << prefix;
    if (vec.size() > 0) {
      // Output the first value without the separator
      output << vec[0];

      // Output each remaining value preceeded by the separator
      for (size_t i = 1; i < vec.size(); i++) {
        output << separator << vec[i];
      }
    }
    output << suffix;
  }
};

// TreeGetNthCommand calls the BinarySearchTree's GetNthKey() function and
// verifies that the returned key matches the expected.
class TreeGetNthCommand : public TreeTestCommand {
private:
  int n;
  int expectedKey;

public:
  TreeGetNthCommand(int n, int expectedKey) {
    this->n = n;
    this->expectedKey = expectedKey;
  }

  bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) override {
    int actualKey = tree.GetNthKey(n);
    if (actualKey == expectedKey) {
      testFeedback << "PASS: GetNthKey(" << n << ") returned ";
      testFeedback << actualKey << std::endl;
      return true;
    }

    // Actual key does not equal expected
    testFeedback << "FAIL: GetNthKey(" << n << ") returned ";
    testFeedback << actualKey << ", but expected key is " << expectedKey;
    testFeedback << std::endl;
    return false;
  }
};

class TreeVerifySubtreeCountsCommand : public TreeTestCommand {
private:
  std::vector<std::pair<int, int>> expectedPairs;

public:
  TreeVerifySubtreeCountsCommand(
      const std::vector<std::pair<int, int>> &expectedKeyCountPairs)
      : expectedPairs(expectedKeyCountPairs) {}

  bool Execute(BinarySearchTree &tree, std::ostream &testFeedback) override {
    using namespace std;

    // Create a BSTNodeVectorVisitor and do an in order traversal
    BSTNodeVectorVisitor visitor;
    tree.InOrder(visitor);

    // Compare actual to expected
    bool passed = true;
    if (visitor.visitedNodes.size() == expectedPairs.size()) {
      for (size_t i = 0; i < expectedPairs.size(); i++) {
        int expectedCount = expectedPairs[i].second;

        // Get the actual node visited and the node's subtree key count
        BSTNode *actualNode = visitor.visitedNodes[i];
        int actualCount = actualNode->GetSubtreeKeyCount();

        // Compare actual vs. expected subtree key count
        if (actualCount != expectedCount) {
          testFeedback << "FAIL: Node with key " << actualNode->GetKey();
          testFeedback << " has a subtree key count of ";
          testFeedback << actualCount << ", but the expected subtree ";
          testFeedback << "key count is " << expectedCount << endl;
          passed = false;
        } else {
          testFeedback << "PASS: Node with key " << actualNode->GetKey();
          testFeedback << " has a subtree key count of ";
          testFeedback << actualCount << endl;
        }
      }

      if (!passed) {
        return false;
      }

      // Display results
      testFeedback << "PASS: All " << expectedPairs.size() << " nodes ";
      testFeedback << "have correct subtree key counts" << endl;
      return true;
    }

    // Give feedback indicating that the number of nodes in the tree is
    // incorrect
    testFeedback << "FAIL: Traversal through tree encountered ";
    testFeedback << visitor.visitedNodes.size() << " nodes before ";
    testFeedback << "either stopping or encountering a circular ";
    testFeedback << "reference. But ";
    if (1 == expectedPairs.size()) {
      testFeedback << "only one node was ";
    } else {
      testFeedback << expectedPairs.size() << " nodes were ";
    }
    testFeedback << "expected in the tree." << endl;

    return false;
  }
};

#endif
