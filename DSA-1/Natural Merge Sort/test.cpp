#include <iostream>

int main() {
  int* array = new int[10];
  for (int i = 0; i < 10; i++) {
    std::cout << array[i] << " ";
  }
}