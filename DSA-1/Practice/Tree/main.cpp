#include "MyNode.cpp"

auto main() -> int {
  std::string test;
  MyNode *n1 = new MyNode(50);
  MyNode *n2 = new MyNode(60);
  MyNode *n3 = new MyNode(100);
  MyNode *n4 = new MyNode(n1, n2, '+');
  MyNode *n5 = new MyNode(n4, n3, '+');
  MyNode *n6 = new MyNode(n5, n2, '+');

  std::cout << n6->calculate() << std::endl;
  n6->PrintInOrder();
  n1->PrintInOrder();

  std::cin >> test;
  return 0;
}