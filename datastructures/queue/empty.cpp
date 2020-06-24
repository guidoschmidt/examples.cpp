#include <queue>
#include <iostream>

void print_q_empty(bool is_empty) {
  std::cout << (is_empty ? "Q is empty" : "Q is not empty") << std::endl;
}

void print_q_items(std::queue<int> q) {
  while (!q.empty()) {
    std::cout << q.front() << ", ";
    q.pop();
  }
  std::cout << std::endl;
}

int main() {
  std::queue<int> q;
  print_q_empty(q.empty());

  q.push(2);
  q.push(7);
  q.push(9);
  print_q_empty(q.empty());
  print_q_items(q);

  print_q_empty(q.empty());
  print_q_items(q);

  return 0;
}
