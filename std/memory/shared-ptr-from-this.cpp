#include <memory>
#include <iostream>

using std::cout;
using std::endl;

class Asset: public std::enable_shared_from_this<Asset> {
public:
  std::shared_ptr<Asset> get_shared() {
    return shared_from_this();
  }
};

int main() {

  std::shared_ptr<Asset> shared_asset(new Asset());
  std::shared_ptr<Asset> shared_asset2 = shared_asset->get_shared();

  cout << shared_asset.use_count() << endl;

  cout << (void*)shared_asset.get() << endl;
  cout << (void*)shared_asset2.get() << endl;
  
  return 0;
}
