#include "LBlock.h"
using namespace std;

LBlock::LBlock(int lv) {
  piece = 'L';
  level = lv;
  coords.push_back(Coordinate{2, 3});
  coords.push_back(Coordinate{0, 4});
  coords.push_back(Coordinate{1, 4});
  coords.push_back(Coordinate{2, 4});
}
