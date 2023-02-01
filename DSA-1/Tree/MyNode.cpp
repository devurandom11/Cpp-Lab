#include "MyNode.h"
#include <iostream>
#include <string>

MyNode::MyNode(MyNode *l, MyNode *r, char op)
{
    value = NULL;
    left = l;
    right = r;
    operation = op;
}

/// @brief
/// @param v
MyNode::MyNode(int v)
{
    value = v;
    left = NULL;
    right = NULL;
    operation = NULL;
}

int MyNode::calculate()
{
    if (isdigit(value))
    {
        return value;
    }
    else
    {
        switch (operation)
        {
        case '+':
            return left->calculate() + right->calculate();
        case '-':
            return left->calculate() - right->calculate();
        case '*':
            return left->calculate() * right->calculate();
        case '/':
            return left->calculate() / right->calculate();
        default:
            return 0;
        }
    }
}

void MyNode::PrintInOrder()
{
    if (left != NULL)
    {
        left->PrintInOrder();
    }
    std::cout << value << " ";
    if (right != NULL)
    {
        right->PrintInOrder();
    }
}
