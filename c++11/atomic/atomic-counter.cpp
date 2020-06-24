#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> _counter = 0;

void increment(int thread_number) {
  _counter += 1;
  std::cout << "Increase @thread " << thread_number << "\n";
}

int main() {
  int thread_num = 0;
  while (_counter < 100) {
    auto t1 = std::thread(increment, thread_num);
    thread_num++;
    auto t2 = std::thread(increment, thread_num);
    thread_num++;
    auto t3 = std::thread(increment, thread_num);
    thread_num++;
    auto t4 = std::thread(increment, thread_num);
    thread_num++;
    t1.join();
    t2.join();
    t3.join();
    t4.join();
  }
  std::cout << _counter << std::endl;
}
