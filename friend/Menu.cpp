#include "Menu.hpp"

void Menu::addItem(const string name, const float prize)
{
	_items.push_back(tuple<string, float>(name, prize));
}

void Menu::printMenu()
{
	cout << "~ Menu ~" << endl;
	cout << "---------" << endl;
	for(auto item : _items)
	{
		cout << get<0>(item) << " | " << get<1>(item) << endl;
	}
}
