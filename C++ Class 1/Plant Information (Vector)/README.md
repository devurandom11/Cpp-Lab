# Plant Information (Vectors)

Given a base `Plant` class and a derived `Flower` class, complete `main()` to create a vector called `myGarden`. The vector should be able to store objects that belong to the `Plant` class or the `Flower` class. Create a function called `PrintVector()`, that uses the `PrintInfo()` functions defined in the respective classes and prints each element in `myGarden`. The program should read `plants` or `flowers` from input (ending with `-1`), adding each `Plant` or `Flower` to the `myGarden` vector, and output each element in `myGarden` using the `PrintInfo()` function.

Ex. If the input is:

```cpp
plant Spirea 10
flower Hydrangea 30 false lilac
flower Rose 6 false white
plant Mint 4
-1
```

the output is:

```cpp
Plant Information:
Plant name: Spirea
Cost: 10

Plant Information:
Plant name: Hydrengea
Cost: 30
Annual: false
Color of flowers: lilac

Plant Information:
Plant name: Rose
Cost: 6
Annual: false
Color of flowers: white

Plant Information:
Plant name: Mint
Cost: 4
```
