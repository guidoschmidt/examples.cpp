#include <iostream>
#include <vector>

int main()
{
	int fibonacciArray[] = { 1, 2, 3, 5, 8, 13 };
	auto arraySize = fibonacciArray + sizeof(fibonacciArray) / sizeof(int);
  std::vector<int> fibonacci(fibonacciArray, arraySize);

	std::cout << "Using for each:" << std::endl;
	for(auto i : fibonacci)
	{
		std::cout << i << ", ";
	}

	std::cout << "\nUsing iterator:" << std::endl;
	for(auto it = fibonacci.begin(); it != fibonacci.end(); ++it) 
	{
    // Adding elements while iterating over the std::vector
    if (it == fibonacci.begin())
      it = fibonacci.insert(it, 1);
    std::cout << *it << ", ";
	}
	std::cout << std::endl;

  for (auto it = fibonacci.begin(); it != fibonacci.end(); ++it) {
    // Removing elements while iterating over the std::vector
    if (it == fibonacci.begin() + 2)
      it = fibonacci.erase(it);
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

	return 0;
}
