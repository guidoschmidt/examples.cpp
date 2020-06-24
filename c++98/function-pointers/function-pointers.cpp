#include <iostream>
#include <string>

using namespace std;

void printHelloWorld(string name) {
	cout << "Hallo " << name << endl;
}

void callLambaFunction(void (*function_ptr)()) {
	function_ptr();
}

int main(int argc, char* argv[]) {

	void (*function_ptr)(string);
	function_ptr = &printHelloWorld;
	function_ptr("User");

	auto func = [] () { cout << "Hello World" << endl; };
	callLambaFunction(func);

	return 0;
}
