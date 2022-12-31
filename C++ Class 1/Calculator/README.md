# Calculator

Given `main()`, complete the Calculator class (in files `Calculator.h` and `Calculator.cpp`) that emulates basic functions of a calculator: `add`, `subtract`, `multiply`, `divide`, and `clear`. The class has one private data member called `value` for the calculator's current value. Implement the following constructor and public member functions as listed below:

`Calculator()` - default constructor to set the data member to 0.0
`void Add(double val)` - add the parameter to the data member
`void Subtract(double val)` - subtract the parameter from the data member
`void Multiply(double val)` - multiply the data member by the parameter
`void Divide(double val)` - divide the data member by the parameter
`void Clear()` - set the data member to 0.0
`double GetValue()` - return the data member

Given two double input values `num1` and `num2`, the program outputs the following values:

- The initial value of the data member, value
- The value after adding num1
- The value after multiplying by 3
- The value after subtracting num2
- The value after dividing by 2
- The value after calling the clear() method

Ex: If the input is:

```cpp
10.0 5.0
```

the output is:

```cpp
0.0
10.0
30.0
25.0
12.5
0.0
```
