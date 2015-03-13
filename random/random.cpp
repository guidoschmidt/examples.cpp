#include <iostream>
#include <random>

int main()
{
    // First create a generator
    // Generators select the algorithm
    // used for generating random numbers
    std::default_random_engine generator;

    // Create a distribution
    std::uniform_int_distribution<unsigned int> distribution(0, 100);

    for(unsigned int i=0; i < 20; i++)
    {
        int randomNumber = distribution(generator);
        std::cout << randomNumber << std::endl;
    }

	return 0;
}
