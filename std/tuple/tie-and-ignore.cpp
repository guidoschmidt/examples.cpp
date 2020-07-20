#include <tuple>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  int first  = 1;
  int second = 2;
  int third  = 3;
  int fourth = 4;

  cout << endl;
  cout << "int0:" << first  << ", " << endl
       << "int1:" << second << ", " << endl
       << "int2:" << third  << ", " << endl
       << "int3:" << fourth << endl;

  // Bind variable into a tuple
  std::tuple bound_tuple = std::tie(first, second, third, fourth);
  // Create tuple and assign it;
  bound_tuple = std::make_tuple(101, 102, 103, 104);

  cout << endl;
  cout << "int0:" << first  << ", " << endl
       << "int1:" << second << ", " << endl
       << "int2:" << third  << ", " << endl
       << "int3:" << fourth << endl;
  cout << "--- Tuple: " << endl;
  cout << std::get<0>(bound_tuple) << ", " << endl
       << std::get<1>(bound_tuple) << ", " << endl
       << std::get<2>(bound_tuple) << ", " << endl
       << std::get<3>(bound_tuple) << endl;

  std::tuple partially_bound_tuple = std::tie(std::ignore, std::ignore,
                                              third, fourth);
  partially_bound_tuple = std::make_tuple(0, 0, 42, 43);

  cout << endl;
  cout << "int0:" << first  << ", " << endl
       << "int1:" << second << ", " << endl
       << "int2:" << third  << ", " << endl
       << "int3:" << fourth << endl;
  cout << "--- Tuple: " << endl;
  return 0;
}
