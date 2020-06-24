#include <iostream>
#include <algorithm>

template<class T>
const T& clamp(const T& value, const T& min, const T& max) {
  return std::min(max, std::max(value, min));
}

int main() {
  for(int i = 0; i < 20; i++) {
    std::cout << clamp(i, 0, 10) << std::endl;
  }
  return 0;
}
