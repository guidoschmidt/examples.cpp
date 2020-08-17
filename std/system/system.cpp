#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

int main() {
  // system("git rev-parse --short HEAD");

  FILE *file_ptr;
  char var[256];
  file_ptr = popen("git rev-parse --short HEAD", "r");
  fgets(var, sizeof(var), file_ptr);
  pclose(file_ptr);
  std::string hash = std::string(var);
  rtrim(hash);
  cout << "Git hash: " << hash << endl;

  // Get git status
  char changes[10];
  file_ptr = popen("git diff HEAD | wc -l", "r");
  fgets(changes, sizeof(changes), file_ptr);
  int change_count = std::stoi(changes);
  cout << change_count << endl;
  pclose(file_ptr);
}
