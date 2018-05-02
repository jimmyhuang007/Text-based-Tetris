#include "OBlock.h"
using namespace std;

OBlock::OBlock(int lv) {
  piece = 'O';
  level = lv;
  coords.push_back(Coordinate{0, 3});
  coords.push_back(Coordinate{1, 3});
  coords.push_back(Coordinate{0, 4});
  coords.push_back(Coordinate{1, 4});
}
