#include <filesystem>

namespace fs = std::filesystem;

int main() {
  fs::create_directories("c++_created/this_dir/");
}
