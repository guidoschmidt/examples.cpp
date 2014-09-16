#include <iostream>
#include <memory>
#include <vector>

using namespace std;

bool checkSharePointer(shared_ptr<int> p)
{
	if(p)
		return true;
	else
		return false;
}



int main()
{
    cout << "C++ 11 Shared Pointer" << endl;
    cout << "---------------------" << endl;

    int aNumber = 5;

    int *int_ptr_one = &aNumber;
    int *int_ptr_two = nullptr;

    cout << "Value of int_ptr_one is " << *int_ptr_one << endl;

    if(!int_ptr_two)
    {
    	cout << "int_ptr_two is a nullptr!" << endl;
    	int_ptr_two = &aNumber;
    }
    if(int_ptr_two)
    {
    	cout << "Now int_ptr_two has a value of " << *int_ptr_two << endl;
    }

    auto_ptr<int> auto_ptr_one(new int);
    *auto_ptr_one.get() = aNumber;
    cout << "My first auto_ptr has the value of " << *auto_ptr_one << endl;

    shared_ptr<int> shared_ptr_one(new int);
    *shared_ptr_one.get() = aNumber;
    cout << "My first shared_ptr has the value of " << *shared_ptr_one << endl;

    shared_ptr<int> shared_ptr_two(nullptr);

    // Evaluate share pointers
    cout << boolalpha; // Set cout to print bool-strings
    cout << "shared_ptr_one is " << checkSharePointer(shared_ptr_one) << endl;
    cout << "shared_ptr_two is " << checkSharePointer(shared_ptr_two) << endl;
    cout << "Currently there are " << shared_ptr_one.use_count()
    	 << " shared ptr on object aNumber" << endl;

   	shared_ptr<int> shared_ptr_three(shared_ptr_one);

    // Evaluate share pointer count
    cout << "Currently there are " << shared_ptr_three.use_count()
    	 << " shared ptr on object aNumber" << endl;


    // Delete sth with a callnback lambda function
    shared_ptr<int> shared_ptr_four(new int, [](int* p){ delete p; } );
    cout << "shared_ptr_four is " << checkSharePointer(shared_ptr_four)
    	 << " and there is " << shared_ptr_four.use_count() << " shared ptrs."
    	 << endl;

    return 0;
}
