#include <iostream>
#include <vector>
#include "Car.hpp"
#include "Ford.hpp"
#include "Mercedes.hpp"

int main(int argc, char* argv[])
{
	std::cout << "--- Inheritance ---" << std::endl;

	Ford* myFord = new Ford();
	std::cout << "My first car is a " << myFord->getType() << std::endl;
	Mercedes* myMercedes = new Mercedes();
	std::cout << "My second car is a " << myMercedes->getType() << std::endl;

	std::vector<Car*> myCars;
	myCars.push_back(myFord);
	myCars.push_back(myMercedes);

	std::cout << "I have ..." << std::endl;
	for(auto car : myCars)
	{
		std::cout << "... a " << car->getType() << std::endl;
	}

	return 0;
}