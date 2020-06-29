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
	for(std::vector<Car*>::iterator it = myCars.begin(); it < myCars.end(); it++)
	{
    if (dynamic_cast<Ford*>(*it)) {
      std::cout << "... a " << dynamic_cast<Ford*>(*it)->getType() << std::endl;
    }
    if (dynamic_cast<Mercedes*>(*it)) {
      std::cout << "... a " << dynamic_cast<Mercedes*>(*it)->getType() << std::endl;
    }
    // if (dynamic_cast<Mercedes*>(*it)) {
    //   std::cout << "... a " << dynamic_cast<Mercedes*>(*it)->getType() << std::endl;
    // }
	}

	return 0;
}
