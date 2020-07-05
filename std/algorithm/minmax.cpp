#include <iostream>
#include <algorithm>

using std::cout;

int main() {
  cout << "min of (19, 2): " << std::min(19, 2) << std::endl;
  cout << "max of (42, 10): " << std::max(42, 10) << std::endl;

  auto list = { 3, 11, 19, 12, 18 };
  cout << "min of list: " << std::min(list) << std::endl;
  cout << "max of list: " << std::max(list) << std::endl;

  auto minmax = std::minmax(list);
  cout << "min tuple of list: " << minmax.first << std::endl;
  cout << "max tuple of list: " << minmax.second << std::endl;

  list = { -3, 11, -19, -202, 18 };
  auto custom_minmax = std::minmax(list, [](int a, int b) {
    return std::abs(a) < std::abs(b);
  });
  cout << "custom min/max (using std::abs): "
       << std::abs(custom_minmax.first)
       << ", "
       << std::abs(custom_minmax.second)
       << std::endl;
}
