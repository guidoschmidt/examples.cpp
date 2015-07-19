/*
  # C++11: Uniform Initalization

  Uniform initalization is the new way of initalizing varaibles
  in C++11.
  It provides syntax allowing fully unform type initalization on any object.
  Therefore distinction between initalizing aggregate & non-aggregate classes,
  arrays, collection classes (STL) and PODs (Plaint old data structure,
  passive data structure).

  In C++98 you could choose between:
  
  - `()`  Calls the constructor
  - `{}`  Creates an aggreagte class or array
  - `  `  Without braces would initialize using the default constructor
  
  for initialization. With C++11 you can now use one uniform way of
  initiliazing objects iwht `{}`

*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

// Define an aggregate 'class'
struct A_is_Struct {
  int    x;
  double y;
};

// Define a non-aggregate class
class B_is_Class {
  private:
    int    x;
    double y;

  public:
    B_is_Class(int xIn, double yIn) : x(xIn), y(yIn)
    {

    };
};

int main()
{
  // Initalize an integer
  int a_old = 1; // old style, C++98
  int a_new {1};  // new style, C++11


  // Initalize an array
  int array_old[] = {1, 2, 3, 4, 5}; // old style, C++98
  int array_new[] {1, 2, 3, 4, 5};    // new style, C++11


  // Initalize a vector
  // old style, C++98
  std::vector<int> vector_old;
  vector_old.push_back(1);
  vector_old.push_back(2);
  vector_old.push_back(3);
  // new style, C++11
  std::vector<int> vector_new {1, 2, 3};


  // Initalize a map
  // old style, C++98
  std::map<std::string, std::string> capitals_old;
  capitals_old["UK"] = "London";
  capitals_old["GE"] = "Berlin";
  capitals_old["FR"] = "Paris";
  // new style, C++11
  std::map<std::string, std::string> capitals_new {
    {"UK", "London"},
    {"GE", "Berlin"},
    {"FR", "Paris"}
  };


  // Initialize a custom struct
  // Old style, C++98
  A_is_Struct objectA0_old;
  A_is_Struct objectA1_old = {1, 1.0};
  // New style, C++11
  A_is_Struct objectA0_new{};
  A_is_Struct objectA1_new{1, 1.0};
  
  // Initialize a custom class
  // Old style, C++98
  B_is_Class objectB1_old(2, 5.0);
  // New style, C++11
  B_is_Class objectB1_new{2, 5.0};


  return 0;
}
