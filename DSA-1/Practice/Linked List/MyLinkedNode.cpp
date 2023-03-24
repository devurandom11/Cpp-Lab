#include "MyLinkedNode.h"

MyLinkedNode::MyLinkedNode() : data("null"), next(nullptr) {
  std::cout << "MyLinkedNode constructor called with data: " << data
            << " and next: " << next << std::endl;
}

MyLinkedNode::MyLinkedNode(std::string data, MyLinkedNode* next)
    : data(data), next(next) {
  std::cout << "MyLinkedNode constructor called with data: " << data
            << " and next: " << next << std::endl;
}

MyLinkedNode::~MyLinkedNode() {
  std::cout << "MyLinkedNode destructor called" << std::endl;
}