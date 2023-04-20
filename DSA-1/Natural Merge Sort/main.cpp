#include <iostream>
#include <string>

#include "NaturalMergeSorter.h"
#include "RunLengthTestCase.h"
using namespace std;

bool IsArraySorted(int* arr, int arrSize);
void WriteArray(int* array, int arrayLength);

int main(int argc, char* argv[]) {
  // Test case array: A completely sorted array
  int arr1[] = {15, 23, 23, 23, 31, 64, 77, 87, 88, 91};
  int arr1Length = sizeof(arr1) / sizeof(arr1[0]);

  // Test case array: Sorted run of 3 followed by sorted run of 6
  int arr2[] = {64, 88, 91, 12, 21, 34, 43, 56, 65};
  int arr2Length = sizeof(arr2) / sizeof(arr2[0]);

  // Test case array: 5 elements in descending order, so 5 runs of length 1
  int arr3[] = {-10, -20, -30, -40, -50};
  int arr3Length = sizeof(arr3) / sizeof(arr3[0]);

  // Test case array: 8 equal elements, so 1 run of 8
  int arr4[] = {-99, -99, -99, -99, -99, -99, -99, -99};
  int arr4Length = sizeof(arr4) / sizeof(arr4[0]);

  // Test cases:
  RunLengthTestCase testCases[] = {
      // First test case uses an out-of-bounds starting index. Remaining test
      // cases do not.
      RunLengthTestCase(arr1, arr1Length, arr1Length, 0),
      RunLengthTestCase(arr1, arr1Length, 0, arr1Length),
      RunLengthTestCase(arr1, arr1Length, 3, arr1Length - 3),
      RunLengthTestCase(arr2, arr2Length, 0, 3),
      RunLengthTestCase(arr2, arr2Length, 2, 1),
      RunLengthTestCase(arr2, arr2Length, 3, 6),
      RunLengthTestCase(arr3, arr3Length, 0, 1),
      RunLengthTestCase(arr3, arr3Length, 3, 1),
      RunLengthTestCase(arr4, arr4Length, 0, arr4Length),
      RunLengthTestCase(arr4, arr4Length, 4, arr4Length - 4),
      RunLengthTestCase(arr4, arr4Length, 5, arr4Length - 5)};

  // Execute each test case
  int testCasesLength = sizeof(testCases) / sizeof(testCases[0]);
  for (int i = 0; i < testCasesLength; i++) {
    RunLengthTestCase& testCase = testCases[i];

    // Execute the test case, using std::cout to write messages
    testCase.Execute(std::cout);
  }

  // Test case array for sorting
  int arr5[] = {92, 71, 18, 26, 54, 73, 89, 10, 39, 99, 64, 22};
  int arr5Length = sizeof(arr5) / sizeof(arr5[0]);
  int* arr5Copy = new int[arr5Length];
  for (int i = 0; i < arr5Length; i++) {
    arr5Copy[i] = arr5[i];
  }

  NaturalMergeSorter sorter;
  sorter.NaturalMergeSort(arr5Copy, arr5Length);
  cout << endl;
  cout << (IsArraySorted(arr5Copy, arr5Length) ? "PASS" : "FAIL");
  cout << ": NaturalMergeSort()" << endl;
  cout << "   Array before calling NaturalMergeSort(): [";
  WriteArray(arr5, arr5Length);
  cout << "]" << endl;
  cout << "   Array after calling NaturalMergeSort():  [";
  WriteArray(arr5Copy, arr5Length);
  cout << "]" << endl;
  delete[] arr5Copy;

  return 0;
}

bool IsArraySorted(int* arr, int arrSize) {
  for (int i = 1; i < arrSize; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

void WriteArray(int* array, int arrayLength) {
  // Output occurs only if at least one array element exists
  if (arrayLength > 0) {
    // Write the first element without a comma
    cout << array[0];

    // Write each remaining element preceded by a comma
    for (int i = 1; i < arrayLength; i++) {
      cout << ", " << array[i];
    }
  }
}
