#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

struct FrameBufer {
  std::vector<int> _data;

  FrameBufer(std::vector<int> data) {
    _data = std::move(data);
  }

  inline int pixelAt(int index) {
    return _data.at(index);
  }
};

int main() {
  // Easily swap two object
  // 2 x 2 pixel frame buffer object
  FrameBufer ping({ 0, 0, 0, 0 });
  FrameBufer pong({ 255, 255, 255, 255 });

  int time_in_seconds = 60;
  int fps = 60;
  int frame_count = fps * time_in_seconds;
  for (int i = 0; i < frame_count; i++) {
    std::swap(ping, pong);
    cout << "--- SWAP ---" << endl;
    cout << "Ping [0, 0]: " << ping.pixelAt(0) << endl;
    cout << "Pong [0, 0]: " << pong.pixelAt(0) << endl;
  }
}
