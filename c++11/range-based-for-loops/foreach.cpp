#include <iostream>

int main()
{
	std::cout << "--- C++ 11 for-each-loops ---" << std::endl;

	int array[] = {1, 2, 3, 4};

	for(auto item : array)
	{
		std::cout << item << std::endl;
		item += 2;

		std::cout << "+2 = " << item << std::endl;
	}

	return 0;
}
