#include "MyNode.h"

#include <iostream>
#include <string>

MyNode::MyNode(MyNode *l, MyNode *r, char op) {
  value = -1;
  left = l;
  right = r;
  operation = op;
}

MyNode::MyNode(int v) {
  value = v;
  left = nullptr;
  right = nullptr;
  operation = '\0';
}

int MyNode::calculate() {
  if (value != 0) {
    return value;
  } else {
    switch (operation) {
      case '+':
        return left->calculate() + right->calculate();
      case '-':
        return left->calculate() - right->calculate();
      case '*':
        return left->calculate() * right->calculate();
      case '/':
        if (right->calculate() == 0) {
          std::cerr << "Division by zero is not allowed!" << std::endl;
          return 0;
        } else if (left->calculate() % right->calculate() != 0) {
          std::cerr << "Division is not an integer!" << std::endl;
          return 0;
        }
        return left->calculate() / right->calculate();
      default:
        return 0;
    }
  }
}

void MyNode::PrintInOrder() {
  if (left != NULL) {
    left->PrintInOrder();
  }
  std::cout << value << " ";
  if (right != NULL) {
    right->PrintInOrder();
  }
}
