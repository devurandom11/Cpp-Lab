#include <iostream>
#include <stack>
#include <string>

#include "GroceryList.h"

using namespace std;

bool ParseIndices(std::string str, int &outIndex1, int &outIndex2) {
  auto spaceIndex = str.find(" ");
  if (spaceIndex == string::npos) {
    return false;
  }

  outIndex1 = stoi(str);
  outIndex2 = stoi(str.substr(spaceIndex + 1));
  return true;
}

int main(int argc, char *argv[]) {
  // Initialize a new grocery list
  GroceryList groceryList;

  string command;
  bool quit = false;

  while (!quit) {
    getline(cin, command);

    // Process user input
    if (command == "print") {
      groceryList.Print(cout);
    } else if (0 == command.find("add ")) {
      groceryList.AddWithUndo(command.substr(4));
    } else if (0 == command.find("removeat ")) {
      int index = stoi(command.substr(9));
      groceryList.RemoveAtWithUndo(index);
    } else if (0 == command.find("swap ")) {
      int index1 = -1, index2 = -1;

      if (ParseIndices(command.substr(5), index1, index2)) {
        groceryList.SwapWithUndo(index1, index2);
      } else {
        cout << "\"swap\" command requires two indices, separated ";
        cout << "by a space. Ex: swap 2 5" << endl;
      }
    } else if (command == "undo") {
      if (0 == groceryList.GetUndoStackSize()) {
        cout << "Cannot execute undo because undo stack is empty" << endl;
      } else {
        groceryList.ExecuteUndo();
      }
    } else if (command == "quit") {
      quit = true;
    } else {
      cout << "Unknown command: " << command << endl;
    }
  }
  return 0;
}
