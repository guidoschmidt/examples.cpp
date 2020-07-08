#include <functional>
#include <iostream>
#include <map>

using std::cout;
using std::endl;

double division(double a, double b) {
  return a / b;
}

int main() {
  std::function<double(double, double)> boundDivisionA =
      std::bind(division, std::placeholders::_1, std::placeholders::_2);

  std::function<double(double)> boundDivisionB =
      std::bind(division, 2000, std::placeholders::_1);

  cout << division(2000, 10) << endl;
  cout << boundDivisionA(2000, 10) << endl;
  cout << boundDivisionB(10) << endl;

  // Use a map to
  std::map<const char, std::function<double(double, double)>> tab;
  // Insert a pair of:
  // 1. a character that symbolizes a math operator
  // 2. a lambda function that semantically implements that mathematical
  //    operation
  tab.insert(std::make_pair('+', [](double a, double b){ return a + b; }));
  tab.insert(std::make_pair('-', [](double a, double b){ return a - b; }));

  cout << tab['-'](2.7, 1.3) << endl;
  cout << tab['+'](2.7, 1.3) << endl;
  return 0;
}
