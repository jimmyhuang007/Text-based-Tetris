#include "KBlock.h"
using namespace std;

KBlock::KBlock(int lv) {
  piece = '*';
  level = lv;
  coords.push_back(Coordinate{5, 3});
}
