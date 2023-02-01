#include "MyNode.cpp"
#include <iostream>
#include <string>

auto main() -> int
{
    std::string test;
    MyNode *n1 = new MyNode(1);
    MyNode *n2 = new MyNode(1);
    MyNode *n3 = new MyNode(1);
    MyNode *n4 = new MyNode(n1, n2, '+');
    MyNode *n5 = new MyNode(n4, n3, '+');
    MyNode *n6 = new MyNode(n5, n2, '+');

    std::cout << n6->calculate() << std::endl;
    std::cin >> test;
    return 0;
}