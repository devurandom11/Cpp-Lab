# 5.9 LAB: Grocery list editor with undo stack

In this lab a grocery list editor with undo functionality is implemented.

- Step 1: Inspect the UndoCommand abstract base class

The read-only UndoCommand.h file has a declaration for the UndoCommand abstract base class. Access UndoCommand.h by clicking on the orange arrow next to main.cpp at the top of the coding window. The UndoCommand class represents a command object: an object that stores all needed information to execute an action at a later point in time. For this lab, a command object stores information to undo a grocery list change made by the user.

- Step 2: Inspect the incomplete GroceryList class

The GroceryList class is declared in GroceryList.h. Two member variables are declared:

    A vector of strings for list items
    A stack of UndoCommand pointers for undo commands

Note that the AddWithUndo() member function is already implemented. The function adds a new item to the list and pushes a new RemoveLastCommand object onto the undo stack.

- Step 3: Implement RemoveLastCommand's Execute() member function

The RemoveLastCommand class inherits from UndoCommand and is declared in RemoveLastCommand.h. When a RemoveLastCommand object is executed, the string vector's last element is removed. So when the user appends a new item to the grocery list, a RemoveLastCommand is pushed onto the stack of undo commands. Popping and executing the RemoveLastCommand then removes the item most recently added by the user.

RemoveLastCommand's sourceVector member variable and constructor are already declared:

    sourceVector is a pointer to a GroceryList object's vector of strings.
    The constructor takes a pointer to a vector of strings as a parameter, and assigns sourceVector with the pointer.

Implement RemoveLastCommand's Execute() member function to remove sourceVector's last element.

- Step 4: Implement GroceryList's ExecuteUndo() member function

  - Implement GroceryList's ExecuteUndo() member function to do the following:

        Pop an UndoCommand off the undo stack
        Execute the popped undo command
        Delete the undo command

  - File main.cpp has code that reads in a list of commands, one per line, that allow for basic testing of basic operations. So after implementing ExecuteUndo(), run your program with the following input:

        add bananas
        add grapes
        add strawberries
        print
        undo
        print
        undo
        print
        quit

  - Verify that the corresponding output is:

    1. bananas
    2. grapes
    3. strawberries
    4. bananas
    5. grapes
    6. bananas

  - The program's output does not affect grading, so additional test cases can be added, if desired.
    - Submitting code written so far to obtain partial credit is recommended before proceeding to the next step.

- Step 5: Implement the SwapCommand class and GroceryList's SwapWithUndo() member function
  - Implement the SwapCommand class in SwapCommand.h. The class itself is declared, but no members yet exist. Add necessary member variables and member functions so that the command can undo swapping two items in the grocery list.
  - Implement GroceryList's SwapWithUndo() member function. The function swaps list items at the specified indices, then pushes a SwapCommand, to undo that swap, onto the undo stack.

- Step 6: Implement the InsertAtCommand class and GroceryList's RemoveAtWithUndo() member function
  - Implement the InsertAtCommand class in InsertAtCommand.h. Add necessary member variables and member functions so that the command can undo removing a grocery list item at an arbitrary index.
  - Implement GroceryList's RemoveAtWithUndo() member function. The function removes the list item at the specified index, then pushes an InsertAtCommand, to undo that removal, onto the undo stack.
