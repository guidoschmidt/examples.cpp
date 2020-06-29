#include <iostream>
#include <vector>

class A {
 protected:
    std::string _type;

 public:
  A() { _type = "A"; }
  A(std::string t) { _type = t; }
  inline virtual std::string getType() { return _type; }
};

class B : public A {
 public :
  B() : A("B") {};
};

class C : public A {
 public :
  C() : A("C") {};
};


int main() {
  A objectA;
  B objectB;
  std::cout << "1st object is of type: " << objectA.getType() << std::endl;
  std::cout << "2nd object is of type: " << objectB.getType() << std::endl;

  // There may be use cases in which you'll have an object of a certain datatype
  // but you need to get another (compatible) data type of that object.
  // To perform a conversion into another data type, there are four
  // cast operators:
  // 1. static_cast
  // 2. const_cast
  // 3. dynamic_cast
  // 4. reinterpret_cast

  std::vector<A*> objects;
  objects.push_back(new A());
  objects.push_back(new B());
  objects.push_back(new C());
  objects.push_back(new C());
  objects.push_back(new B());
  objects.push_back(new A());

  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "1. static_cast" << std::endl;
  // Static cast uses known conversions to change the data type of an object
  // e.g. a constructor or a defined cast operator in the class definition.
  // static_cast will produce data loss, e.g. in the case of numeric conversions

  int a = 7;
  int b = 4;
  double c1 = a / b;
  double c2 = a / static_cast<double>(b);
  std::cout << "not casted: " << c1 << ", casted: " << c2 << std::endl;

  for (std::vector<A*>::iterator it = objects.begin(); it < objects.end(); it++) {
    // Static cast 
    B* b = static_cast<B*>(*it);
    std::cout << b->getType() << std::endl;
  }
}
