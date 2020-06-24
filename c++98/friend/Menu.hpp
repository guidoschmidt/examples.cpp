#ifndef H_MENU
#define H_MENU

#include <string>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Menu
{
	private:
		vector< tuple<string, float> > _items;
	public:
		void addItem(const string name, const float prize);
		void printMenu();
		friend void printOverAllPrize(Menu menu);
};

#endif // H_MENU