#include <set>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  std::set<int> intStore;

  // 'unpack' or 'destruct' the return value of insert
  auto [ iterator, inserted ] = intStore.insert(7);
  std::cout << *iterator << std::endl;

  // Better performance insert
  intStore.insert(iterator, 42);
  intStore.insert(iterator, 1377);

  std::cout << "Inserted element count: " << inserted << std::endl;
  for (iterator=intStore.begin(); iterator != intStore.end(); iterator++) {
    std::cout << *iterator << std::endl;
  }


  // Destructure or unpack arrays
  std::string names[3] = {"Roman", "Herbert", "Waltraud"};
  auto [ nameA, nameB, nameC ] = names;
  std::cout << "Three names: " << nameA << ", " << nameB << ", " << nameC << std::endl;


  // Works for structs, too
  struct KeyValue {
    std::string key = "key";
    float value = 0.0f;
  };

  KeyValue valueWithKey = { "magic_number", 42 };

  auto [ key, value ] = valueWithKey;
  std::cout << "Got key:   " << key << std::endl;
  std::cout << "Got value: " << value << std::endl;


  // Use in range based for-loops:
  std::vector<KeyValue> keyValueStore;
  KeyValue insert1 = { "DE", 12 };
  keyValueStore.push_back(insert1);
  KeyValue insert2 = { "FR", 42 };
  keyValueStore.push_back(insert2);
  

  for (auto [key, value] : keyValueStore) {
    std::cout << key << ": " << value << std::endl;
  }

  return 0;
}
