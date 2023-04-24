#include <iostream>
#include <string>
using namespace std;

string ArrayToString(int* array, int arraySize) {
  // Special case for empty array
  if (0 == arraySize) {
    return string("[]");
  }

  // Start the string with the opening '[' and element 0
  string result = "[" + to_string(array[0]);

  // For each remaining element, append comma, space, and element
  for (int i = 1; i < arraySize; i++) {
    result += ", ";
    result += to_string(array[i]);
  }

  // Add closing ']' and return result
  result += "]";
  return result;
}

int InsertionSortInterleaved(int* numbers, int numbersSize, int startIndex,
                             int gap) {
  int swaps = 0;
  for (int i = startIndex + gap; i < numbersSize; i += gap) {
    int j = i;
    while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
      swaps++;
      // Swap numbers[j] and numbers [j - 1]
      int temp = numbers[j];
      numbers[j] = numbers[j - gap];
      numbers[j - gap] = temp;
      j -= gap;
    }
  }
  return swaps;
}

int ShellSort(int* numbers, int numbersSize, int* gapValues,
              int gapValuesSize) {
  int totalSwaps = 0;
  for (int g = 0; g < gapValuesSize; g++) {
    int swapsForGap = 0;
    for (int i = 0; i < gapValues[g]; i++) {
      swapsForGap +=
          InsertionSortInterleaved(numbers, numbersSize, i, gapValues[g]);
    }
    cout << ArrayToString(numbers, numbersSize) << " (after " << swapsForGap;
    cout << " swap" << (swapsForGap == 1 ? "" : "s") << " with gap=";
    cout << gapValues[g] << ")" << endl;
    totalSwaps += swapsForGap;
  }
  return totalSwaps;
}

int main() {
  // Create an array of numbers to sort
  int numbers[] = {55, 99, 87, 54, 31, 17, 28, 18};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

  // Display the contents of the array
  cout << "---- Shell sort ----" << endl;
  cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

  // Call the ShellSort function
  int gapValues[] = {4, 2, 1};
  int gapValuesSize = sizeof(gapValues) / sizeof(gapValues[0]);
  int totalSwaps = ShellSort(numbers, numbersSize, gapValues, gapValuesSize);

  // Display sorted array and the total number of swaps
  cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
  cout << "Total swaps: " << totalSwaps << endl;
}
