#ifndef H_MERCEDES
#define H_MERCEDES

#include <string>
#include "Car.hpp"

class Mercedes : public Car
{
	public:
		inline std::string getType() { return "Mercedes"; }
};


#endif // H_MERCEDES