#include "ZBlock.h"
using namespace std;

ZBlock::ZBlock(int lv) {
  piece = 'Z';
  level = lv;
  coords.push_back(Coordinate{0, 3});
  coords.push_back(Coordinate{1, 3});
  coords.push_back(Coordinate{1, 4});
  coords.push_back(Coordinate{2, 4});
}
