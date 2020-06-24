#include <iostream>

using namespace std;

void yolo()
{
  std::cout << "#YOLO" << std::endl;
}

int calculateCheckSum(int input)
{
  int sum = 0;
  bool odd = true;
  while (input > 0) {
    int rest = input % 10;
    int mult = odd == true ? 3 : 1;
    input /= 10;
    sum += mult * rest;
    cout << rest << ", is odd: " << odd << ", mult = " << mult << endl;
    odd = !odd;
  }
  cout << "Sum = " << sum << endl;
  int check = 10 - (sum % 10);
  cout << "Check number = " << check << endl;
  return 0;
}


int main(int argc, char* argv[])
{
  int input = 128;
  calculateCheckSum(input);
  return 0;
}
