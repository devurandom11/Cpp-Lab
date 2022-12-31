# Vending machine

Note that inventory below refers to the value of the variable bottles

Declare a class VendingMachine in VendingMachine.h with a one class private integer variable called bottles, no inline functions, and only the declaration of the public functions below:

    A default constructor
    A function named Purchase with one integer parameter named amount, that does not return anything (void)
    An accessor function named GetInventory with no parameters that returns an integer value
    A function called Restock with one integer parameter named amount, that does not return anything (void)
    A function called Report with no parameters, that does not return anything (void)

Next define these same class functions in VendingMachine.cpp:

    A default constructor that initializes bottles (inventory) to 20.
    A function named Purchase with one integer parameter named amount, that does not return anything (void) This function reduces inventory (bottles) by amount
    An accessor function named GetInventory with no parameters that returns the value of bottles
    A function called Restock with one integer parameter named amount, that does not return anything (void) This function increments inventory (bottles) with amount
    A function called Report with no parameters, that does not return anything (void) This function prints out the value of bottles as in this example: "Inventory: 17 bottles"

Then in main: Given two integers as user inputs that represent the number of drinks to buy and the number of bottles to restock, create a Vending Machine object that performs the following operations:

    Purchases input number of drinks
    Restocks input number of bottles
    Reports inventory

A VendingMachine's initial inventory is 20 drinks.

Ex: If the input is:

```cpp
5 2
```

the output is:

```cpp
Inventory: 17 bottles
```
