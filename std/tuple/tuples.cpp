#include <tuple>
#include <iostream>

using std::cout;
using std::endl;

void print_person(std::tuple<const char*, int, float, char> person) {
  std::string gender;
  switch (std::get<char>(person)) {
  case 'm':
      gender = "He";
      break;
  case 'f':
      gender = "She";
      break;
  }

  cout << std::get<const char*>(person)
       << " is " << std::get<int>(person) << " ages old. "
       << gender << " is " << std::get<float>(person) << "m tall."
       << endl;
}

int main() {
  auto person_a = std::make_tuple("Sam", 48, 1.82, 'm');
  auto person_b = std::make_tuple("Toni", 29, 1.79, 'w');

  print_person(person_a);
  print_person(person_b);

  return 0;
}
