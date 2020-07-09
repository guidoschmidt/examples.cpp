#include <utility>
#include <iostream>

using std::cout;
using std::endl;

int main() {
  std::pair<const char*, double> pi_pair("pi", 3.14195);
  std::pair<const char*, double> e_pair("e", 2.71828);

  cout << pi_pair.first << ": " << pi_pair.second << endl;
  cout << e_pair.first << ": " << e_pair.second << endl;

  cout << std::get<1>(pi_pair)
       << " is known as "
       << std::get<0>(pi_pair)
       << endl;

  return 0;
}
