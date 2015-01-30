#include <cstdlib>
#include <iostream>  
#include <string>
#include <ctemplate/template.h>  

int main() {
	ctemplate::TemplateDictionary dict("example");
	int winnings = rand() % 100000;
	dict["NAME"] = "John Smith";
	dict["VALUE"] = winnings;
	dict.SetFormattedValue("TAXED_VALUE", "%.2f", winnings * 0.83);
	// For now, assume everyone lives in CA.
	// (Try running the program with a 0 here instead!)
	if (1) {
		dict.ShowSection("IN_CA");
	}
	std::string output;
	ctemplate::ExpandTemplate("example.tpl", ctemplate::DO_NOT_STRIP, &dict, &output);
	std::cout << output;
	return 0;
}