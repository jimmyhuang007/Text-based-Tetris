#include "TBlock.h"
using namespace std;

TBlock::TBlock(int lv) {
  piece = 'T';
  level = lv;
  coords.push_back(Coordinate{0, 3});
  coords.push_back(Coordinate{1, 3});
  coords.push_back(Coordinate{2, 3});
  coords.push_back(Coordinate{1, 4});
}
