#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 7, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};

  std::cout << "--- std::find ---" << std::endl;
  /*
    - std::find finds the first element in an iterators range
   */
  int searchMe = 7;
  std::vector<int>::iterator it;
  it = std::find(numbers.begin(), numbers.end(), searchMe);
  std::cout << "std::find found " << searchMe << std::endl;
  return 0;
}
