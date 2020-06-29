#include <iostream>
#include <thread>

struct Base {
    Base() { foo(); }
   
    virtual void foo() { 
        std::cout << "BASE" << std::endl; 
    }
};

struct Derived : Base {
  Derived(std::atomic<bool>& b) {
    b.store(true);
  }

  void foo() override {
    std::cout << "Dervied" << std::endl;
  }
};

struct Derived2 : Derived {
  Derived2(std::atomic<bool>& b) : Derived(b) {}

  void foo() override {};
};

int main() {
  auto d = (Derived2*)operator new(sizeof(Derived2));
  std::atomic<bool> d_ctor_running { false };
  auto t1 = std::thread([d, &d_ctor_running]() {
    new(d) Derived2(d_ctor_running);
  });
  auto t2 = std::thread([d, &d_ctor_running]() {
    while(d_ctor_running.load());
    // d->foo(); // Undefined behaviour
    // Caused by vptr access
    // Access to the vptr is not synchronized

    // Simultaneous read and write -> data race condition
    // Writes to the vptr happen at the beginning of the constructors
    // Reads are performed every time we call a polymorphic function

    // Read: d->foo() in thread 2
    // Write is performed at the beginning of the Derived2 constructor
  });
  t1.join();
  t2.join();
}
