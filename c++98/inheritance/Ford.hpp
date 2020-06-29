#ifndef H_FORD
#define H_FORD

#include <iostream>
#include <string>
#include "Car.hpp"

class Ford : public Car
{
	private:
	public:
		virtual std::string getType();
};

#endif // H_FORD
