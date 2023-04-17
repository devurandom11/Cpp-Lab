#include <iostream>
#include <stdexcept>
#include <vector>

#include "BinarySearchTree.h"
#include "ExtendedAVLTree.h"
#include "TreeCommands.h"

using namespace std;

bool ExecuteTestCmds(vector<TreeTestCommand*>& testCommands,
                     ostream& testFeedback);
bool Test1(ostream& testFeedback);
bool Test2(ostream& testFeedback);
bool Test3(ostream& testFeedback);

int main() {
  cout << "Test 1 - insertion and GetSubtreeKeyCount()" << endl;
  bool test1Passed = Test1(cout);
  cout << endl;
  cout << "Test 2 - insertion, removal, and GetSubtreeKeyCount()" << endl;
  bool test2Passed = Test2(cout);
  cout << endl;
  cout << "Test 3 - insertion, removal, GetSubtreeKeyCount(), and GetNthKey()"
       << endl;
  bool test3Passed = Test3(cout);

  cout << endl << "Summary:" << endl;
  cout << "Test 1: " << (test1Passed ? "PASS" : "FAIL") << endl;
  cout << "Test 2: " << (test2Passed ? "PASS" : "FAIL") << endl;
  cout << "Test 3: " << (test3Passed ? "PASS" : "FAIL") << endl;
}

bool ExecuteTestCmds(vector<TreeTestCommand*>& testCommands,
                     ostream& testFeedback) {
  bool passed = false;
  ExtendedAVLTree userTree;
  for (TreeTestCommand* cmd : testCommands) {
    passed = false;
    try {
      passed = cmd->Execute(userTree, testFeedback);
    } catch (runtime_error& err) {
      testFeedback << "Runtime error while executing test case" << endl;
      return false;
    }
    delete cmd;

    // Break the loop if the command didn't return true
    if (!passed) {
      break;
    }
  }

  return passed;
}

// Test 1 - insertion and GetSubtreeKeyCount()
// - Insertion of the 7 keys shown in the lab's sample tree
// - Verify keys
// - Verify subtree key counts
bool Test1(ostream& testFeedback) {
  vector<TreeTestCommand*> testCommands = {
      new TreeInsertCommand({10, 20, 30, 55, 42, 19, 77}),
      new TreeVerifyKeysCommand({10, 19, 20, 30, 42, 55, 77}),
      new TreeVerifySubtreeCountsCommand({make_pair(10, 2), make_pair(19, 1),
                                          make_pair(20, 7), make_pair(30, 1),
                                          make_pair(42, 4), make_pair(55, 2),
                                          make_pair(77, 1)})};
  return ExecuteTestCmds(testCommands, testFeedback);
}

// Test 2 - insertion, removal, and GetSubtreeKeyCount()
// - Insert 11 keys
// - Verify keys
// - Verify subtree key counts
// - Remove 1 key
// - Verify subtree key counts
bool Test2(ostream& testFeedback) {
  vector<TreeTestCommand*> testCommands = {
      new TreeInsertCommand(
          {86, 75, 23, 30, 98, 67, 53, 9, 19, 58, 14}),  // 11 keys
      new TreeVerifyKeysCommand({9, 14, 19, 23, 30, 53, 58, 67, 75, 86, 98}),
      new TreeVerifySubtreeCountsCommand(
          {make_pair(9, 2), make_pair(14, 1), make_pair(19, 4),
           make_pair(23, 1), make_pair(30, 11), make_pair(53, 1),
           make_pair(58, 3), make_pair(67, 1), make_pair(75, 6),
           make_pair(86, 2), make_pair(98, 1)}),
      new TreeRemoveCommand({75}),
      new TreeVerifySubtreeCountsCommand({make_pair(9, 2), make_pair(14, 1),
                                          make_pair(19, 4), make_pair(23, 1),
                                          make_pair(30, 10), make_pair(53, 1),
                                          make_pair(58, 3), make_pair(67, 1),
                                          make_pair(86, 5), make_pair(98, 1)})};
  return ExecuteTestCmds(testCommands, testFeedback);
}

// Test 3 - insertion, removal, GetSubtreeKeyCount(), and GetNthKey()
// - Insert 18 keys
// - Verify keys
// - Test GetNthKey()
// - Verify subtree key counts
bool Test3(ostream& testFeedback) {
  vector<int> keysToInsert = {10, 58, 66, 18, 34, 96, 5,  48, 73,
                              62, 36, 16, 23, 99, 92, 95, 46, 97};
  vector<int> sortedKeys = {5,  10, 16, 18, 23, 34, 36, 46, 48,
                            58, 62, 66, 73, 92, 95, 96, 97, 99};
  vector<TreeTestCommand*> testCommands = {
      new TreeInsertCommand(keysToInsert),
      new TreeVerifyKeysCommand(sortedKeys),
      new TreeGetNthCommand(11, 66),
      new TreeGetNthCommand(7, 46),
      new TreeGetNthCommand(15, 96),
      new TreeGetNthCommand(4, 23),
      new TreeVerifySubtreeCountsCommand(
          {make_pair(5, 1), make_pair(10, 3), make_pair(16, 1),
           make_pair(18, 9), make_pair(23, 1), make_pair(34, 2),
           make_pair(36, 5), make_pair(46, 1), make_pair(48, 2),
           make_pair(58, 18), make_pair(62, 1), make_pair(66, 2),
           make_pair(73, 8), make_pair(92, 2), make_pair(95, 1),
           make_pair(96, 5), make_pair(97, 1), make_pair(99, 2)}),
      new TreeRemoveCommand({58}),
      new TreeVerifySubtreeCountsCommand(
          {make_pair(5, 1), make_pair(10, 3), make_pair(16, 1),
           make_pair(18, 9), make_pair(23, 1), make_pair(34, 2),
           make_pair(36, 5), make_pair(46, 1), make_pair(48, 2),
           make_pair(62, 17), make_pair(66, 1), make_pair(73, 4),
           make_pair(92, 2), make_pair(95, 1), make_pair(96, 7),
           make_pair(97, 1), make_pair(99, 2)}),
      new TreeGetNthCommand(9, 62),
      new TreeGetNthCommand(3, 18),
      new TreeGetNthCommand(10, 66),
      new TreeGetNthCommand(5, 34)};
  return ExecuteTestCmds(testCommands, testFeedback);
}
