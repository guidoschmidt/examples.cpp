#include <queue>
#include <iostream>

int main() {
  std::queue<int> q;

  q.push(2); // [2]
  q.push(4); // [2, 4]
  q.push(6); // [2, 4, 6]
  q.push(8); // [2, 4, 6, 8]

  std::cout << q.back() << std::endl;

  return 0;
}
