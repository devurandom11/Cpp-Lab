#include "MyList.h"

#include "MyLinkedNode.h"

MyList::MyList() : head(nullptr), tail(nullptr), size(0) {
  std::cout << "MyList constructor called with head: " << head
            << " tail: " << tail << " and size: " << size << std::endl;
}

MyList::MyList(MyLinkedNode* head, MyLinkedNode* tail, int size)
    : head(head), tail(tail), size(size) {
  std::cout << "MyList constructor called with head: " << head
            << " tail: " << tail << " and size: " << size << std::endl;
}

MyList::~MyList() {
  std::cout << "MyList destructor called with head: " << head
            << " tail: " << tail << " and size: " << size << std::endl;
}
