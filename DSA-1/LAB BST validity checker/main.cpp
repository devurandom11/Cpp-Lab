#include <iostream>
#include <string>

#include "MyBSTChecker.h"
#include "MyTreeNode.h"
using namespace std;

int main(int argc, char* argv[]) {
  // Get user input
  string userInput;
  getline(cin, userInput);

  // Parse into a binary ree
  MyTreeNode* userRoot = MyTreeNode::Parse(userInput);
  if (userRoot) {
    MyTreeNode* badNode = MyBSTChecker::CheckBSTValidity(userRoot);
    if (badNode) {
      cout << to_string(badNode->key) << endl;
    } else {
      cout << "No violation" << endl;
    }
  } else {
    cout << "Failed to parse input tree" << endl;
  }

  MyTreeNode::DeleteTree(userRoot);
}