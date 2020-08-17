#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

int main() {
  system("git rev-parse --short HEAD");

  FILE *file_ptr, *out_file;
  char var[256];
  file_ptr = popen("git rev-parse --short HEAD", "r");
  // while (fgets(var, sizeof(var), file_ptr) != NULL) {
  //   cout << var << endl;
  // }
  pclose(file_ptr);
  std::string hash = std::string(var);
  cout << var << endl;

  // Get git status

  file_ptr = popen("git diff HEAD | wc -l", "r");
  while (fgets(var, sizeof(var), file_ptr) != NULL) {
    cout << std::stoi(var) << endl;
  }
  pclose(file_ptr);
}
