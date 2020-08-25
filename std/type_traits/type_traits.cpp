#include <type_traits>
#include <iostream>

using std::cout;
using std::endl;

// There are 14 different type categories.
// They are complete and don’t overlap. So each type is only a
// member of one type category. If you check a type category for
// your type, the request is independent of the const or volatile qualifiers.
//
//  1. template <class T> struct is_void;
//  2. template <class T> struct is_integral;
//  3. template <class T> struct is_floating_point;
//  4. template <class T> struct is_array;
//  5. template <class T> struct is_pointer;
//  6. template <class T> struct is_null_pointer;
//  7. template <class T> struct is_member_object_pointer;
//  8. template <class T> struct is_member_function_pointer;
//  9. template <class T> struct is_enum;
// 10. template <class T> struct is_union;
// 11. template <class T> struct is_class;
// 12. template <class T> struct is_function;
// 13. template <class T> struct is_lvalue_reference;
// 14. template <class T> struct is_rvalue_reference;
template <typename T> T fac(T a) {
  static_assert(std::is_integral<T>::value, "T not integral");
  T result = 1;
  for (int i = a; i > 1; i--) {
    result *= i;
  }
  return result;
}

int main() {
  cout << "factorial(1):  " << fac(1) << endl;
  cout << "factorial(3):  " << fac(3) << endl;
  cout << "factorial(10): " << fac(10) << endl;
  // fac(10.1);
  return 0;
}
