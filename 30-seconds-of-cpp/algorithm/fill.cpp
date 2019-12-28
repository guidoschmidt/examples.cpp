#include <iostream>
#include <algorithm>
#include <vector>

void printVector(std::vector<int>& vector) {
  for (auto i : vector) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> myVector(8);
  std::fill(myVector.begin(), myVector.begin() + 4, 5);
  printVector(myVector);
  // [5, 5, 5, 5, 0, 0, 0, 0]
  std::fill(myVector.begin() + 4, myVector.end(), 1);
  printVector(myVector);
  // [5, 5, 5, 5, 1, 1, 1, 1]
  std::fill(myVector.begin() + 2, myVector.end() - 4, 9);
  // [5, 5, 9, 9, 1, 1, 1, 1]
  printVector(myVector);
}
