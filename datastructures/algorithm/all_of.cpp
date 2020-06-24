#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = { 10, 2, 4, 6 };
  if (std::all_of(v.begin(), v.end(), [](int i) { return i % 2 == 0; })) {
    std::cout << "All numbers are even." << std::endl;
  } else {
    std::cout << "All numbers are not even" << std::endl;
  }
}
