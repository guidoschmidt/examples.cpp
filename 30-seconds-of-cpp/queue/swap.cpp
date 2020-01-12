#include <queue>
#include <iostream>

void print_q_elements(std::queue<int> q) {
  while (!q.empty()) {
    std::cout << q.front() << ", ";
    q.pop();
  }
  std::cout << std::endl;
}

int main() {
  std::queue<int> q1, q2;

  // Fill the first queue
  for (int i = 0; i < 3; i++) {
    q1.push(i);
  }

  // Fill the second queue
  for (int i = 15; i > 5; i--) {
    q2.push(i);
  }

  // Swap the queue elements
  q1.swap(q2);
  std::cout << "--- Q1 elements: " << std::endl;
  print_q_elements(q1);
  std::cout << "--- Q2 elements: " << std::endl;
  print_q_elements(q2);
  
  return 0;
}
