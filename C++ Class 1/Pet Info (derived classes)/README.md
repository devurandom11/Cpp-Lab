# Pet Information (derived classes)

The base class `Pet` has protected data members `petName`, and `petAge`. The derived class `Dog` extends the `Pet` class and includes a private data member for `dogBreed`. Complete `main()` to:

- create a generic pet and print information using `PrintInfo()`.
- create a Dog pet, use `PrintInfo()` to print information, and add a statement to print the dog's breed using the `GetBreed()` function.

Ex. If the input is:

```cpp
Dobby
2
Kreacher
3
German Schnauzer
```

the output is:

```cpp
Pet Information:
Name: Dobby
Age: 2
Pet Information:
Name: Kreacher
Age: 3
Breed: German Schnauzer
```
