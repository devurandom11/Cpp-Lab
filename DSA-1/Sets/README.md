# C++ unordered_set overview

The C++ Standard Library contains an unordered_set class that
implements a dynamic set. unordered_set supports range-based for loops
to iterate through the set's items. Additional functionality is
described in [online documentation](https://www.cplusplus.com/reference/unordered_set/unordered_set/).

# Step 1: Inspect StaticSet.h

Inspect the StaticSet template class declaration in the StaticSet.h
file. Access StaticSet.h by clicking on the orange arrow next to
main.cpp at the top of the coding window. StaticSet uses an
unordered_set to implement a static set. The unordered_set's contents
are assigned at construction time and must not change after.

Constructors and some additional member functions are already implemented:

- Contains(const T& item) uses the unordered_set's count()
  function to determine if the set contains the item. If count() returns
  1, the item is in the set and Contains() returns true. Otherwise the
  item is not in the set and Contains() returns false.
- GetSize() uses the unordered_set's size() function to determine the
  number of elements in the set. GetSize() returns the set's size as an
  integer.

# Step 2: Implement StaticSet's Union(), Intersection(), Difference(), Filter(), and Map() member functions

Implement the StaticSet class's Union(), Intersection(),
Difference(), Filter(), and Map() member functions. Each must not change
the StaticSet itself, but rather build and return a new StaticSet.

# Step 3: Test in develop mode, then submit

File main.cpp contains test cases for each of the five operations.
Running code in develop mode displays the test results, with 3 points
possible for the Union(), Intersection(), and Difference() operations,
and 2 points for the Filter() and Map() operations. After each member
function is implemented and all tests pass in develop mode, submit the
code. The unit tests run on submitted code are similar, but use
different sets and template types.
