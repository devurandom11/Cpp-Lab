#include <iostream>
#include <string>

#include "StaticSetTestCases.h"
using namespace std;

int main(int argc, char *argv[]) {
  // First test case tests binary operations: union, intersection, and
  // difference
  BinaryOpsTestCase<int> binaryOpsTestCase(
      {42, 63, 99, 32, 18, 77, 64, 50, 12}, {64, 16, 32, 8, 4, 1, 2},
      {1, 2, 4, 8, 12, 16, 18, 32, 42, 50, 63, 64, 77, 99}, // expected union
      {32, 64},                     // expected intersection
      {42, 63, 99, 18, 77, 50, 12}, // expected A minus B
      {1, 2, 4, 8, 16}              // expected B minus A
  );
  int binaryTestCasePoints = binaryOpsTestCase.Execute(cout);
  cout << endl;

  // Next test case tests unary operations: filter and map
  UnaryOpsTestCase<string, int> unaryOpsTestCase(
      {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
       "nine", "ten"},
      [&](const string &str) {
        // Keep each string with a length <= 4
        return (str.length() <= 4);
      },
      [&](const string &str) {
        // Map from the string to the string's length
        return (int)str.length();
      },
      {"zero", "one", "two", "four", "five", "six", "nine",
       "ten"},  // expected filtered
      {3, 4, 5} // expected mapped
  );
  int unaryTestCasePoints = unaryOpsTestCase.Execute(cout);

  cout << endl;
  cout << "Binary operations score: " << binaryTestCasePoints << " out of 3";
  cout << endl;
  cout << "Unary operations score: " << unaryTestCasePoints << " out of 2";
  cout << endl;

  return 0;
}
