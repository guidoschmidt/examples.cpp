#include <iostream>

// Using bitwise XOR operation to swap values
//
// Conventional swapping requires usage of a temp variable.
void swap(int& x, int& y) {
  std::cout << "— Swapping…" << std::endl;
  x = x ^ y;
  y = y ^ x;
  x = x ^ y;
}


int main(int argc, char* argv[]) {
  int x = 12;
  int y = 200;
  
	std::cout << "x: " << std::to_string(x) << std::endl;
	std::cout << "y: " << std::to_string(y) << std::endl;

  swap(x, y);

	std::cout << "x: " << std::to_string(x) << std::endl;
	std::cout << "y: " << std::to_string(y) << std::endl;

  return 0;
}
