#include <iostream>

using namespace std;

void showArgumentsRecursively(int argc, char* argv[]) {
	if(argc == 1) {
		cout << "Pass some more arguments!" << endl;
		return;
	}
	else {
		cout << argv[argc-- -1] << endl;
		showArgumentsRecursively(argc--, argv);
	}
}

// argc: count of arguments in argument list
// argv: array of arguments
int main(int argc, char* argv[]) {
	showArgumentsRecursively(argc, argv);
}
