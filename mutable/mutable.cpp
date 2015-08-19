#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	//--- CONST
	// This is allowed!
	float doChange = 41.0f;
	doChange = 12.0f;
	float* doChangePtr = &doChange;
	*doChangePtr = 18.0f;
	const float* doChangeConstPtr = &doChange;
	// Not allowed!
	//*doChangeConstPtr = 28;

	const float doNotChange = 42.0f;
	// This is not allowed!
	// The compiler will check this.
	//doNotChange = 4.0f;


	//--- VOLATILE
	volatile double sideEffect = 23.0d;
	sideEffect = 72.2d;


	//--- MUTABLE
	mutable int mutableInteger = 2;

	return 0;
}
