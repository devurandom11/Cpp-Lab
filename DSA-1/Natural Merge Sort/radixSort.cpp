#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int RadixGetLength(int value) {
  if (value == 0) {
    return 1;
  }

  int digits = 0;
  while (value != 0) {
    digits++;
    value /= 10;
  }
  return digits;
}

// Returns the maximum length, in number of digits, out of all array elements
int RadixGetMaxLength(int* numbers, int numbersSize) {
  int maxDigits = 0;
  for (int i = 0; i < numbersSize; i++) {
    int digitCount = RadixGetLength(numbers[i]);
    if (digitCount > maxDigits) {
      maxDigits = digitCount;
    }
  }
  return maxDigits;
}

void RadixSort(int* numbers, int numbersSize) {
  vector<vector<int>*> buckets;
  for (int i = 0; i < 10; i++) {
    vector<int>* bucket = new vector<int>();
    buckets.push_back(bucket);
  }

  int copyBackIndex = 0;

  // Find the max length, in number of digits
  int maxDigits = RadixGetMaxLength(numbers, numbersSize);

  int pow10 = 1;
  for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
    // Put numbers into buckets
    for (int i = 0; i < numbersSize; i++) {
      int num = numbers[i];
      int bucketIndex = (abs(num) / pow10) % 10;
      buckets[bucketIndex]->push_back(num);
    }

    // Copy buckets back into numbers array
    copyBackIndex = 0;
    for (int i = 0; i < 10; i++) {
      vector<int>& bucket = *buckets[i];
      for (int j = 0; j < bucket.size(); j++) {
        numbers[copyBackIndex] = bucket[j];
        copyBackIndex++;
      }
      bucket.clear();
    }

    pow10 *= 10;
  }

  vector<int> negatives;
  vector<int> nonNegatives;
  for (int i = 0; i < numbersSize; i++) {
    int num = numbers[i];
    if (num < 0) {
      negatives.push_back(num);
    } else {
      nonNegatives.push_back(num);
    }
  }

  // Copy sorted content to array - negatives in reverse, then non-negatives
  copyBackIndex = 0;
  for (int i = negatives.size() - 1; i >= 0; i--) {
    numbers[copyBackIndex] = negatives[i];
    copyBackIndex++;
  }
  for (int i = 0; i < nonNegatives.size(); i++) {
    numbers[copyBackIndex] = nonNegatives[i];
    copyBackIndex++;
  }

  // Free each dynamically allocated bucket
  for (int i = 0; i < 10; i++) {
    delete buckets[i];
  }
}

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

int main() {
  // Create an array of numbers to sort
  int numbers[] = {-9, 47, 81, 101, -5, 38, -99, 96, 51, -999, -11, 64};
  int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

  // Display the contents of the array
  cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;

  // Call the RadixSort function
  RadixSort(numbers, numbersSize);

  // Display the sorted contents of the array
  cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
}
