#include <iostream>
#include <vector>

int main()
{
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};

  std::cout << "--- std::adjacent_find ---" << std::endl;
  /*
    - std::adjacent_find is a binary function
    - It finds the first adjacent element pairs based on a condition (third parameter)
    - Default condition is equality check
   */
  auto i = std::adjacent_find(numbers.begin(), numbers.end());
  std::cout << "The first pair of repeated elements are: " << std::to_string(*i) << std::endl;
  return 0;
}
