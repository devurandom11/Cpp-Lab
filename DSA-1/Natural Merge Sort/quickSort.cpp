#include <iostream>
#include <string>
using namespace std;

int Partition(int *numbers, int startIndex, int endIndex) {
  // Select the middle value as the pivot.
  int midpoint = startIndex + (endIndex - startIndex) / 2;
  int pivot = numbers[midpoint];

  // "low" and "high" start at the ends of the partition
  // and move toward each other.
  int low = startIndex;
  int high = endIndex;

  bool done = false;
  while (!done) {
    // Increment low while numbers[low] < pivot
    while (numbers[low] < pivot) {
      low = low + 1;
    }

    // Decrement high while pivot < numbers[high]
    while (pivot < numbers[high]) {
      high = high - 1;
    }

    // If low and high have crossed each other, the loop
    // is done. If not, the elements are swapped, low is
    // incremented and high is decremented.
    if (low >= high) {
      done = true;
    } else {
      int temp = numbers[low];
      numbers[low] = numbers[high];
      numbers[high] = temp;
      low = low + 1;
      high = high - 1;
    }
  }

  // "high" is the last index in the left partition.
  return high;
}

void Quicksort(int *numbers, int startIndex, int endIndex) {
  // Only sort if at least 2 elements exist
  if (endIndex <= startIndex) {
    return;
  }

  // Partition the array
  int high = Partition(numbers, startIndex, endIndex);

  // Recursively sort the left partition
  Quicksort(numbers, startIndex, high);

  // Recursively sort the right partition
  Quicksort(numbers, high + 1, endIndex);
}

string ArrayToString(int *array, int arraySize) {
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

int main() {
  // Create an array of numbers to sort
  int numbers[] = {12, 18, 3, 7, 32, 14, 91, 16, 8, 57};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
  cout << "QUICKSORT" << endl;
  cout << "=========" << endl;
  // Display the unsorted contents of the array
  cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

  // Call the Quicksort function
  Quicksort(numbers, 0, numbersSize - 1);

  // Display the sorted contents of the array
  cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}
