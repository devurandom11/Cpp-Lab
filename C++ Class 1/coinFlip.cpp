#include <cstdlib>
#include <iostream>
#include <string>

std::string CoinFlip() { return (rand() % 2 == 0) ? "Tails" : "Heads"; }

int main() {
  int userInput;
  std::cin >> userInput;

  std::srand(2); // Unique seed

  while (userInput-- > 0) {
    std::cout << CoinFlip() << '\n';
  }

  return 0;
}
