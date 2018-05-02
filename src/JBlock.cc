#include "JBlock.h"
using namespace std;

JBlock::JBlock(int lv) {
  piece = 'J';
  level = lv;
  coords.push_back(Coordinate{0, 3});
  coords.push_back(Coordinate{0, 4});
  coords.push_back(Coordinate{1, 4});
  coords.push_back(Coordinate{2, 4});
}
