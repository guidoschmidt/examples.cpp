#include <iostream>
#include <string>


using namespace std;

template<typename T> void copyTogether(const T& a, const T& b)
{
	T c = a+b;
	cout << c << endl;
}


int main(int argc, char* argv[])
{
	cout << "Templates" << endl;
	cout << "----------" << endl;

	// Integer
	int a = 5;
	int b = 10;
	copyTogether(a, b);

	// Floats
	float c = 1.45;
	float d = 3.14159;
	copyTogether(c, d);

	// Strings
	string astring = "Ein";
	string bstring = "String";
	copyTogether(astring, bstring);

	return 0;
}