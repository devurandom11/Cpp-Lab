#include <iostream>

void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
  int mergedSize = rightLast - leftFirst + 1;
  int* mergedNumbers = new int[mergedSize];

  int mergePos = 0;
  int leftPos = leftFirst;
  int rightPos = leftLast + 1;

  while (leftPos <= leftLast && rightPos <= rightLast) {
    if (numbers[leftPos] <= numbers[rightPos]) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
    } else {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
    }
    mergePos++;
  }

  while (lefPos <= leftLast) {
    mergedNumbers[mergePos] = numbers[leftPos];
    leftPos++;
    mergePos++;
  }

  while (rightPos <= rightLast) {
    mergedNumbers[mergePos] = numbers[rightPos];
    rightPos++;
    mergePos++;
  }

  for (mergePos = 0; mergePos < mergedSize; mergePos++) {
    numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
  }

  delete[] mergedNumbers;
}

void MergeSort(int* numbers, int startIdx, int endIdx) {
  std::cout << "Implementing";
  ;
}

int main() {
  std::cout << "Merge Sort" << std::endl;
  std::cout << "===========" << std::endl;

  return 0;
}