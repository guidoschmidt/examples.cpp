#include <iostream>
#include <thread>
#include <future>

int execute_async() {
  int c = 0;
  while (c < 999999999) {
    c++;
  }
  return c;
}

int main() {
  std::packaged_task<int()> task(execute_async);
  std::future<int> result = task.get_future();
  std::cout << "Waiting for the result" << std::endl;
  std::thread task_thread(std::move(task));
  task_thread.join();
  std::cout << "C is " << result.get() << std::endl;
}
