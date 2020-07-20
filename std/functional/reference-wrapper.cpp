#include <functional>
#include <iostream>

using std::cout;
using std::endl;

void print_sth() {
  cout << "I got invoked..." << endl;
}

void invoke(const std::string& s) {
  cout << s << ": const " << std::endl;
}

typedef void callable();

template<typename T> void doubleIt(T t) {
  t *= 2;
}

int main() {
  std::reference_wrapper<callable> wrapped(print_sth);
  wrapped();

  std::string s {"a simple string"};
  invoke(std::cref(s));

  int i = 1;
  cout << i << endl;
  doubleIt(i);
  cout << i << endl;
  doubleIt(std::ref(i));
  cout << i << endl;
}
