# Random Values

Given `main()`, complete class `RandomNumbers` (in files RandomNumbers.h and RandomNumbers.cpp) that has three integer data members: `var1`, `var2`, and `var3`. Write a getter function for each variable: `getVar1()`, `getVar2()` and `getVar3()`. Then write the following 2 member functions:

    `SetRandomValues()` - accepts a low and high integer values as parameters, and sets var1, var2, and var3 to random numbers (generated using the random function) within the range of the low and high input values (inclusive).
    `GetRandomValues()` - prints out the 3 random numbers in the format: "Random values: var1 var2 var3"

Ex: If the input is:

```cpp
15 20
```

the output is:

```cpp
Random values: 17 15 19
```

where 17, 15, 19 can be any random numbers within 15 and 20 (inclusive).

Note: When submitted, your program will be tested against different input range to verify if the three randomly generated values are within range.
