#ifndef MYLINKEDNODE_H
#define MYLINKEDNODE_H

#include <iostream>
#include <string>

class MyLinkedNode {
 private:
  std::string data;
  MyLinkedNode* next;

 public:
  MyLinkedNode();
  MyLinkedNode(std::string data, MyLinkedNode* next);
  ~MyLinkedNode();
};

#endif