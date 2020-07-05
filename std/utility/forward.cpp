#include <iostream>
#include <utility>

using std::cout;
using std::endl;

struct CustomData {
  int index;
  double number;
  char section;

  CustomData(int i, double d, char c) {
    index = i;
    number = d;
    section = c;
  };
};

/*
 * std::forward can be used to write templates that identically forward their
 * arguments. This is helpful to write factory functions or constructors.
 * Factory functions are functions which create an object and must therefore
 * identically pass all of their arguments.
 *
 * Constructors often use their arguments to initialise their base class with
 * identical arguments.
 *
 * std::forward is the perfect tool for authors of generic libraries
 */
template <typename T, typename... Args>
T createT(Args&&... args) {
  return T(std::forward<Args>(args)...);
}

int main() {
  int a = createT<int>();
  int b = createT<int>(1);

  cout << a << endl;
  cout << b << endl;

  CustomData data = createT<CustomData>(1, 3.14159, 'c');
  cout << data.index << ", " << data.number << ", " << data.section << endl;

  return 0;
}
