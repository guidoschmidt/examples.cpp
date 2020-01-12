#include <iostream>

using namespace std;

class DataStruct {
public:
	mutable int mutableInteger;

// Quoting from the C++ Standard:
// volatile is a hint to the implementation to avoid aggressive compiler
// optimization involving the object because the value of the object might
// be changed by means undetectable by an implementation.[...]

// Volatile can be changed by SOMETHING that you're not even aware of.
// This could be anything. Maybe some alien outside this planet called program.
// Maybe some lighting, some form of interrupt,
// Maybe. You never know who is going to change me!
// So O you ignorant, stop playing an all-knowing god, and don't dare touch the
// code where I'm present. Okay?
//
// https://stackoverflow.com/questions/4437527/why-do-we-use-volatile-keyword
	volatile double volatileDouble;
};

  
int main(int argc, char* argv[]) {
	//--- CONST
	// This is allowed:
	float doChange = 41.0f;
	doChange = 12.0f;
	float* doChangePtr = &doChange;
	*doChangePtr = 18.0f;
	const float* doChangeConstPtr = &doChange;
	// This is not allowed:
	//*doChangeConstPtr = 28;

	const float doNotChange = 42.0f;
	// This is not allowed!
	// The compiler will check this:
	//doNotChange = 4.0f;

	//--- VOLATILE
  // volatile values could maybe change but you are not aware of
  DataStruct* s = new DataStruct();
  s->mutableInteger = 3;
  std::cout << s->mutableInteger << std::endl;
  s->mutableInteger = 1;
  std::cout << s->mutableInteger << std::endl;

  s->volatileDouble = 128.0;
  std::cout << s->volatileDouble << std::endl;
  s->volatileDouble = 28.0;
  std::cout << s->volatileDouble << std::endl;
	return 0;
}
