#include <iostream>

struct Base {
    Base() { foo(); }
   
    virtual void foo() { 
        std::cout << "BASE" << std::endl; 
    }
};

struct Derived : Base {
    void foo() override {
       std::cout << "Derived" << std::endl; 
    }
};

int main() {
  // The construction of d will print "BASE" onto the console output
  // REASON:
  // vptr that points to vtable is going to be updated at the start of the Derived()
  // constructor, so after Base() constructor
  Derived d;  
}
