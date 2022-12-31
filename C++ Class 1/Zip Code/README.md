# Zip Codes

Define a class `StatePair` with two template types `(T1 and T2)`, constructors, mutators, accessors, and a `PrintInfo()` method. Three vectors have been pre-filled with `StatePair` data in `main()`:

```cpp
    vector<StatePair <int, string>> zipCodeState: ZIP code - state abbreviation pairs
    vector<StatePair<string, string>> abbrevState: state abbreviation - state name pairs
    vector<StatePair<string, int>> statePopulation: state name - population pairs
```

Complete `main()` to use an input ZIP code to retrieve the correct state abbreviation from the vector `zipCodeState`. Then use the state abbreviation to retrieve the state name from the vector `abbrevState`. Lastly, use the state name to retrieve the correct state name/population pair from the vector `statePopulation` and output the pair.

Ex: If the input is:

```cpp
21044
```

the output is:

```cpp
Maryland: 6079602
```
