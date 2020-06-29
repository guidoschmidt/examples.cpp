#include <iostream>
#include <vector>

int main()
{
	int fibonacciArray[] = { 1, 2, 3, 5, 8, 13 };
	int* arraySize = fibonacciArray + sizeof(fibonacciArray) / sizeof(int);
  std::vector<int> fibonacci(fibonacciArray, arraySize);

  // Adding elements while iterating over the std::vector
	std::cout << "\nUsing iterator loop, add elements in-loop:" << std::endl;
	for(std::vector<int>::iterator it = fibonacci.begin(); it != fibonacci.end(); ++it) 
	{
    if (it == fibonacci.begin())
      it = fibonacci.insert(it, 1);
    std::cout << *it << ", ";
	}
	std::cout << std::endl;

  // Removing elements while iterating over the std::vector
	std::cout << "\nDelete elements in-loop:" << std::endl;
  for (std::vector<int>::iterator it = fibonacci.begin(); it != fibonacci.end(); ++it) {
    if (it == fibonacci.begin() + 2)
      it = fibonacci.erase(it);
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

	return 0;
}
