#include <iostream>
#include <thread>
#include <string>

using namespace std;

void foo()
{
	cout << "I will pint 'foo' 20 times";
	for(int i=0; i < 20; i++)
		cout << "foo" << endl;
}

void bar(unsigned int times, const string word)
{
	cout << "I will print " << word << " " << times << " times" << endl;
	for(int i=0; i < times; i++)
		cout << word << endl;
}

int main(int argc, char* agrv[])
{
	cout << "--- Threads ---" << endl;

	thread fooThread(foo);
	thread barThread(bar, 6, "#yolo");

	fooThread.join();
	barThread.join();

	return 0;
}