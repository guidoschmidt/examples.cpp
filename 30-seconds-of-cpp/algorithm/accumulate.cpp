#include <iostream>
#include <vector>
#include <numeric>

int GCD(int x, int y) {
  return std::gcd(x, y);
}

int main() {
  std::vector<int> numbers = { 16, 32, 8, 98 };

  std::cout << "--- std::accumulate ---" << std::endl;
  /*
    - std::accumulate performs an operation on a range of provided iterator
   */
  int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
  int greatestDivisor = std::accumulate(numbers.begin(),
                                        numbers.end(),
                                        0,
                                        GCD);
  std::cout << "Sum: " << sum << std::endl;
  std::cout << "GCD: " << greatestDivisor << std::endl;
  return 0;
}
