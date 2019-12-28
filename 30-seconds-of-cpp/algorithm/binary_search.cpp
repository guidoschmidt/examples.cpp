#include <iostream>

void print_array(int array[], int array_size) {
  for (int i = 0; i < array_size; i++) {
    std::cout << array[i] << ", ";
  }
  std::cout << std::endl;
}

void search_for(int array[], int array_size, int search_for) {
  if (std::binary_search(array, array + 10, search_for)) {
    std::cout << search_for << " was found in the array!" << std::endl;
  } else {
    std::cout << search_for << " was NOT found in the array!" << std::endl;
  }
}

int main() {
  int array[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
  int array_size = sizeof(array) / sizeof(array[0]);
  std::cout << "Size of the array is " << array_size << std::endl;

  print_array(array, array_size);

  // Search for '2' in the array
  // 1. sort the array
  std::sort(array, array + array_size);
  print_array(array, array_size);
  // 2. Perform binary search
  search_for(array, array_size, 2);
  search_for(array, array_size, 10);

  return 0;
}
