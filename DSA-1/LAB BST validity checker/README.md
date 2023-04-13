# BST Validity Checker

Step 1: Inspect the Node.h file

Inspect the class declaration for a BST node in Node.h. Access Node.h by clicking on the orange arrow next to main.cpp at the top of the coding window. Each node has a key, a left child pointer, and a right child pointer.
Step 2: Implement the `BSTChecker::CheckBSTValidity()` function

Implement the CheckBSTValidity() function in the BSTChecker class in the BSTChecker.h file. The function takes the tree's root node as a parameter and returns the node that violates BST requirements, or `nullptr` if the tree is a valid BST.

A violating node will be one of three things:

    A node in the left subtree of an ancestor with a lesser key
    A node in the right subtree of an ancestor with a greater key
    A node with the left or right member variable pointing to an ancestor

The given code in main.cpp reads and parses input, and builds the tree for you. Nodes are presented in the form `(key, leftChild, rightChild)`, where `leftChild` and `rightChild` can be nested nodes or `"None"`. A leaf node is of the form `(key)`. After parsing tree input, the `BSTChecker::CheckBSTValidity()` function is called and the returned node's `key`, or `"No violation"`, is printed.

Ex:
If the input is:

    (50, (25, None, (60)), (75))

which corresponds to the tree above, then the output is:

    60    

because 60 violates BST requirements by being in the left subtree of 50.

Ex:
If the input is:

    (20, (10), (30, (29), (31)))    

which corresponds to the tree above, then the output is:

    No violation    

because all BST requirements are met.

The input format doesn't allow creating a tree with a node's child referencing an ancestor, so unit tests are used to test such cases.
