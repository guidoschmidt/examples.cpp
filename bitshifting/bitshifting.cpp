#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "-- Bitshifting ---" << std::endl;
    std::cout << "is like multiplication of pow(2, x)" << std::endl;

    int two = 2;
    std::cout << two << std::endl;
    std::cout << "Bitshift with 1" << std::endl;
    two = two << 1;
    std::cout << two << std::endl;
    std::cout << "Bitshift with 4" << std::endl;
    two = two << 4;
    std::cout << two << std::endl;
}

