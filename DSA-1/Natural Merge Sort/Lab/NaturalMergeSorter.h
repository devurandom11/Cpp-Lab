#ifndef NATURALMERGESORTER_H
#define NATURALMERGESORTER_H

class NaturalMergeSorter {
public:
  virtual int GetSortedRunLength(int *array, int arrayLength, int startIndex) {
    if (startIndex > arrayLength - 1) {
      return 0;
    }
    int runLength = 1;
    for (int i = startIndex + 1; i < arrayLength; i++) {
      if (array[i] >= array[i - 1]) {
        runLength++;
      } else {
        break;
      }
    }
    return runLength;
  }

  virtual void NaturalMergeSort(int *array, int arrayLength) {
    if (arrayLength <= 1) {
      return;
    }

    int startIndex;
    bool hasMerged;
    do {
      startIndex = 0;
      hasMerged = false;
      while (startIndex < arrayLength) {
        int leftFirst = startIndex;
        int leftLast =
            leftFirst + GetSortedRunLength(array, arrayLength, leftFirst) - 1;

        // Check if there's a right run to merge
        if (leftLast < arrayLength - 1) {
          int rightFirst = leftLast + 1;
          int rightLast = rightFirst +
                          GetSortedRunLength(array, arrayLength, rightFirst) -
                          1;

          Merge(array, leftFirst, leftLast, rightLast);
          startIndex = rightLast + 1;
          hasMerged = true;
        } else {
          startIndex = arrayLength; // No more runs to merge
        }
      }
    } while (hasMerged);
  }

  virtual void Merge(int *numbers, int leftFirst, int leftLast, int rightLast) {
    int mergedSize = rightLast - leftFirst + 1;
    int *mergedNumbers = new int[mergedSize];
    int mergePos = 0;
    int leftPos = leftFirst;
    int rightPos = leftLast + 1;

    // Add smallest element from left or right partition to merged numbers
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

    // If left partition isn't empty, add remaining elements to mergedNumbers
    while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
    }

    // If right partition isn't empty, add remaining elements to mergedNumbers
    while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
    }

    // Copy merged numbers back to numbers
    for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
    }

    // Free temporary array
    delete[] mergedNumbers;
  }
};

#endif
