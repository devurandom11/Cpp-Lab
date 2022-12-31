# Program: Online shopping cart (Part 1)

1.  Create three files to submit:

        ItemToPurchase.h - Class declaration
        ItemToPurchase.cpp - Class definition
        main.cpp - main() function

2.  Build the ItemToPurchase class with the following specifications:

        Default constructor
        Public class functions (mutators & accessors)
            SetName() & GetName() (2 pts)
            SetPrice() & GetPrice() (2 pts)
            SetQuantity() & GetQuantity() (2 pts)
        Private data members
            string itemName - Initialized in default constructor to "none"
            int itemPrice - Initialized in default constructor to 0
            int itemQuantity - Initialized in default constructor to 0

3.  In `main()`, prompt the user for two items and create two objects of the ItemToPurchase class. Before prompting for the second item, call `cin.ignore()` to allow the user to input a new string. (2 pts)

```cpp
Item 1
Enter the item name:
Chocolate Chips
Enter the item price:
3
Enter the item quantity:
1

Item 2
Enter the item name:
Bottled Water
Enter the item price:
1
Enter the item quantity:
10
```

4. Add the costs of the two items together and output the total cost. (2 pts)

```cpp
TOTAL COST
Chocolate Chips 1 @ $3 = $3
Bottled Water 10 @ $1 = $10

Total: $13
```
