#include "IBlock.h"
using namespace std;

IBlock::IBlock(int lv) {
  piece = 'I';
  level = lv;
  coords.push_back(Coordinate{0, 3});
  coords.push_back(Coordinate{1, 3});
  coords.push_back(Coordinate{2, 3});
  coords.push_back(Coordinate{3, 3});
}
