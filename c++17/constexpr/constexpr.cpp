#include <iostream>

// constexpr function: multiply two integerns
// Using constexpr forces the compiler to evaluate
// at compile time
constexpr int product(int x, int y) { return (x * y); }

int main()
{
  // Main idea:
  // - Compute expressions at COMPILE TIME rather than RUN TIME
  //
  // Benefits:
  // - performance improvement
  // - Save time at run time (because expressions have been evaluated at compile time already)
  // - Similar to 'template metaprogramming'

  // A value can be evaluated at compile time
  const int x = product (10, 20);
  std::cout << x << std::endl;

  // A function can be declared as constexpr
  // 1. C++11: constexpr function: only one return value
  //    C++14: constexpr function: allows more return values
  //
  // 2. Should refer only constant global variables
  // 3. constexpr can only call other constexpr functions
  // 4. No void type functions, some operators (prefix ++) are not allowed.
  
	return 0;
}
