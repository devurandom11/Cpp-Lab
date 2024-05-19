#ifndef RUNLENGTHTESTCASE_H
#define RUNLENGTHTESTCASE_H

#include <iostream>

#include "NaturalMergeSorter.h"

// RunLengthTestCase represents a test case for the NaturalMergeSorter class's
// GetSortedRunLength() function.
class RunLengthTestCase {
public:
  int *array;
  int arrayLength;
  int startIndex;
  int expectedReturnValue;

  RunLengthTestCase(int *array, int len, int start, int expectedRet) {
    this->array = array;
    arrayLength = len;
    startIndex = start;
    expectedReturnValue = expectedRet;
  }

  // Executes the test case. If the test case passes, a message that starts
  // with "PASS" is printed and true is returned. Otherwise a message that
  // starts with "FAIL" is printed and false is returned.
  bool Execute(std::ostream &testFeedback) {
    using namespace std;

    // Create a NaturalMergeSorter instance
    NaturalMergeSorter userSorter;

    // Call the GetSortedRunLength() function with the test case parameters
    int userRetVal =
        userSorter.GetSortedRunLength(array, arrayLength, startIndex);

    // The test passed only if the actual return value equals the expected
    // return value
    const bool passed = (userRetVal == expectedReturnValue);

    // Show a message about the test case's results
    testFeedback << (passed ? "PASS: " : "FAIL: ");
    testFeedback << "GetSortedRunLength()" << endl;
    testFeedback << "   Array: [";
    WriteArray(testFeedback);
    testFeedback << "]" << endl;
    testFeedback << "   Start index:           " << startIndex << endl;
    testFeedback << "   Expected return value: " << expectedReturnValue;
    testFeedback << endl;
    testFeedback << "   Actual return value:   " << userRetVal << endl;

    return passed;
  }

  // Writes comma-separated elements to the output stream
  void WriteArray(std::ostream &output) const {
    // Output occurs only if at least one array element exists
    if (arrayLength > 0) {
      // Write the first element without a comma
      output << array[0];

      // Write each remaining element preceded by a comma
      for (int i = 1; i < arrayLength; i++) {
        output << ", " << array[i];
      }
    }
  }
};

#endif
