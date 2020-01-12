#include <iostream>
#include <algorithm>
#include <chrono>
#include <array>
#include <random>

int main() {
  std::array<int, 5> random = { 0, 1, 2, 3, 4 };
  for (int i : random) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  // Shuffle the array
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(random.begin(), random.end(), std::default_random_engine(seed));
  std::cout << "— Shuffled: " << std::endl;
  for (int i : random) {
    std::cout << i << ", ";
  }
  std::cout << std::endl;
  return 0;
}
