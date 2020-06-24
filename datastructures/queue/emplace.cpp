//#include <queue>
#include <iostream>

int main() {
  //std::queue<int> q;

  // Adding elements into the queue using emplace()
  //q.emplace(0);
  //q.emplace(1);
  //q.emplace(2);
  // Adding elements into the queue using push()
  //q.push(3);
  //q.push(4);
  //q.push(5);

  // Difference:
  // — emplace
  // constructs a new object in-place and adds it to the end of the queue
  //
  // — push
  // adds a copy of an already constructed object into the queue and adds
  // it to the end of the queue

 /* 
  while (!q.empty()) {
    std::cout << q.front() << std::endl;
    // Pop the first element
    q.pop();
  }
*/

int x = 0;
x += 2;
std::cout << x << std::endl;

  //return 0;
}
