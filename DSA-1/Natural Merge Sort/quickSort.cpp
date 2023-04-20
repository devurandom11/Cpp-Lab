#include <iostream>

int Partition(int numbers[], int lowIndex, int highIndex) {
  // Pick middle element as pivot
  int midpoint = lowIndex + (highIndex - lowIndex) / 2;
  int pivot = numbers[midpoint];

  bool done = false;
  while (!done) {
    // Increment lowIndex while numbers[lowIndex] < pivot
    while (numbers[lowIndex] < pivot) {
      lowIndex += 1;
    }
    // Decrement highIndex while pivot < numbers[highIndex]
    while (pivot < numbers[highIndex]) {
      highIndex -= 1;
    }
    // If zero or one elements remain, then all numbers are
    // partitioned. Return highIndex.
    if (lowIndex >= highIndex) {
      done = true;
    } else {
      // Swap numbers[lowIndex] and numbers[highIndex]
      int temp = numbers[lowIndex];
      numbers[lowIndex] = numbers[highIndex];
      numbers[highIndex] = temp;

      // Update lowIndex and highIndex
      lowIndex += 1;
      highIndex -= 1;
    }
  }
  return highIndex;
}

void Quicksort(int numbers[], int lowIndex, int highIndex) {
  // Base case: If the partition size is 1 or zero
  // elements, then the partition is already sorted
  if (lowIndex >= highIndex) {
    return;
  }

  // Partition the data within the array. Value lowEndIndex
  // returned from partitioning is the index of the low
  // partition's last element.
  int lowEndIndex = Partition(numbers, lowIndex, highIndex);

  // Recursively sort low partition (lowIndex to lowEndIndex)
  // and high partition (lowEndIndex + 1 to highIndex)
  Quicksort(numbers, lowIndex, lowEndIndex);
  Quicksort(numbers, lowEndIndex + 1, highIndex);
}

int main() {
  std::cout << "---- Quick Sort ----" << std::endl;
  int numbers[] = {10, 2, 78, 4, 45, 32, 7, 11};
  int NUMBERS_SIZE = 8;
  int i = 0;

  std::cout << "UNSORTED: ";
  for (i = 0; i < NUMBERS_SIZE; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;

  // Initial call to quicksort
  Quicksort(numbers, 0, NUMBERS_SIZE - 1);

  std::cout << "SORTED: ";
  for (i = 0; i < NUMBERS_SIZE; ++i) {
    std::cout << numbers[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}