#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "--- Iterator ---" << endl;
	int fibonacciArray[] = {1, 1, 2, 3, 5, 8, 13};
	auto arraySize = fibonacciArray + sizeof(fibonacciArray)/sizeof(int);
	vector<int> fibonacciVector(fibonacciArray, arraySize);

	cout << "Using for each:" << endl;
	for(auto i : fibonacciVector)
	{
		cout << i << ", ";
	}

	cout << "\nUsing iterator:" << endl;
	for(auto it = fibonacciVector.begin(); it < fibonacciVector.end(); ++it) 
	{
		cout << *it;
		if((it + 1) != fibonacciVector.end())
			cout << ", ";
	}
	cout << endl;

	return 0;
}