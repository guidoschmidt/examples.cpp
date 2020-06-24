#include <iostream>
#include "Menu.hpp"

using namespace std;

// This is a friend function of the Menu class
void printOverAllPrize(Menu menu)
{
	float result = 0.0f;
	for(auto item : menu._items)
	{
		result += get<1>(item);
	}
	cout << "-----------------------" << endl;
	cout << "Complete: " << result << endl;
}

int main(int argc, char* argv[])
{
	cout << "--- Friend Function ---" << endl;
	Menu myMenu;
	myMenu.addItem("Gefüllte Paprika", 12.80f);
	myMenu.addItem("Pizza", 9.80f);
	myMenu.addItem("Krautsalat", 4.80f);

	myMenu.printMenu();
	printOverAllPrize(myMenu);

	return 0;
}