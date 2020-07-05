#include <utility>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
  // Source and target data structure definitions
  std::vector<int> domain_vector(100);
  for (int i = 0; i < domain_vector.size(); i++) {
    domain_vector[i] = i * 1000;
  }
  std::vector<int> target_vector;

  cout << "Domain vector size: " << domain_vector.size() << endl;
  cout << "Target vector size: " << target_vector.size() << endl;

  /*
   * Use std::move to move data from one to another:
   * 1. Often it's good to use cheaper 'move' than an expensive copy
   * 2. Sometimes objects can not be copied, eg. a thread or a lock
   */

  // Copy:
  //target_vector = domain_vector;
  target_vector = std::move(domain_vector);

  cout << "----------------- std::move ---------------" << endl;
  cout << "Domain vector size: " << domain_vector.size() << endl;
  cout << "Target vector size: " << target_vector.size() << endl;

  return 0;
}
