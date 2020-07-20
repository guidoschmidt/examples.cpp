#include <memory>
#include <iostream>

using std::cout;
using std::endl;

struct Texture {
  Texture(int w, int h) {
    _w = w;
    _h = h;
  }

  ~Texture() {
    cout << "Texture was released, had size: ("
         << _w << ", "
         << _h << ")"
         << endl;
  }

  int _w;
  int _h;
};

struct Counter {
public:
  Counter() : val(count) {
    cout << (void*)this << " Hello: " << val << endl;
    Counter::count++;
  }
  ~Counter() {
    cout << (void*)this << " Good Bype: " << val << endl;
    Counter::count--;
  }
private:
  int val;
  static int count;
};

int Counter::count = 0;

int main() {
  // std::auto_ptr is DEPRECATED!

  // Three types of smart pointers
  // 1. std::unique_ptr, for exclusive ownership
  // 2. std::shared_ptr, for shared ownership
  // 3. std::weak_ptr, for temporary ownership

  // RAII principle:
  // The resource is automatically released if the smart pointer goes out of
  // scope! Constructors are called when an object looses scope.

  /*
   * ------------ 1. Unique Pointer ---------------------------------------------
   */
  {
    std::unique_ptr<Texture> texturePtrUnique{new Texture(100, 100)};
    cout << "Unique texture ptr: " << texturePtrUnique.get() << endl;

    std::unique_ptr<Texture> texturePtrUniqueMoved{std::move(texturePtrUnique)};
    cout << "Unique texture ptr: " << texturePtrUnique.get() << endl;
    cout << "Unique texture ptr (moved): " << texturePtrUniqueMoved.get()
         << endl;

    {
      std::unique_ptr<Texture> localUniquePtr{new Texture(200, 200)};
    } // End of scope of localUniquePtr
    texturePtrUniqueMoved.reset(new Texture(300, 300));
    Texture *texture = texturePtrUniqueMoved.release();
    delete texture;

    std::unique_ptr<Texture> ptrA{new Texture(1, 1)};
    std::unique_ptr<Texture> ptrB{new Texture(9, 9)};

    cout << "\nPointer A: " << ptrA.get() << endl;
    cout << "\nPointer B: " << ptrB.get() << endl;
    std::swap(ptrA, ptrB);
    cout << "\nPointer A: " << ptrA.get() << endl;
    cout << "\nPointer B: " << ptrB.get() << endl;
    ptrA.release();
    ptrB.release();

    //------------ Arrays 
    cout << "------------------------------------------------------------"
         << endl;
    std::unique_ptr<Counter> aCounter{new Counter()};
    { std::unique_ptr<Counter[]> uniqueArray{new Counter[3]}; }

    //------------ Special Deleters
    // You can implement custom deleter for smart pointers:
    // std::unique_ptr<int, MyDeleter> unique_ptr_with_deleter(new int(200),
    // MyDeleter());

    // std::make_unique
    std::unique_ptr<int> made_unique = std::make_unique<int>(2014);
  }

  /*
   * ------------ 2. Shared Pointer ---------------------------------------------
   */
  // Always use `std::make_shared` to create shared pointers, it is a lot faster.
  {
    auto shared_ptr = std::make_shared<Texture>(Texture(900, 900));
    cout << shared_ptr.use_count() << endl;
    {
      std::shared_ptr<Texture> local_shared_ptr(shared_ptr);
      cout << local_shared_ptr.use_count() << endl;
    }
    cout << shared_ptr.use_count() << endl;

    std::shared_ptr<Texture> global_shared_ptr = shared_ptr;
    cout << shared_ptr.use_count() << endl;

    global_shared_ptr.reset();
    cout << shared_ptr.use_count() << endl;
  }

  /*
   * ------------ 3. Weak Pointer ---------------------------------------------
   */
  {
    // std::weak_ptr is not a smart pointer
    // Only borrows a resource from a std::shared_ptr
    auto shared_ptr = std::make_shared<int>(42);
    std::weak_ptr<int> weak_ptr(shared_ptr);

    cout << "Weak ptr use count:   " << weak_ptr.use_count() << endl;
    cout << "Shared ptr use count: " << shared_ptr.use_count() << endl;
    cout << "Expired weake ptr?: " << weak_ptr.expired() << endl;
    if (std::shared_ptr<int> shared_ptr_1 = weak_ptr.lock()) {
      cout << *shared_ptr << endl;
    } else {
      cout << "Don't get it" << endl;
    }

    weak_ptr.reset();
    if (std::shared_ptr<int> shared_ptr_1 = weak_ptr.lock()) {
      cout << *shared_ptr << endl;
    } else {
      cout << "Don't get it" << endl;
    }
  }
}
