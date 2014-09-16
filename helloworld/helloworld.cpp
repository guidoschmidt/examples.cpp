#include <iostream>


void yolo() {
	std::cout << "#YOLO" << std::endl;
}


int main(int argc, char* argv[]) {

	void (*yolo_ptr)();
	yolo_ptr = &yolo;
	yolo_ptr();

	std::cout << "Hello World!" << std::endl;
	return 0;
}
