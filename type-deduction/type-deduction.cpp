#include <iostream>
#include <string>


using namespace std;

template<typename T> T case1(T& param)
{
  return param;
}

int main(int argc, char* argv[])
{
	cout << "Type Deduction" << endl;
	cout << "----------" << endl;

  // CASE 1.
  //
  // Parameter is a reference pointer, but not a universal refrence
  // 1. If param is a reference, ignore the reference part
  // 2. Pattern match the function input against the param type to determine T
  int x = 27;        // x is int
  const int cx = x;  // cx is a const int
  const int& rx = x; // rx is a reference to x as a const int
  cout << "Got an int:          " << case1(x)  << endl;
  cout << "Got a const int:     " << case1(cx) << endl;
  cout << "Got a reference int: " << case1(rx) << endl;
  

  // int intArg = 12;
  // cout << returnArg(intArg) << endl;
  // string stringArg = "Foobar";
  // cout << returnArg(stringArg) << endl;
  // float floatArg = 32823902.323f;
  // cout << returnArg(floatArg) << endl;

	return 0;
}
