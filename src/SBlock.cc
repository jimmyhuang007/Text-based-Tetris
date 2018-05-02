#include "SBlock.h"
using namespace std;

SBlock::SBlock(int lv) {
  piece = 'S';
  level = lv;
  coords.push_back(Coordinate{1, 3});
  coords.push_back(Coordinate{2, 3});
  coords.push_back(Coordinate{0, 4});
  coords.push_back(Coordinate{1, 4});
}
