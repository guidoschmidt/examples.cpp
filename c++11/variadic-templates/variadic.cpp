#include <iostream>

template<typename T>
T add(T v) {
  return v;
}

template<typename T, typename... Args>
T add(T first, Args... args) {
  return first + add(args...);
}

int main() {
  auto sum = add(1, 2, 3, 4, 5, 6);
  std::cout << "The sum is: " << sum << std::endl;
}
