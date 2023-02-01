#ifndef MYNODE_H
#define MYNODE_H

class MyNode
{
public:
    int value;
    MyNode *left;
    MyNode *right;
    char operation;

    MyNode(MyNode *l, MyNode *r, char op);
    MyNode(int v);

    int calculate();

    void PrintInOrder();
};

#endif