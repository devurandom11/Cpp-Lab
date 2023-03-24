#ifndef MYLIST_H
#define MYLIST_H
#include <vector>

#include "MyLinkedNode.h"

class MyList {
 private:
  MyLinkedNode* head;
  MyLinkedNode* tail;
  int size;

 public:
  MyList();
  MyList(MyLinkedNode* head, MyLinkedNode* tail, int size);
  ~MyList();
};

#endif