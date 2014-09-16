#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "C++ 11 to_string function" << endl;
	cout << "---------------------------------------------------------" << endl;

	int array[4] = {1, 2, 3, 4};
	cout << to_string(array[0]) << endl;

	cout << to_string(++(*array)) << std::endl;
	cout << to_string(++(*array)) << std::endl;
	cout << to_string(++(*array)) << std::endl;


	return 0;
}